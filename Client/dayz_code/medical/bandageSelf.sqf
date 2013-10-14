// bleed.sqf
_unit = objNull;
if (typeName (_this select 0) != 'STRING') then {
	_unit = (_this select 3) select 0;
} else {
	if ((_this select 0) == "use") then {
		_unit = player;
	};
};

call fnc_usec_medic_removeActions;
r_action = false;

if (vehicle player == player) then {
	//not in a vehicle
	player playActionNow "Medic";
};

if (_unit == player) then {
	//Self Healing
	_id = [player,player] execVM "\z\addons\dayz_code\medical\publicEH\medBandaged.sqf";
} else {
	//dayzHumanity = [player,20];
	[player,20] call player_humanityChange;
};

	{
	_unit setVariable[_x,false,true];
	} forEach USEC_woundHit;
	_unit setVariable ["USEC_injured",false,true];

player removeMagazine "ItemBandage";

_curTime = time;
waitUntil {time - _curTime >= 1};
//clear the healed player's vision
//["usecPainK",[_unit,player]] call broadcastRpcCallAll;
	usecPainK = [_unit,player];
	publicVariable "usecPainK";
