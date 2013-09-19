private["_object","_position"];
_array = _this select 3;
_object = _array select 0;
_option = _array select 1;

if (_option == 1) then {
	//Kneel Down
	player playMove "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon";
	waitUntil { animationState player != "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon"};
	_object setvectorup [0,0,1];
	player action ["getInDriver", _object];
	_object setvectorup [0,0,1];
} else {
	_object setvectorup [0,0,1];
};