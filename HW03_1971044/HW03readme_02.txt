#1971044_정희수
mainHW3_02.c
목적 : a연결리스트와 b연결리스트의 value를 모두 합쳐 오름차순인 연결리스트 c를 만든다.

1)typedef struct ListNode{
	int value;
	struct ListNode *link;
}ListNode;
목적 : 단일 연결리스트의 노드의 정보(값, 이후 노드를 가리키는 포인터 변수 link)를 묶어 구조체로 만든다.
input : x
output : x

2)typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
}ListType;
목적 : 단일 연결리스트의 헤더 노드를 만들어 연결리스트의 노드 개수, 헤드를 가리키는 포인터, 리스트의 끝을 가리키는 포인터를 쉽게 접근할 수 있도록 해준다.
input : x
output : x

3)ListType * create()
목적 : 연결리스트의 헤더노드를 생성해 하나의 연결리스트를 만든다.
input : x
output : 헤더노드

4)void insert_last(ListType* plist, int value)
목적 : 노드를 연결리스트 맨끝에 삽입하는 함수이다.
input : ListType * plist와 value
output : x

5)void merge_list(ListType* alist,ListType *blist, ListType *clist)
목적 : alist와 blist를 합쳐 오름차순으로 정렬한 clist를 만든다.
input : ListType* alist, ListType *blist, ListType *clist
output : x

6)void list_print(ListType * plist)
목적 : list의 노드의 값을 출력해준다.
input : ListType * plist
output : x

