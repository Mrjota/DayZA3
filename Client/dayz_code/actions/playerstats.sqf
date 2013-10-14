//(TIME HERE-(round(serverTime/60))) Time is in minutes
_restart = (240 - (floor(serverTime / 60)));
_fps = ((round diag_fps) + 10);
_colorFPS = " color='#30DAE3'";
_colorRestart = "";
if (_restart < 30) then { _colorRestart = " color='#DCE854'"; };
if (_restart < 15) then { _colorRestart = " color='#E8C554'"; };
if (_restart < 10) then { _colorRestart = " color='#DB6F0F'"; };
if (_restart < 5) then { _colorRestart = " color='#DB270F'"; };
if (_restart < 0) then {
	_restart = "SKIPPED";
} else {
	_restart = format["%1 minutes", _restart];
};
if (_fps < 60) then { _colorFPS = " color='#309EE3'"; };
if (_fps < 50) then { _colorFPS = " color='#5B7AD9'"; };
if (_fps < 40) then { _colorFPS = " color='#9FCF59'"; };
if (_fps < 30) then { _colorFPS = " color='#E8E843'"; };
if (_fps < 20) then { _colorFPS = " color='#EBA72A'"; };
if (_fps < 10) then { _colorFPS = " color='#EB7A2A'"; };
if (_fps < 5) then { _colorFPS = " color='#F24616'"; };
_hint = "<t size='1.20' font='Bitstream' color='#5882FA'>%1</t><br/><br/>
	<t size='1.20' font='Bitstream' color='#5882FA'>Survived %7 Days</t><br/><br/>
	<t size='1.15' font='Bitstream' align='left'>Blood: </t><t size='1.15' font='Bitstream' align='right'>%8</t><br/><br/>
	<t size='1.15' font='Bitstream' align='left'>Humanity: </t><t size='1.15' font='Bitstream' align='right'>%6</t><br/><br/>
	<t size='1.1' font='Bitstream' align='left'>Murders: </t><t size='1.1' font='Bitstream' align='right'>%4</t><br/>
	<t size='1.1' font='Bitstream' align='left'>Bandits Killed: </t><t size='1.1' font='Bitstream' align='right'>%5</t><br/>
	<t size='1.1' font='Bitstream' align='left'>Zombies Killed: </t><t size='1.1' font='Bitstream' align='right'>%2</t><br/>
	<t size='1.1' font='Bitstream' align='left'>Headshots: </t><t size='1.1' font='Bitstream' align='right'>%3</t><br/><br/>
	<t size='1.1' font='Bitstream' align='left'>FPS: </t><t size='1.1' font='Bitstream' align='right'%11>%9</t><br/><br/>";
if (!isNil "dayz_isOfficial") then {
	_hint = "<t size='1.20' font='Bitstream' color='#5882FA'>%1</t><br/><br/>
			<t size='1.20' font='Bitstream' color='#5882FA'>Survived %7 Days</t><br/><br/>
			<t size='1.15' font='Bitstream' align='left'>Blood: </t><t size='1.15' font='Bitstream' align='right'>%8</t><br/><br/>
			<t size='1.15' font='Bitstream' align='left'>Humanity: </t><t size='1.15' font='Bitstream' align='right'>%6</t><br/><br/>
			<t size='1.1' font='Bitstream' align='left'>Murders: </t><t size='1.1' font='Bitstream' align='right'>%4</t><br/>
			<t size='1.1' font='Bitstream' align='left'>Bandits Killed: </t><t size='1.1' font='Bitstream' align='right'>%5</t><br/>
			<t size='1.1' font='Bitstream' align='left'>Zombies Killed: </t><t size='1.1' font='Bitstream' align='right'>%2</t><br/>
			<t size='1.1' font='Bitstream' align='left'>Headshots: </t><t size='1.1' font='Bitstream' align='right'>%3</t><br/><br/>
			<t size='1.1' font='Bitstream' align='left'>FPS: </t><t size='1.1' font='Bitstream' align='right'%11>%9</t><br/>
			<t size='1.1' font='Bitstream' align='left'>Next Restart: </t><t size='1.1' font='Bitstream' align='right'%12>%10</t><br/><br/>";
};
hintSilent parseText format [
	_hint,
	(name player),
	(player getVariable['zombieKills', 0]),
	(player getVariable['headShots', 0]),
	(player getVariable['humanKills', 0]),
	(player getVariable['banditKills', 0]),
	(player getVariable['humanity', 0]),
	(dayz_skilllevel),
	r_player_blood,
	_fps,
	_restart,
	_colorFPS,
	_colorRestart
];
