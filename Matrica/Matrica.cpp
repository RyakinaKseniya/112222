#include <stdio.h>
#include <stdlib.h>
#include <math.h> //подключение библиотек
#define M 5 //внесение директивы M
int main() //объявление функции main
{
	int arr[M][M] = {
	{12,  -6,   6,   8,   1},
	{8,   7,  -6,   5,   3},
	{0,   7,  -6,  -9,   4},
	{1, -10,  -8,   8,   5},
	{6,  -4,   2,   5,   3},
	}; //задаются значения для элементов матрицы
	int i, j, k;
	int sum, ok, * sums, sum_index;
	int min_elem; //объявление элементов и их типов

	for (j = 0; j < M; j++) {//введение цикла в диапазоне от 0 до M 
		ok = 1;
			sum = 0; // присвоение значений переменным
		for (k = 0; k < M; k++) {
			if (arr[k][j] < 0) {
				ok = 0;
				break;
			}// 
			sum += arr[k][j];// цикл, в котором проверятся есть ли в столбце отрицательные элемент. Если есть отрицательные элемент, то сумма не считается, а если в столбце отрицательных элементов нет, то считается сумма элементов в столбце.
		}
		if (ok) {
			printf("column: %d, sum: %d\n", j + 1, sum);//выводится результат сложения по столбцам 
		}
	}

	sums = (int*)malloc(sizeof(int) * (M - 1) * 2);
	if (sums == NULL) {
		exit(EXIT_FAILURE);
	}
	sum_index = 0; //возвращение указателя


		for (i = 0; i < M - 1; i++) {//введение цикла в диапазоне от 0 до M-1
			j = i;
			k = 0;
			sum = 0;//присвоение значении переменным
			while (j >= 0 && k < M) {
				sum += abs(arr[j][k]);
				j--;
				k++; //вычисление модуля передаваемого значения
			}//выполняются действия пока j>= 0 или k<M
			sums[sum_index] = sum;
			sum_index++;
			min_elem = sums[0];
			for (sum_index -= 1; sum_index >= 0; sum_index--) {
				if (min_elem > sums[sum_index]) {
					min_elem = sums[sum_index];
				}
			} // цикл для поиска минимума элементов диагоналей параллельных побочной диагонали матрицы

			printf("min: %d\n", min_elem);//dsdjl htpekmnfnf hf,jns wbrkf

			free(sums);
			exit(EXIT_SUCCESS);
		} //завершение процесса 

