#include <iostream>
#include<stdio.h>
#define maxsize 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char queue[maxsize];

int isfull();
int isempty();
void Add();
void Delete();
int front=-1,rear=-1;

char num;


int main(void) 
{	
	printf("Insert(1)delete(2):");
	int mode;
	scanf("%d",&mode);
	while(mode==1||mode==2)
	{
		if(mode==1)
		{
			printf("Insert number:");
			scanf(" %c",&num);
			Add();
		}
		else if(mode==2)
		{
			Delete();
		}
		
		printf("Front=%d ,Rear=%d\nQueue:[%c][%c][%c][%c]\n\n",front,rear,queue[0],queue[1],queue[2],queue[3]);
		printf("Insert(1)delete(2):");scanf("%d",&mode);
	}
	while(mode!=1||mode!=2){printf("error,please enter 1 or 2 to insert or delete");break;}
	


	return 0;
}



int isfull()
{
	if(rear==(maxsize-1))	return 1;
	else return 0;
}

int isempty()
{
	if(rear==front) return 1;
	else return 0;
}

void Add()
{
	if(isfull()&&front==-1)	printf("queue is full\n");
	else if(isfull()&&front!=-1)
	{	int i=1,j=0;
		for(;(front+i)<maxsize;i++,j++)//¥­²¾ 
		{ 
		queue[j]=queue[front+i]; 
		queue[front+i]=0;
		}
		front=-1;rear=(i-1);
		queue[rear]=num;	
	}	
	else	queue[++rear]=num;	
}

void Delete()
{
	if(isempty())	printf("queue is empty\n");
	else	
	{	
		queue[++front]=0;	
		if(isempty())
		{front=-1;rear=-1;}
	}
}
