#1971044 정희수
mainHW8_02.c
목적 : min heap을 이용해서 prim algorithm을 완성하라

1)
typedef struct {
	int num;//node number
	int key;//value 
}element;
int num; //node number
int key; //value 

2)
typedef struct {
	element heap[MAX_VERTICES];
	int size;
}HeapType;
element heap[MAX_VERTICES]; //MAX_VERTICES크기의 element 자료형 heap 배열 선언
int size; //heap에 들어가있는 element의 개수

3)
typedef struct {
	int parent;
	int child;
}Relation;
int parent; //부모 노드 vertex_number
int child; //자식 노드 vertex_number

4)
void init(HeapType* h)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
heap을 초기화한다.

5)
int is_empty(HeapType* h)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
heap이 비어있는지 확인한다. 
비어있으면 1, 아니면 0 return

6)
element delete_min_heap(HeapType* h)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
heap의 루트노드를 삭제하고 return한다.

7)
void Decrease_key_min_heap(HeapType* h, int i, int key)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
int i //값을 변경할 heap의 노드의 index
int key //변경할 값
heap의 i번째 노드의 값을 key로 감소한다.

8)
int find_key(HeapType* h, int v_num)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
int v_num //vertex의 number
heap에서 vertex number가 v_num인 노드의 key 값을 return 한다.

9)
int find_num_idx(HeapType* h, int v_num)
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
int v_num //vertex의 number
heap에서 vertex number가 v_num인 노드의 heap idx를 return 한다.

10)
int find_parent(element item)
element item //element 자료형 변수
item의 key값과 같은 weight[i][j]값을 찾아 i를 return 한다.

11)
void insert_min_heap(HeapType* h, int item_num, int item_key) 
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
int item_num //힙에 삽입할 item의 num(vertex_num)
int item_key //힙에 삽입할 item의 key(vertex_key)
힙에 노드를 삽입한다.

12)
void prim(HeapType* h, int s, int n) 
HeapType* h //h가 가리키는 HeapType의 구조체 포인터
int s //prim을 시작할 노드의 vertex 번호
int n //vertex 개수
graph에서 prim algorithm을 시행한다.

13)
void print_prim()
prim algorithm을 시행한 결과물을 출력한다.

