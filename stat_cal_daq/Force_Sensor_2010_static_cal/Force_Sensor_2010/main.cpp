#include <SerialPort.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
#include "cForceSensor.h"
#include "Timer.h"

Timer t;
double StartTime = 0;
double CurrentTime = 0;
double ElapsedTime = 0;
double ReferenceTime = 0;


int main()
{
	std::string portName = "COM3";
	SerialPort* serialport = new SerialPort(portName.c_str());
	double ForceData[3] = {0.00,0.00,0.00};
	int bytesread = 0;
	bool sent = false;
	int buf_idx = 0;
	
	std::string char_string;
	double SensorData[6];

	// Define the force sensor objects from the DAQ
	cForceSensor g_ForceSensor;
	g_ForceSensor.Set_Calibration_File_Loc("FT44298.cal");
	g_ForceSensor.Initialize_Force_Sensor("Dev1/ai0:5");

	Sleep(100);

	if (serialport->isConnected())
		printf("Serial port connected.\n");
	else std::cout << "Unable to connect to " << portName << std::endl;

	//preallocate memory we are printing x.xx,x.xx,x.xx\n which is 14 chars
	char buf[100];
	char outbuf = 'x';

	char kb;
	bool zeroed_flag = false;
	double offset[6] = {0,0,0,0,0,0};
	g_ForceSensor.Zero_Force_Sensor();
	StartTime = t.seconds();

	bool new_file = true;
	FILE *f;

	while (true) {

		CurrentTime = t.seconds();
		ElapsedTime = CurrentTime - StartTime;

		if (new_file && serialport->isConnected())
		{
			std::string filename;
			std::cout << "Enter filename: ";
			std::cin >> filename;
			std::cout << "\n Saving to..." << filename << "\n";
			f = fopen(filename.c_str(), "w");
			new_file = false;
		}

		if (CurrentTime - ReferenceTime > 0.01 && ElapsedTime > 1) {
			int i = g_ForceSensor.AcquireFTData();
			g_ForceSensor.GetForceReading(ForceData);
			ReferenceTime = CurrentTime;

			//if sent flag is false we ask the arduino for a new set of readings
			if (sent == false) 
			{
				sent = serialport->writeSerialPort(&outbuf, 1);
			}
			if (sent == true) {
				//if we succeed in sending then we read the serial port 
				bytesread = serialport->readSerialPort(&buf[buf_idx], 35);
				buf_idx += bytesread;
				if (buf_idx > 30)
				{
					sent = false;
					char_string = std::string(buf);
					buf_idx = 0;
				
					// Loop to record and convert the string data into double so that we can perform maths on the quantities.
					int c = 0;
					for (int n = 0; n < 30; n++)
					{
						if (n % 5 == 0)
						{	
 							SensorData[c] = std::stod(char_string.substr(n, 4));
							c++;
						}
					}
				
					if (!zeroed_flag) {
						for (int n = 0; n < 6; n++) {
							offset[n] = SensorData[n];
						}
						zeroed_flag = true;
					}

					// print data to terminal
					printf("%.3f, ", ElapsedTime);
					for (int n = 0; n < 6; n++)
						printf("%.2f, ", (SensorData[n] - offset[n]));
					printf(" F: %+.4f, %+.4f, %+.4f\r", -ForceData[1], ForceData[0], ForceData[2]);

					// Comment out the keyboard control to the arduino
					if (_kbhit())
					{
						kb = _getch();

						if (kb == 'z')
						{
							for (int n = 0; n < 6; n++) {
								offset[n] = SensorData[n];
							}
							printf("\n");
						}
						if (kb == 'x')
						{
							printf("\n");
							std::cout << "Data capture terminated." << std::endl;
							fclose(f);
							break;
						}
					}

					fflush(stdin);

					fprintf(f, "%.3f, ", ElapsedTime);
					fprintf(f, "%.4f, %.4f, %.4f, ", -ForceData[1], ForceData[0], ForceData[2]);
					for (int n = 0; n < 5; n++)
						fprintf(f, "%.2f, ", SensorData[n] - offset[n]);
					fprintf(f, "%.2f\n", SensorData[5] - offset[5]);
				}
			}
		}
	}
	printf("Data collection done. Exiting...");
}