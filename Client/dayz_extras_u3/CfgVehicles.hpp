// Generated by unRap v1.06 by Kegetys

class CfgVehicles {
	class US_Delta_Force_EP1;	// External class reference
		
	class Bandit3_DZ : US_Delta_Force_EP1 {
		displayName = "Reaper";
        accuracy = 3.9;
        camouflage = 0.5;
		faceType = "Man";
		scope = public;
		faction = PMC_BAF;
		canCarryBackPack = 1;
		vehicleClass = "Men";
		model = "bb_oa_mercs\desert_blackop.p3d";
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
		
		enableGPS = 1;
		
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		weapons[] = {"Throw","Put","Throw_DZ"};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		backpack = "";
		magazines[] = {};
        
		class Wounds {
			tex[] = {};
			mat[] = {"ca\characters_e\us\data\tex1.rvmat", "ca\characters_E\US\data\W1_tex1.rvmat", "ca\characters_E\US\data\W2_tex1.rvmat", "bb_oa_mercs\textures\acr_soldier_nic.rvmat", "bb_oa_mercs\textures\w1_acr_soldier_nic.rvmat", "bb_oa_mercs\textures\w2_acr_soldier_nic.rvmat", "ca\characters_e\heads\male\defaulthead\data\hhl_white.rvmat", "ca\characters_e\Heads\male\DefaultHead\Data\hhl_Wounds.rvmat", "ca\characters_e\Heads\male\DefaultHead\Data\hhl_Wounds2.rvmat"};
		};
	};	
    
	class Survivor4_DZ : US_Delta_Force_EP1 {
		faceType = "Man";
		canCarryBackPack = 1;
		faction = PMC_BAF;
		scope = public;
		vehicleClass = "Men";
		displayName = "Guardian";
		identityTypes[] = {"Language_BAF","Language_EN_EP1","USMC_Glasses","PMC_Glasses_PMC"};
        accuracy = 3.9;
        camouflage = 0.5;
		enableGPS = 1;
		model = "bb_oa_mercs\merc_oa_at.p3d";
        
		Items[] = {};
		RespawnItems[] = {};
		linkedItems[] = {};
		respawnLinkedItems[] = {};
		weapons[] = {"Throw","Put","Throw_DZ"};
		respawnWeapons[] = {"Throw","Put","Throw_DZ"};
		respawnMagazines[] = {};
		backpack = "";
		magazines[] = {};
        
		class Wounds {
			tex[] = {};
			mat[] = {"ca\characters_e\civil\harris\data\european-man_01.rvmat", "bb_oa_mercs\textures\W1_european-man_01.rvmat", "bb_oa_mercs\textures\W2_european-man_01.rvmat", "ca\characters_e\civil\harris\data\harris.rvmat", "bb_oa_mercs\textures\W1_european-man_01.rvmat", "bb_oa_mercs\textures\W2_european-man_01.rvmat", "bb_oa_mercs\textures\acr_soldier_nic.rvmat", "bb_oa_mercs\textures\w1_acr_soldier_nic.rvmat", "bb_oa_mercs\textures\w2_acr_soldier_nic.rvmat", "ca\characters_e\heads\male\defaulthead\data\hhl_white.rvmat", "ca\characters_e\Heads\male\DefaultHead\Data\hhl_Wounds.rvmat", "ca\characters_e\Heads\male\DefaultHead\Data\hhl_Wounds2.rvmat"};
		};
	};
};