// Copyright (c) 2015 YamaArashi

#include <stdio.h>
#include <string.h>
#include "global.h"
#include "gfx.h"
#include "util.h"

// Read/write JASC palette files.

// Format of a JASC palette file, line by line:
// "JASC-PAL" (signature)
// "0100" (version; seems to always be "0100")
// "<NUMBER_OF_COLORS>" (number of colors in decimal)
//
// <NUMBER_OF_COLORS> times:
// "<RED> <GREEN> <BLUE> <ALPHA (optional)>" (color entry)
//
// Line endings can be \r\n or \r or \n
//
// Each color component is a decimal number from 0 to 255.
// Examples:
// Black - "0 0 0"
// Blue  - "0 0 255"
// Brown - "150 75 0"
// Cyan  - "255 255 255 255"


#define MAX_LINE_LENGTH 15

void ReadJascPaletteLine(FILE *fp, char *line)
{
    int c;
    int length = 0;
    int numSpaces = 0; 

    for (;;)
    {
        c = fgetc(fp);

        // CRLF or CR
        if (c == '\r') {
            c = fgetc(fp);
            if (c != '\n') {
                // put it back!
                ungetc(c, fp);
            }

            line[length] = 0;
            return;
        }

        // LF only
        if (c == '\n'){
            line[length] = 0;
            return;
        }

        if (c == 0)
            FATAL_ERROR("NUL character in file.\n");

        if (c == 0)
            FATAL_ERROR("Unexpected EOF. No CRLF, CR, or LF at end of file.\n");
            
        // Count the number of spaces encountered
        // Should be 2 then a newline. If 3, then
        // there's an alpha afterward. Keep reading
        // to consume chars, but don't save them
        if (c == ' ') 
            numSpaces++;

        if (numSpaces < 3) {
            line[length] = c;
        } else if (numSpaces == 3) {
            line[length] = 0;
        }

        length++;
    }
}

void ReadJascPalette(char *path, struct Palette *palette)
{
    char line[MAX_LINE_LENGTH + 1];

    FILE *fp = fopen(path, "rb");

    if (fp == NULL)
        FATAL_ERROR("Failed to open JASC-PAL file \"%s\" for reading.\n", path);

    ReadJascPaletteLine(fp, line);

    if (strcmp(line, "JASC-PAL") != 0)
        FATAL_ERROR("Invalid JASC-PAL signature.\n");

    ReadJascPaletteLine(fp, line);

    if (strcmp(line, "0100") != 0)
        FATAL_ERROR("Unsuported JASC-PAL version.\n");

    ReadJascPaletteLine(fp, line);

    if (!ParseNumber(line, NULL, 10, &palette->numColors))
        FATAL_ERROR("Failed to parse number of colors.\n");

    if (palette->numColors < 1 || palette->numColors > 256)
        FATAL_ERROR("%d is an invalid number of colors. The number of colors must be in the range [1, 256].\n", palette->numColors);

    for (int i = 0; i < palette->numColors; i++)
    {
        ReadJascPaletteLine(fp, line);

        char *s = line;
        char *end;

        int red;
        int green;
        int blue;

        if (!ParseNumber(s, &end, 10, &red))
            FATAL_ERROR("Failed to parse red color component.\n");

        s = end;

        if (*s != ' ')
            FATAL_ERROR("Expected a space after red color component.\n");

        s++;

        if (*s < '0' || *s > '9')
            FATAL_ERROR("Expected only a space between red and green color components.\n");

        if (!ParseNumber(s, &end, 10, &green))
            FATAL_ERROR("Failed to parse green color component.\n");

        s = end;

        if (*s != ' ')
            FATAL_ERROR("Expected a space after green color component.\n");

        s++;

        if (*s < '0' || *s > '9')
            FATAL_ERROR("Expected only a space between green and blue color components.\n");

        if (!ParseNumber(s, &end, 10, &blue))
            FATAL_ERROR("Failed to parse blue color component.\n");

        if (*end != 0)
            FATAL_ERROR("Garbage after blue color component.\n");

        if (red < 0 || red > 255)
            FATAL_ERROR("Red color component (%d) is outside the range [0, 255].\n", red);

        if (green < 0 || green > 255)
            FATAL_ERROR("Green color component (%d) is outside the range [0, 255].\n", green);

        if (blue < 0 || blue > 255)
            FATAL_ERROR("Blue color component (%d) is outside the range [0, 255].\n", blue);

        palette->colors[i].red = red;
        palette->colors[i].green = green;
        palette->colors[i].blue = blue;
    }

    if (fgetc(fp) != EOF)
        FATAL_ERROR("Garbage after color data.\n");

    fclose(fp);
}

void WriteJascPalette(char *path, struct Palette *palette)
{
    FILE *fp = fopen(path, "wb");

    fputs("JASC-PAL\r\n", fp);
    fputs("0100\r\n", fp);
    fprintf(fp, "%d\r\n", palette->numColors);

    for (int i = 0; i < palette->numColors; i++)
    {
        struct Color *color = &palette->colors[i];
        fprintf(fp, "%d %d %d\r\n", color->red, color->green, color->blue);
    }

    fclose(fp);
}
