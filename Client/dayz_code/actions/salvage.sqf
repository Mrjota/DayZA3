private ["_vehicle","_part","_hitpoint","_type","_selection","_array","_started","_finished","_animState","_isMedic","_isOK","_brokenPart","_findPercent","_damage","_hasToolbox","_nameType","_namePart"];

if(repairInProgress) exitWith { systemChat "Salvage already in progress."; };
repairInProgress = true;

//_id = _this select 2;
_array = 	_this select 3;
_vehicle = 	_array select 0;
_part =		_array select 1;
_hitpoint = _array select 2;
_type = typeOf _vehicle; 

_isOK = false;
_brokenPart = false;

//
_hasToolbox = 	"ItemToolbox" in magazines player;

// moving this here because we need to know which part needed if we don't have it
_nameType = 		getText(configFile >> "cfgVehicles" >> _type >> "displayName");
_namePart = 		getText(configFile >> "cfgMagazines" >> _part >> "displayName");

{_vehicle removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
s_player_repair_ctrl = 1;

if (!_hasToolbox) then {
	systemChat "You must have a toolbox to salvage!";
};

if (_hasToolbox) then {

	player playActionNow "Medic";

	[player,"repair",0,false] call dayz_zombieSpeak;
	[player,50,true,(getPosATL player)] spawn player_alertZombies;

	r_interrupt = false;
	_animState = animationState player;
	r_doLoop = true;
	_started = false;
	_finished = false;
	
	while {r_doLoop} do {
		_animState = animationState player;
		_isMedic = ["medic",_animState] call fnc_inString;
		if (_isMedic) then {
			_started = true;
		};
		if (_started and !_isMedic) then {
			r_doLoop = false;
			_finished = true;
		};
		if (r_interrupt) then {
			r_doLoop = false;
		};
		sleep 0.1;
	};
	r_doLoop = false;

	if (s_player_repair_ctrl == -1) then {
		r_interrupt = false;
		if (vehicle player == player) then {
			player playActionNow "stop";
		};
		systemChat "Salvage was canceled...";
		_finished = false;
	};

	if (_finished) then {
	
		_damage = [_vehicle,_hitpoint] call object_getHit;
		// _vehicle removeAction _id;
	
		if (_damage < 1) then {
		
			_findPercent = (1 - _damage) * 10;
			_isOK = true; //Force isOK
			//Random break part chance
			if(ceil (random _findPercent) == 1) then {
				_brokenPart = true;
			} else {
				_brokenPart = false;
			};
		
			if (_isOK) then {
				if(_brokenPart) then {
					//Failed!
					_selection = getText(configFile >> "cfgVehicles" >> _type >> "HitPoints" >> _hitpoint >> "name");
					systemChat format["You have destroyed the %1 while attempting to remove from the %2",_namePart,_nameType];
					dayzSetFix = [_vehicle,_selection,1];
					publicVariable "dayzSetFix";
					//if (local _vehicle) then {
						dayzSetFix call object_setFixServer;
					//};
				} else {
					//Success!
					_selection = getText(configFile >> "cfgVehicles" >> _type >> "HitPoints" >> _hitpoint >> "name");
			
					dayzSetFix = [_vehicle,_selection,0.85];
					publicVariable "dayzSetFix";
					//if (local _vehicle) then {
						dayzSetFix call object_setFixServer;
					//};

					_vehicle setvelocity [0,0,1];
					
					systemChat format["You have successfully removed the %1 from the %2",_namePart,_nameType];
					
					_stack = createVehicle ["GroundWeaponHolder", position player, [], 0, "CAN_COLLIDE"];
					_stack addMagazineCargoGlobal [_part, 1];
				};

			} else {
				cutText [localize "STR_DAYZ_CODE_2", "PLAIN DOWN"];
			};
		
		};
	
	};
			
} else {
	systemChat format["You need [a(n)] %1 to remove this part.",_namePart];
};

dayz_myCursorTarget = objNull;
s_player_repair_ctrl = -1;

repairInProgress = false;