#include <stdio.h>
#include <stdlib.h>

typedef struct element{
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix{
	element data[100];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix transposeMatrix(SparseMatrix a){
	SparseMatrix b;
	int bindex=0;
	b.rows=a.cols;
	b.cols=a.rows;
	b.terms=a.terms;

	if(a.terms>0){
		int c;
		int i;
		for(c=0;c<a.cols;c++){
			for(i=0;i<a.terms;i++){
				if(a.data[i].col==c){
					b.data[bindex].row=a.data[i].col;
					b.data[bindex].col=a.data[i].row;
					b.data[bindex].value=a.data[i].value;
					bindex++;
				}
			}
		}
	}
	
	return b;
}

void matrixPrint(SparseMatrix a){
	int i;
	for(i=0;i<a.terms;i++){
		printf("(%d, %d, %d)\n",a.data[i].row,a.data[i].col,a.data[i].value);
	}
}

void matrixPrint2(SparseMatrix a){
	int k=0,t=0;
	int c,i;
	for(c=0;c<a.rows;c++){
		for(i=0;i<a.cols;i++){
			if(a.data[k].row==c){
				if(a.data[k].col==i){
					printf("%d ",a.data[k].value);
					k++;
				}
				else
					printf("%d ",0);
			}
			else
				printf("%d ",0);
			t++;
			if(t%a.cols==0)
				printf("\n");//t가 a의 열의 배수가 되면 다음 줄로 넘어간다.
		}
	}
}

int main(void){
	//add B as an input. Use your own example freely.
	SparseMatrix B={
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2},{5,7,3}},6,8,8
	};

	//Perform the transpose operation
	SparseMatrix BT;
	BT=transposeMatrix(B);

	//Print out B and B^T in a dense matrix for to check
	//whether the operation works correctly.
	printf("B^T의 sparsematrix 출력\n");
	matrixPrint(BT);
	printf("");
	printf("---------------------------------\n");
	printf("B in a dense matrix form to check\n");
	matrixPrint2(B);
	printf("---------------------------------\n");
	printf("B^T in a dense matrix form to check\n");
	matrixPrint2(BT);
	printf("---------------------------------\n");

	return 0;
}