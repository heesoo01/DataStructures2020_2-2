#1971044 정희수
mainHW8_01.c
목적 : min-heap에서 decrease-key와 increase-key 함수를 정의한다
1)
typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} HeapType;
HeapType 구조체를 정의한다.
int heap[MAX_ELEMENT] // 힙에 들어가는 노드의 값을 저장하는 배열
int heap_size // 힙에 들어가는 노드 개수 

2)
void init(HeapType* h)
h가 가리키는 HeapType을 초기화 한다.

3)
void insert_min_heap(HeapType* h, int key)
h가 가리키는 HeapType에 key값을 가지는 노드를 삽입한다.

4)
void Decrease_key_min_heap(HeapType* h, int i, int key)
heap의 노드안의 값보다 작은 값을 대입하여 min heap을 만든다
HeapType* h //h가 가리키는 HeapType
int i // 힙의 i번째 노드 (==heap[i])
int key // 바꿀 노드 안의 값

5)
void increase_key_min_heap(HeapType* h, int i, int key)
heap의 노드안의 값보다 큰 값을 대입하여 min heap을 만든다
HeapType* h //h가 가리키는 HeapType
int i // 힙의 i번째 노드 (==heap[i])
int key // 바꿀 노드 안의 값

6)
void print(HeapType* h)
h가 가리키는 HeapType의 힙 값을 순서대로 출력한다.
HeapType* h //h가 가리키는 HeapType


