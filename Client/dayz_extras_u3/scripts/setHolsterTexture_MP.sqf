_array 	= _this select 0;
_unit 	= _array select 0;
_state	= _array select 1;
_type   = _array select 2;

if (_state) then
{
	_unit setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
    switch (_type) do
    {
        case "":
        {
            _unit setObjectTexture [0,""];
        };
        case "revolver_EP1":
        {
            _unit setObjectTexture [0,"ca\weapons_e\revolver\data\revolver_co"];
        };
        case "UZI_EP1":
        {
            _unit setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
        };
        case "UZI_SD_EP1":
        {
            _unit setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
        };
        case "UZI_SD_DZ":
        {
            _unit setObjectTexture [0,"ca\weapons_e\uzi\data\micro_co"];
        };
        case "M9":
        {
            _unit setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
        };
        case "M9SD":
        {
            _unit setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
        };
        case "M9DZ_DZ":
        {
            _unit setObjectTexture [0,"ca\weapons\data\m9_beretta_co"];
        };
        case "Makarov":
        {
            _unit setObjectTexture [0,"ca\weapons\data\makarov_co"];
        };
        case "Colt1911":
        {
            _unit setObjectTexture [0,"ca\weapons\colt1911\data\colt1911_body_co"];
        };
        case "glock17_EP1":
        {
            _unit setObjectTexture [0,"ca\weapons_e\glock17\data\glock17_co"];
        };
        case "hgun_P07_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f\pistols\p07\data\p07_co"];
        };
        case "hgun_P07_snds_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f\pistols\p07\data\p07_co"];
        };
        case "hgun_Rook40_snds_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f\pistols\rook40\data\rook40_co"];
        };
        case "hgun_Rook40_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f\pistols\rook40\data\rook40_co"];
        };
        case "hgun_ACPC2_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f_beta\Pistols\acpc2\data\acpc2_co"];
        };
        case "hgun_ACPC2_snds_F":
        {
            _unit setObjectTexture [0,"A3\weapons_f_beta\Pistols\acpc2\data\acpc2_co"];
        };
    };
} else {
	_unit setObjectTexture [0,""];
};
