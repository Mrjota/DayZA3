private["_refObj","_size","_vel","_speed","_hunger","_thirst","_array","_unsaved","_timeOut","_result","_lastSave"];
disableSerialization;
_timeOut = 	0;
_messTimer = 0;
_lastSave = 0;
_lastTemp = dayz_temperatur;
_debug = getMarkerpos "respawn_west";
_isBandit = false;
_isHero = false;
_isAssassin = false;
_isGuardian = false;

player setVariable ["temperature",dayz_temperatur,true];

dayz_myLoad = (((count dayz_myBackpackMags) * 0.2) + (count dayz_myBackpackWpns)) +  (((count dayz_myMagazines) * 0.1) + (count dayz_myWeapons * 0.5));

	//player addMagazine "Hatchet_swing";
	//player addWeapon "MeleeHatchet";

while {true} do {
	//Initialize
	_refObj = 	vehicle player;
	_size = 	(sizeOf typeOf _refObj) * 0.6;
	_vel = 		velocity player;
    _mylastPos =    getPosATL player;
	_speed = 	round((_vel distance [0,0,0]) * 3.5);
    _typeOf =    typeOf player;
	_saveTime = 5;
    if ((playersNumber west > 10) and (playersNumber west <= 20)) then {
    _saveTime = 10;
    };
    if ((playersNumber west > 20) and (playersNumber west <= 30)) then {
    _saveTime = 15;
    };
    if (playersNumber west > 30) then {
    _saveTime = 20;
    };
		
	//reset position
	_randomSpot = true;
	_tempPos = getPosATL player;
	_distance = _debug distance _tempPos;
	if (_distance < 2000) then {
		_randomSpot = false;
	};	
	_distance = [0,0,0] distance _tempPos;
	if (_distance < 500) then {
		_randomSpot = false;
	};
	_distance = _mylastPos distance _tempPos;
	if (_distance > 400) then {
		_randomSpot = false;
	};
	
	if (_randomSpot) then {
		_mylastPos = _tempPos;
	};
	
	dayz_areaAffect = _size;
	
	//CheckVehicle
	/*
	if (_refObj != player) then {
		_isSync =_refObj getVariable ["ObjectID",0] > 0;
		if (!_isSync) then {
			_veh allowDamage true;
			_veh setDamage 1;
			player setDamage 1;			
		};
	};
	*/
	
	if (_speed > 0.1) then {
		_timeOut = _timeOut + 1;
	};
	
	_humanity = player getVariable ["humanity",0];
	if ((_timeOut > 300) and (_typeOf != "Bandit2_DZ")) then {
		_timeOut = 0;
		if (_humanity < 2500) then {
			_humanity = _humanity + 100;
			_humanity = _humanity min 2500;
			player setVariable ["humanity",_humanity,true];
		};
	};
	
	if (_humanity < -12000 and !_isAssassin) then {
		_isBandit = false;
        _isHero = false;
        _isGuardian = false;
        _isAssassin = true;
		_model = typeOf player;
		if ((_model == "Survivor2_DZ") or (_model == "Bandit1_DZ") or (_model == "Survivor3_DZ") or (_model == "Survivor4_DZ")) then {
			[dayz_playerUID,dayz_characterID,"Bandit2_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity > -12000 and _humanity < -2000 and !_isBandit) then {
		_isBandit = true;
        _isHero = false;
        _isGuardian = false;
        _isAssassin = false;
		_model = typeOf player;
		if ((_model == "Survivor2_DZ") or (_model == "Bandit2_DZ") or (_model == "Survivor3_DZ") or (_model == "Survivor4_DZ")) then {
			[dayz_playerUID,dayz_characterID,"Bandit1_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity > 0 and (_isBandit or _isAssassin)) then {
		_isBandit = false;
        _isAssassin = false;
		_model = typeOf player;
		if ((_model == "Bandit1_DZ") or (_model == "Bandit2_DZ")) then {
			[dayz_playerUID,dayz_characterID,"Survivor2_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity < 15000 and _humanity > 5000 and !_isHero) then {
		_isBandit = false;
        _isHero = true;
        _isGuardian = false;
        _isAssassin = false;
		_model = typeOf player;
		if ((_model == "Survivor2_DZ") or (_model == "Bandit1_DZ") or (_model == "Bandit2_DZ") or (_model == "Survivor4_DZ")) then {
			[dayz_playerUID,dayz_characterID,"Survivor3_DZ"] spawn player_humanityMorph;
		};
	};
	
	if (_humanity > 15000 and !_isGuardian) then {
		_isBandit = false;
        _isHero = false;
        _isGuardian = true;
        _isAssassin = false;
		_model = typeOf player;
		if ((_model == "Survivor2_DZ") or (_model == "Bandit1_DZ") or (_model == "Bandit2_DZ") or (_model == "Survivor3_DZ")) then {
			[dayz_playerUID,dayz_characterID,"Survivor4_DZ"] spawn player_humanityMorph;
		};
	};
	
	//Has infection?
	//if (r_player_infected) then {
	//	[player,"cough",8,false] call dayz_zombieSpeak;
	//};

	//Record Check
	_lastUpdate = 	time - dayZ_lastPlayerUpdate;
	if (_lastUpdate > 8) then {
		//POSITION?
		_distance = dayz_myPosition distance player;
		if (_distance > 10) then {
			//Player has moved
			dayz_myPosition = getPosATL player;
			player setVariable["posForceUpdate",true,true];
			dayz_unsaved = true;
			dayZ_lastPlayerUpdate = time;
		};
	};

	//Hunger
	if ((_refObj == player) and (!r_player_onVehicleC)) then {
	_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5) + _speed + dayz_myLoad);
    } else {
	_hunger = +((((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal) * 5));
    };
	if (time - dayz_panicCooldown < 120) then {
		_hunger = _hunger * 2;
	};
	dayz_hunger = dayz_hunger + (_hunger / 60);

	//Thirst
	_thirst = 27;
	if ((_refObj == player) and (!r_player_onVehicleC)) then {
		_thirst = (_speed + 4) * 3;
	};
	dayz_thirst = dayz_thirst + (_thirst / 60) * (dayz_temperatur / dayz_temperaturnormal);	//TeeChange Temperatur effects added Max Effects: -25% and + 16.6% waterloss

	//Temperatur
	2 call player_temp_calculation; //2 = sleep time of this loop		//TeeChange
	if ((_lastTemp - dayz_temperatur) > 0.75 or (_lastTemp - dayz_temperatur) < -0.75 ) then {
		player setVariable ["temperature",dayz_temperatur,true];
		_lastTemp = dayz_temperatur;
	};
	
	//can get nearby infection
	if (!r_player_infected) then {
		//	Infectionriskstart
		if (dayz_temperatur < ((80 / 100) * (dayz_temperaturnormal - dayz_temperaturmin) + dayz_temperaturmin)) then {	//TeeChange
			_listTalk = _mylastPos nearEntities ["CAManBase",8];
			{
				if (_x getVariable["USEC_infected",false]) then {
					_rnd = (random 1) * (((dayz_temperaturnormal - dayz_temperatur) * (100 /(dayz_temperaturnormal - dayz_temperaturmin)))/ 50);	//TeeChange
					if (_rnd < 0.1) then {
						_rnd = random 1;
						if (_rnd > 0.7) then {
							r_player_infected = true;
							//player setVariable["USEC_infected",true];
						};
					};
				};
			} forEach _listTalk;
			if (dayz_temperatur < ((50 / 100) * (dayz_temperaturnormal - dayz_temperaturmin) + dayz_temperaturmin)) then {	//TeeChange
				_rnd = (random 1) * (((dayz_temperaturnormal - dayz_temperatur) * (100 /(dayz_temperaturnormal - dayz_temperaturmin)))/ 25);	//TeeChange
				if (_rnd < 0.05) then {
					_rnd = random 1;
					if (_rnd > 0.95) then {
						r_player_infected = true;
						//player setVariable["USEC_infected",true];
					};
				};
			};
		};
	};
	
	//If has infection reduce blood cough and add shake
	if (r_player_infected) then {
		if !(player getVariable["USEC_infected",false]) then { 
			player setVariable["USEC_infected",true,true];  
		};
		
		_rnd = ceil (random 8);
		[player,"cough",_rnd,false,9] call dayz_zombieSpeak;
		
		if (_rnd < 3) then {
			addCamShake [2, 1, 25];
		};
		if (r_player_blood > 3000) then {
			r_player_blood = r_player_blood - 3;
			player setVariable["USEC_BloodQty",r_player_blood];
		};
	};
	
	//Pain Shake Effects
	if (r_player_inpain and !r_player_unconscious) then {
		playSound "breath_1";
		addCamShake [2, 1, 25];
	};
	
	//Hunger Effect
	_foodVal = 		dayz_statusArray select 0;
	_thirstVal = 	dayz_statusArray select 1;
	if (_thirstVal <= 0) then {
		_result = r_player_blood - 10;
		if (_result < 0) then {
			_id = [player,"dehyd"] spawn player_death;
		} else {
			r_player_blood = _result;
		};
	};
	if (_foodVal <= 0) then {
		_result = r_player_blood - 10;
		if (_result < 0) then {
			_id = [player,"starve"] spawn player_death;
		} else {
			r_player_blood = _result;
		};
	};
	
	//Record low bloow
	_lowBlood = player getVariable ["USEC_lowBlood", false];
	if ((r_player_blood < r_player_bloodTotal) and !_lowBlood) then {
		player setVariable["USEC_lowBlood",true,true];
	};
	
	//Broadcast Hunger/Thirst
	_messTimer = _messTimer + 1;
	if (_messTimer > 15) then {
		_messTimer = 0;
		player setVariable ["messing",[dayz_hunger,dayz_thirst],true];
	};
	
	//check if can disconnect
	if (!dayz_canDisconnect) then {
		if ((time - dayz_damageCounter) > 180) then {
			if (!r_player_unconscious) then {
				dayz_canDisconnect = true;
				//["dayzDiscoRem",getPlayerUID player] call callRpcProcedure;
				dayzDiscoRem = getPlayerUID player;
				publicVariable "dayzDiscoRem";
				
				//Ensure Control is hidden
				_display = uiNamespace getVariable 'DAYZ_GUI_display';
				_control = 	_display displayCtrl 1204;
				_control ctrlShow false;
			};
		};
	};

	//Save Checker
	if (dayz_unsaved) then {
		if ((time - dayz_lastSave) > _saveTime) then {
			//["dayzPlayerSave",[player,dayz_Magazines,false]] call callRpcProcedure;
			
			dayzPlayerSave = [player,dayz_Magazines,false];
			publicVariableServer "dayzPlayerSave";
			
			if (isServer) then {
				dayzPlayerSave call server_playerSync;
			};
						
			dayz_lastSave = time;
			dayz_Magazines = [];
		};
		_lastSave = _lastSave + 2;
	} else {
		dayz_lastSave = time;
		_lastSave = 0;
	};

	if (!dayz_unsaved) then {
		dayz_lastSave = time;
	};

	//Attach Trigger Current Object
	//dayz_playerTrigger attachTo [_refObj,[0,0,0]];
	//dayz_playerTrigger setTriggerArea [_size,_size,0,false];

	// If in combat, display counter and restrict logout
	_startcombattimer      = player getVariable["startcombattimer",0];
	if (_startcombattimer == 1) then {
		player setVariable["combattimeout", time + 30, true];
		player setVariable["startcombattimer", 0, true];
		dayz_combat = 1;
	};

	_combattimeout = player getVariable["combattimeout",0];
	if (_combattimeout > 0) then {
		_timeleft = _combattimeout - time;
		if (_timeleft > 0) then {
			//hintSilent format["In Combat: %1",round(_timeleft)];
		} else {
			//hintSilent "Not in Combat";
			player setVariable["combattimeout", 0, true];
			dayz_combat = 0;
			_combatdisplay = uiNamespace getVariable 'DAYZ_GUI_display';
			_combatcontrol = 	_combatdisplay displayCtrl 1307;
			_combatcontrol ctrlShow true;
		};
	} else {
		//hintSilent "Not in Combat";
		dayz_combat = 0;
		_combatdisplay = uiNamespace getVariable 'DAYZ_GUI_display';
		_combatcontrol = 	_combatdisplay displayCtrl 1307;
		_combatcontrol ctrlShow true;
	};
	
	/*
	setGroupIconsVisible [false,false];
	clearGroupIcons group player;
	*/
	"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, (r_player_blood/r_player_bloodTotal)],  [1, 1, 1, 0.0]];
	"colorCorrections" ppEffectCommit 0;
	sleep 1;
	
	_myPos = player getVariable["lastPos",[]];
	if (count _myPos > 0) then {
		player setVariable["lastPos",_mylastPos, true];
		player setVariable["lastPos",[]];
	};
	
	_lastPos = getPosATL player;
    _currentWep = currentWeapon player;

    if ((_currentWep == "MeleeHatchet") or (_currentWep == "MeleeMachete") or (_currentWep == "MeleeCrowbar")) then {
        if (_currentWep == "MeleeHatchet") then {
            player setWeaponReloadingTime [player,currentWeapon player,0.8];
        };
        if (_currentWep == "MeleeMachete") then {
            player setWeaponReloadingTime [player,currentWeapon player,0.55];
        };
        if (_currentWep == "MeleeCrowbar") then {
            player setWeaponReloadingTime [player,currentWeapon player,0.7];
        };
    };
	//Hatchet ammo fix	
	"MeleeHatchet" call dayz_meleeMagazineCheck;
	
	//Crowbar ammo fix	
	"MeleeCrowbar" call dayz_meleeMagazineCheck;
    
	//Machete ammo fix	
	"MeleeMachete" call dayz_meleeMagazineCheck;
    {
    if(_x select 1 == getPlayerUID player) then {_hasInvite = true;
    
    if (_hasInvite) then {
        if (dayz_pendingInvite == "") then {
                _invite = _x;
                if (_invite select 1 == getPlayerUID player) then {
                    {
                        if(_invite select 0 == getPlayerUID _x) then {
                            _name = name(_x);
                        if (dayz_pendingInvite != _name) then {
                            dayz_pendingInvite = _name;
                hint parseText format["<t size='1.20' font='Bitstream' color='#0CE800'>[GROUP]</t><br/>
        <t size='1' font='Bitstream' align='left'>You have been invited to %1's group.</t><br/>", _name];
                        };
                        };
                    } forEach playableUnits;
                };
        };
    } else {
    dayz_pendingInvite = "";
    };
    };
    } forEach currentInvites;
    
    {
        if (damage _x >= 1) then {
            _typeOf = "ItemTent";
            if (typeOf _x == "ACampStorage") then {
                _typeOf = "ItemATent";
            };
            _bag = createVehicle ["WeaponHolder",getPosATL _x,[], 0, "CAN_COLLIDE"];
            _bag addMagazineCargoGlobal [_typeOf, 1];
            
            _objectID 	= _x getVariable["ObjectID","0"];
            _objectUID	= _x getVariable["ObjectUID","0"];
            
            _weapons = 	getWeaponCargo _x;
            _magazines = 	getMagazineCargo _x;
            _backpacks = 	getBackpackCargo _x;
            
            dayzDeleteObj = [_objectID,_objectUID];
            publicVariable "dayzDeleteObj";
            if (isServer) then {
                dayzDeleteObj call server_deleteObj;
            };
            deleteVehicle _x;
            
            _objWpnTypes = 	_weapons select 0;
            _objWpnQty = 	_weapons select 1;
            _countr = 0;
            {
                _bag addweaponcargoGlobal [_x,(_objWpnQty select _countr)];
                _countr = _countr + 1;
            } forEach _objWpnTypes;
            
            _objWpnTypes = _magazines select 0;
            _objWpnQty = _magazines select 1;
            _countr = 0;
            {
                _bag addmagazinecargoGlobal [_x,(_objWpnQty select _countr)];
                _countr = _countr + 1;
            } forEach _objWpnTypes;

            _objWpnTypes = _backpacks select 0;
            _objWpnQty = _backpacks select 1;
            _countr = 0;
            {
                _bag addbackpackcargoGlobal [_x,(_objWpnQty select _countr)];
                _countr = _countr + 1;
            } forEach _objWpnTypes;
            player reveal _bag;
        };
    } forEach nearestObjects [getPosATL player, ["TentStorage","ACampStorage"], 35];
    
    if (player distance (nearestObject [player,"SmokeShellTear"]) <= 35) then {
        _nearest = nearestObject [player,"SmokeShellTear"];
        _dist = player distance _nearest;
        if (goggles player != "G_Combat_DZ") then {
            if ((_dist < 35) and (_dist >= 25) and (!r_player_tearGasOn)) then {
                "dynamicBlur" ppEffectEnable true; "dynamicBlur" ppEffectAdjust [1]; "dynamicBlur" ppEffectCommit 3; 
                "colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 0.2, 1],  [1, 1, 1, 0.0]];"colorCorrections" ppEffectCommit 3;
            };
            if ((_dist < 25) and (_dist >= 15) and (!r_player_tearGasOn)) then {
                "dynamicBlur" ppEffectEnable true; "dynamicBlur" ppEffectAdjust [2]; "dynamicBlur" ppEffectCommit 3; 
                "colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 0.2, 0.95],  [1, 1, 1, 0.0]];"colorCorrections" ppEffectCommit 3;
            };
            if ((_dist < 15) and (_dist >= 10) and (!r_player_tearGasOn)) then {
                "dynamicBlur" ppEffectEnable true; "dynamicBlur" ppEffectAdjust [4]; "dynamicBlur" ppEffectCommit 3;    
                "colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 0.2, 0.9],  [1, 1, 1, 0.0]];"colorCorrections" ppEffectCommit 3;
            };
            if ((_dist < 10)) then {
                if (!r_player_tearGasOn) then {
                    r_player_tearGasOn = true;
                    [] spawn {
                        while { r_player_tearGasOn } do {
                            if (r_player_tearGasCount >= 30) exitWith {
                                r_player_tearGasCount = 0;
                                r_player_tearGasOn = false;
                            };
                            "dynamicBlur" ppEffectEnable true; "dynamicBlur" ppEffectAdjust [8]; "dynamicBlur" ppEffectCommit 2; 
                            "colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 0.2, 0.8],  [1, 1, 1, 0.0]];"colorCorrections" ppEffectCommit 2;
                            addCamShake [5, 0.5, 25];
                            r_player_tearGasCount = r_player_tearGasCount + 1;
                            sleep 2;
                        };
                    };
                };
            };
        } else {
            "dynamicBlur" ppEffectEnable true; "dynamicBlur" ppEffectAdjust [0.5]; "dynamicBlur" ppEffectCommit 1; 
        };
    } else {
        if (r_player_clear) then {
            "dynamicBlur" ppEffectAdjust [0]; "dynamicBlur" ppEffectCommit 5;
            "colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 1],  [1, 1, 1, 1]];"colorCorrections" ppEffectCommit 5;
            r_player_clear = false;
        };
    };
};
