#include <iostream>
#include <cstdio>
#include <string>
#include "conio.h"
#include "cForceSensor.h"
#include "tcpSocket.h"
#include "Timer.h"

#pragma comment (lib, "Ws2_32.lib")
#define PORT "1999"
#define CAL_FILE "FT44298.cal"
#define DEVICE "Dev1/ai0:5"

#define forceSensor
//#define test

using namespace std;

int main() {

#ifdef forceSensor

    Timer t;
    double StartTime = 0;
    double CurrentTime = 0;
    double ElapsedTime = 0;
    double ReferenceTime = 0;

    bool exit = false;
    char kb;
    char x[7], y[7], z[7];
    char* force_ptr[3] = { x, y, z };
    double ForceData[3] = { 0.00,0.00,0.00 };
    char axes[] = { 'x', 'y', 'z' };

    cForceSensor ATISensor;
    ATISensor.Set_Calibration_File_Loc(CAL_FILE);
    ATISensor.Initialize_Force_Sensor(DEVICE);

    TCPSocket server;
    if (!server.initialize(PORT)) {
        cerr << "Server initialization failed." << endl;
        return -1;
    }
    Sleep(100);

    cout << "Sending messages..." << endl;

    ATISensor.Zero_Force_Sensor();
    StartTime = t.seconds();

    while (!exit) {
        CurrentTime = t.seconds();
        ElapsedTime = CurrentTime - StartTime;

        if (CurrentTime - ReferenceTime > 0.001) {

            ATISensor.AcquireFTData();
            ATISensor.GetForceReading(ForceData);

            ReferenceTime = CurrentTime;

            string message = "";
            for (int n = 0; n < 3; n++) {
                char buffer[30];
                snprintf(buffer, sizeof(buffer), "%+.4f", ForceData[n]);
                message += string(buffer) + (n < 2 ? "," : "\n");
            }
            if (!server.send_msg(const_cast<char*>(message.c_str()))) {
                cerr << "Failed to send message." << endl;
                exit = true;
                break;
            }

            printf("Time: %.3f\t", ElapsedTime);
            cout << "Force: ";
            for (int i = 0; i < 3; i++) {
                printf("%c: %.4f \t",axes[i], ForceData[i]);
            }
            cout << "\r";
            Sleep(5);

            if (_kbhit())
            {
                kb = _getch();

                if (kb == 'x')
                {
                    printf("\n");
                    std::cout << "Data capture terminated." << std::endl;
                    exit = true;
                    break;
                }
            }
        }
    }
    server.kill_server();

#endif

#ifdef test

    TCPSocket s;
    bool ex = false;
    if (!s.initialize(PORT)) {
        cerr << "Server initialization failed." << endl;
        return -1;
    }

    while(true){
        if (!s.send_msg(const_cast<char*>("Hi.\n"))) {
            cerr << "Failed to send message." << endl;
        }
    }
    s.kill_server();

#endif

    return 0;
}