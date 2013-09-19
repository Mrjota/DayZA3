private ["_objects"];

_objects = nearestObjects [getPosATL player, ["Car", "Helicopter", "Motorcycle", "Ship", "TentStorage", "ACampStorage"], 10];
{
	dayzUpdateVehicle = [_x,"gear"];
	publicVariable "dayzUpdateVehicle";
	
} foreach _objects;

private["_dialog","_magazineArray","_control","_item","_val","_max"];

disableSerialization;
_dialog = 			_this select 0;
_magazineArray = 	[];

_config = configFile >> "CfgMagazines";
_data = [];

for "_i" from 0 to (count _config)-1 do {
  _current = _config select _i;
  if(isClass _current) then {
    if(getNumber(_current>>"scope")==2 && getText(_current>>"picture")!="" &&
      getNumber(_current>>"count")>=5
    ) then {
      _data=_data+[configName _current];
    };
  };
};
dayz_unsaved = true;
dayz_Magazines = _data;