#include<stdio.h>
int total;
int findee(int [],int **,int);
int findle(int [],int **,int);
int main()

{	
	int i,j;
	
	FILE *fPtr; 		
    fPtr = fopen("Sample_input.txt","r");
    if (fPtr)	{}
    else	printf("檔案開啟失敗...\n");
    
	fscanf(fPtr,"%d",&total);
	
	int** c = new int *[total];
	for (int i=0;i<total;i++)
	{c[i] = new int [total];} 
   	
	for(i=0;i<total;i++)for(j=0;j<total;j++)fscanf(fPtr,"%d",&c[i][j]);
	
	//printf("%d\n",total);	
	int count=1;
	for(i=0;i<total;i++)for(j=0;j<total;j++)if(c[i][j]!=0){count++;}count--;
	
	//for(i=0;i<total;i++){for(j=0;j<total;j++)printf("%d ",c[i][j]);printf("\n");}
	//------------------------------------讀入資料---------------------------------------
	 	
	int ee[total]={0};
	for(i=1;i<total;i++)ee[i]=findee(ee,c,i);
	
	int le[total];for(i=1;i<total;i++)le[i]=30000;
	le[total-1]=ee[total-1];
	for(i=total-2;i>=0;i--)le[i]=findle(le,c,i);
	
//	for(i=0;i<total;i++)printf("%d ",ee[i]);printf("\n");
//	for(i=total-1;i>=0;i--)printf("%d ",le[i]);printf("\n");
	
	//------------------------------------找ee le---------------------------------------
	int e[count],l[count],slack[count],x[count],y[count];
	int a=0;
	for(i=0;i<total;i++)for(j=0;j<total;j++)if(c[i][j]!=0){x[a]=i;y[a]=j;e[a]=ee[i];l[a]=le[j]-c[i][j];slack[a]=l[a]-e[a];a++;}
	
	printf("%s%15s%15s%15s\n","activity","early time","late time","slack");
	for(i=0;i<count;i++)printf("a%2d (%d,%d) %12d%16d%15d\n",i+1,x[i],y[i],e[i],l[i],slack[i]);
}

int findee(int ee[],int** c,int now)
{	
	int big=ee[now];
	
	for(int a=0;a<total;a++)if(c[a][now]+ee[a]>ee[now]&&c[a][now]!=0)ee[now]=c[a][now]+ee[a];
	
	return ee[now];
	
}

int findle(int le[],int** c,int now)
{
	int min=le[now];
	for(int a=total-1;a>0;a--)if(le[a]-c[now][a]<le[now]&&c[now][a]!=0)le[now]=le[a]-c[now][a];
	return le[now];
}
