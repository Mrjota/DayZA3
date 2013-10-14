
#define Use_Display 2553
#define flist 2505
#define dlist 2506
#define mlist 2507

disableSerialization;

_type = _this select 0;

_dialog = findDisplay Use_Display;
_foodBox = _dialog displayCtrl flist;
_drinkBox = _dialog displayCtrl dlist;
_medBox = _dialog displayCtrl mlist;

switch (_type) do {
	case 0:
	{
		lbClear _foodBox;
		lbClear _drinkBox;
		lbClear _medBox;
	};
	case 1:
	{
		lbClear _foodBox;
	};
	case 2:
	{
		lbClear _drinkBox;
	};
	case 3:
	{
		lbClear _medBox;
	};
};

_foodArray = food_with_output + no_output_food;
_drinkArray = no_output_drink + drink_with_output;
_medArray = ["SurvivalPack","ItemBandage","ItemEpinephrine","ItemMorphine","ItemHeatPack","ItemPainkiller","ItemAntibiotic"];

_magArray = [];
{
	_isOk = isClass (configFile >> "CfgMagazines" >> _x);
	if (_isOk) then {
		if (!(_x in _magArray)) then {
			_magArray set[count _magArray,_x];
			_mag = _x;
			_name = getText(configFile >> "cfgMagazines" >> _x >> "displayName");
			_pic = getText(configFile >> "cfgMagazines" >> _x >> "picture");
			if ((_mag in _foodArray) and ((_type == 0) or (_type == 1))) then {
				_index = _foodBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_foodBox lbSetData [_index, _mag];
				_foodBox lbSetPicture [_index, _pic];
			};
			if ((_mag in _drinkArray) and ((_type == 0) or (_type == 2))) then {
				_index = _drinkBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_drinkBox lbSetData [_index, _mag];
				_drinkBox lbSetPicture [_index, _pic];
			};
			if ((_mag in _medArray) and ((_type == 0) or (_type == 3))) then {
				_index = _medBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_medBox lbSetData [_index, _mag];
				_medBox lbSetPicture [_index, _pic];
			};
		};
	};
} forEach ((vestItems player) + (backpackItems player));
