#1971044_정희수
mainHW3_03.c
목적 : 주어진 example code를 실행시킨다.

1)typedef int element;
목적 : element의 자료형을 int로 정의한다.

2)typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;
목적 : ListNode의 구조체를 정의한다.
ListNode *link는 다음 노드를 가리키는 포인터이다.

3)typedef struct{
	ListNode *head;
	ListNode *tail;
	int length;
}ListType;
목적 : 단일 연결리스트 헤더노드의 구조체를 정의한다.
ListNode *head는 연결리스트의 첫번째 노드를 가리키는 포인터이다.

4)int is_empty(ListType *list)
목적 : 연결리스트에 노드가 아무것도 없는지 확인한다.
input : ListType *list
output : 연결리스트가 비어있으면 1, 안비어있으면 0을 return 한다.

5)int get_length(ListType *list)
목적 : list의 길이를 받는다.
input : ListType *list
output : 연결리스트의 노드 개수

6)ListNode *get_node_at(ListType *list, int pos)
목적 : pos에 해당하는 연결리스트의 노드를 받는다.
input : ListType *list, int positon 
output : pos에 해당하는 연결리스트의 노드

7)void insert_node(ListType *phead, ListNode *p, ListNode *newnode)
목적 : p가 가리키는 노드 다음에 newnode를 새로 삽입한다.
input : ListType *phead, ListNode *p, ListNode *newnode
output : x

8)void add(ListType *list, int position, element data)
목적 : 특정 position에 노드를 삽입한다. 
input : ListType *list, int position, element data
output : x

9)void remove_node(ListType *phead,ListNode *p,ListNode *removed)
목적 : p가 가리키는 노드 다음의 node를 삭제한다.
input : ListType *phead,ListNode *p,ListNode *removed
output : x

10)void deletee(ListType *list,int pos)
목적 : 특정 positoin의 노드를 삭제한다.
input : ListType *list,int pos
output : x

11)element get_entry(ListType *list, int pos)
목적 : 리스트에서 특정 position에 있는 노드의 값(data)을 받는다.
input : ListType *list, int pos
output : 특정 position에 있는 노드의 data

12)void display(ListType *list)
목적 : 리스트의 값들을 출력한다.
input : ListType *list
output : x

13)int is_in_list(ListType *list, element item)
목적 : 리스트에 item값을 가지는 노드가 있는지 확인한다.
input : ListType *list, element item
output : 있으면 1, 없으면 0을 return 한다.

14)void init(ListType *phead)
목적 : 연결리스트를 초기화한다.
input : ListType *phead
output : x

15)void add_first(ListType *p,element data)
목적 : 연결리스트 맨 처음에 노드를 삽입한다.
input : ListType *p,element data
output : x

16)void add_last(ListType *p,element data)
목적 : 연결리스트 맨 끝에 노드를 삽입한다.
input : ListType *p,element data
output : x 

17)void delete_first(ListType *p)
목적 : 연결리스트 맨 처음의 노드를 삭제한다.
input : ListType *p
output : x 

18)void delete_last(ListType *p)
목적 : 연결리스트 맨 끝의 노드를 삭제한다.
input : ListType *p
output : x 