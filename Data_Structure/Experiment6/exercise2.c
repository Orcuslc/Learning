#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 100

int NoBracket(char *glist){
	if(*glist == '(') return 0;
	else return 1;
}

void Extract(char *glist, char op){
	int i, j;
	if(*(glist + 1) == '('){
		int stack = 1;
		for(i = 2; ; i++){
			if(*(glist + i) == '(') stack++;
			if(*(glist + i) == ')') stack--; 
			if(stack == 0) break;
		}
	}
	else{
		for(i = 0; *(glist + i) != ',' && *(glist + i) != ')'; i++);
		i--;
	}
	if(op == 'H'){
		for(j = 0; j < i; j++)
			*(glist + j) = *(glist + j + 1);
		*(glist + i) = '\0';
	}
	else{
		int l = strlen(glist);
		i = i + 2;
		*glist = '(';
		for(j = 1; i <= l; ){
			*(glist + j) = *(glist + i);
			i++;
			j++;
		}
	}
}

char *GlistOp(char *glist, char *op){
	if(NoBracket(glist)){
		return glist;
	}
	else{
		Extract(glist, *op);
		int i;
		for(i = 0; *(op + i); i++){
			*(op + i) = *(op + i + 1);
		}
		return GlistOp(glist, op);
	}
}


int main(){
	char glist[MAX], copy[MAX], *op;
	int n;
	printf("Sample1:\n");
	printf("Input:\n");
	scanf("%s",glist);
	scanf("%d",&n);
	op = (char *)malloc(n * sizeof(char));
	scanf("%s",op);
	strcpy(copy, glist);
	printf("\nOutput:\n%s",GlistOp(copy, op));
	printf("\n");
	printf("Sample2:\n");
	printf("Input:\n");
	scanf("%s",glist);
	scanf("%d",&n);
	op = (char *)malloc(n * sizeof(char));
	scanf("%s",op);
	strcpy(copy, glist);
	printf("\nOutput:\n%s",GlistOp(copy, op));
	printf("\n");
	return 0;
}