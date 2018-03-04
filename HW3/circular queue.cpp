#include <iostream>
#include<stdio.h>
#define maxsize 4

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char queue[maxsize];

int isfull();
int isempty();
void Add();
void Delete();
int front=0,rear=0;

char num;


int main(void) 
{	
	printf("Insert(1)delete(2):");
	int mode;
	scanf("%d",&mode);
	while(mode!=-1)
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


	return 0;
}



int isfull()
{
	if((rear+1==front)||(front==0&&rear==maxsize-1))	return 1;
	else return 0;
}

int isempty()
{
	if(rear==front) return 1;
	else return 0;
}

void Add()
{
	if(isfull())	printf("queue is full\n");
	else
	{
		rear=(rear+1)%maxsize;
		queue[rear]=num;		
	}
}

void Delete()
{
	if(isempty())	printf("queue is empty\n");
	else	
	{	
		front=(front+1)%maxsize;
		queue[front]=' ';	
	}
}
