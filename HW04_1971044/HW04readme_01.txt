#1971044_정희수
mainHW4_01.c
목적 : circular doubly linked list를 이용해 main function이 돌아가게 만든다.
1) typedef int element;
목적 : element의 자료형을 int로 정해준다.

2) typedef struct DlistNode{
	element item;
	struct DlistNode *rlink;
	struct DlistNode *llink;
}DlistNode;
목적 : circular doubly linked list안에 들어있는 item과 이전 노드를 가리키는 포인터 llink와 이후 노드를 가리키는 포인터 rlink의 정보를 묶어 구조체  DlistNode라고 정의한다.

3) typedef struct{
	DlistNode *top;
}LinkedStackType;
목적 : circular doubly linked list로 만든 스택에 top인 노드를 가리키는 top 변수를 구조체 LinkedStackType이라고 정의한다.

4) void init(LinkedStackType *s, DlistNode *head)
목적 : LinkedStackType의 스택을 초기화한다.
input : LinkedStackType *s, DlistNode *head
output : x(s가 초기화됨)

5) int is_empty(LinkedStackType *s,DlistNode *head)
목적 : s가 가리키는 스택이 비어있는지 확인한다.
input : LinkedStackType *s,DlistNode *head
output : 비어있으면 1, 안비어있으면 0을 return

6) void push(LinkedStackType *s, DlistNode *head, element item)
목적 : s가 가리키는 스택에 item을 삽입한다.
input : LinkedStackType *s, DlistNode *head, element item
output : x

7) element pop(LinkedStackType *s)
목적 : s가 가리키는 스택에 element 하나를 무엇인지 확인하고 삭제한다.
input : LinkedStackType *s
output : element item

8) element peek(LinkedStackType *s)
목적 : s가 가리키는 스택에 가장 최근의 element가 무엇인지 확인한다.
input : LinkedStackType *s
output : element item

