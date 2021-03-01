#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 8
#define INF 1000


int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0,3,INF,INF,INF,INF,INF,14},
	{3,0,8,INF,INF,INF,INF,10},
	{INF,8,0,15,2,INF,INF,INF},
	{INF,INF,15,0,INF,INF,INF,INF},
	{INF,INF,2,INF,0,9,4,5},
	{INF,INF,INF,INF,9,0,INF,INF},
	{INF,INF,INF,INF,4,INF,0,6},
	{14,10,INF,INF,5,INF,6,0}
};

typedef struct {
	int num;//node number
	int key;//value 
}element;

typedef struct {
	element heap[MAX_VERTICES];
	int size;
}HeapType;

typedef struct {
	int parent;
	int child;
}Relation;

element selected[MAX_VERTICES];
Relation edge[MAX_VERTICES];

void init(HeapType* h) {
	h->size = 0;
}
int is_empty(HeapType* h) {
	return(h->size == 0);
}

element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[0];
	temp = h->heap[--(h->size)];
	parent = 0;
	child = 1;
	while (child <= h->size) {
		if ((child < h->size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void Decrease_key_min_heap(HeapType* h, int i, int key) {
	element temp;
	if (key >= h->heap[i].key) {
		printf("error new key is not smaller than current key\n");
		return;
	}
	h->heap[i].key = key;

	while ((i > 0) && (h->heap[i / 2].key > h->heap[i].key)) {
		temp = h->heap[i / 2];
		h->heap[i / 2] = h->heap[i];
		h->heap[i] = temp;
		i /= 2;
	}
}
int find_key(HeapType* h, int v_num) {
	for (int i = 0;i < MAX_VERTICES;i++) {
		if (h->heap[i].num == v_num)
			return h->heap[i].key;
	}
}
int find_num_idx(HeapType* h, int v_num) {
	for (int i = 0;i < MAX_VERTICES;i++) {
		if (h->heap[i].num == v_num)
			return i;
	}
}
int find_parent(element item) {
	for (int i = 0;i < MAX_VERTICES;i++)
		for (int j = 0;j < MAX_VERTICES;j++) {
			if (weight[i][j] == item.key)
				return i;
		}
}
void insert_min_heap(HeapType* h, int item_num, int item_key) {
	int i;
	i = ++(h->size);
	while ((i != 1) && (item_key < h->heap[i / 2].key)) {
		h->heap[i].key = h->heap[i / 2].key;
		h->heap[i].num = h->heap[i / 2].num;
		i /= 2;
	}
	h->heap[i - 1].num = item_num;
	h->heap[i - 1].key = item_key;
}


void prim(HeapType* h, int s, int n) {
	int i, u, v;
	element item;
	for (i = 0;i < n;i++) { //selected와 edge배열을 초기화한다.
		selected[i].num = FALSE;
		selected[i].key = FALSE;
		edge[i].child = FALSE;
		edge[i].parent = FALSE;
	}
	Decrease_key_min_heap(h, find_num_idx(h, s), 0); //vertex_num이 0인 노드에 0 key 값을 대입한다.
	while (!is_empty(h)) { //힙이 빌 때까지 while문을 돌린다.
		item = delete_min_heap(h); //item은 힙에 있는 노드 중 가장 작은 key 값을 가지는 element를 받는다.
		u = item.num;
		selected[u] = item; //selected배열의 u번째 vertex 값이 FALSE가 아니게 된다. 
		edge[u].child = u; //u의 child를 삽입한다.
		edge[u].parent = find_parent(item); //u의 parent를 찾아 edge에 삽입한다.
		for (v = 0;v < n;v++) {
			if (weight[u][v] != INF) { //weight값이 무한대가 아닐때
				if (selected[v].num==FALSE && weight[u][v] < find_key(h, v)) {
					//아직 v번째 vertex가 MST에 없고, weight[u][v] 값이 기존의 find_key(h,v)값 보다 작다면
					Decrease_key_min_heap(h, find_num_idx(h, v), weight[u][v]); //힙의 노드의 값을 바꿔준다.
				}
			}
		}
	}

}

void print_prim() {
	for (int i = 1;i < MAX_VERTICES;i++) {
		printf("Vertex %d -> %d", edge[i].parent, edge[i].child);
		printf("    edge : %d\n", selected[i].key);
	}
}
void main() {
	HeapType* h = (HeapType*)malloc(sizeof(HeapType));
	init(h);
	for (int i = 0;i < MAX_VERTICES;i++)
		insert_min_heap(h, i, INF);
	
	prim(h, 0, MAX_VERTICES);
	print_prim();
}