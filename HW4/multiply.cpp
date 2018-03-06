#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  50
typedef enum {head,entry} tagfield;
typedef struct MatrixNode *MatrixPointer;
	struct EntryNode {
			 int row;
			 int col;
			 int value;
	};
	struct MatrixNode {
			  MatrixPointer down;
			  MatrixPointer right;
			  tagfield tag;
			  union {
				MatrixPointer next;
				struct EntryNode entry;
			  } u;	
			  
	};
MatrixPointer HdNode[3][MAX_SIZE];
MatrixPointer mread(int i);
void mwrite(MatrixPointer,int);
void mmult();
int NumRows[3],NumCols[3];


int main()
{
    MatrixPointer a,b,c;
    a = mread(0);
    b = mread(1);
    if(NumCols[0]!=NumRows[1]){printf("\ncannot multiply");return 0;}
  //  mwrite(a,0);
  //  mwrite(b,1);
    printf("\n");
    mmult();
}

MatrixPointer mread(int a)
{
  int  NumEntries, NumHeads, i;
  int row, col, value, CurrentRow;
  MatrixPointer temp,last,node;

// printf("Enter the number of rows, columns and entries: ");
  scanf("%d",&NumRows[a]);
  scanf("%d",&NumCols[a]);
  NumEntries=NumRows[a]*NumCols[a]; 
  
  
  NumHeads = (NumCols[a] > NumRows[a]) ? NumCols[a] : NumRows[a];
  
  node = (MatrixPointer)malloc(sizeof(struct MatrixNode));
  node->tag = entry;
  node->u.entry.row = NumRows[a];
  node->u.entry.col = NumCols[a];

  if (!NumHeads)
     node->right = node;
  else {
     
     for (i = 0; i < NumHeads; i++) {
       temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
       HdNode[a][i] = temp;
       HdNode[a][i]->tag = head;
       HdNode[a][i]->right = temp;
       HdNode[a][i]->u.next = temp;
     }
  
  
     CurrentRow = 0;
     last = HdNode[a][0];
    

    row=0;col=0;
	for (i = 0; i < NumEntries; i++) 
{
     
   //									 printf("Enter row, column and value: ");
    scanf("%d",&value);
	
    if(value==0){col++;if(col==NumCols[a]){row++;col=0;}}
	
else{
		//	printf("row:%d,col:%d\n",row,col);
	
     if (row > CurrentRow) {
	 	last->right = HdNode[a][CurrentRow]; 
	 	CurrentRow = row;
	 	last = HdNode[a][row];
     }
       temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
       temp->tag = entry;
       temp->u.entry.row = row;
       temp->u.entry.col = col;
       temp->u.entry.value = value;
       last->right = temp;          
       last = temp;
       HdNode[a][col]->u.next->down = temp; 
       HdNode[a][col]->u.next = temp;
       
       col++;if(col==NumCols[a]){row++;col=0;}
    }
}
    
     last->right = HdNode[a][CurrentRow];
    
     for (i = 0; i < NumCols[a]; i++)
	    HdNode[a][i]->u.next->down = HdNode[a][i];
     
     for (i = 0; i < NumHeads-1; i++)
	    HdNode[a][i]->u.next = HdNode[a][i+1];
     HdNode[a][NumHeads-1]->u.next =  node;
     node->right = HdNode[a][0];
    }
    return node;

}

void mwrite(MatrixPointer node,int b)
{

  int i,temp2;
  MatrixPointer temp;
  
  printf("\n\nNumRows = %d, NumCols = %d\n",node->u.entry.row,
	  node->u.entry.col);
  printf(" The matrix by row, column, and value: \n\n");
  for (i = 0; i < node->u.entry.row; i++)
  
     for (temp = HdNode[b][i]->right; temp != HdNode[b][i]; temp = temp->right)
       	printf("%5d%5d%5d\n",temp->u.entry.row,temp->u.entry.col,
	      temp->u.entry.value);
}


void mmult()
{
	MatrixPointer m1,m2;
	
	NumRows[2]=NumRows[0];NumCols[2]=NumCols[1];
	int m,n,x,result=0;
        for(m=0;m<NumRows[2];m++){
		
		for(x=0;x<NumCols[2];x++)
        {	m1=HdNode[0][m]->right;m2=HdNode[1][x]->down;
        	for(n=0;n<NumCols[0];n++)
			{
			if(m1->u.entry.col > m2->u.entry.row){m2= m2->down;if(m2==HdNode[0][n])break;}
			else if(m1->u.entry.col == m2->u.entry.row)
			{
			result+=m1->u.entry.value*m2->u.entry.value;
			m1= m1->right;if(m1==HdNode[0][n])break;
			m2= m2->down;if(m2==HdNode[0][n])break;
			}					//Result[m][x]+=m1[m][n]*b[x][n];Hdnode[2][x]
			else {m1= m1->right;if(m1==HdNode[0][n])break;}
			
			}
			printf("%4d ",result);
        	result=0;
        }
        printf("\n");}

}
