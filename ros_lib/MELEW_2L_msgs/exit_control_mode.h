#ifndef _ROS_SERVICE_exit_control_mode_h
#define _ROS_SERVICE_exit_control_mode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace MELEW_2L_msgs
{

static const char EXIT_CONTROL_MODE[] = "MELEW_2L_msgs/exit_control_mode";

  class exit_control_modeRequest : public ros::Msg
  {
    public:
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;

    exit_control_modeRequest():
      CAN_ID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
     return offset;
    }

    virtual const char * getType() override { return EXIT_CONTROL_MODE; };
    virtual const char * getMD5() override { return "f930db358785fbbc5d2a0424c4fb00c8"; };

  };

  class exit_control_modeResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    exit_control_modeResponse():
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

    virtual const char * getType() override { return EXIT_CONTROL_MODE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class exit_control_mode {
    public:
    typedef exit_control_modeRequest Request;
    typedef exit_control_modeResponse Response;
  };

}
#endif
