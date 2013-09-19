//Assess Terrain
private["_unit","_pos","_type","_typeA","_soundType","_soundVal","_array","_test"];
_unit = 	_this;
_pos = 		getPosATL _unit;
_type = 	surfaceType _pos;
_typeA = 	toArray _type;
_typeA 		set [0,"DEL"];
_typeA = 	_typeA - ["DEL"];
_type = 	toString _typeA;
_test = 	0;

//diag_log ("FINDME: " + _type);

_soundType = 	getText (configFile >> "CfgSurfaces" >> _type >> "soundEnviron");
_valArray = getArray (configFile >> "CfgVehicles" >> "CAManBase" >> "SoundEnvironExt" >> _soundType);
if (count _valArray > 0) then { _valArray = _valArray select 0; };
if (count _valArray > 0) then { _valArray = _valArray select 1; };
if (typeName _valArray == "ARRAY") then { if (count _valArray > 0) then { _valArray = _valArray select 3; }; };
_soundVal =		parseNumber format["%1", _valArray];
if (_soundVal == 0) then {
	_soundVal = 25;
};
_array = [_soundType,_soundVal];
_array