clear;

load 1.5_test/hys1.txt;

Data = hys1;

Fx = Data(:,2);
Fy = Data(:,3);
Fz = Data(:,4);

V1 = Data(:,5);
V2 = Data(:,6);
V3 = Data(:,7);
V4 = Data(:,8);
V5 = Data(:,9);
V6 = Data(:,10);

% subplot(3,1,1);
% hold on;
plot(Fx,V1);

% subplot(3,1,2);
% hold on;
% plot(Fx,V5);
% 
% subplot(3,1,3);
% hold on;
% plot(Fx,V6);