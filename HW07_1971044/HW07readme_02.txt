#1971044 정희수
mainHW7_02.c
목적 : counting sort를 통해 radix sort 코드를 완성하라

1)
int get_max(int arr[],int arr_num)
목적 : arr배열의 가장 큰 수를 return한다.
input : int arr[](배열),int arr_num(배열 원소 개수)
output : arr배열의 가장 큰 수

2)
void counting_sort(int arr[], int cal,int num)
목적 : arr배열을 count sort한다.
input : int arr[], int cal(거듭제곱해서 만들 n진수), int num(num진수)
output : x

3)
void radix_sort(int arr[],int arr_num,int num)
목적 : arr배열을 radix sort한다.
input : int arr[], int arr_num(arr배열의 원소개수), int num(num진수)
output : x

4)
void print_arr(int arr[],int arr_num)
목적 : arr배열을 출력한다.
input : int arr[](배열), int arr_num(arr배열의 원소개수)
output : x

5)
void make_random_arr(int arr[],int arr_num, int num)
목적 : num자리 랜덤 수를 arr_num개 만들어 arr배열을 생성한다.
input : int arr[](배열), int arr_num(배열 원소개수), int num(비트수)
output : x


1000개 랜덤 수
수 범위 : 0~2^24-1
총 24비트의 랜덤 수
24비트를 4개 digit으로 나눔
한 digit에 6비트있음
6비트->2^6=64
64진수
