
#define Use_Display 2553
#define flist 2505
#define dlist 2506
#define mlist 2507
disableSerialization;
closeDialog 0;
_start = createDialog "useManagement";
_dialog = findDisplay Use_Display;
_foodBox = _dialog displayCtrl flist;
_drinkBox = _dialog displayCtrl dlist;
_medBox = _dialog displayCtrl mlist;
lbClear _foodBox;
lbClear _drinkBox;
lbClear _medBox;

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
			systemChat _mag;
			_name = getText(configFile >> "cfgMagazines" >> _mag >> "displayName");
			_pic = getText(configFile >> "cfgMagazines" >> _mag >> "picture");
			if (_mag in _foodArray) then {
				_index = _foodBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_foodBox lbSetData [_index, _mag];
				_foodBox lbSetPicture [_index, _pic];
			};
			if (_mag in _drinkArray) then {
				_index = _drinkBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_drinkBox lbSetData [_index, _mag];
				_drinkBox lbSetPicture [_index, _pic];
			};
			systemChat "1";
			if (_mag in _medArray) then {
			systemChat "2";
				_index = _medBox lbAdd format["[%1] %2",({_x == _mag} count ((vestItems player) + (backpackItems player))),_name];
				_medBox lbSetData [_index, _mag];
				_medBox lbSetPicture [_index, _pic];
			systemChat "3";
			};
		};
	};
} forEach ((vestItems player) + (backpackItems player));