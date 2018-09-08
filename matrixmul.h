// matrixmul.h

#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define MAXARRAY 90000

int *input;
size_t input_size;

/* A_n = num rows in A
/* A_k = num cols in A
/* B_k = num rows in B
/* B_m = num cols in B
/* C_n = num rows in C
/* C_m = num cols in C
*/

struct matrix
{
  int *data;
  int rows, cols;
};

struct matrix A, B, C;
struct matrix *pA, *pB, *pC;

void create_matrix_A(int *list_in, int *matrix_out, int *cols, int *rows);
void create_matrix_B(int *list_in, int *matrix_out, int *cols, int* rows);
void print_matrix(int *arr, int cols, int rows);
void load_list(int *list_out, size_t *size);
int dimension_check(int ak, int bk);
//void matrix_multiply(int *matrix_A, int *matrix_B, int *matrix_C);

