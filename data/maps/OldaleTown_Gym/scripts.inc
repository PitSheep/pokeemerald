OldaleTown_Gym_MapScripts::
	.byte 0

OldaleTown_Gym_EventScript_MoveSingleIn::
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	step_end

OldaleTown_Gym_EventScript_MoveSingleOut::
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	face_down
	step_end

OldaleTown_Gym_EventScript_MoveDuoLeftIn::
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

OldaleTown_Gym_EventScript_MoveDuoLeftOut::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	face_down
	step_end

OldaleTown_Gym_EventScript_MoveDuoRightIn::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	face_up
	step_end

OldaleTown_Gym_EventScript_MoveDuoRightOut::
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

OldaleTown_Gym_EventScript_MoveOpponentIn::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

OldaleTown_Gym_EventScript_MoveOpponentAway::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Gym_EventScript_MoveOpponentDisappear::
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentAway
	waitmovement 0
	removeobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleOut
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightOut
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftOut
	end

OldaleTown_Gym_EventScript_GymArtist::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_GYM_1, OldaleTown_Gym_EventScript_GymArtist_1
	goto_if_set FLAG_BATTLE_GYM_2, OldaleTown_Gym_EventScript_GymArtist_2
	goto_if_set FLAG_BATTLE_GYM_3, OldaleTown_Gym_EventScript_GymArtist_3
	goto_if_set FLAG_BATTLE_GYM_4, OldaleTown_Gym_EventScript_GymArtist_4
	goto_if_set FLAG_BATTLE_GYM_5, OldaleTown_Gym_EventScript_GymArtist_5
	goto_if_set FLAG_BATTLE_GYM_6, OldaleTown_Gym_EventScript_GymArtist_6
	goto_if_set FLAG_BATTLE_GYM_7, OldaleTown_Gym_EventScript_GymArtist_7
	goto_if_set FLAG_BATTLE_GYM_8, OldaleTown_Gym_EventScript_GymArtist_8
	goto_if_set FLAG_BATTLE_GYM_9, OldaleTown_Gym_EventScript_GymArtist_9
	goto_if_set FLAG_BATTLE_GYM_REWARD, OldaleTown_Gym_EventScript_GymArtist_10
	goto OldaleTown_Gym_EventScript_GymArtist_0
	release
	end

OldaleTown_Gym_EventScript_GymArtist_0::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_0, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_0:
	.string "Hi Master!\p"
	.string "You haven't defended\n"
	.string "the CHAMPION GYM yet.$"

OldaleTown_Gym_EventScript_GymArtist_1::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_1, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_1:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 1 of 10$"

OldaleTown_Gym_EventScript_GymArtist_2::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_2, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_2:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 2 of 10$"

OldaleTown_Gym_EventScript_GymArtist_3::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_3, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_3:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 3 of 10$"

OldaleTown_Gym_EventScript_GymArtist_4::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_4, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_4:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 4 of 10$"

OldaleTown_Gym_EventScript_GymArtist_5::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_5, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_5:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 5 of 10$"

OldaleTown_Gym_EventScript_GymArtist_6::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_6, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_6:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 6 of 10$"

OldaleTown_Gym_EventScript_GymArtist_7::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_7, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_7:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 7 of 10$"

OldaleTown_Gym_EventScript_GymArtist_8::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_8, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_8:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 8 of 10$"

OldaleTown_Gym_EventScript_GymArtist_9::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_9, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_9:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 9 of 10$"

OldaleTown_Gym_EventScript_GymArtist_10::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymArtistAdvice_10, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymArtistAdvice_10:
	.string "Hi Master!\p"
	.string "Gym defense fight:\n"
	.string "Current 10 of 10$"

OldaleTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymGuideAdvice:
	.string "Good morning champion {PLAYER}.\n"
	.string "Welcome to YOUR GYM.\p"
	.string "There are no limitations\n"
	.string "on the species or level\p"
	.string "of POKéMON you can use.\p"
	.string "Defend the gym by single trainer\n"
	.string "or by trainers in duo.\p"
	.string "Every 10 battles you win,\n"
	.string "you will be rewarded with a MASTER BALL.\p"
	.string "Your challenger's level\n"
	.string "is based on yours POKéMON level.\p"
	.string "Talk to your followers\n"
	.string "to receive more information.\p"
	.string "Talk to reporter to know\n"
	.string "the number of the current battle.\p"
	.string "Have a good fight!$"

