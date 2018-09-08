// matrixmul.h
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define MAXARRAY 90000

int *A;
int *B;
int *C;
int *input;
size_t input_size;

/* A_n = num rows in A
/* A_k = num cols in A
/* B_k = num rows in B
/* B_m = num cols in B
*/

int A_n, A_k, B_k, B_m;

void create_matrix_A(int *list_in, size_t in_size, int *matrix_out, int *cols, int *rows);
//void create_matrix_B();
void print_matrix(int *arr);
int get_size_A(int *rows, int *cols);
void load_list(int *list_out, size_t *size);
