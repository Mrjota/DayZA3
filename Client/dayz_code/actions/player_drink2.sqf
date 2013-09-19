private["_onLadder","_itemorignal","_hasdrinkitem","_hasoutput","_config","_text","_sfx","_dis","_id","_itemtodrop","_nearByPile","_item","_display"];
disableserialization;

_onLadder =     (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {cutText [(localize "str_player_21") , "PLAIN DOWN"]};

if (vehicle player != player) exitWith {cutText ["You may not drink while in a vehicle", "PLAIN DOWN"]};

//Force players to wait 3 mins to drink again
//if (dayz_lastDrink < 180) exitWith {cutText ["You may not drink, your not thirsty", "PLAIN DOWN"]};

_itemorignal2 = no_output_drink + drink_with_output;
_itemorignal = "ItemSodaPepsi";
{
if (_x in _itemorignal2) then {
_itemorignal = _x;
_hasdrinkitem = true;
};
} forEach (magazines player);
_hasoutput = _itemorignal in drink_with_output;

_config = configFile >> "CfgMagazines" >> _itemorignal;
_text = getText (_config >> "displayName");

//getting type of sfx (now just drink od soda open and drink)
_sfx =  getText (_config >> "sfx");

if (!_hasdrinkitem) exitWith {cutText [format[(localize "str_player_31"),_text,"drink"] , "PLAIN DOWN"]};

player playActionNow "PutDown";
player removeMagazine _itemorignal;
sleep 0.5;

if (["ItemWaterbottle",_itemorignal] call fnc_inString) then {
    //low alert and sound radius
    _dis=5;
    [player,_sfx,0,false,_dis] call dayz_zombieSpeak;
    [player,_dis,true,(getPosATL player)] spawn player_alertZombies;
    player addMagazine "ItemWaterbottleUnfilled";
};
if (["ItemSoda",_itemorignal] call fnc_inString) then {
    //higher alert and sound radius
    _dis=10;
    [player,_sfx,0,false,_dis] call dayz_zombieSpeak;
    _id = [player,_dis,true,(getPosATL player)] spawn player_alertZombies;
};  

if (_hasoutput) then{
    // Selecting output
    _itemtodrop = drink_output select (drink_with_output find _itemorignal);

    sleep 0.1;
    _nearByPile= nearestObjects [(position player), ["WeaponHolder","WeaponHolderBase"],2];
    if (count _nearByPile ==0) then { 
        _item = createVehicle ["WeaponHolder", position player, [], 0.0, "CAN_COLLIDE"];
    } else {
        _item = _nearByPile select 0;
    };
    _item addMagazineCargoGlobal [_itemtodrop,1];
};





//add infection chance for "ItemWaterbottle", 
if ((random 15 < 1) and (_itemorignal == "ItemWaterbottle")) then {
    r_player_infected = true;
    player setVariable["USEC_infected",true,true];
};

dayz_lastDrink = time;
dayz_thirst = 0;

player setVariable ["messing",[dayz_hunger,dayz_thirst],true];

//Ensure Control is visible
_display = uiNamespace getVariable 'DAYZ_GUI_display';
(_display displayCtrl 1302) ctrlShow true;

cutText [format[(localize  "str_player_consumed"),_text], "PLAIN DOWN"];

player removeAction dayz_thirst2;
dayz_thirst2 = -1;

_fatigue = getFatigue player;
if (_fatigue >= 0.3) then {
    player setFatigue (_fatigue - 0.3);
};

if (_itemorignal == "ItemSodaLemonade") then {
    [] spawn {
        player enableFatigue false;
        sleep 60;
        player enableFatigue true;
    };
} else {
    [] spawn {
        player enableFatigue false;
        sleep 7;
        player enableFatigue true;
    };
};