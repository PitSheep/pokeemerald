@ Move tutor with a single list containing every Battle Frontier tutor move.
@ VAR_TEMP_D is the move selection, VAR_0x8008 is the price (set by SetBattleFrontierAllTutorMove)
BattleFrontier_EventScript_AllMoveTutor::
	lock
	faceplayer
	msgbox BattleFrontier_Text_AllMoveTutorWelcome, MSGBOX_DEFAULT
	message BattleFrontier_Text_AllMoveTutorWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_ALL
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	goto BattleFrontier_EventScript_AllMoveTutor_HandleSelection
	end

BattleFrontier_EventScript_AllMoveTutor_ChooseNewMove::
	message BattleFrontier_Text_AllMoveTutorWhichMove
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_ALL
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	goto BattleFrontier_EventScript_AllMoveTutor_HandleSelection
	end

BattleFrontier_EventScript_AllMoveTutor_HandleSelection::
	goto_if_eq VAR_RESULT, 30, BattleFrontier_EventScript_AllMoveTutor_Exit
	goto_if_eq VAR_RESULT, MULTI_B_PRESSED, BattleFrontier_EventScript_AllMoveTutor_Exit
	copyvar VAR_TEMP_D, VAR_RESULT
	special SetBattleFrontierAllTutorMove
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Text_AllMoveTutorConfirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_EventScript_AllMoveTutor_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_EventScript_AllMoveTutor_TeachMove
	msgbox BattleFrontier_Text_AllMoveTutorNotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_EventScript_AllMoveTutor_ChooseNewMove
	end

BattleFrontier_EventScript_AllMoveTutor_TeachMove::
	msgbox BattleFrontier_Text_AllMoveTutorWhichMon, MSGBOX_DEFAULT
	special SetBattleFrontierAllTutorMove
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_EventScript_AllMoveTutor_CancelChooseMon
	msgbox BattleFrontier_Text_AllMoveTutorTaughtMove, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_EventScript_AllMoveTutor_Exit::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Text_AllMoveTutorGoodbye, MSGBOX_DEFAULT
	release
	end

BattleFrontier_EventScript_AllMoveTutor_CancelChooseMon::
	msgbox BattleFrontier_Text_AllMoveTutorGoodbye, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Text_AllMoveTutorWelcome:
	.string "Welcome!\n"
	.string "I can teach your POKéMON any move\l"
	.string "in exchange for Battle Points.$"

BattleFrontier_Text_AllMoveTutorWhichMove:
	.string "Which move should I teach?$"

BattleFrontier_Text_AllMoveTutorConfirm:
	.string "The move {STR_VAR_1}, is it?\n"
	.string "That will be {STR_VAR_2} Battle Points, okay?$"

BattleFrontier_Text_AllMoveTutorNotEnoughPoints:
	.string "You haven't got enough Battle Points!$"

BattleFrontier_Text_AllMoveTutorWhichMon:
	.string "Now pick the POKéMON I should\n"
	.string "teach the move to.$"

BattleFrontier_Text_AllMoveTutorTaughtMove:
	.string "There you go!\n"
	.string "I'll take those Battle Points.$"

BattleFrontier_Text_AllMoveTutorGoodbye:
	.string "Come back anytime if you want\n"
	.string "to learn a move.$"
