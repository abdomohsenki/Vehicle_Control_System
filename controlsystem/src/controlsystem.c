/*
 ============================================================================
 Name        : controlsystem.c
 Author      : Abdelrahman_Mohsen
 Version     :
 Copyright   : Your copyright notice
 Description : C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
enum ac{
	OFF,ON
};
enum ac Ac=OFF;
enum ac Ec=OFF;


void traffic_light(int **ps){
	char c;
	scanf(" %c",&c);

	if(c=='G'||c=='g'){
		**ps=100;
	}
	else if(c=='O'||c=='o'){
		**ps=30;
	}
	else if(c=='R'||c=='r'){
		**ps=0;
	}

}



void room_temp(int **y){
	int r=0;
	scanf("%d",&r);
	**y=r;

	if(**y<10){
		Ac=ON;
		**y=20;
	}
	else if(**y>30){
		Ac=ON;
		**y=20;
	}
	else {
		Ac=OFF;
	}


}

void engine_temop(int **e){
	int r=0;
	scanf("%d",&r);
	**e=r;

	if(**e<100){
		Ec=ON;
		**e=125;
	}
	else if(**e>150){
		Ec=ON;
		**e=125;
	}
	else{
		Ec=OFF;
	}

}

//void check(int***s,int ***t,int ***e){
//	if(***s==30){
//			if(Ac==OFF){
//				Ac=ON;
//				***t=(***t )* ((float)(5/4)) +1;
//			}
//			if(Ec==OFF){
//				Ec=ON;
//				***e=(***e )* ((float)(5/4))+1;
//			  }
//		}
//}




void display(int**s,int **rt,int**en){
	if(**s==30){
		if(Ac==OFF){
			Ac=ON;
			**rt=(**rt )* ((float)5/4) +1;
		}
		if(Ec==OFF){
			Ec=ON;
			**en=(**en )* ((float)5/4)+1;
		}
	}
	printf("Engine is ON\n");
	if(Ac==1){
		printf("AC is ON\n");

	}
	else{
		printf("AC is oFF\n");

	}

	printf("Vehicle Speed: %d KM/Hr \n",**s);
	printf("Room temperature:%d c\n",**rt);
	if(Ec==1){
		printf("Engine Temperature Controller is ON\n");

	}
	else{
		printf("Engine Temperature Controller is oFF\n");

	}
	printf("Engine temperature:%d c\n\n",**en);



}


void turn_on(int *speed,int *Rtemp,int*etemp,char *x){


	if(*x=='b'||*x=='B'){
		printf("Enter the traffic light color\n\n");
		traffic_light(&speed);
		display(&speed,&Rtemp,&etemp);
	}
	else if(*x=='c'||*x=='C'){
		printf("Enter the room temperature (Temperature Sensor)\n\n");
		room_temp(&Rtemp);
		display(&speed,&Rtemp,&etemp);
	}

	else if(*x=='d'||*x=='D'){
		printf("Enter the engine temperature (Engine Temperature Sensor)\n\n");
		engine_temop(&etemp);
		display(&speed,&Rtemp,&etemp);
	}
}


int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	while(1){
		char in;
		int speed=90;
		int Rtemp=25;
		int etemp=125;
		printf("a. Turn on the vehicle engine\n");

		printf("b. Turn off the vehicle engine\n");

		printf("c. Quit the system\n\n");

		scanf(" %c",&in);

		if(in=='a'||in=='A'){

			printf(" Turn on the vehicle engine\n\n");

			while(1){

				printf("a.  Turn off the engine\n");
				printf("b.Set the traffic light color\n");
				printf("c.Set the room temperature (Temperature Sensor)\n");
				printf("d.Set the engine temperature (Engine Temperature Sensor)\n");

				char inz;

				scanf(" %c",&inz);

				if(inz=='a'||inz=='A'){

					printf("the engine Turned off \n\n");

					Ac=OFF;
					Ec=OFF;
					break;
				}
				else{

					turn_on(&speed,&Rtemp,&etemp,&inz);
				}
			}
		}
		else if(in=='b'||in=='B'){

			printf(" the engine Turned off\n\n");

			Ac=OFF;
			Ec=OFF;


		}
		else if(in=='c'||in=='C'){
			printf("Quit the system\n\n");
			exit(0);
		}



	}
}

