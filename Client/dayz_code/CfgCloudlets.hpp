
class CfgCloudlets {
	class Default;	// External class reference
	
	class SmokeShellBio : Default {
		animationSpeedCoef = 1;
		colorCoef[] = {"colorR", "colorG", "colorB", "colorA"};
		sizeCoef = 1;
		position[] = {0, 0, 0};
		interval = 0.03;
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 7;
		particleFSFrameCount = 48;
		particleFSLoop = 1;
		angleVar = 0.1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = "20";
		moveVelocity[] = {0.2, 0.1, 0.1};
		rotationVelocity = 1;
		weight = 1.2777;
		volume = 1;
		rubbing = 0.05;
		size[] = {0.1, 2, 6};
		color[] = {{0.6, 0.6, 0.6, 0.2}, {0.6, 0.6, 0.6, 0.05}, {0.6, 0.6, 0.6, 0}};
		animationSpeed[] = {1.5, 0.5};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0.04;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.05;
		positionVar[] = {0, 0, 0};
		MoveVelocityVar[] = {0.25, 0.25, 0.25};
		rotationVelocityVar = 20;
		sizeVar = 0.5;
		colorVar[] = {0, 0, 0, 0.35};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};