EventScript_StatEditorNpc::
	lockall
	faceplayer
	msgbox Text_StatEditorNpc_Offer, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EventScript_StatEditorNpc_ChooseMon
	case NO, EventScript_StatEditorNpc_Declined
	releaseall
	end

EventScript_StatEditorNpc_ChooseMon::
	msgbox Text_StatEditorNpc_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_StatEditorNpc_Cancel
	special OpenStatEditorFromScript
	releaseall
	end

EventScript_StatEditorNpc_Cancel::
EventScript_StatEditorNpc_Declined::
	msgbox Text_StatEditorNpc_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

Text_StatEditorNpc_Offer:
	.string "I can help you adjust your POKéMON's\n"
	.string "stats.\pWould you like to proceed?$"

Text_StatEditorNpc_ChooseMon:
	.string "Which POKéMON would you like to\n"
	.string "work on?$"

Text_StatEditorNpc_ComeAgain:
	.string "Come back if you change your mind.$"
