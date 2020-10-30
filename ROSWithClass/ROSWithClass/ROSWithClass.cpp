#include "ROSWithClass.h"

ROSWithClass::ROSWithClass(void) : myled(LED1),
                                   led_pub("/status/led", &led_status),
                                   value_pub("/status/value", &value),
                                   led_sub("/cmd/led", &ROSWithClass::led_Cb, this),
                                   value_sub("/cmd/value", &ROSWithClass::value_Cb, this)
{        
    myled = 0;
    led_status.data = 0;
    value.data = 0;
    nh_priv.initNode();
    nh_priv.advertise(led_pub);
    nh_priv.advertise(value_pub);
    nh_priv.subscribe(led_sub);
    nh_priv.subscribe(value_sub);
}


void ROSWithClass::publish_status(void){
    led_pub.publish(&led_status);
    value_pub.publish(&value);
    nh_priv.spinOnce();
    wait_ms(10);
}

void ROSWithClass::led_Cb(const std_msgs::Bool& led_){
    myled = led_.data;
    led_status.data = led_.data;
}

void ROSWithClass::value_Cb(const std_msgs::Int32& value_){
    value.data = value_.data;
}