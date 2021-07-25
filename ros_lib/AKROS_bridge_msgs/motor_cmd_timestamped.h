#ifndef _ROS_AKROS_bridge_msgs_motor_cmd_timestamped_h
#define _ROS_AKROS_bridge_msgs_motor_cmd_timestamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "AKROS_bridge_msgs/motor_cmd_single.h"

namespace AKROS_bridge_msgs
{

  class motor_cmd_timestamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t motor_length;
      typedef AKROS_bridge_msgs::motor_cmd_single _motor_type;
      _motor_type st_motor;
      _motor_type * motor;

    motor_cmd_timestamped():
      header(),
      motor_length(0), st_motor(), motor(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->motor_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_length);
      for( uint32_t i = 0; i < motor_length; i++){
      offset += this->motor[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t motor_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_length);
      if(motor_lengthT > motor_length)
        this->motor = (AKROS_bridge_msgs::motor_cmd_single*)realloc(this->motor, motor_lengthT * sizeof(AKROS_bridge_msgs::motor_cmd_single));
      motor_length = motor_lengthT;
      for( uint32_t i = 0; i < motor_length; i++){
      offset += this->st_motor.deserialize(inbuffer + offset);
        memcpy( &(this->motor[i]), &(this->st_motor), sizeof(AKROS_bridge_msgs::motor_cmd_single));
      }
     return offset;
    }

    virtual const char * getType() override { return "AKROS_bridge_msgs/motor_cmd_timestamped"; };
    virtual const char * getMD5() override { return "6a8e1c148ffb72aeb073cc53572f95e2"; };

  };

}
#endif
