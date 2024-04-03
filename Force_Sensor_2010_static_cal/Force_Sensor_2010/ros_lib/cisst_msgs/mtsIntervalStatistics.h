#ifndef _ROS_cisst_msgs_mtsIntervalStatistics_h
#define _ROS_cisst_msgs_mtsIntervalStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cisst_msgs
{

  class mtsIntervalStatistics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef double _PeriodAvg_type;
      _PeriodAvg_type PeriodAvg;
      typedef double _PeriodStdDev_type;
      _PeriodStdDev_type PeriodStdDev;
      typedef double _PeriodMin_type;
      _PeriodMin_type PeriodMin;
      typedef double _PeriodMax_type;
      _PeriodMax_type PeriodMax;
      typedef double _ComputeTimeAvg_type;
      _ComputeTimeAvg_type ComputeTimeAvg;
      typedef double _ComputeTimeStdDev_type;
      _ComputeTimeStdDev_type ComputeTimeStdDev;
      typedef double _ComputeTimeMin_type;
      _ComputeTimeMin_type ComputeTimeMin;
      typedef double _ComputeTimeMax_type;
      _ComputeTimeMax_type ComputeTimeMax;
      typedef int64_t _NumberOfSamples_type;
      _NumberOfSamples_type NumberOfSamples;
      typedef int64_t _NumberOfOverruns_type;
      _NumberOfOverruns_type NumberOfOverruns;
      typedef double _StatisticsInterval_type;
      _StatisticsInterval_type StatisticsInterval;
      typedef int64_t _UserData_type;
      _UserData_type UserData;

    mtsIntervalStatistics():
      header(),
      PeriodAvg(0),
      PeriodStdDev(0),
      PeriodMin(0),
      PeriodMax(0),
      ComputeTimeAvg(0),
      ComputeTimeStdDev(0),
      ComputeTimeMin(0),
      ComputeTimeMax(0),
      NumberOfSamples(0),
      NumberOfOverruns(0),
      StatisticsInterval(0),
      UserData(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_PeriodAvg;
      u_PeriodAvg.real = this->PeriodAvg;
      *(outbuffer + offset + 0) = (u_PeriodAvg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PeriodAvg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PeriodAvg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PeriodAvg.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PeriodAvg.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PeriodAvg.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PeriodAvg.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PeriodAvg.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PeriodAvg);
      union {
        double real;
        uint64_t base;
      } u_PeriodStdDev;
      u_PeriodStdDev.real = this->PeriodStdDev;
      *(outbuffer + offset + 0) = (u_PeriodStdDev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PeriodStdDev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PeriodStdDev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PeriodStdDev.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PeriodStdDev.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PeriodStdDev.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PeriodStdDev.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PeriodStdDev.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PeriodStdDev);
      union {
        double real;
        uint64_t base;
      } u_PeriodMin;
      u_PeriodMin.real = this->PeriodMin;
      *(outbuffer + offset + 0) = (u_PeriodMin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PeriodMin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PeriodMin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PeriodMin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PeriodMin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PeriodMin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PeriodMin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PeriodMin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PeriodMin);
      union {
        double real;
        uint64_t base;
      } u_PeriodMax;
      u_PeriodMax.real = this->PeriodMax;
      *(outbuffer + offset + 0) = (u_PeriodMax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_PeriodMax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_PeriodMax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_PeriodMax.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_PeriodMax.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_PeriodMax.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_PeriodMax.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_PeriodMax.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->PeriodMax);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeAvg;
      u_ComputeTimeAvg.real = this->ComputeTimeAvg;
      *(outbuffer + offset + 0) = (u_ComputeTimeAvg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ComputeTimeAvg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ComputeTimeAvg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ComputeTimeAvg.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ComputeTimeAvg.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ComputeTimeAvg.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ComputeTimeAvg.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ComputeTimeAvg.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ComputeTimeAvg);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeStdDev;
      u_ComputeTimeStdDev.real = this->ComputeTimeStdDev;
      *(outbuffer + offset + 0) = (u_ComputeTimeStdDev.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ComputeTimeStdDev.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ComputeTimeStdDev.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ComputeTimeStdDev.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ComputeTimeStdDev.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ComputeTimeStdDev.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ComputeTimeStdDev.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ComputeTimeStdDev.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ComputeTimeStdDev);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeMin;
      u_ComputeTimeMin.real = this->ComputeTimeMin;
      *(outbuffer + offset + 0) = (u_ComputeTimeMin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ComputeTimeMin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ComputeTimeMin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ComputeTimeMin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ComputeTimeMin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ComputeTimeMin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ComputeTimeMin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ComputeTimeMin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ComputeTimeMin);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeMax;
      u_ComputeTimeMax.real = this->ComputeTimeMax;
      *(outbuffer + offset + 0) = (u_ComputeTimeMax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ComputeTimeMax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ComputeTimeMax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ComputeTimeMax.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ComputeTimeMax.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ComputeTimeMax.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ComputeTimeMax.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ComputeTimeMax.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ComputeTimeMax);
      union {
        int64_t real;
        uint64_t base;
      } u_NumberOfSamples;
      u_NumberOfSamples.real = this->NumberOfSamples;
      *(outbuffer + offset + 0) = (u_NumberOfSamples.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_NumberOfSamples.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_NumberOfSamples.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_NumberOfSamples.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_NumberOfSamples.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_NumberOfSamples.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_NumberOfSamples.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_NumberOfSamples.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->NumberOfSamples);
      union {
        int64_t real;
        uint64_t base;
      } u_NumberOfOverruns;
      u_NumberOfOverruns.real = this->NumberOfOverruns;
      *(outbuffer + offset + 0) = (u_NumberOfOverruns.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_NumberOfOverruns.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_NumberOfOverruns.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_NumberOfOverruns.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_NumberOfOverruns.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_NumberOfOverruns.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_NumberOfOverruns.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_NumberOfOverruns.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->NumberOfOverruns);
      union {
        double real;
        uint64_t base;
      } u_StatisticsInterval;
      u_StatisticsInterval.real = this->StatisticsInterval;
      *(outbuffer + offset + 0) = (u_StatisticsInterval.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_StatisticsInterval.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_StatisticsInterval.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_StatisticsInterval.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_StatisticsInterval.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_StatisticsInterval.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_StatisticsInterval.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_StatisticsInterval.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->StatisticsInterval);
      union {
        int64_t real;
        uint64_t base;
      } u_UserData;
      u_UserData.real = this->UserData;
      *(outbuffer + offset + 0) = (u_UserData.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_UserData.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_UserData.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_UserData.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_UserData.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_UserData.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_UserData.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_UserData.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->UserData);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_PeriodAvg;
      u_PeriodAvg.base = 0;
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PeriodAvg.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PeriodAvg = u_PeriodAvg.real;
      offset += sizeof(this->PeriodAvg);
      union {
        double real;
        uint64_t base;
      } u_PeriodStdDev;
      u_PeriodStdDev.base = 0;
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PeriodStdDev.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PeriodStdDev = u_PeriodStdDev.real;
      offset += sizeof(this->PeriodStdDev);
      union {
        double real;
        uint64_t base;
      } u_PeriodMin;
      u_PeriodMin.base = 0;
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PeriodMin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PeriodMin = u_PeriodMin.real;
      offset += sizeof(this->PeriodMin);
      union {
        double real;
        uint64_t base;
      } u_PeriodMax;
      u_PeriodMax.base = 0;
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_PeriodMax.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->PeriodMax = u_PeriodMax.real;
      offset += sizeof(this->PeriodMax);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeAvg;
      u_ComputeTimeAvg.base = 0;
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ComputeTimeAvg.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ComputeTimeAvg = u_ComputeTimeAvg.real;
      offset += sizeof(this->ComputeTimeAvg);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeStdDev;
      u_ComputeTimeStdDev.base = 0;
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ComputeTimeStdDev.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ComputeTimeStdDev = u_ComputeTimeStdDev.real;
      offset += sizeof(this->ComputeTimeStdDev);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeMin;
      u_ComputeTimeMin.base = 0;
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ComputeTimeMin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ComputeTimeMin = u_ComputeTimeMin.real;
      offset += sizeof(this->ComputeTimeMin);
      union {
        double real;
        uint64_t base;
      } u_ComputeTimeMax;
      u_ComputeTimeMax.base = 0;
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ComputeTimeMax.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ComputeTimeMax = u_ComputeTimeMax.real;
      offset += sizeof(this->ComputeTimeMax);
      union {
        int64_t real;
        uint64_t base;
      } u_NumberOfSamples;
      u_NumberOfSamples.base = 0;
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_NumberOfSamples.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->NumberOfSamples = u_NumberOfSamples.real;
      offset += sizeof(this->NumberOfSamples);
      union {
        int64_t real;
        uint64_t base;
      } u_NumberOfOverruns;
      u_NumberOfOverruns.base = 0;
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_NumberOfOverruns.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->NumberOfOverruns = u_NumberOfOverruns.real;
      offset += sizeof(this->NumberOfOverruns);
      union {
        double real;
        uint64_t base;
      } u_StatisticsInterval;
      u_StatisticsInterval.base = 0;
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_StatisticsInterval.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->StatisticsInterval = u_StatisticsInterval.real;
      offset += sizeof(this->StatisticsInterval);
      union {
        int64_t real;
        uint64_t base;
      } u_UserData;
      u_UserData.base = 0;
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_UserData.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->UserData = u_UserData.real;
      offset += sizeof(this->UserData);
     return offset;
    }

    virtual const char * getType() override { return "cisst_msgs/mtsIntervalStatistics"; };
    virtual const char * getMD5() override { return "fc177c4951f85470a8a9c80c56822cfb"; };

  };

}
#endif
