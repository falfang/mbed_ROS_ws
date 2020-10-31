/** main.cpp **/
#include <testClass.h>

int main(void){
    ros::NodeHandle nh;
    testClass tc(&nh);

    while(1){
        tc.publish_status();
        wait_ms(10);
    }
}