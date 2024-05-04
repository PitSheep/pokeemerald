OldaleTown_Hunter_House_MapScripts::
	.byte 0

OldaleTown_Hunter_House_EventScript_Guide::
	lock
	faceplayer
	msgbox OldaleTown_Hunter_House_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_GuideAdvice:
	.string "Good morning {PLAYER}.\n"
	.string "Welcome to HUNTER HOUSE.\p"
	.string "Select a Pokemon via PC near him\n"
	.string "to receive information\p"
	.string "on his latest sighting.\n"
	.string "Then go there for hunting.\p"
	.string "Remember that you must insert\n"
	.string "a MASTER BALL to do this!\p"
	.string "Have a good hunting!$"

OldaleTown_Hunter_House_Text_Monster_Quest:
	.string "Wanna try Hunt?\n"
	.string "Insert 1 MASTER BALL!$"

OldaleTown_Hunter_House_Text_Monster_NoMasterball:
	.string "You don't have any MasterBall.$"

OldaleTown_Hunter_House_EventScript_Answer_No:
	msgbox OldaleTown_Hunter_House_Text_Answer_No, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Answer_No:
	.string "Well Hunter,\n"
	.string "come back when you are ready...$"

OldaleTown_Hunter_House_EventScript_Monster1::
	lock
	msgbox OldaleTown_Hunter_House_Text_Monster_Quest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_Hunter_House_EventScript_Answer_No
	goto OldaleTown_Hunter_House_EventScript_Answer_Yes
	release
	end

OldaleTown_Hunter_House_EventScript_Answer_Yes:
	checkitem ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Hunter_House_EventScript_Start_Hunt
	msgbox OldaleTown_Hunter_House_Text_Monster_NoMasterball, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_EventScript_Start_Hunt:
	removeitem ITEM_MASTER_BALL
	msgbox OldaleTown_Hunter_House_Text_Start_Hunt, MSGBOX_DEFAULT
	release
	end

OldaleTown_Hunter_House_Text_Start_Hunt:
	.string "Start Hunting!$"