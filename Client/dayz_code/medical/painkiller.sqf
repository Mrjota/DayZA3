// bleed.sqf
_unit = (_this select 3) select 0;

_unit setVariable ["USEC_inPain", false, true];

call fnc_usec_medic_removeActions;
r_action = false;

if (vehicle player == player) then {
	//not in a vehicle
	player playActionNow "Gear";
};

if (_unit == player) then {
	//Self Healing
	_id = [player,player] execVM "\z\addons\dayz_code\medical\publicEH\medPainkiller.sqf";
} else {
	//dayzHumanity = [player,20];
	[player,20] call player_humanityChange;
};

player removeMagazine "ItemPainkiller";

_curTime = time;
waitUntil {time - _curTime >= 1};
	usecPainK = [_unit,player];
	publicVariable "usecPainK";

        [] spawn {
        player enableFatigue false;
		_curTime = time;
		waitUntil {time - _curTime >= 5};
        player enableFatigue true;
        };