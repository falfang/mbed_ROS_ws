#ifndef _ROS_SERVICE_currentState_h
#define _ROS_SERVICE_currentState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "MELEW_2L_msgs/robot_reply.h"

namespace MELEW_2L_msgs
{

static const char CURRENTSTATE[] = "MELEW_2L_msgs/currentState";

  class currentStateRequest : public ros::Msg
  {
    public:

    currentStateRequest()
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

    virtual const char * getType() override { return CURRENTSTATE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class currentStateResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef MELEW_2L_msgs::robot_reply _reply_type;
      _reply_type reply;

    currentStateResponse():
      success(0),
      reply()
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
      offset += this->reply.serialize(outbuffer + offset);
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
      offset += this->reply.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CURRENTSTATE; };
    virtual const char * getMD5() override { return "14175d60ed38c3c9e3406dd5f44c3247"; };

  };

  class currentState {
    public:
    typedef currentStateRequest Request;
    typedef currentStateResponse Response;
  };

}
#endif
