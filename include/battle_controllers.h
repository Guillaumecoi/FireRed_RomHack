#ifndef GUARD_BATTLE_CONTROLLERS_H
#define GUARD_BATTLE_CONTROLLERS_H

#include "global.h"
#include "battle.h"

enum
{
    REQUEST_ALL_BATTLE,
    REQUEST_SPECIES_BATTLE,
    REQUEST_HELDITEM_BATTLE,
    REQUEST_MOVES_PP_BATTLE,
    REQUEST_MOVE1_BATTLE,
    REQUEST_MOVE2_BATTLE,
    REQUEST_MOVE3_BATTLE,
    REQUEST_MOVE4_BATTLE,
    REQUEST_PP_DATA_BATTLE,
    REQUEST_PPMOVE1_BATTLE,
    REQUEST_PPMOVE2_BATTLE,
    REQUEST_PPMOVE3_BATTLE,
    REQUEST_PPMOVE4_BATTLE,
    REQUEST_UNUSED_13_BATTLE,
    REQUEST_UNUSED_14_BATTLE,
    REQUEST_UNUSED_15_BATTLE,
    REQUEST_UNUSED_16_BATTLE,
    REQUEST_OTID_BATTLE,
    REQUEST_EXP_BATTLE,
    REQUEST_HP_EV_BATTLE,
    REQUEST_ATK_EV_BATTLE,
    REQUEST_DEF_EV_BATTLE,
    REQUEST_SPEED_EV_BATTLE,
    REQUEST_SPATK_EV_BATTLE,
    REQUEST_SPDEF_EV_BATTLE,
    REQUEST_FRIENDSHIP_BATTLE,
    REQUEST_POKERUS_BATTLE,
    REQUEST_MET_LOCATION_BATTLE,
    REQUEST_MET_LEVEL_BATTLE,
    REQUEST_MET_GAME_BATTLE,
    REQUEST_POKEBALL_BATTLE,
    REQUEST_ALL_IVS_BATTLE,
    REQUEST_HP_IV_BATTLE,
    REQUEST_ATK_IV_BATTLE,
    REQUEST_DEF_IV_BATTLE,
    REQUEST_SPEED_IV_BATTLE,
    REQUEST_SPATK_IV_BATTLE,
    REQUEST_SPDEF_IV_BATTLE,
    REQUEST_PERSONALITY_BATTLE,
    REQUEST_CHECKSUM_BATTLE,
    REQUEST_STATUS_BATTLE,
    REQUEST_LEVEL_BATTLE,
    REQUEST_HP_BATTLE,
    REQUEST_MAX_HP_BATTLE,
    REQUEST_ATK_BATTLE,
    REQUEST_DEF_BATTLE,
    REQUEST_SPEED_BATTLE,
    REQUEST_SPATK_BATTLE,
    REQUEST_SPDEF_BATTLE,
    REQUEST_COOL_BATTLE,
    REQUEST_BEAUTY_BATTLE,
    REQUEST_CUTE_BATTLE,
    REQUEST_SMART_BATTLE,
    REQUEST_TOUGH_BATTLE,
    REQUEST_SHEEN_BATTLE,
    REQUEST_COOL_RIBBON_BATTLE,
    REQUEST_BEAUTY_RIBBON_BATTLE,
    REQUEST_CUTE_RIBBON_BATTLE,
    REQUEST_SMART_RIBBON_BATTLE,
    REQUEST_TOUGH_RIBBON_BATTLE,
};

// Special arguments for Battle Controller functions.

enum { // Values given to the emit functions to choose gBattleResources->bufferA or gBattleResources->bufferB
    BUFFER_A,
    BUFFER_B
};

enum {
    RESET_ACTION_MOVE_SELECTION,
    RESET_ACTION_SELECTION,
    RESET_MOVE_SELECTION,
};

