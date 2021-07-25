#ifndef _ROS_SERVICE_motor_config_h
#define _ROS_SERVICE_motor_config_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace MELEW_2L_msgs
{

static const char MOTOR_CONFIG[] = "MELEW_2L_msgs/motor_config";

  class motor_configRequest : public ros::Msg
  {
    public:
      typedef uint8_t _configration_mode_type;
      _configration_mode_type configration_mode;
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;

    motor_configRequest():
      configration_mode(0),
      CAN_ID(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->configration_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->configration_mode);
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->configration_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->configration_mode);
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
     return offset;
    }

    virtual const char * getType() override { return MOTOR_CONFIG; };
    virtual const char * getMD5() override { return "f7aa5c350b029098c7b0954ac9603605"; };

  };

  class motor_configResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    motor_configResponse():
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

    virtual const char * getType() override { return MOTOR_CONFIG; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class motor_config {
    public:
    typedef motor_configRequest Request;
    typedef motor_configResponse Response;
  };

}
#endif
