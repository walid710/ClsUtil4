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
using namespace std;


class ClsUtil2
{

private:



public:

    //[1]_Multiplication Table 1 to 10
    static void PrintTabelHeader()
    {
        cout << "\n\n\t\t\tMultipliaction Table From 1 To 10 \n\n";
        cout << "\t";
        for (int i = 1; i <= 10; i++)
        {
            cout <<"[" << i << "]\t";
        }
        cout << "\n--------------------------------------------------------------------------------------\n";
    }
    static string ColumSperator(int i)
    {
        if (i < 10)
            return "  |";
        else
            return " |";
    }
    static string RowSperator(int i)
    {
        if (i >= 100)
            return " |\t";
        else if (i >= 10)
            return  "  |\t";
        else
            return  "   |\t";
    }
    static void printtMultipliactionTable()
    {
        PrintTabelHeader();
        int N = 0;
        for (int i = 1; i <= 10; i++)
        {
            cout << "  " << i << ColumSperator(i) << "\t";
            for (int j = 1; j <= 10; j++)
            {
               
                cout <<" "<<i * j << RowSperator(i * j);
                
            }
            cout << "\n--------------------------------------------------------------------------------------";
            cout << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[2]_Print All Prime Numbers 1 to N
    static void PrintPrimeNumFrom1ToN(int Number)
    {
        cout << "\n-----------------------------------------------\n";
        cout << "The All Prime Numbers in this number [ 1 : " << Number << " ]" << endl;
        cout << "-----------------------------------------------\n";

        for (int i = 1; i <= Number;i++)
        {
            if (ClsUtil1::CheckPrime(i) == ClsUtil1::enPrimeNotPrime::Prime)
            {
                cout <<"\t=> " << i << endl;
            }
        }
        cout << "-----------------------------------------------\n";  
    }
    //-------------------------------------------------------------------------

    //[3]_Prefect Number
    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1;i < Number;i++)
        {
            if (Number % i == 0)
            {
                Sum += i;
            }
        }
       
        return (Number == Sum);
    }
    static void printNumberperfect(int Number)
    {
        if (IsPerfectNumber(Number))
        {
            cout << "\nThe Number [ " << Number << " ] is perfect.\n";
        }
        else
        {
            cout << "\nThe Number [ " << Number << " ] is not perfect.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[4]__Prefect Number From 1 to N
    static void PrintPerfectNumberFrom1ToN(int Number)
    {
        cout << "\n-----------------------------------------------\n";
        cout << "This is all perfect Numbers : [ 1 :"+to_string(Number)+" ] ";
        cout << "\n-----------------------------------------------\n";
        for (int i = 1;i <= Number;i++)
        {
            if (IsPerfectNumber(i))
            {
                cout <<"\t => "<<i<<endl;
            }
        }
        cout << "-----------------------------------------------\n";

    }
    //-------------------------------------------------------------------------

    //[5]_Print Digits in a Reversed Order
    static void PrintDigitsInAReversedOrder(int Number)
    {
        int Remainder = 0;
        cout << "\n--------------------------------------------------\n";
        cout << "The Digits In A Reversed Order in Numbers : [ " + to_string(Number) + " ] ";
        cout << "\n--------------------------------------------------\n";
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            cout <<"\t => "<< Remainder << endl;
        }
        cout << "-----------------------------------------------\n";

    }
    //-------------------------------------------------------------------------
    
    //[6]_Sum of Digits
    static string PrintOperatorPlus(int Number,int Counter)
    {
        string N = to_string(Number);
        int Ln = N.length();
        if (Counter == Ln)
            return  "";
        else
            return  " + ";
    }
    static int SumOfDigits(int Number)
    {
        int Remainder = 0;
        int Sum = 0;
        int Counter = 0;
        int Number2 = Number;
        while (Number > 0)
        {
            Counter++;
            Remainder = Number % 10;
            Number = Number / 10;
            cout << Remainder << PrintOperatorPlus(Number2,Counter);
            Sum += Remainder;
        }
        cout << " = "; 
        return Sum;
    }
    static void PrintSumOfDigits(int Number)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "The Sum Of Digits  in Numbers : [ " + to_string(Number) + " ] ";
        cout << "\n--------------------------------------------------\n";
        cout << "\t => " << SumOfDigits(Number) << endl;
        cout << "-----------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[7]_Reverse Number
    static int ReverseNumber(int Number)
    {
     
        int Sum = 0;
        int Remainder = 0;
        int Number2 = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }
    static void PrintReverseNumber(int Number)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "The Reverse Number in Numbers : [ " + to_string(Number) + " ] ";
        cout << "\n--------------------------------------------------\n";
        cout << "\t => " << ReverseNumber(Number)  << endl;
        cout << "-----------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[8]_Digit Frequency
    static int CountDigitFrequency(short  DigitToCheck , int Number)
    {
        int Remainder = 0;
        int FreqCount = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
        return FreqCount;
    }
    static void PrintDigitFrequency()
    {
       int Number = ClsUtil1::ReadPositiveNumber("Please enter positive Number ? ");
       short DigitToCheck = ClsUtil1::ReadPositiveNumber("Please enter One digit to Check ? ");
       cout << "\nDigit [ " << DigitToCheck << " ] Frequency is : " << CountDigitFrequency(DigitToCheck , Number) << " Time(s) ." << endl;
    }
    //-------------------------------------------------------------------------

    //[9]_All Digits Frequency
    static void PrintAllDigitsFrequency(int Number)
    {

        short DigitFrequency = 0;
        cout << "\n";
        for (int i = 0;i < 10; i++)
        { 
            DigitFrequency = CountDigitFrequency(i , Number);
            if (DigitFrequency > 0)
            {
                cout << "Digit [ " << i << " ] Frequency is : " << DigitFrequency << " Times ." << endl;
            }
        }
    }
    //-------------------------------------------------------------------------
    
    //[10]_Print Digit In Order
    static void PrintDigitInOrder()
    {

        PrintDigitsInAReversedOrder(ReverseNumber(ClsUtil1::ReadPositiveNumber("Please enter positive Number ")));
    
    }
    //-------------------------------------------------------------------------
    
    //[11]_Palindrome Number
    static bool IsPalindromeNumber(int Number)
    {
        return (Number == ReverseNumber(Number));
    }
    static void PrintIsIPalindromeNumberOrNot(int Number)
    {
        if (IsPalindromeNumber(Number))
        {
            cout << "\nThe Number :[ " + to_string(Number) + " ] is a Palindrome Number .  " << endl;
        }
        else
        {
            cout << "\nThe Number :[ " + to_string(Number) + " ] is not a Palindrome Number .  " << endl;
        }
    }
    //-------------------------------------------------------------------------
    
    //[12]_Inverted Number Pattern
    static void PrintInvertedPatternNumber(int Number)
    {
        cout << "\n";
        for (int i = Number;i >= 1;i--)
        {
            for (int j = 1;j <= i;j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[13]_Number Pattern
    static void PrintNumberPattern(int Number)
    {
        cout << endl;
        for (int i = 1;i <= Number;i++)
        {
            for (int j = 1;j <= i;j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }
    //-------------------------------------------------------------------------
    
    //[14]_Inverted Letter Pattern
    static void PrintInvertedLetterPattern(int Number)
    {
        cout << endl;
        for (int i = 65 + Number - 1;i >= 65;i--)
        {
            for (int j = 1;j <= Number - (65 + Number - 1 - i);j++)
            {
                cout << char(i);
            }
            cout << endl;
        }

    }
    //-------------------------------------------------------------------------
    
    //[15]_Letter Pattern
    static void PrintLetterPattern(int Number)
    {
        cout << endl;
        for (int i = 65;i <= (65 + Number - 1);i++)
        {
            for (int j = 1;j <= i - 65 + 1;j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }
    //-------------------------------------------------------------------------
    
    //[16]_All Words From AAA To ZZZ
    static void PrintWordsFromAAAtoZZZ()
    {
        cout << "\n";
        string Word = "";
        for (int i = 65;i <= 90;i++)
        {
            for (int j = 65;j <= 90;j++)
            {
                for (int K = 65;K <= 90;K++)
                {
                    Word = Word + char(i);
                    Word = Word + char(j);
                    Word = Word + char(K);
                    cout << Word << endl;
                    Word = "";
                }
                cout << "------------------------------------";
                cout << endl;
            }
        }
    }
    //-------------------------------------------------------------------------
    
    //[17]_Guess a 3_Letters Password
    static bool Is3LetterOrNot(string Password)
    {
        return (Password.length() == 3);
    }
    static string CheckCapitalLetterOrNot(string Password)
    {
      
        string Password2 = "";
        for (int i = 0;i< Password.length();i++)
        {
            for (int j = 65; j <= 90; j++)
            {
              
                if (Password[i] == char(j))
                {
                    Password2+= Password[i];
                }
            }
        }
        return Password2;
    }
    static bool IsCapitalLetter(string Password)
    {
        return (Password == CheckCapitalLetterOrNot(Password));
    }
    static string ReadPassword(string Message)
    {
        string Password = "";
        cout << Message << " => ";
        cin >> Password;

        if (Is3LetterOrNot(Password))
        {
            if (IsCapitalLetter(Password))
            {
                return Password;
            }
            else
                return ReadPassword(Message);
        }
        else
            return ReadPassword(Message);
    }
    static bool GuessPassword(string OriginalPassword)
    {
        int Counter = 0;
        string Word = "";
        for (int i = 65;i <= 90;i++)
        {
            for (int j = 65;j <= 90;j++)
            {
                for (int C = 65;C <= 90;C++)
                {
                    Word = Word + char(i);
                    Word = Word + char(j);
                    Word = Word + char(C);
                    Counter++;
                    cout << "\nTrail [ " + to_string(Counter) + " ] :  " << Word << "\n ";
                    if (Word == OriginalPassword )
                    {
                        cout << "\nPassword is : [ " << Word <<" ]"<< endl;
                        cout << "Found After : [ " << Counter << " ] Terial(s)\n";
                        return true;
                    }
                    Word = "";
                }
                cout << "------------------------------------";
                cout << endl;
            }
        }
        return false;
    }
    //-------------------------------------------------------------------------

    //[18]_Encrypt/Decrypt Text
    static string ReadPassword2(string Message)
    {

        string Password = "";
        cout << Message << " => ";
        getline(cin >>ws, Password);
        return Password;
    }
    static string EncryptText(string Text, short   EncryptionKey)
    {
        for (int i = 0;i <= Text.length();i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }
    static string DecryptText(string Text, short   EncryptionKey)
    {
        for (int i = 0;i <= Text.length();i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }
    static void PrintEncryptAndDecryptText()
    {
        //This is The Key
        const short EncryptionKey = 2;
        string Text = ReadPassword2("please enter Text  ?  ");
        string TesxtAftererEncryption = EncryptText(Text, EncryptionKey);
        string TesxtAftererDecryptionText = DecryptText(TesxtAftererEncryption, EncryptionKey);

        cout << "\n----------------------------------------------\n";
        cout << "Text before Encryption  : " << Text << endl;
        cout << "Text Afterer Encryption : " << TesxtAftererEncryption << endl;
        cout << "Text Afterer Decryption : " << TesxtAftererDecryptionText;
        cout << "\n----------------------------------------------\n";

    }
    //-------------------------------------------------------------------------

    //[19]_Random 3 Numbers From 1 T0 10
    static void SrandRondom()
    {
        //Seeds the random number generator in C++,called only once.
        srand((unsigned)time(NULL));
    }
    static int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randomNumber = rand() % (To - From + 1) + From;
        return randomNumber;

    }
    //-------------------------------------------------------------------------

    //[20]_Random Samll Letters ,Capital Letters,Special C,and Digit in order
    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, DigitNumber = 4 };
    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
            return char(RandomNumber(97, 122));
        case enCharType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharType::SpecialCharacter:
            return char(RandomNumber(33, 47));
        case enCharType::DigitNumber:
            return char(RandomNumber(48, 57));
        }
    }
    //-------------------------------------------------------------------------
    
    //[21]_General Keys  
    static string GeneratWord(enCharType CharType, short Length)
    {
        string Word = "";
        for (int i = 1; i <= Length;i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }
    static string GeneratKey(enCharType CharType, short Length)
    {
        string Key = "";
        Key = GeneratWord(CharType, Length) + "-";
        Key = Key + GeneratWord(CharType, Length) + "-";
        Key = Key + GeneratWord(CharType, Length) + "-";
        Key = Key + GeneratWord(CharType, Length);
        return   Key;
    }
    static void GeneratKeys(short NumberOfKeys, enCharType CharType, short Length)
    {
        cout << "\n";
        for (int i = 1; i <= NumberOfKeys;i++)
        {
            cout << "Key [ " + to_string(i) + " ] : ";
            cout << GeneratKey(CharType, Length) << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[22]_Repeated Elements Count In Array
    static void ReadArray(int arr[100], int& arrLength)
    {
        arrLength = ClsUtil1::ReadNumberInRange2(1,100,"please enter the Number Of element ");
        cout << "\nEnter Array elements :" << endl;
        cout << "---------------------\n";
        for (int i = 0; i < arrLength;i++)
        {
            arr[i] = ClsUtil1::ReadNumber("Element [ " + to_string(i + 1) + " ] : ");
        }
        cout << "---------------------\n";
    }
    static void printArray(int arr[100], int arrLength)
    {
        cout << " = { ";
        for (int i = 0; i < arrLength;i++)
        {
            cout << arr[i];
            if(i!= arrLength-1)
               cout<<" , ";
        }
        cout << " }.";
        cout << endl;
    }
    static int TimesRepeated(int Number , int arr[100], int arrLength )
    {
        int Count = 0;
        for (int i = 0; i < arrLength;i++)
        {
            if (Number == arr[i])
            {
                Count++;
              //  cout << "\n[" + to_string(Number) + "] Found in Array in element : [ " + to_string(i) + " ] .";
            }
        }
        return Count;
    }
    static void PrintRepeatedElementsCountInArray()
    {
        int arr[100], arrLength, NumberToCheck;
        ReadArray(arr, arrLength);
        NumberToCheck = ClsUtil1::ReadPositiveNumber("Enter the number you want to check? ");
        cout << "\n----------------------------\n";
        cout << "original array : ";
        printArray(arr, arrLength);
        int Count = TimesRepeated(NumberToCheck , arr, arrLength);
        cout <<"\nNumber      : [ "<< NumberToCheck<<" ]."<< endl;
        cout <<"is repeated : [ " << Count << " ] time(s) ." << endl;
        cout << "\n----------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[23]_Fill Array with random number from 1 to 100
    static void FillArrayWigthRandomNumbers(int arr[100], int& arrLength)
    {
        arrLength = ClsUtil1::ReadNumberInRange2(1, 100, "please enter the Number Of element ");
        for (int i = 0; i < arrLength;i++)
        {
            arr[i] = RandomNumber(1, 100);
        }
    }
    static void PrintArrayWithRondom()
    {
        int arr[100],  arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\noriginal array : \n";
        printArray(arr, arrLength);

    }
    //-------------------------------------------------------------------------

    //[24]_Max of Random Array
    static int  MaxNumberInArray(int arr[100],  int arrlength)
    {
        int Max = 0;
        for (int i = 0; i < arrlength;i++)

        {
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;
    }
    static void PrintMaxNumberInArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\noriginal array :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nMax Number is : [ " << MaxNumberInArray(arr, arrLength) << " ].\n";

    }
    //-------------------------------------------------------------------------

    //[25]_Min of Random Array
    static int  MinNumberInArray(int arr[100], int arrlength)
    {
        int Min = 0;
        Min = arr[0];
        for (int i = 0; i < arrlength;i++)

        {
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;
    }
    static void PrintMinNumberInArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\noriginal array :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nMin Number is : [ " << MinNumberInArray(arr, arrLength) << " ].\n";

    }
    //-------------------------------------------------------------------------

    //[26]_Sum Of Random Array
    static int SumArray(int arr[100], int arrlength)
    {
        int Sum = 0;
        for (int i = 0; i < arrlength;i++)
        {
            Sum += arr[i];
        }
        return    Sum;
    }
    static void PrintSumArray()
    {

        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\noriginal array :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nSum of All Numbers is : [ " << SumArray(arr, arrLength) << " ].\n";

    }
    //-------------------------------------------------------------------------
    
    //[27]_Average of Random Array
    static float AveregeArray(int arr[100], int arrlength)
    {
        return (float)SumArray(arr, arrlength) / arrlength;
    }
    static void PrintAveregeArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\noriginal array :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nSum of All Numbers is    : [ " << SumArray(arr, arrLength) << " ].\n";
        cout << "\Averege of All Numbers is : [ " << AveregeArray(arr, arrLength) << " ].\n";
    }
    //-------------------------------------------------------------------------

    //[28]_Copy Array
    static void CopyArray(int arrSource[100], int arrDestination[100], int arrlength)
    {
        for (int i = 0; i < arrlength;i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }
    static void PrintCopyArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        CopyArray(arr, arr2, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 elements after copy :\n\t\t";
        printArray(arr2, arrLength);
    }
    //-------------------------------------------------------------------------

    //[29]_Copy Only Prime Numbers
    static void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrlength, int& arr2Length)
    {
        int Counter = 0;
        for (int i = 0;i <= arrlength;i++)
        {
            if (ClsUtil1::CheckPrime(arrSource[i]) == ClsUtil1::enPrimeNotPrime::Prime)
            {
                arrDestination[Counter] = arrSource[i];
                Counter++;
            }
        }
        arr2Length = --Counter;
    }
    static void PrintCopyOnlyPrimeNumbers()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100], arr2Length;
        CopyOnlyPrimeNumbers(arr, arr2, arrLength , arr2Length);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nPrime Number in Array2 :\n\t\t";
        printArray(arr2, arr2Length);
    }
    //-------------------------------------------------------------------------

    //[30]_Sum Of 2 Arrays To a Third One
    static void FillArrayWigthRandomNumbers2(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength;i++)
        {
            arr[i] = RandomNumber(1, 100);
        }
    }
    static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        for (int i = 0; i < arrLength;i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }
    static void PrintSumOf2Arrays()
    {
        int arr[100], arr2[100] , arrSum[100] ;
        int arrLength = ClsUtil1::ReadNumberInRange2(1, 100, "please enter the Number Of element ");
        FillArrayWigthRandomNumbers2(arr, arrLength);
        FillArrayWigthRandomNumbers2(arr2, arrLength);
        SumOf2Arrays(arr, arr2, arrSum, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 elements :\n\t\t";
        printArray(arr2, arrLength);
        cout << "\nSum of  aray 1 and array 2 elements :\n\t\t";
        printArray(arrSum, arrLength);
       
    }
    //-------------------------------------------------------------------------

    //[31]_Shuffle Ordered Array
    static void FillArrayWith1ToN(int arr[100], int arrlength)
    {
        for (int i = 0; i < arrlength;i++)
        {
            arr[i] = i + 1;
        }

    }
    static void Swap(int& A, int& B)
    {
        int Temp = 0;
        Temp = A;
        A = B;
        B = Temp;
    }
    static void ShuffleArray(int arr[100], int arrlength)
    {
        for (int i = 0; i < arrlength;i++)
        {
            Swap(arr[RandomNumber(1, arrlength) - 1], arr[RandomNumber(1, arrlength) - 1]);
        }
    }
    static void Print_ShuffleArray()
    {
        int arr[100];
        int arrLength = ClsUtil1::ReadNumberInRange2(1, 100, "please enter the Number Of element ");
        FillArrayWith1ToN(arr, arrLength);
        cout << "\nArray elements before shuffle :\n\t\t";
        printArray(arr, arrLength);
        ShuffleArray(arr, arrLength);
        cout << "\nArray elements after shuffle :\n\t\t";
        printArray(arr, arrLength);
    }

    //-------------------------------------------------------------------------

    //[32]_Copy Array In Reverse Order
    static void CopyArrayInReveseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        for (int i = 0; i < arrLength;i++)
        {  
            arrDestination[i] = arrSource[arrLength - 1 - i];
        }
    }
    static void PrintCopyArrayInReverseOrder()
    {
        int arr[100] , arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        CopyArrayInReveseOrder(arr, arr2, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 elements after copy :\n\t\t";
        printArray(arr2, arrLength);
    }
    //-------------------------------------------------------------------------

    //[33]_Fill Array With Keys
    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType, short Length)
    {
        for (int i = 0; i < arrLength;i++)
        {
            arr[i] = GeneratKey(CharType, Length);
        }
    }
    static void PrintStringArray(string arr[100], int arrLength)
    {
        cout << " = { ";
        for (int i = 0; i < arrLength;i++)
        {
            cout << arr[i];
            if (i != arrLength - 1)
                cout << " , \n\t\t     ";
        }
        cout << " }.";
        cout << endl;

    }
    static void PrintFillArrayWithKeys()
    {
        string arr[100];
        int arrLength = ClsUtil1::ReadNumberInRange2(1, 100, "How Many keys do you want to generate? ");
        FillArrayWithRandomKeys(arr, arrLength, enCharType::SmallLetter, 4);
        cout << "\nArray 1 elements :\n\t\t";
        PrintStringArray(arr, arrLength);
    }
    //-------------------------------------------------------------------------

    //[34]_Return Number Index In Array
    static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        /*This function will search for a number in array and return its index,
        or return -1 if it does not exists*/
        for (int i = 0; i < arrLength;i++)
        {
            if (arr[i] == Number)
            {
                //This will break the functoin and return the index.
                return i;
            }

        }
        //if you reached here, this means the number is not found
        return -1;
    }
    static void PrintReturnNumberIndexInArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int Number = ClsUtil1::ReadNumber("Please enter a number to search for ?");
        short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);
        cout << "\nNumber you are looking for is : [ " << Number << " ].\n";
        if (NumberPosition == -1)
        {
            cout << "The number is not found :-(\n";
        }
        else
        {
            cout << "The Number Found at position  : [ " << NumberPosition <<" ]." <<endl;
            cout << "The Number Found its order    : [ " << NumberPosition+1 <<" ]."<< endl;
        }
    }
    //-------------------------------------------------------------------------

    //[35]_Check Number In Array
    static bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        return (FindNumberPositionInArray(Number, arr, arrLength) != -1);
    }
    static void PrintCheckNumberInArray()
    {
        int arr[100], arrLength;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int Number = ClsUtil1::ReadNumber("Please enter a number to search for ?");
        short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);
        cout << "\nNumber you are looking for is : [ " << Number << " ].\n";
        if (!IsNumberInArray(Number, arr, arrLength))
        {
            cout << "No,The number is not found :-(\n";
        }
        else
        {
            cout << "Yes, it is found :-)\n";
        }
    }
    //-------------------------------------------------------------------------

    //[36]_Add Array Element simi Dynamic
    static void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        //its a new element so we need to add the length by 1.
        arrLength++;
        arr[arrLength - 1] = Number;
    }
    static void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;
        do 
        {
            AddArrayElement(ClsUtil1::ReadNumber("please enter a number ? "), arr, arrLength);
            cout << "Do you want to add more numbers ?[0]:No,[1]:yes => ";
            cin >> AddMore;
        } while (AddMore);
    }
    static void PrintAddArrayElementsimiDynamic()
    {
        int arr[100], arrLength =0 ;
        InputUserNumbersInArray(arr, arrLength);
        cout << "\nArray Length : [ " << arrLength << " ].\n";
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
    }
    //-------------------------------------------------------------------------

    //[37]_Resolve Problme 28/2 Copy Array Using AddArrayElement
    static void CopyArryUsingAddArrayElement(int arrSource[100], int arrDestination[100], int& arrLength, int& arr2Length)
    {
        for (int i = 0; i < arrLength;i++)
        {
            AddArrayElement(arrSource[i], arrDestination, arr2Length);
        }
    }
    static void PrintCopyArrayUsingAddArrayElement()
    {
        int arr[100], arrLength = 0 , arr2Length = 0;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        CopyArryUsingAddArrayElement(arr, arr2, arrLength, arr2Length);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 elements after copy :\n\t\t";
        printArray(arr2, arr2Length);
    }
    //-------------------------------------------------------------------------

    //[38]_Copy Odd Numbers to a new Array
    static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int& arrLength, int& arr2Length, ClsUtil1::enNumberType NumberType)
    {
        for (int i = 0; i < arrLength;i++)
        {
            if (ClsUtil1::CheckNumberType(arrSource[i]) == NumberType)
                 AddArrayElement(arrSource[i], arrDestination, arr2Length);
        }
    }
    static void PrintCopyOddNumbersToANewArray()
    {
        int arr[100], arrLength = 0, arr2Length = 0;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        CopyOddNumbers(arr, arr2, arrLength, arr2Length,ClsUtil1::Odd);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 Odd Numbers :\n\t\t";
        printArray(arr2, arr2Length);
    }
    //-------------------------------------------------------------------------

    //[39]_Copy Prime Numbers to a new Array
    static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int& arrLength, int& arr2Length)
    {
        for (int i = 0; i < arrLength;i++)
        {
            if (ClsUtil1::CheckPrime(arrSource[i]) == ClsUtil1::enPrimeNotPrime::Prime)
                AddArrayElement(arrSource[i], arrDestination, arr2Length);
        }
    }
    static void PrintCopyPrimeNumbersToANewArray()
    {
        int arr[100], arrLength = 0, arr2Length = 0;
        FillArrayWigthRandomNumbers(arr, arrLength);
        int arr2[100];
        CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        cout << "\nArray 2 Prime Numbers :\n\t\t";
        printArray(arr2, arr2Length);
    }

    //-------------------------------------------------------------------------

    //[40]_Copy Distinct Numbers To Array
    static void FillArray(int arr[100], int& arrLength)
    {
        arrLength = 10;
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
        arr[5] = 50;
        arr[6] = 40;
        arr[7] = 30;
        arr[8] = 20;
        arr[9] = 10;
        
    }
    static void CopyDistinctNumber(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
    {
        for (int i = 0; i < SourceLength;i++)
        {
            if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
               AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
    static void PrintCopyDistinctNumbersToArray()
    {
        int arrSource[100], SourceLength = 0, arrDestination[100] ,DestinationLength = 0;
        FillArray(arrSource, SourceLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arrSource, SourceLength);
        CopyDistinctNumber(arrSource, arrDestination, SourceLength, DestinationLength);
        cout << "\nArray 2 Prime Numbers :\n\t\t";
        printArray(arrDestination, DestinationLength);
    }
    //-------------------------------------------------------------------------

    //[41]_Is Palindrome Array
    static bool IsPalindromeArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength;i++)
        {
            if (arr[i] != arr[arrLength - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    static void PrintIsPalindromeArray()
    {
        int arr[100], arrLength = 0;
        FillArray(arr, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        if (IsPalindromeArray(arr, arrLength))
        {
            cout << "\nYes array is Palindrome.\n";
        }
        else
        {
            cout << "\nNo array is Not Palindrome.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[42]_Count Odd Numbers In Array 
    static int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength;i++)
        {
            if (ClsUtil1::CheckNumberType(arr[i]) == ClsUtil1::enNumberType::Odd)
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountOddNumbersInArray()
    {
        int arr[100], arrLength = 0;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int arr2[100], arr2Length = 0;
        CopyOddNumbers(arr, arr2, arrLength, arr2Length,ClsUtil1::Odd);
        cout << "\nArray 2 Odd Numbers :\n\t\t";
        printArray(arr2, arr2Length);
        cout << "\nOdd Numbers Count is [ "<< OddCount(arr, arrLength) <<" ]\n";
    }
    //-------------------------------------------------------------------------

    //[43]_Count Even Numbers In Array 
    static int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength;i++)
        {
            if (ClsUtil1::CheckNumberType(arr[i]) == ClsUtil1::enNumberType::Even)
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountEvenNumbersInArray()
    {
        int arr[100], arrLength = 0;
        FillArrayWigthRandomNumbers(arr, arrLength);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int arr2[100], arr2Length = 0;
        CopyOddNumbers(arr, arr2, arrLength, arr2Length,ClsUtil1::Even);
        cout << "\nArray 2 Even Numbers :\n\t\t";
        printArray(arr2, arr2Length);
        cout << "\nEven Numbers Count is [ " << EvenCount(arr, arrLength) << " ]\n";
    }
    //-------------------------------------------------------------------------

    //[44]_Count Positive Numbers In Array
    enum enPositiveOrNegative{Positive=1,Negative=2};
    static enPositiveOrNegative CheckPositiveOrNegative(int Number)
    {
        if (Number >= 0)
        {
            return enPositiveOrNegative::Positive;
        }
        else
        {
            return enPositiveOrNegative::Negative;
        }
    }
    static void FillArrayWigthRandomNumbers2(int arr[100], int& arrLength,int From,int To)
    {
        arrLength = ClsUtil1::ReadNumberInRange2(1, 100, "please enter the Number Of element ");
        for (int i = 0; i < arrLength;i++)
        {
            arr[i] = RandomNumber(From, To);
        }
    }
    static void CopyPositiveNumbers(int arrSource[100], int arrDestination[100], int& arrLength, int& arr2Length, enPositiveOrNegative P_Or_N)
    {
        for (int i = 0; i < arrLength;i++)
        {
            if (CheckPositiveOrNegative(arrSource[i]) == P_Or_N)
                AddArrayElement(arrSource[i], arrDestination, arr2Length);
        }
    }
    static int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength;i++)
        {
            if (arr[i] >= 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountPositiveNumbersInArray()
    {
        int arr[100], arrLength = 0;
        FillArrayWigthRandomNumbers2(arr, arrLength,-100,100);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int arr2[100], arr2Length = 0;
        CopyPositiveNumbers(arr, arr2, arrLength, arr2Length, enPositiveOrNegative::Positive);
        cout << "\nArray 2 Positive Numbers :\n\t\t";
        printArray(arr2, arr2Length);
        cout << "\nPositive Numbers Count is [ " << PositiveCount(arr, arrLength) << " ]\n";
    }
    //-------------------------------------------------------------------------
    
    //[45]_Count Negative Numbers In Array
    static int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;
        for (int i = 0; i < arrLength;i++)
        {
            if (arr[i] < 0)
            {
                Counter++;
            }
        }
        return Counter;
    }
    static void PrintCountNegativeNumbersInArray()
    {
        int arr[100], arrLength = 0;
        FillArrayWigthRandomNumbers2(arr, arrLength, -100, 100);
        cout << "\nArray 1 elements :\n\t\t";
        printArray(arr, arrLength);
        int arr2[100], arr2Length = 0;
        CopyPositiveNumbers(arr, arr2, arrLength, arr2Length, enPositiveOrNegative::Negative);
        cout << "\nArray 2 Negative Numbers :\n\t\t";
        printArray(arr2, arr2Length);
        cout << "\nNegative Numbers Count is [ " << NegativeCount(arr, arrLength) << " ]\n";
    }
    //-------------------------------------------------------------------------

    //[46]_MyABS
    static float MyABS(float Number)
    {
        if (Number > 0)
            return  Number;
        else
            return  Number * -1;
    }
    static void PrintResultMyABS()
    {
        float Number = ClsUtil1::ReadNegativNumber("please enter Negative a Number ? ");
        cout << "\n-----------------------------\n";
        cout << "My abs Reasult  : [ " << MyABS(Number) <<" ]."<< endl;
        cout << "C++ abs Reasult : [ " << abs(Number) <<" ]."<< endl;
        cout << "-----------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[47]_MyRound
    static float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }
    static int  MyRound(float Number)
    {
        int Inpart = int(Number);
        float FractionPart = GetFractionPart(Number);
        if (MyABS(FractionPart) >= 0.5)
        {
            if (Number > 0)
            {
                return ++Inpart;
            }
            else
            {
                return --Inpart;
            }
        }
        else
        {
            return  Inpart;
        }
    }
    static void PrintResultMyRound()
    {
        float Number = ClsUtil1::ReadNumber2("please enter a Number ? ");
        cout << "\n-----------------------------\n";
        cout << "My MyRound Reasult  : [ " << MyRound(Number) << " ]." << endl;
        cout << "C++ MyRound Reasult : [ " << round(Number) << " ]." << endl;
        cout << "-----------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[48]_MyFloor
    static int MyFloor(float Number)
    {
        if (Number > 0)
        {
            return (int)Number;
        }
        else
        {
            return int(Number)-1;

        }
    }
    static void PrintResultMyFloor()
    {
        float Number = ClsUtil1::ReadNumber2("please enter a Number ? ");
        cout << "\n-----------------------------\n";
        cout << "My MyFloor Reasult  : [ " << MyFloor(Number) << " ]." << endl;
        cout << "C++ Floor Reasult   : [ " << floor(Number) << " ]." << endl;
        cout << "-----------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[49]_MyCeil
    static int  MyCeil(float Number)
    {
        if (MyABS(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
            {
                return int(Number) + 1;
            }
            else
            {
                return int(Number);
            }
        }
        else
        {
            return Number;
        }
    }
    static void PrintResultMyCeil()
    {
        float Number = ClsUtil1::ReadNumber2("please enter a Number ? ");
        cout << "\n-----------------------------\n";
        cout << "My MyCeil Reasult  : [ " << MyCeil(Number) << " ]." << endl;
        cout << "C++ Ceil Reasult   : [ " << ceil(Number) << " ]." << endl;
        cout << "-----------------------------\n";
    }
    
    //-------------------------------------------------------------------------
    
    //[50]_MySqrt
    static float MySqrt(float Number)
    {
        return pow(Number, 0.5);
    }
    static void PrintResultMySqrt()
    {
        float Number = ClsUtil1::ReadNumber2("please enter a Number ? ");
        cout << "\n-----------------------------\n";
        cout << "My MySqrt Reasult  : [ " << MySqrt(Number) << " ]." << endl;
        cout << "C++ Sqrt Reasult   : [ " << sqrt(Number) << " ]." << endl;
        cout << "-----------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    




};

