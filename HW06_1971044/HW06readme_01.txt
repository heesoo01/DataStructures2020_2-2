#1971044_정희수
mainHW6_01.c
목적 : input data를 build_max_heap 함수를 통해 sort한다.

1)
typedef struct element {
    int key;
} element;
key 정보(binary tree의 node 정보)를 담은 구조체이다.

2)
typedef struct {
    element* heap; 
    int heap_size;
} HeapType;
HeapType의 정보를 담은 구조체이다.

3)
int random(int n)
0과 n-1사이의 랜덤 수를 return 한다.
input : int n
ouput : 랜덤 수

4)
void init(HeapType* h)
h가 가리키는 HeapType을 초기화한다.
input : HeapType* h
output : x

5)
void insert_max_heap(HeapType* h, element item)
h가 가리키는 HeapType에 새로운 element 자료형의 item을 추가한다.
input : HeapType* h, element item
output : x

6)
element delete_max_heap(HeapType* h)
h가 가리키는 HeapType에 우선순위가 가장 높은 node를 삭제한다.
input : HeapType* h
output : x

7) 
void build_max_heap(HeapType* h)
h가 가리키는 HeapType을 매개변수로 받아 max_heap을 만든다.
input : HeapType* h
output : x

8)
void heap_sort(HeapType* h, element* a, int n)
HeapType * h의 heap을 최대 heap으로 정렬해 우선순위가 큰 값부터 a에 저장한다.
input : HeapType* h, element* a, int n
output : x

9)
int check_sort_results(element* output, int n)
ouput이 가리키는 배열의 원소가 작은값부터 큰값까지 차례대로 정렬되어있는지 확인한다.
input : element* output, int n
output : 정렬되어있으면 1, 아니면 0을 return 한다.


 


