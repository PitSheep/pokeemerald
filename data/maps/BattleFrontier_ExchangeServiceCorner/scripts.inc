BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "You've chosen the KISS POSTER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "You've chosen the KISS CUSHION.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "You've chosen the SMOOCHUM DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "You've chosen the TOGEPI DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "You've chosen the MEOWTH DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "You've chosen the CLEFAIRY DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "You've chosen the DITTO DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "You've chosen the CYNDAQUIL DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "You've chosen the CHIKORITA DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "You've chosen the TOTODILE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "You've chosen the LAPRAS DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "You've chosen the SNORLAX DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "You've chosen the VENUSAUR DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "You've chosen the CHARIZARD DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "You've chosen the BLASTOISE DOLL.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "You've chosen the PROTEIN.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "You've chosen the CALCIUM.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "You've chosen the IRON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "You've chosen the ZINC.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "You've chosen the CARBOS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "You've chosen the HP UP.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the BRIGHTPOWDER.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the WHITE HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the QUICK CLAW.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the MENTAL HERB.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the CHOICE BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the KING'S ROCK.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the FOCUS BAND.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the SCOPE LENS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the LEFTOVERS.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush DOLLS!\l"
	.string "Little plush DOLLS!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my POKéMON will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, SMOOCHUM?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the BATTLE facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a SMOOCHUM print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A SMOOCHUM cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A SMOOCHUM DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A TOGEPI DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A MEOWTH DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A CLEFAIRY DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A DITTO DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A CYNDAQUIL DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A CHIKORITA DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A TOTODILE DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large DOLL.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Raises the stat ATTACK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Raises the stat SP. ATK of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Raises the stat DEFENSE of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Raises the stat SP. DEF of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Raises the stat SPEED of one\n"
	.string "POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Raises the HP of one POKéMON.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps POKéMON out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"


