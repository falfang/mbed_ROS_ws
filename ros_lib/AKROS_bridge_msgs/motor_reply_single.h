#ifndef _ROS_AKROS_bridge_msgs_motor_reply_single_h
#define _ROS_AKROS_bridge_msgs_motor_reply_single_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace AKROS_bridge_msgs
{

  class motor_reply_single : public ros::Msg
  {
    public:
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;
      typedef float _position_type;
      _position_type position;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _effort_type;
      _effort_type effort;

    motor_reply_single():
      CAN_ID(0),
      position(0),
      velocity(0),
      effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_effort;
      u_effort.real = this->effort;
      *(outbuffer + offset + 0) = (u_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effort.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position = u_position.real;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_effort;
      u_effort.base = 0;
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->effort = u_effort.real;
      offset += sizeof(this->effort);
     return offset;
    }

    virtual const char * getType() override { return "AKROS_bridge_msgs/motor_reply_single"; };
    virtual const char * getMD5() override { return "c96adb76edec85c1ecd74de5b254e099"; };

  };

}
#endif
