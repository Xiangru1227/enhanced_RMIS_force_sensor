#ifndef _ROS_crtk_msgs_operating_state_h
#define _ROS_crtk_msgs_operating_state_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace crtk_msgs
{

  class operating_state : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _state_type;
      _state_type state;
      typedef bool _is_homed_type;
      _is_homed_type is_homed;
      typedef bool _is_busy_type;
      _is_busy_type is_busy;

    operating_state():
      header(),
      state(""),
      is_homed(0),
      is_busy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      union {
        bool real;
        uint8_t base;
      } u_is_homed;
      u_is_homed.real = this->is_homed;
      *(outbuffer + offset + 0) = (u_is_homed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_homed);
      union {
        bool real;
        uint8_t base;
      } u_is_busy;
      u_is_busy.real = this->is_busy;
      *(outbuffer + offset + 0) = (u_is_busy.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_busy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      union {
        bool real;
        uint8_t base;
      } u_is_homed;
      u_is_homed.base = 0;
      u_is_homed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_homed = u_is_homed.real;
      offset += sizeof(this->is_homed);
      union {
        bool real;
        uint8_t base;
      } u_is_busy;
      u_is_busy.base = 0;
      u_is_busy.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_busy = u_is_busy.real;
      offset += sizeof(this->is_busy);
     return offset;
    }

    virtual const char * getType() override { return "crtk_msgs/operating_state"; };
    virtual const char * getMD5() override { return "b1bd4021639d9d9c5fbfff78d6ff3158"; };

  };

}
#endif
