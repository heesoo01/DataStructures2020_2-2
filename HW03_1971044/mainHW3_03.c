#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define TRUE 1

typedef int element;

typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

typedef struct{
	ListNode *head;
	ListNode *tail;
	int length;
}ListType;

int is_empty(ListType *list){
	if(list->head==NULL)
		return 1;
	else 
		return 0;
}

int get_length(ListType *list){
	return list->length;
}

//pos�� �ش��ϴ� node�� �޴´�.
ListNode *get_node_at(ListType *list, int pos){
	int i;
	ListNode *tmp = list->head;
	if(pos<0)
		return NULL;
	for(i=0;i<pos;i++)
		tmp=tmp->link;
	return tmp;
}

//newnode�� p�� ����Ű�� ��� ������ �����ϴ� �Լ�
void insert_node(ListType *phead, ListNode *p, ListNode *newnode){
	if(phead->length==0){
		newnode->link=NULL;
		phead->head=newnode;
	}
	else if(p==NULL){
	newnode->link=phead->head;
	phead->head=newnode;
	}
	else{
	newnode->link=p->link;
	p->link=newnode;
	}

}

//Ư�� pos�� data���� ������ node�� �����ϴ� �Լ�
void add(ListType *list, int position, element data){
	ListNode *p;
	if((position>=0)&&(position<=list->length)){
		ListNode *newnode=(ListNode *)malloc(sizeof(ListNode));
		newnode->data=data;
		p=get_node_at(list,position-1);
		insert_node(list,p,newnode);
		list->length++;
	}
}

//p�� ����Ű�� ��� ������ ��带 �����ϴ� �Լ�
void remove_node(ListType *phead,ListNode *p,ListNode *removed){
	if(p==NULL)
		phead->head=phead->head->link;
	else
		p->link=removed->link;
	free(removed);
}

//Ư�� pos�� node�� �����ϴ� �Լ�
void deletee(ListType *list,int pos){
	if(!is_empty(list)&&(pos>=0)&&(pos<list->length)){
		ListNode *p=get_node_at(list,pos-1);
		ListNode *removed = get_node_at(list,pos);
		remove_node(list,p,removed);
		list->length--;
	}
}

//Ư�� pos�� ����� data���� return
element get_entry(ListType *list, int pos){
	ListNode *p;
	p=get_node_at(list,pos);
	return p->data;
}

//list�� ����Ű�� ���Ḯ��Ʈ�� ��尪 ���
void display(ListType *list){
	int i;
	ListNode *node=list->head;
	printf("(");
	for(i=0;i<list->length;i++){
		printf("%d,",node->data);
		node=node->link;
	}
	printf(")\n");
}

//item�� ���� ���� ������ �ִ� ��尡 ����Ʈ�� �ִ��� Ȯ��
int is_in_list(ListType *list, element item){
	ListNode *p;
	p=list->head;
	while(p!=NULL){
		if(p->data==item)
			break;
		p=p->link;
	}
	if(p==NULL)
		return 0;
	else return 1;
}
//���Ḯ��Ʈ �ʱ�ȭ
void init(ListType *phead){
	phead->length=0;
}
//����Ʈ ó���� ��� ����
void add_first(ListType *p,element data){
	add(p,0,data);
}
//����Ʈ ���� ��� ����
void add_last(ListType *p,element data){
	add(p, get_length(p), data);
}
//����Ʈ ó���� ��� ����
void delete_first(ListType *p){
	deletee(p,0);
}
//����Ʈ ���� ��� ����
void delete_last(ListType *p){
	deletee(p,get_length(p)-1);
}

int main(){
	ListType list1;
	init(&list1);
	add_first(&list1,20); //(20)
	add_last(&list1,30);  //(20,30,)
	add_first(&list1,10);  //(10,20,30,)
	add_last(&list1,40); //(10,20,30,40,)
	add(&list1,2,70); //(10,20,70,30,40,)
	display(&list1);

	deletee(&list1,2); //(10,20,30,40,)
	delete_first(&list1); //(20,30,40,)
	delete_last(&list1); //(20,30,)
	display(&list1);

	printf("%s\n",is_in_list(&list1,20)==TRUE ? "TRUE":"FALSE");
	printf("%d\n",get_entry(&list1,0));
}
