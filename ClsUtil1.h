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

using namespace std;




class ClsUtil1
{

private :

   

public:

    //[1]_Print Your Name
    static void printName(string Name)
    {
        cout << "\n-----------------------------";
        cout << "\nYour name is  : " << Name << endl;
        cout << "-----------------------------\n";

    }
    //-------------------------------------------------------------------------
   
	//[2]_Read Name And Print It
    static string ReadName()
    {
        string Name;
        cout << "please enter your Name ?  =>";
        getline(cin, Name);

        return Name;
    }
    //-------------------------------------------------------------------------

    //[3]_Check Odd Or Even
     enum enNumberType { Odd = 1, Even = 2 };

    static int ReadNumber(string Message)
    {
        int Number=0;

        cout << Message << " = > ";
        cin >> Number;
        return Number;
    }
    static float ReadNumber2(string Message)
    {
        float Number = 0;

        cout << Message << " = > ";
        cin >> Number;
        return Number;
    }
    static enNumberType CheckNumberType(int Number)
    {
        int Result = Number % 2;
        if (Result == 0)
        {
            return enNumberType::Even;
        }
        else
        {
            return enNumberType::Odd;

        }

    }
    static void PrintNumberType(enNumberType NumberType, int Number)
    {
        switch (NumberType)
        {


        case enNumberType::Even:
            cout << "\nNumber : [ " << Number << " ] is : Even ." << endl;
            break;

        case  enNumberType::Odd:
            cout << "\nNumber : [ " << Number << " ] is : Odd ." << endl;
            break;

        default:
            cout << "\nno Thing !!!" << endl;
            break;

        }

    }
    //-------------------------------------------------------------------------
    
    //[4]_Hire a driver Case 1
    struct stInfo
    {

        int Age;
        bool HasDrivingLicense;

    };
    static stInfo  ReadInfo()
    {
        stInfo Info1;
        cout << "please enter your age ? => ";
        cin >> Info1.Age;
       
        cout << "Do you have a driving license? [Yes=1/No=0] => ";
        cin >> Info1.HasDrivingLicense;

        return Info1;
    }
    static bool IsAccepted(stInfo Info)
    {
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
    static void PrintResult(stInfo Info)
    {

        if (IsAccepted(Info))
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Hired >>" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Rejected >>" << endl;
            cout << "--------------------------" << endl;
        }

    }
    //-------------------------------------------------------------------------
   
    //[5]_Hire a driver Case 2
    struct stInfo2
    {

