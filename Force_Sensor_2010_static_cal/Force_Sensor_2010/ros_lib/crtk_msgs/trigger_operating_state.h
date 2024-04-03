#ifndef _ROS_SERVICE_trigger_operating_state_h
#define _ROS_SERVICE_trigger_operating_state_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "crtk_msgs/operating_state.h"

namespace crtk_msgs
{

static const char TRIGGER_OPERATING_STATE[] = "crtk_msgs/trigger_operating_state";

  class trigger_operating_stateRequest : public ros::Msg
  {
    public:

    trigger_operating_stateRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return TRIGGER_OPERATING_STATE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class trigger_operating_stateResponse : public ros::Msg
  {
    public:
      typedef crtk_msgs::operating_state _operating_state_type;
      _operating_state_type operating_state;

    trigger_operating_stateResponse():
      operating_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->operating_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->operating_state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TRIGGER_OPERATING_STATE; };
    virtual const char * getMD5() override { return "d941a2d049e2c9ac5773fc4a3a8a892d"; };

  };

  class trigger_operating_state {
    public:
    typedef trigger_operating_stateRequest Request;
    typedef trigger_operating_stateResponse Response;
  };

}
#endif
