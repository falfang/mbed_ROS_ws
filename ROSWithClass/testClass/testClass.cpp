#include "testClass.h"

testClass::testClass(ros::NodeHandle* n_) 
  : myled(LED1),
    led_pub("/status/led", &led_status),
    value_pub("/status/value", &value),
    led_sub("/cmd/led", &testClass::led_Cb, this),
    value_sub("/cmd/value", &testClass::value_Cb, this),
    server("srv", &testClass::service_Cb, this)
{
    nh_priv = n_;
    myled = 0;
    led_status.data = 0;
    value.data = 0;
    nh_priv->initNode();
    nh_priv->advertise(led_pub);
    nh_priv->advertise(value_pub);
    nh_priv->subscribe(led_sub);
    nh_priv->subscribe(value_sub);
    nh_priv->advertiseService(server);
}


void testClass::publish_status(void){
    __disable_irq();
    led_pub.publish(&led_status);
    value_pub.publish(&value);
    nh_priv->spinOnce();
    __enable_irq();
}

void testClass::led_Cb(const std_msgs::Bool& led_){
    myled = led_.data;
    led_status.data = led_.data;
}

void testClass::value_Cb(const std_msgs::Int32& value_){
    value.data = value_.data;
}

void testClass::service_Cb(const std_srvs::Empty::Request&, std_srvs::Empty::Response&){
    myled = !myled;
    bool temp = led_status.data;
    led_status.data = !temp;
}