OldaleTown_Gym_EventScript_GymFollowerSingle::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymFollowerSingleAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymFollowerSingleAdvice:
	.string "Good morning leader {PLAYER}.\n"
	.string "Things are simple:\p"
	.string "talk to the lone fighter\n"
	.string "on the left to defend the gym\p"
	.string "from a single trainer.\p"
	.string "Win 10 battles and you will receive\n"
	.string "a MASTER BALL.\p"
	.string "Your challenger's level\n"
	.string "is based on yours POKéMON level.\p"
	.string "Before every battle,\n"
	.string "we heal your pokemon party.\p"
	.string "Have a good fight!$"

OldaleTown_Gym_EventScript_GymFollowerDuo::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymFollowerDuoAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymFollowerDuoAdvice:
	.string "Good morning leader {PLAYER}.\n"
	.string "Things are simple:\p"
	.string "talk to the paired fighters\n"
	.string "on the right to defend the gym\p"
	.string "from a pair of trainers.\p"
	.string "Win 10 battles and you will receive\n"
	.string "a MASTER BALL.\p"
	.string "Your challenger's level\n"
	.string "is based on yours POKéMON level.\p"
	.string "Before every battle,\n"
	.string "we heal your pokemon party.\p"
	.string "Have a good fight!$"

OldaleTown_Gym_EventScript_GymFollowerNE4::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_GymFollowerNE4Advice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_GymFollowerNE4Advice:
	.string "Good morning leader {PLAYER}.\n"
	.string "I heard that:\p"
	.string "new trainers will come to challenge you!\p"
	.string "It's said around,\n"
	.string "they come from a distant country.\p"
	.string "I don't remember well...\n"
	.string "but it's something like ITALIA\p"
	.string "They call themselves the NEW ELITE 4!\p"
	.string "Win 10 battles and you will receive\n"
	.string "a MASTER BALL.\p"
	.string "defend your gym from the NEW ELITE 4!\p"
	.string "Have a good fight!$"

OldaleTown_Gym_Text_SingleBattleDefeat:
	.string "Grrrrr!\n"
	.string "I will return and victory will be mine!$"

OldaleTown_Gym_Text_SingleBattlePostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"

OldaleTown_Gym_Text_DoubleBattleNoPokemon:
	.string "You don't even have two POKéMON.\n"
	.string "You can't expect to beat me like that.$"

OldaleTown_Gym_Text_Single_Start_Yes_No:
	.string "Well, Master, you're ready\n"
	.string "to defend the gym\p"
	.string "in a single battle?$"

OldaleTown_Gym_EventScript_SingleBattle_No::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_Single_Start_No, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_Single_Start_No:
	.string "well, come back when\n"
	.string "you feel ready$"

OldaleTown_Gym_EventScript_SingleBattle_Yes_No::
	lock
	faceplayer
	special HealPlayerParty
	updatefollowerpokemongraphic
	msgbox OldaleTown_Gym_Text_Single_Start_Yes_No, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Gym_EventScript_SingleBattle_No
	goto OldaleTown_Gym_EventScript_SingleBattle
	release
	end

OldaleTown_Gym_Text_Duo_Start_Yes_No:
	.string "Well, Master, you're ready\n"
	.string "to defend the gym\p"
	.string "in a Duo battle?$"

OldaleTown_Gym_EventScript_DuoBattle_No::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_Duo_Start_No, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_Duo_Start_No:
	.string "well, come back when\n"
	.string "you feel ready$"

OldaleTown_Gym_EventScript_DuoBattle_NoPokemon::
	lock
	faceplayer
	msgbox OldaleTown_Gym_Text_Duo_Start_NoPokemon, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_Text_Duo_Start_NoPokemon:
	.string "You don't even have two POKéMON.\n"
	.string "You can't expect to beat me like that.$"

