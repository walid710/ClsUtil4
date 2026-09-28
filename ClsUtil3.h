#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

//-----------------------
#include "ClsUtil1.h"
#include "ClsUtil2.h"

using namespace std;


class ClsUtil3
{

private:



public:


    //[1]_3*3 Random Matrix
    static string Taps(string Tap, short NumberOfTap)
    {
        string M = "";
        for (int i = 1; i <= NumberOfTap;i++)
        {
            M += Tap;
        }
        return M;
    }
    static void FillMatrixWithRondomNumbers(int arr[3][3], short Row, short Cols)
    {

        for (short i = 0;i < Row;i++)
        {
            for (short j = 0;j < Cols;j++)
            {
                arr[i][j] = ClsUtil2::RandomNumber(1, 100);
            }
        }
    }
    static void PrintMatrix(int arr[3][3], short Rows, short Cols)
    {
        //system("color 9F");
        cout << Taps("\n", 1) << Taps("\t     ", 2);
        cout << "[Matrix : " << Rows << "x" << Cols << "]\n";
        cout << Taps("\n", 0) << Taps("\t", 2);
        cout << "|-----------------------------|\n";
        for (int i = 0;i < Rows;i++)
        {
            cout << Taps("\n", 0) << "\t        |";
            for (int j = 0;j < Cols;j++)
            {
                cout << setw(5);
                printf("   %0*d",2, arr[i][j]);
                cout << "|";
            }
            cout << Taps("\n", 1) << Taps("\t", 2);
            cout << "|-----------------------------|";
            cout << endl;
        }
    }
    static void Print3X3RandomMatrix()
    {
        int arr[3][3];
        FillMatrixWithRondomNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 random matrix : \n";
        PrintMatrix(arr, 3, 3);
    }
    //-------------------------------------------------------------------------

