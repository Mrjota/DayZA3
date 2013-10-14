if (!isnil "Press_A3") then 
{
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", Press_A3];
};

Bindings_A3 =
{
	private ["_key", "_return"];
	_key = _this select 1;
	_return = false;
    
	switch (_key) do 
	{
		case 41: //TILDE
		{
            createDialog "menuDiag";
		};
		/*
		case 211: // DELETE
		{
            [] execVM "\z\addons\dayz_code\group\dialog\groupMenu.sqf";
		};
		case 199: //HOME
		{
            [] execVM "\z\addons\dayz_code\ammo\listB.sqf";
		};
		*/
        case 14: //BACKSPACE
        {
            if (r_player_onVehicleC and alive player) then {
                [] execVM "\z\addons\dayz_code\actions\player_getout.sqf";
            };
        };
	};
    _return
};

waituntil {!isnull (finddisplay 46)};
Press_A3 = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call Bindings_A3; _this call dayz_spaceInterrupt; false;"];