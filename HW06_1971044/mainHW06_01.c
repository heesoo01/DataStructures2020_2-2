// heapsort.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define MAX_ELEMENT 2000
typedef struct element {
    int key;
} element;

typedef struct {
    element* heap;
    int heap_size;
} HeapType;

// Integer random number generation function between 0 and n-1
int random(int n)
{
    return rand() % n;
}

// Initialization
void init(HeapType* h) {
    h->heap_size = 0;
}

// Insert the item at heap h, (# of elements: heap_size)
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    // The process of comparing with the parent node as it traverses the tree
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // Insert new node
}

// Delete the root at heap h, (# of elements: heap_size)
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; //루트노드 값을 반환하기 위해 item에 대입
    temp = h->heap[(h->heap_size)--]; //temp에 말단노드 대입(heap_size 하나 줄임)
    parent = 1;
    child = 2;
    while (child <= h->heap_size) { //자식노드번호가 heap_size보다 작을때까지(히프트리를 벗어나지않으면)
        // Find a smaller child node
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key) //왼쪽자식노드가 오른쪽 자식노드보다 작으면
            child++; //child를 오른쪽 자식노드 번호로 바꿈
        if (temp.key >= h->heap[child].key) break;
        // 한단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}


void build_max_heap(HeapType* h)
{
    for (int i = h->heap_size / 2;i > 0;i--) {
        int l = i * 2;
        int r = (i * 2) + 1;
        int largest = i;
        int change = 0;

        if (l<h->heap_size && h->heap[l].key>h->heap[largest].key)//왼쪽자식노드와 비교
            largest = l; //왼쪽 자식노드가 더 크면 largest에 l 대입

        if (r<h->heap_size && h->heap[r].key>h->heap[largest].key)//오른쪽자식노드와 비교
            largest = r; //오른쪽 자식노드가 더 크면 largest에 r 대입

        if (largest != i) { //부모노드보다 자식 노드가 큰 경우 교환
            change = h->heap[largest].key;
            h->heap[largest].key = h->heap[i].key;
            h->heap[i].key = change;
            build_max_heap(h); //재귀 호출
        }
    }


}

//input: heap 'h'
//output: sorted element array 'a'
void heap_sort(HeapType* h, element* a, int n)
{
    int i;

    build_max_heap(h);
    for (i = (n - 1); i >= 0; i--) {
        a[i] = delete_max_heap(h);
    }
}

int check_sort_results(element* output, int n)
{
    int index = 1;
    for (int i = 0;i < n - 1;i++)
        if (output[i].key > output[i + 1].key)
        {
            index = 0;
            break;
        }
    return index;
}

void main()
{
    clock_t t = clock();
    time_t t1;
    //Intializes random number generator
    srand((unsigned)time(&t1));

    int input_size = 10;   //10, 100, 1000
    int data_maxval = 10000;

    HeapType* h1 = (HeapType*)malloc(sizeof(HeapType));
    // 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
    h1->heap = (element*)malloc(sizeof(element) * (input_size + 1));

    // output: sorted result
    element* output = (element*)malloc(sizeof(element) * input_size);



    // Generate an input data randomly
    for (int i = 0; i < input_size; i++)
        h1->heap[i + 1].key = random(data_maxval);   // note) heap starts with 1.
    h1->heap_size = input_size;

    if (input_size < 20) {
        printf("Input data\n");
        for (int i = 0; i < input_size; i++)   printf("%d\n", h1->heap[i + 1].key);
        printf("\n");
    }
   
    // Perform the heap sort
    heap_sort(h1, output, input_size);
    

    if (input_size < 20) {
        printf("Sorted data\n");
        for (int i = 0; i < input_size; i++)
            printf("%d\n", output[i].key);
        printf("\n");
    }

    // Your code should pass the following function (returning 1)
    if (check_sort_results(output, input_size))
        printf("Sorting result is correct.\n");
    else
        printf("Sorting result is wrong.\n");
    clock_t t2 = clock();
    printf("input_size: %d runtime : %lf\n", input_size,(double)(t2 - t) / CLOCKS_PER_SEC);
}