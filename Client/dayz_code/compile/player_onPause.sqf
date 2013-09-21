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
		_btnAbortText = ctrlText _btnAbort;
		_timeOut = 0;
		_timeMax = 10;
		dayz_lastCheckBit = time;
		
		if (time - dayz_lastCheckBit > 10) then {
			call player_gearSync;
		};			
				
		while {!isNull _display} do {
			switch true do {
				case ((owner player) getVariable["isDead",0] == 1) : {
					_btnAbort ctrlEnable true;
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlSetText _btnAbortText;		
				};
				case (_timeOut < _timeMax && (player getVariable["brokenLegs",0] == 1)) : {
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlEnable false;
					_btnAbort ctrlSetText format["%1 (%2)", _btnAbortText, (_timeMax - _timeOut)];
				};
				case (_timeOut < _timeMax && (player getVariable["brokenLegs",0] == 0)) : {
					_btnAbort ctrlEnable false;
					_btnAbort ctrlSetText format["%1 (%2)", _btnAbortText, (_timeMax - _timeOut)];
				};
				default {
					_btnAbort ctrlEnable true;
					_btnRespawn ctrlEnable true;
					_btnAbort ctrlSetText _btnAbortText;		
				};
			};
			sleep 1;
			_timeOut = _timeOut + 1;
		};