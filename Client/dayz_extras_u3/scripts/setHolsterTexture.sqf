if (!isServer) then {waitUntil{player == player}};

// Create publicVariable eventhandler to send the on/off state of the texture across the network
"bb_oa_mercs" addPublicVariableEventHandler {[_this select 1] execVM "bb_oa_mercs\scripts\setHolsterTexture_MP.sqf"};

// Set pistol texture to empty
player setObjectTexture [0,""];
// Send texture change across the network
bb_oa_mercs = [player, false, ""];
publicVariable "bb_oa_mercs";
_c = 0;
_wepArray = ["","M9","M9SD","M9DZ_DZ","Makarov","UZI_EP1","UZI_SD_EP1","revolver_EP1","Colt1911","glock17_EP1","UZI_SD_DZ","hgun_P07_F","hgun_P07_snds_F","hgun_Rook40_F","hgun_Rook40_snds_F","hgun_ACPC2_F","hgun_ACPC2_snds_F"];
sleep 0.1;

while {true} do
{	
	while {(handgunWeapon player) in (weapons player)} do
	{
        _secWeapon = handgunWeapon player;
        if !(_secWeapon in _wepArray) then 
        {
            _secWeapon = "Colt1911";
        };
        if (_c == 0 && !((currentWeapon player) isKindOf _secWeapon) && (_secWeapon != "")) then
        {	
            // Show the pistol
            switch (_secWeapon) do
            {
                case "M9":
                {
                    player setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
                };
                case "M9SD":
                {
                    player setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
                };
                case "M9DZ_DZ":
                {
                    player setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
                };
                case "revolver_EP1":
                {
                    player setObjectTexture [0,"ca\weapons_e\revolver\data\revolver_co"];
                };
                case "UZI_EP1":
                {
                    player setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
                };
                case "UZI_SD_EP1":
                {
                    player setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
                };
                case "UZI_SD_DZ":
                {
                    player setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
                };
                case "Makarov":
                {
                    player setObjectTexture [0,"ca\weapons\data\makarov_co"];
                };
                case "Colt1911":
                {
                    player setObjectTexture [0,"ca\weapons\colt1911\data\colt1911_body_co"];
                };
                case "glock17_EP1":
                {
                    player setObjectTexture [0,"ca\weapons_e\glock17\data\glock17_co"];
                };
                case "hgun_P07_F":
                {
                    player setObjectTexture [0,"A3\weapons_f\pistols\p07\data\p07_co"];
                };
                case "hgun_P07_snds_F":
                {
                    player setObjectTexture [0,"A3\weapons_f\pistols\p07\data\p07_co"];
                };
                case "hgun_Rook40_snds_F":
                {
                    player setObjectTexture [0,"A3\weapons_f\pistols\rook40\data\rook40_co"];
                };
                case "hgun_Rook40_F":
                {
                    player setObjectTexture [0,"A3\weapons_f\pistols\rook40\data\rook40_co"];
                };
                case "hgun_ACPC2_F":
                {
                    player setObjectTexture [0,"A3\weapons_f_beta\Pistols\acpc2\data\acpc2_co"];
                };
                case "hgun_ACPC2_snds_F":
                {
                    player setObjectTexture [0,"A3\weapons_f_beta\Pistols\acpc2\data\acpc2_co"];
                };
            };
            _c  = 1;
            // Send texture change across the network
            bb_oa_mercs = [player, true, _secWeapon];
            publicVariable "bb_oa_mercs";
        };				
        if  (((format ["%1", (currentWeapon player)] == _secWeapon) or (_secWeapon == "")) && _c == 1) then
        { 	
            // Set the pistol to empty texture
            player setObjectTexture [0,""];
            _c = 0;
            // Send texture change across the network
            bb_oa_mercs = [player, false, ""];
            publicVariable "bb_oa_mercs";
        };	
        sleep 1;
    };
	if (_c == 1) then
	{	
		// Set the pistol to empty texture
		player setObjectTexture [0,""];
		_c = 0;
		// Send texture change across the network
		bb_oa_mercs = [player, false, ""];
		publicVariable "bb_oa_mercs";
	};
	sleep 1;
};