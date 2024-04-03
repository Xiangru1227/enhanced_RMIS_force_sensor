#ifndef _ROS_force_sensor_DoubleWrenchStamped_h
#define _ROS_force_sensor_DoubleWrenchStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Wrench.h"

namespace force_sensor
{

  class DoubleWrenchStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Wrench _left_wrench_type;
      _left_wrench_type left_wrench;
      typedef geometry_msgs::Wrench _right_wrench_type;
      _right_wrench_type right_wrench;

    DoubleWrenchStamped():
      header(),
      left_wrench(),
      right_wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->left_wrench.serialize(outbuffer + offset);
      offset += this->right_wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->left_wrench.deserialize(inbuffer + offset);
      offset += this->right_wrench.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "force_sensor/DoubleWrenchStamped"; };
    virtual const char * getMD5() override { return "5d9c8d6c6454f405addc406d2417b29e"; };

  };

}
#endif
