.set LOCALID_ROOT_FOSSIL, 1
.set LOCALID_CLAW_FOSSIL, 2

MirageTower_4F_MapScripts:: @ 823AD47
	.byte 0

MirageTower_4F_EventScript_RootFossil:: @ 823AD48
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MirageTower_4F_EventScript_LeaveRootFossil
	call GiveTheFossil
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject LOCALID_ROOT_FOSSIL
	delay 30
	setflag FLAG_CHOSE_ROOT_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRootFossil:: @ 823AD7F
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil:: @ 823AD89
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MirageTower_4F_EventScript_LeaveClawFossil
	call GiveTheFossil
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_CLAW_FOSSIL
	delay 30
	setflag FLAG_CHOSE_ROOT_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveClawFossil:: @ 823ADC0
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

GiveTheFossil::
	call GetItem_Root_Fossil
	return

MirageTower_4F_EventScript_CollapseMirageTower:: @ 823ADCA
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 255, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_TakeRootFossil: @ 823ADF9
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_LeftRootFossilAlone: @ 823AE79
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_TakeClawFossil: @ 823AE98
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveClawFossilAlone: @ 823AF18
	.string "{PLAYER} left the CLAW FOSSIL alone.$"