BattleFrontier_EventScript_ChooseWildPokemon::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_POKEMON_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Wild1
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Wild2
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Wild3
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Wild4
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Wild5
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild1:
	.string "You've chosen 1-50 POKéDEX POKéMON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild2:
	.string "You've chosen 50-100 POKéDEX POKéMON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild3:
	.string "You've chosen 100-150 POKéDEX POKéMON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild4:
	.string "You've chosen 150-200 POKéDEX POKéMON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild5:
	.string "You've chosen 200-251 POKéDEX POKéMON.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_Wild1::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize1
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Wild2::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Wild3::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize3
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Wild4::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize4
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Wild5::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWild5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize5
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize1::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize1
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize2::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize2
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize3::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize3
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize4::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize4
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize5::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize5
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseWildPokemon
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize1::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	random 50
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Start1
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Start2
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Start3
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Start4
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Start5
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Start6
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Start7
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Start8
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Start9
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Start10
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Start11
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Start12
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Start13
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Start14
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Start15
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Start16
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_Start17
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Start18
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_Start19
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_Start20
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Start21
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Start22
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Start23
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_Start24
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_Start25
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_Start26
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_Start27
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_Start28
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_Start29
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_Start30
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_Start31
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_Start32
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_Start33
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_Start34
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_Start35
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_Start36
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_Start37
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_Start38
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_Start39
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_Start40
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_Start41
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_Start42
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_Start43
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_Start44
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_Start45
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_Start46
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_Start47
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_Start48
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_Start49
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_Start50
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize2::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	random 50
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Start51
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Start52
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Start53
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Start54
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Start55
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Start56
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Start57
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Start58
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Start59
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Start60
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Start61
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Start62
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Start63
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Start64
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Start65
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Start66
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_Start67
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Start68
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_Start69
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_Start70
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Start71
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Start72
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Start73
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_Start74
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_Start75
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_Start76
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_Start77
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_Start78
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_Start79
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_Start80
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_Start81
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_Start82
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_Start83
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_Start84
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_Start85
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_Start86
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_Start87
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_Start88
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_Start89
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_Start90
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_Start91
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_Start92
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_Start93
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_Start94
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_Start95
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_Start96
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_Start97
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_Start98
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_Start99
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_Start100
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize3::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	random 50
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Start101
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Start102
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Start103
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Start104
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Start105
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Start106
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Start107
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Start108
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Start109
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Start110
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Start111
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Start112
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Start113
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Start114
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Start115
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Start116
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_Start117
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Start118
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_Start119
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_Start120
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Start121
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Start122
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Start123
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_Start124
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_Start125
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_Start126
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_Start127
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_Start128
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_Start129
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_Start130
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_Start131
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_Start132
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_Start133
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_Start134
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_Start135
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_Start136
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_Start137
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_Start138
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_Start139
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_Start140
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_Start141
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_Start142
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_Start143
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_Start144
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_Start145
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_Start146
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_Start147
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_Start148
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_Start149
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_Start150
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize4::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	random 50
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Start151
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Start152
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Start153
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Start154
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Start155
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Start156
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Start157
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Start158
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Start159
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Start160
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Start161
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Start162
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Start163
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Start164
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Start165
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Start166
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_Start167
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Start168
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_Start169
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_Start170
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Start171
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Start172
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Start173
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_Start174
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_Start175
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_Start176
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_Start177
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_Start178
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_Start179
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_Start180
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_Start181
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_Start182
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_Start183
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_Start184
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_Start185
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_Start186
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_Start187
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_Start188
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_Start189
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_Start190
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_Start191
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_Start192
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_Start193
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_Start194
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_Start195
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_Start196
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_Start197
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_Start198
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_Start199
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_Start200
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize5::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	random 51
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Start201
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Start202
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Start203
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Start204
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Start205
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_Start206
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_Start207
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_Start208
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_Start209
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_Start210
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_Start211
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_Start212
	case 12, BattleFrontier_ExchangeServiceCorner_EventScript_Start213
	case 13, BattleFrontier_ExchangeServiceCorner_EventScript_Start214
	case 14, BattleFrontier_ExchangeServiceCorner_EventScript_Start215
	case 15, BattleFrontier_ExchangeServiceCorner_EventScript_Start216
	case 16, BattleFrontier_ExchangeServiceCorner_EventScript_Start217
	case 17, BattleFrontier_ExchangeServiceCorner_EventScript_Start218
	case 18, BattleFrontier_ExchangeServiceCorner_EventScript_Start219
	case 19, BattleFrontier_ExchangeServiceCorner_EventScript_Start220
	case 20, BattleFrontier_ExchangeServiceCorner_EventScript_Start221
	case 21, BattleFrontier_ExchangeServiceCorner_EventScript_Start222
	case 22, BattleFrontier_ExchangeServiceCorner_EventScript_Start223
	case 23, BattleFrontier_ExchangeServiceCorner_EventScript_Start224
	case 24, BattleFrontier_ExchangeServiceCorner_EventScript_Start225
	case 25, BattleFrontier_ExchangeServiceCorner_EventScript_Start226
	case 26, BattleFrontier_ExchangeServiceCorner_EventScript_Start227
	case 27, BattleFrontier_ExchangeServiceCorner_EventScript_Start228
	case 28, BattleFrontier_ExchangeServiceCorner_EventScript_Start229
	case 29, BattleFrontier_ExchangeServiceCorner_EventScript_Start230
	case 30, BattleFrontier_ExchangeServiceCorner_EventScript_Start231
	case 31, BattleFrontier_ExchangeServiceCorner_EventScript_Start232
	case 32, BattleFrontier_ExchangeServiceCorner_EventScript_Start233
	case 33, BattleFrontier_ExchangeServiceCorner_EventScript_Start234
	case 34, BattleFrontier_ExchangeServiceCorner_EventScript_Start235
	case 35, BattleFrontier_ExchangeServiceCorner_EventScript_Start236
	case 36, BattleFrontier_ExchangeServiceCorner_EventScript_Start237
	case 37, BattleFrontier_ExchangeServiceCorner_EventScript_Start238
	case 38, BattleFrontier_ExchangeServiceCorner_EventScript_Start239
	case 39, BattleFrontier_ExchangeServiceCorner_EventScript_Start240
	case 40, BattleFrontier_ExchangeServiceCorner_EventScript_Start241
	case 41, BattleFrontier_ExchangeServiceCorner_EventScript_Start242
	case 42, BattleFrontier_ExchangeServiceCorner_EventScript_Start243
	case 43, BattleFrontier_ExchangeServiceCorner_EventScript_Start244
	case 44, BattleFrontier_ExchangeServiceCorner_EventScript_Start245
	case 45, BattleFrontier_ExchangeServiceCorner_EventScript_Start246
	case 46, BattleFrontier_ExchangeServiceCorner_EventScript_Start247
	case 47, BattleFrontier_ExchangeServiceCorner_EventScript_Start248
	case 48, BattleFrontier_ExchangeServiceCorner_EventScript_Start249
	case 49, BattleFrontier_ExchangeServiceCorner_EventScript_Start250
	case 50, BattleFrontier_ExchangeServiceCorner_EventScript_Start251
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start1::
	setwildbattle 1,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start2::
	setwildbattle 2,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start3::
	setwildbattle 3,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start4::
	setwildbattle 4,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start5::
	setwildbattle 5,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start6::
	setwildbattle 6,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start7::
	setwildbattle 7,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start8::
	setwildbattle 8,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start9::
	setwildbattle 9,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start10::
	setwildbattle 10,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start11::
	setwildbattle 11,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start12::
	setwildbattle 12,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start13::
	setwildbattle 13,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start14::
	setwildbattle 14,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start15::
	setwildbattle 15,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start16::
	setwildbattle 16,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start17::
	setwildbattle 17,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start18::
	setwildbattle 18,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start19::
	setwildbattle 19,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start20::
	setwildbattle 20,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start21::
	setwildbattle 21,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start22::
	setwildbattle 22,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start23::
	setwildbattle 23,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start24::
	setwildbattle 24,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start25::
	setwildbattle 25,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start26::
	setwildbattle 26,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start27::
	setwildbattle 27,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start28::
	setwildbattle 28,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start29::
	setwildbattle 29,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start30::
	setwildbattle 30,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start31::
	setwildbattle 31,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start32::
	setwildbattle 32,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start33::
	setwildbattle 33,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start34::
	setwildbattle 34,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start35::
	setwildbattle 35,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start36::
	setwildbattle 36,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start37::
	setwildbattle 37,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start38::
	setwildbattle 38,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start39::
	setwildbattle 39,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start40::
	setwildbattle 40,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start41::
	setwildbattle 41,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start42::
	setwildbattle 42,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start43::
	setwildbattle 43,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start44::
	setwildbattle 44,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start45::
	setwildbattle 45,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start46::
	setwildbattle 46,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start47::
	setwildbattle 47,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start48::
	setwildbattle 48,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start49::
	setwildbattle 49,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start50::
	setwildbattle 50,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start51::
	setwildbattle 51,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start52::
	setwildbattle 52,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start53::
	setwildbattle 53,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start54::
	setwildbattle 54,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start55::
	setwildbattle 55,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start56::
	setwildbattle 56,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start57::
	setwildbattle 57,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start58::
	setwildbattle 58,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start59::
	setwildbattle 59,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start60::
	setwildbattle 60,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start61::
	setwildbattle 61,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start62::
	setwildbattle 62,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start63::
	setwildbattle 63,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start64::
	setwildbattle 64,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start65::
	setwildbattle 65,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start66::
	setwildbattle 66,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start67::
	setwildbattle 67,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start68::
	setwildbattle 68,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start69::
	setwildbattle 69,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start70::
	setwildbattle 70,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start71::
	setwildbattle 71,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start72::
	setwildbattle 72,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start73::
	setwildbattle 73,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start74::
	setwildbattle 74,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start75::
	setwildbattle 75,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start76::
	setwildbattle 76,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start77::
	setwildbattle 77,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start78::
	setwildbattle 78,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start79::
	setwildbattle 79,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start80::
	setwildbattle 80,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start81::
	setwildbattle 81,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start82::
	setwildbattle 82,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start83::
	setwildbattle 83,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start84::
	setwildbattle 84,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start85::
	setwildbattle 85,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start86::
	setwildbattle 86,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start87::
	setwildbattle 87,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start88::
	setwildbattle 88,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start89::
	setwildbattle 89,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start90::
	setwildbattle 90,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start91::
	setwildbattle 91,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start92::
	setwildbattle 92,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start93::
	setwildbattle 93,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start94::
	setwildbattle 94,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start95::
	setwildbattle 95,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start96::
	setwildbattle 96,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start97::
	setwildbattle 97,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start98::
	setwildbattle 98,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start99::
	setwildbattle 99,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start100::
	setwildbattle 100,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start101::
	setwildbattle 101,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start102::
	setwildbattle 102,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start103::
	setwildbattle 103,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start104::
	setwildbattle 104,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start105::
	setwildbattle 105,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start106::
	setwildbattle 106,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start107::
	setwildbattle 107,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start108::
	setwildbattle 108,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start109::
	setwildbattle 109,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start110::
	setwildbattle 110,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start111::
	setwildbattle 111,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start112::
	setwildbattle 112,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start113::
	setwildbattle 113,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start114::
	setwildbattle 114,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start115::
	setwildbattle 115,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start116::
	setwildbattle 116,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start117::
	setwildbattle 117,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start118::
	setwildbattle 118,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start119::
	setwildbattle 119,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start120::
	setwildbattle 120,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start121::
	setwildbattle 121,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start122::
	setwildbattle 122,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start123::
	setwildbattle 123,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start124::
	setwildbattle 124,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start125::
	setwildbattle 125,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start126::
	setwildbattle 126,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start127::
	setwildbattle 127,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start128::
	setwildbattle 128,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start129::
	setwildbattle 129,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start130::
	setwildbattle 130,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start131::
	setwildbattle 131,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start132::
	setwildbattle 132,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start133::
	setwildbattle 133,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start134::
	setwildbattle 134,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start135::
	setwildbattle 135,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start136::
	setwildbattle 136,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start137::
	setwildbattle 137,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start138::
	setwildbattle 138,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start139::
	setwildbattle 139,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start140::
	setwildbattle 140,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start141::
	setwildbattle 141,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start142::
	setwildbattle 142,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start143::
	setwildbattle 143,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start144::
	setwildbattle 144,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start145::
	setwildbattle 145,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start146::
	setwildbattle 146,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start147::
	setwildbattle 147,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start148::
	setwildbattle 148,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start149::
	setwildbattle 149,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start150::
	setwildbattle 150,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start151::
	setwildbattle 151,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start152::
	setwildbattle 152,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start153::
	setwildbattle 153,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start154::
	setwildbattle 154,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start155::
	setwildbattle 155,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start156::
	setwildbattle 156,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start157::
	setwildbattle 157,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start158::
	setwildbattle 158,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start159::
	setwildbattle 159,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start160::
	setwildbattle 160,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start161::
	setwildbattle 161,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start162::
	setwildbattle 162,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start163::
	setwildbattle 163,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start164::
	setwildbattle 164,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start165::
	setwildbattle 165,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start166::
	setwildbattle 166,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start167::
	setwildbattle 167,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start168::
	setwildbattle 168,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start169::
	setwildbattle 169,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start170::
	setwildbattle 170,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start171::
	setwildbattle 171,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start172::
	setwildbattle 172,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start173::
	setwildbattle 173,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start174::
	setwildbattle 174,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start175::
	setwildbattle 175,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start176::
	setwildbattle 176,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start177::
	setwildbattle 177,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start178::
	setwildbattle 178,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start179::
	setwildbattle 179,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start180::
	setwildbattle 180,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start181::
	setwildbattle 181,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start182::
	setwildbattle 182,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start183::
	setwildbattle 183,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start184::
	setwildbattle 184,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start185::
	setwildbattle 185,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start186::
	setwildbattle 186,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start187::
	setwildbattle 187,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start188::
	setwildbattle 188,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start189::
	setwildbattle 189,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start190::
	setwildbattle 190,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start191::
	setwildbattle 191,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start192::
	setwildbattle 192,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start193::
	setwildbattle 193,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start194::
	setwildbattle 194,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start195::
	setwildbattle 195,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start196::
	setwildbattle 196,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start197::
	setwildbattle 197,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start198::
	setwildbattle 198,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start199::
	setwildbattle 199,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start200::
	setwildbattle 200,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start201::
	setwildbattle 201,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start202::
	setwildbattle 202,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start203::
	setwildbattle 203,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start204::
	setwildbattle 204,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start205::
	setwildbattle 205,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start206::
	setwildbattle 206,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start207::
	setwildbattle 207,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start208::
	setwildbattle 208,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start209::
	setwildbattle 209,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start210::
	setwildbattle 210,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start211::
	setwildbattle 211,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start212::
	setwildbattle 212,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start213::
	setwildbattle 213,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start214::
	setwildbattle 214,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start215::
	setwildbattle 215,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start216::
	setwildbattle 216,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start217::
	setwildbattle 217,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start218::
	setwildbattle 218,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start219::
	setwildbattle 219,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start220::
	setwildbattle 220,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start221::
	setwildbattle 221,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start222::
	setwildbattle 222,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start223::
	setwildbattle 223,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start224::
	setwildbattle 224,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start225::
	setwildbattle 225,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start226::
	setwildbattle 226,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start227::
	setwildbattle 227,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start228::
	setwildbattle 228,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start229::
	setwildbattle 229,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start230::
	setwildbattle 230,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start231::
	setwildbattle 231,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start232::
	setwildbattle 232,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start233::
	setwildbattle 233,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start234::
	setwildbattle 234,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start235::
	setwildbattle 235,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start236::
	setwildbattle 236,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start237::
	setwildbattle 237,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start238::
	setwildbattle 238,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start239::
	setwildbattle 239,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start240::
	setwildbattle 240,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start241::
	setwildbattle 241,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start242::
	setwildbattle 242,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start243::
	setwildbattle 243,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start244::
	setwildbattle 244,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start245::
	setwildbattle 245,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start246::
	setwildbattle 246,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start247::
	setwildbattle 247,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start248::
	setwildbattle 248,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start249::
	setwildbattle 249,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start250::
	setwildbattle 250,1
	dowildbattle
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Start251::
	setwildbattle 251,1
	dowildbattle
	end
