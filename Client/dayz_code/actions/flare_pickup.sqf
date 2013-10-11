private["_flare"];
_flare = (_this select 3) select 0;
_text = (_this select 3) select 1;
player playActionNow "PutDown";
_curTime = time;
waitUntil {time - _curTime >= 2};
_flare attachTo [player,[0,0,0],"granat2"];
[_flare, -90, -10] call object_setpitchbank;
_flare setPos (getPos _flare);
_flare setVariable ["owner",player,true];
player removeAction s_player_grabflare;
player removeAction s_player_removeflare;
player removeAction s_player_grabflare2;
player removeAction s_player_removeflare2;
player removeAction s_player_grabflare3;
player removeAction s_player_removeflare3;
player removeAction s_player_grabflare4;
player removeAction s_player_removeflare4;
player removeAction s_player_grabflare5;
player removeAction s_player_removeflare5;
dayz_hasLight = true;

//Add Drop Action
s_player_dropflare = player addAction [format["Drop %1",_text], "\z\addons\dayz_code\actions\flare_drop.sqf",_flare, 1, false, true, "", ""];

while {(alive _flare) and dayz_hasLight} do {
	_curTime = time;
	waitUntil {time - _curTime >= 1};
};
if (dayz_hasLight) then {
	dayz_hasLight = false;
	player removeAction s_player_dropflare;
	player removeAction s_player_hideflare;
	player removeAction s_player_showflare;
    s_player_dropflare = -1;
	s_player_grabflare = -1;
	s_player_removeflare = -1;
	s_player_grabflare2 = -1;
	s_player_removeflare2 = -1;
	s_player_grabflare3 = -1;
	s_player_removeflare3 = -1;
	s_player_grabflare4 = -1;
	s_player_removeflare4 = -1;
	s_player_grabflare5 = -1;
	s_player_removeflare5 = -1;
};
