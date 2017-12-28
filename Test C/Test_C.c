#include <stdio.h>
#include <stdlib.h>

void swapIntNumber(int *a, int *b); // 두 정수 swap 함수 선언
void swapFloatNumber(float *a, float *b); // 두 실수 swap 함수 선언
void quickSortDescending(float efficiency[], int size[], int price[], int first, int last); // 내림차순 QuickSort 함수 선언
int *sliceArr(int arr[], int startIndex, int endIndex); // Python의 a[b:c]의 기능 함수 선언
int fractionalKnapsack(int n, int size[], int price[], int K); // fractional knapsack 함수 선언, bounding function역할
void knapsack(int n, int size[], int price[], int T, int i); // 0/1 knapsack 함수 선언

int *x; // i번째의 물품을 선택할 것인지에 대한 여부를 저장할 동적 배열
int *solution; // i번째의 물품을 선택했는지에 대한 여부를 저장할 동적 배열
int maxProfit = 0; // 최대 이익

int main()
{
	int n; // 물품의 개수
	int K; // 가방의 크기
	int i; // loop-index

	scanf("%d", &K); // 가방의 크기 입력
	scanf("%d", &n); // 물품의 개수 입력

	x = (int*)malloc(sizeof(int)*n); // 배열 x 동적 할당
	solution = (int*)malloc(sizeof(int)*n); // 배열 solution 동적 할당
	int *size = (int*)malloc(sizeof(int)*n); // 배열 size 동적 할당
	int *price = (int*)malloc(sizeof(int)*n); // 배열 profit 동적 할당
	float *efficiency = (float*)malloc(sizeof(int)*n); // 배열 efficiency 동적 할당

	for(i = 0; i < n; i++)
	{ // 배열 x, solution 초기화
		x[i] = 0;
		solution[i] = 0;
	}

	for(i = 0; i < n; i++)
	{ // 각 물품의 크기를 입력
		scanf("%d", &size[i]);
	}

	for(i = 0; i < n; i++)
	{ // 각 물품의 가격 입력
		scanf("%d", &price[i]);
	}

	for(i = 0; i < n; i++)
	{ // 각 물품의 단위 크기(1) 당 이익을 구함
		efficiency[i] = (float)price[i] / (float)size[i];
	}

	quickSortDescending(efficiency, size, price, 0, n-1); // 각 물품의 이익을 기준으로 물품의 속성을 내림차순 정렬

	knapsack(n, size, price, K, 0); // 원하는 해를 구함

	printf("%d\n", maxProfit); // 결과 출력

	return 0;
}

void swapIntNumber(int *a, int *b)
{ // 두 정수 swap 함수
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swapFloatNumber(float *a, float *b)
{ // 두 실수 swap 함수
	float temp = *a;
	*a = *b;
	*b = temp;
}

void quickSortDescending(float efficiency[], int size[], int price[], int first, int last)
{ // 내림차순 QuickSort 함수
	if(first >= last)
	{ // 정렬할 값이 1개 이하인 경우
		return;
	}

	int left = first + 1;
	int right = last;
	float pivot = efficiency[first]; // pivot의 값을 배열의 가장 첫 번째 값으로 지정

	while(left <= right)
	{ // left > right이 아닐 때 까지 반복
		while(left <= last && efficiency[left] > pivot)
		{ // pivot보다 큰 수를 만날 때까지 오른쪽으로 이동
			left++;
		}
		while(right > first && efficiency[right] <= pivot)
		{ // pivot보다 작은 수를 만날 때까지 왼쪽으로 이동
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
	quickSortDescending(efficiency, size, price, first, right-1); // pivot보다 작은 값들에 대해 quickSort 재귀 호출
	quickSortDescending(efficiency, size, price, right+1, last); // pivot보다 큰 값들에 대해 quickSort 재귀 호출
}

int *sliceArr(int arr[], int startIndex, int endIndex)
{ // Python의 a[b:c]의 기능 함수
	int slicedSize = endIndex - startIndex; // 잘라진 배열의 크기
	int *sliced = (int*)malloc(sizeof(int)*slicedSize); // 잘라진 배열의 크기 만큼 새로운 배열 동적 할당
	int i; // loop-index

	for(i = 0; i < slicedSize; i++)
	{ // 원래의 배열에서 값 복사
		sliced[i] = arr[startIndex+i];
	}

	return sliced; // 잘라진 배열 반환
}

int fractionalKnapsack(int n, int size[], int price[], int K)
{ // n개의 물품, 크기 size[], 가격 profit[], 가방의 현재 빈 공간 K
	if(K <= 0)
	{ // 가방의 현재 빈 공간이 0 이하인 경우
		return 0;
	}

	int s = 0; // 현재까지 선택한 물품의 크기 합 = 0 (초기 값)
	int p = 0; // 현재까지 선택한 물품의 가치 합 = 0 (초기 값)
	int selectedProfit = 0; // 현재 선택한 물품의 이익
	int i = 0; // loop-index

	for(i = 0; i < n; i++)
	{
		if(s + size[i] <= K)
		{ // 배낭에 쏙 들어가면 전체 선택
			selectedProfit += price[i];
			s += size[i];
			p += selectedProfit;
		}
		else
		{ // 넘치면 잘라서 선택
			selectedProfit += (K-s)*(price[i]/size[i]);
			s = K; // 자른 물품을 채움으로써 가방이 가득 찼음
			break;
		}
	}

	return selectedProfit; // bounding function의 값 반환
}

void knapsack(int n, int size[], int price[], int T, int i)
{ // n개의 물품, 크기 size[], 가격 profit[], 가방의 현재 빈 공간 T, 인덱스 i
	if(i >= n || T <= 0)
	{ // 배열의 최대 인덱스를 거나, 가방의 현재 빈 공간이 0 이하인 경우
		return;
	}

	int s = 0; // 현재까지 선택한 아이템의 크기 합 = 0 (초기 값)
	int p = 0; // 현재까지 선택한 아이템의 가치 합 = 0 (초기 값)
	int m; // loop-index

	for(m = 0; m < n; m++)
	{ // 현재까지 선택한 아이템의 크기와 가치 계산
		s += size[m] * x[m];
		p += price[m] * x[m];
	}

	x[i] = 1; // i번째 물품을 가방에 넣는 경우
	int B = fractionalKnapsack(n-(i+1), sliceArr(size, i+1, n), sliceArr(price, i+1, n), T-size[i]);
	if((size[i] <= T) && (p+price[i]+B >= maxProfit))
	{ // 계속 탐색해야 하는 경우
		if(p+price[i] > maxProfit)
		{ // maxProfit보다 더 큰 경우를 찾았을 때
			maxProfit = p+price[i]; // maxProfit 업데이트
			solution[i] = x[i]; // 해를 저장한 배열 업데이트
		}

		s += size[i]; // 현재까지 선택한 아이템의 크기 합 계산
		p += price[i]; // 현재까지 선택한 아이템의 가치 합 계산

		knapsack(n, size, price, T-size[i], i+1); // 줄어든 가방 크기에 대해 다음 아이템에 대하여 재귀 호출
	}

	x[i] = 0; // i번째 물품을 가방에 넣지 않는 경우
	B = fractionalKnapsack(n-(i+1), sliceArr(size, i+1, n), sliceArr(price, i+1, n), T);
	if(p+B > maxProfit)
	{ // 계속 탐색해야 하는 경우
		knapsack(n, size, price, T, i+1); // 줄어들지 않은 가방 크기에 대해 다음 아이템에 대하여 재귀 호출
	}
}
