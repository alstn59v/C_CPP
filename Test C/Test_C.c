#include <stdio.h>
#include <stdlib.h>

void swapIntNumber(int *a, int *b); // �� ���� swap �Լ� ����
void swapFloatNumber(float *a, float *b); // �� �Ǽ� swap �Լ� ����
void quickSortDescending(float efficiency[], int size[], int price[], int first, int last); // �������� QuickSort �Լ� ����
int *sliceArr(int arr[], int startIndex, int endIndex); // Python�� a[b:c]�� ��� �Լ� ����
int fractionalKnapsack(int n, int size[], int price[], int K); // fractional knapsack �Լ� ����, bounding function����
void knapsack(int n, int size[], int price[], int T, int i); // 0/1 knapsack �Լ� ����

int *x; // i��°�� ��ǰ�� ������ �������� ���� ���θ� ������ ���� �迭
int *solution; // i��°�� ��ǰ�� �����ߴ����� ���� ���θ� ������ ���� �迭
int maxProfit = 0; // �ִ� ����

int main()
{
	int n; // ��ǰ�� ����
	int K; // ������ ũ��
	int i; // loop-index

	scanf("%d", &K); // ������ ũ�� �Է�
	scanf("%d", &n); // ��ǰ�� ���� �Է�

	x = (int*)malloc(sizeof(int)*n); // �迭 x ���� �Ҵ�
	solution = (int*)malloc(sizeof(int)*n); // �迭 solution ���� �Ҵ�
	int *size = (int*)malloc(sizeof(int)*n); // �迭 size ���� �Ҵ�
	int *price = (int*)malloc(sizeof(int)*n); // �迭 profit ���� �Ҵ�
	float *efficiency = (float*)malloc(sizeof(int)*n); // �迭 efficiency ���� �Ҵ�

	for(i = 0; i < n; i++)
	{ // �迭 x, solution �ʱ�ȭ
		x[i] = 0;
		solution[i] = 0;
	}

	for(i = 0; i < n; i++)
	{ // �� ��ǰ�� ũ�⸦ �Է�
		scanf("%d", &size[i]);
	}

	for(i = 0; i < n; i++)
	{ // �� ��ǰ�� ���� �Է�
		scanf("%d", &price[i]);
	}

	for(i = 0; i < n; i++)
	{ // �� ��ǰ�� ���� ũ��(1) �� ������ ����
		efficiency[i] = (float)price[i] / (float)size[i];
	}

	quickSortDescending(efficiency, size, price, 0, n-1); // �� ��ǰ�� ������ �������� ��ǰ�� �Ӽ��� �������� ����

	knapsack(n, size, price, K, 0); // ���ϴ� �ظ� ����

	printf("%d\n", maxProfit); // ��� ���

	return 0;
}

