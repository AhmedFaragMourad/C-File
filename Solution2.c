/**************************************************************************************************
 Name        : Vehicle Control system.c
 Author      : Ahmed Farag
 Description :Vehicle Control system
 **************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "math.h"
#include "DataBase.h"
#define true 1
#define false 0
void onvech(void);

void trafficData();
void ACtemp();
void EngineTemp();
void sysstat();
volatile int speed=0;
volatile int AC=false;
volatile float roomTemp=0;
volatile float roomtemp2=0;

int Etc=0;
int enginetemp=0;
char display (void){
/* ******************************************************
 * =======First menu to chose from========================
 */
	printf("Welcome to Our System \n");
			fflush(stdout);
			printf("Please chose one of the below options:\n ");
				fflush(stdout);
				printf("a. Turn on the vehicle engine\n b. Turn off the vehicle engine\n c. Quit the system\n");
				fflush(stdout);
				char chose;
/////////////// Scan the chosen character from User ///////////////////////////////////////////
				fflush(stdin);
					scanf("%c",&chose);
					if(chose=='a'||chose=='A'){
						onvech();
					}
					 if(chose=='b'||chose=='B'){
						display();
					}
					 if (chose=='c'||chose=='C'){
						return 0;
					}

					return chose;

}
//Beginning of the program
int main(){
//calling the first menu to be displayed
display();
//calling the System Status Func. to display system status
sysstat();
}
/*
 * display Sensor set menu
 * =====================menu that simulate vehicle sensors readings===============================
 */
void onvech(void){
	printf("a. Turn off the engine.\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor).\n");
	printf("d. Set the engine temperature (Engine Temperature Sensor).\n");
	fflush(stdout);
	char traffic;
	fflush(stdin);
	//Taking input from user assuming it's the sensors Data
	scanf("%c",&traffic);
	switch(traffic){
	case'a':
	case'A':
		display();
		break;
		//simulates Traffic data reading
	case'b':
	case'B':
		trafficData();
		break;
		//simulate temperature sensor reading
	case'c':
	case'C':ACtemp();
		break;
		//engine temperature reading
	case'd':
	case'D': EngineTemp();
		break;
	default:printf("chose from the menu\n");
	}
	/*************Additional condition if speed=30km\h***********************
	 * set AC ON
	 * set temp=current temp*1.25+1
	 * ETC ON
	 */
	if(speed==30){
			AC=true;
			Etc=1;
			roomtemp2=roomTemp*(1.25)+1;
			enginetemp=roomtemp2;
	}
	else{
		roomtemp2=roomTemp;
	}
}
//Traffic data inputs from sensors
void trafficData(){
	printf("Please enter Traffic Color:\n");
	fflush(stdout);
	char tcolor;
	fflush(stdin);
	scanf("%c",&tcolor);
	if(tcolor=='g'||tcolor=='G'){
		printf("speed=100\n");
		speed=100;
	}
 if(tcolor=='o'||tcolor=='O'){
			printf("speed=30\n");
			speed=30;
		}
	if(tcolor=='r'||tcolor=='R'){
			printf("speed=0\n");
			speed=0;
		}
	/************************recalling display Sensor set menu************************************
	 * =======to keep sensors menu displayed and waits for an answer======================
	 */
	onvech();
}
/************************************************************************************************************
 * inside temperature sensor reading
 * ======controlling in AC ON/OFF
 */
void ACtemp(){
	float temp;
	printf("please enter Temp\n");
	fflush(stdout);
	scanf("%f",&temp);
	if(temp<=10){
		AC=true;
		roomTemp=20;
		printf("AC oN, Temp=20\n");
	}
	else if(temp>=30){
		printf("AC,ON Temp=20\n");
		AC=true;
		roomTemp=20;
	}
	else{
		printf("turn AC OFF\n");
		AC=false;
		roomTemp=temp;

	}
/************************recalling display Sensor set menu************************************
* =======to keep sensors menu displayed and waits for an answer======================
*/
	onvech();
}
/* ======================engine temperature reading ===============================
 * *******************************************************************************
 * ***********************************************************************************
 * ======================CONTROLLING ETC=============================================
 */
void EngineTemp(){
	printf("enter Temp of engine\n");
	fflush(stdout);
	float temp;
	fflush(stdin);
	scanf("%f",&temp);
	if(temp<=100){
		printf("Turn “Engine Temperature Controller ON and set temperature to 125\n");
		Etc=1;
		enginetemp=125;
	}
	else	if(temp>=150){
		printf("Turn “Engine Temperature Controller ON and set temperature to 125\n");
Etc=1;
enginetemp=125;
	}
	else{
		printf("Turn Engine Temperature Controller OFF\n");
		Etc=0;
		enginetemp=temp;
	}
	/************************recalling display Sensor set menu************************************
		 * =======to keep sensors menu displayed and waits for an answer======================
		 */
	onvech();
}
/*
 * ================================FUNCTION TO PRINT SYSTEM STATUS=================================================
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 * *****************************************************************************************************************
 * ================================WHILE TURNNING ENGINE OFF OR QUIT THE SYSTEM====================================
 */

void sysstat(){
	printf("System status:\n");
	if(AC==0){
printf("Ac:OF\n");
	}
	else{
		printf("Ac:ON\n");
	}
	printf("vehicle speed: %d\n",speed);
	printf("room Temp=%0.1f\n",roomtemp2);
	if(Etc==0){
		printf("Etc: OF\n");
		}
		else{
			printf("Etc:ON\n");
		}
	printf("Engine Temp=%d\n",enginetemp);
}
