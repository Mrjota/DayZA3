private["_display","_btnRespawn","_btnAbort","_timeOut","_timeMax","_isDead"];
		disableSerialization;
		waitUntil {
			_display = findDisplay 49;
			!isNull _display;
		}; 
		_btnRespawn = _display displayCtrl 1010;
		_btnAbort = _display displayCtrl 104;
		_btnRespawn ctrlEnable false;
		_btnAbort ctrlEnable false;
		_btnAbortText = "LEAVE";
		_btnRespawn ctrlSetText "SUICIDE";
		_timeOut = 0;
		_timeMax = 10;
		dayz_lastCheckBit = time;
		
		if (time - dayz_lastCheckBit > 10) then {
			call player_gearSync;
		};			
				
		while {!isNull _display} do {
			_isDead = player getVariable ["isDead",0];
			_brokenLegs = player getVariable ["brokenLegs",0];
			switch true do {
				case (_isDead == 1) : {
					_btnAbort ctrlEnable true;
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlSetText _btnAbortText;		
				};
				case (_timeOut < _timeMax && (_brokenLegs == 1)) : {
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlEnable false;
					_btnAbort ctrlSetText format["%1 (%2)", _btnAbortText, (_timeMax - _timeOut)];
				};
				case (_timeOut < _timeMax && (_brokenLegs == 0)) : {
					_btnAbort ctrlEnable false;
					_btnAbort ctrlSetText format["%1 (%2)", _btnAbortText, (_timeMax - _timeOut)];
				};
				default {
					_btnAbort ctrlEnable true;
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlSetText _btnAbortText;		
				};
			};
			_curTime = time;
			waitUntil {time - _curTime >= 1};
			_timeOut = _timeOut + 1;
		};