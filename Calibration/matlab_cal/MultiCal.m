clear;

load test/1.5_test/test0.txt;
load test/1.5_test/test1.txt;
load test/1.5_test/test2.txt;

Data0 = test0;
Data1 = test1;
Data2 = test2;

Time0 = Data0(:,1);
Time1 = Data1(:,1);
Time2 = Data2(:,1);

ForceData0 = Data0(:,[2,3,4]);
ForceData1 = Data1(:,[2,3,4]);
ForceData2 = Data2(:,[2,3,4]);

ForceSensor0 = Data0(:,[5,6,7,8,9,10]);
ForceSensor1 = Data1(:,[5,6,7,8,9,10]);
ForceSensor2 = Data2(:,[5,6,7,8,9,10]);

ForceSensor0_aug = [ForceSensor0 ones(height(ForceSensor0),1)];
ForceSensor1_aug = [ForceSensor1 ones(height(ForceSensor1),1)];
ForceSensor2_aug = [ForceSensor2 ones(height(ForceSensor2),1)];

Calibration0 = ForceSensor0 \ ForceData0;
Calibration1 = ForceSensor1 \ ForceData1;
Calibration2 = ForceSensor2 \ ForceData2;

Calibration0_aug = ForceSensor0_aug \ ForceData0;
Calibration1_aug = ForceSensor1_aug \ ForceData1;
Calibration2_aug = ForceSensor2_aug \ ForceData2;

% testCal01 means using the Calibration Matrix calculated from test0 to
% predict the force sensor data of test1
testCal0_aug = ForceSensor0_aug * Calibration0_aug;
testCal1_aug = ForceSensor1_aug * Calibration1_aug;
testCal2_aug = ForceSensor2_aug * Calibration2_aug;
testCal01_aug = ForceSensor1_aug * Calibration0_aug;
testCal02_aug = ForceSensor2_aug * Calibration0_aug;
testCal10_aug = ForceSensor0_aug * Calibration1_aug;
testCal12_aug = ForceSensor2_aug * Calibration1_aug;
testCal20_aug = ForceSensor0_aug * Calibration2_aug;
testCal21_aug = ForceSensor1_aug * Calibration2_aug;

RMSE0 = RMSE(ForceData0,testCal0_aug);
RMSE1 = RMSE(ForceData1,testCal1_aug);
RMSE2 = RMSE(ForceData2,testCal2_aug);
RMSE01 = RMSE(ForceData1,testCal01_aug);
RMSE02 = RMSE(ForceData2,testCal02_aug);
RMSE10 = RMSE(ForceData0,testCal10_aug);
RMSE12 = RMSE(ForceData2,testCal12_aug);
RMSE20 = RMSE(ForceData0,testCal20_aug);
RMSE21 = RMSE(ForceData1,testCal21_aug);

NRMSD0 = NRMSD(ForceData0,testCal0_aug);
NRMSD1 = NRMSD(ForceData1,testCal1_aug);
NRMSD2 = NRMSD(ForceData2,testCal2_aug);
NRMSD01 = NRMSD(ForceData1,testCal01_aug);
NRMSD02 = NRMSD(ForceData2,testCal02_aug);
NRMSD10 = NRMSD(ForceData0,testCal10_aug);
NRMSD12 = NRMSD(ForceData2,testCal12_aug);
NRMSD20 = NRMSD(ForceData0,testCal20_aug);
NRMSD21 = NRMSD(ForceData1,testCal21_aug);

R_0 = R2(ForceData0,testCal0_aug);
R_1 = R2(ForceData1,testCal1_aug);
R_2 = R2(ForceData2,testCal2_aug);
R_01 = R2(ForceData1,testCal01_aug);
R_02 = R2(ForceData2,testCal02_aug);
R_10 = R2(ForceData0,testCal10_aug);
R_12 = R2(ForceData2,testCal12_aug);
R_20 = R2(ForceData0,testCal20_aug);
R_21 = R2(ForceData1,testCal21_aug);

fprintf("sensor2:\n\n");

fprintf(['RMSE of the calibration results (augmented):\n' ...
    'Calibration of test0: %.4f %.4f %.4f\n' ...
    'Calibration of test1: %.4f %.4f %.4f\n' ...
    'Calibration of test2: %.4f %.4f %.4f\n' ...
    'Using Calibration0 to predict Force1: %.4f %.4f %.4f\n' ...
    'Using Calibration0 to predict Force2: %.4f %.4f %.4f\n' ...
    'Using Calibration1 to predict Force0: %.4f %.4f %.4f\n' ...
    'Using Calibration1 to predict Force2: %.4f %.4f %.4f\n' ...
    'Using Calibration2 to predict Force0: %.4f %.4f %.4f\n' ...
    'Using Calibration2 to predict Force1: %.4f %.4f %.4f\n'] ...
    , RMSE0, RMSE1, RMSE2, RMSE01, RMSE02, RMSE10, RMSE12, RMSE20, RMSE21);
