EventScript_ChangeMovesNpc::
	lockall
	faceplayer
	msgbox Text_ChangeMovesNpc_Offer, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_ChangeMovesNpc_ChooseMon
	case NO, EventScript_ChangeMovesNpc_Declined
	releaseall
	end

EventScript_ChangeMovesNpc_ChooseMon::
	msgbox Text_ChangeMovesNpc_ChooseMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_ChangeMovesNpc_Cancel
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, EventScript_ChangeMovesNpc_Egg
	goto_if_eq VAR_0x8005, 0, EventScript_ChangeMovesNpc_NoMoves
	msgbox Text_ChangeMovesNpc_ChooseMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, EventScript_ChangeMovesNpc_ChooseMon
	msgbox Text_ChangeMovesNpc_Done, MSGBOX_DEFAULT
	releaseall
	end

EventScript_ChangeMovesNpc_Egg::
	msgbox Text_ChangeMovesNpc_Egg, MSGBOX_DEFAULT
	goto EventScript_ChangeMovesNpc_ChooseMon

EventScript_ChangeMovesNpc_NoMoves::
	msgbox Text_ChangeMovesNpc_NoMoves, MSGBOX_DEFAULT
	goto EventScript_ChangeMovesNpc_ChooseMon

EventScript_ChangeMovesNpc_Cancel::
EventScript_ChangeMovesNpc_Declined::
	msgbox Text_ChangeMovesNpc_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

Text_ChangeMovesNpc_Offer:
	.string "I can help your POKéMON remember\n"
	.string "moves they have forgotten.\pWould you like to proceed?$"

Text_ChangeMovesNpc_ChooseMon:
	.string "Which POKéMON would you like to\n"
	.string "teach?$"

Text_ChangeMovesNpc_ChooseMove:
	.string "Choose a move for your POKéMON to\n"
	.string "remember.$"

Text_ChangeMovesNpc_Egg:
	.string "An EGG can't be taught any moves.$"

Text_ChangeMovesNpc_NoMoves:
	.string "That POKéMON has no moves it can\n"
	.string "remember.$"

Text_ChangeMovesNpc_Done:
	.string "There you go!$"

Text_ChangeMovesNpc_ComeAgain:
	.string "Come back if you change your mind.$"
