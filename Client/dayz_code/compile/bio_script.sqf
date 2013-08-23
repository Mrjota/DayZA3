_shellPos = _this; //Get position of shell

_shell = _shellPos nearestObject "SmokeShellBio"; //Find the actual shell

if ((isNull _shell) or (!alive _shell) or ((_shell distance _shellPos) > 3) or ((count (_shellPos nearEntities ["zZombie_Base",8])) <= 0)) exitWith { }; //Check if shell is existant

_near = _shellPos nearEntities ["zZombie_Base",8];
_list = count _near;
for "_i" from 0 to (_list - 1) do
{
    _obj = _near select _i;
    if ((alive _obj) and ((damage _obj) < 1)) then {
        _obj setDamage 1.963;
    };
};