fprintf('\n');

fprintf(['NRMSD of the calibration results (augmented):\n' ...
    'Calibration of test0: %.4f%% %.4f%% %.4f%%\n' ...
    'Calibration of test1: %.4f%% %.4f%% %.4f%%\n' ...
    'Calibration of test2: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration0 to predict Force1: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration0 to predict Force2: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration1 to predict Force0: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration1 to predict Force2: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration2 to predict Force0: %.4f%% %.4f%% %.4f%%\n' ...
    'Using Calibration2 to predict Force1: %.4f%% %.4f%% %.4f%%\n'] ...
    , NRMSD0, NRMSD1, NRMSD2, NRMSD01, NRMSD02, NRMSD10, NRMSD12, NRMSD20, NRMSD21);
fprintf('\n');

fprintf(['R^2 of the calibration results (augmented):\n' ...
    'Calibration of test0: %.4f\n' ...
    'Calibration of test1: %.4f\n' ...
    'Calibration of test2: %.4f\n' ...
    'Using Calibration0 to predict Force1: %.4f\n' ...
    'Using Calibration0 to predict Force2: %.4f\n' ...
    'Using Calibration1 to predict Force0: %.4f\n' ...
    'Using Calibration1 to predict Force2: %.4f\n' ...
    'Using Calibration2 to predict Force0: %.4f\n' ...
    'Using Calibration2 to predict Force1: %.4f\n'] ...
    , R_0, R_1, R_2, R_01, R_02, R_10, R_12, R_20, R_21);

subplot(3,3,1);
hold on;
plot(Time0,ForceData0(:,1),'m');
plot(Time0,testCal0_aug(:,1),'b');
plot(Time0,testCal10_aug(:,1),'r');
plot(Time0,testCal20_aug(:,1),'k');
title('Cal0_x');

subplot(3,3,2);
hold on;
plot(Time0,ForceData0(:,2),'k',"LineWidth",2);
plot(Time0,testCal0_aug(:,2),'b');
plot(Time0,testCal10_aug(:,2),'r');
plot(Time0,testCal20_aug(:,2),'g');
title('Cal0_y');

subplot(3,3,3);
hold on;
plot(Time0,ForceData0(:,3),'k',"LineWidth",2);
plot(Time0,testCal0_aug(:,3),'b');
plot(Time0,testCal10_aug(:,3),'r');
plot(Time0,testCal20_aug(:,3),'g');
title('Cal0_z');

subplot(3,3,4);
hold on;
plot(Time1,ForceData1(:,1),'k',"LineWidth",2);
plot(Time1,testCal1_aug(:,1),'b');
plot(Time1,testCal01_aug(:,1),'r');
plot(Time1,testCal21_aug(:,1),'g');
title('Cal1_x');

subplot(3,3,5);
hold on;
plot(Time1,ForceData1(:,2),'k',"LineWidth",2);
plot(Time1,testCal1_aug(:,2),'b');
plot(Time1,testCal01_aug(:,2),'r');
plot(Time1,testCal21_aug(:,2),'g');
title('Cal1_y');

subplot(3,3,6);
hold on;
plot(Time1,ForceData1(:,3),'k',"LineWidth",2);
plot(Time1,testCal1_aug(:,3),'b');
plot(Time1,testCal01_aug(:,3),'r');
plot(Time1,testCal21_aug(:,3),'g');
title('Cal1_z');

subplot(3,3,7);
hold on;
plot(Time2,ForceData2(:,1),'k',"LineWidth",2);
plot(Time2,testCal2_aug(:,1),'b');
plot(Time2,testCal12_aug(:,1),'r');
plot(Time2,testCal02_aug(:,1),'g');
title('Cal2_x');

subplot(3,3,8);
hold on;
plot(Time2,ForceData2(:,2),'k',"LineWidth",2);
plot(Time2,testCal2_aug(:,2),'b');
plot(Time2,testCal12_aug(:,2),'r');
plot(Time2,testCal02_aug(:,2),'g');
title('Cal2_y');

subplot(3,3,9);
hold on;
plot(Time2,ForceData2(:,3),'k',"LineWidth",2);
plot(Time2,testCal2_aug(:,3),'b');
plot(Time2,testCal12_aug(:,3),'r');
plot(Time2,testCal02_aug(:,3),'g');
title('Cal2_z');