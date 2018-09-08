// matrixmul.c
#include "matrixmul.h"

void create_matrix_A(int input[], size_t in_size, int *arr, int *cols, int *rows)
{
  int a;
  a = 0;
  /* test for empty array */
  if(input[0] == 0 && input[1] == 0){return;}
  else
  {
    /* record the dimensions of the array */
    *cols = input[0];
    *rows = input[1];
    /* place values in array */
    for(int i = 2; i <= in_size; ++i)
    {
      arr[a] = input[i];
      ++a;
    }
    /* resize array */
    arr = (int*) realloc(arr, a);
  }
}
void print_matrix(int *arr)
{
  for(int i = 0; i < (A_n * A_k); ++i )
  {
    printf("%d", *(arr+i));
  }
  printf("\n");
}
int get_size_A(int *rows, int *cols)
{
  scanf("%d%d", &A_n, &A_k);
  return 0;
}

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
}

int main()
{
  A = (int*) malloc(MAXARRAY * sizeof(int));
  input = (int*) malloc(MAXARRAY * sizeof(int));
  B = (int*) malloc(MAXARRAY * sizeof(int));
  load_list(input, &input_size);
  create_matrix_A(input, input_size, A, &A_k, &A_n);
  //create_matrix_B();
  print_matrix(A);
  print_matrix(B);
  free(A);
  free(input);
  //get_size_A(&A_n, &A_k);
}
