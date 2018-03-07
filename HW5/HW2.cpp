#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


int a[1000],count=1;//count紀錄共有幾個數字(node) count=1原因為編號是從1開始，a[0]為-1 
void create(void);
void change(int,int);//複製HW1的change函式 
void delete_element(int);
void print();


int main(void)
{
	double diff_time;
	for(int j=0;j<1000;j++)a[j]=-1;	//把array初值設為-1,-1表示裡面沒填數字 為不存在的node 
	
	//------------------------------------------------------讀入資料 
    FILE *fPtr;
    int i; 
    
    fPtr = fopen("in.txt", "r");
    if (!fPtr) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
     
    while(1)
	{
    	fscanf(fPtr,"%d,",&a[count++]);
		
  	if(feof(fPtr)) break;
	}
    fclose(fPtr);
    
    count--;//前面是++,最後多加一次 
    

    
    //------------------------------------------------------整理最初的max heap 
    
	create();
	printf("Create Max Heap\n");
	print();    
    
	//---------------------------------------------------------
	while(1){
	
	char a1; int b,c;
    printf("Delete element?(Y/N) : ");scanf(" %c",&a1); 
     
	if(a1=='Y')
    {
    
    printf("Choice element : ");scanf("%d",&b);
    
    
    LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);
    
	delete_element(b);
	
	QueryPerformanceCounter(&t2);
	print(); 
    printf("Spend time: %lf sec\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));

    
	
	}
    else if(a1=='N')return 0;
	
	}
	
    //------------------------------------------------------------// 
	
	
}

void create(void)
{
	int m=1,temp;
	while(a[m]!=-1)
	{	
		if(m==1) m++;//root node 不用整理
		else 
		{	int index=m;
			int biggest=a[index/2];//比較parents和自己誰大以調換位置 
			while(a[index]>a[index/2])//若位置不對(parents比自己小) 
			{
			biggest=a[index];
			temp=a[index/2];a[index/2]=biggest;a[index]=temp;//互換 
			index/=2;//更新自己的位置index 
			if(index==1)break;//已經是root,跳出while 
			}
			m++; 
		}
	/*	int i=0;
		while(a[i]!=-1)printf("%d ",a[i++]);printf("\n\n");*/ 
	}
}

void change(int ini,int now)
{   
	printf("\n");
	int index=1,biggest,temp; 
	while(a[index]!=-1){if(a[index]==ini){a[index++]=now;break;} index++;}index--;//找到index及把數字代換掉 
	
	
	while(a[index]>a[index/2]&&a[index/2]!=-1)//若parents比自己小且不是root 
	{	
		biggest=a[index];
		temp=a[index/2];a[index/2]=biggest;a[index]=temp;//互換 
		index/=2;//更新自己的位置index 
		if(index==1)break;//已經是root,跳出while 
	}
	
	while(a[index*2]>a[index]||a[index*2+1]>a[index])//若left child或是right child 比自己大
	{	
		if(a[index*2]>a[index*2+1]){biggest=a[index*2];index*=2;}
		else if(a[index*2+1]>a[index*2]){biggest=a[index*2+1];index=index*2+1;}//比left child 和right child誰大同時更新調換後index在哪 
		 
		temp=a[index/2];a[index/2]=biggest;a[index]=temp;//與最大的互換 
		if(index*2>count)break;//如果已經是leaf node(left child編號>現有的最大編號),跳出while 
	} 
	
}


void delete_element(int del)
{
	int temp=a[count];a[count--]=-1;//把最後一個數字存進temp 並把最後一個node刪除，而後更新數量(count) 
	change(del,temp);//做刪除的動作等於把要刪除的數字改成暫存的數字再整理成max heap 
	
}

void print()
{	
	printf("Max Heap:\n");
	int u=1,judge=1;
    while(a[u]!=-1)
	{
    printf("%d ",a[u]);if(u==judge||a[u+1]==-1){printf("\n");judge=judge*2+1;}u++;
	}
} 
