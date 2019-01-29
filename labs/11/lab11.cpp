/*********************************************************
 *  AUTHOR          : Nicholas Spector & Victor Truong
 *  Lab #11         : Intro to 2D Arrays
 *  CLASS           : CS2
 *  SECTION         : MTWR: 07:30a – 12:30p
 *  Due Date        : 01/29/19
 *********************************************************/

#include <iostream>

using namespace std;

/*******************************************************************************
* Intro to 2D Arrays
*
* Part 1:
* This program adds two matrices together and outputs it.
*
* Part 2:
* This program multiples two matrices together and outputs it.
*
* INPUT:
*
*   Part 1
*   mat1            : First addition matrix
*   mat2            : Second addition matrix
*
*   Part 2
*   mat3            : First multiplication matrix
*   mat4            : Second multiplication matrix
*
* OUTPUT:
*
*   Part 1:
*   matrixAdd()     : Outputs resulting matrix from addition
*
*   Part 2:
*   matrixMult()    : Outputs resulting matrix from multiplication
*
*
*******************************************************************************/

// Matrix sizes
const int M = 2;
const int N = 3;
const int Q = 2;
const int R = 3;
const int S = 3;

void matrixAdd(const int a[][N],          // IN: First matrix
               const int b[][N],          // IN: Second matrix
               int sum[][N]);             // IN: Array to save result in
int multiplyRowByColumn(const int a[][R], // IN: First matrix
                        const int b[][S], // IN: Second matrix
                        int row,          // IN: Row to perform multiplication on
                        int cols);        // IN: Column to perform multiplication on
void matrixMult(const int a[][R],         // IN: First matrix
                const int b[][S],         // IN: Second matrix
                int product[][S]);        // IN: Array to save result in

int main()
{
    int mat1[M][N]; // IN: Matrix A for addition
    int mat2[M][N]; // IN: Matrix B for addition
    int mat3[Q][R]; // IN: Matrix A for multiplication
    int mat4[R][S]; // IN: Matrix B for multiplication
    int sum[M][N];  // OUT: Sum of addition matrices
    int prod[Q][S]; // OUT: Product of multiplication matrices

    // PROC: Addition Input
    cout << "Enter Matrix A(size 2x3): ";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mat1[i][j];
        }
    }
    cout << "\nEnter Matrix B(size 2x3): ";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mat2[i][j];
        }
    }

    // PROC: Addition addition
    matrixAdd(mat1, mat2, sum);
    cout << "\nRes:\n";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    // PROC: Multiply Input
    cout << "Enter Matrix A(size 2x3): ";
    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cin >> mat3[i][j];
        }
    }
    cout << "\nEnter Matrix B(size 3x3): ";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cin >> mat4[i][j];
        }
    }

    // PROC: Multiply addition
    matrixMult(mat3, mat4, prod);
    cout << "\nRes:\n";
    for (int i = 0; i < Q; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cout << prod[i][j] << " ";
        }
        cout << endl;
    }

}

/*******************************************************************************
 *
 * FUNCTION matrixAdd
 *_________________________________________________________
 *
 * This function adds to matrices and saves the result into
 * sum.
 * _________________________________________________________
 * PRE-CONDITIONS
 *  a  : First matrix
 *  b  : Second matrix
 *  sum: Array to save result in
 *
 * POST-CONDITIONS
 *  Will update sum with the results of the matrix addition
 ******************************************************************************/
void matrixAdd(const int a[][N], const int b[][N], int sum[][N])
{
    // PROC: Iterates through each element and adds it
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

/*******************************************************************************
 *
 * FUNCTION matrixMult
 *_________________________________________________________
 *
 * This function multiplies a matrix by another matrix
 * _________________________________________________________
 * PRE-CONDITIONS
 *  a      : First matrix
 *  b      : Second matrix
 *  product: Array to save result in
 *
 * POST-CONDITIONS
 *  Will update sum with the results of the matrix multiplication
 ******************************************************************************/
void matrixMult(const int a[][R], const int b[][S], int product[][S])
{
    // PROC: Iterates through each element and multiples it
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            product[i][j] = multiplyRowByColumn(a, b, i, j);
        }
    }
}

/*******************************************************************************
 *
 * FUNCTION multiplyRowByColumn
 *_________________________________________________________
 *
 * This function returns a true bool if the number passed to it is prime. If it
 * is not prime, it returns false.
 *
 * _________________________________________________________
 * PRE-CONDITIONS
 *  a   : First matrix
 *  b   : Second matrix
 *  row : Row to perform multiplication on
 *  cols: Column to perform multiplication on
 *
 * POST-CONDITIONS
 *  Will return the sum of the multiplication of the specified row and column
 ******************************************************************************/
int multiplyRowByColumn(const int a[][R], const int b[][S], int row, int cols)
{
    int product; // OUT: Product of row and column
    product = 0;

    // PROC: Get product of row and column
    for (int i = 0; i < R; i++)
    {
        product += a[row][i] * b[i][cols];
    }

    return product;
}