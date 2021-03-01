#1971044_정희수
HW2_02.c
목적 : 3D array인 A와 B에 동적 메모리 할당을 하고 값을 임의로 넣어준 다음, 두 배열을 합친다. 마지막으로 A와 B를 dealloacte한다. 

1) void matrixPrint(double*** A,int a,int b,int c)
목적 : triple pointer인 A 배열을 출력한다. 
input : double*** A(3D array), a(열), b(행), c(면)
output : return 값 없음(출력 수행)

2) double*** mem_alloc_3D_double(int a, int b, int c)
목적 : a열 b행 c면인 3D 배열에 동적 메모리 할당을 해준다.
input : a(열), b(행), c(면)
output : 동적 메모리 할당을 해준 a(열), b(행), c(면)인 3D 배열을 return한다.

3) void addition_3D(double ***A,double ***B,int a,int b,int c )
목적 : a열 b행 c면인 3D 배열 두개를 더해준다.
input :  double*** A(3D array),  double*** B(3D array),  a(열), b(행), c(면)
output : return 값 없음(A와 B를 더한 배열을 출력한다.)