SP_proj1

Project Description: Program takes as input two matrices and returns their matrix product.

Compiling Instructions: Compile with gcc.

Sample Run: 
$ cat matrices.txt
3 2
1 1
1 2
-4 0
2 3
1 2 1
3 2 1 

$ gcc -o test matrixmul.c
$ ./test < matrices.txt
3 3
4 4 2 
4 6 3 
7 6 -4 

Known Bugs: None.
