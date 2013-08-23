class CfgVehicles {
	class Citizen1;	// External class reference
	class zZombie_Base : Citizen1 {
		scope = 2;
		glassesEnabled = 0;
		vehicleClass = "Zombie";
		displayName = "Zombie";
		fsmDanger = "";
		fsmFormation = "";
		zombieLoot = "civilian";
		moves = "CfgMovesZombie";
		isMan = false;
		weapons[] = {};
		sensitivity = 4;	// sensor sensitivity
		sensitivityEar = 2;
		identityTypes[] = {"zombie1","zombie2"};
		model = "\ca\characters2\civil\Villager\Villager";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\ca\characters2\civil\villager\data\villager_v3_co.paa"};
		faceType = "Man";
		class TalkTopics {};
		languages[] = {};
        
		Items[] = {};
		RespawnItems[] = {};
		magazines[] = {};
		respawnMagazines[] = {};
		linkedItems[] = {"V_PlateCarrier1_rgr_AiA_DZ"};
		respawnLinkedItems[] = {};
		
		class Eventhandlers {
			init = "_this call zombie_initialize;";
			local = "if(_this select 1) then {[(position (_this select 0)),(_this select 0),true] execFSM '\z\AddOns\dayz_code\system\zombie_agent.fsm'};";
		};
		
		class HitPoints {
			class HitHead {
				armor = 0.3;
				material = -1;
				name = "head_hit";
				passThrough = true;
				memoryPoint = "pilot";
			};
			
			class HitBody : HitHead {
				armor = 2;
				name = "body";
				memoryPoint = "aimPoint";
			};
			
			class HitSpine : HitHead {
				armor = 2;
				name = "Spine2";
				memoryPoint = "aimPoint";
			};
			
			class HitHands : HitHead {
				armor = 0.5;
				material = -1;
				name = "hands";
				passThrough = true;
			};
			
			class HitLArm : HitHands {
				name = "LeftArm";
				memoryPoint = "lelbow";
			};
			
			class HitRArm : HitHands {
				name = "RightArm";
				memoryPoint = "relbow";
			};
			
			class HitLForeArm : HitHands {
				name = "LeftForeArm";
				memoryPoint = "lwrist";
			};
			
			class HitRForeArm : HitHands {
				name = "RightForeArm";
				memoryPoint = "rwrist";
			};
			
			class HitLHand : HitHands {
				name = "LeftHand";
				memoryPoint = "LeftHandMiddle1";
			};
			
			class HitRHand : HitHands {
				name = "RightHand";
				memoryPoint = "RightHandMiddle1";
			};
			
			class HitLegs : HitHands {
				name = "legs";
				memoryPoint = "pelvis";
			};
			
			class HitLLeg : HitHands {
				name = "LeftLeg";
				memoryPoint = "lknee";
			};
			
			class HitLLegUp : HitHands {
				name = "LeftUpLeg";
				memoryPoint = "lfemur";
			};
			
			class HitRLeg : HitHands {
				name = "RightLeg";
				memoryPoint = "rknee";
			};
			
			class HitRLegUp : HitHands {
				name = "RightUpLeg";
				memoryPoint = "rfemur";
			};
		};
	};
	class AllVehicles;
	class Air : AllVehicles 
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
	};
	class Helicopter : Air 
	{
		class HitPoints; 
		class Turrets
        {
            class MainTurret: NewTurret
            {
                class Turrets;
				class ViewOptics;
            };
        };
	};
	
	class Mi17_base: Helicopter 
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: ViewOptics {};
				class Turrets: Turrets {};
			};
			class BackTurret: MainTurret
			{
				class Turrets: Turrets {};
			};
		};
	};
	
	class Mi17_DZ: Mi17_base	
	{
		displayname = "Mi17_DZ";
		displaynameshort = "Mi17_DZ";
		scope = 2;
		side = 2;
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxWeapons = 10;
		transportMaxMagazines = 50;
        transportmaxbackpacks = 10;
		
		class Turrets : Turrets 
		{
			class MainTurret : MainTurret 
			{
				magazines[] = {"100Rnd_762x54_PK"};
			};
			class BackTurret : BackTurret
			{
				magazines[] = {"100Rnd_762x54_PK"};
			};
		};
	};
	
	class UH1H_base: Helicopter 
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: ViewOptics {};
				class Turrets: Turrets {};
			};
			class LeftDoorGun: MainTurret
			{
				class Turrets: Turrets {};
			};
		};
	};
	
	class UH1H_DZ: UH1H_base
	{
		scope = 2;
		side = 2;
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxWeapons = 5;
		transportMaxMagazines = 25;
        transportmaxbackpacks = 4;
		
		class Turrets : Turrets 
		{
			class MainTurret : MainTurret 
			{
				magazines[] = {"100Rnd_762x51_M240"};
			};
			class LeftDoorGun : LeftDoorGun
			{
				magazines[] = {"100Rnd_762x51_M240"};
			};
		};
	};
	class AH6_Base_EP1;
	//class AH6X_EP1: AH6_Base_EP1 {};
	class AH6X_DZ: AH6_Base_EP1
	{
		displayname = "AH6X Little Bird";
		displaynameshort = "AH6X_DZ";
		audible = 6;
		enablemanualfire = 0;
		scope = 2;
		side = 2;
		crew = "";
		typicalCargo[] = {};
		hiddenselections[] = {"camo1"};
		hiddenselectionstextures[] = {"ca\air_e\ah6j\data\ah6_merge1_co.paa"};
		icon = "\ca\air_e\data\UI\Icon_ah6x_CA.paa";
		model = "\ca\air_e\ah6j\ah6x";
		picture = "\ca\air_e\data\UI\Picture_ah6x_CA.paa";
		isuav = 0;
		radartype = 0;
		class TransportMagazines{};
		class TransportWeapons{};
		weapons[] = {};
		magazines[] = {};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxWeapons = 3;
		transportMaxMagazines = 10;
        transportmaxbackpacks = 2;
		class Turrets {};
	};
	class HMMWV_Base;
	class HMMWV_DZ: HMMWV_Base {
		accuracy = 0.32;
		displayname = "HMMWV_DZ";
		hasgunner = 0;
		hiddenselections[] = {"Camo1"};
		hiddenselectionstextures[] = {"\ca\wheeled\hmmwv\data\hmmwv_body_co.paa"};
		icon = "\Ca\wheeled\data\map_ico\icomap_hmwv_CA.paa";
		mapsize = 5;
		model = "ca\wheeled_E\HMMWV\HMMWV";
		picture = "\Ca\wheeled\data\ico\HMMWV_CA.paa";
		scope = 2;
		side = 2;
		crew = "";
		typicalCargo[] = {};
		transportMaxWeapons = 4;
		transportMaxMagazines = 12;
        transportmaxbackpacks = 4;
		class Turrets {};
		class Damage {
			mat[] = {"ca\wheeled\hmmwv\data\hmmwv_details.rvmat", "Ca\wheeled\HMMWV\data\hmmwv_details_damage.rvmat", "Ca\wheeled\HMMWV\data\hmmwv_details_destruct.rvmat", "ca\wheeled\hmmwv\data\hmmwv_body.rvmat", "Ca\wheeled\HMMWV\data\hmmwv_body_damage.rvmat", "Ca\wheeled\HMMWV\data\hmmwv_body_destruct.rvmat", "ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat", "ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat", "ca\wheeled\data\hmmwv_clocks_destruct.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass_Half_D.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass_Half_D.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass_in.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass_in_Half_D.rvmat", "ca\wheeled\HMMWV\data\hmmwv_glass_in_Half_D.rvmat"};
			tex[] = {};
		};
	};
	class RubberBoat;
	class PBX: RubberBoat {
		cargoaction[] = {"PBX_Cargo01", "PBX_Cargo02", "PBX_Cargo03"};
		crew = "";
		displayname = "PBX";
		driveraction = "PBX_Driver";
		extcameraposition[] = {0, 4, -14};
		faction = "RU";
		icon = "\Ca\water\Data\map_ico\icomap_rubber_CA.paa";
		mapsize = 6;
		maxspeed = 65;
		model = "\ca\water\PBX";
		picture = "\ca\water\data\ico\pbx_CA.paa";
		scope = 2;
		side = 0;
		transportsoldier = 3;
		typicalcargo[] = {};
		class TransportMagazines {};
		class Library {
			libtextdesc = "The PBX is a Combat Rubber Craft very similar to the CRRC in design. It is intended to be used for maritime raids and infiltration, as well as riverine operations.";
		};
		class Damage {
			mat[] = {"ca\water\data\pbx_engine.rvmat", "ca\water\data\pbx_engine.rvmat", "ca\water\data\pbx_engine_destruct.rvmat", "ca\water\data\pbx_01.rvmat", "ca\water\data\pbx_01.rvmat", "ca\water\data\pbx_01_destruct.rvmat", "ca\water\data\pbx_02.rvmat", "ca\water\data\pbx_02.rvmat", "ca\water\data\pbx_02_destruct.rvmat"};
			tex[] = {};
		};
	};
	class TT650_Base;
	class TT650_Ins: TT650_Base {
		crew = "";
		faction = "INS";
		hiddenselectionstextures[] = {"\ca\wheeled3\tt650\data\Yam650_skin1_CO.paa"};
		scope = 2;
		side = 0;
		typicalcargo[] = {};
	};
	class V3S_Base;
	class V3S_Civ: V3S_Base {
		crew = "";
		faction = "CIV";
		rarityurban = 0.3;
		scope = 2;
		side = 3;
		typicalcargo[] = {};
		class Library {
			libtextdesc = "The V3S is a Czech-made military 6x6 cargo truck capable of carrying cargo up to 5 tons, or up to 3 tons in rough terrain.<br/>This one is a harmless civilian vehicle.";
		};
	};
	class SkodaBase;
	 class car_hatchback: SkodaBase {
		armorcrash0[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_01", 0.707946, 1, 200};
		armorcrash1[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_02", 0.707946, 1, 200};
		armorcrash2[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_03", 0.707946, 1, 200};
		armorcrash3[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_04", 0.707946, 1, 200};
		brakedistance = 10;
		buildcrash0[] = {"Ca\sounds\Vehicles\Crash\crash_building_01", 0.707946, 1, 200};
		buildcrash1[] = {"Ca\sounds\Vehicles\Crash\crash_building_02", 0.707946, 1, 200};
		buildcrash2[] = {"Ca\sounds\Vehicles\Crash\crash_building_03", 0.707946, 1, 200};
		buildcrash3[] = {"Ca\sounds\Vehicles\Crash\crash_building_04", 0.707946, 1, 200};
		cargoaction[] = {"Hatchback_Cargo01"};
		cargoiscodriver[] = {1, 0};
		crew = "";
		displayname = "Old hatchback";
		driveraction = "Hatchback_Driver";
		faction = "CIV";
		hiddenselections[] = {"Camo1"};
		hiddenselectionstextures[] = {"\ca\wheeled\data\hatchback_co.paa"};
		icon = "\Ca\wheeled\data\map_ico\icomap_skoda_CA.paa";
		mapsize = 6;
		maxspeed = 125;
		model = "\ca\Wheeled\car_hatchback";
		picture = "\Ca\wheeled\data\ico\car_hatchback_CA.paa";
		rarityurban = 0.6;
		scope = 2;
		soundarmorcrash[] = {"ArmorCrash0", 0.25, "ArmorCrash1", 0.25, "ArmorCrash2", 0.25, "ArmorCrash3", 0.25};
		soundbuildingcrash[] = {"buildCrash0", 0.25, "buildCrash1", 0.25, "buildCrash2", 0.25, "buildCrash3", 0.25};
		soundengineoffext[] = {"ca\sounds\vehicles\Wheeled\sedan\ext\ext-sedan-stop-1", 0.398107, 1, 250};
		soundengineoffint[] = {"ca\sounds\vehicles\Wheeled\sedan\int\int-sedan-stop-1", 0.398107, 1};
		soundengineonext[] = {"ca\sounds\vehicles\Wheeled\sedan\ext\ext-sedan-start-1", 0.398107, 1, 250};
		soundengineonint[] = {"ca\sounds\vehicles\Wheeled\sedan\int\int-sedan-start-1", 0.398107, 1};
		soundgear[] = {"", "5.62341e-005", 1};
		soundgetin[] = {"ca\sounds\vehicles\Wheeled\sedan\ext\ext-sedan-getout-1", 0.316228, 1};
		soundgetout[] = {"ca\sounds\vehicles\Wheeled\sedan\ext\ext-sedan-getout-1", 0.316228, 1, 30};
		soundwoodcrash[] = {"woodCrash0", 0.166, "woodCrash1", 0.166, "woodCrash2", 0.166, "woodCrash3", 0.166, "woodCrash4", 0.166, "woodCrash5", 0.166};
		typicalcargo[] = {};
		wheelcircumference = 2.148;
		woodcrash0[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_01", 0.707946, 1, 200};
		woodcrash1[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_02", 0.707946, 1, 200};
		woodcrash2[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_03", 0.707946, 1, 200};
		woodcrash3[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_04", 0.707946, 1, 200};
		woodcrash4[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_05", 0.707946, 1, 200};
		woodcrash5[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_06", 0.707946, 1, 200};
		class SoundEvents {
			class AccelerationIn {
				expression = "(engineOn*(1-camPos))*gmeterZ";
				limit = 0.5;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\sedan\int\int-sedan-acce-1", 0.398107, 1};
			};
			class AccelerationOut {
				expression = "(engineOn*camPos)*gmeterZ";
				limit = 0.5;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\sedan\ext\ext-sedan-acce-1", 0.398107, 1, 250};
			};
		};
		class Sounds {
			class Engine {
				frequency = "(randomizer*0.05+0.95)*rpm";
				sound[] = {"\ca\sounds\Vehicles\Wheeled\sedan\ext\ext-sedan-low-1", 0.398107, 0.9, 300};
				volume = "engineOn*camPos*(rpm factor[0.6, 0.2])";
			};
			class EngineHighOut {
				frequency = "(randomizer*0.05+0.95)*rpm";
				sound[] = {"\ca\sounds\Vehicles\Wheeled\sedan\ext\ext-sedan-high-1", 0.398107, 0.8, 380};
				volume = "engineOn*camPos*(rpm factor[0.45, 0.9])";
			};
			class IdleOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\sedan\ext\ext-sedan-idle-1", 0.281838, 1, 200};
				volume = "engineOn*camPos*(rpm factor[0.3, 0])";
			};
			class TiresRockOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2", 0.316228, 1, 30};
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2", 0.316228, 1, 30};
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3", 0.316228, 1, 30};
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2", 0.316228, 1, 30};
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel2", 0.316228, 1, 30};
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3", 0.316228, 1, 30};
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\ext\int-noise3", 0.316228, 1, 30};
				volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
			};
			class EngineLowIn {
				frequency = "(randomizer*0.05+0.95)*rpm";
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\sedan\int\int-sedan-low-1", 0.562341, 0.8};
				volume = "((engineOn*thrust) factor[0.65, 0.2])*(1-camPos)";
			};
			class EngineHighIn {
				frequency = "(randomizer*0.05+0.95)*rpm";
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\sedan\int\int-sedan-high-1", 0.562341, 0.8};
				volume = "((engineOn*thrust) factor[0.55, 0.95])*(1-camPos)";
			};
			class IdleIn {
				frequency = 1;
				sound[] = {"\ca\sounds\Vehicles\Wheeled\sedan\int\int-sedan-idle-1", 0.316228, 1};
				volume = "engineOn*(rpm factor[0.3, 0])*(1-camPos)";
			};
			class TiresRockIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2", 0.177828, 1};
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2", 0.177828, 1};
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3", 0.177828, 1};
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2", 0.177828, 1};
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel2", 0.177828, 1};
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3", 0.177828, 1};
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn {
				frequency = 1;
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\BUS\int\noise3", 0.177828, 1};
				volume = "(damper0 max 0.04)*(speed factor[0, 8])*(1-camPos)";
			};
			class Movement {
				frequency = 1;
				sound = "soundEnviron";
				volume = 0;
			};
		};
		class Damage {
			mat[] = {"ca\wheeled\data\hatchback.rvmat", "ca\wheeled\data\hatchback.rvmat", "ca\wheeled\data\hatchback_destruct.rvmat", "ca\wheeled\data\hatchback.rvmat", "ca\wheeled\data\hatchback.rvmat", "ca\wheeled\data\hatchback_destruct.rvmat", "ca\wheeled\data\detailmapy\auta_skla.rvmat", "ca\wheeled\data\detailmapy\auta_skla_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in_damage.rvmat", "ca\wheeled\data\detailmapy\auta_skla_in_damage.rvmat"};
			tex[] = {};
		};
		class Library {
			libtextdesc = "Civilian Car";
		};
	};
	class UAZ_Unarmed_Base;
	class UAZ_CDF: UAZ_Unarmed_Base {
		accuracy = 0.3;
		crew = "";
		faction = "CDF";
		hiddenselectionstextures[] = {"\ca\wheeled\data\Uaz_main_002_CO.paa"};
		scope = 2;
		side = 1;
		typicalcargo[] = {};
	};
	class MH6J_DZ: AH6_Base_EP1
	{
		scope = 2;
		side = 2;
		crew = "";
		enablemanualfire = 0;
		typicalCargo[] = {};
		displayname = "MH-6J Little Bird";
		displaynameshort = "MH6J_DZ";
		hiddenselections[] = {"camo1", "camo2"};
		transportsoldier = 5;
		hiddenselectionstextures[] = {"ca\air_e\ah6j\data\ah6_merge1_co.paa", "ca\air_e\ah6j\data\default_co.paa"};
		icon = "\ca\air_e\data\UI\Icon_mh6j_CA.paa";
		model = "\ca\air_e\ah6j\mh6j";
		picture = "\ca\air_e\data\UI\Picture_mh6j_CA.paa";
		radartype = 0;
		class TransportMagazines{};
		class TransportWeapons{};
		weapons[] = {};
		magazines[] = {};
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxWeapons = 3;
		transportMaxMagazines = 20;
        transportmaxbackpacks = 5;
		class Turrets {};
	};	
	class Animal;
	class Pastor;
	class Fin;
	class DZAnimal: Animal
	{
		scope = 0;
		side = 1;
		accuracy = 0.25;
		boneHead = "head";
		bonePrimaryWeapon = "head";
		triggerAnim = "";
		picture = "";
		icon = "\Ca\animals2\data\mapicon_animals_ca.paa";
		mapSize = 10;
		weaponSlots = 0;
		fsmFormation = "";
		fsmDanger = "";
		agentTasks[] = {};
		moves = "CfgMovesAnimal";
		memoryPointHeadAxis = "head_axis";
		woman = 0;
		faceType = "Default";
		boneLEye = "l_eye";
		boneREye = "r_eye";
		boneLEyelidUp = "eye_upl";
		boneREyelidUp = "eye_upr";
		boneLEyelidDown = "eye_lwl";
		boneREyelidDown = "eye_lwr";
		boneLPupil = "l_pupila";
		boneRPupil = "r_pupila";
		memoryPointAim = "aimPoint";
		memoryPointCameraTarget = "camera";
		extCameraPosition[] = {0,0.5,-2.5};
		class EventHandlers{};
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar {};
		class VariablesString {};
	};
	class DZ_Pastor : Pastor {
		scope = 2;
		side = 1;
		model = "\ca\animals2\Dogs\Pastor\Pastor";
		displayName = "Alsatian";
		moves = "CfgMovesDogDZ";
		gestures = "CfgGesturesDogDZ";
		fsmDanger = "";
		fsmFormation = "";
		agentTasks[] = {};
		woman = 0;
		class EventHandlers{};
		class Wounds
		{
			tex[] = {};
			mat[] = {};
		};
		class VariablesScalar {};
		class VariablesString {};
	};
	
	class DZ_Fin : Fin {
		scope = 2;
		model = "\ca\animals2\Dogs\Fin\Fin";
		displayName = "Fin";
		moves = "CfgMovesDogDZ";
		gestures = "CfgGesturesDogDZ";
		fsmDanger = "";
		fsmFormation = "";
	};

	class Soldier_Crew_PMC;
	class Bandit1_DZ : Soldier_Crew_PMC {
        scope = 2;
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		faceType = "Man";
		hiddenSelections[] = {"_middlearm", "_lowerroll", "_middleroll"};
		displayName = "$STR_CHAR_2";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		model = "\dayz\characters\man_bandit";
		portrait = "\Ca\characters_E\data\portraits\ger_soldier_CA";
		magazines[] = {};
		backpack = "";
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
	};

	class BAF_Soldier_Officer_W;
	class Rocket_DZ: BAF_Soldier_Officer_W {
        scope = 2;
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		faceType = "Man";
		hiddenSelections[] = {"_middlearm", "_lowerroll", "_middleroll"};
		displayName = "Rocket";
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
	};
	class BAF_Soldier_W;
	class Soldier1_DZ: BAF_Soldier_W {
		displayName = "Soldier";
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
	};
    class US_Soldier_SniperH_EP1;
	class Sniper2_DZ: US_Soldier_SniperH_EP1 {
        scope = 2;
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		faceType = "Man";
		displayName = "Sniper";
        hiddenselections[] = {"Camo"};
        hiddenselectionstextures[] = {"\ca\characters_E\Ghillie\Data\ghillie_overall1_desert_co.paa"};
        vehicleclass = "Men";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
        
        model = "\ca\characters_E\Ghillie\Ghillie_Overall";
        picture = "\Ca\characters\data\Ico\i_null_CA.paa";
        portrait = "\Ca\characters\data\portraits\comBarHead_common_sniper_ca";
        accuracy = 3.9;
        camouflage = 0.5;
        textplural = "Snipers";
        textsingular = "Sniper";
        cancarrybackpack = 1;
        faction = PMC_BAF;
        
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
        class Wounds {
            mat[] = {"ca\characters\data\us_hhl.rvmat", "ca\characters\data\us_hhl_wound1.rvmat", "ca\characters\data\us_hhl_wound2.rvmat"};
            tex[] = {};
        };
	};
	class BAF_Soldier_SniperH_W;
	class Sniper1_DZ: BAF_Soldier_SniperH_W {
        scope = 2;
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		faceType = "Man";
		displayName = "Sniper";
        hiddenselections[] = {"Camo"};
        hiddenselectionstextures[] = {"\ca\characters_W_baf\data\Ghillie_Overall2_co.paa","\ca\characters_W_baf\data\armour_dpm_co.paa","\ca\characters_W_baf\data\equip_dpm_co.paa"};
        vehicleclass = "MenW";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
        
        model = "\ca\characters_e\Ghillie\Ghillie_Overall";
        picture = "\Ca\characters\data\Ico\i_null_CA.paa";
        portrait = "\Ca\characters\data\portraits\comBarHead_common_sniper_ca";
        accuracy = 3.9;
        camouflage = 0.5;
        textplural = "Snipers";
        textsingular = "Sniper";
        cancarrybackpack = 1;
        faction = "BIS_BAF";
        
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
        class Wounds {
            mat[] = {"ca\characters_d_baf\Data\armour.rvmat","ca\characters_d_baf\Data\W1_armour.rvmat","ca\characters_d_baf\Data\W2_armour.rvmat","ca\characters_d_baf\Data\camo.rvmat", "ca\characters_d_baf\Data\W1_camo.rvmat","ca\characters_d_baf\Data\W2_camo.rvmat"};
            tex[] = {};
        };
	};
	class BAF_Soldier_L_W;
	class Camo1_DZ: BAF_Soldier_L_W {
        scope = 2;
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		faceType = "Man";
        hiddenselections[] = {"Camo","Camo2","Camo3"};
        hiddenselectionstextures[] = {"\ca\characters_W_baf\data\camo_dpm_co.paa","\ca\characters_W_baf\data\armour_dpm_co.paa","\ca\characters_W_baf\data\equip_dpm_co.paa"};
        vehicleclass = "MenW";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
        icon = "\Ca\characters2\data\icon\i_soldier_CA.paa";
        model = "\ca\characters_d_BAF\BAF_Soldier_light_BAF";
        picture = "\Ca\characters\data\Ico\i_null_CA.paa";
        portrait = "ca\characters_d_baf\Data\portraits\baf_soldier_CA";
        accuracy = 2;
        camouflage = 1.4;
        cancarrybackpack = 1;
        expansion = 2;
        faction = "BIS_BAF";
        
		displayName = "Survivor";
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
        class Wounds {
            mat[] = {"ca\characters_d_baf\Data\armour.rvmat","ca\characters_d_baf\Data\W1_armour.rvmat","ca\characters_d_baf\Data\W2_armour.rvmat","ca\characters_d_baf\Data\camo.rvmat","ca\characters_d_baf\Data\W1_camo.rvmat", "ca\characters_d_baf\Data\W2_camo.rvmat"};
            tex[] = {};
        };
	};	
    class GUE_Commander;
	class Ranger_DZ: GUE_Commander {
        scope = 2;
        displayName = "Ranger";
        languages[] = {};
		identityTypes[] = {"Head_GUE"};
		faceType = "Man";
        vehicleclass = "Men";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
        
        icon = "\Ca\characters2\data\icon\i_officer_CA.paa";
        model = "\ca\characters2\IndepIns\Prizrak";
        picture = "\Ca\characters\data\Ico\i_off_CA.paa";
        portrait = "\Ca\characters\data\portraits\comBarHead_opFor_ca";
        accuracy = 2;
        camouflage = 1.4;
        cancarrybackpack = 1;
        expansion = 2;
        faction = PMC_BAF;
        
		side = 1;
		weapons[] = {"Throw","Put","Throw_DZ"};
		backpack = "";
		magazines[] = {};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		weaponSlots = "1	 + 	4	 + 12*		256	 + 2*	4096	 + 	2	 + 8*	16  + 12*131072";
		canHideBodies = 1;
        class Wounds {
            mat[] = {"ca\characters2\IndepIns\Data\soldier_khaki.RVmat", "ca\characters2\IndepIns\Data\soldier_khaki_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_khaki_W2.RVmat", "ca\characters2\IndepIns\Data\soldier_flecktarn.RVmat", "ca\characters2\IndepIns\Data\soldier_flecktarn_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_flecktarn_W2.RVmat", "ca\characters2\IndepIns\Data\soldier2_khaki.RVmat", "ca\characters2\IndepIns\Data\soldier2_khaki_W1.RVmat", "ca\characters2\IndepIns\Data\soldier2_khaki_W2.RVmat", "ca\characters2\IndepIns\Data\soldier2_woodland.RVmat", "ca\characters2\IndepIns\Data\soldier2_woodland_W1.RVmat", "ca\characters2\IndepIns\Data\soldier2_woodland_W2.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_khaki.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_khaki_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_khaki_W2.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_flecktarn.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_flecktarn_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_mg_flecktarn_W2.RVmat", "ca\characters2\civil\worker\data\worker.rvmat", "ca\characters2\civil\worker\data\W1_worker.rvmat", "ca\characters2\civil\worker\data\W2_worker.rvmat", "ca\characters2\civil\Woodlander\data\Woodlander.rvmat", "ca\characters2\civil\Woodlander\data\W1_Woodlander.rvmat", "ca\characters2\civil\Woodlander\data\W2_Woodlander.rvmat", "ca\characters2\Civil\Villager\Data\villager.RVmat", "ca\characters2\Civil\Villager\Data\villager_w1.RVmat", "ca\characters2\Civil\Villager\Data\villager_w2.RVmat", "ca\characters2\IndepIns\Data\prizrak.rvmat", "ca\characters2\IndepIns\Data\W1_prizrak.rvmat", "ca\characters2\IndepIns\Data\W2_prizrak.rvmat", "ca\characters2\IndepIns\Data\soldier_back_khaki.RVmat", "ca\characters2\IndepIns\Data\soldier_back_khaki_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_back_khaki_W2.RVmat", "ca\characters2\IndepIns\Data\soldier_back_woodland.RVmat", "ca\characters2\IndepIns\Data\soldier_back_woodland_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_back_woodland_W2.RVmat", "ca\characters2\Data\ghillie.rvmat", "ca\characters2\Data\w1_ghillie.rvmat", "ca\characters2\Data\w2_ghillie.rvmat", "ca\characters2\IndepIns\Data\soldier_com_flecktarn.RVmat", "ca\characters2\IndepIns\Data\soldier_com_flecktarn_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_com_flecktarn_W2.RVmat", "ca\characters2\IndepIns\Data\soldier_com_khaki.RVmat", "ca\characters2\IndepIns\Data\soldier_com_khaki_W1.RVmat", "ca\characters2\IndepIns\Data\soldier_com_khaki_W2.RVmat"};
            tex[] = {};
        };
	};	
	class Bag_Base_EP1;
	class Bag_Base_BAF;
	class Bag_Base;
    class DZ_Patrol_Pack_A3: Bag_Base
    {
        scope = 2;
        displayName = "Patrol Pack";
		picture = "\ca\weapons_e\data\icons\backpack_US_ASSAULT_COYOTE_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_us_assault_Coyote.p3d";
		transportMaxWeapons = 1;
		transportMaxMagazines = 8;
        mass = 28;
        maximumload = 28;
    };
	class DZ_Assault_Pack_A3: Bag_Base
	{
		scope = 2;
		displayName = "Assault Pack";
		picture = "\ca\weapons_e\data\icons\backpack_US_ASSAULT_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_us_assault.p3d";
		transportMaxWeapons = 1;
		transportMaxMagazines = 12;
        mass = 40;
        maximumload = 40;
	};
	class DZ_Czech_Vest_Pouch_A3: Bag_Base
	{
		scope = 2;
		displayname = "Czech Vest Pouch";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_acr_small.p3d";
		picture = "\ca\weapons_e\data\icons\backpack_ACR_small_CA.paa";
		transportMaxWeapons = 0;
		transportMaxMagazines = 12;
        mass = 30;
        maximumload = 30;
	};
	class DZ_ALICE_Pack_A3: Bag_Base
	{
		scope = 2;
		displayName = "ALICE Pack";
		picture = "\ca\weapons_e\data\icons\backpack_TK_ALICE_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_tk_alice.p3d";
		transportMaxWeapons = 2;
		transportMaxMagazines = 16;
        mass = 57;
        maximumload = 74;
	};
	class DZ_TK_Assault_Pack_A3 : Bag_Base
	{
		scope = 2;
		displayName = "Survival ACU";
		picture = "\ca\weapons_e\data\icons\backpack_CIVIL_ASSAULT_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_civil_assault.p3d";
		transportMaxWeapons = 2;
		transportMaxMagazines = 16;
        mass = 57;
        maximumload = 74;
	};
	class DZ_British_ACU_A3 : Bag_Base
	{
		scope = 2;
		displayName = "British Assault Pack";
		model = "\ca\weapons_baf\Backpack_Small_BAF";
		picture = "\ca\weapons_baf\data\UI\backpack_BAF_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		transportMaxWeapons = 3;
		transportMaxMagazines = 18;
        mass = 70;
        maximumload = 86;
	};
	class DZ_CivilBackpack_A3: Bag_Base 
	{
		scope = 2;
		displayName = "Czech Backpack";
		picture = "\ca\weapons_e\data\icons\backpack_ACR_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_acr.p3d";
		transportMaxWeapons = 4;
		transportMaxMagazines = 24;
        mass = 70;
        maximumload = 111;
	};
	class DZ_Backpack_A3: Bag_Base
	{
		scope = 2;
		displayName = "Coyote Backpack";
		picture = "\ca\weapons_e\data\icons\backpack_US_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		model = "\ca\weapons_e\AmmoBoxes\backpack_us.p3d";
		transportMaxWeapons = 6;
		transportMaxMagazines = 24;
        mass = 100;
        maximumload = 160;
	};
	class DZ_DJ_Pack_A3: Bag_Base
	{
		scope = 2;
		displayName = "Legendary Pack";
        picture = "\A3\Weapons_F\Ammoboxes\Bags\data\ui\backpack_CA.paa";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
        hiddenselectionstextures[] = {"\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_khk_co.paa"};
        model = "\A3\weapons_f\Ammoboxes\bags\Backpack_Tortila";
		transportMaxWeapons = 2;
		transportMaxMagazines = 20;
        mass = 100;
        maximumload = 320;
	};
    
    
	//An2_TK_EP1
	class An2_Base_EP1;
	class AN2_DZ: An2_Base_EP1
	{
		displayname = "AN2 Cargo Plane";
		displaynameshort = "AN2_DZ";
		scope = 2;
		side = 2;
		crew = "";
		typicalCargo[] = {};
		hiddenSelections[] = {};
		class TransportMagazines{};
		class TransportWeapons{};
		weapons[] = {};
		magazines[] = {};
		gunnerHasFlares = false;
		commanderCanSee = 2+16+32;
		gunnerCanSee = 2+16+32;
		driverCanSee = 2+16+32;
		transportMaxWeapons = 10;
		transportMaxMagazines = 80;
		transportmaxbackpacks = 15;
	};
	class House {
		class DestructionEffects;
	};
	
	// This parent class is made to make referring to these objects easier later with allMissionObjects
	class SpawnableWreck : House {};

	class UH1Wreck_DZ: SpawnableWreck
	{
		model = "\ca\air2\UH1Y\UH1Y_Crashed.p3d";
		icon = "\ca\air2\data\UI\icon_UH1Y_CA.paa";
		mapSize = 15;
		displayName = "Crashed UH-1Y";
		vehicleClass = "Wrecks";
	};
	class UH60Wreck_DZ: SpawnableWreck
	{
		model = "\Ca\Misc_E\Wreck_UH60_EP1.p3d";
		icon = "ca\Misc_E\data\Icons\Icon_uh60_wreck_CA";
		mapSize = 15;
		displayName = "UH-60 Wreck";
		vehicleClass = "Wrecks";
	};
	class HouseDZ: House {
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = "false";
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				period[] = {0,1};
			};
		};
	};
	class Strategic;
	class NonStrategic;

	class Land_A_FuelStation_Feed: Strategic
	{
		model = "\ca\structures\House\A_FuelStation\A_FuelStation_Feed";
		transportFuel = 0; //50000;
		nameSound = "fuelstation";
	};
	class Land_Ind_MalyKomin: House
	{
		scope = 1;
		armor = 100;
		featureSize = 40;
		model = "\Ca\buildings2\Ind_CementWorks\Ind_MalyKomin\Ind_MalyKomin";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\Buildings2\Ind_CementWorks\Ind_MalyKomin\Ind_MalyKomin_ruins";
				position = "";
				intensity = 1;
				interval = 0.05;
				lifeTime = 1;
			};
		};
		ladders[] = {{"start","end"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Rail_Semafor: House
	{
		scope = 1;
		model = "\CA\Structures\Rail\Rail_Misc\rail_Semafor";
		destrType = "DestructTree";
		class MarkerLights
		{
			class GreenStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Rail_Zavora: House
	{
		scope = 1;
		model = "\CA\Structures\Rail\Rail_Misc\rail_Zavora";
		destrType = "DestructTree";
		class MarkerLights
		{
			class WhiteBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_majak: House
	{
		scope = 1;
		model = "\ca\buildings\majak";
		displayName = "Lighthouse";
		animated = 1;
		ladders[] = {{"start","end"}};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\majak_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		armor = 1000;
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
	};
	class Land_majak2: Land_majak
	{
		model = "\ca\buildings\majak2";
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\majak_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_Vysilac_FM: House
	{
		scope = 1;
		armor = 150;
		destrType = "DestructBuilding";
		ladders[] = {{"start","end"}};
		model = "\ca\buildings\Vysilac_FM";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Destruction
		{
			animations[] = {{"ca\buildings\rtm\vysilac_fm.rtm",0.5,3}};
		};
		displayName = "Radio 1";
	};
	class Land_telek1: House
	{
		scope = 1;
		armor = 600;
		destrType = "DestructBuilding";
		model = "\ca\buildings\telek1";
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\telek1_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		displayName = "Telek 1";
		ladders[] = {{"start1","end1"},{"start2","end2"},{"start3","end3"}};
	};
	class Land_komin: House
	{
		ladders[] = {{"start","end"}};
		model = "\ca\buildings\komin";
		armor = 300;
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\ca\buildings\ruins\komin_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Stoplight01: House
	{
		scope = 1;
		model = "\ca\buildings\Misc\stoplight01";
		armor = 50;
		class MarkerLights
		{
			class YellowTopBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
			class YellowLowBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_Stoplight02: Land_Stoplight01
	{
		model = "\ca\buildings\Misc\stoplight02";
		class MarkerLights
		{
			class YellowTopBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_NavigLight: House
	{
		scope = 1;
		displayName = "";
		model = "\ca\buildings\Misc\NavigLight";
		armor = 50;
		class MarkerLights
		{
			class WhiteStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_runway_edgelight: House
	{
		scope = 1;
		displayName = "";
		model = "\ca\buildings\Misc\runway_edgelight";
		armor = 20;
		class MarkerLights
		{
			class RedStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_VASICore: NonStrategic
	{
		scope = 1;
		animated = 0;
		reversed = 0;
		vehicleClass = "Objects";
		icon = "";
		model = "";
		displayName = "VASI";
		accuracy = 0.2;
		typicalCargo[] = {};
		destrType = "DestructBuilding";
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		cost = 0;
		armor = 100;
		mapSize = 6.4;
		simulation = "house";
	};
	class Land_HouseB_Tenement: House
	{
		armor = 180;
		model = "\Ca\Structures\House\HouseBT\HouseB_Tenement";
		scope = 1;
		featureSize = 50;
		class HitPoints
		{
			class Hit1
			{
				armor = 0.15;
				material = -1;
				name = "dam 1";
				visual = "damT1";
				passThrough = 0;
				convexComponent = "dam 1";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
		};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0.0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = "false";
			};
		};
		class AnimationSources
		{
			class Lights_1
			{
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
			class Lights_2: Lights_1
			{
			};
		};
	};
	class Land_Mil_ControlTower: House
	{
		scope = 1;
		armor = 400;
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Mil\Mil_ControlTower_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
		class HitPoints
		{
			class Hit1
			{
				armor = 0.25;
				material = -1;
				name = "dam 1";
				visual = "damT1";
				passThrough = 1;
				convexComponent = "dam 1";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit2
			{
				armor = 0.25;
				material = -1;
				name = "dam 2";
				visual = "damT2";
				passThrough = 1;
				convexComponent = "dam 2";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit3
			{
				armor = 0.25;
				material = -1;
				name = "dam 3";
				visual = "damT3";
				passThrough = 1;
				convexComponent = "dam 3";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit4
			{
				armor = 0.25;
				material = -1;
				name = "dam 4";
				visual = "damT4";
				passThrough = 1;
				convexComponent = "dam 4";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit5
			{
				armor = 0.25;
				material = -1;
				name = "dam 5";
				visual = "damT5";
				passThrough = 1;
				convexComponent = "dam 5";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hit6
			{
				armor = 0.25;
				material = -1;
				name = "dam 6";
				visual = "damT6";
				passThrough = 1;
				convexComponent = "dam 6";
				class DestructionEffects
				{
					class Dust
					{
						simulation = "particles";
						type = "HousePartDust";
						position = "";
						intensity = 1;
						interval = 1;
						lifeTime = 0.01;
					};
					class Dust2: Dust
					{
						type = "HousePartDustLong";
					};
					class Walls: Dust
					{
						type = "HousePartWall";
					};
				};
			};
			class Hitglass
			{
				armor = 0.0005;
				material = -1;
				name = "dam glass";
				visual = "damTglass";
				passThrough = 0;
				convexComponent = "dam glass";
			};
			class Hittower
			{
				armor = 0.0005;
				material = -1;
				name = "dam tower";
				visual = "damTtower";
				passThrough = 0;
				convexComponent = "dam tower";
			};
		};
		replaceDamagedHitpoints[] = {"Hit1","Hit2","Hit3","Hit4","Hit5","Hit6"};
		class Damage
		{
			tex[] = {};
			mat[] = {"CA\Structures\Mil\Data\Mil_ControlTower_windows1.rvmat","CA\Structures\Mil\Data\destruct_half_Mil_ControlTower_windows1.rvmat","CA\Structures\Mil\Data\destruct_full_Mil_ControlTower_windows1.rvmat"};
		};
		model = "\CA\Structures\Mil\Mil_ControlTower";
		ladders[] = {{"start1","end1"},{"start2","end2"}};
		class AnimationSources
		{
			class dvere_spodni_R
			{
				animPeriod = 1;
				initPhase = 0;
				source = "user";
			};
			class dvere_spodni_L
			{
				animPeriod = 1;
				initPhase = 1;
				source = "user";
			};
			class dvere_vrchni
			{
				animPeriod = 1;
				initPhase = 1;
				source = "user";
			};
			class HitTower
			{
				source = "Hit";
				hitpoint = "HitTower";
				raw = 1;
			};
		};
		class UserActions
		{
			class OpenDoors1
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_open_ca.paa' size='4' />";
				displayName = "Open door";
				position = "Dvere_spodni_R_osa";
				radius = 3;
				onlyForPlayer = 0;
				condition = "this animationPhase ""Dvere_spodni_R"" < 0.5";
				statement = "this animate [""Dvere_spodni_R"", 1];this animate [""Dvere_spodni_L"", 1]";
			};
			class CloseDoors1: OpenDoors1
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_close_ca.paa' size='4' />";
				displayName = "Close door";
				condition = "this animationPhase ""Dvere_spodni_R"" >= 0.5";
				statement = "this animate [""Dvere_spodni_R"", 0];this animate [""Dvere_spodni_L"", 0]";
			};
			class OpenDoors3
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_open_ca.paa' size='4' />";
				displayName = "Open door";
				position = "Dvere_Vrchni_osa";
				radius = 2;
				onlyForPlayer = 0;
				condition = "this animationPhase ""dvere_vrchni"" < 0.5";
				statement = "this animate [""dvere_vrchni"", 1]";
			};
			class CloseDoors3: OpenDoors3
			{
				displayNameDefault = "<img image='\ca\ui\data\ui_action_close_ca.paa' size='4' />";
				displayName = "Close door";
				condition = "this animationPhase ""dvere_vrchni"" >= 0.5";
				statement = "this animate [""dvere_vrchni"", 0]";
			};
		};
		actionBegin1 = "OpenDoors1";
		actionEnd1 = "OpenDoors1";
		actionBegin2 = "OpenDoors3";
		actionEnd2 = "OpenDoors3";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		replaceDamaged = "Land_Mil_ControlTower_dam";
	};
	class Land_NAV_Lighthouse: House
	{
		scope = 1;
		armor = 500;
		featureSize = 15;
		model = "\Ca\Structures\NAV\NAV_Lighthouse";
		ladders[] = {{"start1","end1"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Reflectors
		{
			class MainLight
			{
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				position = "";
				direction = "";
				hitpoint = "";
				selection = "";
				size = 0;
				brightness = 0;
				period[] = {0,1};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\structures\nav\data\nav_lighthouse_multi.rvmat","ca\structures\nav\data\destruct_half_nav_lighthouse_multi.rvmat","ca\structures\nav\data\destruct_full_nav_lighthouse_multi.rvmat","ca\structures\nav\data\nav_lighthouse_windows.rvmat","ca\structures\nav\data\destruct_half_lighthouse_windows.rvmat","ca\structures\nav\data\destruct_full_lighthouse_windows.rvmat"};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Nav\NAV_Lighthouse_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_NAV_Lighthouse2: Land_NAV_Lighthouse
	{
		model = "\Ca\Structures\NAV\NAV_Lighthouse2";
		class Reflectors: Reflectors
		{
			class MainLight: MainLight
			{
				period[] = {0,1};
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\Structures\Nav\NAV_Lighthouse_ruins.p3d";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_A_Crane_02b: House
	{
		scope = 1;
		armor = 110;
		featureSize = 30;
		model = "\ca\buildings2\A_Crane_02\A_Crane_02b";
		destrType = "DestructBuilding";
		ladders[] = {{"start3","end3"},{"start4","end4"},{"start5","end5"},{"start6","end6"}};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class Destruction
		{
			animations[] = {{"ca\buildings2\A_Crane_02\data\anim\crane.rtm",0.5,3}};
		};
	};
	class Land_Farm_WTower: House
	{
		scope = 1;
		armor = 100;
		model = "\CA\buildings2\Farm_WTower\Farm_WTower";
		class MarkerLights
		{
			class RedBlinking
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
		class DestructionEffects: DestructionEffects
		{
			class Ruin1
			{
				simulation = "ruin";
				type = "\Ca\buildings2\Farm_WTower\Farm_WTower_ruins";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
		};
	};
	class Land_A_TVTower_Mid: House
	{
		scope = 1;
		destrType = "DestructNo";
		model = "\ca\Structures\A_TVTower\A_TVTower_Mid";
		featureSize = 150;
		class MarkerLights
		{
			class RedStill
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class Land_A_TVTower_Top: House
	{
		scope = 1;
		destrType = "DestructNo";
		model = "\ca\Structures\A_TVTower\A_TVTower_Top";
		featureSize = 150;
		class MarkerLights
		{
			class RedLight
			{
				name = "";
				color[] = {0,0,0,0};
				ambient[] = {0,0,0,0};
				brightness = 0;
				blinking = 0;
			};
		};
	};
	class WeaponHolderBase;
	class WoodenArrowF : WeaponHolderBase {
		scope = public;
		displayName = "WoodenArrowF";
		model = "\dayz_weapons\models\bolt";
		
		class eventHandlers {
			init = "[(_this select 0),'cfgMagazines','WoodenArrow'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
		};
	};	
	class WeaponHolder_ItemCrowbar: WeaponHolderBase
	{
		scope=2;
		displayName="Crowbar";
		model="\dayz_equip\models\crowbar.p3d";
		class eventHandlers
		{
			init="[(_this select 0),'cfgWeapons','ItemCrowbar'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
		};
	};
	class WeaponHolder_ItemMachete: WeaponHolderBase
	{
		scope=2;
		displayName="Machete";
		model="\z\addons\dayz_communityassets\models\machete.p3d";
		class eventHandlers
		{
			init="[(_this select 0),'cfgWeapons','ItemMachete'] execVM '\z\addons\dayz_code\init\object_pickupAction.sqf';";
		};
	};
};
class CfgNonAIVehicles {
	
	access = 0;
	class StreetLamp
	{
		scope = 0;
		model = "";
		destrType = "DestructTree";
		simulation = "thing";
	};
	class Land_lampa_sidl: StreetLamp
	{
		scope = 1;
		model = "\ca\buildings\Misc\lampa_sidl";
	};
	class Land_lampa_sidl_2: StreetLamp
	{
		scope = 1;
		model = "\ca\buildings\Misc\lampa_sidl_2";
	};
	class Land_lampa_sidl_3: StreetLamp
	{
		scope = 1;
		model = "\ca\buildings\Misc\lampa_sidl_3";
	};
	class Land_lampa_ind: StreetLamp
	{
		scope = 1;
		model = "\ca\buildings\Misc\lampa_ind";
	};
	class Land_lampa_ind_zebr: StreetLamp
	{
		scope = 1;
		model = "\ca\buildings\Misc\lampa_ind_zebr";
	};

};