void swapIntNumber(int *a, int *b)
{ // �� ���� swap �Լ�
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapFloatNumber(float *a, float *b)
{ // �� �Ǽ� swap �Լ�
	float temp = *a;
	*a = *b;
	*b = temp;
}

void quickSortDescending(float efficiency[], int size[], int price[], int first, int last)
{ // �������� QuickSort �Լ�
	if(first >= last)
	{ // ������ ���� 1�� ������ ���
		return;
	}

	int left = first + 1;
	int right = last;
	float pivot = efficiency[first]; // pivot�� ���� �迭�� ���� ù ��° ������ ����

	while(left <= right)
	{ // left > right�� �ƴ� �� ���� �ݺ�
		while(left <= last && efficiency[left] > pivot)
		{ // pivot���� ū ���� ���� ������ ���������� �̵�
			left++;
		}
		while(right > first && efficiency[right] <= pivot)
		{ // pivot���� ���� ���� ���� ������ �������� �̵�
			right--;
		}
		if(left <= right)
		{
			swapFloatNumber(&efficiency[left], &efficiency[right]); // swap
			swapIntNumber(&size[left], &size[right]); // swap
			swapIntNumber(&price[left], &price[right]); // swap
			left++;
			right--;
		}
	}

	swapFloatNumber(&efficiency[first], &efficiency[right]); // swap
	swapIntNumber(&size[first], &size[right]); // swap
	swapIntNumber(&price[first], &price[right]); // swap
	quickSortDescending(efficiency, size, price, first, right-1); // pivot���� ���� ���鿡 ���� quickSort ��� ȣ��
	quickSortDescending(efficiency, size, price, right+1, last); // pivot���� ū ���鿡 ���� quickSort ��� ȣ��
}

int *sliceArr(int arr[], int startIndex, int endIndex)
{ // Python�� a[b:c]�� ��� �Լ�
	int slicedSize = endIndex - startIndex; // �߶��� �迭�� ũ��
	int *sliced = (int*)malloc(sizeof(int)*slicedSize); // �߶��� �迭�� ũ�� ��ŭ ���ο� �迭 ���� �Ҵ�
	int i; // loop-index

	for(i = 0; i < slicedSize; i++)
	{ // ������ �迭���� �� ����
		sliced[i] = arr[startIndex+i];
	}

	return sliced; // �߶��� �迭 ��ȯ
}

int fractionalKnapsack(int n, int size[], int price[], int K)
{ // n���� ��ǰ, ũ�� size[], ���� profit[], ������ ���� �� ���� K
	if(K <= 0)
	{ // ������ ���� �� ������ 0 ������ ���
		return 0;
	}

	int s = 0; // ������� ������ ��ǰ�� ũ�� �� = 0 (�ʱ� ��)
	int p = 0; // ������� ������ ��ǰ�� ��ġ �� = 0 (�ʱ� ��)
	int selectedProfit = 0; // ���� ������ ��ǰ�� ����
	int i = 0; // loop-index

	for(i = 0; i < n; i++)
	{
		if(s + size[i] <= K)
		{ // �賶�� �� ���� ��ü ����
			selectedProfit += price[i];
			s += size[i];
			p += selectedProfit;
		}
		else
		{ // ��ġ�� �߶� ����
			selectedProfit += (K-s)*(price[i]/size[i]);
			s = K; // �ڸ� ��ǰ�� ä�����ν� ������ ���� á��
			break;
		}
	}

	return selectedProfit; // bounding function�� �� ��ȯ
}

void knapsack(int n, int size[], int price[], int T, int i)
{ // n���� ��ǰ, ũ�� size[], ���� profit[], ������ ���� �� ���� T, �ε��� i
	if(i >= n || T <= 0)
	{ // �迭�� �ִ� �ε����� �ų�, ������ ���� �� ������ 0 ������ ���
		return;
	}

	int s = 0; // ������� ������ �������� ũ�� �� = 0 (�ʱ� ��)
	int p = 0; // ������� ������ �������� ��ġ �� = 0 (�ʱ� ��)
	int m; // loop-index

	for(m = 0; m < n; m++)
	{ // ������� ������ �������� ũ��� ��ġ ���
		s += size[m] * x[m];
		p += price[m] * x[m];
	}

	x[i] = 1; // i��° ��ǰ�� ���濡 �ִ� ���
	int B = fractionalKnapsack(n-(i+1), sliceArr(size, i+1, n), sliceArr(price, i+1, n), T-size[i]);
	if((size[i] <= T) && (p+price[i]+B >= maxProfit))
	{ // ��� Ž���ؾ� �ϴ� ���
		if(p+price[i] > maxProfit)
		{ // maxProfit���� �� ū ��츦 ã���� ��
			maxProfit = p+price[i]; // maxProfit ������Ʈ
			solution[i] = x[i]; // �ظ� ������ �迭 ������Ʈ
		}

		s += size[i]; // ������� ������ �������� ũ�� �� ���
		p += price[i]; // ������� ������ �������� ��ġ �� ���

		knapsack(n, size, price, T-size[i], i+1); // �پ�� ���� ũ�⿡ ���� ���� �����ۿ� ���Ͽ� ��� ȣ��
	}

	x[i] = 0; // i��° ��ǰ�� ���濡 ���� �ʴ� ���
	B = fractionalKnapsack(n-(i+1), sliceArr(size, i+1, n), sliceArr(price, i+1, n), T);
	if(p+B > maxProfit)
	{ // ��� Ž���ؾ� �ϴ� ���
		knapsack(n, size, price, T, i+1); // �پ���� ���� ���� ũ�⿡ ���� ���� �����ۿ� ���Ͽ� ��� ȣ��
	}
}