        int Age;
        bool HasDrivingLicense;
        bool HasRecommendation;

    };
    static stInfo2  ReadInfo2()
    {
        stInfo2 Info;
        cout << "please enter your age ? => ";
        cin >> Info.Age;

        cout << "Do you have a driving license? [Yes=1/No=0] => ";
        cin >> Info.HasDrivingLicense;

        cout << "Do you have a Recommendation ? [Yes=1/No=0] => ";
        cin >> Info.HasRecommendation;

        return Info;
    }
    static bool IsAccepted2(stInfo2 Info)
    {
        if (Info.HasRecommendation)
            return true;
        else
            return (Info.Age > 21 && Info.HasDrivingLicense);
    }
    static void PrintResult2(stInfo2 Info)
    {

        if (IsAccepted2(Info))
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Hired >>" << endl;
            cout << "--------------------------" << endl;
        }
        else
        {
            cout << "\n--------------------------" << endl;
            cout << "\t<< Rejected >>" << endl;
            cout << "--------------------------" << endl;
        }

    }
    //-------------------------------------------------------------------------

    //[6]_Full Name
    enum enChoice { First_Last = 1, Last_First = 2, Both_options = 3 };
    struct strInfo
    {
        string FirstName;
        string LastName;
    };
    static strInfo ReadFirstAndLastName()
    {
        strInfo Info;
        cout << "please enter your firstrst name ? \n => ";
        cin >> Info.FirstName;
        cout << "please enter your last name ? \n => ";
        cin >> Info.LastName;

        return Info;
    }
    static string GetFullName(strInfo Info,bool Reversed)
    {
        string FullName = " ";
        if(Reversed)
            FullName = Info.LastName + " " + Info.FirstName;
        else
            FullName = Info.FirstName + " " + Info.LastName;
        return FullName;
    }
    /*static string GetReciveFullName(strInfo Info)
    {
        string FullName = " ";
        FullName = Info.LastName+" "+ Info.FirstName;
        return FullName;
    }*/
    static void PrintFullNameFirstNameAndLastName(string FullName, strInfo Info)
    {
        cout << "\n------------------------------------\n";
        cout << "First Name is : " << Info.FirstName << endl;
        cout << "Last Name is  : " << Info.LastName << endl;
        cout << "FullName is   : " << FullName << endl;
        cout << "FullName is   : " << GetFullName(Info, false) << endl;
        cout << "FullName is   : " << Info.FirstName + " " + Info.LastName << endl;
        cout << "------------------------------------\n";
    }
    static void PrintReversedFullName(string FullName, strInfo Info)
    {
        cout << "\n------------------------------------\n";
        cout << "First Name is : " << Info.FirstName << endl;
        cout << "Last Name is  : " << Info.LastName << endl;
        cout << "FullName is   : " << FullName << endl;
        cout << "FullName is   : " << GetFullName(Info, true) << endl;
        cout << "FullName is   : " << Info.LastName + " " + Info.FirstName<<endl;
        cout << "------------------------------------\n";
    }
    static void RunFunction(enChoice Choice, strInfo Info)
    {
        switch (Choice)
        {

        case enChoice::First_Last:
            system("cls");
            PrintFullNameFirstNameAndLastName(GetFullName(Info, false), Info);
            GoBackToMenue(Info);
            break;
        case enChoice::Last_First:
            system("cls");
            PrintReversedFullName(GetFullName(Info, true), Info);
            GoBackToMenue(Info);
            break;
        case enChoice::Both_options: 
            system("cls");
            PrintFullNameFirstNameAndLastName(GetFullName(Info, false), Info);
            PrintReversedFullName(GetFullName(Info, true), Info);
            GoBackToMenue(Info);
            break;
        default:
            system("cls");
            cout << "Good Luck !!!\n"; 
            break;
        }

    }
    static void ShowOption(strInfo Info)
    {
        int Number = 0;
        system("cls");
        cout << "How would you like your name to be displayed?\n";
        cout << "1: FirstName and LastName ." << endl;
        cout << "2: LastName and FirstName ." << endl;
        cout << "3: Both options ." << endl;
        cout << "4: Exit ." << endl;
        cout << "------------------------------------------\n";
        cin >> Number;
        RunFunction((enChoice)Number, Info);
    }
    static void GoBackToMenue(strInfo Info)
    {
       
        cout << "Please enter any key to back to Menue....";
        system("pause>0");
        ShowOption(Info);

    }
    //-------------------------------------------------------------------------
    
    //[7]_Half Number
    static float CalculateHalfNumber(int Number)
    {
        return (float)Number / 2;
    }
    static void PrintResultOfHalfNumber(int Number)
    {
        cout << "---------------------------------------------\n";
        string Result = "Result [ Half of Number ] : " + to_string(Number) + "/2 = " + to_string(CalculateHalfNumber(Number));
        cout << Result << endl;
        printf("\nResult = [ Half of %d ]     : %d/2 = %.1f ", Number, Number, CalculateHalfNumber(Number));
        printf("\nResult = [ Half of %0*d ]     : %0*d/2 = %.1f ", 2,Number,2, Number, CalculateHalfNumber(Number));
        printf("\nResult = [ Half of %0d ]   : %0d/2 = %.*f ", Number, Number, 3,CalculateHalfNumber(Number));
        printf("\n%s = [ Half of %0d ]   : %0d/2 = %.*f ","Result", Number, Number, 3, CalculateHalfNumber(Number));
        printf("\n%*s = [ Half of %0d ]   : %0d/2 = %.*f ", 3,"Result", Number, Number, 3, CalculateHalfNumber(Number));
        cout << "\n---------------------------------------------\n";

    }
    //-------------------------------------------------------------------------
    
    //[8]_Mark Pass Fail
    enum enPassFail{ Pass = 1 ,Fail = 2 };
    static int ReadMark()
    {

        int Mark;
        cout << "Please enter your Mark ?\n =>";
        cin >> Mark;
        return Mark;

    }
    static enPassFail CheckMark(int Mark)
    {

        if (Mark >= 50)
        {
            return enPassFail::Pass;

        }

        else
        {
            return enPassFail::Fail;

        }
    }
    static void PrintResultOfMark(int Mark)
    {

        if (CheckMark(Mark) == enPassFail::Pass)
        {
            cout << "---------------------------------------------\n";
            cout << "\tYou are successful ." << endl;
            cout << "---------------------------------------------\n";
        }
        else if (CheckMark(Mark) == enPassFail::Fail)
        {
            cout << "---------------------------------------------\n";
            cout << "\tYou failed ." << endl;
            cout << "---------------------------------------------\n";
        }
    }
    //-------------------------------------------------------------------------
    
    //[9]_Sum Of 3 Numbers
    struct str3Number
    {

        int Number1, Number2, Number3,TheSum;

    };
    static str3Number ReadNumbers()
    {

        str3Number Info;
        cout << "please enter number 1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter number 2 ?\n => ";
        cin >> Info.Number2;
        cout << "please enter number 3 ?\n => ";
        cin >> Info.Number3;

        return Info;
    }
    static int SumOf3Numbers(str3Number& Info)
    {

        Info.TheSum = Info.Number1+ Info.Number2 + Info.Number3;
        return   Info.TheSum;

    }
    static void PrintResultSumOf3Numbers(str3Number Info)
    {
        cout << "\n-----------------------------------\n";
        cout << "  The Sum = " << Info.Number1 << " + " << Info.Number2 << " + " << Info.Number3 << " = " << SumOf3Numbers(Info) << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void ReadNumbers2(int& Number1, int& Number2, int& Number3)
    {
        cout << "please enter number 1 ?\n => ";
        cin >> Number1;
        cout << "please enter number 2 ?\n => ";
        cin >> Number2;
        cout << "please enter number 3 ?\n => ";
        cin >> Number3;
    }
    static int SumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        return   Number1 + Number2 + Number3;
    }
    static void PrintResultSumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        cout << "\n---------------------------------\n";
        cout << "  The Sum = " << Number1 << " + " << Number2 << " + " << Number3 << " = " << SumOf3Numbers2(Number1, Number2, Number3) << endl;
        cout << "---------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void  ReadNumbers3(int  Array[3])
    {

        for (int i = 0;i < 3;i++)
        {
            printf("please enter number %d ?\n => ",i+1);
            cin >> Array[i];
        }
    }
    static int SumOf3Numbers3(int  Array[3])
    {
        int Sum = 0;
        for (int i = 0;i < 3;i++)
        {
              Sum += Array[i];
        }
        return  Sum;

    }
    static void PrintResultSumOf3Numbers3(int  Array[3])
    {
        cout << "---------------------------------\n";
        cout << "  The Sum = ";
            for (int i = 0;i < 3;i++)
            {
                
                cout << to_string(Array[i]);
                if (i == 2)
                    break;
                cout<<" + ";

            }
        cout << " = " << SumOf3Numbers3(Array) << endl;
        cout << "---------------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[10]_Average Of 3 Marks
    static float CalculateAverage(str3Number Info)
    {

        return (float)SumOf3Numbers(Info) / 3;
    }
    static void PrintResultAverageOf3Marks(str3Number Info)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = " << Info.Number1 << " + " << Info.Number2 << " + " << Info.Number3 << " = "
             << SumOf3Numbers(Info)<<" / 3 = "<< CalculateAverage(Info) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static float CalculateAverage2(int& Number1, int& Number2, int& Number3)
    {

        return (float)SumOf3Numbers2(Number1, Number2, Number3) / 3;
    }
    static void PrintResultAverageOf3Marks2(int Number1, int Number2, int Number3)
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = " << Number1 << " + " << Number2 << " + " << Number3 << " = "
            << SumOf3Numbers2(Number1, Number2, Number3) << " / 3 = " << CalculateAverage2(Number1, Number2, Number3) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static float CalculateAverage3(int  Array[3])
    {

        return (float)SumOf3Numbers3(Array) / 3;
    }
    static void PrintResultAverageOf3Marks3(int  Array[3])
    {
        cout << "\n--------------------------------------------------\n";
        cout << "  The Average = ";
            for (int i = 0;i < 3;i++)
            {

                cout << to_string(Array[i]);
                if (i == 2)
                    break;
                cout << " + ";

            }
            cout << " = " << SumOf3Numbers3(Array) << " / 3 = " << CalculateAverage3(Array) << endl;
        cout << "--------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
   
    //[11]_Avrage Pass/Fail
    static enPassFail CheckAverage(float Average)
    {

        if (Average >= 50)
        {
            return enPassFail::Pass;

        }

        else
        {
            return enPassFail::Fail;

        }

    }
    static void PrintResultPaasOrFail(float Average)
    {
        cout << "\n----------------------------\n";
        cout << "\n Your Average is : " << Average << endl;

        if (CheckAverage(Average) == enPassFail::Pass)
            cout << "\n You Passed" << endl;
        else
            cout << "\n You Faild\n";

        cout << "\n----------------------------\n";

    }
    //-------------------------------------------------------------------------

    //[12]_Max Of Two Numbers
    struct stTwoNumbers
    {

        int Number1, Number2,Number3;

    };
    static stTwoNumbers Read2Numbers()
    {
        stTwoNumbers Info;
        cout << "please enter Number1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Info.Number2;
        return Info;
    }
    static int Maxof2Numbers(stTwoNumbers Info)
    {
        if (Info.Number1 > Info.Number2)
            return Info.Number1;
        else
            return Info.Number2;
    }
    static void PrintMaximumOf2Numbers(stTwoNumbers Info)
    {
        cout << "-----------------------------------------\n";
        cout << "The Maximum Number of [ " << Info.Number1 << " , " << Info.Number2 << " ] " << " is : " << Maxof2Numbers(Info) << endl;
        cout << "-----------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read2Numbers2(int& Number1, int& Number2)
    {
        cout << "please enter Number1 ?\n => ";
        cin >> Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Number2;
    }
    static int Maxof2Numbers2(int Number1, int Number2)
    {

        if (Number1 > Number2)
            return Number1;
        else
            return Number2;
    }
    static void PrintMaximumOf2Numbers2( int Number1, int Number2)
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Number1 << " , " << Number2 << " ] " << " is : " << Maxof2Numbers2(Number1, Number2) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read2Numbers3(int Array[2])
    {
        for (int i = 0;i < 2;i++)
        {
            printf("please enter number %d ?\n => ", i + 1);
            cin >> Array[i];
        }
    }
    static int Maxof2Numbers3(int Array[2])
    {
        if (Array[0] == Array[1])
            return 0;
        for (int i = 0;i < 2;i++)
        {

            if (Array[i] > Array[i+1])
                return Array[i];
            else
                return Array[i + 1];
        }
    }
    static void PrintMaximumOf2Numbers3(int Array[2])
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ ";
        for (int i = 0;i < 2;i++)
        {
           cout<< Array[i];
           if (i == 1)
               break;

           cout << " , ";
        }
        cout<<" ] " << " is : " << Maxof2Numbers3(Array) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
   
    //[13]_Max Of Three Numbers
    static stTwoNumbers Read3Numbers()
    {
        stTwoNumbers Info;
        cout << "please enter Number1 ?\n => ";
        cin >> Info.Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Info.Number2;
        cout << "please enter Number3 ?\n => ";
        cin >> Info.Number3;
        return Info;
    }
    static int Maxof3Numbers(stTwoNumbers Info)
    {
        // 1 2 3
        if (Info.Number1 == Info.Number2 == Info.Number3)
            return 0;
        if (Info.Number1 > Info.Number2)
            if (Info.Number1 > Info.Number3)
                return Info.Number1;
            else
                return Info.Number3;

        else
            if (Info.Number2 > Info.Number3)
                return Info.Number2;
            else
                return Info.Number3;

    }
    static void PrintMaximumOf3Numbers(stTwoNumbers Info)
    {
        cout << "--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Info.Number1 << " , " << Info.Number2 << " , " << Info.Number3 << " ] " << " is : " << Maxof3Numbers(Info) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read3Numbers2(int& Number1, int& Number2 , int& Number3)
    {
        cout << "please enter Number1 ?\n => ";
        cin >> Number1;
        cout << "please enter Number2 ?\n => ";
        cin >> Number2;
        cout << "please enter Number3 ?\n => ";
        cin >> Number3;
    }
    static int Maxof3Numbers2(int Number1, int Number2, int Number3)
    {
        // 1 2 3
        if (Number1 == Number2 == Number3)
            return 0;
        if (Number1 > Number2)
            if (Number1 > Number3)
                return Number1;
            else
                return Number3;

        else
            if (Number2 > Number3)
                return Number2;
            else
                return Number3;

    }
    static void PrintMaximumOf3Numbers2(int Number1, int Number2, int Number3)
    {
        cout << "--------------------------------------------\n";
        cout << "The Maximum Number of [ " << Number1 << " , " << Number2 << " , " << Number3 << " ] " << " is : " << Maxof3Numbers2(Number1, Number2, Number3) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void Read3Numbers3(int Array[3])
    {
        for (int i = 0;i < 3;i++)
        {
            printf("please enter number %d ?\n => ", i + 1);
            cin >> Array[i];
        }
    }
    static int Maxof3Numbers3(int Array[3])
    {
        // 1 2 3

        if (Array[0] == Array[1] == Array[2])
            return 0;
        if (Array[0] > Array[1])
            if (Array[0] > Array[2])
                return Array[0];
            else
                return Array[2];

        else
            if (Array[1] > Array[2])
                return Array[1];
            else
                return Array[2];

    }
    static void PrintMaximumOf3Numbers3(int Array[3])
    {
        cout << "\n--------------------------------------------\n";
        cout << "The Maximum Number of [ ";
        for (int i = 0;i < 3;i++)
        {
            cout << Array[i];
            if (i == 2)
                break;

            cout << " , ";
        }
        cout << " ] " << " is : " << Maxof3Numbers3(Array) << endl;
        cout << "--------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[14]_Swap Two Numbers
    static void TheNumberBefoureSwap(stTwoNumbers Info)
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Info.Number1 << endl;
        cout << "Number2 = " << Info.Number2 << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP(stTwoNumbers &Info)
    {
        int Temp;
        Temp = Info.Number1;
        Info.Number1 = Info.Number2;
        Info.Number2 = Temp;

    }
    static void TheNumberAfterSwap(stTwoNumbers Info)
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Info.Number1 << endl;
        cout << "Number2 = " << Info.Number2 << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------
    static void TheNumberBefoureSwap2(int Number1, int Number2)
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Number1 << endl;
        cout << "Number2 = " << Number2 << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP2(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;

    }
    static void TheNumberAfterSwap2(int Number1, int Number2)
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Number1 << endl;
        cout << "Number2 = " << Number2 << endl;
        cout << "-----------------------------------\n";


    }
    //-------------------------------------------------------------------------
    static void TheNumberBefoureSwap3(int Array[2])
    {
        cout << "\nBefore Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Array[0] << endl;
        cout << "Number2 = " << Array[1] << endl;
        cout << "-----------------------------------\n";
    }
    static void SwaP3(int Array[2])
    {
        int Temp;
        Temp = Array[0];
        Array[0] = Array[1];
        Array[1] = Temp;

    }
    static void TheNumberAfterSwap3(int Array[2])
    {
        cout << "\nAfter Swap" << endl;
        cout << "-----------------------------------\n";
        cout << "Number1 = " << Array[0] << endl;
        cout << "Number2 = " << Array[1] << endl;
        cout << "-----------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[15]_Rectangle Area
    static void ReadRectangleArea(float& Width, float& Length)
    {
        cout << "Please enter rectangle width ?\n =>";
        cin >> Width;
        cout << "Please enter rectangle length ?\n =>";
        cin >> Length;
    }
    static float CalculateRectangleArea(float Width, float Length)
    {   
        return Width * Length;
    }
    static void PrintRectangleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Rectangle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[16]_Rectangle Area By Diagonal & Side
    static void ReadRectangleAreaBySideAndDiagonal(float& side, float& diagonal)
    {
        cout << "Enter rectangle Side A ?\n =>";
        cin >> side;
        cout << "Enter rectangle diagonal D ?\n =>";
        cin >> diagonal;
    }
    static float RectangleAreaBySideAndDiagonale(float side, float diagonal)
    {
        float Area=0;
        Area = side *( sqrt(pow(diagonal, 2) - pow(side, 2)));
        return Area;
    }
    //-------------------------------------------------------------------------
    
    //[17]_Triangle Area
    static void ReadTriangleArea(float& base, float& Height)
    {
        cout << "Enter triangle Base A ?\n =>";
        cin >> base;
        cout << "Enter triangle Height H ?\n =>";
        cin >> Height;
    }
    static float TriangleArea(float& base, float& Height)
    {
        float Area;
        Area = (base / 2) * Height;
        return Area;
    }
    static void PrintTriangleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Triangle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[18]_Circle Area
    static float ReadRadious()
    {
        float Radious =0;
        cout << "Enter the radiuos R ?\n =>";
        cin >> Radious;
        return Radious;
    }
    static float CircleArea(float Radious)
    {
        float Area;
        const float PI = 3.14/*1592653589793238*/;
        Area = PI * pow(Radious, 2);
        return Area;
    }
    static void PrintCircleArea(float Area)
    {
        cout << "\n------------------------------------------\n";
        cout << "Circle Area = " << Area << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[19]_Circle Area By Diameter
    static float ReadDiameter()
    {
        float Diameter;
        cout << "Enter radious D ?\n =>";
        cin >> Diameter;
        return Diameter;
    }
    static float CircleAreaByDiameter(float Diameter)
    {
        float Area;
        const float PI = 3.14/*1592653589793238*/;
        Area = (PI * pow(Diameter, 2)) / 4;
        return Area ;
    }
    //-------------------------------------------------------------------------

    //[20]_Circle Area Inscribed in a Square
    static float ReadSquareside()
    {
        float A;
        cout << "Enter Square Side A ?\n =>";
        cin >> A;
        return A;
    }
    static float CircleAreaInscribedInSquare(float A)
    {
        float Area=0;
        const float PI = 3.141592653589793238;
        Area = (PI * pow(A, 2)) / 4;
        return Area;
    }
    //-------------------------------------------------------------------------

    //[21]_Circle Area Along The Circumference
    static float ReadCircumference()
    {
        float L;
        cout << "Please Enter  Circumference  ?\n =>";
        cin >> L;
        return L;
    }
    static float CircleAreaByCircumference(float L)
    {
        float Area;
        const float PI = 3.141592653589793238;
        Area = pow(L, 2) / (4 * PI);
        return Area;
    }
    //-------------------------------------------------------------------------

    //[22]_Circle Area Inscribed in an Isosceles Triangle
    static void ReadTraingleData(float& A, float& B)
    {


        cout << "Enter Triangle side A ?\n =>";
        cin >> A;
        cout << "Enter Triangle base B ?\n =>";
        cin >> B;


    }
    static float CircleAreaByTraingle(float A, float B)
    {
        float Area;
        const float PI = 3.14/*1592653589793238*/;
        Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
        return Area;
    }
    //-------------------------------------------------------------------------

    //[23]_Circle Area Described Around an Arbitrary Triangle
    static void ReadTraingleData2(float& A, float& B, float& C)
    {
        cout << "Enter Triangle side A ?\n =>";
        cin >> A;
        cout << "Enter Triangle base B ?\n =>";
        cin >> B;
        cout << "Enter Triangle side C ?\n =>";
        cin >> C;
    }
    static float CircleAreaByATraingle(float A, float B, float C)
    {
        float Area;
        const float PI = 3.14/*1592653589793238*/;
        float P = (A + B + C) / 2;
        float T;
        T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
        Area = PI * pow(T, 2);
        return Area;
    }
    //-------------------------------------------------------------------------

    //[24]_Validate Number In Range
    static bool ValidateNumberInRange(int& Number, int From, int To)
    {

        return (Number >=From && Number<=To);
    }
    static int ReadAge(int From,int To)
    {
        int Age;
        cout << "please enter the age between [ "<<From<<" : "<<To<<" ] ? = >";
        cin >> Age;
        return Age;
    }
    static void PrintAge(int Age,int From, int To)
    {
        if (ValidateNumberInRange(Age, From, To))
        {
            cout << "\n------------------------------------------\n";
            cout << "   Your Age is : [ " << Age << " ] " << endl;
            cout << "------------------------------------------\n";
        }
        else
        {
            cout << "\n------------------------------------------\n";
            cout << "     Is Invalid Age " << endl;
            cout << "------------------------------------------\n";
        }
       
    }
    //-------------------------------------------------------------------------

    //[25]_Read Until Age Between 18 and 45
    static int ReadUntilAgeBetween(int From, int To)
    {
        int Age = 0;
        do
        {
            Age = ReadAge(From, To);

        } while (!ValidateNumberInRange(Age, From, To));

        return Age;
    }
    static void PrintResultAge(int Age, int From, int To)
    {
        cout << "\n------------------------------------------\n";
        cout << "   Your Age is : [ " << Age << " ] " << endl;
        cout << "------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[26]_Print Numbers from 1 to N 
    static void PrintRangeFrom1toN_Usingwhile(int N)
    {
        int Counter = 0;
        cout << "\nRange printed using while Statement : \n";
        while (Counter < N)
        {
            Counter++;
            cout << Counter << endl;
        }
    }
    static void PrintRangeFrom1toN_Using_Dowhile(int N)
    {
        int Counter = 0;
        cout << "\nRange printed using do_while Statement. \n";
        do {
             Counter++;
             cout << Counter << endl;
           } while (Counter < N);
    }
    static void PrintRangeFrom1toN_UsingFor(int N)
    {
        cout << "\nRange printed using For Statement \n";
        for (int Counter = 1;Counter <= N; Counter++)
        {
            cout << Counter << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[27]_Print Numbers from N to 1
    static void PrintRangeFromNto1_Usingwhile(int N)
    {
        int Counter = N+1;
        cout << "\nRange printed using while Statement : \n";
        while (Counter > 1)
        {
            Counter--;
            cout << Counter << endl;
        }
    }
    static void PrintRangeFromNto1_Using_Dowhile(int N)
    {
        int Counter = N+1;
        cout << "\nRange printed using do_while Statement. \n";
        do {
            Counter--;
            cout << Counter << endl;
        } while (Counter > 1);
    }
    static void PrintRangeFromNto1_UsingFor(int N)
    {
        cout << "\nRange printed using For Statement \n";
        for (int Counter =N ;Counter >= 1; Counter--)
        {
            cout << Counter << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[28]_Sum Odd Numbers From 1 to N
    static int SumOddNumbersFrom1toN_Usingwhile(int N)
    {
        int Sum = 0;
        int Counter = 0;
        cout << "\nSum Odd Numbers using while Statement. \n";

        while (Counter < N)
        {
            Counter++;
            if (CheckNumberType(Counter) == enNumberType::Odd)
            {
                Sum += Counter;
            }
        }
        return Sum;
    }
    static int SumOddNumbersFrom1toN_Using_Dowhile(int N)
    {
        int Sum = 0;
        int Counter = 0;
        cout << "\nSum Odd Numbers using Do_while Statement. \n";
        do 
        {
            Counter++;
            if (CheckNumberType(Counter) == enNumberType::Odd)
            {
                Sum += Counter;
            }
        } while (Counter < N);
        return Sum;
    }
    static int SumOddNumbersFrom1toN_UsingFor(int N)
    {
        int Sum = 0;
        cout << "\nSum Odd Numbers using For Statement \n";
        for (int Counter = 1;Counter <= N; Counter++)
        {
            if (CheckNumberType(Counter) == enNumberType::Odd)
            {
                Sum += Counter;
            }
        }
        return Sum;
    }
    static vector<int>ReadAllOddNumbers(int N)
    {
        vector<int>vReadNumbers;
        for (int Counter = 1;Counter <= N; Counter++)
        {
            if (CheckNumberType(Counter) == enNumberType::Odd)
            {
        
                vReadNumbers.push_back(Counter);
            }
        }
        return vReadNumbers;
    }
    static void PrintTheOddNumberFormTheVector(vector<int>vNumbers)
    {
        for (int i = 0; i < vNumbers.size();i++)
        {
            cout << vNumbers.at(i);
            if (i == vNumbers.size() - 1)
                break;
            cout << " , ";
        }
    }
    static void PrintTheOddNumbersFrom1ToN(int N )
    {
        cout << "\n------------------------------\n";
        cout << "   The Odd Numbers ." << endl;
        cout << "------------------------------\n";
        cout << "\nFrom 1 to " << N << " [";
        vector<int>_vNumbers = ReadAllOddNumbers(N);
        PrintTheOddNumberFormTheVector(_vNumbers);
        cout << "] \n";
    }
    //-------------------------------------------------------------------------

    //[29]_Sum Even Numbers from 1 to N
    static int SumEvenNumbersFrom1toN_Usingwhile(int N)
    {
        int Sum = 0;
        int Counter = 0;
        cout << "\nSum Even Numbers using while Statement. \n";

        while (Counter < N)
        {
            Counter++;
            if (CheckNumberType(Counter) == enNumberType::Even)
            {
                Sum += Counter;
            }
        }
        return Sum;
    }
    static int SumEvenNumbersFrom1toN_Using_Dowhile(int N)
    {
        int Sum = 0;
        int Counter = 0;
        cout << "\nSum Even Numbers using Do_while Statement. \n";
        do
        {
            Counter++;
            if (CheckNumberType(Counter) == enNumberType::Even)
            {
                Sum += Counter;
            }
        } while (Counter < N);
        return Sum;
    }
    static int SumEvenNumbersFrom1toN_UsingFor(int N)
    {
        int Sum = 0;
        cout << "\nSum Even Numbers using For Statement \n";
        for (int Counter = 1;Counter <= N; Counter++)
        {
            if (CheckNumberType(Counter) == enNumberType::Even)
            {
                Sum += Counter;
            }
        }
        return Sum;
    }
    static vector<int>ReadAllEvenNumbers(int N)
    {
        vector<int>vReadNumbers;
        for (int Counter = 1;Counter <= N; Counter++)
        {
            if (CheckNumberType(Counter) == enNumberType::Even)
            {

                vReadNumbers.push_back(Counter);
            }
        }
        return vReadNumbers;
    }
    static void PrintTheEvenNumberFormTheVector(vector<int>vNumbers)
    {
        for (int i = 0; i < vNumbers.size();i++)
        {
            cout << vNumbers.at(i);
            if (i == vNumbers.size() - 1)
                break;
            cout << " , ";
        }
    }
    static void PrintTheEvenNumbersFrom1ToN(int N)
    {
        cout << "\n------------------------------\n";
        cout << "   The Even Numbers ." << endl;
        cout << "------------------------------\n";
        cout << "\nFrom 1 to " << N << " [";
        vector<int>_vNumbers = ReadAllEvenNumbers(N);
        PrintTheEvenNumberFormTheVector(_vNumbers);
        cout << "] \n";
    }
    //-------------------------------------------------------------------------

    //[30]_Factorial of N!
    static int ReadPositiveNumber(string Message)
    {
        int Number;
        do 
        {
            cout << Message <<" => ";
            cin >> Number;

        } while (Number <= 0);
        return Number;
    }
    static float ReadNegativNumber(string Message)
    {
        int Number;
        do
        {
            cout << Message << " => ";
            cin >> Number;

        } while (Number >= 0);
        return Number;
    }
    static int Factorial(int N)
    {
        int F = 1;
        for (int Count = N;Count >= 1;Count--)
        {
            F *= Count;
        }
        return F;
    }
    static void PrintFactorail(int N)
    {
        cout << "\nResult = ";
        for (int i = N;i >= 1; i--)
        {
            cout << i;
            if (i == 1)
            {
                break;
            }
            cout << " * ";
        }
        cout << " = " << Factorial(N) << endl;
    }
    //-------------------------------------------------------------------------
    
    //[31]_Power of 2,3,4
    static void PowerOf2_3_4(int Number)
    {
        int a, b, c;
        a = Number * Number;
        b = a * Number;
        c = b * Number;

        cout <<"\n"<< a << " " << b << " " << c<<endl;
    }
    //-------------------------------------------------------------------------

    //[32]_Power of M
    static int ReadPower()
    {
        int Number;
        cout << "please enter The   power  ? m=> ";
        cin >> Number;
        return Number;
    }
    static int PowerOfM(int Number, int M)
    {
        if (M == 0)
        {
            //Any Number Powered to Zero gives 1
            return 1;
        }
        int P = 1;
        for (int i = 1;i <= M;i++)
        {
            P = P * Number;    
        }
        return P;
    }
    static void PrintPowerOfM(int Number, int M)
    {

        cout << "\nResult = "<<Number<<"^"<<M<<" = ";
        for (int i = 1;i <= M;i++)
        {
            cout << Number;
            if (i == M)
            {
                break;
            }
            cout << " * ";
        }
        cout << " = " << PowerOfM(Number, M) << endl;

    }
    //-------------------------------------------------------------------------
    enum enMenue
    {
        CheckNumberOddOrEven=1,
        SumOddNumbers=2,
        SumEvenNumbers=3,
        AllOptions=4,
        FactorialofN=5,
        NumberOfPow2_3_4=6,
        NumberOfPowerM=7
    };
    static void GoBackToMenue2()
    {

        cout << "\nPlease enter any key to back to Menue....";
        system("pause>0");
        ShowMenue();

    }
    static enMenue ReadOption(string Message)
    {
        int Number = 0;
        do
        {
           // cout << "Please enter Numbr From [1:7] ? => ";
            cout << Message << " => ";
            cin >> Number;
        } while (Number < 1 || Number>7);
        return (enMenue)Number;
    }
    static void  DoOption(enMenue Op)
    {
        int Number = 0;
        switch (Op)
        {

            case enMenue ::CheckNumberOddOrEven :
                system("cls");
                Number = ReadNumber("Please Enter a Number ? ");
                PrintNumberType(ClsUtil1::CheckNumberType(Number), Number);
                GoBackToMenue2();
                break;
            case enMenue::SumOddNumbers :
                system("cls");
                Number = ReadNumber("please enter Number?");
                PrintTheOddNumbersFrom1ToN(Number);
                cout <<SumOddNumbersFrom1toN_Usingwhile(Number) << endl;
                cout <<SumOddNumbersFrom1toN_Using_Dowhile(Number) << endl;
                cout <<SumOddNumbersFrom1toN_UsingFor(Number) << endl;
                GoBackToMenue2();
                break;
            case enMenue::SumEvenNumbers:
                system("cls");
                Number = ReadNumber("please enter Number?");
                PrintTheEvenNumbersFrom1ToN(Number);
                cout <<SumEvenNumbersFrom1toN_Usingwhile(Number) << endl;
                cout <<SumEvenNumbersFrom1toN_Using_Dowhile(Number) << endl;
                cout <<SumEvenNumbersFrom1toN_UsingFor(Number) << endl;
                GoBackToMenue2();
                break;
            case enMenue::AllOptions:
                system("cls");
                Number = ReadNumber("please enter Number?");
                PrintTheOddNumbersFrom1ToN(Number);
                cout << SumOddNumbersFrom1toN_Usingwhile(Number) << endl;
                cout << SumOddNumbersFrom1toN_Using_Dowhile(Number) << endl;
                cout << SumOddNumbersFrom1toN_UsingFor(Number) << endl;
                cout << "\n-----------------------------\n";
                PrintTheEvenNumbersFrom1ToN(Number);
                cout << SumEvenNumbersFrom1toN_Usingwhile(Number) << endl;
                cout << SumEvenNumbersFrom1toN_Using_Dowhile(Number) << endl;
                cout << SumEvenNumbersFrom1toN_UsingFor(Number) << endl;
                GoBackToMenue2();
                break;
            case enMenue::FactorialofN:
                system("cls");
                PrintFactorail(ReadPositiveNumber("Please Enter N ? "));
                GoBackToMenue2();
                break;
            case enMenue::NumberOfPow2_3_4:
                system("cls");
                ClsUtil1::PowerOf2_3_4(ReadPositiveNumber("Please Enter N ? "));
                GoBackToMenue2();
                break;
            case enMenue::NumberOfPowerM:
                system("cls");
                PrintPowerOfM(ReadPositiveNumber("Please Enter N ? "),ReadPower());
                GoBackToMenue2();
                break;
        }
    }
    static void ShowMenue()
    {
        system("cls");
        cout << "------------[ The Minue ]------------\n";
        cout << "1 : Check Number Odd Or Even .\n";
        cout << "2 : Sum Odd Numbers . \n";
        cout << "3 : Sum Even Numbers . \n";
        cout << "4 : All Options . \n";
        cout << "5 : Factorial of N .\n";
        cout << "6 : Number Of Pow2,3,4 .\n";
        cout << "7 : Number of power M .\n";
        cout << "--------------------------------------\n";
        DoOption(ReadOption("Please enter Numbr From[1:7] ?"));
    }
    //-------------------------------------------------------------------------

    //[33]_Grade A,B,C,D,E,F
    static int ReadNumberInRange(int From, int To)
    {
        int Grade;
        do 
        {
            cout << "please enter your Grade between [ " << From << " , " << To << " ] ? => ";
            cin >> Grade;
        } while (!ValidateNumberInRange(Grade,From,To));
        return Grade;
    }
    static char GetGradeLeter(int Grade)
    {
        if (Grade >= 90)
        {
            return 'A';
        }
        else if (Grade >= 80)
        {
            return 'B';
        }
        else if (Grade >= 70)
        {
            return 'C';
        }
        else if (Grade >= 60)
        {
            return 'D';
        }
        else if (Grade >= 50)
        {
            return 'E';
        }
        else
        {
            return 'F';
        }
    }
    //-------------------------------------------------------------------------

    //[34]_Commition Percentage
    static float ReadTotalSales()
    {
        float TotalSales;
        cout << "please enter Total sales ? \n => ";
        cin >> TotalSales;
        return TotalSales;
    }
    static float GetComisionPercantage(int TotalSales)
    {
        if (TotalSales > 1000000)
        {
            return(0.01);
        }
        else if (TotalSales > 500000)
        {
            return (0.02);
        }
        else if (TotalSales > 100000)
        {
            return (0.03);
        }
        else if (TotalSales > 50000)
        {
            return (0.05);
        }
        else
        {
            return 0.00;
        }
    }
    static float CalculateComition(float TotalSales)
    {
        return GetComisionPercantage(TotalSales) * TotalSales;
    }
    static void PrintResultCommition()
    {

        float TotalSales = ReadTotalSales();
        cout << "Comission = " << GetComisionPercantage(TotalSales) << endl;
        cout << "CalcolatComission = " << CalculateComition(TotalSales) << endl;

    }
    //-------------------------------------------------------------------------

    //[35]_Pig Bank Calculator
    struct stPiggyBankContenet
    {
        int Pennies, Nickels, Dimes, Quarters, Dollars;
    };
    static stPiggyBankContenet ReadPiggyBankCountet()
    {
        stPiggyBankContenet PiggyBankContenet;
        cout << "please enter Pennies ?\n => ";
        cin >> PiggyBankContenet.Pennies;
        cout << "please enter Nickels ?\n => ";
        cin >> PiggyBankContenet.Nickels;
        cout << "please enter Dimes ?\n => ";
        cin >> PiggyBankContenet.Dimes;
        cout << "please enter Quarters ?\n => ";
        cin >> PiggyBankContenet.Quarters;
        cout << "please enter Dollars ?\n => ";
        cin >> PiggyBankContenet.Dollars;
        return  PiggyBankContenet;
    }
    static int  CalculateTotalPennies(stPiggyBankContenet PiggyBankContenet)
    {
        float TotalPennies = 0;
        TotalPennies = PiggyBankContenet.Pennies * 1 + PiggyBankContenet.Nickels * 5 + PiggyBankContenet.Dimes * 10 + PiggyBankContenet.Quarters * 25 + PiggyBankContenet.Dollars * 100;
        return TotalPennies;
    }
    static float CalculateTotalDollers(stPiggyBankContenet PiggyBankContenet)
    {

        float TotalDollers = 0;
        TotalDollers = PiggyBankContenet.Pennies * 0.01 + PiggyBankContenet.Nickels * 0.05 + PiggyBankContenet.Dimes * 0.1 + PiggyBankContenet.Quarters * 0.25 + PiggyBankContenet.Dollars * 1;

        return TotalDollers;
    }
    static void PrintResultPigBankCalculator()
    {
        stPiggyBankContenet PiggyBankContenet = ReadPiggyBankCountet();
        int TotalPennies = CalculateTotalPennies(PiggyBankContenet);
        float TotalDollers = CalculateTotalDollers(PiggyBankContenet);
        cout << "\nTotalPennies  = " << TotalPennies << endl;
        cout << "TotalDollers1 = " << (float)TotalPennies / 100 << endl;
        cout << "TotalDollers2 = " << TotalDollers << endl;
    }
    //-------------------------------------------------------------------------

    //[36]_Simple Calculator
    enum enOpetationType 
    { 
        Sum = 1, 
        Subtract = 2,
        Multiplay = 3, 
        Devide = 4, 
        AllOptions1 = 5 
    };
    static int CheckOption(string Message,int From,int To)
    {
        int  OT = 0;
        do
        {
            cout << Message << " => ";
            cin >> OT;

        } while (OT<From || OT>To);
        return OT;
    }
    static enOpetationType ReadOperation()
    {
        cout << "-------------[ Minue of Operation ]-------------\n";
        cout << "1 : ( + )  Sum .\n";
        cout << "2 : ( -  ) Subtract .\n";
        cout << "3 : ( * )  Multiplay  .\n";
        cout << "4 : ( / )  Devide.\n";
        cout << "5 : (+ - * / ) AllOptions .\n";
        cout << "----------------------------------------------\n";
        return (enOpetationType)CheckOption(" Enter operation ",1,5);
    }
    static float Calculate(float Number1, float Number2, enOpetationType Opytype)
    {
        switch (Opytype)
        {
        case enOpetationType::Sum:
            return Number1 + Number2;
        case enOpetationType::Subtract:
            return Number1 - Number2;
        case enOpetationType::Multiplay:
            return Number1 * Number2;
        case enOpetationType::Devide:
            if (Number1 == 0 || Number2 == 0)
                return 1;
            else
                return Number1 / Number2;
        default:
            return Number1 + Number2;
        }
    }
    static void PrintResultOfSimpleCalculate()
    {
        float Number1 = ReadNumber("please enter Number 1 ?\n");
        float Number2 = ReadNumber("please enter Number 2?\n");
        enOpetationType Opytype = ReadOperation();
        float Number3 = Calculate(Number1, Number2, Opytype);
        cout << "\nResult = " << Number3 << endl;
    }
    //-------------------------------------------------------------------------
    static void GoBackToMenue3(float Number1, float Number2)
    {

        cout << "\nPlease enter any key to back to Menue....";
        system("pause>0");
        ShowMenueOfOperation(Number1, Number2);

    }
    static void ReturnResultOfOperation(float Number1, float Number2, enOpetationType OpType)
    {
        switch (OpType)
        {
        case enOpetationType::Sum:
            system("cls");
            cout << "The Sum = " << Number1 << " + " << Number2 << " = " << Calculate(Number1, Number2, OpType) << endl;
            GoBackToMenue3(Number1, Number2);
            break;
        case enOpetationType::Subtract:
            system("cls");
            cout << "The Subtract = " << Number1 << " - " << Number2 << " = " << Calculate(Number1, Number2, OpType) << endl;
            GoBackToMenue3(Number1, Number2);
            break;
        case enOpetationType::Multiplay:
            system("cls");
            cout << "The Multiplay = " << Number1 << " * " << Number2 << " = " << Calculate(Number1, Number2, OpType) << endl;
            GoBackToMenue3(Number1, Number2);
            break;
        case enOpetationType::Devide:
            system("cls");
            cout << "The Devide = " << Number1 << " / " << Number2 << " = " << Calculate(Number1, Number2, OpType) << endl;
            GoBackToMenue3(Number1, Number2);
            break;
        case enOpetationType::AllOptions1:
            system("cls");
            cout << "The Sum = " << Number1 << " + " << Number2 << " = " << Calculate(Number1, Number2, enOpetationType::Sum) << endl;
            cout << "The Subtract = " << Number1 << " - " << Number2 << " = " << Calculate(Number1, Number2, enOpetationType::Subtract) << endl;
            cout << "The Multiplay = " << Number1 << " * " << Number2 << " = " << Calculate(Number1, Number2, enOpetationType::Multiplay) << endl;
            cout << "The Devide = " << Number1 << " / " << Number2 << " = " << Calculate(Number1, Number2, enOpetationType::Devide) << endl;
            GoBackToMenue3(Number1, Number2);
            break;
        }

    }
    static void ShowMenueOfOperation(float Number1, float Number2)
    {
        system("cls");
        cout << "-------------[ Minue of Operation ]-------------\n";
        cout << "1 : ( + )  Sum .\n";
        cout << "2 : ( -  ) Subtract .\n";
        cout << "3 : ( * )  Multiplay  .\n";
        cout << "4 : ( / )  Devide.\n";
        cout << "5 : (+ - * / ) AllOptions .\n";
        cout << "----------------------------------------------\n";
        ReturnResultOfOperation(Number1,Number2,(enOpetationType)CheckOption(" Enter operation ", 1, 5));
    }
    static void PrintResultOfSimpleCalculate2()
    {
        float Number1 = ReadNumber("please enter Number 1 ?\n");
        float Number2 = ReadNumber("please enter Number 2?\n");
        ShowMenueOfOperation(Number1, Number2);
    }
    //-------------------------------------------------------------------------

    //[37]_Sum Until -99
    static float SumNumbers()
    {
        int Sum = 0, Number = 0,Counter=0;
        do {
            Number = ReadNumber("Please enter Number " + to_string(Counter + 1));
            if (Number == -99)
            {
                break;
            }
            Sum += Number;
            Counter++;
        } while (Number != -99);
        return Sum;
    }
    //-------------------------------------------------------------------------
    
    //[38]_Prime Number
    static enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
    static enPrimeNotPrime CheckPrime(int Number)
    {
        int M = round(Number / 2);
        for (int Counter = 2; Counter <= M;Counter++)
        {
            if (Number % Counter == 0)
            {
                return enPrimeNotPrime::NotPrime;
            }
        }
        return enPrimeNotPrime::Prime;
    }
    static void PrintNumberType(int Number)
    {
        switch (CheckPrime(Number))
        {
        case enPrimeNotPrime::Prime:
            cout << "\nThe number : " + to_string(Number) + " is prime. " << endl;
            break;
        case enPrimeNotPrime::NotPrime:
            cout << "\nThe number : [ " + to_string(Number) + " ] is Not prime. " << endl;
            break;
        }
    }
    //-------------------------------------------------------------------------

    //[39]_Pay Remainder
    static float CalculateRemainder(float TotalBill, float TotalCashPaid)
    {
        return TotalCashPaid - TotalBill;
    }
    static void PrintResultOfPayRemainder()
    {
        float TotalBill, TotalCashPaid;
        TotalBill = ReadPositiveNumber("Enter Total Bill ? \n");
        TotalCashPaid = ReadPositiveNumber("Enter Total Cash Paid ? \n");

        cout << "----------------------------------------------\n";
        cout << "Total Bill       : " << TotalBill << endl;
        cout << "Total Cash Paid  : " << TotalCashPaid << endl;
        cout << "----------------------------------------------\n";
        cout << "Remainder : " << CalculateRemainder(TotalBill, TotalCashPaid);
        cout << endl;
    }
    //-------------------------------------------------------------------------

    //[40]_Service Fee and Sales Tax
    static float CalculateRemainder(float TotalBill)
    {
        TotalBill = TotalBill * 1.1;
        TotalBill = TotalBill * 1.16;
        return TotalBill;
    }
    static void PrintResultOfServiceFeeAndSalesTax( )
    {
        float TotalBill = ReadPositiveNumber("Please Enter Total Bill ? \n");
        cout << "----------------------------------------------\n";
        cout << "Total Bill   : " << TotalBill << endl;
        cout << "-------------------------------------------------\n";
        cout << "Total Bill Value After Service Fee and Sales Tax : " << CalculateRemainder(TotalBill);
        cout << endl;
        cout << "------------------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[41]_Weeks and Days
    static float HoursToDays(int NumberOfHouers)
    {
        float  Days;
        Days = (float)NumberOfHouers / 24;
        return  Days;
    }
    static float HoursToWeeks(int NumberOfHouers)
    {
        float Weeks;
        Weeks = (float)(NumberOfHouers / 24) / 7;
        return Weeks;
    }
    static float DaysToWeeks(int NumberOfDays)
    {
        float Weeks;
        Weeks = (float)NumberOfDays / 7;
        return Weeks;
    }
    static void PrintData()
    {
        float NumberOfHouers = ReadPositiveNumber("please enter Number Of Houers ? \n");
        float NumberOfDay = HoursToDays(NumberOfHouers);
        float NumberOfWeeks1 = HoursToWeeks(NumberOfHouers);
        float NumberOfWeeks2 = DaysToWeeks(NumberOfDay);

        cout << "\n----------------------------------------------\n";
        cout << "Total Hours : " << NumberOfHouers << endl;
        cout << "Total Days  : " << NumberOfDay<< endl;
        cout << "Total Weeks : " << NumberOfWeeks1 << endl;
        cout << "Total Weeks : " << NumberOfWeeks2 << endl;
        cout << "----------------------------------------------\n";
    }
    //-------------------------------------------------------------------------

    //[42]_Task Duration In Seconds
    struct strTaskDuration
    {
        int NumberOfDays;
        int NumberOfHours;
        int NumberOfMinutes;
        int NumberOfSeconds;
    };
    static strTaskDuration ReadTaskDuration()
    {
        strTaskDuration TaskDuration;
        TaskDuration.NumberOfDays = ReadPositiveNumber("Enter Number Of Days ?");
        TaskDuration.NumberOfHours = ReadPositiveNumber("Enter Number Of Hours ?");
        TaskDuration.NumberOfMinutes = ReadPositiveNumber("Enter Number Of Minutes ?");
        TaskDuration.NumberOfSeconds = ReadPositiveNumber("Enter Number Of Seconds ?");
        return TaskDuration;
    }
    static int TaskDurationInSecond(strTaskDuration TaskDuration)
    {
        int DurationInSecend = 0;
        DurationInSecend = TaskDuration.NumberOfDays * 24 * 60 * 60;
        DurationInSecend += TaskDuration.NumberOfHours * 60 * 60;
        DurationInSecend += TaskDuration.NumberOfMinutes * 60;
        DurationInSecend += TaskDuration.NumberOfSeconds;
        return DurationInSecend;
    }
    //-------------------------------------------------------------------------

    //[43]_Second To Days Hours Minutes Seconds
    static strTaskDuration SecondsToTaskDuration(int TotalSecond)
    {
        strTaskDuration TaskDuration;
        const int SecondsPerDay = 24 * 60 * 60;
        const int SecondsPerHour = 60 * 60;
        const int SecondsPerMinute = 60;

        int Remainder = 0;
        TaskDuration.NumberOfDays = floor(TotalSecond / SecondsPerDay);
        Remainder = TotalSecond % SecondsPerDay;
        TaskDuration.NumberOfHours = floor(Remainder / SecondsPerHour);
        Remainder = Remainder % SecondsPerHour;
        TaskDuration.NumberOfMinutes = floor(Remainder / SecondsPerMinute);
        Remainder = Remainder % SecondsPerMinute;
        TaskDuration.NumberOfSeconds = Remainder;
        return TaskDuration;
    }
    static void PrintTaskDurationDetails(strTaskDuration TaskDuration)
    {
        cout << "\n";
        cout << "\t\t---------------\n";
        cout << "\t\t";
        cout << TaskDuration.NumberOfDays << " : "
             << TaskDuration.NumberOfHours << " : "
             << TaskDuration.NumberOfMinutes << " : "
             << TaskDuration.NumberOfSeconds;
        cout << "\n\t\t---------------\n";
    }
    //-------------------------------------------------------------------------

    //[44]_Day Of Week
    enum enDayOfWeek { Sat = 1,Sun = 2, Mon = 3, Teu = 4, Wed = 5, Thue = 6, Frid = 7 };
    static int ReadNumberInRange2(int From, int To,string Message)
    {
        int Number;
        do
        {
            cout << Message << " [ "<<From << " , " << To << " ] ? => ";
            cin >> Number;
        } while (!ValidateNumberInRange(Number, From, To));
        return Number;
    }
    static void ShowDayOfWeek()
    {
        cout << "----------------------------------------\n";
        cout << "\tMenue Of Days In Week\n";
        cout << "----------------------------------------\n";
        cout << "1: Saturday  \n";
        cout << "2: Sunday  \n";
        cout << "3: Monday  \n";
        cout << "4: Tuesday  \n";
        cout << "5: Wednesday\n";
        cout << "6: Thuresday \n";
        cout << "7: Friday\n";
        cout << "8: other\n";
        cout << "----------------------------------------\n";
    }
    static enDayOfWeek ReadDayOfWeek()
    {
        int Number = ReadNumberInRange2(1, 8, "Enter Number of Day Between ");
        return (enDayOfWeek)Number;
    }
    static string GetDayOfWeek(enDayOfWeek Day)
    {
      switch (Day)
      {
        case enDayOfWeek::Sat:
            return " Saturday \n";
        case enDayOfWeek::Sun:
            return " Sunday \n";
        case enDayOfWeek::Mon:
            return " Monday \n";
        case enDayOfWeek::Teu:
            return " Tuesday \n";
        case enDayOfWeek::Wed:
            return " Wednesday \n";
        case enDayOfWeek::Thue:
            return " Thuresday \n";
        case enDayOfWeek::Frid:
            return " Friday \n";
        default:
            return " Not Week day ! \n";
      }
    }
    static void PrintResultDayOfWeek()
    {
        ShowDayOfWeek();
        string Day = GetDayOfWeek(ReadDayOfWeek());
        cout << "\nResult = " << Day << endl;
    }
    //-------------------------------------------------------------------------
    
    //[45]_Month Of Year
    enum enMonthOfYear { January = 1, Febuary = 2, March = 3, April = 4, May = 5, June = 6, July = 7, Agust = 8, September = 9, October = 10, November = 11, Desember = 12 };
    static void Show_MonthOfYear()
    {
        cout << "----------------------------------------\n";
        cout << "  Menue  Of Monthes In Year\n";
        cout << "----------------------------------------\n";
        cout << "1 : January \n";
        cout << "2 : February  \n";
        cout << "3 : March  \n";
        cout << "4 : April  \n";
        cout << "5 : May\n";
        cout << "6 : Jun \n";
        cout << "7 : July\n";
        cout << "8 : August\n";
        cout << "9 : September\n";
        cout << "10: October\n";
        cout << "11: November\n";
        cout << "12: December\n";
        cout << "----------------------------------------\n";   
    }
    static enMonthOfYear ReadMonthOfYear()
    {
        enMonthOfYear MonthOfYear;
        int Month = ReadNumberInRange2(1, 12, "Enter Number of Month Between ");
        return (enMonthOfYear)Month;
    }
    static string GetMonthOfYear(enMonthOfYear Month)
    {
       switch (Month)
       {
        case enMonthOfYear::January:
            return " January \n";
        case enMonthOfYear::Febuary:
            return " February \n";
        case enMonthOfYear::March:
            return " March \n";
        case enMonthOfYear::April:
            return " April \n";
        case enMonthOfYear::May:
            return " May \n";
        case enMonthOfYear::June:
            return " Jun \n";
        case enMonthOfYear::July:
            return " July \n";
        case enMonthOfYear::Agust:
            return " August \n";
        case enMonthOfYear::September:
            return " September \n";
        case enMonthOfYear::October:
            return " October \n";
        case enMonthOfYear::November:
            return " November \n";
        case enMonthOfYear::Desember:
            return " December \n";
        default:
            return " Not avalid Month ! \n";
       }
    }
    static void PrintResultMonthOfYear()
    {
        Show_MonthOfYear();
        string Month = GetMonthOfYear(ReadMonthOfYear());
        cout << "\nResult = " << Month << endl;
    }
    //-------------------------------------------------------------------------

    //[46]_Print Letters From A to Z
    static void  PrintLetterAtoZ()
    {
        cout << "\n  ------------------------------------------------------\n  [";
        for (int i = 65;i <= 90; i++)
        {
            cout << char(i);
            if (i == 90)
            {
                break;
            }
            cout << "-";
        }
        cout << " ] \n  ------------------------------------------------------\n";
        for (int i = 65;i <= 90; i++)
        {
            cout << "\t\t\t [-" << char(i);
            if (i == 91)
            {
                break;
            }
            cout << "-]\n";
        }
        cout << "\n\t----------------------------------------\n";
    }
    //-------------------------------------------------------------------------
    
    //[47]_Loan Installment Months
    static float TotalMonths(float LoanAmount, float MonthlyInstallement)
    {
        return LoanAmount / MonthlyInstallement;
    }
    static void PrintResultLoanInstallmentMonths()
    {
        float LoanAmount = ReadPositiveNumber("Please enter Loan Amount ?");
        float MonthlyInstallement = ReadPositiveNumber("Please enter Monthly Insatlement ?");
        cout << "\n Total Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallement) << " months ." << endl;
    }
    //-------------------------------------------------------------------------

    //[48]_Monthly Loan Installment
    static float MonthlyInstallment(float LoanAmount, float HowManyMonths)
    {
        return LoanAmount / HowManyMonths;
    }
    static void PrintResultMonthlyLoanInstallment()
    {
        float LoanAmount = ReadPositiveNumber("Please enter Loan Amount ?");
        float HowManyMonths = ReadPositiveNumber("How Many Months ?");
        cout << "\nMonthly Installment = " << MonthlyInstallment(LoanAmount, HowManyMonths) << " months ." << endl;
    }
    //-------------------------------------------------------------------------

    //[49]_ATM PIN
    static string  ReadPinCode()
    {
        string PinCode;
        cout << "please enter your PIN : From 4 Numbers .\n => ";
        cin >> PinCode;
        return PinCode;
    }
    static bool Login()
    {
        string PinCode;
        do {
            PinCode = ReadPinCode();
            if (PinCode == "1234")
            {
                //this will exit the function and return 1.
                return 1;
            }
            else
            {
                cout << "\n Wrong PIN !!\n";
                //return screen to Red.
                system("color 4F");
            }
        } while (PinCode != "1234");
        //when you reach here this means login faild.
        return 0;
    }
    static void PrintResultATMPIN()
    {
        if (Login())
        {
            //turn screen to green
            system("color 2F");
            cout << "\n Your account balance is " << 7500 << endl;
        }
    }
    //-------------------------------------------------------------------------

    //[50]_ATM PIN 3 Times
    static bool Login2()
    {
        string PinCode;
        int Counter1 = 3;
        int Counter2 = 3;
        int I = 0;
        do {
            Counter1--;
            I++;
            PinCode = ReadPinCode();
            if (PinCode == "1234")
            {
                //this will exit the function and return 1.
                return 1;
            }
            else
            {
                //return screen to Red.
                system("cls");
                system("color 4F");
                cout << "\n Wrong PIN !!\n";
                cout << "You have  [ " + to_string(I) +" :: "+ to_string(Counter2)+" ] more tries !\n";

            }
        } while (Counter1 >= 1 && PinCode != "1234");
        //when you reach here this means login faild.
        return 0;
    }
    static void PrintResultATMPIN3Times()
    {
        if (Login2())
        {
            //turn screen to green
            system("cls");
            system("color 2F");
            cout << "\n Your account balance is " << 7500 << endl;
        }
        else
        {
            system("cls");
            system("color 4F");
            cout << "\n\n\n\n\n\tYour card blocked call the bank for help .\n\n\n\n\n\n";
        }
    }
    //-------------------------------------------------------------------------





};

