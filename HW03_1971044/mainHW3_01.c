#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct DListNode{
	element data;
	struct DListNode * llink;
	struct DListNode * rlink;
}DListNode;

//���� ���� ����Ʈ �ʱ�ȭ
void init(DListNode *phead){
	phead->llink=phead;
	phead->rlink=phead;
}

//���߿��Ḯ��Ʈ ��� ���
void print_dlist(DListNode *phead){
	DListNode *p;
	for(p=phead->rlink;p!=phead;p=p->rlink){
		printf("<-| |%d| |->",p->data);
	}
	printf("\n");
	
}

//���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert_node(DListNode *before, element data){
	DListNode *newnode =(DListNode*)malloc(sizeof(DListNode));  
	newnode->data=data; 
	//41p �Լ��ڵ�
	newnode->llink=before;
	newnode->rlink=before->rlink;  
	before->rlink->llink=newnode; 
	before->rlink=newnode;  
}


void dinsert_last_node(DListNode *head, element data){	
	DListNode *newnode =(DListNode*)malloc(sizeof(DListNode)); 
	newnode->data=data; 
	newnode->llink=head->llink; 
	newnode->rlink=head;  
	head->llink->rlink=newnode;  
	head->llink=newnode;
}

int main(){
	DListNode *head=(DListNode *)malloc(sizeof(DListNode));
	init(head);
	dinsert_node(head,20);
	dinsert_node(head,10); 
	dinsert_last_node(head,30); 
	dinsert_last_node(head,40); 
	print_dlist(head);	
	free(head);
}
