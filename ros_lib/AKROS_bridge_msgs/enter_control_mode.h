#ifndef _ROS_SERVICE_enter_control_mode_h
#define _ROS_SERVICE_enter_control_mode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace AKROS_bridge_msgs
{

static const char ENTER_CONTROL_MODE[] = "AKROS_bridge_msgs/enter_control_mode";

  class enter_control_modeRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef uint8_t _CAN_ID_type;
      _CAN_ID_type CAN_ID;
      typedef const char* _model_type;
      _model_type model;

    enter_control_modeRequest():
      name(""),
      CAN_ID(0),
      model("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->CAN_ID >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CAN_ID);
      uint32_t length_model = strlen(this->model);
      varToArr(outbuffer + offset, length_model);
      offset += 4;
      memcpy(outbuffer + offset, this->model, length_model);
      offset += length_model;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->CAN_ID =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->CAN_ID);
      uint32_t length_model;
      arrToVar(length_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model-1]=0;
      this->model = (char *)(inbuffer + offset-1);
      offset += length_model;
     return offset;
    }

    virtual const char * getType() override { return ENTER_CONTROL_MODE; };
    virtual const char * getMD5() override { return "22b73b59c9ebd8182ba8616cbfc08039"; };

  };

  class enter_control_modeResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    enter_control_modeResponse():
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

    virtual const char * getType() override { return ENTER_CONTROL_MODE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class enter_control_mode {
    public:
    typedef enter_control_modeRequest Request;
    typedef enter_control_modeResponse Response;
  };

}
#endif
