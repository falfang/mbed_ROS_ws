/** main.cpp **/
#include <testClass.h>

int main(void){
    ros::NodeHandle nh;
    nh.getHardware()->setBaud(115200);
    nh.initNode();

    testClass tc(&nh);

    while(1){
        tc.publish_status();
        nh.spinOnce();
        wait_ms(20);    //  NG @ 10ms
    }
}