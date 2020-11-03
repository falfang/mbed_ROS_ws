/* JointState_reply_test */
// Receive JointTrajectory message
// Send JointState
#include <ros.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <sensor_msgs/JointState.h>

#include "mbed.h"

#define MOTOR_NUM   2

DigitalOut myled(LED1);
bool initializeFlag = false;

ros::NodeHandle nh;
sensor_msgs::JointState js;



void messageCb(const trajectory_msgs::JointTrajectory& tj_msg);

ros::Publisher jointState_pub("joint_state", &js);
ros::Subscriber<trajectory_msgs::JointTrajectory> sub("tj_cmd", &messageCb);

int main(){
    myled = 0;
    
    nh.getHardware()->setBaud(115200);
    nh.initNode();
    nh.advertise(jointState_pub);
    nh.subscribe(sub);
    
    js.position_length = MOTOR_NUM;
    js.position = (double *)malloc(sizeof(double)*js.position_length);
    
    js.velocity_length = MOTOR_NUM;
    js.velocity = (double *)malloc(sizeof(double)*js.velocity_length);
    
    js.effort_length = MOTOR_NUM;
    js.effort = (double *)malloc(sizeof(double)*js.effort_length);
    
    
    
    js.position[0] = 0.0;
    js.position[1] = 0.0;
    
    js.velocity[0] = 1.0;
    js.velocity[1] = 1.0;
    
    js.effort[0] = 2.0;
    js.effort[1] = 2.0;
    
    // Jointstateをpublishできるか？
    while(1){
        jointState_pub.publish(&js);
        nh.spinOnce();
        wait_ms(20);
    }
}


void messageCb(const trajectory_msgs::JointTrajectory& tj_msg){
    myled = !myled;
    
    // メモリの動的確保（配列型のmsgを扱うときはこれは忘れずに！）
    // JointTrajectoryの要素数を取り出せる！
    if(initializeFlag == false){
        js.position_length = tj_msg.joint_names_length;
        js.position = (double *)malloc(sizeof(double)*js.position_length);
    
        js.velocity_length = tj_msg.joint_names_length;
        js.velocity = (double *)malloc(sizeof(double)*js.velocity_length);
    
        js.effort_length = tj_msg.joint_names_length;
        js.effort = (double *)malloc(sizeof(double)*js.effort_length);
        initializeFlag = true;
    }
    
    // jointStateの中にデータを格納
    // 本番であればCANMessageから実数に変換される
    for(uint8_t i=0; i<js.position_length; i++){
        js.position[i] = tj_msg.points[0].positions[i];
        js.velocity[i] = 1.0 * i;
        js.effort[i] = 2.0 * i;
    }
    jointState_pub.publish(&js);
}