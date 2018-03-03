#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int judge(int,int,int**);
void randomwalk(int &,int &,int ,int ,int[],int[],int **);
int count=0;

int main() {
	int n,m,x,y;	
	printf("N: ");
	scanf("%d",&n);
	while(n>40||n<2)
	{
	printf("error,please enter the number between 2~40\n\nN: ");	
	scanf("%d",&n);
	}
	printf("M: ");
	scanf("%d",&m);
	while(m>40||m<2)
	{
	printf("error,please enter the number between 2~40\nM: ");	
	scanf("%d",&m);
	}
	
	
	printf("Initial bug position X: ");
	scanf("%d",&x);
	while(x>=n||x<0)
	{
	printf("error,x out of m*n range\n\nX: ");	
	scanf("%d",&x);
	}
	printf("Initial bug position Y: ");
	scanf("%d",&y);
	while(y>=m||y<0)
	{
	printf("error,y out of m*n range\n\nY: ");	
	scanf("%d",&y);
	}



	int** matrix = new int *[n];
	for (int i=0;i<n;i++)
	{matrix[i] = new int [m];}
	
	for(int k1=0;k1<n;k1++)
		for(int k2=0;k2<m;k2++)
		matrix[k1][k2]=0;
	int imove[8]={-1,0,1,1,1,0,-1,-1};	
	int jmove[8]={1,1,1,0,-1,-1,-1,0};

	srand((unsigned)time(NULL)); 



	while(judge(n,m,matrix)==1&&count<50000)
	{
	randomwalk(x,y,n,m,imove,jmove,matrix);	
	
	}
		if(count>=50000)
	{
		printf("expirment terminate,cockroach walk over 50000 step.\n");
	}
	
	/* 

	printf("%d\n",count);
	for(int k1=0;k1<n;k1++)
	{
	
		for(int k2=0;k2<m;k2++)
		{
		printf("%2d ",matrix[k1][k2]);
		}
		printf("\n");
	}
*/ 
	
FILE *fPtr;     
fPtr = fopen("Sample_Output.txt", "w");
    if (!fPtr) {
        printf("\ncan not create file\n");
        exit(1);
    }
    fprintf(fPtr,"Á`¦@%d¨B\n",count);
    for(int k1=0;k1<n;k1++)
	{
	
		for(int k2=0;k2<m;k2++)
		{
		fprintf(fPtr,"%2d ",matrix[k1][k2]);
		}
		fprintf(fPtr,"\n");
	} 
    
    fclose(fPtr);
     
    return 0;

 
}



int judge(int a,int b,int** array)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
		if(array[i][j]==0)
		return 1;
		}
	}
	return 0;
}


void randomwalk(int &x2,int &y2,int n2,int m2,int i[],int j[],int** array2)
{
	int e;
	e=rand()%8;

	int xtemp=x2+i[e],ytemp=y2+j[e];
	
	if(xtemp>=n2||xtemp<0||ytemp>=m2||ytemp<0)
	{}
	else
	{
		x2+=i[e];y2+=j[e];
		count++;array2[x2][y2]++;
	}
}
