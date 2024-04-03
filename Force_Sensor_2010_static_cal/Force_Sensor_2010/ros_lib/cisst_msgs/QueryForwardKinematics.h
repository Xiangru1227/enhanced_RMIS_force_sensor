#ifndef _ROS_SERVICE_QueryForwardKinematics_h
#define _ROS_SERVICE_QueryForwardKinematics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PoseStamped.h"

namespace cisst_msgs
{

static const char QUERYFORWARDKINEMATICS[] = "cisst_msgs/QueryForwardKinematics";

  class QueryForwardKinematicsRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::JointState _jp_type;
      _jp_type jp;

    QueryForwardKinematicsRequest():
      jp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->jp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->jp.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return QUERYFORWARDKINEMATICS; };
    virtual const char * getMD5() override { return "5191cd748a07d772aa0922cfb255ff24"; };

  };

  class QueryForwardKinematicsResponse : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _cp_type;
      _cp_type cp;

    QueryForwardKinematicsResponse():
      cp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->cp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->cp.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return QUERYFORWARDKINEMATICS; };
    virtual const char * getMD5() override { return "dcf42bd3051d9ea5a90899ecedcae4af"; };

  };

  class QueryForwardKinematics {
    public:
    typedef QueryForwardKinematicsRequest Request;
    typedef QueryForwardKinematicsResponse Response;
  };

}
#endif
