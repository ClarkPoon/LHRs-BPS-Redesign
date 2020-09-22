#include "io.h"

static bool currentInitFlag = false;
static bool tempInitFlag = false;
static bool voltInitFlag = false;
static bool contactorInitFlag = false;
static bool contactorState = false;
static int voltage, temperature, current;

//functions to simulate initializing drivers

void currentInit(void){
	currentInitFlag = true;
	current = 0;
}

void tempInit(void){
	tempInitFlag = true;
	temperature = 0;
}

void voltInit(void){
	voltInitFlag = true;
	voltage = MIN_VOLTAGE;
}

void contactorInit(void){
	contactorInitFlag = true;
}

//functions to read state of battery
//feel free to make these more complex for testing purposes

int currentRead(void){
	if (currentInitFlag){
		return current++;
	}else{
		return -1000000;
	}
}

int tempRead(void){
	if (tempInitFlag){
		return temperature++;
	}else{
		return -1000000;
	}
}

int voltRead(void){
	if (voltInitFlag){
		return voltage++;
	}else{
		return -1000000;
	}
	
}

//function to control contactor
//true is on (closed circuit), false is off (open circuit)
void setContactor(bool state){
	contactorState = state;
	if (contactorState)
		printf("contactor on\n");
	else
		printf("contactor off\n");
}

