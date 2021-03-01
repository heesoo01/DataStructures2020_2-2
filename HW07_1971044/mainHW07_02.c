#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define SIZE 1000

//revise the code by revising the counting sort instead of the queue.


int get_max(int arr[],int arr_num) {
	int max = arr[0];
	for (int i = 0;i < arr_num;i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}


void counting_sort(int arr[], int cal,int num) {//num=64
	int B[SIZE];
	int C[64] = { 0, }; //배열 선언&초기화
	for (int i = 0;i < SIZE;i++) { //count개수 증가            //(1)
		C[(arr[i] / cal) % num]+=1;
	}
	for (int i = 1;i < num;i++) { //누적 배열생성              //(2)
		C[i] += C[i - 1];
	}
	for (int i = SIZE - 1;i >= 0;i--) {                        //(3)
		B[C[(arr[i] / cal) % num] - 1] = arr[i];
		C[(arr[i] / cal) % num]-=1;
	}
	for (int i = 0;i < SIZE;i++) {                             //(4)
		arr[i] = B[i];
	}
}


void radix_sort(int arr[],int arr_num,int num) { //num=64
	int arr_max = get_max(arr,arr_num);
	for (int cal = 1;arr_max / cal > 0;cal *= num) //64==2^6
		counting_sort(arr, cal, num);
}

void print_arr(int arr[],int arr_num) {
	for (int i = 0;i <arr_num;i++)
		printf("%d | ", arr[i]);
}

void make_random_arr(int arr[],int arr_num, int num){
	srand((unsigned int)time(NULL));
	int sum = 0, cal=1, result=1;
	for (int i = 0; i <arr_num; i++){
		for (int j = 0; j < num; j++) { //2진수로 num자리 랜덤수 생성
			result = rand() % 2; //0 or 1중에 랜덤으로 생성
			if (result == 1)
				sum += cal;
			cal *= 2;
		}
		arr[i] = sum;
		sum = 0;//합계 초기화
		cal = 1;//이진수 초기화
	}
}

void main(void) {
	int arr[SIZE]; //랜덤수 넣을 SIZE크기의 배열 선언
	make_random_arr(arr,SIZE,24); //0~2^24-1까지의 랜덤 수 SIZE만큼 생성해 arr에 삽입
	print_arr(arr,SIZE);//arr배열 출력
	printf("%s\n", "<--------------------------SORT-------------------------------->");
	radix_sort(arr,SIZE,64);//arr배열 radix_sort하기
	print_arr(arr,SIZE);//sort된 arr배열 출력
}