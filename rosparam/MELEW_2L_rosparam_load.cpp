// load rosparam and publish the value
#include <mbed.h>
#include <ros.h>
#include <std_msgs/UInt8.h>

ros::NodeHandle nh;
std_msgs::UInt8 Hip_msg, Knee_msg, Wheel_msg;
ros::Publisher Hip_pub("Hip", &Hip_msg);
ros::Publisher Knee_pub("Knee", &Knee_msg);
ros::Publisher Wheel_pub("Wheel", &Wheel_msg);
int can_ids[3];

DigitalOut led(D13, 1);

int main(void){
    nh.initNode();
    nh.advertise(Hip_pub);
    nh.advertise(Knee_pub);
    nh.advertise(Wheel_pub);

    while(!nh.connected()){
        wait_ms(100);
        nh.spinOnce();
    }

    led = 0;

    // load Hip CAN_ID
    if(!nh.getParam("/MELEW_2L/Hip_position_controller/config/can_id", &can_ids[0])){}

    // load Knee CAN_ID
    if(!nh.getParam("/MELEW_2L/Knee_position_controller/config/can_id", &can_ids[1])){}

    // load Wheel CAN_ID
    if(!nh.getParam("/MELEW_2L/Wheel_position_controller/config/can_id", &can_ids[2])){}

    Hip_msg.data = can_ids[0];
    Knee_msg.data = can_ids[1];
    Wheel_msg.data = can_ids[2];

    while(1){
        Hip_pub.publish(&Hip_msg);
        Knee_pub.publish(&Knee_msg);
        Wheel_pub.publish(&Wheel_msg);
        nh.spinOnce();
        wait_ms(200);
    }
}
