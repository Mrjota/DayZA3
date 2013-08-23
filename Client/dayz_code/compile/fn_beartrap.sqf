_unitName = _this select 0;

if (name player == _unitName) then {
    _unit = player;
    _hit = "legs";
	_rnd = floor(random(2));
	_wound = ["RightFoot","LeftFoot"] select _rnd;
    
	1 call fnc_usec_bulletHit;
	_isHit = _unit getVariable[_wound,false];
	r_player_blood = r_player_blood - 50;
	[_unit,_hit,1] call object_processHit;
	if(!_isHit) then {
		_unit setVariable[_wound,true,true];
		[_unit,_wound,_hit] spawn fnc_usec_damageBleed;
		usecBleed = [_unit,_wound,_hit];
		publicVariable "usecBleed";

		_isInjured = _unit getVariable["USEC_injured",false];
		if (!_isInjured) then {
			_unit setVariable["USEC_injured",true,true];
		};
        
		_lowBlood = _unit getVariable["USEC_lowBlood",false];
		if (!_lowBlood) then {
			_unit setVariable["USEC_lowBlood",true,true];
		};
		r_player_injured = true;
	};
    _unit say ["z_fracture_0", 50];
};