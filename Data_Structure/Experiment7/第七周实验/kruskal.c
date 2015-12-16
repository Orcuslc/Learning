#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXNUM 100

typedef struct Node{
	int num;
	struct Node *parent;
	struct Node *sons[MAXNUM];
}Node;

typedef struct MFSet{
	int length;
	Node class[MAXNUM];
}MFSet;

void arrayexchange(int array[][3], int i, int j){
	int a1,a2,a3;
	a1 = array[i][0], a2 = array[i][1], a3 = array[i][2];
	array[i][0] = array[j][0];
	array[i][1] = array[j][1];
	array[i][2] = array[j][2];
	array[j][0] = a1;
	array[j][1] = a2;
	array[j][2] = a3;
}

int Partition(int array[][3], int p, int r){
	int x, i, j, k;
    x = array[r][2];
    i = p - 1;
    for(j = p; j < r; j++){
        if(array[j][2] <= x){
            i++;
            arrayexchange(array,i,j);
   		}
   	}
    arrayexchange(array,i+1,r);
    return i+1;
}

void PartlyQuicksort(int array[][3], int p, int r){
    int q;
    if(p < r){
        q = Partition(array, p, r);
        PartlyQuicksort(array, p, q - 1);
        PartlyQuicksort(array, q + 1, r);
	}
}

void Sort(int array[][3], int n){
    PartlyQuicksort(array,0,n-1);
}

int Find_MFSet(MFSet A, int i){
	int j;
	for(j = i; A.class[j].parent; j = A.class[j].parent->num);
	return j;
}

void Merge_MFSet(MFSet *A, int i, int j){
	//(*A).class[i].parent = (A->class + j);
	((A->class) + i)->parent = (A->class + j);
	A->length--;
	//printf("%d\n",A.class[i].parent->num);
}

int Modify(MFSet *A, int Edge[][3], int i){
	int a1, a2;
	a1 = Find_MFSet(*A, Edge[i][0]);
	a2 = Find_MFSet(*A, Edge[i][1]);
	//printf("%d %d\n",a1,a2);
	if(a1 == a2) return 0;
	else {
		Merge_MFSet(A, a1, a2);
		return 1;
	}
}

int main(){
	int n, i, j, len, sum = 0;
	int Edge[MAXNUM][3];
	Node *p, *q;
	MFSet A;
	printf("EdgeNum:\n");
	scanf("%d",&n);
	A.length = n;
	for(i = 0; i < MAXNUM; i++){
		p = (Node *)malloc(sizeof(Node));
		p->num = i;
		A.class[i] = *p;
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < 3; j++)
			scanf("%d",&Edge[i][j]);
	Sort(Edge, n);
	for(i = 0; i < n; i++)
		if(Modify(&A, Edge, i)) 
			sum += Edge[i][2];
	printf("\n");
	printf("Sum:\n");
	printf("%d\n",sum);
	return 0;
}