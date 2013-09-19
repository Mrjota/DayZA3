while {true} do {
	[] spawn fnc_usec_damageActions;
	[] spawn fnc_usec_selfActions;
	sleep 0.2;
};