#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define Life

#ifdef Life

#define N 5
#define M 5
#define K 0
int count = 0;

int count_of_1(int** a, int x, int y) {
	int sum = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++){
			sum += a[x + i][y + j];
		}
	}
	sum -= a[x][y];
	return sum;
}

int the_next_generation(int** a, int x, int y, int count) {
	if (count == 3) {
		return 1;
	}
	else if (count == 2 && a[x][y] == 1) {
		return 1;
	}
	else return 0;
}

int check_last_generations(int*** last, int** a) {
	int b = 0;
	for (int k = 0; k < count; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == last[i][j][k]) {
					b++;
				}
			}
		}// hhgghkuh
		if (b == N * M) {
			return 1;
			break;
		}
		else if (k == count - 1) return 0;
	}
}

void create_new_table(int*** last) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			last[i][j] = (int*)malloc(sizeof(int));
		}
	}
}

int main (){
	setlocale(LC_ALL, "Russian");
	int a[N][M] = { 0 };
	int* p_a[N] = { 0 }, * p_b[N] = { 0 };
	int** pointer_a = 0, **pointer_b = 0;
	int b[N][M] = { 0 };
	int*** last = 0;
	int sircle_count = 0, chotchik = -1;

	for (int i = 0; i < N; i++) {
		p_a[i] = a[i];
		p_b[i] = b[i];
	}
	pointer_a = p_a;
	pointer_b = p_b;

	last = (int***)calloc(N, sizeof(int**)); 
	for (int i = 0; i < N; i++)
	{
		last[i] = (int**)calloc(M, sizeof(int*));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			last[i][j] = (int*)malloc(sizeof(int));
		}
	}
	chotchik++;
	
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a[i][j] = rand() % 2;
			printf("%d\t", a[i][j]);
			last[i][j][0] = a[i][j];
		}
		puts("\n");
	}
	puts("\n\n");
	int n = 1;
		
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%d\t", a[i][j]);
				sircle_count = count_of_1(pointer_a, i, j);
				b[i][j] = the_next_generation(pointer_a, i, j, sircle_count);
			}
			puts("\n");
		}
		puts("\n\n");
		int chek = check_last_generations(last, pointer_a);
		if (chek == 1) {
			break;
		}
		else create_new_table(last);
	}



	// заметаем следы
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			free(last[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		free(last[i]);
	}
	free(last);

#undef N
#undef M
#undef K
	return 0;
}
#endif // Life
