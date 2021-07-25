#ifndef _ROS_SERVICE_servo_setting_h
#define _ROS_SERVICE_servo_setting_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace MELEW_2L_msgs
{

static const char SERVO_SETTING[] = "MELEW_2L_msgs/servo_setting";

  class servo_settingRequest : public ros::Msg
  {
    public:
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;
      typedef bool _servo_type;
      _servo_type servo;

    servo_settingRequest():
      CAN_ID(0),
      servo(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      union {
        bool real;
        uint8_t base;
      } u_servo;
      u_servo.real = this->servo;
      *(outbuffer + offset + 0) = (u_servo.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
      union {
        bool real;
        uint8_t base;
      } u_servo;
      u_servo.base = 0;
      u_servo.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->servo = u_servo.real;
      offset += sizeof(this->servo);
     return offset;
    }

    virtual const char * getType() override { return SERVO_SETTING; };
    virtual const char * getMD5() override { return "df038de2dc5248103d5afa6a0f26dc87"; };

  };

  class servo_settingResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    servo_settingResponse():
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

    virtual const char * getType() override { return SERVO_SETTING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class servo_setting {
    public:
    typedef servo_settingRequest Request;
    typedef servo_settingResponse Response;
  };

}
#endif
