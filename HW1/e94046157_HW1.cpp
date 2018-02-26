#include <iostream>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int recursive(int);
	int	iterative(int);

int main(int argc, char** argv) {
	
	
	int n;
	printf("please enter a number biger then 0.enter'-1'to end program.\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		printf("Recursive: %d\n",recursive(n));
		printf("Iterative: %d\n",iterative(n));
		printf("please enter a number biger then 0.enter'-1'to end program.\n");
		scanf("%d",&n);
		
	}

	return 0;
	
	
	
}

int recursive(int a)
{

	if(a==1||a==0)
	{
		return 1;
	}
	else
	{
		return a*recursive(a-1);
	}
		
} 

int iterative(int a)
{
 	int ans=1;
	if(a==1||a==0)
	{
		return 1;
	}
	else
	{
		for(a;a>0;a--)
		{
		ans*=a;	
		}
	}
		
} 
	
