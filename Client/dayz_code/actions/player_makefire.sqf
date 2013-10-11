private["_location","_isOk","_dir","_classname"];
_location = player modeltoworld [0,0.3,0];
if ((_location select 2) < 0) then {
	_location set [2,0];
};
//_location set [2,0];
_isOk = true; //count (_location isFlatEmpty [0.3,0,0,4,0,false,player]) > 0;
_hasWood = 		"PartWoodPile" in magazines player;
_hasMatch = 		"ItemMatchbox" in magazines player;

if (_hasWood) then {
if (_hasMatch) then {
	if (_isOk) then {
			player removeMagazine "PartWoodPile";
			_dir = getDir player;
			_classname = "Land_Fire_DZ";
			player playActionNow "Medic";
			_curTime = time;
			waitUntil {time - _curTime >= 6};
			_fire = createVehicle [_classname, _location, [], 0, "CAN_COLLIDE"];
			_fire setDir _dir;
			player reveal _fire;
			
			_id = _fire spawn player_fireMonitor;
			
			cutText [localize "str_fireplace_01", "PLAIN DOWN"];
	} else {
		cutText [localize "str_fireplace_02", "PLAIN DOWN"];
	};
    } else {
    cutText ["You must have matches in order to setup a camp fire!", "PLAIN DOWN"];
    };
} else {
	cutText [localize "str_player_22", "PLAIN DOWN"];
};