OldaleTown_Gym_EventScript_DuoBattle_Yes_No::
	lock
	faceplayer
	special HealPlayerParty
	updatefollowerpokemongraphic
	msgbox OldaleTown_Gym_Text_Duo_Start_Yes_No, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Gym_EventScript_DuoBattle_No
	getpartysize
	goto_if_ge VAR_RESULT, 2, OldaleTown_Gym_EventScript_DuoBattle
	goto OldaleTown_Gym_EventScript_DuoBattle_NoPokemon
	release
	end

OldaleTown_Gym_EventScript_SingleBattle::
	closemessage
	setflag FLAG_BATTLE_GYM
	goto_if_set FLAG_BATTLE_GYM_1, OldaleTown_Gym_EventScript_SingleBattle1
	goto_if_set FLAG_BATTLE_GYM_2, OldaleTown_Gym_EventScript_SingleBattle2
	goto_if_set FLAG_BATTLE_GYM_3, OldaleTown_Gym_EventScript_SingleBattle3
	goto_if_set FLAG_BATTLE_GYM_4, OldaleTown_Gym_EventScript_SingleBattle4
	goto_if_set FLAG_BATTLE_GYM_5, OldaleTown_Gym_EventScript_SingleBattle5
	goto_if_set FLAG_BATTLE_GYM_6, OldaleTown_Gym_EventScript_SingleBattle6
	goto_if_set FLAG_BATTLE_GYM_7, OldaleTown_Gym_EventScript_SingleBattle7
	goto_if_set FLAG_BATTLE_GYM_8, OldaleTown_Gym_EventScript_SingleBattle8
	goto_if_set FLAG_BATTLE_GYM_9, OldaleTown_Gym_EventScript_SingleBattle9
	goto_if_set FLAG_BATTLE_GYM_REWARD, OldaleTown_Gym_EventScript_SingleBattle10
	goto OldaleTown_Gym_EventScript_SingleBattle1
	end

OldaleTown_Gym_Text_SingleBattleIntro_a:
	.string "First battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle1::
	setflag FLAG_BATTLE_GYM_1
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_a
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_a
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_a
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_a
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_a
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_a
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_a
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_a::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_a::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_a::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_a::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_a::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_a::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_a::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_b:
	.string "Second battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle2::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_b
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_b
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_b
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_b
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_b
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_b
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_b
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_b::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_b::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_b::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_b::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_b::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_b::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_b::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_c:
	.string "Third battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle3::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_c
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_c
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_c
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_c
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_c
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_c
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_c
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_c::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_c::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_c::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_c::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_c::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_c::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_c::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_d:
	.string "Fourth battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle4::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_d
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_d
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_d
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_d
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_d
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_d
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_d
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_d::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_d::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_d::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_d::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_d::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_d::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_d::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_e:
	.string "Fifth battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle5::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_e
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_e
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_e
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_e
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_e
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_e
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_e
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_e::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_e::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_e::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_e::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_e::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_e::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_e::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_f:
	.string "Sixth battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle6::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_f
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_f
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_f
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_f
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_f
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_f
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_f
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_f::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_f::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_f::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_f::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_f::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_f::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_f::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_g:
	.string "Seventh battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle7::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_g
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_g
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_g
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_g
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_g
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_g
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_g
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_g::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_g::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_g::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_g::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_g::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_g::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_g::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_h:
	.string "Eighth battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle8::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_h
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_h
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_h
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_h
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_h
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_h
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_h
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_h::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_h::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_h::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_h::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_h::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_h::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_h::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_i:
	.string "Ninth battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle9::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_i
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_i
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_i
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_i
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_i
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_i
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_i
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_i::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_i::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_i::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_i::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_i::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_i::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_i::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_Text_SingleBattleIntro_l:
	.string "Final battle!\n"
	.string "Defend your gym!$"

