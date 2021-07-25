#ifndef _ROS_MELEW_2L_msgs_robot_reply_single_h
#define _ROS_MELEW_2L_msgs_robot_reply_single_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace MELEW_2L_msgs
{

  class robot_reply_single : public ros::Msg
  {
    public:
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;
      typedef uint16_t _position_type;
      _position_type position;
      typedef uint16_t _velocity_type;
      _velocity_type velocity;
      typedef uint16_t _effort_type;
      _effort_type effort;

    robot_reply_single():
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
      *(outbuffer + offset + 0) = (this->position >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position >> (8 * 1)) & 0xFF;
      offset += sizeof(this->position);
      *(outbuffer + offset + 0) = (this->velocity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->velocity);
      *(outbuffer + offset + 0) = (this->effort >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort >> (8 * 1)) & 0xFF;
      offset += sizeof(this->effort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
      this->position =  ((uint16_t) (*(inbuffer + offset)));
      this->position |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->position);
      this->velocity =  ((uint16_t) (*(inbuffer + offset)));
      this->velocity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->velocity);
      this->effort =  ((uint16_t) (*(inbuffer + offset)));
      this->effort |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->effort);
     return offset;
    }

    virtual const char * getType() override { return "MELEW_2L_msgs/robot_reply_single"; };
    virtual const char * getMD5() override { return "ec744a452ff757916fabd529f1429b94"; };

  };

}
#endif
