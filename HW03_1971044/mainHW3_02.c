#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode{
	int value;
	struct ListNode *link;
}ListNode;//노드 타입

typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;//리스트 헤더 타입

//리스트 헤더 생성 함수
ListType * create(){
	ListType *plist=(ListType *)malloc(sizeof(ListType));
	plist->size=0;
	plist->head=plist->tail=NULL;
	return plist;
}

//node 삽입 함수
void insert_last(ListType* plist, int value){
	ListNode *newnode=(ListNode *)malloc(sizeof(ListNode));
	newnode->value=value;
	newnode->link=NULL;
	if(plist->tail==NULL){
		plist->head=plist->tail=newnode;
	}
	else{
		plist->tail->link=newnode;
		plist->tail=newnode;
	}
	plist->size++;
}

void merge_list(ListType* alist,ListType *blist, ListType *clist){
	ListNode *k=alist->head;
	ListNode *p=blist->head;

	//k와 p 모두 NULL이 아닐때
	while(k&&p){
		if(k->value==p->value){
			insert_last(clist,k->value);
			insert_last(clist,p->value);
			k=k->link;
			p=p->link;
		}
		else if(k->value<p->value){
			insert_last(clist,k->value);
			k=k->link;
		}
		else{
			insert_last(clist,p->value);
			p=p->link;
		}
	}
	for(;p!=NULL;p=p->link)
		insert_last(clist,p->value);
	for(;k!=NULL;k=k->link)
		insert_last(clist,k->value);
}
void list_print(ListType * plist){
	ListNode *p=plist->head;
	for(;p;p=p->link)
		printf("%d,",p->value);
	printf("\n");
}

int main(void){
	ListType *alist, *blist, *clist;

	alist=create();
	blist=create();
	clist=create();

	insert_last(alist,1);
	insert_last(alist,2);
	insert_last(alist,5);
	insert_last(alist,10);
	insert_last(alist,15);
	insert_last(alist,20);
	insert_last(alist,25);

	insert_last(blist,3);
	insert_last(blist,7);
	insert_last(blist,8);
	insert_last(blist,15);
	insert_last(blist,18);
	insert_last(blist,30);

	printf("a=");
	list_print(alist);
	printf("b=");
	list_print(blist);
	merge_list(alist,blist,clist);
	printf("c=");
	list_print(clist);

	free(alist);
	free(blist);
	free(clist);
}
