/** main.cpp **/
#include <ROSWithClass.h>

ROSWithClass rwc;

int main(void){    
    while(1){
        rwc.publish_status();
    }
}