// matrixmul.c
#include "matrixmul.h"

/* Takes integers stored in the input array and organizes them in a matrix struct */
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
    /* TODO: Ask Prof. Wang regarding realloc, why am I leaking memory below? */
    /* one idea is to return the new size and realloc in main()  */
    /* resize array */
//    arr = (int*) realloc(arr, a * sizeof(int));
  }
}//end create_matrix

/* Takes integers stored in the input array and organizes them in a matrix struct */
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
  /* TODO: Ask Prof. Wang regarding realloc, why am I leaking memory below? */
//  arr = (int*) realloc(arr, b * sizeof(int));
} //end create_matrix

/* Prints the dimensions and members of the matrix */
void print_matrix(struct matrix p)
{
  if(p.cols * p.rows == 0)
  {
    printf("%d%c%d", p.rows, ' ', p.cols);
  }
  else
    printf("%d%c%d\n", p.rows, ' ', p.cols);
    for(int i = 0; i < (p.cols * p.rows); ++i )
    {
      printf("%d%c", p.data[i], ' ');
      if((i+1) % p.cols == 0)
      {
	printf("\n");
      }
    }
    printf("\n");
} //end print_matrix

/* Takes integers from stdin and loads them into an array */
void load_list(int *in, size_t *size)
{
  int i, value;

  /* TODO: confirm with Prof. Wang that the input will be via file redirection */
  /* (include an EOF character. */

  //use scanf to load all of the values from input into an array of ints
  for(i = 0; scanf("%d", &value) != EOF; i++)
  {
    in[i] = value;
  }
  /* TODO: Ask Prof. Wang regarding realloc, why am I leaking memory below */
//  in = (int*) realloc(input, i * sizeof(int));
  *size = (size_t) i;
} //end load_list

/* ensures that the dimensions of the two matrices match */
int dimension_check(int ak, int bk)
{
  return (ak != bk);
} //end dimension_check

/* Computes the matrix product, C, of two matrices, A, & B. */
void matrix_multiply(struct matrix Am, struct matrix Bm, struct matrix *Cm)
{
  /* initialize counters */
  int cell = 0;
  int sum = 0;
  int A_i = 0;
  int B_i = 0;
  
  /* fill in each cell of matrix C */
  for(int row_C = 0; row_C < C.rows; row_C++)
  {
    for(int width = 0; width < C.cols; cell++)
    {
      for(int i = A_i; i < (A_i + Am.cols); i++)
      {
	B_i = (cell % C.cols) + C.cols * (i % A.cols);
	sum += Am.data[i] * Bm.data[B_i];
	B_i = 0;
      }
      if(cell <= (C.rows * C.cols))
      {
	C.data[cell] = sum;
      }
      else
	printf("ERROR @ : %d\n", cell);
      sum = 0;
      width++;
    }
    A_i += Am.cols;
  }  
}//end matrix_multiply

int main()
{
/* dynamic memory allocation for the array that holds input */
  input = (int*) malloc(MAXARRAY * sizeof(int));

/* default value for C will be empty */
  C.rows = 0;
  C.cols = 0;

/* process the input into an array, record its size */
  load_list(input, &input_size);

/* dynamic memory allocation for arrays that hold the matrices */
  A.data = (int*) malloc((input_size/2) * sizeof(int));  
  B.data = (int*) malloc((input_size/2) * sizeof(int));

/* process the input data into matrix structs */
  create_matrix_A(input, A.data, &(A.cols), &(A.rows));
  create_matrix_B(input, B.data, &(B.cols), &(B.rows));

/* check that the dimensions of A & B are such that matrix multiplication is possible */
  if(dimension_check(A.cols, B.rows))
  {
    print_matrix(C);
    return 0;
  }

/* for debugging purposes */
/*  print_matrix(A); */
/*  print_matrix(B); */

/* allocate memory for matrix C */
  C.data = (int*) malloc((A.rows * B.cols) * sizeof(int));
  C.rows = A.rows;
  C.cols = B.cols;

/* carry out the multiplication and print the matrix */  
  matrix_multiply(A, B, pC);
  print_matrix(C);

/* release allocated memory */
  free(A.data);
  free(B.data);
  free(input);
  free(C.data);
} //end main
