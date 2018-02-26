#include <iostream>
#include<string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	void com(int n, int r, int r2,char []);//單做組合的函式(輸入C n取r) 
	void powerset(char[],int size );
	int way[1000]={0};
	int n,m,g=0;

int main(int argc, char** argv) {

	int i;
	char e[100];//儲存元素
	 
	printf("輸入元素(不須空格):");
	scanf("%s",&e[i]);
	int num=strlen(e); //計算元素個數 (用strlen故上方input不可有空格) 
		
	powerset(e, num);
	
	return 0;
}

void com(int n,int r,int r2,char t[]) 
{
    for (int i=n;i>=r;i--)
	{
        way[r-1]=i;//取數字 
        if(r>1)//若還需要取(ex:c 5取3 取完一個還需要C 4取2、而後C3取1) 
		{
            
            com(i-1,r-1,r2,t);// recursive
        }
		else//若不須取則跑進else 印出一種組合 
		{
            
            printf("{");
            for (int i=0; i<r2; i++)
		    printf(" %c",t[way[i]-1]);
            
            printf(" }\n");
            g++;
        }
    }
}





	void powerset(char s[], int size)
	{	
	if(size!=0)
	{
		for(int count=size;count>0;count--)	//ex:輸入abcd則須考慮取4 取3 取2 取1 的組合 
		{
		
		com(size,count,count,s);				//印出所有組合的函數 

		} 
		
		printf("{ }");//空集合在上面沒印到 要加上去 
		
		printf("\nPowerset裡總共有%d個集合",g+1);
	}	 

	}
