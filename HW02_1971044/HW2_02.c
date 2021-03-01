#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void matrixPrint(double*** A,int a,int b,int c){
	int i,j,k,count=0;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			for(k=0;k<c;k++){
				printf("%lf ",*(*(*(A+i)+j)+k));
				count++;
				if(count%a==0)
					printf("\n");
				if(count%(a*b)==0)
					printf("\n");
			}
		}
	}
}

double*** mem_alloc_3D_double(int a, int b, int c){
	double ***p;
	int i,j;
	p=(double ***)malloc(sizeof(double **)*a);
	for(i=0;i<a;i++){
		p[i]=(double**)malloc(sizeof(double*)*b);
		for(j=0;j<b;j++){
			p[i][j]=(double *)malloc(sizeof(double)*c);
		}
	}
	return p;
}

void addition_3D(double ***A,double ***B,int a,int b,int c ){
	int i,j,k;
	int count=0;
	double ***C=mem_alloc_3D_double(a,b,c);
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			for(k=0;k<c;k++){
				*(*(*(C+i)+j)+k)=*(*(*(A+i)+j)+k)+*(*(*(B+i)+j)+k);
			}
		}
	}
	matrixPrint(C,a,b,c);
}


void main(){
	//Define 2 matrices A and B using 'mem_alloc_3D_double'
	int i,j,k,count=0;
	int a=4,b=3,c=2;
	double ***A=mem_alloc_3D_double(a,b,c);
	double ***B=mem_alloc_3D_double(a,b,c);
	if(A==NULL)
		printf("A할당 실패");
	if(B==NULL)
		printf("B할당 실패");

	//3D array A와 B에 value 넣기
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			for(k=0;k<c;k++){
				*(*(*(A+i)+j)+k)=count++;
				*(*(*(B+i)+j)+k)=count++;
			}
		}
	}

	//3D array A와 B 출력하기
	printf("-----A배열 출력-----\n");
	matrixPrint(A,a,b,c);
	printf("-----B배열 출력-----\n");
	matrixPrint(B,a,b,c);

	//Perform addition of 2 matrices using 'addition_3D();
	printf("-----addition배열 출력-----\n");
	addition_3D(A,B,a,b,c );

	//Deallocate A and B	
	if(A!=NULL){
		free(A[0][0]);
		free(A[0]);
		free(A);
		A=NULL;
	}
	if(B!=NULL){
		free(B[0][0]);
		free(B[0]);
		free(B);
		B=NULL;
	}
}