enum {
    BALL_NO_SHAKES,
    BALL_1_SHAKE,
    BALL_2_SHAKES,
    BALL_3_SHAKES_FAIL,
    BALL_3_SHAKES_SUCCESS,
    BALL_TRAINER_BLOCK,
    BALL_GHOST_DODGE,
};

enum {
    LINK_STANDBY_MSG_STOP_BOUNCE,
    LINK_STANDBY_STOP_BOUNCE_ONLY,
    LINK_STANDBY_MSG_ONLY,
};

#define INSTANT_HP_BAR_DROP     0x7FFF

#define PARTY_SUMM_SKIP_DRAW_DELAY (1 << 7)

// Special return values in gBattleResources->bufferB from Battle Controller functions.
#define RET_VALUE_LEVELED_UP   11
#define RET_MEGA_EVOLUTION (1 << 7)
#define RET_ULTRA_BURST    (1 << 6)
#define RET_DYNAMAX        (1 << 5)

struct UnusedControllerStruct
{
    u8 unk:7;
    u8 flag:1;
};

struct HpAndStatus
{
    u16 hp;
    u32 status;
};

struct MovePpInfo
{
    u16 moves[MAX_MON_MOVES];
    u8 pp[MAX_MON_MOVES];
    u8 ppBonuses;
};

struct ChooseMoveStruct
{
    u16 moves[MAX_MON_MOVES];
    u8 currentPp[MAX_MON_MOVES];
    u8 maxPp[MAX_MON_MOVES];
    u16 species;
    u8 monType1;
    u8 monType2;
    u8 monType3;
    struct MegaEvolutionData mega;
    struct UltraBurstData burst;
    struct ZMoveData zmove;
};

enum
{
    CONTROLLER_GETMONDATA,
    CONTROLLER_GETRAWMONDATA,
    CONTROLLER_SETMONDATA,
    CONTROLLER_SETRAWMONDATA,
    CONTROLLER_LOADMONSPRITE,
    CONTROLLER_SWITCHINANIM,
    CONTROLLER_RETURNMONTOBALL,
    CONTROLLER_DRAWTRAINERPIC,
    CONTROLLER_TRAINERSLIDE,
    CONTROLLER_TRAINERSLIDEBACK,
    CONTROLLER_FAINTANIMATION,
    CONTROLLER_PALETTEFADE,
    CONTROLLER_SUCCESSBALLTHROWANIM,
    CONTROLLER_BALLTHROWANIM,
    CONTROLLER_PAUSE,
    CONTROLLER_MOVEANIMATION,
    CONTROLLER_PRINTSTRING,
    CONTROLLER_PRINTSTRINGPLAYERONLY,
    CONTROLLER_CHOOSEACTION,
    CONTROLLER_UNKNOWNYESNOBOX,
    CONTROLLER_CHOOSEMOVE,
    CONTROLLER_OPENBAG,
    CONTROLLER_CHOOSEPOKEMON,
    CONTROLLER_23,
    CONTROLLER_HEALTHBARUPDATE,
    CONTROLLER_EXPUPDATE,
    CONTROLLER_STATUSICONUPDATE,
    CONTROLLER_STATUSANIMATION,
    CONTROLLER_STATUSXOR,
    CONTROLLER_DATATRANSFER,
    CONTROLLER_DMA3TRANSFER,
    CONTROLLER_PLAYBGM,
    CONTROLLER_32,
    CONTROLLER_TWORETURNVALUES,
    CONTROLLER_CHOSENMONRETURNVALUE,
    CONTROLLER_ONERETURNVALUE,
    CONTROLLER_ONERETURNVALUE_DUPLICATE,
    CONTROLLER_CLEARUNKVAR,
    CONTROLLER_SETUNKVAR,
    CONTROLLER_CLEARUNKFLAG,
    CONTROLLER_TOGGLEUNKFLAG,
    CONTROLLER_HITANIMATION,
    CONTROLLER_CANTSWITCH,
    CONTROLLER_PLAYSE,
    CONTROLLER_PLAYFANFAREORBGM,
    CONTROLLER_FAINTINGCRY,
    CONTROLLER_INTROSLIDE,
    CONTROLLER_INTROTRAINERBALLTHROW,
    CONTROLLER_DRAWPARTYSTATUSSUMMARY,
    CONTROLLER_HIDEPARTYSTATUSSUMMARY,
    CONTROLLER_ENDBOUNCE,
    CONTROLLER_SPRITEINVISIBILITY,
    CONTROLLER_BATTLEANIMATION,
    CONTROLLER_LINKSTANDBYMSG,
    CONTROLLER_RESETACTIONMOVESELECTION,
    CONTROLLER_ENDLINKBATTLE,
    /*new controllers should go here*/
    CONTROLLER_TERMINATOR_NOP,
    CONTROLLER_CMDS_COUNT
};

