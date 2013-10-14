
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
		_handle = [_item] spawn player_eat2;
		waitUntil {scriptDone _handle};
		[1] spawn player_refreshU;
	};
	case 1:
	{
		_item = lbData [dlist, (lbCurSel dlist)];
		_handle = [_item] spawn player_drink2;
		waitUntil {scriptDone _handle};
		[2] spawn player_refreshU;
	};
	case 2:
	{
		_item = lbData [mlist, (lbCurSel mlist)];
		switch (_item) do {
			case "SurvivalPack":
			{
				_handle = ["use"] spawn player_spack;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemBandage":
			{
				_handle = ["use"] spawn player_bandageSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemEpinephrine":
			{
				_handle = ["use"] spawn player_adrenSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemMorphine":
			{
				_handle = ["use"] spawn player_morphineSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemHeatPack":
			{
				_handle = [] spawn player_heatSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemPainkiller":
			{
				_handle = ["use"] spawn player_painkillerSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
			case "ItemAntibiotic":
			{
				_handle = [] spawn player_antibioticSelf;
				waitUntil {scriptDone _handle};
				[3] spawn player_refreshU;
			};
		};
	};
};