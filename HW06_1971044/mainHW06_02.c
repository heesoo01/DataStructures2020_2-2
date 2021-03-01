// huffman.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_ELEMENT 1000
#define MAX_BIT      10
#define MAX_CHAR   20

// Input data for huffman code
typedef struct input_huff {
    char* data;      // Character array (a ~ f)
    int* freq;      // Frequency array
    int size;      // Number of characters
} input_huff;

// Structure for huffman binary tree
typedef struct TreeNode {
    char data;         // Character (a ~ f)
    int key;         // Frequency
    int bits[MAX_BIT];   // Huffman codeword
    int bit_size;      // Huffman codeword's size
    struct TreeNode* l;   // Left child of huffman binary tree
    struct TreeNode* r;   // Right child of huffman binary tree
} TreeNode;

// Structure for bits stream
typedef struct bits_stream {
    int* stream;
    int length;
} bits_stream;

// Elements used in the heap
typedef struct element {
    TreeNode* ptree;
    int key;   // frequency of each character
} element;

// Heap
typedef struct HeapType {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

int** m_LUT, * m_bit_size;
int   m_char_size = 6;

// Initialization
void init(HeapType* h)
{
    h->heap_size = 0;
}
//
int is_empty(HeapType* h)
{
    if (h->heap_size == 0)
        return 1;
    else
        return 0;
}

//min heap : 부모노드의 값 < 자식노드의 값 
void insert_min_heap(HeapType* h, element item)
{
    int i; 
    i = ++(h->heap_size); // 가장 마지막 노드 번호

    // compare it with the parent node in an order from the leaf to the root
    while ((i != 1) && (item.key < h->heap[i / 2].key)) { //i가 1이 아니거나, item의 key가 부모노드의 key보다 작을때
        h->heap[i] = h->heap[i / 2];
        i /= 2;  //부모노드와 자식노드 위치를 바꾼다. 
    }
    h->heap[i] = item; // Insert new node
}

//heap에서 가장 작은 값(우선순위가 가장 높음)을 삭제하고 return한다.
element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;
    item = h->heap[1]; //heap의 가장 작은 노드
    temp = h->heap[(h->heap_size)--]; //heap의 마지막 노드
    parent = 1;
    child = 2;
    while (child <= h->heap_size) { //child값이 heap의 size보다 작을때까지 while문을 돌린다.
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
            //child값이 heap_size보다 작거나, 왼쪽 노드값이 오른쪽 노드값보다 크다면
            child++; //child의 값을 1 증가한다.
        if (temp.key <= h->heap[child].key) break; //temp의 key값이 child번호의 key값보다 작으면 break
        h->heap[parent] = h->heap[child]; //부모노드에 자식노드를 대입한다.
        parent = child; //parent값에 child값을 대입한다.
        child *= 2; //child값을 2배로 증가한다. ->자식노드
    }
    h->heap[parent] = temp;
    return item; //삭제한 노드의 값을 return 한다.
}

// Node generation in binary tree
TreeNode* make_tree(TreeNode* left, TreeNode* right)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    node->l = left;
    node->r = right;
    return node;
}

// Binary tree removal
void destroy_tree(TreeNode* root)
{
    if (root == NULL) return;
    destroy_tree(root->l);
    destroy_tree(root->r);
    free(root);
}

// Huffman code generation
element huffman_tree(input_huff* huff)
{
    int i;
    TreeNode* node, * x;
    HeapType heap;
    element e, e1, e2;
    init(&heap);

    int n = huff->size;

    for (i = 0; i < n; i++) {
        node = make_tree(NULL, NULL);
        e.ptree = node;
        node->data = huff->data[i];
        e.key = node->key = huff->freq[i];
        memset(node->bits, 0, sizeof(int) * MAX_BIT);
        node->bit_size = 0;

        insert_min_heap(&heap, e);
    }

    for (i = 1; i < n; i++) {
        // Delete two nodes with minimum values
        e1 = delete_min_heap(&heap);
        e2 = delete_min_heap(&heap);

        // Merge two nodes
        x = make_tree(e1.ptree, e2.ptree);
        e.ptree = x;
        x->data = NULL;
        e.key = x->key = e1.key + e2.key;
        memset(x->bits, 0, sizeof(int) * MAX_BIT);
        x->bit_size = 0;

        insert_min_heap(&heap, e);
    }
    e = delete_min_heap(&heap); // Final Huffman binary tree

    return e;
    //   destroy_tree(e.ptree);
}


// Generate the huffman codeword from the huffman binary tree
// Hint: use the recursion for tree traversal
// input: root node
// output: m_LUT, m_bit_size
void huffman_traversal(TreeNode* node, int arr[], int idx)
{
    //...
    int char_num = 0;
    if (node->l) {
        arr[idx] = 0;
        huffman_traversal(node->l, arr, idx + 1);
    }
    if (node->r) {
        arr[idx] = 1;
        huffman_traversal(node->r, arr, idx + 1);
    }
    if (node->l==NULL && node->r==NULL) {
        switch (node->data) {
        case('a'): char_num = 0;  break;
        case('b'): char_num = 1;  break;
        case('c'): char_num = 2;  break;
        case('d'): char_num = 3;  break;
        case('e'): char_num = 4;  break;
        case('f'): char_num = 5;  break;
        }
        for (int i = 0;i < idx;i++) {
            m_LUT[char_num][i] = arr[i];
        }
        m_bit_size[char_num] = idx;
    }


}