    //[2]_Sum Each Row In Matrix
    static int RowSum(int arr1[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;
        for (int i = 0;i <= Cols-1;i++)
        {
            Sum += arr1[RowNumber][i];
        }
        return  Sum;
    }
    static void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
    {
        cout << "\nThe following are the sum of each row in the Matrix : \n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0;i < Rows;i++)
        {
            cout << "Row" << i + 1 << " Sum = ";
            cout << RowSum(arr,i,Cols);
            cout << endl;
        }
    }
    static void PrintSumEachRowInMatrix()
    {
        int arr[3][3];
        FillMatrixWithRondomNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 random matrix : \n";
        PrintMatrix(arr, 3, 3);
        PrintEachRowSum(arr, 3, 3);
    }
    //-------------------------------------------------------------------------

    //[3]_Sum Each Row In Matrix In Array
    static void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
    {
        for (int i = 0;i < Rows;i++)
        {
            arrSum[i] = RowSum(arr, i, Cols);
        }
    }
    static void PrintRowsSumArray( int arrSum[3], short arrLength)
    {
        cout << "\nThe following are the Sum of Eash Row in the Matrix :\n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0;i < arrLength;i++)
        {
            cout << " Row" << i + 1 << " Sum = " << arrSum[i];
            cout << endl;
        }
    }
    static void PrintSumEachRowInMatrixInArray()
    {
        int arr[3][3];
        int arrSum[3];
        FillMatrixWithRondomNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 random matrix : \n";
        PrintMatrix(arr, 3, 3);
        SumMatrixRowsInArray(arr, arrSum, 3,3);
        PrintRowsSumArray(arrSum, 3);
    }
    //-------------------------------------------------------------------------

    //[4]_Sum Each Col In Matrix
    static int ColSum(int arr[3][3], short Rows , short ColNumber)
    {
        int Sum = 0;
        for (int i = 0;i <= Rows - 1;i++)
        {
            Sum += arr[i][ColNumber];
        }
        return  Sum;
    }
    static void PrintEachColSum(int arr[3][3], short Rows, short Cols)
    {
        cout << "\nThe following are the sum of each col in the Matrix : \n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0;i < Cols;i++)
        {
            cout << "Col" << i + 1 << " Sum = ";
            cout << ColSum(arr, Rows,i);
            cout << endl;
        }
    }
    static void PrintSumEachColInMatrix()
    {
        int arr[3][3];
        FillMatrixWithRondomNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 random matrix : \n";
        PrintMatrix(arr, 3, 3);
        PrintEachColSum(arr, 3, 3);
    }
    //-------------------------------------------------------------------------

    //[5]_Sum Each Col In Matrix In Another Array
    static void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
    {
        for (int i = 0;i < Cols;i++)
        {
            arrSum[i] = ColSum(arr,Rows, i);
        }
    }
    static void PrintColsSumArray(int arrSum[3], short arrLength)
    {
        cout << "\nThe following are the Sum of Eash Col in the Matrix :\n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0;i < arrLength;i++)
        {
            cout << " Col" << i + 1 << " Sum = " << arrSum[i];
            cout << endl;
        }
    }
    static void PrintSumEachColInMatrixInArray()
    {
        int arr[3][3];
        int arrSum[3];
        FillMatrixWithRondomNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 random matrix : \n";
        PrintMatrix(arr, 3, 3);
        SumMatrixColsInArray(arr, arrSum, 3, 3);
        PrintColsSumArray(arrSum, 3);
    }

    //-------------------------------------------------------------------------

    //[6]_3*3 Order Matrix
    static void FillMatrixWithOrderNumbers(int arr[3][3], short Rows, short Cols)
    {
        int Counter = 0;
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                Counter++;
                arr[i][j] = Counter;
            }
        }
    }
    static void Print3X3OrderMatrix()
    {
        int arr[3][3];
        FillMatrixWithOrderNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 Ordered Matrix : \n ";
        PrintMatrix(arr, 3, 3);
       
    }
    //-------------------------------------------------------------------------

    //[7]_Traspose Matrix
    static void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Row, short Cols)
    {
        for (int i = 0;i < Row;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                arrTransposed[i][j] = arr[j][i];
            }
        }
    }
    static void PrintTrasposedMatrix()
    {
        int arr[3][3]; //={ {1,2,3},{4,5,6},{7,8,9} };    
        int arrTransposed[3][3];
        FillMatrixWithOrderNumbers(arr, 3, 3);
        cout << "\nThe following is a 3x3 Ordered Matrix : \n ";
        PrintMatrix(arr, 3, 3);
        TransposeMatrix(arr, arrTransposed, 3, 3);
        cout << "\nThe following is the Trasposed Matrix : \n ";
        PrintMatrix(arrTransposed, 3, 3);

    }
    //-------------------------------------------------------------------------

    //[8]_Multiply Two Matrices
    static void MaltiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Row, short Cols)
    {
        for (int i = 0;i < Row;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
            }
        }
    }
    static void PrintMultiplyTwoMatrices()
    {
        int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];
       
        FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        FillMatrixWithRondomNumbers(Matrix2, 3, 3);
        cout << "\nMatrix2 : \n ";
        PrintMatrix(Matrix2, 3, 3);
        MaltiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);
        cout << "\nThe following is the Trasposed Matrix : \n ";
        PrintMatrix(MatrixResults, 3, 3);

    }
    //-------------------------------------------------------------------------

    //[9]_Print Middle Row and Col of Matrix
    static void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MiddleRow = Rows / 2;
        for (int i = 0; i < Cols;i++)
        {
            printf("  %0*d  ", 2, arr[MiddleRow][i]);
        }
        cout << endl;
    }
    static void PrintMiddleColsOfMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MiddleCol  = Cols / 2;
        for (int i = 0; i < Rows;i++)
        {
            printf("  %0*d  ", 2, arr[i][MiddleCol]);
        }
        cout << endl;
    }
    static void PrintMiddleRowAndColOfMatrix()
    {
        int Matrix1[3][3];
        FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        cout << "\nMiddle Row of Matrix1 is : \n";
        cout << "-------------------\n";
        PrintMiddleRowOfMatrix(Matrix1, 3, 3);
        cout << "\nMiddle Col of Matrix1 is : \n";
        cout << "-------------------\n";
        PrintMiddleColsOfMatrix(Matrix1, 3, 3);
       
    }
    //-------------------------------------------------------------------------

    //[10]_Sum Of Matrix
    static  int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Sum = 0;
        for (short i = 0;i < Rows;i++)
        {
            for (short j = 0;j < Cols;j++)
            {
                Sum += Matrix1[i][j];
            }
        }
        return Sum;
    }
    static void PrintSumOfMatrix()
    {
        int Matrix1[3][3];
        FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        cout << "\nSum of Matrix1 is : [ " << SumOfMatrix(Matrix1, 3, 3) << " ]." << endl;
    }
    //-------------------------------------------------------------------------

    //[11]_Check Matrices Equality
    static bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {

        return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));

    }
    static void PrintCheckMatricesEquality()
    {
        int Matrix1[3][3] , Matrix2[3][3];
        FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        cout << "\nSum of Matrix1 is : [ " << SumOfMatrix(Matrix1, 3, 3) << " ]." << endl;

        FillMatrixWithRondomNumbers(Matrix2, 3, 3);
        cout << "\nMatrix2 : \n ";
        PrintMatrix(Matrix2, 3, 3);
        cout << "\nSum of Matrix2 is : [ " << SumOfMatrix(Matrix2, 3, 3) << " ]." << endl;

        if (AreEqualMatrices(Matrix1, Matrix2, 3, 3))
        {
            cout << "\nYes : both Matrices are equal .\n";
        }
        else
        {
            cout << "\nNo :  Matrices are Not equal .\n";
        } 
    }
    //-------------------------------------------------------------------------

    //[12]_Check Typical Matrices
    static bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (short i = 0;i < Rows;i++)
        {
            for (short j = 0;j < Cols;j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                {
                    return  false;
                }
            }
        }
        return true;

    }
    static void PrintCheckTypicalMatrices()
    {
        int Matrix1[3][3], Matrix2[3][3];
        //FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        FillMatrixWithOrderNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        //FillMatrixWithRondomNumbers(Matrix2, 3, 3);
        FillMatrixWithOrderNumbers(Matrix2, 3, 3);
        cout << "\nMatrix2 : \n ";
        PrintMatrix(Matrix2, 3, 3);
        if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
        {
            cout << "\nYes : both Matrices are Typical .\n";
        }
        else
        {
            cout << "\nNo :  Matrices are Not Typical .\n";
        }
    }
    //-------------------------------------------------------------------------

    //[13]_Check Identity Matrix
    static bool IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        //check Diagonal elements are 1 and rest elements are 0.
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                //check for diagonals element
                if (i == j && Matrix1[i][j] != 1)
                {
                    return false;
                }
                //check for rest elements
                else if (i != j && Matrix1[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    static void PrintCheckIdentityMatrix()
    {
        int Matrix1[3][3] = { {1,0,0},{1,1,0},{0,0,1} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);

        if (IsIdentityMatrix(Matrix1, 3, 3))
        {
            cout << "\nYes : Matrix is identity .\n";
        }
        else
        {
            cout << "\nNo :  Matrices is Not identity .\n";
        }
    }
    //-------------------------------------------------------------------------

    //[14]_Check Scalar Matrix
    static bool IsScalarMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int FirstDiagElement = Matrix1[0][0];
        //check Diagonal elements are 1 and rest elements are 0.
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                //check for diagonals element
                if (i == j && Matrix1[i][j] != FirstDiagElement)
                {
                    return false;
                }
                //check for rest elements
                else if (i != j && Matrix1[i][j] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    static void PrintCheckScalarMatrix()
    {
        int Matrix1[3][3] = { {1,0,0},{0,3,0},{0,0,1} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);

        if (IsScalarMatrix(Matrix1, 3, 3))
        {
            cout << "\nYes : Matrix is Scalar .\n";
        }
        else
        {
            cout << "\nNo :  Matrices is Not Scalar .\n";
        }
    }
    //-------------------------------------------------------------------------

    //[15]_Count Number In Matrix
    static short CountNumberInMatrix(int arr1[3][3], short Number, short Rows, short Cols)
    {
        short NumberCount = 0;
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                if (arr1[i][j] == Number)
                {
                    NumberCount++;
                }
            }
        }
        return NumberCount;
    }
    static void PrintCountNumberInMatrix()
    {
        int Matrix1[3][3] = { {1,0,0},{0,3,0},{0,0,1} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        int Number = 0;
        cout << "\nEnter the number to count in matrix ? =>";
        cin >> Number;
        cout << "\nNumber [" << Number << "] count in matrix is : " << CountNumberInMatrix(Matrix1,Number, 3, 3) << endl;  
    }
    //-------------------------------------------------------------------------

    //[16]_Check Sparse Matrix
    static bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        short MarixSize = Rows * Cols;
        return (CountNumberInMatrix(Matrix1, 0, Rows, Cols) >= (MarixSize / 2));
    }
    static void PrintCheckSparseMatrix()
    {
        int Matrix1[3][3] = { {1,1,0},{0,3,0},{1,1,1} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        if (IsSparseMatrix(Matrix1, 3, 3))
        {
            cout << "\nYes : is Sparse .\n";
        }
        else
        {
            cout << "\nNo : is Not Sparse .\n";
        }
    }
    //-------------------------------------------------------------------------

    //[17]_Number Exists In Matrix
    static bool IsNumberInMatrix(int Matrix1[3][3], short Number, short Rows, short Cols)
    {
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                if (Matrix1[i][j] == Number)
                {
                    return true;
                }
            }
        }
        return false;
    }
    static void PrintNumberExistsInMatrix()
    {
        int Matrix1[3][3] = { {1,0,0},{0,3,0},{0,0,1} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        int Number = 0;
        cout << "\nEnter the number to Look for in matrix ? =>";
        cin >> Number;
        if (IsNumberInMatrix(Matrix1,Number, 3, 3))
        {
            cout << "\nYes : it is there.\n";
        }
        else
        {
            cout << "\nNo : it is Not there.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[18]_Intersected Number In Matrices
    static void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        short Number = 0;
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                Number = Matrix1[i][j];
                if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
                {
                    cout <<setw(3)<< Number << "    ";
                }
            }
        }
        cout << "\n";
    }
    static void PrintIntersectedNumberInMatrices()
    {
        int Matrix1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
        int Matrix2[3][3] = { {1,5,6},{8,3,6},{10,4,7} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        cout << "\nMatrix2 : \n ";
        PrintMatrix(Matrix2, 3, 3);
        cout << "\nIntersected Number are : \n\n";
        PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3); 
    }
    //-------------------------------------------------------------------------

    //[19]_Min/Max Number In Matrix
    static int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Min = Matrix1[0][0];
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                if (Matrix1[i][j] < Min)
                {
                    Min = Matrix1[i][j];
                }
            }
        }
        return Min;
    }
    static int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Max = Matrix1[0][0];
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols;j++)
            {
                if (Matrix1[i][j] > Max)
                {
                    Max = Matrix1[i][j];
                }
            }
        }
        return Max;
    }
    static void PrintMinAndMaxNumberInMatrix()
    {
        int Matrix1[3][3] ;
        FillMatrixWithRondomNumbers(Matrix1, 3, 3);
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        cout << "\nMinimum Number is : ";
        cout << MinNumberInMatrix(Matrix1, 3, 3) << endl;
        cout << "Maximum Number is : ";
        cout << MaxNumberInMatrix(Matrix1, 3, 3) << endl;
    }
    //-------------------------------------------------------------------------

    //[20]_Palindrome Matrix
    static bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        for (int i = 0;i < Rows;i++)
        {
            for (int j = 0;j < Cols / 2;j++)
            {
                if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    static void PrintPalindromeMatrix()
    {
        int Matrix1[3][3] = { {1,2,1},{4,5,4},{7,8,7} };
        cout << "\nMatrix1 : \n ";
        PrintMatrix(Matrix1, 3, 3);
        if (IsPalindromeMatrix(Matrix1, 3, 3))
        {
            cout << "\nYes : Matrix  is Palindrome.\n";
        }
        else
        {
            cout << "\nNo : Matrix is Not Palindrome.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[21]_Fibonacci Series With Loop
    static void PrintFibonacciUsingLoop(short Number)
    {
        int FebNumber = 0;
        int Prev2 = 0, Prev1 = 1;
        cout << "\n1   ";
        for (short i = 2;i <= Number;i++)
        {
            FebNumber = Prev1 + Prev2;
            cout << FebNumber << "    ";
            Prev2 = Prev1;
            Prev1 = FebNumber;
        }
        cout << "\n\n";
    }
    //-------------------------------------------------------------------------

    //[22]_Fibonacci Series With Recursion
    static void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
    {
        int FebNumber = 0;
        if (Number > 0)
        {
            FebNumber = Prev1 + Prev2;
            Prev2 = Prev1;
            Prev1 = FebNumber;
            cout << FebNumber << "    ";
            PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
        }  
    }
    //-------------------------------------------------------------------------
    
      //-------------------------------------------------------------------------//
     //                  [This Is All Functions of String]                      // 
    //-------------------------------------------------------------------------//

    //[23]_Print First Letter Of Each Word
    static string ReadString()
    {
        string S1;
        cout << "please Enter your string? => ";
        getline(cin>>ws, S1);
        return S1;
    }
    static void PrintFirstLetterFromEachWord(string S1)
    {
        bool isFirstLetter = true;
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "First Letters of this string : \n";
        cout << "-------------------------------------\n";
        for (short i = 0;i < S1.length();i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                cout <<" => " << S1[i] << endl;
            }
            isFirstLetter = (S1[i] == ' ' ? true : false);
        }
        cout << "-------------------------------------\n";

    }
    //-------------------------------------------------------------------------

    //[24]_Upper First Letter Of Each Word
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0;i < S1.length();i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }

            isFirstLetter = S1[i] == ' ' ? true : false;
        }
        return S1;
    }
    static void PrintUpperFirstLetterOfEachWord()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "\nString After Conversion  : \n";
        cout << "-------------------------------------\n";
        S1 = UpperFirstLetterOfEachWord(S1);
        cout << "\nThe String is : [ " << S1 << " ].\n";
    }
    //-------------------------------------------------------------------------

    //[25]_Lower First Letter Of Each Word
    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0;i < S1.length();i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }

            isFirstLetter = S1[i] == ' ' ? true : false;
        }
        return S1;
    }
    static void PrintLowerFirstLetterOfEachWord()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "\nString After Conversion  : \n";
        cout << "-------------------------------------\n";
        S1 = LowerFirstLetterOfEachWord(S1);
        cout << "\nThe String is : [ " << S1 << " ].\n";
    }
    //-------------------------------------------------------------------------

    //[26]_Upper/Lower All Letters Of a String 
    static string LowerAllString(string S1)
    {
        for (short i = 0;i < S1.length();i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }
    static string UpperAllString(string S1)
    {
        for (short i = 0;i < S1.length();i++)
        {
             S1[i] = toupper(S1[i]);
        }
        return S1;
    }
    static void PrintUpper_LowerAllLettersOfString()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "\nString After Upper  : \n";
        cout << "-------------------------------------\n";
        S1 = UpperAllString(S1);
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "\nString After Lower  : \n";
        cout << "-------------------------------------\n";
        S1 = LowerAllString(S1);
        cout << "\nThe String is : [ " << S1 << " ].\n";
    }
    //-------------------------------------------------------------------------

    //[27]_Invert Charcter Case 
    static char ReadChar()
    {
        char S1;
        cout << "please enter a character ? => ";
        cin >> S1;
        return S1;
    }
    static char InvertLetterCase(char Char1)
    {
        return isupper(Char1) ? tolower(Char1) : toupper(Char1);
    }
    static void PrintInvertCharcterCase()
    {
        char Ch1 = ReadChar();
        cout << "\nThe Char is : [ " << Ch1 << " ].\n";
        cout << "Char after Inverting Case : \n";
        cout << "-------------------------------------\n";
        Ch1 = InvertLetterCase(Ch1);
        cout << "The Char is : [ " << Ch1 << " ].\n";
    }
    //-------------------------------------------------------------------------

    //[28]_Invert All Letters Case
    static string InvertAllStringLettersCase(string S1)
    {
        for (short i = 0;i < S1.length();i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return  S1;
    }
    static void PrintInvertAllLettersCase()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "String after Inverting All Letter  Case : \n";
        cout << "-------------------------------------\n";
        S1 = InvertAllStringLettersCase(S1);
        cout << "The String is : [ " << S1 << " ].\n";

    }
    //-------------------------------------------------------------------------

    //[29]_Count Small/Capital Letters
    enum enWhatToCount { SmallLetter = 0, CapitalLetter = 1,All=3 };
    static short CounterLetters(string S1, enWhatToCount WhatToCount= enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }
        else if (WhatToCount == enWhatToCount::CapitalLetter)
        {
            return CountCapitalLetters(S1);
        }
        else if (WhatToCount == enWhatToCount::SmallLetter)
        {
            return CountSmallLetters(S1);
        }
           
    }
    static short CountSmallLetters(string S1)
    {
        short Counter= 0;
        for (short i = 0;i <= S1.length();i++)
        {
            if (islower(S1[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }
    static short CountCapitalLetters(string S1)
    {
        short Counter = 0;
        for (short i = 0;i <= S1.length();i++)
        {
            if (isupper(S1[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountSmall_CapitalLetters()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "\nThe Length is : [ " << CounterLetters(S1) << " ].\n";
        cout << "\nCapital Letters Count : [ " << CounterLetters(S1, enWhatToCount::CapitalLetter) <<" ]." << endl;
        cout << "-------------------------------------\n";
        cout << "Small Letters Count   : [ " << CounterLetters(S1, enWhatToCount::SmallLetter) << " ]." << endl;

    }
    //-------------------------------------------------------------------------

    //[30]_Count Letters 
    static short CountLetter(string S1, char Letter,bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0;i < S1.length();i++)
        {
            if (MatchCase)
            {
                if (S1.at(i) == Letter)
                {
                    Counter++;
                }
            }
            else
            {
                if (tolower(S1.at(i)) == tolower(Letter))
                {
                    Counter++;
                }
            }
        }
        return Counter;
    }
    static void PrintCountLetters()
    {
        string S1 = ReadString();
        char Ch1 = ReadChar();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        cout << "Letter \'" << Ch1 << "\' Count : [ " << CountLetter(S1,Ch1) <<" ]." << endl;
    }
    //-------------------------------------------------------------------------

    //[31]_Count Letters Match Case
    static void PrintCountLetters_MatchCase()
    {
        string S1 = ReadString();
        char Ch1 = ReadChar();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        cout << "Letter \'" << Ch1 << "\' Count : [ " << CountLetter(S1, Ch1) << " ]." << endl;
        cout << "-------------------------------------\n";
        cout << "\nLetter \'" << Ch1 << "\' or \'" << InvertLetterCase(Ch1) << "\' Count : [ " << CountLetter(S1, Ch1,false) << " ]." << endl;
    }
    //-------------------------------------------------------------------------

    //[32]_Is Vowel
    static bool  IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
    }
    static void PrintIsVowel()
    {
        char Ch1 = ReadChar();
        if(IsVowel(Ch1))
        {
            cout << "\nYes, Letter \'" << Ch1 << "\' is vowel." << endl;
        }
        else
        {
            cout << "\nNo, Letter \'" << Ch1 << "\' is Not vowel." << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[33]_Count Vowels
    static short CountVowels(string S1)
    {
        short Counter = 0;
        for (short i = 0;i < S1.length();i++)
        {
            if (IsVowel(S1[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountVowels()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        cout << "Number of vowels is : [ " << CountVowels(S1) << " ]." << endl;
        cout << "-------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[34]_Print All Vowels In String
    static void PrintVowels(string S1)
    {
        cout << "\nVowels in string are : [ ";
        for (short i = 0;i < S1.length();i++)
        {   
            if (IsVowel(S1[i]))
            {
                cout << S1[i];
                cout << " ";
            }   
        }
        cout << "].\n";
    }
    static void PrintAllVowelsInString()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------";
        PrintVowels(S1);
        cout << "-------------------------------------\n";
        cout << "Number of vowels is : [ " << CountVowels(S1) << " ]." << endl;
    }
    //-------------------------------------------------------------------------

    //[35]_Print Each Word In String 
    static void  PrintEachWordInString(string S1)
    {
        string delim = " "; //delimiter.
        cout << "Your string Words are : \n";
        short pos = 0;
        string sWord; //define a string variable
        //using .find() function to get the position of the delimiter
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //store the word.     
            if (sWord != "")
            {
                cout << sWord << endl;
            }
            //.erase() until position and move to next Word.    
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            //it print last word of the string.
            cout << S1 << endl;
        }
    }
    static void PrintAllWordInString()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        PrintEachWordInString(S1);
    }
    //-------------------------------------------------------------------------

    //[36]_Coutn Each Word In String
    static short  CountWords(string S1)
    {
        string delim = " "; //delimiter
        short counter = 0;
        short pos = 0;
        string sWord; //define a string variable
        //using .find() function to get the position of the delimiter
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //store the word      
            if (sWord != "")
            {
                counter++;
            }
            //.erase() until position and move to next Word.  
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            //it Counts last word of the string
            counter++;
        }
        return counter;
    }
    static void PrintCoutnEachWordInString()
    {
        string S1 = ReadString();
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        PrintEachWordInString(S1);
        cout << "-------------------------------------\n";
        cout << "The Number of Words in your string is : " << CountWords(S1) << endl;
    }
    //-------------------------------------------------------------------------

    //[37]_Split String
    static vector<string> SplitString(string S1, string Delim)
    {
        vector<string>vString;
        short pos = 0;
        string sWord; //define a string variable
        //using .find() function to get the position of the delimiter.
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); //store the word.      
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            //.erase() until position and move to next Word.  
            S1.erase(0, pos + Delim.length());
        }
        if (S1 != "")
        {
            //it adds last word of the string.
            vString.push_back(S1);
        }
        return vString;
    }
    static void PrintStringVector(vector<string>& vString)
    {
        for (string& S : vString)
        {
            cout << S << endl;
        }
    }
    static void PrintSplitString()
    {
        string S1 = ReadString();
        vector<string>vString = SplitString(S1,"<||>");
        cout << "\nThe String is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        cout << "Tokens = " << vString.size() << endl;
        PrintStringVector(vString);
        cout << "-------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[38]_TrimLeft And TrimRight And Trim
    static string TermLeft(string S1)
    {
        for (short i = 0;i < S1.length();i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - 1);
            }
        }
        return "";
    }
    static string TermRight(string S1)
    {
        for (short i = S1.length()-1;i >= 0;i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }
    static string Term(string S1)
    {
        return (TermLeft(TermRight(S1)));
    } 
    static void PrintTrimLeftAndTrimRightAndTrim()
    {
        string S1 = "   Walid Amer Attia Mohamed   ";
        cout << "\nThe String is = [" << S1 << "].\n";
        cout << "-------------------------------------\n";
        cout << "Term Left     = [" << TermLeft(S1) <<"]." << endl;
        cout << "Term Right    = [" << TermRight(S1) << "]." << endl;
        cout << "Term          = [" << Term(S1) << "]." << endl;
        cout << "-------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[39]_Join String
    static string JoinString(vector<string>& vString, string Delim)
    {
        string S1 = "";
        for (string& S : vString)
        {
           S1 += S + Delim;
        }
        return   S1.substr(0, S1.length() - Delim.length());
    }
    static void PrintJoinString()
    {
        vector<string>vString = { "Walid","Amer","Attia","Mohemmed"};
        cout << "\nThe Vector is : \n";
        cout << "-------------------------------------\n";
        PrintStringVector(vString);
        cout << "-------------------------------------\n";
        cout << "vector after join : \n";
        cout << JoinString(vString, "<||>") << endl;
    }
    //-------------------------------------------------------------------------

    //[40]_Join String OverLooding
    static string JoinString(string arrString[], short Length , string Delim)
    {
        string S1 = "";
        for (short i = 0;i < Length;i++)
        {
            S1 += arrString[i] + Delim;
        }
        return   S1.substr(0, S1.length() - Delim.length());
    }
    static void PrintStringArray(string arrString[],short Length)
    {
        for (short i = 0;i < Length;i++)
        {
            cout << arrString[i] << endl;
        }
    }
    static void PrintJoinStringOverLooding()
    {
        vector<string>vString = { "Walid","Amer","Attia","Mohemmed" };
        string arrString[] = { "Walid","Amer","Attia","Mohemmed" };
        cout << "\nThe Vector is : \n";
        cout << "-------------------------------------\n";
        PrintStringVector(vString);
        cout << "-------------------------------------\n";
        cout << "vector after join : \n";
        cout << JoinString(vString, "<||>") << endl;
        cout << "\nThe Array is : \n";
        cout << "-------------------------------------\n";
        PrintStringArray(arrString,4);
        cout << "-------------------------------------\n";
        cout << "Array after join : \n";
        cout << JoinString(arrString,4, "<||>") << endl;
    }
    //-------------------------------------------------------------------------

    //[41]_Reverse Words
    static string  ReverseWordsInString(string S1)
    {
        vector<string>vString = SplitString(S1, " ");
        string S2 = "";
        //declare iterator.
        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        //Remove last space.
        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }
    static void PrintReverseWords()
    {
        string S1 = ReadString();
        cout << "\nThe String before reversing word is : [ " << S1 << " ].\n";
        cout << "-------------------------------------\n";
        cout << "The String after reversing word is  : [ " << ReverseWordsInString(S1) << " ].\n";
        cout << "-------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[42]_Replace Words
    static string ReplaceWordInStringUsingBuiltFunction(string S1, string StringToReplace, string sReplaceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
            pos = S1.find(StringToReplace); //find to next
        }
        return S1;
    }
    static string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
    {
        return ReplaceWordInStringUsingBuiltFunction(S1, StringToReplace, sReplaceTo);
    }
    static string ReadString(string Message)
    {
        string S1;
        cout << Message << " = > ";
        getline(cin >> ws, S1);
        return S1;
    }
    static void PrintReplaceWords()
    {
        string S1 = "Walid Amer Attia Mohammed";
        cout << "\nOriginal String      : [ " << S1 << " ].\n";
        string StringToReplace = ReadString("please enter the word To Changing Or Replacing ?");
        string ReplaceTo = ReadString("please enter New Word to Replacing ?");
        cout << "-------------------------------------\n";
        cout << "\nString After Replace : [ " 
             << ReplaceWordInStringUsingBuiltFunction(S1, StringToReplace, ReplaceTo) << " ].\n";  
    }
    //-------------------------------------------------------------------------

    //[43]_Replace Words Custom
    static string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
    {
        vector<string>vString = SplitString(S1, " ");
        for (string& S : vString)
        {
            if (MatchCase)
            {
                if (S == StringToReplace)
                {
                    S = sReplaceTo;
                }
            }
            else
            {

                if (LowerAllString(S) == LowerAllString(StringToReplace))
                {
                    S = sReplaceTo;
                }
            }
        }
        return JoinString(vString, " ");
    }
    static void PrintReplaceWordsCustom()
    {
        string S1 = "Walid Amer Attia Mohammed";
        cout << "\nOriginal String      : [ " << S1 << " ].\n";
        string StringToReplace = ReadString("please enter the word To Changing Or Replacing ?");
        string ReplaceTo = ReadString("please enter New Word to Replacing ?");
        cout << "-------------------------------------\n";
        cout << "\nReplace with Match case      : [ "
            << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo) << " ].\n";
        cout << "-------------------------------------\n";
        cout << "\nReplace with dont Match case : [ "
            << ReplaceWordInStringUsingSplit(S1, StringToReplace, ReplaceTo,false) << " ].\n";
    }
    //-------------------------------------------------------------------------
  
    //[44]_Remove Punctuations
    static string RemovePunctuationFromString(string S1)
    {
        string S2 = "";
        for (short i = 0;i < S1.length();i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }  
        }
        return   S2;
    }
    static void PrintRemovePunctuations()
    {
        string S1 = "Walid , Ame@r _ At%tia .<> Mohammed.";
        cout << "\nOriginal String      : [ " << S1 << " ].\n";
        cout << "Punctuations Removed : [ " << RemovePunctuationFromString(S1) << " ].\n";

    }
    //-------------------------------------------------------------------------

    //[45]_Convert Record To Line
    struct stClient
    {
        string AccountNumber = "";
        string PinCode = "";
        string Name = "";
        string phone = "";
        double AccountBalance = 0;
        bool MarkForDelete = false;
    };
    static stClient ReadNewClient()
    {
        stClient Client;
        cout << "\n-------------------------------------\n";
        cout << "plesea enetr Account Number ? => ";
        //usage of std::ws will extract allthe whitespace character.
        getline(cin >> ws, Client.AccountNumber);
        cout << "plesea enetr Pin Code ? => ";
        getline(cin,Client.PinCode);
        cout << "plesea enetr Name ? => ";
        getline(cin , Client.Name);
        cout << "plesea enetr phone ? => ";
        getline(cin, Client.phone);
        cout << "plesea enetr Account Balance ? => ";
        cin >> Client.AccountBalance;
        cout << "\n-------------------------------------\n";
        return Client;
    }
    static string ConvertRecordToLine(stClient Client, string Seperator = "<||>")
    {
        string stClientRecord = "";
        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += Client.Name + Seperator;
        stClientRecord += Client.phone + Seperator;
        stClientRecord += to_string(Client.AccountBalance);
        return stClientRecord;
    }
    static void PrintConvertRecordToLine()
    {
        cout << "\nplease enter Client Data : ";
        cout << "\n-------------------------------------\n";
        stClient Client;
        Client = ReadNewClient();
        cout << "\nClient Record for saving is : \n";
        cout << "-------------------------------------\n";
        string S1 = ConvertRecordToLine(Client);
        cout << S1 << endl;
    }
    //-------------------------------------------------------------------------

    //[46]_Convert Line Data To Record
    static void PrintClientCard(stClient Client)
    {
        cout << "the following is the extracted client record :\n";
        cout << "-------------------------------------\n";
        cout << "Account Number  : " << Client.AccountNumber << endl;
        cout << "PinCode         : " << Client.PinCode << endl;
        cout << "Name            : " << Client.Name << endl;
        cout << "phone           : " << Client.phone << endl;
        cout << "Account Balance : " << Client.AccountBalance << endl;
        cout << "-------------------------------------\n";
    }
    static stClient ConverLineToRecord(string Line, string Seperator = "<||>")
    {
        stClient Client;
        vector<string>vClientData;
        vClientData = SplitString(Line, "<||>");               
        Client.AccountNumber = vClientData.at(0);              
        Client.PinCode = vClientData.at(1);             
        Client.Name = vClientData.at(2);               
        Client.phone = vClientData.at(3);              
        Client.AccountBalance = stod(vClientData.at(4));//cast string to double
        return Client;
    }
    static void PrintConvertLineDataToRecord()
    {
        string stLine = "A150<||>1234<||>Walid amer attia<||>01111840678<||>5000";
        cout << "Line Record is : \n";
        cout << "-------------------------------------\n";
        cout << stLine << endl << endl;
        stClient Client = ConverLineToRecord(stLine);
        PrintClientCard(Client);
    }
    //-------------------------------------------------------------------------

    //[47]_Add Client To File
    static void AddDataLineToFile(string FileName, string stDataLine)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }
    static void AddNewClient()
    {
        static const string ClientsFileName = "Clients.txt";
        stClient Client = ReadNewClient();
        AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
    }
    static void AddClients()
    {
        char AddMore = 'Y';
        do {
            system("cls");
            cout << "\nAdding New Client : ";
            AddNewClient();
            cout << "\nClient Added Successfully, Do you want add more Client [Y/N] => ";
            cin >> AddMore;
        } while (toupper(AddMore) == 'Y');
    }
    //-------------------------------------------------------------------------

    //[48]_Show All Clients
    static vector<stClient>LoadClientsDataFromFile(string FileName)
    {
        fstream MyFile;
        vector<stClient>vClients;
        MyFile.open(FileName, ios::in);//read Mode
        if (MyFile.is_open())
        {
            string Line = "";
            stClient Client;
            while (getline(MyFile, Line))
            {
                Client = ConverLineToRecord(Line);
                vClients.push_back(Client);
            }
            MyFile.close();
        }
        return vClients;
    }
    static void PrintClientRecord(stClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(40) << left << Client.Name;
        cout << "| " << setw(12) << left << Client.phone;
        cout << "| " << setw(12) << left << Client.AccountBalance << "|\n";
    }
    static void PrintAllClientsData(vector<stClient>& vClients)
    {
        cout<<"\t\t\t\t<------[Client List["<< vClients.size()<<"] client(s)]------>\n";
        cout << "-----------------------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(15) << "Account Number ";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(12) << "Balance";
        cout << "| ";
        cout << "\n-----------------------------------------------------------------------------------------------------\n";
        for (stClient& Client : vClients)
        {
            PrintClientRecord(Client);
        }
        cout << "-----------------------------------------------------------------------------------------------------\n";

    }
    static void PrintShowAllClients()
    {
        string ClientsFileName = "Clients.txt";
        vector<stClient>vClients = LoadClientsDataFromFile(ClientsFileName);
        PrintAllClientsData(vClients);
    }
    //-------------------------------------------------------------------------

    //[49]_Find Client By Account Number
    static string ReadClientAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter Account Number? => ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    static bool FindClientByAccountNumber(string AccountNumber, stClient &Client)
    {
        string ClientsFileName = "Clients.txt";
        vector<stClient>vClients = LoadClientsDataFromFile(ClientsFileName);
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }
    static void PrintFindClientByAccountNumber()
    {
        stClient Client;
        string AccountNumber = ReadClientAccountNumber();
        if (FindClientByAccountNumber(AccountNumber, Client))
        {
            PrintClientCard(Client);
        }
        else
        {
            cout << "\nClient with Account number [ " << AccountNumber << " ] is Not Found.\n";
        }   
    }
    //-------------------------------------------------------------------------

    //[50]_Delete Client By Account Number
    static bool FindClientByAccountNumber(string AccountNumber, vector<stClient>vClients , stClient& Client)
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }
    static bool MarckClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients)
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.MarkForDelete = true;
                return true;
            }
        }
        return false;
    }
    static void SaveClientsDataToFile(string FileName, vector<stClient>& vClients)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out);//read Mode and over write All data.
        string DataLine = "";
        if (MyFile.is_open())
        {
            for (stClient& C : vClients)
            {
                if (C.MarkForDelete == false)
                {
                    //we only write record that are not marked for delete .
                    DataLine = ConvertRecordToLine(C, "<||>");
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }
    static bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>vClients)
    {
        stClient Client;
        char Answer = 'n';
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);
            cout << "\nAre you sure you want delete this client? [Y/N] => ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                MarckClientForDeleteByAccountNumber(AccountNumber, vClients);
                SaveClientsDataToFile("Clients.txt", vClients);
                //Refresh Clients.
                vClients = LoadClientsDataFromFile("Clients.txt");
                cout << "\n\nClient Delete Succefully.\n";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account number [ " << AccountNumber << " ] is Not Found.\n";
        }
    }
    static void PrintDeleteClientByAccountNumber()
    {
        vector<stClient>vClients = LoadClientsDataFromFile("Clients.txt");
        string AccountNumber = ReadClientAccountNumber();
        DeleteClientByAccountNumber(AccountNumber, vClients);
    }
    //-------------------------------------------------------------------------

    //[51]_Update Client By Account Number
    static stClient ChangeClientRecord(string AccountNumber)
    {
        stClient Client;
        Client.AccountNumber = AccountNumber;
        cout << "\n-------------------------------------\n";
        cout << "plesea enetr Pin Code ? => ";
        getline(cin >> ws, Client.PinCode);
        cout << "plesea enetr Name ? => ";
        getline(cin, Client.Name);
        cout << "plesea enetr phone ? => ";
        getline(cin, Client.phone);
        cout << "plesea enetr Account Balance ? => ";
        cin >> Client.AccountBalance;
        cout << "\n-------------------------------------\n";
        return Client;
    }
    static bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>&vClients)
    {
        stClient Client;
        char Answer = 'n';
        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);
            cout << "\nAre you sure you want Update this client? [Y/N] => ";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y')
            {
                for (stClient& C : vClients)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientRecord(AccountNumber);
                        break;
                    }
                } 
                SaveClientsDataToFile("Clients.txt", vClients);
                //Refresh Clients.
                vClients = LoadClientsDataFromFile("Clients.txt");
                cout << "\n\nClient Update Succefully.\n";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account number [ " << AccountNumber << " ] is Not Found.\n";
        }
    }
    static void PrintUpdateClientByAccountNumber()
    {
        vector<stClient>vClients = LoadClientsDataFromFile("Clients.txt");
        string AccountNumber = ReadClientAccountNumber();
        UpdateClientByAccountNumber(AccountNumber, vClients);
    }
    //-------------------------------------------------------------------------
    
    //[52]_Print File In Screen
    static void PrintFileInScreen(string FileName)
    {
        fstream MyFile;
        string DataLine = "";
        MyFile.open(FileName, ios::in);//read Mode and over write All data.
        if (MyFile.is_open())
        {
            while (getline(MyFile, DataLine))
            {
                cout << DataLine << endl;
            }
            MyFile.close();
        }
    }
    //-------------------------------------------------------------------------
    
    //[53]_Check Validate Number
    static void  CheckValidateNumber(stClient Client,string Message )
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nInvalid Number : " << endl;
          //cout << "plesea enetr Account Balance \n=>";
            cout << Message << " => ";
            cin >> Client.AccountBalance;
        }
    }
    static void  CheckValidateNumber(short &Choose, string Message)
    {
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nInvalid Number : " << endl;
            //cout << "plesea enetr Account Balance \n=>";
            cout << Message << " => ";
            cin >> Choose;
        }
    }
    //-------------------------------------------------------------------------
    
    //[54]_Check Validate Number
    static bool IsCharacter_Y_N_(char Y)
    {
        if (Y == 'Y' || Y == 'y')
        {
            return 1;
        }
        else if (Y == 'N' || Y == 'n')
        {
            return 1;
        }
        return 0;
    }
    //-------------------------------------------------------------------------
    
    //[55]_Check The Choose
    static void CheckTheChoose(short& Choose)
    {
        CheckValidateNumber(Choose,"");
        while (Choose < 0 || Choose>16)
        {
            cout << "Enter Name In Range[1:16] \n=>";
            cin >> Choose;
            CheckValidateNumber(Choose,"");
        }

    }
    //-------------------------------------------------------------------------


};

