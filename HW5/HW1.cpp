#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>


int a[1000],count=1;//count�����@���X�ӼƦr(node) count=1��]���s���O�q1�}�l�Aa[0]��-1 
void create(void);//�@�}�l�إ�maxheap 
void change(int,int);//�洫priority�ɪ��ʧ@ 
void print();



int main(void)
{
	double diff_time;
	for(int j=0;j<1000;j++)a[j]=-1;	//��array��ȳ]��-1,-1��ܸ̭��S��Ʀr �����s�b��node 
	
	//------------------------------------------------------Ū�J��� 
    FILE *fPtr;
    int i; 
    
    fPtr = fopen("in.txt", "r");
    if (!fPtr) {
        printf("�ɮ׶}�ҥ���...\n");
        exit(1);
    }
     
    while(1)
	{
    	fscanf(fPtr,"%d,",&a[count++]);
		
  	if(feof(fPtr)) break;
	}
    fclose(fPtr);
    
    count--;//�e���O++,�̫�h�[�@�� 
    
    //------------------------------------------------------��z�̪쪺max heap 
    
	create();
	printf("Create Max Heap\n");
	print();    
	//---------------------------------------------------------

	while(1){
	
	char a1; int b,c;
    printf("Change priority?(Y/N) : ");scanf(" %c",&a1); 
     
	if(a1=='Y')
    {
    
    printf("Choice priority : ");scanf("%d",&b);
    printf("Change priority to : ");scanf("%d",&c);
    	

    
    LARGE_INTEGER t1, t2, ts;
    QueryPerformanceFrequency(&ts);
    QueryPerformanceCounter(&t1);
    
	change(b,c);
	
	QueryPerformanceCounter(&t2);
	print();
    printf("Spend time: %lf sec\n",(t2.QuadPart-t1.QuadPart)/(double)(ts.QuadPart));

    
	
	}
    else if(a1=='N')return 0;
	
	}
	
    //------------------------------------------------------------
}


void create(void)
{
	int m=1,temp;
	while(a[m]!=-1)
	{	
		if(m==1) m++;//root node ���ξ�z
		else 
		{	int index=m;
			int biggest=a[index/2];//���parents�M�ۤv�֤j�H�մ���m 
			while(a[index]>a[index/2])//�Y��m����(parents��ۤv�p) 
			{
			biggest=a[index];
			temp=a[index/2];a[index/2]=biggest;a[index]=temp;//���� 
			index/=2;//��s�ۤv����mindex 
			if(index==1)break;//�w�g�Oroot,���Xwhile 
			}
			m++; 
		}

	}
}

void change(int ini,int now)
{   
	printf("\n");
	int index=1,biggest,temp; 
	
	while(a[index]!=-1){if(a[index]==ini){a[index++]=now;break;} index++;}index--;//���index�Χ�Ʀr�N���� 
	
	while(a[index]>a[index/2]&&a[index/2]!=-1)//�Yparents��ۤv�p�B���Oroot 
	{	
		biggest=a[index];
		temp=a[index/2];a[index/2]=biggest;a[index]=temp;//���� 
		index/=2;//��s�ۤv����mindex 
		if(index==1)break;//�w�g�Oroot,���Xwhile 
	}
	
	while(a[index*2]>a[index]||a[index*2+1]>a[index])//�Yleft child�άOright child ��ۤv�j
	{	
		if(a[index*2]>a[index*2+1]){biggest=a[index*2];index*=2;}
		else if(a[index*2+1]>a[index*2]){biggest=a[index*2+1];index=index*2+1;}//��left child �Mright child�֤j�P�ɧ�s�մ���index�b�� 
		 
		temp=a[index/2];a[index/2]=biggest;a[index]=temp;//�P�̤j������ 
		if(index*2>count)break;//�p�G�w�g�Oleaf node(left child�s��>�{�����̤j�s��),���Xwhile 
	} 
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