extern struct UnusedControllerStruct gUnusedControllerStruct;
extern void (*gBattlerControllerFuncs[MAX_BATTLERS_COUNT])(u32 battler);
extern void (*gBattlerControllerEndFuncs[MAX_BATTLERS_COUNT])(u32 battler);
extern u8 gBattleControllerData[MAX_BATTLERS_COUNT];

// general functions
void HandleLinkBattleSetup(void);
void SetUpBattleVars(void);
void InitBattleControllers(void);
void TryReceiveLinkBattleData(void);
void PrepareBufferDataTransferLink(u32 battler, u32 bufferId, u16 size, u8 *data);
bool32 IsValidForBattle(struct Pokemon *mon);

// emitters
void BtlController_EmitGetMonData(u32 battler, u32 bufferId, u8 requestId, u8 monToCheck);
void BtlController_EmitSetMonData(u32 battler, u32 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data);
void BtlController_EmitLoadMonSprite(u32 battler, u32 bufferId);
void BtlController_EmitSwitchInAnim(u32 battler, u32 bufferId, u8 partyId, bool8 dontClearSubstituteBit);
void BtlController_EmitReturnMonToBall(u32 battler, u32 bufferId, bool8 skipAnim);
void BtlController_EmitDrawTrainerPic(u32 battler, u32 bufferId);
void BtlController_EmitTrainerSlide(u32 battler, u32 bufferId);
void BtlController_EmitTrainerSlideBack(u32 battler, u32 bufferId);
void BtlController_EmitFaintAnimation(u32 battler, u32 bufferId);
void BtlController_EmitBallThrowAnim(u32 battler, u32 bufferId, u8 caseId);
void BtlController_EmitMoveAnimation(u32 battler, u32 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit);
void BtlController_EmitPrintString(u32 battler, u32 bufferId, u16 stringId);
void BtlController_EmitPrintSelectionString(u32 battler, u32 bufferId, u16 stringId);
void BtlController_EmitChooseAction(u32 battler, u32 bufferId, u8 action, u16 itemId);
void BtlController_EmitChooseMove(u32 battler, u32 bufferId, bool8 isDoubleBattle, bool8 NoPpNumber, struct ChooseMoveStruct *movePpData);
void BtlController_EmitChooseItem(u32 battler, u32 bufferId, u8 *arg1);
void BtlController_EmitChoosePokemon(u32 battler, u32 bufferId, u8 caseId, u8 arg2, u16 abilityId, u8 *arg4);
void BtlController_EmitHealthBarUpdate(u32 battler, u32 bufferId, u16 hpValue);
void BtlController_EmitExpUpdate(u32 battler, u32 bufferId, u8 partyId, s32 expPoints);
void BtlController_EmitStatusIconUpdate(u32 battler, u32 bufferId, u32 status1, u32 status2);
void BtlController_EmitStatusAnimation(u32 battler, u32 bufferId, bool8 status2, u32 status);
void BtlController_EmitDataTransfer(u32 battler, u32 bufferId, u16 size, void *data);
void BtlController_EmitTwoReturnValues(u32 battler, u32 bufferId, u8 ret8, u32 ret32);
void BtlController_EmitChosenMonReturnValue(u32 battler, u32 bufferId, u8 b, u8 *c);
void BtlController_EmitOneReturnValue(u32 battler, u32 bufferId, u16 arg1);
void BtlController_EmitOneReturnValue_Duplicate(u32 battler, u32 bufferId, u16 b);
void BtlController_EmitHitAnimation(u32 battler, u32 bufferId);
void BtlController_EmitCantSwitch(u32 battler, u32 bufferId);
void BtlController_EmitPlaySE(u32 battler, u32 bufferId, u16 songId);
void BtlController_EmitPlayFanfareOrBGM(u32 battler, u32 bufferId, u16 songId, bool8 playBGM);
void BtlController_EmitFaintingCry(u32 battler, u32 bufferId);
void BtlController_EmitIntroSlide(u32 battler, u32 bufferId, u8 terrainId);
void BtlController_EmitIntroTrainerBallThrow(u32 battler, u32 bufferId);
void BtlController_EmitDrawPartyStatusSummary(u32 battler, u32 bufferId, struct HpAndStatus *hpAndStatus, u8 param);
void BtlController_EmitHidePartyStatusSummary(u32 battler, u32 bufferId);
void BtlController_EmitEndBounceEffect(u32 battler, u32 bufferId);
void BtlController_EmitSpriteInvisibility(u32 battler, u32 bufferId, bool8 isInvisible);
void BtlController_EmitBattleAnimation(u32 battler, u32 bufferId, u8 animationId, struct DisableStruct* disableStructPtr, u16 argument);
void BtlController_EmitLinkStandbyMsg(u32 battler, u32 bufferId, u8 mode);
void BtlController_EmitResetActionMoveSelection(u32 battler, u32 bufferId, u8 caseId);
void BtlController_EmitEndLinkBattle(u32 battler, u32 bufferId, u8 battleOutcome);

