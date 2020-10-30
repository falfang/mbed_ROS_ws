#ifndef ROSWITHCLASS_H_
#define ROSWITHCLASS_H_

#include <mbed.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>

class ROSWithClass{
private:
    DigitalOut myled;
    std_msgs::Bool led_status;
    std_msgs::Int32 value;
    
public:
    ROSWithClass(void);

    ros::NodeHandle nh_priv;
    ros::Publisher led_pub, value_pub;
    ros::Subscriber<std_msgs::Bool, ROSWithClass> led_sub;
    ros::Subscriber<std_msgs::Int32, ROSWithClass> value_sub;

    void led_Cb(const std_msgs::Bool&);
    void value_Cb(const std_msgs::Int32&);

    void publish_status(void);
    void publish_value(void);
};
#endif