OldaleTown_Gym_EventScript_SingleBattle10::
	random 7
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_l
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_l
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_l
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_l
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_l
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_l
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_l
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_l::
	setvar VAR_CURRENT_TRAINER, 9
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_SIDNEY
	trainerbattle_single TRAINER_SIDNEY, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_l::
	setvar VAR_CURRENT_TRAINER, 10
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_STEVEN
	trainerbattle_single TRAINER_STEVEN, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_l::
	setvar VAR_CURRENT_TRAINER, 11
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PHOEBE
	trainerbattle_single TRAINER_PHOEBE, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_l::
	setvar VAR_CURRENT_TRAINER, 12
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_GLACIA
	trainerbattle_single TRAINER_GLACIA, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart5_l::
	setvar VAR_CURRENT_TRAINER, 13
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_DRAKE
	trainerbattle_single TRAINER_DRAKE, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart6_l::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_1
	trainerbattle_single TRAINER_WINONA_1, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_l::
	setvar VAR_CURRENT_TRAINER, 15
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WALLACE
	trainerbattle_single TRAINER_WALLACE, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle::
	closemessage
	setflag FLAG_BATTLE_GYM
	goto_if_set FLAG_BATTLE_GYM_1, OldaleTown_Gym_EventScript_SingleBattle1D
	goto_if_set FLAG_BATTLE_GYM_2, OldaleTown_Gym_EventScript_SingleBattle2D
	goto_if_set FLAG_BATTLE_GYM_3, OldaleTown_Gym_EventScript_SingleBattle3D
	goto_if_set FLAG_BATTLE_GYM_4, OldaleTown_Gym_EventScript_SingleBattle4D
	goto_if_set FLAG_BATTLE_GYM_5, OldaleTown_Gym_EventScript_SingleBattle5D
	goto_if_set FLAG_BATTLE_GYM_6, OldaleTown_Gym_EventScript_SingleBattle6D
	goto_if_set FLAG_BATTLE_GYM_7, OldaleTown_Gym_EventScript_SingleBattle7D
	goto_if_set FLAG_BATTLE_GYM_8, OldaleTown_Gym_EventScript_SingleBattle8D
	goto_if_set FLAG_BATTLE_GYM_9, OldaleTown_Gym_EventScript_SingleBattle9D
	goto_if_set FLAG_BATTLE_GYM_REWARD, OldaleTown_Gym_EventScript_SingleBattle10D
	goto OldaleTown_Gym_EventScript_SingleBattle1D
	end

OldaleTown_Gym_EventScript_SingleBattle1D::
	setflag FLAG_BATTLE_GYM_1
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_ad
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_ad
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_ad
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_ad
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_ad
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_ad
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_ad
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_ad
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_ad::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_ad::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_ad::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_ad::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_ad::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_ad::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_ad::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_ad::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle2D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_bd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_bd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_bd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_bd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_bd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_bd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_bd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_bd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_bd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_bd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_bd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_bd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_bd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_bd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_bd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_bd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle3D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_cd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_cd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_cd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_cd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_cd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_cd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_cd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_cd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_cd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_cd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_cd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_cd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_cd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_cd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_cd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_cd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle4D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_dd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_dd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_dd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_dd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_dd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_dd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_dd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_dd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_dd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_dd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_dd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_dd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_dd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_dd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_dd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_dd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle5D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_ed
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_ed
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_ed
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_ed
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_ed
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_ed
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_ed
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_ed
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_ed::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_ed::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_ed::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_ed::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_ed::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_ed::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_ed::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_ed::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle6D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_fd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_fd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_fd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_fd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_fd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_fd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_fd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_fd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_fd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_fd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_fd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_fd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_fd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_fd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_fd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_fd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle7D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_gd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_gd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_gd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_gd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_gd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_gd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_gd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_gd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_gd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_gd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_gd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_gd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_gd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_gd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_gd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_gd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle8D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_hd
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_hd
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_hd
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_hd
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_hd
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_hd
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_hd
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_hd
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_hd::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_hd::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_hd::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_hd::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_hd::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_hd::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_hd::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_hd::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle9D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_id
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_id
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_id
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_id
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_id
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_id
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_id
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_id
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_id::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_id::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_id::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_id::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_id::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_id::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_id::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_id::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle10D::
	random 8
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_ld
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_ld
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_ld
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_ld
	case 4, OldaleTown_Gym_EventScript_SingleBattleStart5_ld
	case 5, OldaleTown_Gym_EventScript_SingleBattleStart6_ld
	case 6, OldaleTown_Gym_EventScript_SingleBattleStart7_ld
	case 7, OldaleTown_Gym_EventScript_SingleBattleStart8_ld
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_ld::
	setvar VAR_CURRENT_TRAINER, 22
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_TATE_AND_LIZA_5
	trainerbattle_double TRAINER_TATE_AND_LIZA_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_ld::
	setvar VAR_CURRENT_TRAINER, 16
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ROXANNE_5
	trainerbattle_double TRAINER_ROXANNE_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart3_ld::
	setvar VAR_CURRENT_TRAINER, 17
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_BRAWLY_5
	trainerbattle_double TRAINER_BRAWLY_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart4_ld::
	setvar VAR_CURRENT_TRAINER, 18
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WATTSON_5
	trainerbattle_double TRAINER_WATTSON_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart5_ld::
	setvar VAR_CURRENT_TRAINER, 19
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_FLANNERY_5
	trainerbattle_double TRAINER_FLANNERY_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart6_ld::
	setvar VAR_CURRENT_TRAINER, 20
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_NORMAN_5
	trainerbattle_double TRAINER_NORMAN_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart7_ld::
	setvar VAR_CURRENT_TRAINER, 14
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_WINONA_5
	trainerbattle_double TRAINER_WINONA_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end
	
