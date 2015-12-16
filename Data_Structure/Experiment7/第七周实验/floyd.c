#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define Inf 1000000

//我们使用floyd算法来实现求最短路
int main(){
	int n, v, w, u, i;
	int *D, *P;
	printf("Vexmun:\n");
	scanf("%d",&n);
	D = (int *)malloc(n * n * sizeof(int));
	P = (int *)malloc(n * n * n * sizeof(int));
	for(v = 0; v < n; v++)
		for(w = 0; w < n; w++){
			scanf("%d",D + n * v + w);
			if(*(D+n*v+w) == -1) *(D+n*v+w) = Inf; //不存在的路径用－1输入
			for(u = 0; u < n; u++) *(P + v * n * n + w * n + u) = 0;
			if(*(D+v*n+w) < Inf){
				*(P + v * n * n + w * n + v) = 1;
				*(P + v * n * n + w * n + w) = 1;
			}  
		}  //floyd算法初始化
	for(u = 0; u < n; u++)
		for(v = 0; v < n; v++)
			for(w = 0; w < n; w++)
				if(*(D+v*n+u) + *(D+u*n+w) < *(D+v*n+w)){
					*(D+v*n+w) = *(D+v*n+u) + *(D+u*n+w);
					for(i = 0; i < n; i++)
						*(P+n*n*v+w*n+i) = *(P+n*n*v+u*n+i) || *(P+n*n*u+w*n+i);
				}//floyd算法主循环
	printf("Distance between vex:\n");
	for(v = 0; v < n; v++){
		for(w = 0; w < n; w++)
			printf("%d ",*(D + n * v + w));
		printf("\n");	
	}//输出
	return 0;
}