#1971044_정희수
mainHW4_02.c
목적 : Simulatoin.cpp를 수정해 두명의 bank staff가 일할때로 코드를 실행한다.

1) typedef struct element {
	int id;
	int arrival_time;
	int service_time;
} element;
목적 : customer의 정보(id, arrival_time, service_time)를 묶어 구조체를 정의한다.

2) typedef struct QueueType {
	element  queue[MAX_SIZE];
	int  front, rear;
} QueueType;
목적 : customer가 저장될 queue의 정보(queue[],front,rear)를 묶어 구조체를 정의한다.

3)double random() 
목적 : 랜덤으로 0에서 1사이의 수를 return 한다.
input : x
output : 0에서 1 사이의 random수

4) int is_empty(QueueType * q)
목적 : 큐가 비어있는지 확인한다.
input : QueueType * q
output : 비어있으면 1, 안비어있으면 0을 return

5) int is_full(QueueType * q)
목적 : 큐가 포화상태인지 확인한다.
input : QueueType * q
output : 포화상태면 1, 아니면 0을 return

6)void enqueue(QueueType * q, element item)
목적 : 큐에 item 하나를 삽입한다.
input : QueueType * q, element item
output : x

7) int is_customer_arrived()
목적 : 고객이 왔는지 확인한다.
input :x
output : 고객이 왔으면 1, 안왔으면 0

8) void insert_customer(int arrival_time)
목적 : 새로 온 고객을 큐에 삽입한다.
input : int arrival_time
output : x

9)int remove_customer()
목적 : 고객이 기다린 시간과 고객의 서비스가 시작한 시각을 알려준다.
input : x
output : service_time

10) print_stat()
목적 : 서비스 종료 후 서비스 수행 상태를 알려준다.
input : x
output : x
