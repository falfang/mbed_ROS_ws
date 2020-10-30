/** main.cpp **/
#include <testClass.h>

testClass tc;

int main(void){
    while(1){
        tc.publish_status();
        wait_ms(10);
    }
}