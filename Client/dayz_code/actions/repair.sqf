private["_vehicle","_part","_hitpoint","_type","_selection","_array"];

if (repairInProgress) exitWith { systemChat "Repair already in progress."; };
repairInProgress = true;

_id = _this select 2;
_array = 	_this select 3;
_vehicle = 	_array select 0;
_part =		_array select 1;
_hitpoint = _array select 2;
_type = typeOf _vehicle;

//
_hasToolbox = 	"ItemToolbox" in magazines player;
_section = _part in magazines player;

//moving this here because we need to know which part needed if we don't have it
_nameType = 		getText(configFile >> "cfgVehicles" >> _type >> "displayName");
_namePart = 		getText(configFile >> "cfgMagazines" >> _part >> "displayName");

{_vehicle removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
s_player_repair_ctrl = 1;

if (!_hasToolbox) then {
	systemChat "You must have a toolbox to repair this!";
};

if (!_section) then {
	systemChat format["You must have [a(n)] %1 to repair this!",_namePart];
};

if (_section and _hasToolbox) then {

	player playActionNow "Medic";
	
	[player,"repair",0,false,20] call dayz_zombieSpeak;
	[player,20,true,(getPosATL player)] spawn player_alertZombies;
	
	r_interrupt = false;
	_animState = animationState player;
	r_doLoop = true;
	_started = false;
	_finished = false;
	
	while { r_doLoop } do {
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
		systemChat "Repair was canceled...";
		_finished = false;
	};
	
	if (_finished) then {
	
		_damage = [_vehicle,_hitpoint] call object_getHit;
		_vehicle removeAction _id;
		
		if (_damage > 0) then {
			_num_removed = player removeMagazine _part;
		
			_selection = getText (configFile >> "cfgVehicles" >> _type >> "HitPoints" >> _hitpoint >> "name");
			
			dayzSetFix = [_vehicle,_selection,0];
			publicVariable "dayzSetFix";
			if (local _vehicle) then {
				dayzSetFix call object_setFixServer;
			};
			
			_vehicle setVelocity [0,0,1];
			
			systemChat format["You have successfully attached %1 to the %2",_namePart,_nameType];
		};
	};

	//check if repaired fully
	_hitpoints = _vehicle call vehicle_getHitpoints;
	_allFixed = true;
	{
		_damage = [_vehicle,_x] call object_getHit;
		if (_damage > 0) exitWith {
			_allFixed = false;
		};
	} forEach _hitpoints;

	//update if repaired
	if (_allFixed) then {
		_vehicle setDamage 0;
		//["dayzUpdateVehicle",[_vehicle,"repair"]] call callRpcProcedure;
		dayzSetFix = [_vehicle,_selection,0];
		publicVariable "dayzSetFix";
		if (local _vehicle) then {
			dayzSetFix call object_setFixServer;
		};
	};
};

{dayz_myCursorTarget removeAction _x} forEach s_player_repairActions;s_player_repairActions = [];
dayz_myCursorTarget = objNull;

s_player_repair_ctrl = -1;

repairInProgress = false;