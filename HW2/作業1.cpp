#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void value(int n, int a, int b, int i, int j, int []);
FILE *fPtr;
void test();
int count;
int row[1000];
int col[1000];
int main(void)
{  
	char filename[30];
	printf("Please input the file name: ");
	scanf("%s",&filename);
    int n;
    fPtr = fopen(filename, "r");
    if (!fPtr) 
	{
        printf("�ɮ׶}�ҥ���\n");
        exit(1);
    }
   	
	   
    fscanf(fPtr,"%d",&n);

	static int size=n*n;
	int e[size];

	
	int a,b;
	printf("a: ");//Ū�Ja,b 
	scanf("%d",&a);
 	printf("b: ");
	scanf("%d",&b);
 	
 		
 	
	int i,j;
	//��(0,1)(0,2)(0,3)�̧�Ū�J�A�üg�Je�}�C���A���m�C 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
 		{
		 
			value(n,a,b,i,j,e);
		
		}	
	}
	
	int num;
	int total=n*n-count;
	for(num=0;num<total;num++)
	printf("e[%2d] = %d  d(%d,%d)\n",num,e[num],row[num],col[num]);


	
	
	fclose(fPtr);


	return 0;
    
    
} 

void value(int n, int a, int b, int i, int j,int k[])
{
	int index=0;

	
	if(i-j>=a||j-i>=b)
	{
	int garbage;	
	fscanf(fPtr,"%d",&garbage);
	count++;
	
	}
	else if(i==j||i>j)//�p��U�ӼƸ��\�Je�}�C���Ӧ�m
	{
		int sub=i-j;
		index=((n-sub-1)+(n-a+1))*(a-1-sub)/2   +j;
		fscanf(fPtr,"%d",&k[index]);
		row[index]=i;
		col[index]=j;
	}
	else if(i<j)//�p��U�ӼƸ��\�Je�}�C���Ӧ�m 
	{
		int sub=j-i;
		index=(n+(n-a+1))*a/2;
	
		index=index+((n-1)+(n-sub+1))*(sub-1)/2  +i;
		fscanf(fPtr,"%d",&k[index]);
		row[index]=i;
		col[index]=j;
	}	
	
	
}





