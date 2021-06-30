// 최대 힙

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEAP_SIZE	256
#define ARRAY_SIZE		10

int heap[MAX_HEAP_SIZE] = { 0, };
int heap_count = 0;

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int data)
{
	// heap 의 끝에 데이터 추가
	heap[++heap_count] = data;

	// child를 parent와 하나하나 비교하며, 알맞은 위치로 올림
	int child = heap_count;
	int parent = child / 2;
	while (1 < child && heap[parent] < heap[child])
	{
		swap(&heap[parent], &heap[child]);

		child = parent;
		parent = child / 2;
	}
}

int pop()
{
	// heap 의 가장 첫 번째 원소를 반환
	int result = heap[1];

	// 첫 번째 원소에, 가장 마지막 원소를 대입
	// 원소 하나 줄어들기 때문에 heap count 감소
	heap[1] = heap[heap_count];
	heap_count--;

	// parent를 child와 비교하며, 알맞은 위치로 내림
	// 자식 노드 (좌)
	int parent = 1;
	int child = parent * 2;
//	if (child + 1 <= heap_count)
//	{
//		child = (heap[child] > heap[child + 1]) ? child : child + 1;
//	}

	while (child <= heap_count && heap[parent] < heap[child])
	{
		swap(&heap[parent], &heap[child]);

		parent = child;
		child = parent * 2;
//		if (child + 1 <= heap_count)
//		{
//			child = (heap[child] > heap[child + 1]) ? child : child + 1;
//		}
	}

	return result;
}

int main()
{
	int arr[ARRAY_SIZE];

	srand(time(NULL));
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// 1~50까지의 난수 생성
		arr[i] = rand() % 50 + 1;
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// 1~50까지의 난수 생성
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		push(arr[i]);

		for (int j = 0; j < heap_count; j++)
			printf("%d ", heap[j]);

		printf("\n");
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", pop());
	}

	scanf("%d", arr[1]);
	
	return 0;
}