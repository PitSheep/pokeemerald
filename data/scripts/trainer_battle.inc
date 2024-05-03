EventScript_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
EventScript_TrainerApproach::
	special PlayTrainerEncounterMusic
	special DoTrainerApproach
	waitstate
	goto EventScript_ShowTrainerIntroMsg

EventScript_TryDoNormalTrainerBattle::
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	specialvar VAR_RESULT, GetTrainerFlag
	goto_if_ne VAR_RESULT, FALSE, EventScript_NoNormalTrainerBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NoNormalTrainerBattle::
	gotopostbattlescript

EventScript_TryDoDoubleTrainerBattle::
	lock
	faceplayer
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, GetTrainerFlag
	goto_if_ne VAR_RESULT, FALSE, EventScript_NoDoubleTrainerBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NotEnoughMonsForDoubleBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_NoDoubleTrainerBattle::
	gotopostbattlescript

EventScript_DoNoIntroTrainerBattle::
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	special PlayTrainerEncounterMusic
	dotrainerbattle
	gotopostbattlescript

EventScript_TryDoRematchBattle::
	call EventScript_RevealTrainer
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoRematchTrainerBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	goto_if_set FLAG_BATTLE_GYM, Flag_Battle_Gym_up
	frontier_givepoints
	frontier_givepoints
	releaseall
	end

EventScript_NoRematchTrainerBattle::
	gotopostbattlescript

EventScript_TryDoDoubleRematchBattle::
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoDoubleRematchTrainerBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleRematchBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	goto_if_set FLAG_BATTLE_GYM, Flag_Battle_Gym_up
	frontier_givepoints
	frontier_givepoints
	releaseall
	end

EventScript_NoDoubleRematchTrainerBattle::
	gotopostbattlescript

EventScript_NotEnoughMonsForDoubleRematchBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_RevealTrainer::
	applymovement VAR_LAST_TALKED, Movement_RevealTrainer
	waitmovement 0
	return

Movement_RevealTrainer:
	reveal_trainer
	step_end

EventScript_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special TryPrepareSecondApproachingTrainer
	goto_if_eq VAR_RESULT, TRUE, EventScript_TrainerApproach
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle::
	dotrainerbattle
	@ Below battle mode check only needed in FRLG
	specialvar VAR_RESULT, GetTrainerBattleMode
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_SINGLE, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE, EventScript_EndTrainerBattle
	goto_if_eq VAR_RESULT, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, EventScript_EndTrainerBattle
EventScript_EndTrainerBattle::
	goto_if_set FLAG_BATTLE_GYM, Flag_Battle_Gym_up
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Std_MsgboxAutoclose::
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

Flag_Battle_Gym_up::
	goto_if_set FLAG_BATTLE_GYM_1, Flag_Battle_Gym_up1
	goto_if_set FLAG_BATTLE_GYM_2, Flag_Battle_Gym_up2
	goto_if_set FLAG_BATTLE_GYM_3, Flag_Battle_Gym_up3
	goto_if_set FLAG_BATTLE_GYM_4, Flag_Battle_Gym_up4
	goto_if_set FLAG_BATTLE_GYM_5, Flag_Battle_Gym_up5
	goto_if_set FLAG_BATTLE_GYM_6, Flag_Battle_Gym_up6
	goto_if_set FLAG_BATTLE_GYM_7, Flag_Battle_Gym_up7
	goto_if_set FLAG_BATTLE_GYM_8, Flag_Battle_Gym_up8
	goto_if_set FLAG_BATTLE_GYM_9, Flag_Battle_Gym_up9
	goto_if_set FLAG_BATTLE_GYM_REWARD, Flag_Battle_Gym_upReward
	end

Flag_Battle_Gym_up1::
	setflag FLAG_BATTLE_GYM_2
	clearflag FLAG_BATTLE_GYM_1
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up2::
	setflag FLAG_BATTLE_GYM_3
	clearflag FLAG_BATTLE_GYM_2
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up3::
	setflag FLAG_BATTLE_GYM_4
	clearflag FLAG_BATTLE_GYM_3
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up4::
	setflag FLAG_BATTLE_GYM_5
	clearflag FLAG_BATTLE_GYM_4
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up5::
	setflag FLAG_BATTLE_GYM_6
	clearflag FLAG_BATTLE_GYM_5
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up6::
	setflag FLAG_BATTLE_GYM_7
	clearflag FLAG_BATTLE_GYM_6
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up7::
	setflag FLAG_BATTLE_GYM_8
	clearflag FLAG_BATTLE_GYM_7
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up8::
	setflag FLAG_BATTLE_GYM_9
	clearflag FLAG_BATTLE_GYM_8
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_up9::
	setflag FLAG_BATTLE_GYM_REWARD
	clearflag FLAG_BATTLE_GYM_9
	clearflag FLAG_BATTLE_GYM
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end

Flag_Battle_Gym_upReward::
	setflag FLAG_BATTLE_GYM_1
	clearflag FLAG_BATTLE_GYM_REWARD
	clearflag FLAG_BATTLE_GYM
	giveitem ITEM_MASTER_BALL
	closemessage
	frontier_givepoints
	frontier_givepoints
	gotobeatenscript
	releaseall
	end