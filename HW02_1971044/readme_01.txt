#1971044_정희수
HW2_01.c
목적 : sparsematrix를 이용하여 2차원 배열의 전치 행렬 출력하기 
1) typedef struct element{}element;
목적 :  한 행렬의 값이 0이 아닌 행(row), 열(col), 값(value)를 구조체 element로 묶기

2) typedef struct SparseMatrix{}SparseMatrix;
목적 : element 배열 선언, 한 행렬의 rows(행개수), cols(열개수), term(값이 0이 아닌 행렬의 개수)를 구조체  SparseMatrix로 묶기

3) SparseMatrix transposeMatrix(SparseMatrix a)
목적 : 한 행렬의 전치행렬 구하기
input : 한 행렬
output : 한 행렬의 전치 행렬

4) void matrixPrint(SparseMatrix a)
목적 : 한 행렬의 sparsematrix버전 출력하기
input : 한 행렬 
output : return 값 없음

5) void matrixPrint2(SparseMatrix a)
목적 : 한 행렬의 dense matrix버전 출력하기
input : 한 행렬
output : return 값 없음


