#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct DlistNode{
	element item;
	struct DlistNode *rlink;
	struct DlistNode *llink;
}DlistNode;

typedef struct{
	DlistNode *top;
}LinkedStackType;

//�ʱ�ȭ �Լ�
void init(LinkedStackType *s, DlistNode *head){
	head->llink=head;
	head->rlink=head;
	s->top=head;
}

//������ ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(LinkedStackType *s,DlistNode *head){
	return (s->top==head);
}

//���ÿ� �����Լ�
void push(LinkedStackType *s, DlistNode *head, element item){
	DlistNode *temp =(DlistNode *)malloc(sizeof(DlistNode));
	if(temp==NULL){
		printf("�޸� �Ҵ�X");
		return;
	}
	else{
		temp->item=item; //1
		temp->llink=head;  //2
		temp->rlink=s->top;  //3
		s->top->llink=temp;  //4
		head->rlink=temp;  //5
		s->top=temp;  //6
	}
}

//���ÿ� �����Լ�
element pop(LinkedStackType *s){
	if(is_empty(s,s->top->llink)){
		printf("������ ����ֽ��ϴ�.\n");
		exit(1);
	}
	else{
		DlistNode *temp=s->top;  //1
		element item;
		item=temp->item;
		s->top=temp->rlink;  //2
		temp->llink->rlink=temp->rlink;  //3
		temp->rlink->llink=temp->llink;	 //4
		free(temp);  //5
		return item;
	}
}

//��ũ�Լ�
element peek(LinkedStackType *s){
	if(is_empty(s,s->top->llink)){
		printf("������ ����ֽ��ϴ�.\n");
		exit(1);
	}
	else{
		return s->top->item;
	}
}

void main(){
	LinkedStackType s;
	DlistNode *head=(DlistNode *)malloc(sizeof(DlistNode));
	init(&s,head);
	push(&s, head, 1);
	push(&s, head, 2);
	push(&s, head ,3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}