/*
	DayZ Enhanced ChopWood
	Usage: spawn player_chopWood;
	Original script by those at DayZ Epoch
	Edited by MistaD for use in Zoombies
	
	Changes:
		- Harvesting will only work when you are looking at the tree.
		- You must be within 4.5 meters of the tree.
		- Using systemChat for some messages.
		- Altered when messages are displayed.
		- Altered the messages themselves.
*/
private ["_isOk","_i","_objName","_objInfo","_lenInfo","_started","_finished","_animState","_isMedic","_proceed","_counter","_itemOut","_countOut","_tree","_distance2d","_distance3d","_trees","_findNearestTree"];

if(repairInProgress) exitWith { systemChat "[SYSTEM] Character currently busy..."; };
repairInProgress = true;

// allowed trees list move this later
_trees = ["t_larix3s.p3d","t_pyrus2s.p3d","str_briza_kriva.p3d","dd_borovice.p3d","les_singlestrom_b.p3d","les_singlestrom.p3d","smrk_velky.p3d","smrk_siroky.p3d","smrk_maly.p3d","les_buk.p3d","str krovisko vysoke.p3d","str_fikovnik_ker.p3d","str_fikovnik.p3d","str vrba.p3d","hrusen2.p3d","str dub jiny.p3d","str lipa.p3d","str briza.p3d","p_akat02s.p3d","jablon.p3d","p_buk.p3d","str_topol.p3d","str_topol2.p3d","p_osika.p3d","t_picea3f.p3d","t_picea2s.p3d","t_picea1s.p3d","t_fagus2w.p3d","t_fagus2s.p3d","t_fagus2f.p3d","t_betula1f.p3d","t_betula2f.p3d","t_betula2s.p3d","t_betula2w.p3d","t_alnus2s.p3d","t_acer2s.p3d","t_populus3s.p3d","t_quercus2f.p3d","t_sorbus2s.p3d","t_malus1s.p3d","t_salix2s.p3d","t_picea1s_w.p3d","t_picea2s_w.p3d","t_ficusb2s_ep1.p3d","t_populusb2s_ep1.p3d","t_populusf2s_ep1.p3d","t_amygdalusc2s_ep1.p3d","t_ficusb2s_ep1.p3d","t_pistacial2s_ep1.p3d","t_pinuse2s_ep1.p3d","t_pinuss3s_ep1.p3d","t_prunuss2s_ep1.p3d","t_pinusn2s.p3d","t_pinusn1s.p3d","t_pinuss2f.p3d","t_poplar2f_dead_pmc.p3d","misc_torzotree_pmc.p3d","misc_burnspruce_pmc.p3d","brg_cocunutpalm8.p3d","brg_umbrella_acacia01b.p3d","brg_jungle_tree_canopy_1.p3d","brg_jungle_tree_canopy_2.p3d","brg_cocunutpalm4.p3d","brg_cocunutpalm3.p3d","palm_01.p3d","palm_02.p3d","palm_03.p3d","palm_04.p3d","palm_09.p3d","palm_10.p3d","brg_cocunutpalm2.p3d","brg_jungle_tree_antiaris.p3d","brg_cocunutpalm1.p3d"];

//Check 5 meters infront of player for trees.
_pos = getPos player;
_dir = getDir player;
_pos = [(_pos select 0) + 4 * sin(_dir), (_pos select 1) + 4 * cos(_dir), _pos select 2];

_findNearestTree = [];
{
	_dist1 = [_pos, _x] call BIS_fnc_distance2D;
	if (_dist1 <= 4.5) then {
		_dist2 = [player, _x] call BIS_fnc_distance2D;
		if (_dist2 <= 4.5) then {
			if("" == typeOf _x) then {
					
				if (alive _x) then {
						
					_objName = _x call dayz_getModelName;
					
					// Exit since we found a tree
					if (_objName in _trees) exitWith { 
						_findNearestTree set [(count _findNearestTree),_x];
					};
				};
			};
		};
	};
} foreach nearestObjects [_pos, [], 20];

if (count(_findNearestTree) >= 1) then {
		
	_tree = _findNearestTree select 0;

	// get 2d distance
	_distance2d = [player, _tree] call BIS_fnc_distance2D;
	_distance3d = player distance _tree;

	if(_distance2d <= 5) then {

		_countOut = ceil(_distance3d-_distance2d);
		
		_counter = 0;
		_isOk = true;
		_proceed = false;
		while {_isOk} do {

			player playActionNow "Medic";
			
			hintSilent parseText format ["<t size='1.20' font='Bitstream' color='#F20C0C'>[SYSTEM]</t><br/><t size='1' font='Bitstream'>Chopping the tree...<br/>To cancel,<br/>Walk away at anytime.<br/>(%1/%2)</t><br/>", _counter + 1,  _countOut];
			[player,20,true,(getPosATL player)] spawn player_alertZombies;
	
			r_interrupt = false;
			_animState = animationState player;
			r_doLoop = true;
			_started = false;
			_finished = false;

			while {r_doLoop} do {
				_animState = animationState player;
				_isMedic = ["medic",_animState] call fnc_inString;
				if (_isMedic) then {
					_started = true;
				};
				if (_started and !_isMedic) then {
					r_doLoop = false;
					_finished = true;
					[player,"chopwood",0,false] call dayz_zombieSpeak;
				};
				if (r_interrupt) exitWith {
					r_doLoop = false;
				};
		
				sleep 0.1;
		
			};
			if (r_interrupt) exitWith { };

			if(!_finished) exitWith {
				_isOk = false;
				_proceed = false;
			};

			if(_finished) then {
				_counter = _counter + 1;
			};

			if(_counter == _countOut) exitWith {
				_isOk = false;
				_proceed = true;
				sleep 1;
			};
			hintSilent parseText format ["<t size='1.20' font='Bitstream' color='#F20C0C'>[SYSTEM]</t><br/><t size='1' font='Bitstream'>Chopping the tree...<br/>To cancel,<br/>Walk away at anytime.<br/>(%1/%2)</t><br/>", _counter + 1,  _countOut];
		};

		if (_proceed) then {

			_itemOut = "PartWoodPile";
			
			_item = createVehicle ["GroundWeaponHolder", getPosATL player, [], 1, "CAN_COLLIDE"];
			_item addMagazineCargoGlobal [_itemOut,_countOut];
			_item modelToWorld getPosATL player;
			_item setdir (getDir player);
			player reveal _item;
			
			// chop down tree
			if("" == typeOf _tree) then {
				_tree setDamage 1;
			};
			
			hintSilent parseText format ["<t size='1.20' font='Bitstream' color='#F20C0C'>[SYSTEM]</t><br/><t size='1' font='Bitstream'>Finished! %1 piles of wood have been dropped.</t><br/>", _countOut];
		} else {
			r_interrupt = false;
			if (vehicle player == player) then {
				[[player, { _this switchMove ''; }], "BIS_fnc_spawn", true, false] call BIS_fnc_MP;
				player switchMove "";
				player playActionNow "Gear";
			};
			systemChat "[SYSTEM] Action was canceled...";
			hintSilent "";
		};

	} else {
		systemChat "[SYSTEM] You must be close to a tree to harvest wood.";
	};

} else {
		systemChat "[SYSTEM] You must be close to and facing a tree to harvest wood.";
};
repairInProgress = false;
