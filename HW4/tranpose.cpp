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
MatrixPointer HdNode[MAX_SIZE];
MatrixPointer mread(void);
void mwrite(MatrixPointer);
void tranpose(MatrixPointer);
void mwritetrue(MatrixPointer);
int NumRows, NumCols;

int main()
{
    MatrixPointer a,b,c;
    a = mread();
    //printf("before:\n\n");
    //mwrite(a);
    tranpose(a);
    //printf("after:\n\n");
    //mwrite(a);
    
	mwritetrue(a);
}

MatrixPointer mread(void)
{
  int  NumEntries, NumHeads, i;
  int row, col, value, CurrentRow;
  MatrixPointer temp,last,node;

							 // printf("Enter the number of rows, columns and entries: ");
  scanf("%d",&NumRows);
  scanf("%d",&NumCols);
  NumEntries=NumRows*NumCols; 
  
  
  NumHeads = (NumCols > NumRows) ? NumCols : NumRows;
  
  node = (MatrixPointer)malloc(sizeof(struct MatrixNode));
  node->tag = entry;
  node->u.entry.row = NumRows;
  node->u.entry.col = NumCols;

  if (!NumHeads)
     node->right = node;
  else {
     
     for (i = 0; i < NumHeads; i++) {
       temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
       HdNode[i] = temp;
       HdNode[i]->tag = head;
       HdNode[i]->right = temp;
       HdNode[i]->u.next = temp;
     }
  
  
     CurrentRow = 0;
     last = HdNode[0];
    

    row=0;col=0;
	for (i = 0; i < NumEntries; i++) 
{
     
   //									 printf("Enter row, column and value: ");
    scanf("%d",&value);
	
    if(value==0){col++;if(col==NumCols){row++;col=0;}}
	
else{
		//	printf("row:%d,col:%d\n",row,col);
	
     if (row > CurrentRow) {
	 	last->right = HdNode[CurrentRow]; 
	 	CurrentRow = row;
	 	last = HdNode[row];
     }
       temp = (MatrixPointer)malloc(sizeof(struct MatrixNode));
       temp->tag = entry;
       temp->u.entry.row = row;
       temp->u.entry.col = col;
       temp->u.entry.value = value;
       last->right = temp;         
       last = temp;
       HdNode[col]->u.next->down = temp;  
       HdNode[col]->u.next = temp;
       
       col++;if(col==NumCols){row++;col=0;}
    }
}
     
     last->right = HdNode[CurrentRow];
     
     for (i = 0; i < NumCols; i++)
	    HdNode[i]->u.next->down = HdNode[i];
     
     for (i = 0; i < NumHeads-1; i++)
	    HdNode[i]->u.next = HdNode[i+1];
     HdNode[NumHeads-1]->u.next =  node;
     node->right = HdNode[0];
    }
    return node;

}
void tranpose(MatrixPointer node)
{	MatrixPointer temp,temp2;
	int i,temp3;
	for (i = 0; i < node->u.entry.row; i++)
//	for (temp = HdNode[i];; temp = temp->right)
	for (temp = HdNode[i]->right; temp != HdNode[i]; temp = temp->right)
	{
		temp3=temp->u.entry.row;
		temp->u.entry.row=temp->u.entry.col;
		temp->u.entry.col=temp3;
	//	printf("%5d%5d%5d\n",temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
	}
	
	
		int bigger=(node->u.entry.col > node->u.entry.row) ? node->u.entry.col : node->u.entry.row;
		for (i = 0; i < bigger; i++)
		for (temp = HdNode[i];; temp = temp->down){
		temp2=temp->right;
		temp->right=temp->down;
		temp->down=temp2;
	//	printf("%5d%5d%5d\n",temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
		if(temp2 == HdNode[i])break;
		}
		int temp4;
		
		temp4=node->u.entry.col;node->u.entry.col=node->u.entry.row;node->u.entry.row=temp4;
	//printf("%d\n",HdNode[1]->right->u.entry.value);
	
	//printf("%d,%d\n",node->u.entry.col,node->u.entry.row);
	
	/*	for (i = 0; i < node->u.entry.row; i++){	
		for (temp = HdNode[i]->right; temp != HdNode[i]; temp = temp->right)	printf("%5d%5d%5d\n",temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
		printf("\n");
		}*/ 
		
	
} 		
void mwrite(MatrixPointer node)
{

  int i;
  MatrixPointer temp;
  
  printf("\n\nNumRows = %d, NumCols = %d\n",node->u.entry.row,node->u.entry.col);
  printf(" The matrix by row, column, and value: \n\n");
  
  for (i = 0; i < node->u.entry.row; i++)
  
     for (temp = HdNode[i]->right; temp != HdNode[i]; temp = temp->right)
      	printf("%5d%5d%5d\n",temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
}

void mwritetrue(MatrixPointer node)
{

  int i,j,i2=0;
  MatrixPointer temp; //= HdNode[i2]->right;
  for(i=0;i<NumCols;i++)
{  temp= HdNode[i2++]->right;
  for(j=0;j<NumRows;j++)
  {
  		if(temp->u.entry.col==j&&temp->u.entry.row==i)
		{
		printf("%3d ",temp->u.entry.value);temp = temp->right;
    	}
		else{printf("%3d ",0);}
   	
  } printf("\n");
}
}