OldaleTown_Gym_EventScript_SingleBattleStart8_ld::
	setvar VAR_CURRENT_TRAINER, 21
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_JUAN_5
	trainerbattle_double TRAINER_JUAN_5, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end












OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite::
	lock
	faceplayer
	call OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Welcome
	goto OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Choose
	end

OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Welcome::
	msgbox OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Welcome_Text, MSGBOX_DEFAULT
	return

OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Welcome_Text:
	.string "First of all,\n"
	.string "you want to defend the gym from:\p"
	.string "Classic Trainer?\n"
	.string "or New Elite 4?$"

OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Choose::
	special HealPlayerParty
	updatefollowerpokemongraphic
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_NORMAL_ELITE
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattle_Yes_No
	case 1, OldaleTown_Gym_EventScript_SingleBattle_Yes_No_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Esc
	case MULTI_B_PRESSED, OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Esc
	end

OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Esc::
	msgbox OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Esc_Text, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_SingleBattle_Normal_Elite_Esc_Text:
	.string "Okey Master.\p"
	.string "Come back and see me if you\n"
	.string "want defend YOUR GYM.$"

OldaleTown_Gym_EventScript_SingleBattle_Yes_No_Elite::
	lock
	faceplayer
	special HealPlayerParty
	updatefollowerpokemongraphic
	msgbox OldaleTown_Gym_Text_Single_Start_Yes_No, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Gym_EventScript_SingleBattle_No
	goto OldaleTown_Gym_EventScript_SingleBattle_Elite
	release
	end

OldaleTown_Gym_EventScript_SingleBattle_Elite::
	closemessage
	setflag FLAG_BATTLE_GYM
	goto_if_set FLAG_BATTLE_GYM_1, OldaleTown_Gym_EventScript_SingleBattle1_Elite
	goto_if_set FLAG_BATTLE_GYM_2, OldaleTown_Gym_EventScript_SingleBattle2_Elite
	goto_if_set FLAG_BATTLE_GYM_3, OldaleTown_Gym_EventScript_SingleBattle3_Elite
	goto_if_set FLAG_BATTLE_GYM_4, OldaleTown_Gym_EventScript_SingleBattle4_Elite
	goto_if_set FLAG_BATTLE_GYM_5, OldaleTown_Gym_EventScript_SingleBattle5_Elite
	goto_if_set FLAG_BATTLE_GYM_6, OldaleTown_Gym_EventScript_SingleBattle6_Elite
	goto_if_set FLAG_BATTLE_GYM_7, OldaleTown_Gym_EventScript_SingleBattle7_Elite
	goto_if_set FLAG_BATTLE_GYM_8, OldaleTown_Gym_EventScript_SingleBattle8_Elite
	goto_if_set FLAG_BATTLE_GYM_9, OldaleTown_Gym_EventScript_SingleBattle9_Elite
	goto_if_set FLAG_BATTLE_GYM_REWARD, OldaleTown_Gym_EventScript_SingleBattle10_Elite
	goto OldaleTown_Gym_EventScript_SingleBattle1_Elite
	end

