.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts:: @ 823AF37
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition: @ 823AF3D
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil:: @ 823AF41
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil:: @ 823AF57
	goto GiveUnderFossil
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil:: @ 823AF68
	goto GiveUnderFossil
	removeobject LOCALID_FOSSIL
	release
	end

GiveUnderFossil::
	call GetItem_Claw_Fossil
	return

@ Unused
DesertUnderpass_Text_FoundRootFossil:: @ 823AF79
	.string "{PLAYER} found the ROOT FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil:: @ 823AF93
	.string "{PLAYER} found the CLAW FOSSIL.$"

