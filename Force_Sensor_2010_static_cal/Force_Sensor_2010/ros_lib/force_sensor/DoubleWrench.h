#ifndef _ROS_force_sensor_DoubleWrench_h
#define _ROS_force_sensor_DoubleWrench_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Wrench.h"

namespace force_sensor
{

  class DoubleWrench : public ros::Msg
  {
    public:
      typedef geometry_msgs::Wrench _left_wrench_type;
      _left_wrench_type left_wrench;
      typedef geometry_msgs::Wrench _right_wrench_type;
      _right_wrench_type right_wrench;

    DoubleWrench():
      left_wrench(),
      right_wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->left_wrench.serialize(outbuffer + offset);
      offset += this->right_wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->left_wrench.deserialize(inbuffer + offset);
      offset += this->right_wrench.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "force_sensor/DoubleWrench"; };
    virtual const char * getMD5() override { return "49ed5ae8388ba0d73aaf07522c04d198"; };

  };

}
#endif