OldaleTown_Gym_EventScript_SingleBattle1_Elite::
	setflag FLAG_BATTLE_GYM_1
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_a_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_a_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_a_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_a_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_a_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_a_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_a_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_a_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle2_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_b_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_b_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_b_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_b_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_b_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_b_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_b_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_b_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle3_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_c_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_c_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_c_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_c_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_c_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_c_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_c_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_c_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle4_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_d_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_d_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_d_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_d_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_d_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_d_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_d_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_d_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle5_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_e_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_e_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_e_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_e_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_e_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_e_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_e_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_e_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle6_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_f_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_f_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_f_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_f_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_f_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_f_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_f_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_f_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle7_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_g_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_g_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_g_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_g_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_g_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_g_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_g_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_g_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle8_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_h_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_h_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_h_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_h_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_h_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_h_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_h_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_h_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle9_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_i_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_i_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_i_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_i_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_i_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_i_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_i_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_i_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattle10_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_SingleBattleStart1_l_Elite
	case 1, OldaleTown_Gym_EventScript_SingleBattleStart2_l_Elite
	case 2, OldaleTown_Gym_EventScript_SingleBattleStart3_l_Elite
	case 3, OldaleTown_Gym_EventScript_SingleBattleStart4_l_Elite
	end

OldaleTown_Gym_EventScript_SingleBattleStart1_l_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_S
	trainerbattle_single TRAINER_PIT_S, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart2_l_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_S
	trainerbattle_single TRAINER_ALE_S, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart3_l_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_S
	trainerbattle_single TRAINER_LEO_S, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_SingleBattleStart4_l_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_S
	trainerbattle_single TRAINER_RICK_S, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end












OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite::
	lock
	faceplayer
	call OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Welcome
	goto OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Choose
	end

OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Welcome::
	msgbox OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Welcome_Text, MSGBOX_DEFAULT
	return

OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Welcome_Text:
	.string "First of all,\n"
	.string "you want to defend the gym from:\p"
	.string "Classic Trainer?\n"
	.string "or New Elite 4?$"

OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Choose::
	special HealPlayerParty
	updatefollowerpokemongraphic
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_NORMAL_ELITE
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattle_Yes_No
	case 1, OldaleTown_Gym_EventScript_DuoBattle_Yes_No_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Esc
	case MULTI_B_PRESSED, OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Esc
	end

OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Esc::
	msgbox OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Esc_Text, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_DuoBattle_Normal_Elite_Esc_Text:
	.string "Okey Master.\p"
	.string "Come back and see me if you\n"
	.string "want defend YOUR GYM.$"

OldaleTown_Gym_EventScript_DuoBattle_Yes_No_Elite::
	lock
	faceplayer
	special HealPlayerParty
	updatefollowerpokemongraphic
	msgbox OldaleTown_Gym_Text_Duo_Start_Yes_No, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Gym_EventScript_DuoBattle_No
	getpartysize
	goto_if_ge VAR_RESULT, 2, OldaleTown_Gym_EventScript_DuoBattle_Elite
	goto OldaleTown_Gym_EventScript_DuoBattle_NoPokemon
	release
	end

