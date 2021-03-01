#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct DListNode{
	element data;
	struct DListNode * llink;
	struct DListNode * rlink;
}DListNode;

//이중 연결 리스트 초기화
void init(DListNode *phead){
	phead->llink=phead;
	phead->rlink=phead;
}

//이중연결리스트 노드 출력
void print_dlist(DListNode *phead){
	DListNode *p;
	for(p=phead->rlink;p!=phead;p=p->rlink){
		printf("<-| |%d| |->",p->data);
	}
	printf("\n");
	
}

//새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert_node(DListNode *before, element data){
	DListNode *newnode =(DListNode*)malloc(sizeof(DListNode));  
	newnode->data=data; 
	//41p 함수코드
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
