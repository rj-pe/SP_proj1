// matrixmul.c
#include "matrixmul.h"

void create_matrix_A(int input[], int *arr, int *cols, int *rows)
{
  int a;
  a = 0;
  /* test for empty array */
  if(input[0] == 0 && input[1] == 0){return;}
  else
  {
    /* record the dimensions of the array */
    *rows = input[0];
    *cols = input[1];
    /* place values in array */
    for(int i = 2; i < (A.rows * A.cols) + 2; ++i)
    {
      arr[a] = input[i];
      ++a;
    }
    /* resize array */
    arr = (int*) realloc(arr, a);
  }
}

void create_matrix_B(int input[], int *arr, int *cols, int *rows )
{
  int b, start_b;
  b = 0;
  start_b = (A.rows * A.cols) + 2;
  *rows = input[start_b];
  *cols = input[++start_b];
  for(int i = ++start_b; i < (B.rows * B.cols) + start_b ; ++i)
  {
    arr[b] = input[i];
    ++b;
  }
  arr = (int*) realloc(arr, b);
} //end create_matrix

/* TODO: consider simply passing in the struct (e.g. C) accessing members inside of print
/*       function */
void print_matrix(int *arr, int cols, int rows)
{
  if(cols * rows == 0)
  {
    printf("%d%c%d", rows, ' ', cols);
  }
  for(int i = 0; i < (cols * rows); ++i )
  {
    printf("%d", *(arr+i));
  }
  printf("\n");
} //end print_matrix

void load_list(int *in, size_t *size)
{
  int i, value;

  /* TODO: confirm with Prof. Wang that the input will be via file redirection (include an EOF
  /* character. */

  //use scanf to load all of the values from input into an array of ints

  for(i = 0; scanf("%d", &value) != EOF; i++)
  {
    in[i] = value;
  }
  in = (int*) realloc(input, i);
  *size = (size_t) i;
} //end load_list

int dimension_check(int ak, int bk)
{
  return (ak != bk);
} //end dimension_check

int main()
{
/* using dynamic memory allocation for the arrays that hold the matrices */
  A.data = (int*) malloc(MAXARRAY * sizeof(int));
  input = (int*) malloc(MAXARRAY * sizeof(int));
  B.data = (int*) malloc(MAXARRAY * sizeof(int));
/* default value for C will be empty */
  C.data = (int*) malloc(0 * sizeof(int));
  C.rows = 0;
  C.cols = 0;
/* process the input into separate arrays */
  load_list(input, &input_size);
  create_matrix_A(input, A.data, &(A.cols), &(A.rows));
  create_matrix_B(input, B.data, &(B.cols), &(B.rows));
/* check that the dimensions of A & B are such that matrix multiplication is possible */
  if(dimension_check(A.cols, B.rows))
  {
    print_matrix(C.data, C.cols, C.rows);
    free(C.data);
    return 0;
  }
/* for debugging */
  print_matrix(A.data, A.cols, A.rows);
  print_matrix(B.data, B.cols, B.rows);
/* TODO: implement the multilpication procedure */
  //matrix_multiply(pA, pB, pC);

/* release the memory allocated for the arrays */
  free(A.data);
  free(B.data);
  free(input);
}
