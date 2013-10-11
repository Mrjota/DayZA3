private["_vehicle","_curFuel","_newFuel","_timeLeft"];
_vehicle = 		cursorTarget;
_hasJerryE =    "ItemJerrycanEmpty" in magazines player;

_configVeh = 	configFile >> "cfgVehicles" >> TypeOf(_vehicle);
_capacity = 	getNumber(_configVeh >> "fuelCapacity");
_nameType = 	getText(_configVeh >> "displayName");
_curFuel = 		((fuel _vehicle) * _capacity);
_newFuel = 		(_curFuel - 20);

if (_curFuel < 20) exitWith {cutText ["The vehicle doesn't have enough fuel to fill the jerry can.", "PLAIN DOWN"];};
_newFuel = (_newFuel / _capacity);

player playActionNow "Medic";
_dis=10;
_sfx = "refuel";
[player,_sfx,0,false,_dis] call dayz_zombieSpeak;  
[player,_dis,true,(getPosATL player)] spawn player_alertZombies;

_curTime = time;
waitUntil {time - _curTime >= 6};

player removeMagazine "ItemJerrycanEmpty";
player addMagazine "ItemJerrycan";

dayzSetFuel = [_vehicle,_newFuel];
dayzSetFuel spawn local_setFuel;
publicVariable "dayzSetFuel";

cutText ["20 liters of Fuel has been siphoned.", "PLAIN DOWN"];
_curTime = time;
waitUntil {time - _curTime >= 1};

call fnc_usec_medic_removeActions;
r_action = false;