void BtlController_Empty(u32 battler); // Empty command, does nothing, only completes the execution.
void BtlController_TerminatorNop(u32 battler); // Dummy function at the end of the table.
void StartSendOutAnim(u32 battler, bool32 dontClearSubstituteBit);
void Controller_WaitForString(u32 battler);

// handlers
void BtlController_HandleGetMonData(u32 battler);
void BtlController_HandleGetRawMonData(u32 battler);
void BtlController_HandleSetMonData(u32 battler);
void BtlController_HandleSetRawMonData(u32 battler);
void BtlController_HandleSwitchInAnim(u32 battler, bool32 isPlayerSide, void (*controllerCallback)(u32 battler));
void BtlController_HandleReturnMonToBall(u32 battler);
void BtlController_HandleDrawTrainerPic(u32 battlerId, u32 trainerPicId, bool32 isFrontPic, s16 xPos, s16 yPos, s32 subpriority);
void BtlController_HandleTrainerSlide(u32 battler, u32 trainerPicId);
void BtlController_HandleTrainerSlideBack(u32 battlerId, s16 data0, bool32 startAnim);
void BtlController_HandleFaintAnimation(u32 battler);
void BtlController_HandleSuccessBallThrowAnim(u32 battler, u32 target, u32 animId, bool32 allowCriticalCapture);
void BtlController_HandleBallThrowAnim(u32 battler, u32 target, u32 animId, bool32 allowCriticalCapture);
void BtlController_HandleMoveAnimation(u32 battler);
void BtlController_HandlePrintString(u32 battler);
void BtlController_HandleHealthBarUpdate(u32 battler, bool32 updateHpText);
void BtlController_HandleStatusIconUpdate(u32 battler);
void BtlController_HandleStatusAnimation(u32 battler);
void BtlController_HandleClearUnkVar(u32 battler);
void BtlController_HandleSetUnkVar(u32 battler);
void BtlController_HandleClearUnkFlag(u32 battler);
void BtlController_HandleToggleUnkFlag(u32 battler);
void BtlController_HandleHitAnimation(u32 battler);
void BtlController_HandlePlaySE(u32 battler);
void BtlController_HandlePlayFanfareOrBGM(u32 battler);
void BtlController_HandleFaintingCry(u32 battler);
void BtlController_HandleIntroSlide(u32 battler);
void BtlController_HandleSpriteInvisibility(u32 battler);
bool32 TwoPlayerIntroMons(u32 battlerId); // Double battle with both player pokemon active.
bool32 TwoOpponentIntroMons(u32 battlerId); // Double battle with both opponent pokemon active.
void BtlController_HandleIntroTrainerBallThrow(u32 battler, u16 tagTrainerPal, const u32 *trainerPal, s16 framesToWait, void (*controllerCallback)(u32 battler), void (*spriteCallback)(struct Sprite *sprite));
void BtlController_HandleDrawPartyStatusSummary(u32 battler, u32 side, bool32 considerDelay);
void BtlController_HandleHidePartyStatusSummary(u32 battler);
void BtlController_HandleBattleAnimation(u32 battler, bool32 ignoreSE);

