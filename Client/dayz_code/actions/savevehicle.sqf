_object = _this select 3;
dayzUpdateVehicle = [_object,"gear"];
publicVariable "dayzUpdateVehicle";
systemChat format["[SYSTEM] Successfully saved! (%1)", typeOf _object];