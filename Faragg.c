#include<stdio.h>
#include<stdlib.h>
unsigned char speed;
unsigned char AC =0;
unsigned char ETC=0;
unsigned char temp;
int tempeng;
void display();
char switchfun(char x);
int trafficlightdata();
int roomtempdata();
void enginetemp();
int vspeed();
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	unsigned char finput;
	display();
	scanf(" %c",&finput);
	switchfun(finput);
	printf("Room Temperature %d \n",temp);
	printf("Engine Temperature %d \n",tempeng);
	printf("Speed %d \n",speed);
	if (AC==1){
		printf("AC ON \n");
	}
	else{
		printf("AC OFF \n");
	}
	if(ETC ==1){
		printf("ETC ON \n");
	}
	else{
		printf("ETC OFF \n");
	}
}
void display(){
	printf("What do you want? \n");
	printf("a. Turn on the vehicle engine \n");
	printf("b. Turn off the vehicle engine \n");
	printf("c. Quit the system \n");


}
void sensorsetmenuchoise( char selection){
	switch(selection){
	case 'a': main(1);
	break;
	case 'b': trafficlightdata();
	break;
	case 'c': roomtempdata();
	break;
	case 'd': enginetemp();
	break;
	case'e': return ;
	break;
	}
}
void sensorsetmenu(){
	printf("a. Turn off the vehicle engine \n");
	printf("b. Set the traffic light color \n");
	printf("c. Set the room temperature \n");
	printf("d. Set the engine temperature \n");
	printf("e.Diplay STATE \n");
	char x;
	scanf(" %c",&x);
	sensorsetmenuchoise(x);
}
char switchfun(char x){//2
	switch(x){
	case 'b':main();
	break;
	case 'a': sensorsetmenu();
	break;
	case 'c': return 0;
	break;
	}
	return 1;
}
int trafficlightdata(){
	unsigned char color;
	printf("enter the traffic light status \n");
	scanf(" %c",&color);
	switch (color){
	case 'G': printf("set vehicle speed to 100 km/hr \n");
	speed=100;
	break;
	case 'O':      printf("set vehicle speed to 30  km/hr \n ");
	speed=30;
	AC=1;
	ETC=1;
	break;
	case 'R':      printf("set vehicle speed to 0 km /h \n");
	speed=0;
	break;
	}
	sensorsetmenu(1);
	return speed;
}
int roomtempdata(){
	int x;
	printf("Enter Temperature");
	scanf(" %d",&x);
	if(10>=x){
		AC=1;
		printf("Turn ON AC \n");
		temp=20;
	}
	else if(30<x){
		AC=1;
		printf("Turn AC ON \n");
		temp=20;
	}
	else{
		AC=0;
		printf("Turn AC OFF");
	}
	sensorsetmenu(1);
	return temp;
}
void enginetemp(){
	printf("enter engine temperature \n");
	scanf("%d",&tempeng);
	if(100>tempeng || 125<tempeng){
		printf("ETC ON \n");
		tempeng=125;
	}
	else{
		printf("ETC OFF \n");
	}
	sensorsetmenu(1);
}
int vspeed(int x){
	if(AC==1 && ETC==1 ){
		x=x*(5/4)+1;
		printf("room temperature %d \n",x);
		printf("ETC ON ,ETC %d \n",x);
	}
	else{
		AC=1;
		ETC=1;
	}
	return x;
}
