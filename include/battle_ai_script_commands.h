#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5

void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
u8 BattleAI_GetBadMovesMask(u8 target);
u8 BattleAI_ChooseMoveAgainstTarget(u8 allowedMoves, u8 target);
s32 BattleAI_ChooseMoveByDamageDoubles(u8 allowedMoves, u8 target);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordAbilityBattle(u8 battlerId, u8 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);

#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
