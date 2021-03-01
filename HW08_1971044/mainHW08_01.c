
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define MAX_ELEMENT 200

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_min_heap(HeapType* h, int key) {
    int i;
    i = ++(h->heap_size);
    while ((i != 1) && (key < h->heap[i / 2])) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = key;
}

void Decrease_key_min_heap(HeapType* h, int i, int key) {
    int temp;
    if (key >= h->heap[i]) {
        printf("error new key is not smaller than current key ");
        return;
    }
    h->heap[i] = key;
    while ((i > 1) && (h->heap[i / 2] > h->heap[i])) {
        temp = h->heap[i / 2];
        h->heap[i / 2] = h->heap[i];
        h->heap[i] = temp;
        i /= 2;
    }
}

void increase_key_min_heap(HeapType* h, int i, int key) {
    int temp;
    if (key <= h->heap[i]) {
        printf("error : new key is not bigger than current key ");
        return;
    }
    h->heap[i] = key;
    while ((i<h->heap_size) && (h->heap[i]>h->heap[i * 2]) ) {
        temp = h->heap[i * 2];
        h->heap[i * 2] = h->heap[i];
        h->heap[i] = temp;
        i *= 2;
    }
    i /= 2;
    h->heap[i] = key;
  
}

void print(HeapType* h) {
    for (int i = 1;i < h->heap_size + 1;i++)
        printf("%d\n", h->heap[i]);
    printf("----------------\n");
}

void main(void) {
    HeapType h;
    init(&h);
    
    insert_min_heap(&h, 1);
    insert_min_heap(&h, 4);
    insert_min_heap(&h, 2);
    insert_min_heap(&h, 7);
    insert_min_heap(&h, 5);
    insert_min_heap(&h, 3);
    insert_min_heap(&h, 3);
    insert_min_heap(&h, 7);
    insert_min_heap(&h, 8);
    insert_min_heap(&h, 9);

    print(&h); 
    
    Decrease_key_min_heap(&h, 4, 3);

    print(&h);

    increase_key_min_heap(&h, 3, 10);

    print(&h);
  

}