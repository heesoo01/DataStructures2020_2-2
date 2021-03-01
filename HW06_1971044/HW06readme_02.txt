#1971044_정희수
mainHW6_02.c
목적 : Huffman binary tree를 이용하여 input data를 encode, decode한다.

1)
typedef struct input_huff {
    char* data;      // Character array (a ~ f)
    int* freq;      // Frequency array
    int size;      // Number of characters
} input_huff;
huffman code에 들어갈 input data의 구조체이다.

2)
typedef struct TreeNode {
    char data;         // Character (a ~ f)
    int key;         // Frequency
    int bits[MAX_BIT];   // Huffman codeword
    int bit_size;      // Huffman codeword's size
    struct TreeNode* l;   // Left child of huffman binary tree
    struct TreeNode* r;   // Right child of huffman binary tree
} TreeNode;
huffman binary tree의 구조체이다.

3)
typedef struct bits_stream {
    int* stream; //bits를 넣을 stream 배열 
    int length; //stream 배열의 길이
} bits_stream;

4)
typedef struct element {
    TreeNode* ptree;
    int key;   // frequency of each character
} element;
heap에 쓰일 element의 구조체이다.

5)
typedef struct HeapType {
    element heap[MAX_ELEMENT]; //element자료형의 이름 heap인 배열
    int heap_size; //heap의 원소 개수(크기)
} HeapType;
heap의 구조체이다.

6)
int** m_LUT //각 character의 비트를 2차원배열에 담았다.
int* m_bit_size; //각 character의 비트 길이를 1차원배열에 담았다.
int   m_char_size = 6; //character의 개수

7)
void init(HeapType* h)
input : HeapType* h(HeapType 구조체를 가리키는 포인터 변수)
output : x
h가 가리키는 heaptype을 초기화한다.

8)
int is_empty(HeapType* h)
{
    if (h->heap_size == 0)
        return 1;
    else
        return 0;
}
input : HeapType* h(HeapType 구조체를 가리키는 포인터 변수)
output : empty면 1, 아니면 0
h가 가리키는 heaptype이 empty인지 확인한다.

9)
void insert_min_heap(HeapType* h, element item)
input : HeapType* h(HeapType 구조체를 가리키는 포인터 변수), element item
ouptut : x
h가 가리키는 HeapType에 element 자료형의 item을 추가한다.

10)
element delete_min_heap(HeapType* h)
input : HeapType* h(HeapType 구조체를 가리키는 포인터 변수)
ouput : 삭제한 element 값
h가 가리키는 HeapType에 element 하나를 삭제하고 return한다.

11)
TreeNode* make_tree(TreeNode* left, TreeNode* right)
input : TreeNode* left, TreeNode* right
ouptut : TreeNode * 자료형의 tree
매개변수로 들어간 left와 right를 잇는 부모 노드를 return하여 tree하나를 만든다.

12)
void destroy_tree(TreeNode* root)
input : TreeNode* root(TreeNode의 root 노드를 가리키는 포인터 변수)
output : x
root 노드에 동적할당한 메모리를 없애준다.

13)
element huffman_tree(input_huff* huff)
input : input_huff* huff(허프만 트리에 쓰일 input data의 구조체)
output : huffman binary tree
huff tree를 인자로 받아 huffman tree를 만들고 return한다.

14)
void huffman_traversal(TreeNode* node, int arr[], int idx)
input : TreeNode* node, int arr[](huffman code를 담을 배열), int idx()
ouput : x
node의 huffman code를 traversal한다. 

15)
int** mem_2D_int(int row, int col)
input : int row, int col
ouput : 동적할당한 2D 배열을 가리키는 이중 포인터 변수
행이 row고 열이 col인 2D 배열을 동적할당해 return한다.

16)
void print_codeword()
input : x
ouput : x
huffman codeword를 print한다.

17)
void huffman_encoding(char* str, bits_stream* bits_str)
input : char* str, bits_stream* bits_str
ouput : x
str을 인코딩하여 bits_str 배열에 저장한 후 순서대로 print한다.

18)int huffman_decoding(bits_stream* bits_str, TreeNode* node, char* decoded_str)
input : bits_stream* bits_str, TreeNode* node, char* decoded_str
output : decoding한 char의 길이
bits_str을 받아 decoding하여 decoded_char에 저장하여 출력한다.








