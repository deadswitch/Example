

/*****************************************************************************************************
Написать функцию bsearch, которая принимает на вход отсортированный по неубыванию массив целых чисел и целое число x. 
В качестве результата функция должна возвращать индекс первого элемента массива, строго большего x. 
В Вашей реализации функция может принимать любое количество любых параметров, только 2 этих параметра обязательны. 
При использовании Вашей функции должна быть возможность определить, существует ответ или нет. 
В качестве решения пришлите ссылку на репозиторий с программой на языке C с примером использования функции.
******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE_ARRAY (25)
#define X (153)
#define FAIL (-1)

typedef int index;

index Bsearch(int array[],int left,int right,int x)
{
	if(array[right]<=x) return FAIL;
	if(array[left]>x) return left;
	long long int middle;
	while(left<right) {
		middle = (right+left)>>1;
		if(array[middle]>x) {
			right = middle;
		} else if(array[middle]<x) {
			left = middle+1;
		} else {
			while(array[++middle]==x);
			return middle;
		}
	}
	return right;
}

void QuickSort(int array[], int first, int last)
{
	if (first>=last) return;
	int left = first, right = last, middle = array[(left+last)>>1];
	while(left <= right) {
		while (array[left]<middle) left++;
		while (array[right]>middle) right--;
		if (left<=right) {
			int tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;
			left++;
			right--;
		}
	}
	QuickSort(array, first, right);
	QuickSort(array, left, last);
}

int main(int argc,char **argv)
{
	setlocale(0,"rus");
	int someArray[SIZE_ARRAY];
	for(int i=0; i<SIZE_ARRAY; i++) {
		someArray[i] = rand()%677+2;
	}
	QuickSort(someArray,0,SIZE_ARRAY-1);
	for(int i=0; i<SIZE_ARRAY; i++) {
		printf("%d-ый элемент  = %d\n",i,someArray[i]);
	}
	index res = Bsearch(someArray,0,SIZE_ARRAY-1,X);
	if(res!=FAIL) {
		printf("Индекс элемента строго большего X - %d\n",res);
	} else {
		printf("Такое число отсутствует");
	}
	return 0;
}
