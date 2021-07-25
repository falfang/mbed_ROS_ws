#ifndef _ROS_AKROS_bridge_msgs_motor_cmd_single_h
#define _ROS_AKROS_bridge_msgs_motor_cmd_single_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace AKROS_bridge_msgs
{

  class motor_cmd_single : public ros::Msg
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
      typedef float _Kp_type;
      _Kp_type Kp;
      typedef float _Kd_type;
      _Kd_type Kd;

    motor_cmd_single():
      CAN_ID(0),
      position(0),
      velocity(0),
      effort(0),
      Kp(0),
      Kd(0)
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
      union {
        float real;
        uint32_t base;
      } u_Kp;
      u_Kp.real = this->Kp;
      *(outbuffer + offset + 0) = (u_Kp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Kp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Kp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Kp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Kp);
      union {
        float real;
        uint32_t base;
      } u_Kd;
      u_Kd.real = this->Kd;
      *(outbuffer + offset + 0) = (u_Kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Kd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Kd);
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
      union {
        float real;
        uint32_t base;
      } u_Kp;
      u_Kp.base = 0;
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Kp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Kp = u_Kp.real;
      offset += sizeof(this->Kp);
      union {
        float real;
        uint32_t base;
      } u_Kd;
      u_Kd.base = 0;
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Kd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Kd = u_Kd.real;
      offset += sizeof(this->Kd);
     return offset;
    }

    virtual const char * getType() override { return "AKROS_bridge_msgs/motor_cmd_single"; };
    virtual const char * getMD5() override { return "86ce620cf2e428947fca430cc81f9d9c"; };

  };

}
#endif
