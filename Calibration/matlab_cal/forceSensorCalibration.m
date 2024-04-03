clear;

load test/1.5_test/test.txt
load test/1.5_test/test_zeroed.txt;

Data = test;
Data0 = test_zeroed;

Time = Data(:,1);
Time0 = Data0(:,1);

ForceData = Data(:,[2,3,4]);
ForceData0 = Data0(:,[2,3,4]);
ForceSensor = Data(:,[5,6,7,8,9,10]);
ForceSensor0 = Data0(:,[5,6,7,8,9,10]);

ForceSensor_aug = [ForceSensor ones(height(ForceSensor),1)];
ForceSensor0_aug = [ForceSensor0 ones(height(ForceSensor0),1)];

Calibration = ForceSensor \ ForceData;
Calibration0 = ForceSensor0 \ ForceData0;
Calibration_aug = ForceSensor_aug \ ForceData;
Calibration0_aug = ForceSensor0_aug \ ForceData0;

testCal = ForceSensor * Calibration;
testCal0 = ForceSensor0 * Calibration0;
testCal_aug = ForceSensor_aug * Calibration_aug;
testCal0_aug = ForceSensor0_aug * Calibration0_aug;

RMSE_aug = RMSE(ForceData,testCal_aug);
RMSE0_aug = RMSE(ForceData0,testCal0_aug);

NRMSD_aug = NRMSD(ForceData,testCal_aug);
NRMSD0_aug = NRMSD(ForceData0,testCal0_aug);

Rx_aug = R2(ForceData(:,1),testCal_aug(:,1));
Ry_aug = R2(ForceData(:,2),testCal_aug(:,2));
Rz_aug = R2(ForceData(:,3),testCal_aug(:,3));
Rx0_aug = R2(ForceData0(:,1),testCal0_aug(:,1));
Ry0_aug = R2(ForceData0(:,2),testCal0_aug(:,2));
Rz0_aug = R2(ForceData0(:,3),testCal0_aug(:,3));

fprintf("sensor without insert layer:\n\n");

fprintf('RMSE of the calibration results (augmented): %.4f, %.4f %.4f.\n', RMSE_aug);
fprintf('NRMSD of the calibration results (augmented): %.4f%%, %.4f%% %.4f%%.\n', NRMSD_aug);
fprintf('R^2 of the calibration results (augmented): %.4f, %.4f, %.4f.\n', Rx_aug, Ry_aug, Rz_aug);
fprintf('\n');

fprintf('RMSE of the zeroed calibration results (augmented): %.4f, %.4f %.4f.\n', RMSE0_aug);
fprintf('NRMSD of the zeroed calibration results (augmented): %.4f%%, %.4f%% %.4f%%.\n', NRMSD0_aug);
fprintf('R^2 of the zeroed calibration results (augmented): %.4f, %.4f, %.4f.\n', Rx0_aug, Ry0_aug, Rz0_aug);

subplot(3,2,1);
hold on;
plot(Time,ForceData(:,1),'black');
plot(Time,testCal(:,1),'red');
plot(Time,testCal_aug(:,1),'blue');
title('Force Data in x-deriction');

subplot(3,2,3);
hold on;
plot(Time,ForceData(:,2),'black');
plot(Time,testCal(:,2),'red');
plot(Time,testCal_aug(:,2),'blue');
title('Force Data in y-deriction');

subplot(3,2,5);
hold on;
plot(Time,ForceData(:,3),'black');
plot(Time,testCal(:,3),'red');
plot(Time,testCal_aug(:,3),'blue');
title('Force Data in z-deriction');

subplot(3,2,2);
hold on;
plot(Time0,ForceData0(:,1),'black');
plot(Time0,testCal0(:,1),'red');
plot(Time0,testCal0_aug(:,1),'blue');
title('Force Data in x-deriction (zeroed)');

subplot(3,2,4);
hold on;
plot(Time0,ForceData0(:,2),'black');
plot(Time0,testCal0(:,2),'red');
plot(Time0,testCal0_aug(:,2),'blue');
title('Force Data in y-deriction (zeroed)');

subplot(3,2,6);
hold on;
plot(Time0,ForceData0(:,3),'black');
plot(Time0,testCal0(:,3),'red');
plot(Time0,testCal0_aug(:,3),'blue');
title('Force Data in z-deriction (zeroed)');