OldaleTown_Gym_EventScript_DuoBattle_Elite::
	closemessage
	setflag FLAG_BATTLE_GYM
	goto_if_set FLAG_BATTLE_GYM_1, OldaleTown_Gym_EventScript_DuoBattle1_Elite
	goto_if_set FLAG_BATTLE_GYM_2, OldaleTown_Gym_EventScript_DuoBattle2_Elite
	goto_if_set FLAG_BATTLE_GYM_3, OldaleTown_Gym_EventScript_DuoBattle3_Elite
	goto_if_set FLAG_BATTLE_GYM_4, OldaleTown_Gym_EventScript_DuoBattle4_Elite
	goto_if_set FLAG_BATTLE_GYM_5, OldaleTown_Gym_EventScript_DuoBattle5_Elite
	goto_if_set FLAG_BATTLE_GYM_6, OldaleTown_Gym_EventScript_DuoBattle6_Elite
	goto_if_set FLAG_BATTLE_GYM_7, OldaleTown_Gym_EventScript_DuoBattle7_Elite
	goto_if_set FLAG_BATTLE_GYM_8, OldaleTown_Gym_EventScript_DuoBattle8_Elite
	goto_if_set FLAG_BATTLE_GYM_9, OldaleTown_Gym_EventScript_DuoBattle9_Elite
	goto_if_set FLAG_BATTLE_GYM_REWARD, OldaleTown_Gym_EventScript_DuoBattle10_Elite
	goto OldaleTown_Gym_EventScript_DuoBattle1_Elite
	end

OldaleTown_Gym_EventScript_DuoBattle1_Elite::
	setflag FLAG_BATTLE_GYM_1
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_a_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_a_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_a_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_a_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_a_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_a_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_a_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_a_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_a, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle2_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_b_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_b_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_b_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_b_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_b_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_b_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_b_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_b_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_b, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle3_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_c_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_c_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_c_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_c_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_c_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_c_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_c_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_c_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_c, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle4_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_d_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_d_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_d_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_d_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_d_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_d_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_d_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_d_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_d, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle5_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_e_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_e_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_e_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_e_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_e_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_e_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_e_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_e_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_e, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle6_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_f_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_f_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_f_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_f_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_f_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_f_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_f_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_f_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_f, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle7_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_g_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_g_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_g_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_g_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_g_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_g_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_g_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_g_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_g, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle8_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_h_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_h_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_h_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_h_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_h_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_h_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_h_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_h_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_h, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle9_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_i_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_i_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_i_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_i_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_i_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_i_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_i_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_i_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_i, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattle10_Elite::
	random 4
	switch VAR_RESULT
	case 0, OldaleTown_Gym_EventScript_DuoBattleStart1_l_Elite
	case 1, OldaleTown_Gym_EventScript_DuoBattleStart2_l_Elite
	case 2, OldaleTown_Gym_EventScript_DuoBattleStart3_l_Elite
	case 3, OldaleTown_Gym_EventScript_DuoBattleStart4_l_Elite
	end

OldaleTown_Gym_EventScript_DuoBattleStart1_l_Elite::
	setvar VAR_CURRENT_TRAINER, 23
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_PIT_D
	trainerbattle_double TRAINER_PIT_D, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart2_l_Elite::
	setvar VAR_CURRENT_TRAINER, 24
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_ALE_D
	trainerbattle_double TRAINER_ALE_D, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart3_l_Elite::
	setvar VAR_CURRENT_TRAINER, 25
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_LEO_D
	trainerbattle_double TRAINER_LEO_D, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_DuoBattleStart4_l_Elite::
	setvar VAR_CURRENT_TRAINER, 26
	addobject VAR_CURRENT_TRAINER
	applymovement 5, OldaleTown_Gym_EventScript_MoveSingleIn
	applymovement 4, OldaleTown_Gym_EventScript_MoveDuoLeftIn
	applymovement 6, OldaleTown_Gym_EventScript_MoveDuoRightIn
	applymovement VAR_CURRENT_TRAINER, OldaleTown_Gym_EventScript_MoveOpponentIn
	waitmovement 0
	cleartrainerflag TRAINER_RICK_D
	trainerbattle_double TRAINER_RICK_D, OldaleTown_Gym_Text_SingleBattleIntro_l, OldaleTown_Gym_Text_SingleBattleDefeat, OldaleTown_Gym_Text_DoubleBattleNoPokemon, OldaleTown_Gym_EventScript_MoveOpponentDisappear
	msgbox OldaleTown_Gym_Text_SingleBattlePostBattle, MSGBOX_AUTOCLOSE
	end