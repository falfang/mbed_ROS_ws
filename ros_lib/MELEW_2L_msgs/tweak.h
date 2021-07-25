#ifndef _ROS_SERVICE_tweak_h
#define _ROS_SERVICE_tweak_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace MELEW_2L_msgs
{

static const char TWEAK[] = "MELEW_2L_msgs/tweak";

  class tweakRequest : public ros::Msg
  {
    public:
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;
      typedef uint8_t _control_type;
      _control_type control;

    tweakRequest():
      CAN_ID(0),
      control(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      *(outbuffer + offset + 0) = (this->control >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
      this->control =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control);
     return offset;
    }

    virtual const char * getType() override { return TWEAK; };
    virtual const char * getMD5() override { return "b0f1c65003d720245a1f5426f075341a"; };

  };

  class tweakResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    tweakResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return TWEAK; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class tweak {
    public:
    typedef tweakRequest Request;
    typedef tweakResponse Response;
  };

}
#endif
