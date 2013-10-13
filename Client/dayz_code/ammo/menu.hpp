
#include "\z\addons\dayz_code\ammo\common.hpp"
#define GUI_GRID_H 0.04
#define GUI_GRID_W 0.025
#define GUI_GRID_X 0
#define GUI_GRID_Y 0

class menuDiag {
	idd = 2500;
	movingEnable = true;
	enableSimulation = true;
    onLoad = "breakActive = false; combineActive = false; breakActive2 = false; combineActive2 = false; [] spawn fnc_usec_selfActions;";
    
	class controlsBackground {
		class RscTitleBackground:a_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 16.5 * GUI_GRID_W + GUI_GRID_X;
			y = (9 * GUI_GRID_H + GUI_GRID_Y) - 0.044;
			w = 6.5 * GUI_GRID_W;
			h = (1 / 25);
		};
		class MainBackground:a_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
            x = 16.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9 * GUI_GRID_H + GUI_GRID_Y;
            w = 6.5 * GUI_GRID_W;
            h = 6.5 * GUI_GRID_H;
		};
	};
	
	class controls {
	
        class RscButtonInvis : a_RscButtonMenu
        {
            idc = 55524;
            text = ""; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0};
            onButtonClick = "closeDialog 0;";
            x = 1000 * GUI_GRID_W + GUI_GRID_X;
            y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1600: a_RscButtonMenu
        {
            idc = 55521;
            text = "Cancel"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0;";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 14 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1601: a_RscButtonMenu
        {
            idc = 55522;
            text = "Ammo"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0; createDialog 'ammoDiag';";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1602: a_RscButtonMenu
        {
            idc = 55523;
            text = "Use"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\ammo\listU.sqf';";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 11 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1603: a_RscButtonMenu
        {
            idc = 55525;
            text = "Groups"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\group\dialog\groupMenu.sqf';";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 12.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
	};
};

class ammoDiag {
	idd = 2500;
	movingEnable = true;
	enableSimulation = true;
    onLoad = "breakActive = false; combineActive = false; breakActive2 = false; combineActive2 = false;";
    
	class controlsBackground {
		class RscTitleBackground:a_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 16.5 * GUI_GRID_W + GUI_GRID_X;
			y = (9 * GUI_GRID_H + GUI_GRID_Y) - 0.044;
			w = 6.5 * GUI_GRID_W;
			h = (1 / 25);
		};
		class MainBackground:a_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
            x = 16.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9 * GUI_GRID_H + GUI_GRID_Y;
            w = 6.5 * GUI_GRID_W;
            h = 5 * GUI_GRID_H;
		};
	};
	
	class controls {
	
        class RscButtonInvis : a_RscButtonMenu
        {
            idc = 55524;
            text = ""; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0};
            onButtonClick = "closeDialog 0;";
            x = 1000 * GUI_GRID_W + GUI_GRID_X;
            y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1600: a_RscButtonMenu
        {
            idc = 55521;
            text = "Cancel"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0;";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 12.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1601: a_RscButtonMenu
        {
            idc = 55522;
            text = "Break"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\ammo\listB.sqf';";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
        class RscButton_1602: a_RscButtonMenu
        {
            idc = 55523;
            text = "Combine"; //--- ToDo: Localize;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
            onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\ammo\listC.sqf';";
            x = 17.5 * GUI_GRID_W + GUI_GRID_X;
            y = 11 * GUI_GRID_H + GUI_GRID_Y;
            w = 4.5 * GUI_GRID_W;
            h = 1 * GUI_GRID_H;
        };
	};
};


class useManagement {
	idd = 2553;
	movingEnable = true;
	enableSimulation = true;
	
	class controlsBackground {
		class RscTitleBackground:a_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.04;
			y = 0.2;
			w = 0.915;
			h = (1 / 25);
		};
		
		class MainBackground:a_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.04;
			y = 0.2 + (11 / 250);
			w = 0.915;
			h = 0.57 - (22 / 250);
		};
		
		class foodText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Food";
			sizeEx = 0.04;
			x = 0.06; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class drinkText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Drinks";
			sizeEx = 0.04;
			
			x = 0.66; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class medText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Medical";
			sizeEx = 0.04;
			
			x = 0.36; y = 0.27;
			w = 0.275; h = 0.04;
		};
	};
	
	class controls {
    
		class foodList : a_RscListBox 
		{
			idc = 2505;
			text = "";
			sizeEx = 0.032;
			
			x = 0.06; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		class useFood : a_RscButtonMenu
		{
			idc = -1;
			text = "    Eat";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[0] spawn player_useU;";
			x = 0.12875; y = 0.67;
			w = 0.1375;
			h = (1 / 25);
		};
		
		class drinkList : a_RscListBox 
		{
			idc = 2506;
			text = "";
			sizeEx = 0.032;
			
			x = 0.66; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		class useDrink : a_RscButtonMenu
		{
			idc = -1;
			text = "   Drink";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[1] spawn player_useU;";
			x = 0.72875; y = 0.67;
			w = 0.1375;
			h = (1 / 25);
		};
		
		class medList : a_RscListBox 
		{
			idc = 2507;
			text = "";
			sizeEx = 0.032;
			
			x = 0.36; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		class useMed : a_RscButtonMenu
		{
			idc = -1;
			text = " Administer";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[2] spawn player_useU;";
			x = 0.42875; y = 0.67;
			w = 0.1375;
			h = (1 / 25);
		};
			
		class Title : a_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = -1;
            style = 2;
			text = "Use Items";
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};
        
		class ButtonClose : a_RscButtonMenu {
			idc = -1;
			text = "Close";
            style = 2;
			onButtonClick = "closeDialog 0;";
			x = 0.04;
			y = 0.77 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class ButtonRefresh : a_RscButtonMenu {
			idc = -1;
			text = "Refresh";
            style = 2;
			onButtonClick = "[0] spawn player_refreshU;";
			x = 0.955 - (6.25 / 40);
			y = 0.77 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};


class breakManagement {
	idd = 2551;
	movingEnable = true;
	enableSimulation = true;
    onUnload = "breakActive = false; breakActive2 = false;";
	
	class controlsBackground {
		class RscTitleBackground:a_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};
		
		class MainBackground:a_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.1;
			y = 0.2 + (11 / 250);
			w = 0.8;
			h = 0.6 - (22 / 250);
		};
		
		class inputText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Input";
			sizeEx = 0.04;
			x = 0.12; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class outText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Output";
			sizeEx = 0.04;
			
			x = 0.60; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class noteText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Breaking or combining will drop the output in a pile below you.";
			sizeEx = 0.04;
            
			x = 0.12;
			y = 0.696;
			w = 0.755;
			h = (1 / 25);
		};
	};
	
	class controls {
    
		class inList : a_RscListBox 
		{
			idc = 2501;
			text = "";
			sizeEx = 0.032;
			onLBSelChanged = "[_this] execVM '\z\addons\dayz_code\ammo\list2B.sqf';";
			
			x = 0.12; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		class outList : a_RscListBox 
		{
			idc = 2502;
			text = "";
			sizeEx = 0.032;
			
			x = 0.60; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		
		class breakOne : a_RscButtonMenu
		{
			idc = -1;
			text = "Break";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[_this] execVM '\z\addons\dayz_code\ammo\break.sqf';";
			x = 0.42; y = 0.35;
			w = (6.25 / 40);
			h = (1 / 25);
		};
		
		class breakAll : a_RscButtonMenu
		{
			idc = -1;
			text = "Break All";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[_this] execVM '\z\addons\dayz_code\ammo\breakAll.sqf';";
			x = 0.42; y = 0.40;
			w = (6.25 / 40);
			h = (1 / 25);
		};
			
		class Title : a_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = -1;
            style = 2;
			text = "Break Magazines";
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};
        
		class ButtonClose : a_RscButtonMenu {
			idc = -1;
			text = "Close";
            style = 2;
			onButtonClick = "closeDialog 0; breakActive = false; breakActive2 = false;";
			x = 0.1;
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class ButtonCombine : a_RscButtonMenu {
			idc = -1;
			text = "Combine";
            style = 2;
			onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\ammo\listC.sqf';";
			x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};

class combineManagement {
	idd = 2552;
	movingEnable = true;
	enableSimulation = true;
	
	class controlsBackground {
		class RscTitleBackground:a_RscText {
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"};
			idc = -1;
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};
		
		class MainBackground:a_RscText {
			colorBackground[] = {0, 0, 0, 0.7};
			idc = -1;
			x = 0.1;
			y = 0.2 + (11 / 250);
			w = 0.8;
			h = 0.6 - (22 / 250);
		};
		
		class inputText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Input";
			sizeEx = 0.04;
			x = 0.12; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class outText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Output";
			sizeEx = 0.04;
			
			x = 0.60; y = 0.27;
			w = 0.275; h = 0.04;
		};
		
		class noteText : a_RscText
		{
			idc = -1;
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			text = "Breaking or combining will drop the output in a pile below you.";
			sizeEx = 0.04;
            
			x = 0.12;
			y = 0.696;
			w = 0.755;
			h = (1 / 25);
		};
	};
	
	class controls {
    
		class inList : a_RscListBox 
		{
			idc = 2503;
			text = "";
			sizeEx = 0.032;
			onLBSelChanged = "[_this] execVM '\z\addons\dayz_code\ammo\list2C.sqf';";
			
			x = 0.12; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		class outList : a_RscListBox 
		{
			idc = 2504;
			text = "";
			sizeEx = 0.032;
			x = 0.60; y = 0.31;
			w = 0.275; h = 0.340;
		};
		
		
		class combineOne : a_RscButtonMenu
		{
			idc = -1;
			text = "Combine";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[_this] execVM '\z\addons\dayz_code\ammo\combine.sqf';";
			x = 0.42; y = 0.35;
			w = (6.25 / 40);
			h = (1 / 25);
		};
		
		class combineAll : a_RscButtonMenu
		{
			idc = -1;
			text = "Combine All";
            style = 2;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 0.5};
			onButtonClick = "[_this] execVM '\z\addons\dayz_code\ammo\combineAll.sqf';";
			x = 0.42; y = 0.40;
			w = (6.25 / 40);
			h = (1 / 25);
		};
			
		class Title : a_RscTitle {
			colorBackground[] = {0, 0, 0, 0};
			idc = -1;
            style = 2;
			text = "Combine Magazines";
			x = 0.1;
			y = 0.2;
			w = 0.8;
			h = (1 / 25);
		};
        
		class ButtonClose : a_RscButtonMenu {
			idc = -1;
			text = "Close";
            style = 2;
			onButtonClick = "closeDialog 0; combineActive = false; combineActive2 = false;";
			x = 0.1;
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};

		class ButtonBreak : a_RscButtonMenu {
			idc = -1;
			text = "Break";
            style = 2;
			onButtonClick = "closeDialog 0; [] execVM '\z\addons\dayz_code\ammo\listB.sqf';";
			x = 0.1 + (6.25 / 40) + (1 / 250 / (safezoneW / safezoneH));
			y = 0.8 - (1 / 25);
			w = (6.25 / 40);
			h = (1 / 25);
		};
	};
};