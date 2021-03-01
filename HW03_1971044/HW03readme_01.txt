#1971044_정희수
mainHW3_01.c
목적 : 이중연결리스트에서 새로운 노드를 함수를 통해 맨 앞과 맨 뒤에 삽입한다. 

1)typedef int element;
목적 : 노드에 넣을 data의 자료형을 결정한다.

2)typedef struct DListNode{}DListNode;
목적 : 이중연결리스트의 노드 안에 들어있는 data와 이전 노드를 가리키는 포인터 llink와 이후 노드를 가리키는 포인터 rlink의 정보를 묶어 구조체 DListNode라고 정의한다.

3)void init(DListNode *phead)
목적 : 이중연결리스트를 초기화한다.
input : 이중연결리스트의 헤더노드를 가리키는 변수 phead
output : x

4)void print_dlist(DListNode *phead)
목적 : 이중 연결리스트에 있는 data들을 출력한다.
input : 이중연결리스트의 헤더노드를 가리키는 변수 phead
output : x

5)void dinsert_node(DListNode *before, element data)
목적 : newnode(새로 삽입할 노드)를 before 가리키는 노드 다음 순서에 삽입한다.
input : newnode이전의 노드를 가리키는 변수 before, newnode의 data
output : x

6)void dinsert_last_node(DListNode *head, element data)
목적 : 이중연결리스트 맨 끝에 노드(newnode)를 새로 삽입한다.
input : 이중연결리스트의 헤더노드를 가리키는 변수 head, newnode의 data
output : x