// player controller
void BattleControllerDummy(u32 battler);
void SetControllerToPlayer(u32 battler);
void SpriteCB_FreePlayerSpriteLoadMonSpriteOld(struct Sprite *sprite);
void SetCB2ToReshowScreenAfterMenu(void);
void SetCB2ToReshowScreenAfterMenu2(void);
void Task_PlayerController_RestoreBgmAfterCry(u8 taskId);
void ActionSelectionCreateCursorAt(u8 cursorPos, u8 unused);
void ActionSelectionDestroyCursorAt(u8 cursorPos);
void InitMoveSelectionsVarsAndStrings(u32 battler);
void SetBattleEndCallbacks(u32 battler);
void MoveSelectionCreateCursorAt(u8 cursorPos, u8 arg1);
void MoveSelectionDestroyCursorAt(u8 cursorPos);
void HandleInputChooseMove(u32 battler);

// opponent controller
void SetControllerToOpponent(u32 battler);
void OpponentBufferExecCompleted(u32 battler);

// safari controller
void SetControllerToSafari(u32 battler);

// pokedude controller
void SetControllerToPokedude(u32 battler);
void InitPokedudePartyAndOpponent(void);

// oak and old man controller
void SetControllerToOakOrOldMan(u32 battler);

// These flags are set to signal that the indicated message
// was already emitted

// Inflicting damage is key
#define FIRST_BATTLE_MSG_FLAG_INFLICT_DMG    0x1
// Lowering stats is advantageous
#define FIRST_BATTLE_MSG_FLAG_STAT_CHG       0x2
// Keep an eye on your HP
#define FIRST_BATTLE_MSG_FLAG_HP_RESTORE     0x4
//
#define FIRST_BATTLE_MSG_FLAG_PARTY_MENU     0x8

bool8 BtlCtrl_OakOldMan_TestState2Flag(u8 mask);
void BtlCtrl_OakOldMan_SetState2Flag(u8 mask);
void PrintOakText_InflictingDamageIsKey(u32 battler);
void PrintOakText_HowDisappointing(u32 battler);
void PrintOakText_OakNoRunningFromATrainer(u32 battler);
void OakOldManHandleInputChooseMove(u32 battler);
void BtlCtrl_DrawVoiceoverMessageFrame(void);
void BtlCtrl_RemoveVoiceoverMessageFrame(void);

// link opponent controller
void SetControllerToLinkOpponent(u32 battler);

// link partner controller
void SetControllerToLinkPartner(u32 battler);

#endif // GUARD_BATTLE_CONTROLLERS_H
