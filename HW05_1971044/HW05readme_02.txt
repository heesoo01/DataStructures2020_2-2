#1971044_정희수
mainHW5_02.c
목적 : Implement the function that finds a successor of node in the inorder traversal.

1)
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right, *parent;
}TreeNode;
목적 : tree의 각 node에 data, *left, *right, *parent 정보의 값을 저장할 수 있는 구조체를 정의한다.

2) TreeNode *tree_successor(TreeNode *p)
목적 : p가 가리키는 node의 successor node를 구해 return한다.
input : TreeNode *p
ouput : p가 가리키는 node의 successor node


