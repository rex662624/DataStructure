#include <iostream>
#include<string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	void com(int n, int r, int r2,char []);//�氵�զX���禡(��JC n��r) 
	void powerset(char[],int size );
	int way[1000]={0};
	int n,m,g=0;

int main(int argc, char** argv) {

	int i;
	char e[100];//�x�s����
	 
	printf("��J����(�����Ů�):");
	scanf("%s",&e[i]);
	int num=strlen(e); //�p�⤸���Ӽ� (��strlen�G�W��input���i���Ů�) 
		
	powerset(e, num);
	
	return 0;
}

void com(int n,int r,int r2,char t[]) 
{
    for (int i=n;i>=r;i--)
	{
        way[r-1]=i;//���Ʀr 
        if(r>1)//�Y�ٻݭn��(ex:c 5��3 �����@���ٻݭnC 4��2�B�ӫ�C3��1) 
		{
            
            com(i-1,r-1,r2,t);// recursive
        }
		else//�Y�������h�]�ielse �L�X�@�زզX 
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
		for(int count=size;count>0;count--)	//ex:��Jabcd�h���Ҽ{��4 ��3 ��2 ��1 ���զX 
		{
		
		com(size,count,count,s);				//�L�X�Ҧ��զX����� 

		} 
		
		printf("{ }");//�Ŷ��X�b�W���S�L�� �n�[�W�h 
		
		printf("\nPowerset���`�@��%d�Ӷ��X",g+1);
	}	 

	}
