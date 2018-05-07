#include "rctank.h"
#include "unistd.h"
#include <iostream>

int main(){
    if( wiringPiSetupGpio() < 0){ //initialize failed
	return 1; 
    }
    
    DcMotor motorL(5, 6);
    DcMotor motorR(13,19);
    int voltage_level = 5; // 0 ~ 10
    int cmd;
    Mode current_mode = STOP;

    while(cmd != 6){
	std::cout << "0:STOP 1:FORWARD 2:BACKWARD 3:CW 4:CCW 5:Change Voltage Level 6:Terminate" << std::endl;
	std::cin >> cmd;
	if( (cmd == 0) || (cmd == 6) ){
	    ChangeDriveMode(STOP, voltage_level, motorL, motorR);
	    current_mode = STOP;
	}
	else if(cmd == 1){
	    ChangeDriveMode(FORWARD, voltage_level, motorL, motorR);
	    current_mode = FORWARD;
	}
	else if(cmd == 2){
	    ChangeDriveMode(BACKWARD, voltage_level, motorL, motorR);
	    current_mode = BACKWARD;
	}
	else if(cmd == 3){
	    ChangeDriveMode(CW, voltage_level, motorL, motorR);
	    current_mode = CW;
	}
	else if(cmd == 4){
	    ChangeDriveMode(CCW, voltage_level, motorL, motorR);
	    current_mode = CCW;
	}
	else if(cmd == 5){
	    std::cout << "Current voltage level is " << voltage_level << std::endl;
	    std::cout << "Input voltage level (0 ~ 10)" << std::endl;
	    std::cin >> voltage_level;
	    ChangeDriveMode(current_mode, voltage_level, motorL, motorR);
	}
    }
    return 0;
}    
    


