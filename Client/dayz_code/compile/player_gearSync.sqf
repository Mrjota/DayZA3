private ["_objects"];

_objects = nearestObjects [getPosATL player, ["Car", "Helicopter", "Motorcycle", "Ship", "TentStorage", "ACampStorage"], 50];
{
	dayzUpdateVehicle = [_x,"gear"];
	publicVariable "dayzUpdateVehicle";
	
} foreach _objects;

dayz_unsaved = true;