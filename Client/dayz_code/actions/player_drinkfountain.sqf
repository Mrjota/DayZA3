
private["_onLadder","_itemorignal","_hasdrinkitem","_hasoutput","_config","_text","_sfx","_dis","_id","_itemtodrop","_nearByPile","_item","_display"];
disableserialization;

_onLadder =     (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText ["You may not drink while in a vehicle", "PLAIN DOWN"]};

player playActionNow "PutDown";
sleep 0.5;

dayz_lastDrink = time;
dayz_thirst = 0;
player setVariable ["messing",[dayz_hunger,dayz_thirst],true];

_display = uiNamespace getVariable 'DAYZ_GUI_display';
(_display displayCtrl 1302) ctrlShow true;

cutText ["You drank from the fountain.", "PLAIN DOWN"];

player removeAction dayz_drinkFromFountain;
dayz_drinkFromFountain = -1;

[] spawn {
	player enableFatigue false;
	_curTime = time;
	waitUntil {time - _curTime >= 7};
	player enableFatigue true;
};

_fatigue = getFatigue player;
if (_fatigue >= 0.5) then {
    player setFatigue (_fatigue - 0.5);
};