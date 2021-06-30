// �ִ� ��

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
	// heap �� ���� ������ �߰�
	heap[++heap_count] = data;

	// child�� parent�� �ϳ��ϳ� ���ϸ�, �˸��� ��ġ�� �ø�
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
	// heap �� ���� ù ��° ���Ҹ� ��ȯ
	int result = heap[1];

	// ù ��° ���ҿ�, ���� ������ ���Ҹ� ����
	// ���� �ϳ� �پ��� ������ heap count ����
	heap[1] = heap[heap_count];
	heap_count--;

	// parent�� child�� ���ϸ�, �˸��� ��ġ�� ����
	// �ڽ� ��� (��)
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
		// 1~50������ ���� ����
		arr[i] = rand() % 50 + 1;
	}

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// 1~50������ ���� ����
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