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
#include "ClsUtil3.h"

using namespace std;


class ClsUtil4
{

private:



public:

    //[1]_Number To Text
    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
            "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[Number] + " ";
        }
        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }
        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred "+ NumberToText(Number % 100);
        }
        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }
        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }
        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }
        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }
        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return NumberToText(Number / 1000000000) + " Billions " + NumberToText(Number % 1000000000);
        }

    }
    static void PrintNumberToText()
    {
        int Number = ClsUtil1::ReadNumber("Please enter a Number ?");
        cout << "\n" << NumberToText(Number) << endl;
    }
    //-------------------------------------------------------------------------

    //[2]_Leap Year
    static short ReadYear()
    {
        short Year = 0;
        cout << "\nPlease enter a Year to check ?  => ";
        cin >> Year;
        return Year;
    }
    static bool _IsLeapYear(short Year)
    {
        //leap year if perfectly divisible by 400
        if ( Year % 400 == 0)
        {
            return true;
        }
        //not a leap year if divisible by 100
        //but not divisible by 400
        else if (Year % 100 == 0)
        {
            return false;
        }
        //leap year if not divisible by 100
        //but not divisible by 4
        else if (Year % 4 == 0)
        {
            return true;
        }
        //all other years are not leap year
        else 
        {
            return false;
        }
    }
    static void PrintLeapYear()
    {
        short Year = ReadYear();
        if (IsLeapYear(Year))
        {
            cout << "\nYes, Year [" << Year << "] is a leap year.\n";
        }
        else
        {
            cout << "\nNo, Year [" << Year << "] is Not a leap year.\n";
        }
    }
    //-------------------------------------------------------------------------
    static void PrintHeaderOfTable()
    {
        cout << "\n--------------------------------------\n";
        cout << "| " << left << setw(15) << "Leap Year ";
        cout << "| " << left << setw(18) << "Not Leap Year ";
        cout << "|\n--------------------------------------\n";
    }
    static void PrintHeaderOfTableOfText()
    {
        cout << "\n--------------------------------------------------------------------------------------\n";
        cout << "| " << left << setw(40) << "Leap Year ";
        cout << "| " << left << setw(40) << "Not Leap Year ";
        cout << "|\n--------------------------------------------------------------------------------------\n";
    }
    static void MakeTableOfLeapOrNotLeapYear(vector<short> &vAllLeapYear, vector<short> &vAllNOtLeapYear)
    {
        PrintHeaderOfTable();
        short Length1 = vAllLeapYear.size();
        short Length2 = vAllNOtLeapYear.size();
        short Length3 = 0;
        if (Length1 > Length2)
        {
            for (short i = 1;i <= (Length1 - Length2);i++)
            {
                vAllNOtLeapYear.push_back(0);
            }
            Length3 = Length1;
        }
        else if(Length2 > Length1)
        {
            for (short i = 1;i <= (Length2 - Length1);i++)
            {
                vAllLeapYear.push_back(0);
            }
            Length3 = Length2;
        }
        else
        {
            Length3 = Length1;
        }
        for (short i = 0;i < Length3;i++)
        {
            cout << "| " << setw(15) << left << vAllLeapYear[i];
            cout << "| " << setw(18) << left << vAllNOtLeapYear[i];
            cout << "|\n";
        }
        cout << "--------------------------------------\n";
    }
    static void MakeTableOfLeapOrNotLeapYearOfText(vector<short>& vAllLeapYear, vector<short>& vAllNOtLeapYear)
    {
        PrintHeaderOfTableOfText();
        short Length1 = vAllLeapYear.size();
        short Length2 = vAllNOtLeapYear.size();
        short Length3 = 0;
        if (Length1 > Length2)
        {
            for (short i = 1;i <= (Length1 - Length2);i++)
            {
                vAllNOtLeapYear.push_back(0);
            }
            Length3 = Length1;
        }
        else if (Length2 > Length1)
        {
            for (short i = 1;i <= (Length2 - Length1);i++)
            {
                vAllLeapYear.push_back(0);
            }
            Length3 = Length2;
        }
        else
        {
            Length3 = Length1;
        }
        for (short i = 0;i < Length3;i++)
        {
            cout << "| " << setw(40) << left << NumberToText( vAllLeapYear[i]);
            cout << "| " << setw(40) << left << NumberToText(vAllNOtLeapYear[i]);
            cout << "|\n";
        }
        cout << "--------------------------------------------------------------------------------------\n";
    }
    static vector<short> LeapYear(vector<short>& vNumbers)
    {
        vector<short> vAllLeapYear;
        for (short &Y : vNumbers)
        {
            if (IsLeapYear(Y))
            {
                vAllLeapYear.push_back(Y);
            }
        }
        return vAllLeapYear;
    }
    static vector<short> NotLeapYear(vector<short>& vNumbers)
    {
        vector<short> vAllNOtLeapYear;
        for (short& Y : vNumbers)
        {
            if (!IsLeapYear(Y))
            {
                vAllNOtLeapYear.push_back(Y);
            }
        }
        return vAllNOtLeapYear;
    }
    static void PrintTableOfLeapYearByNumber()
    {
        vector<short> vNumbers = { 1968,1971,2004,2002,2006,2012,2010,1200,1700,1600,2013,1800,2000,1900 };
        vector<short> vAllLeapYear = LeapYear(vNumbers);
        vector<short> vAllNOtLeapYear = NotLeapYear(vNumbers);
        MakeTableOfLeapOrNotLeapYear(vAllLeapYear, vAllNOtLeapYear);
    }
    static void PrintTableOfLeapYearByText()
    {
        vector<short> vNumbers = { 1968,1971,2004,2002,2006,2012,2010,1200,1700,1600,2013,1800,2000,1900 };
        vector<short> vAllLeapYear = LeapYear(vNumbers);
        vector<short> vAllNOtLeapYear = NotLeapYear(vNumbers);
        MakeTableOfLeapOrNotLeapYearOfText(vAllLeapYear, vAllNOtLeapYear);
    }
    //-------------------------------------------------------------------------

    //[3]_Leap Year One Line Of Code
    static bool IsLeapYear(short Year)
    {
        // if year is divisible by 4 And  not divisible by 100
        // OR if year is divisible by 400
        //then it is a leap year
        return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
        
    }
    static void PrintLeapYearByOneLineOfCode()
    {
        short Year = ReadYear();
        if (IsLeapYear(Year))
        {
            cout << "\nYes, Year [" << Year << "] is a leap year.\n";
        }
        else
        {
            cout << "\nNo, Year [" << Year << "] is Not a leap year.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[4]_Number Of Days_Hours_Minutes_Seconds In A Year
    static short NumberOfDaysInAYear(short Year)
    {
        return IsLeapYear(Year) ? 366 : 365;
    }
    static short NumberOfHoursInAYear(short Year)
    {
        return NumberOfDaysInAYear(Year) * 24;
    }
    static int NumberOfMinutesInAYear(short Year)
    {
        return NumberOfHoursInAYear(Year) * 60;
    }
    static int NumberOfSecondsInAYear(short Year)
    {
        return NumberOfMinutesInAYear(Year) * 60;
    }
    static void PrintNumberOfDays_Hours_Minutes_SecondsInAYear()
    {
        short Year = ReadYear();
        cout << "\nNumber of Days    in Year [" << Year << "] is : ["
            << NumberOfDaysInAYear(Year)<<"]";
        cout << "\nNumber of Hours   in Year [" << Year << "] is : ["
            << NumberOfHoursInAYear(Year) << "]";
        cout << "\nNumber of Minutes in Year [" << Year << "] is : ["
            << NumberOfMinutesInAYear(Year) << "]";
        cout << "\nNumber of Seconds in Year [" << Year << "] is : ["
            << NumberOfSecondsInAYear(Year) << "]";
    }
    //-------------------------------------------------------------------------

    //[5]_Number Of Days_Hours_Minutes_Seconds In A Month
    static short ReadMonth()
    {
        short Month = 0;
        cout << "\nPlease enter a Month to check ? => ";
        cin >> Month;
        return Month;
    }
    static short _NumberOfDaysInAMonth(short Month,short Year)
    {
        if (Month < 1 || Month > 12)
        {
            return 0;
        }
        if (Month == 2)
        {
            return IsLeapYear(Year) ? 29 : 28;
        }
        short arr31Days[7] = { 1,3,5,7,8,10,12 };
        for (short i = 1;i <= 7;i++)
        {
            if (arr31Days[i - 1] == Month)
            {
                return 31;
            }
        }
        //if you reach here then its 30 days.
        return 30;
    }
    static short NumberOfHoursInAMonth(short Month, short Year)
    {
        return NumberOfDaysInAMonth(Month,Year) * 24;
    }
    static int NumberOfMinutesInAMonth(short Month, short Year)
    {
        return NumberOfHoursInAMonth(Month, Year) * 60;
    }
    static int NumberOfSecondsInAMonth(short Month, short Year)
    {
        return NumberOfMinutesInAMonth(Month, Year) * 60;
    }
    static void PrintNumberOfDays_Hours_Minutes_SecondsInAMonth()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        cout << "\nNumber of Days    in Month [" << Month << "] is : ["
             << _NumberOfDaysInAMonth(Month,Year) << "]";
        cout << "\nNumber of Hours   in Month [" << Month << "] is : ["
             << NumberOfHoursInAMonth(Month, Year) << "]";
        cout << "\nNumber of Minutes in Month [" << Month << "] is : ["
             << NumberOfMinutesInAMonth(Month, Year) << "]";
        cout << "\nNumber of Seconds in Month [" << Month << "] is : ["
             << NumberOfSecondsInAMonth(Month, Year) << "]";
    }
    //-------------------------------------------------------------------------

    //[6]_Number Of Days_Hours_Minutes_Seconds In A Month Short Logic
    static short NumberOfDaysInAMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
        {
            return 0;
        }
        short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
    }
    static void PrintNumberOfDays_Hours_Minutes_SecondsInAMonthShortLogic()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        cout << "\nNumber of Days    in Month [" << Month << "] is : ["
             << NumberOfDaysInAMonth(Month, Year) << "]";
        cout << "\nNumber of Hours   in Month [" << Month << "] is : ["
             << NumberOfHoursInAMonth(Month, Year) << "]";
        cout << "\nNumber of Minutes in Month [" << Month << "] is : ["
             << NumberOfMinutesInAMonth(Month, Year) << "]";
        cout << "\nNumber of Seconds in Month [" << Month << "] is : ["
             << NumberOfSecondsInAMonth(Month, Year) << "]";
    }
    //-------------------------------------------------------------------------

    //[7]_Day Name
    static short ReadDay()
    {
        short Day = 0;
        cout << "\nPlease enter a Day to check ?   => ";
        cin >> Day;
        return Day;
    }
    static short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short a, y, m;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + (12 * a) - 2;
        //Gregorian: 0:Sun,1:Mon,2:Thue...etc.
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }
    static string DayShortName(short DayOfWeekOrder)
    {
        string arrDayNames[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat",};
        return arrDayNames[DayOfWeekOrder];
    }
    static void PrintDayName()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        short Day = ReadDay();
        cout << "\nDate      : " << Day << "/" << Month << "/" << Year;
        cout << "\nDay Order : " << DayOfWeekOrder(Day, Month, Year);
        cout << "\nDay Name  : " << DayShortName(DayOfWeekOrder(Day, Month, Year));
    }
    //-------------------------------------------------------------------------

    //[8]_Month Calendar
    static string MonthShortName(short MonthNumber)
    {
        string Months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
        return Months[MonthNumber-1];
    }
    static void PrintMonthCalendar(short Month, short Year)
    {
        int NumberOfDays = 0;
        //Index of the day from 0 to 6
        int Current = DayOfWeekOrder(1, Month, Year);
        NumberOfDays = NumberOfDaysInAMonth(Month, Year);
        //Print the current month name
        printf("\n ________________%s_________________\n\n", MonthShortName(Month).c_str());
        //Print the Columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
        //Print appropriate spaces
        int i;
        for ( i= 0;i < Current;i++)
        {
            printf("     ");
        }
        for (int j = 1; j <= NumberOfDays;j++)
        {
            printf("%5d", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n ____________________________________\n");
    }
    static void PrintMonthCalendar()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        PrintMonthCalendar(Month, Year);
    }
    //-------------------------------------------------------------------------

    //[9]_Year Calendar
    static void PrintYearCalendar(short Year)
    {
        printf("\n_________________________________\n\n");
        printf("          Calendar - %d\n", Year);
        printf("_________________________________\n");
        for (short i = 1;i <= 12;i ++)
        {
            PrintMonthCalendar(i, Year);
        }
    }
    static void PrintYearCalendar()
    {
        short Year = ReadYear();  
        PrintYearCalendar(Year);
    }
    //-------------------------------------------------------------------------

    //[10]_Days From The Beginning Of Year
    static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
    {
        short TotalDays = 0;
        for (short i = 1;i <= Month - 1;i++)
        {
            TotalDays += NumberOfDaysInAMonth(i, Year);
        }
        TotalDays += Day;
        return TotalDays;
    }
    static void PrintDaysFromTheBeginningOfYear()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        short Day = ReadDay();
        cout << "\nNumber of Days from begining of the year is : ["
            << NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year)<<"] Day(s).\n";
    }
    //-------------------------------------------------------------------------

    //[11]_Date From Day Order In Year
    struct sDate
    {
        short Year;
        short Month;
        short Day;
    };
    static sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
    {
        sDate Date;
        short RemainingDayes = DaysOrderInYear;
        short MonthDays = 0;
        Date.Year = Year;
        Date.Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
            if (RemainingDayes > MonthDays)
            {
                RemainingDayes -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainingDayes;
                break;
            }
        }
        return Date;
    }
    static void PrintDateFromDayOrderInYear()
    {
        short Year = ReadYear();
        short Month = ReadMonth();
        short Day = ReadDay();
        short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year);
        cout << "\nNumber of Days from begining of the year is : ["<< DaysOrderInYear << "] Day(s).\n\n";
        sDate Date;
        Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
        cout << "\nDate for [" << DaysOrderInYear << "] is : "
             << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;
    }
    //-------------------------------------------------------------------------

    //[12]_Add Days To Date
    static sDate ReadFullDate()
    {
        sDate Date;
        Date.Day = ReadDay();
        Date.Month = ReadMonth();
        Date.Year = ReadYear();
        return Date;
    }
    static short RadDaysToAdd()
    {
        short Days = 0;
        cout << "\nHow many days to add ? = > ";
        cin >> Days;
        return Days;
    }
    static sDate DateAddDays(short Days, sDate Date)
    {
        short RemainingDayes = Days+NumberOfDaysFromTheBeginingOfTheYear(Date.Day,Date.Month,Date.Year);
        short MonthDays = 0;
        Date.Month = 1;
        while (true)
        {
            MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
            if (RemainingDayes > MonthDays)
            {
                RemainingDayes -= MonthDays;
                Date.Month++;
                if (Date.Month > 12)
                {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else
            {
                Date.Day = RemainingDayes;
                break;
            }
        }
        return Date;
    }
    static void PrintAddDaysToDate()
    {
        sDate Date = ReadFullDate();
        short Days = RadDaysToAdd();
        Date = DateAddDays(Days, Date);
        cout << "\nDate after adding : [" << Days << "] days is : ";
        cout << Date.Day << " / " << Date.Month << " / " << Date.Year << endl;
    }
    //-------------------------------------------------------------------------

    //[13]_Date1 Less Than Date2
    static bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
    {  
        return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day:false)):false);                                                                                                                                                 
    }
    static void PrintDate1LessThanDate2()
    {
        sDate Date1 = ReadFullDate();
        sDate Date2 = ReadFullDate();

        if (IsDate1BeforeDate2(Date1, Date2))
        {
            cout << "\nYes, Date1 is Less Than To Date2.\n";
        }
        else
        {
            cout << "\nNo, Date1 is Not Less Than To Date2.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[14]_Date1 Equals To Date2
    static bool IsDate1EqualDate2(sDate Date1, sDate Date2)
    {                                  //-|-[----------------------------------True--------------------------------------------] [--False--]
        return (Date1.Year == Date2.Year) ? ((Date1.Day == Date2.Day) ? ((Date1.Month == Date2.Month) ? true : false ) : false ) : false   ;       
                                                                   //-|-[--------------------True--------------------]  [-False-] 
                                                                                                   //-|-[True][False]-    
    }
    static void PrintDate1EqualsToDate2()
    {
        sDate Date1 = ReadFullDate();
        sDate Date2 = ReadFullDate();

        if (IsDate1EqualDate2(Date1, Date2))
        {
            cout << "\nYes, Date1 is Equal To Date2.\n";
        }
        else
        {
            cout << "\nNo, Date1 is Not Equal To Date2.\n";
        }
    }
    //-------------------------------------------------------------------------
    
    //[15]_Last Day Last Month 
    static bool IsLastDayInMonth(sDate Date)
    {
        return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
    }
    static bool IsLastMonthInYear(short Month)
    {
        return (Month == 12);
    }
    static void PrintLastDayLastMonth()
    {
        sDate Date1 = ReadFullDate();
        if (IsLastDayInMonth(Date1))
        {
            cout << "\nYes, Day is Last Day in Month.\n";
        }
        else
        {
            cout << "\nNo, Day is Not Last Day in Month.\n";
        }
        if (IsLastMonthInYear(Date1.Month))
        {
            cout << "\nYes, Month is Last Month in Year.\n";
        }
        else
        {
            cout << "\nNo, Month is Not Last Month in Year.\n";
        }
    }
    //-------------------------------------------------------------------------

    //[16]_Increase Date By One Day
    static sDate IncreaseDateByOneDay(sDate Date)
    {
        if (IsLastDayInMonth(Date))
        {
            if (IsLastMonthInYear(Date.Month))
            {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }
            else
            {
                Date.Day = 1;
                Date.Month++;
            }  
        }
        else
        {
            Date.Day++;
        }
        return Date;
    }
    static void PrintIncreaseDateByOneDay()
    {
        sDate Date1 = ReadFullDate();
        Date1 = IncreaseDateByOneDay(Date1);
        cout << "\nDate after adding One : [" << 1 << "] days is : ";
        cout << Date1.Day << " / " << Date1.Month << " / " << Date1.Year << endl;
    }
    //-------------------------------------------------------------------------

    //[17]_Diff In Days
    static int _GetDifferenceInDays(sDate Date1, sDate Date2,bool IncludeEndDay = false)
    {
        int Days = 0;
        while(IsDate1BeforeDate2(Date1,Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days : Days;
    }
    static void PrintGetDifferenceInDays()
    {
        sDate Date1 = ReadFullDate();
        sDate Date2 = ReadFullDate();
        cout << "\nDiffrence is : [" << GetDifferenceInDays(Date1, Date2) << "] Day(s)\n";
        cout << "\nDiffrence (Including End Day) is : [" << GetDifferenceInDays(Date1, Date2,true) << "] Day(s)\n";
    }
    //-------------------------------------------------------------------------

    //[18]_Your Age In Days
    static sDate GetSystemDate()
    {
        sDate Date;
        time_t t = time(0);
        tm* now = localtime(&t);
        Date.Year = now->tm_year + 1900;
        Date.Month = now->tm_mon + 1;
        Date.Day = now->tm_mday;
        return Date;
    }
    static void PrintYourAgeInDays()
    {
        cout << "\nPlease Enter Your Date of Birth :\n";
        sDate Date1 = ReadFullDate();
        sDate Date2 = GetSystemDate();
        cout << Date2.Day << " / " << Date2.Month << " / " << Date2.Year << endl;

        int Days = GetDifferenceInDays(Date1, Date2, true);
        cout << "\nYour Age is : [" << Days << "] Day(s)\n";
        PrintYourAgeCard(Days+20);
    }
    //-------------------------------------------------------------------------
    static sDate GetAgeWithYearsAndMonthsAndDays(int Days)
    {
        sDate Date;
        Date.Year = Days / 365;
        short RemainingDayes = Days % 365;
        if (RemainingDayes > 0)
        {
            if (RemainingDayes > 30)
            {
                Date.Month = RemainingDayes / 30;
                Date.Day = RemainingDayes % 30;
            }
            else if (RemainingDayes == 30)
            {
                Date.Month = 1;
                Date.Day = 0;
            }
            else
            {
                Date.Month = 0;
                Date.Day = RemainingDayes;
            }   
        }
        else
        {
            Date.Month = 0;
            Date.Day = 0;
        }
        return Date;
    }
    static void PrintYourAgeCard(int Days)
    {
        sDate Date3 = GetAgeWithYearsAndMonthsAndDays(Days);

        cout << "\n:--------------------------------:\n";
        cout << ":  Years  ::  Months  ::  Days   :\n";
        cout << ":--------------------------------:\n";
        cout << ":    " << Date3.Year << "   ::    " << Date3.Month << "     ::   " << Date3.Day << "    :\n";
        cout << ":--------------------------------:\n";


    }
    //-------------------------------------------------------------------------

    //[19]_Diff In Days Negative Days
    static void SwapDates(sDate& Date1, sDate& Date2)
    {
        sDate TempDate;
        TempDate.Year  = Date1.Year;
        TempDate.Month = Date1.Month;
        TempDate.Day   = Date1.Day;

        Date1.Year  = Date2.Year;
        Date1.Month = Date2.Month;
        Date1.Day   = Date2.Day;

        Date2.Year  = TempDate.Year;
        Date2.Month = TempDate.Month;
        Date2.Day   = TempDate.Day;
             
    }
    static int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
    {
        int Days = 0;
        short SwapFlagValue = 1;
        if (!IsDate1BeforeDate2(Date1, Date2))
        {

            SwapDates(Date1, Date2);
            SwapFlagValue = -1;

        }
        while (IsDate1BeforeDate2(Date1, Date2))
        {
            Days++;
            Date1 = IncreaseDateByOneDay(Date1);
        }
        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }
    static void PrintGetDifferenceInDaysNegativeDays()
    {
        sDate Date1 = ReadFullDate();
        sDate Date2 = ReadFullDate();
        cout << "\nDiffrence is : [" << GetDifferenceInDays(Date1, Date2) << "] Day(s)\n";
        cout << "\nDiffrence (Including End Day) is : [" << GetDifferenceInDays(Date1, Date2, true) << "] Day(s)\n";
    }
    //-------------------------------------------------------------------------

    //[20 To 32]_Increase Date Problems
    static sDate IncreaseDateByXDays(short Days,sDate Date)
    {
        for (short i = 1;i <= Days;i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByOneWeek(sDate Date)
    {
        for (short i = 1;i <= 7;i++)
        {
            Date = IncreaseDateByOneDay(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByXWeeks(short Weeks,sDate Date)
    {
        for (short i = 1;i <= Weeks;i++)
        {
            Date = IncreaseDateByOneWeek(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByOneMonth(sDate Date)
    {
        if (Date.Month == 12)
        {
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Month++;
        }
        //last check day in date should not exceed max days in the current month.
        //example if date is 31/1/2022 increase one month should not be 31/2/2022,it should be 28/2/2022.
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    static sDate IncreaseDateByXMonths(short Months, sDate Date)
    {
        for (short i = 1;i <= Months;i++)
        {
            Date = IncreaseDateByOneMonth(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByOneYear(sDate Date)
    {
        Date.Year++;
        return Date;
    }
    static sDate IncreaseDateByXYears(short Years, sDate Date)
    {
        for (short i = 1;i <= Years;i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByXYearsFaster(short Years, sDate Date)
    {
        Date.Year += Years;
        return Date;
    }
    static sDate IncreaseDateByOneDecade(sDate Date)
    {
        //Period of 10 Years.
        Date.Year += 10;
        return Date;
    }
    static sDate IncreaseDateByXDecades(short Decades, sDate Date)
    {
        for (short i = 1;i <= Decades*10;i++)
        {
            Date = IncreaseDateByOneYear(Date);
        }
        return Date;
    }
    static sDate IncreaseDateByXDecadesFaster(short Decades,sDate Date)
    {
        Date.Year += Decades*10;
        return Date;
    }
    static sDate IncreaseDateByOneCentury(sDate Date)
    {
        //Period of 100 Years.
        Date.Year += 100;
        return Date;
    }
    static sDate IncreaseDateByOneMillennium(sDate Date)
    {
        //Period of 1000 Years.
        Date.Year += 1000;
        return Date;
    }
    static void PrintIncreaseDateProblems()
    {
        sDate Date1 = ReadFullDate();
        cout << "\nDate After : "<< Date1.Day << " / " << Date1.Month << " / " << Date1.Year<<endl;
        cout << "---------------------------------------------------";
        Date1 = IncreaseDateByOneDay(Date1);
        cout << "\n01-Adding One day is             : "
             << Date1.Day << " / " << Date1.Month << " / " << Date1.Year ;
        Date1 = IncreaseDateByXDays(10,Date1);
        cout << "\n02-Adding 10 day is              : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneWeek(Date1);
        cout << "\n03-Adding One week is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXWeeks(10,Date1);
        cout << "\n04-Adding 10 week is             : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneMonth(Date1);
        cout << "\n05-Adding One Month is           : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXMonths(5,Date1);
        cout << "\n06-Adding 5 Month is             : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneYear(Date1);
        cout << "\n07-Adding One Year is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXYears(10,Date1);
        cout << "\n08-Adding 10 Years is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXYearsFaster(10, Date1);
        cout << "\n09-Adding 10 Years (faster) is   : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneDecade(Date1);
        cout << "\n10-Adding One Decade is          : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXDecades(10,Date1);
        cout << "\n11-Adding 10 Decades is          : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByXDecadesFaster(10, Date1);
        cout << "\n12-Adding 10 Decades (faster) is : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneCentury(Date1);
        cout << "\n13-Adding One Century is         : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = IncreaseDateByOneMillennium(Date1);
        cout << "\n14-Adding One Millennium is      : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        cout << "\n---------------------------------------------------\n";

        cout << "\n\n";

    }
    //-------------------------------------------------------------------------

    //[33 To 46]_Decrease Date Problems
    static sDate DecreaseDateByOneDay(sDate Date)
    {
        if (Date.Day == 1)
        {
            if (Date.Month == 1)
            {
                Date.Month = 12;
                Date.Day = 13;
                Date.Year--;
            }
            else
            {
                Date.Month--;
                Date.Day = NumberOfDaysInAMonth(Date.Month,Date.Year);
            }
        }
        else
        {
            Date.Day--;
        }
        return Date;
    }
    static sDate DecreaseDateByXDays(short Days, sDate Date)
    {
        for (short i = 1;i <= Days;i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByOneWeek(sDate Date)
    {
        for (short i = 1;i <= 7;i++)
        {
            Date = DecreaseDateByOneDay(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByXWeeks(short Weeks, sDate Date)
    {
        for (short i = 1;i <= Weeks;i++)
        {
            Date = DecreaseDateByOneWeek(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByOneMonth(sDate Date)
    {
        if (Date.Month == 1)
        {
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
        }
        //last check day in date should not exceed max days in the current month.
        //example if date is 31/3/2022 Decrease one month should not be 31/2/2022,it should be 28/2/2022.
        short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth)
        {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }
    static sDate DecreaseDateByXMonths(short Months, sDate Date)
    {
        for (short i = 1;i <= Months;i++)
        {
            Date = DecreaseDateByOneMonth(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByOneYear(sDate Date)
    {
        Date.Year--;
        return Date;
    }
    static sDate DecreaseDateByXYears(short Years, sDate Date)
    {
        for (short i = 1;i <= Years;i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByXYearsFaster(short Years, sDate Date)
    {
        Date.Year -= Years;
        return Date;
    }
    static sDate DecreaseDateByOneDecade(sDate Date)
    {
        //Period of 10 Years.
        Date.Year -= 10;
        return Date;
    }
    static sDate DecreaseDateByXDecades(short Decades, sDate Date)
    {
        for (short i = 1;i <= Decades * 10;i++)
        {
            Date = DecreaseDateByOneYear(Date);
        }
        return Date;
    }
    static sDate DecreaseDateByXDecadesFaster(short Decades, sDate Date)
    {
        Date.Year -= Decades * 10;
        return Date;
    }
    static sDate DecreaseDateByOneCentury(sDate Date)
    {
        //Period of 100 Years.
        Date.Year -= 100;
        return Date;
    }
    static sDate DecreaseDateByOneMillennium(sDate Date)
    {
        //Period of 1000 Years.
        Date.Year -= 1000;
        return Date;
    }
    static void PrintDecreaseDateProblems()
    {
        sDate Date1 = ReadFullDate();
        cout << "\nDate After : " << Date1.Day << " / " << Date1.Month << " / " << Date1.Year << endl;
        cout << "---------------------------------------------------";
        Date1 = DecreaseDateByOneDay(Date1);
        cout << "\n01-Subtracting One day is             : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXDays(10, Date1);
        cout << "\n02-Subtracting 10 day is              : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneWeek(Date1);
        cout << "\n03-Subtracting One week is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXWeeks(10, Date1);
        cout << "\n04-Subtracting 10 week is             : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneMonth(Date1);
        cout << "\n05-Subtracting One Month is           : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXMonths(5, Date1);
        cout << "\n06-Subtracting 5 Month is             : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneYear(Date1);
        cout << "\n07-Subtracting One Year is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXYears(10, Date1);
        cout << "\n08-Subtracting 10 Years is            : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXYearsFaster(10, Date1);
        cout << "\n09-Subtracting 10 Years (faster) is   : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneDecade(Date1);
        cout << "\n10-Subtracting One Decade is          : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXDecades(10, Date1);
        cout << "\n11-Subtracting 10 Decades is          : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByXDecadesFaster(10, Date1);
        cout << "\n12-Subtracting 10 Decades (faster) is : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneCentury(Date1);
        cout << "\n13-Subtracting One Century is         : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        Date1 = DecreaseDateByOneMillennium(Date1);
        cout << "\n14-Subtracting One Millennium is      : "
            << Date1.Day << " / " << Date1.Month << " / " << Date1.Year;
        cout << "\n---------------------------------------------------\n";
        cout << "\n\n";

    }
    //-------------------------------------------------------------------------

    //[47 To 53]_More Date Problems
    static short DayOfWeekOrder(sDate Date)
    {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }
    static bool IsEndOfWeek(sDate Date)
    {
        return (DayOfWeekOrder(Date) == 6);
    }
    static bool IsWeekEnd(sDate Date)
    {
        //Weekends are Fri and Sat
        short DayIndex = DayOfWeekOrder(Date);
        return (DayIndex == 5 || DayIndex == 6);
    }
    static bool IsBusinessDay(sDate Date)
    {
        //Weekends are Sun,Mon,Tue,Wed,and Thur
        //short DayIndex = DayOfWeekOrder(Date);
        //return (DayIndex >= 5 && DayIndex <= 4);
        
        //shorter Method is to invert the IsWeekEnd: This will save updating code.
        return (!IsWeekEnd(Date));
    }
    static short DaysUntilTheEndOfWeek(sDate Date)
    {
        return (6 - DayOfWeekOrder(Date));
    }
    static short DaysUntilTheEndOfMonth(sDate Date)
    {
        sDate EndOfMonthDate ;
        EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
        EndOfMonthDate.Month = Date.Month;
        EndOfMonthDate.Year = Date.Year;
        return GetDifferenceInDays(Date, EndOfMonthDate, true);
    }
    static short DaysUntilTheEndOfYear(sDate Date)
    {
        sDate EndOfYearDate;
        EndOfYearDate.Day = 31;
        EndOfYearDate.Month = 12;
        EndOfYearDate.Year = Date.Year;
        return GetDifferenceInDays(Date, EndOfYearDate, true);
    }
    static void PrintMoreDateProblems()
    {
        sDate Date1 = GetSystemDate();
        string Tody = DayShortName(DayOfWeekOrder(Date1));
        cout << "\n\nTody is : "<< Tody
             << " : " <<Date1.Day << " / " << Date1.Month << " / " << Date1.Year << endl;
        cout << "\n\nIs it End of Week?\n";
        if (IsEndOfWeek(Date1))
        {
            cout << "Yes,Tody : [" << Tody << "] it's End of week.";
        }
        else
        {
            cout << "No,Tody : [" << Tody << "] it's Not End of week.";
        }
        cout << "\n\nIs it WeekEnd?\n";
        if (IsWeekEnd(Date1))
        {
            cout << "Yes,Tody : [" << Tody << "] it's  a week End.";
        }
        else
        {
            cout << "No,Tody : ["<< Tody <<"] it's Not a week End.";
        }
        cout << "\n\nIs it Business Day?\n";
        if (IsBusinessDay(Date1))
        {
            cout << "Yes,Tody : [" << Tody << "] it's  a Business Day.";
        }
        else
        {
            cout << "No,Tody : [" << Tody << "] it's Not a Business Day.";
        }
        cout << "\n\nDays Until end of Week  : ["<<DaysUntilTheEndOfWeek(Date1)<<"] Day(s).";
        cout << "\nDays Until end of Month : [" << DaysUntilTheEndOfMonth(Date1) << "] Day(s).";
        cout << "\nDays Until end of Year  : [" << DaysUntilTheEndOfYear(Date1) << "] Day(s).\n\n";
    }
    //-------------------------------------------------------------------------

    //[54]_Calculate Vacation Days
    static short CalculateVacationDays(sDate DateFrom, sDate DateTo)
    {
        short DaysCount = 0;
        while(IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
            {
                DaysCount++;
            }
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DaysCount;
    }
    static void PrintCalculateVacationDays()
    {
        cout << "\nVacation Starts : ";
        sDate DateFrom = ReadFullDate();
        cout << "\nVacation Ends : ";
        sDate DateTo = ReadFullDate();
        cout << "\nVacation From : " << DayShortName(DayOfWeekOrder(DateFrom)) << ", "
             << DateFrom.Day << " / " << DateFrom.Month << " / " << DateFrom.Year << endl;
        cout << "\nVacation To : "<< DayShortName(DayOfWeekOrder(DateTo)) << ", "
            << DateTo.Day << " / " << DateTo.Month << " / " << DateTo.Year << endl;
        cout << "\nThe Number of Days is : [" << GetDifferenceInDays(DateFrom, DateTo) << "] Days.\n";
        cout << "\n\nActucal Vacation Days is : " << CalculateVacationDays(DateFrom, DateTo)<<endl;
    }
    //-------------------------------------------------------------------------

    //[55]_Calculate Vacation Return Date
    static short ReadVacationDays()
    {
        short Days = 0;
        cout << "\nPlease enter Vacation Days ?   => ";
        cin >> Days;
        return Days;

    }
    static sDate CalculateVacationReturnDate(sDate DateFrom,short VacationDays)
    {
        short WeekEndCounter = 0;
        //in case the date is weekend keep adding one day until you reach business day.
        //we get rid of all weekends before the first business day.
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        //her we increase the vacation dates to add all weekends to it.
        for (short i = 1;i <= VacationDays + WeekEndCounter;i++)
        {
            if (IsWeekEnd(DateFrom))
            {
                WeekEndCounter++;
            }
            DateFrom = IncreaseDateByOneDay(DateFrom); 
        }
        //in case the return date is week end keep adding on day until you reach business day
        while (IsWeekEnd(DateFrom))
        {
            DateFrom = IncreaseDateByOneDay(DateFrom);
        }
        return DateFrom;
    }
    static void PrintCalculateVacationReturnDate()
    {
        cout << "\nVacation Starts : ";
        sDate DateFrom = ReadFullDate();
        short VacationDays = ReadVacationDays(); 

        cout << "\nVacation From : " << DayShortName(DayOfWeekOrder(DateFrom)) << ", "
            << DateFrom.Day << " / " << DateFrom.Month << " / " << DateFrom.Year << endl;
        DateFrom = CalculateVacationReturnDate(DateFrom, VacationDays);
        cout << "\nReturn Date : " << DayShortName(DayOfWeekOrder(DateFrom)) << ", "
            << DateFrom.Day << " / " << DateFrom.Month << " / " << DateFrom.Year << endl;
    }
    //-------------------------------------------------------------------------

    //[56]_Is Date1 After Date2
    static bool IsDate1AfterDate2(sDate Date1, sDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
    }
    static void PrintIsDate1AfterDate2()
    {
        cout << "\nEnter Date1 : ";
        sDate Date1 = ReadFullDate();
        cout << "\n\nEnter Date2 : ";
        sDate Date2 = ReadFullDate();
        if (IsDate1AfterDate2(Date1,Date2))
        {
            cout << "\n\nYes,Date1 is after Date2.\n\n";
        }
        else
        {
            cout << "\n\nNo,Date1 is Not after Date2.\n\n";
        }
    }
    //-------------------------------------------------------------------------

    //[57]_Compare Date Function
    enum enDateCompare{Before =-1,Equal=0,After =1};
    static enDateCompare CompareDates(sDate Date1, sDate Date2)
    {
        if (IsDate1BeforeDate2(Date1, Date2))
            return enDateCompare::Before;
        if (IsDate1EqualDate2(Date1, Date2))
            return enDateCompare::Equal;
        //if(IsDate1AfterDate2(Date1, Date2))
        //    return enDateCompare::After;
        return enDateCompare::After;
    }
    static string ReturnSortOfCompare(enDateCompare Compare)
    {
        switch (Compare)
        {
        case enDateCompare::Before :
                return " Before";
        case enDateCompare::Equal:
            return " Equal";
        case enDateCompare::After:
            return " After";
        }
    }
    static void PrintCompareDateFunction()
    {
        cout << "\nEnter Date1 : ";
        sDate Date1 = ReadFullDate();
        cout << "\n\nEnter Date2 : ";
        sDate Date2 = ReadFullDate();
        enDateCompare Compare = CompareDates(Date1, Date2);
        cout << "\n\nCompare Result = " << Compare << ReturnSortOfCompare(Compare) << endl;
    }
    //-------------------------------------------------------------------------

    //[58]_Is Overlap Periods
    struct stPeriod
    {
        sDate StartDate;
        sDate EndDate;
    };
    static stPeriod ReadPeriod()
    {
        stPeriod Period;
        cout << "\nEnter Start Date :\n";
        Period.StartDate = ReadFullDate();
        cout << "\nEnter End Date :\n";
        Period.EndDate = ReadFullDate();
        return Period;
    }
    static bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
    {
        if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
            ||
            CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
            )
            return false;
        else
            return true;

    }
    static void PrintIsOverlapPeriods()
    {
        cout << "\nEnter Period1 : \n";
        stPeriod Period1 = ReadPeriod();
        cout << "\nEnter Period2 : \n";
        stPeriod Period2 = ReadPeriod();
        if (IsOverlapPeriods(Period1, Period2))
        {
            cout << "\nYes,Periods Overlap\n";
        }
        else
        {
            cout << "\nNo,Periods do not Overlap\n";

        }
    }
    //-------------------------------------------------------------------------

    //[59]_Period Length In Days
    static int PeriodLengthInDays(stPeriod Period1, bool IncludeEndDay = false)
    {
        return GetDifferenceInDays(Period1.StartDate, Period1.EndDate, IncludeEndDay);
    }
    static void PrintPeriodLengthInDays()
    {
        cout << "\nEnter Period1 : \n";
        stPeriod Period1 = ReadPeriod();
        cout << "\nPeriods Length is : ["<<PeriodLengthInDays(Period1)<<"].";
        cout << "\nPeriods Length  (Including End Date) is : [" << PeriodLengthInDays(Period1,true) << "].\n\n";
    }
    //-------------------------------------------------------------------------
    
    //[60]_Is Date Within Period
    static bool IsDateInPeriod(sDate Date,stPeriod Period1)
    {
        return !(CompareDates(Date, Period1.StartDate) == enDateCompare::Before
               ||
               CompareDates(Date, Period1.EndDate) == enDateCompare::After);         
    }
    static void PrintIsDateWithinPeriod()
    {
        cout << "\nEnter Period : \n";
        stPeriod Period1 = ReadPeriod();
        cout << "\nEnter Date to Check : \n";
        sDate Date = ReadFullDate();
        if (IsDateInPeriod(Date, Period1))
        {
            cout << "\nYes,Date is within period\n";
        }
        else
        {
            cout << "\nNo,Date is Not within period\n";
        }
    }
    //-------------------------------------------------------------------------

    //[61]_Coutn Overlap Days
    static int CoutnOverlapDays(stPeriod Period1, stPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        if (Period1Length < Period2Length)
        {
            while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateInPeriod(Period1.StartDate, Period2))
                    OverlapDays++;
                Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
            }
        }
        else
        {
            while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (IsDateInPeriod(Period2.StartDate, Period1))
                    OverlapDays++;
                Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
            }
        }
        return OverlapDays;
    }
    static void PrintCoutnOverlapDays()
    {
        cout << "\nEnter Period1 : \n";
        stPeriod Period1 = ReadPeriod();
        cout << "\nEnter Period2 : \n";
        stPeriod Period2 = ReadPeriod();
        cout << "\n\nOverlap Days Count Is : [" << CoutnOverlapDays(Period1, Period2) << "].\n\n";
    }
    //-------------------------------------------------------------------------

    //[62]_Validate Date 
    static bool IsValidDate(sDate Date)
    {
        if (Date.Day < 1 || Date.Day > 31)
        {
            return false;
        }
        if (Date.Month < 1 || Date.Month > 12)
        {
            return false;
        }
        if (Date.Year <= 0)
        {
            return false;
        }
        if (Date.Month == 2)
        {
            if (IsLeapYear(Date.Year))
            {
                if(Date.Day > 29)
                    return false;
            }
            else
            {
                if (Date.Day > 28)
                    return false;
            }
        }
        short DaysInMonth = NumberOfDaysInAMonth(Date.Month,Date.Year);
        if (Date.Day > DaysInMonth)
        {
            return false;
        }
        return true;
    }
    static void PrintValidateDate()
    {
        sDate Date1 = ReadFullDate();
        if (IsValidDate(Date1))
        {
            cout << "\nYes,Date is Valid Date\n";
        }
        else
        {
            cout << "\nNo,Date is Not Valid Date\n";
        }
    }
    //-------------------------------------------------------------------------

    //[63 To 64]_Read and Print Date String
    static string ReadStringDate(string Message)
    {
        string DateStrin;
        cout << Message << " => ";
        getline(cin>>ws , DateStrin);
        return DateStrin;
    }
    static sDate StringToDate(string DateStrin)
    {
        sDate Date;
        vector<string>vDate;
        vDate = ClsUtil3::SplitString(DateStrin, "/");
        Date.Day = stoi(vDate[0]);
        Date.Month = stoi(vDate[1]);
        Date.Year = stoi(vDate[2]);
        return Date;
    }
    static string DateToString(sDate Date)
    {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }
    static void PrintReadandPrintDateString()
    {
        string DateString = ReadStringDate("\nPlease enter date dd/mm/yyyy?");
        sDate Date = StringToDate(DateString);

        cout << "\nDate : " << Date.Day << endl;
        cout << "Month: " << Date.Month << endl;
        cout << "Year : " << Date.Year << endl;
        cout << "\n\nYou Entered :  " << DateToString(Date) << endl;
    }
    //-------------------------------------------------------------------------
    
    //[65]_Format Date
    static string FormatDate(sDate Date,string DateFormat = "dd/mm/yyyy")
    {
        string FormatToDateString = "";
        FormatToDateString = ClsUtil3::ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
        FormatToDateString = ClsUtil3::ReplaceWordInString(FormatToDateString, "mm", to_string(Date.Month));
        FormatToDateString = ClsUtil3::ReplaceWordInString(FormatToDateString, "yyyy", to_string(Date.Year));
        return FormatToDateString;
    }
    static void PrintFormatDate()
    {
        string DateString = ReadStringDate("\nPlease enter date dd/mm/yyyy?");
        sDate Date = StringToDate(DateString);
        cout << "\n" << FormatDate(Date) << endl;
        cout << "\n" << FormatDate(Date,"yyyy/dd/mm") << endl;
        cout << "\n" << FormatDate(Date,"mm/dd/yyyy") << endl;
        cout << "\n" << FormatDate(Date,"mm-dd-yyyy") << endl;
        cout << "\n" << FormatDate(Date,"dd-mm-yyyy") << endl;
        cout << "\n" << FormatDate(Date, "Day:dd,Month:mm,Year:yyyy") << endl;   
    }
    //-------------------------------------------------------------------------

};

