
#define Use_Display 2553
#define flist 2505
#define dlist 2506
#define mlist 2507

disableSerialization;

_type = _this select 0;
_item = "";

switch (_type) do {
	case 0:
	{
		_item = lbData [flist, (lbCurSel flist)];
		[_item] spawn player_eat2;
		[1] execVM 'VAS\refreshU.sqf';
	};
	case 1:
	{
		_item = lbData [dlist, (lbCurSel dlist)];
		[_item] spawn player_drink2;
		[2] execVM 'VAS\refreshU.sqf';
	};
	case 2:
	{
		_item = lbData [mlist, (lbCurSel mlist)];
		switch (_item) do {
			case "SurvivalPack":
			{
				[] spawn player_spack;
			};
			case "ItemBandage":
			{
				[] spawn player_bandageSelf;
			};
			case "ItemEpinephrine":
			{
				[] spawn player_adrenSelf;
			};
			case "ItemMorphine":
			{
				[] spawn player_morphineSelf;
			};
			case "ItemHeatPack":
			{
				[] spawn player_heatSelf;
			};
			case "ItemPainkiller":
			{
				[] spawn player_painkillerSelf;
			};
			case "ItemAntibiotic":
			{
				[] spawn player_antibioticSelf;
			};
		};
		[3] execVM 'VAS\refreshU.sqf';
	};
};