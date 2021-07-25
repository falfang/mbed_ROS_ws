// load rosparam and publish the value
#include <mbed.h>
#include <ros.h>
#include <std_msgs/UInt8.h>

ros::NodeHandle nh;
std_msgs::UInt16 msg;
ros::Publisher pub("value", &msg);
int value;

DigitalOut led(D13, 1);

int main(void){
    nh.initNode();
    nh.advertise(pub);

    while(!nh.connected()){
        wait_ms(100);
        nh.spinOnce();
    }

    led = 0;

    while(1){
        if(!nh.getParam("value", &value)){
            value = 0;
        }
        msg.data = value;
        pub.publish(&msg);
        nh.spinOnce();
        wait_ms(200);
    }
}