#include <stdio.h>
#include<iostream>

char c[20][20];
int i=0;
int totcol=0,totrow=0;
int entrancei,entrancej;

int stack1[100];int top1=-1;//�O�e������� 
int stack2[100];int top2=-1;//�O�e���ᨫ�L���� 
int movei[8]={0,1,1,1,0,-1,-1,-1};
int movej[8]={1,1,0,-1,-1,-1,0,1};
int nowi,nowj,endi,endj;
int deadroad(char[][20],int,int);
int fork(char [][20],int,int);
void print(void);
int step=1;

int main() {
	
	FILE *fPtr;
     		
    fPtr = fopen("in.txt", "r");
    if (fPtr)	{}
    else	printf("�ɮ׶}�ҥ���...\n");
//-------------------------------------------------------------------�Ĥ@���� 
   while(1)
	{
    	fscanf(fPtr,"%s", c[i]);
		i++;
  	if(feof(fPtr)) break;
	}
	
	while(1)//��@���Xcol 
	{
		if(c[2][totcol]) totcol++;
		else break;	
	}
	while(1)//��@���Xrow
	{
		if(c[totrow][1]) totrow++;
		else break;	
	}
	
	for(int i1=totrow;i1>=0;i1--)	{
	for(int i2=totcol;i2>=0;i2--)	{c[i1+1][i2+1]=c[i1][i2];}
	}
	
	for(int i1=totrow+1;i1>=0;i1--)	//��J�f �v�� 
	for(int i2=totcol+1;i2>=0;i2--)	
	{if(i1==0||i2==0||i2==totcol+1||i1==totrow+1){c[i1][i2]='1';}
	 if(c[i1][i2]=='s') {nowi=i1,nowj=i2;entrancei=i1;entrancej=i2;}
	 if(c[i1][i2]=='d') endi=i1,endj=i2;
	
	}
//-------------------------------------------------------------------�ĤG���� 

 
while(c[nowi][nowj]!='d')
{

if(deadroad(c,nowi,nowj))//�Y������ 
{	
		if(fork(c,nowi,nowj))//�Y���e��
		{	
			int u=0;
			while(u<8) 
			{
			
				if(c[nowi+movei[u]][nowj+movej[u]]=='0')
				{
				c[nowi][nowj]='*';nowi+=movei[u];nowj+=movej[u];
				top2++;	stack2[top2]=10*nowi+nowj;
				break;
				
				}
				else if(c[nowi+movei[u]][nowj+movej[u]]=='d')
				{
					c[nowi][nowj]='*';nowi+=movei[u];nowj+=movej[u]; 
					print();
					return 0;
				}
				u++;	
				
			
			}	
			
		}

		

		else //�Y����V�D
		{	int u=0;
			while(u<8) 
			{
			
			if(c[nowi+movei[u]][nowj+movej[u]]=='0')
			{
			c[nowi][nowj]='*';nowi+=movei[u];nowj+=movej[u];
			u++;
			}
			else if(c[nowi+movei[u]][nowj+movej[u]]=='d')
			{
				c[nowi][nowj]='*';nowi+=movei[u];nowj+=movej[u];
				print();			
				return 0;
			}
			break;
			}
			
			
		}
}
else//�Y������ 
{
		if(top1>=0)//�Ystack���� 
		{	
			nowi=(stack1[top1]/10);nowj=(stack1[top1]%10);
			
			while(stack2[top2]!=stack1[top1])
			{
			c[stack2[top2]/10][stack2[top2]%10]='8';
			stack2[top2]=0;top2--;
			}
			stack2[top2]=0;top2--;
			stack1[top1]=0;top1--;
		
			
		
		}
		else
		{	c[nowi][nowj]='*';
			printf("�S���X�f,�{�b��m:%d,%d\n",nowi,nowj);
			return 0;
			break;
		}
	
}		
} 

//printf("test now: %d,%d ",nowi,nowj);
}
//----------------------------------------------------------------------- 
int deadroad(char a[][20],int nowi,int nowj)
{
	for(int u=0;u<8;u++) {if ( a[nowi+movei[u]][nowj+movej[u]] =='0'|| a[nowi+movei[u]][nowj+movej[u]] =='d')return 1;}	
	return 0;
}


int fork(char a[][20],int nowi,int nowj)
{	int count;
	
	for(int u=0;u<8;u++) 
	{if( a[nowi+movei[u]][nowj+movej[u]] =='0') count++;}
	
	if(count>1)
	{
	top1++;	stack1[top1]=10*nowi+nowj;
	top2++;	stack2[top2]=10*nowi+nowj;
	return 1;
	}
	
	return 0;
	
	
	
}
void print(void)
{
	FILE *fPtr;     
	fPtr = fopen("out.txt", "w");
if (!fPtr) {
printf("\ncan not create file\n");
exit(1);
}
	c[entrancei][entrancej]='s';
	for(int i1=1;i1<=totrow;i1++)	
	{
	for(int i2=1;i2<=totcol;i2++)	
	{
	if(c[i1][i2]!='8') fprintf(fPtr,"%c",c[i1][i2]);
	else fprintf(fPtr,"%c",'0');
	
	if(c[i1][i2]=='*')step++;
	}
	fprintf(fPtr,"\n");
	}
	fprintf(fPtr,"\n%d steps\n",step);
	
	printf("out.txt file created");
	fclose(fPtr);
} 

