#1971044 정희수
mainHW7_01.c
목적 : selection_sort를 stable하게 만들어라

1)
typedef struct data {
    int* id;
    int* score;
} data;
목적 : int *id, int *score을 묶어 data의 구조체를 정의함
int *id : 배열 순서번호
int *score : 배열 값

2)
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
목적 : x와 y의 값을 바꾼다.

3)
void selection_sort(data* list, int n)
목적 : selectoin_sort로 unstable한 sort를 만든다.
input : data *list(구조체 data를 가리키는 포인터 변수), int n(숫자 개수)
output : x

4)
void selection_sort_stable(data* list, int n)
목적 : selection sort로 stable한 sort를 만든다.
input : data *list(구조체 data를 가리키는 포인터 변수), int n(숫자 개수)
output : x


