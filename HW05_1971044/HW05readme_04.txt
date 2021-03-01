#1971044_정희수
mainHW5_04.c
목적 : Revise the case 3 by using the predecessor at the left subtree.

1) 
typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;
key값, node의 왼쪽 자식노드를 가리키는 *left변수, node의 오른쪽 자식노드를 가리키는 *right변수를 구조체로 묶어 TreeNode를 선언했다.

2)void insert_node(TreeNode **root, int key)
목적 : tree에 key 값을 가지는 노드를 삽입한다.
input : TreeNode **root, int key
output : x

3)void delete_node(TreeNode **root, int key)
목적 : tree에 key 값을 가지는 노드를 삭제한다.
input : TreeNode **root, int key
output : x

4)void inorder(TreeNode *root)
목적 : tree를 inorder(L->V->R)방식으로 순회해 node값을 print한다.
input : TreeNode *root
output : x

