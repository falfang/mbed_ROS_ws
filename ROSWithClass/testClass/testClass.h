#ifndef TESTCLASS_H_
#define TESTCLASS_H_

#include <mbed.h>
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int32.h>
#include <std_srvs/Empty.h>

class testClass{
private:
    DigitalOut myled;
    std_msgs::Bool led_status;
    std_msgs::Int32 value;

    ros::NodeHandle nh;
    ros::Publisher led_pub, value_pub;
    ros::Subscriber<std_msgs::Bool, testClass> led_sub;
    ros::Subscriber<std_msgs::Int32, testClass> value_sub;
    ros::ServiceServer<std_srvs::Empty::Request, std_srvs::Empty::Response, testClass> server;

    void led_Cb(const std_msgs::Bool&);
    void value_Cb(const std_msgs::Int32&);
    void service_Cb(const std_srvs::Empty::Request&, std_srvs::Empty::Response&);
    
public:
    testClass(void);
    void publish_status(void);
};
#endif