int** mem_2D_int(int row, int col)
{
    int** m2 = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
        m2[i] = (int*)malloc(sizeof(int) * col);

    return m2;
}

void print_codeword()
{
    printf("* Huffman codeword\n");
    for (int i = 0; i < m_char_size; i++)
    {
        switch (i) {
        case 0:
            printf("%c: ", 'a');
            break;
        case 1:
            printf("%c: ", 'b');
            break;
        case 2:
            printf("%c: ", 'c');
            break;
        case 3:
            printf("%c: ", 'd');
            break;
        case 4:
            printf("%c: ", 'e');
            break;
        case 5:
            printf("%c: ", 'f');
            break;
        }

        for (int j = 0; j < m_bit_size[i]; j++)
            printf("%d", m_LUT[i][j]);

        printf("\n");
    }

}

// Input: 'str'
// Output: 'bits_stream' (consisting of 0 or 1)
// 'bits_stream' is generated using 'm_LUT' generated by the huffman binary tree
// Return the total length of bits_stream
void huffman_encoding(char* str, bits_stream* bits_str)
{
    //..
    int i = 0;
    int char_num = 0;
    bits_str->length = 0;
    int n = bits_str->length;
    while (str[i] != NULL) {
        switch (str[i]) {
        case('a'): char_num = 0; break;
        case('b'): char_num = 1; break;
        case('c'): char_num = 2; break;
        case('d'): char_num = 3; break;
        case('e'): char_num = 4; break;
        case('f'): char_num = 5; break;
        }
        for (int j = n;j < n + m_bit_size[char_num];j++) {
            bits_str->stream[j] = m_LUT[char_num][j - n];
            bits_str->length++;
        }
        n = bits_str->length;
        i++;
    }
    int interval = bits_str->length;
    printf("\n* Huffman encoding\n");
    printf("total length of bits stream: %d\n", interval);
    printf("bits stream: ");
    for (int i = 0; i < interval; i++)
        printf("%d", bits_str->stream[i]);
    printf("\n");
}

// input: 'bits_stream' and 'total_length'
// output: 'decoded_str'
int huffman_decoding(bits_stream* bits_str, TreeNode* node, char* decoded_str)
{
    //...
    int index_char = 0;
    TreeNode* p = node;
    for (int i = 0;i < bits_str->length;i++) {
        if (bits_str->stream[i] == 0) { 
            p = p->l;
            if (p->l == NULL && p->r == NULL) {
                decoded_str[index_char++] = p->data;
                p = node;  //p가 leaf node가 되면 다시 p에 root를 대입한다.            
            }
        }
        if (bits_str->stream[i] == 1) {
            p = p->r;
            if (p->l == NULL && p->r == NULL) {
                decoded_str[index_char++] = p->data;
                p = node; //p가 leaf node가 되면 다시 p에 root를 대입한다.    
            }
        }
    }
    printf("\n* Huffman decoding\n");
    printf("total number of decoded chars: %d\n", index_char);
    printf("decoded chars: ");
    for (int i = 0; i < index_char; i++)
        printf("%c", decoded_str[i]);
    printf("\n");

    return index_char;
}

void main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 45, 13, 12, 16, 9, 5 };
    int top = 0;
    int codes[100];

    input_huff* huff1 = (input_huff*)malloc(sizeof(input_huff));
    huff1->data = data;
    huff1->freq = freq;
    huff1->size = m_char_size;

    // m_LUT: each row corresponds to the codeword for each character
    // m_bit_size: 1D array of codeword size for each character
    // For instance, a = 0, b = 101, ...
    // 1st row of 'm_LUT': 0 0 ... 0
    // 2nd row of 'm_LUT': 1 0 1 ...0
    // m_bit_size = {1, 3, ...}
    m_LUT = mem_2D_int(m_char_size, MAX_BIT);
    m_bit_size = (int*)malloc(sizeof(int) * m_char_size);

    // Generate the huffman binary tree on heap
    // 'element_root': element containing the root node
    element element_root = huffman_tree(huff1);

    // Generate the huffman codeword from the huffman binary tree
    huffman_traversal(element_root.ptree, codes, top);

    //printf out the huffman codeword
    print_codeword();

    //example of input data
    char str[MAX_CHAR] = { "abacdebaf" };
    //char str[MAX_CHAR] = { "ab" };
    char decoded_str[MAX_CHAR];

    printf("\n* input chars: ");
    for (int i = 0; i < strlen(str); i++)
        printf("%c", str[i]);
    printf("\n");

    //start encoding
    bits_stream* bits_str1 = (bits_stream*)malloc(sizeof(bits_stream));
    bits_str1->stream = (int*)malloc(sizeof(int) * MAX_BIT * MAX_CHAR);
    memset(bits_str1->stream, -1, sizeof(int) * MAX_BIT * MAX_CHAR);
    bits_str1->length = 0;

    huffman_encoding(str, bits_str1);

    //start decoding   
    int decoded_char_length = huffman_decoding(bits_str1, element_root.ptree, decoded_str);
}