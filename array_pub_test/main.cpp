/** main.cpp **/
#include <mbed.h>
#include <ros.h>
#include <basic_lecture/simple_msg.h>   // = simple_msg_single[]

ros::NodeHandle nh;
basic_lecture::simple_msg msg;
ros::Publisher pub("array", &msg);

int main(void){
    nh.getHardware()->setBaud(115200);
    nh.initNode();
    nh.advertise(pub);

    wait_ms(10);

    // 自作msgの配列に対するメモリ確保
    /*  これだと何も送られて来ない．Lost sync with deviceが起こる
    msg.data_length = 2;
    msg.data = (basic_lecture::simple_msg::_data_type *)malloc(sizeof(basic_lecture::simple_msg::_data_type) * 2);
    */
    
    // これでうまくいった！！！
    msg.data_length = 2;
    msg.data = new basic_lecture::simple_msg::_data_type[2];
    
    
    msg.data[0].a = 0;
    msg.data[0].b = 1.0;

    msg.data[1].a = 1;
    msg.data[1].b = 2.0;


    while(1){
        pub.publish(&msg);
        nh.spinOnce();
        wait_ms(20);
    }
}