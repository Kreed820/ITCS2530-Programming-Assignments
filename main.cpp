#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void changeColor()
{
    system("color 0A");
}

void displayBanner()
{
    cout << "==========================================" << endl;
    cout << "   Welcome to the Emblem Restoration App" << endl;
    cout << "==========================================" << endl;
}

int getMenuChoice()
{
    int choice;

    cout << endl;
    cout << "Menu Options:" << endl;
    cout << "1. Add Restoration Session" << endl;
    cout << "2. View Weekly Report" << endl;
    cout << "3. Recommend Restoration Level" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Enter 1, 2, 3, or 4: ";
        cin >> choice;
    }

    return choice;
}

int getPositiveInt(string prompt)
{
    int number;

    cout << prompt;
    cin >> number;

    while (cin.fail() || number < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive whole number: ";
        cin >> number;
    }

    return number;
}

//Slightly alternate function of getPositiveInt, this one is used to make a limit on
//how many weeks you can review!
int getPositiveIntAlt(string prompt)
{
    int number;

    cout << prompt;
    cin >> number;

    //Added the "10 or less" condition
    while (cin.fail() || number < 0 || number > 10)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive whole number that is 10 or less: ";
        cin >> number;
    }

    return number;
}

double getPositiveDouble(string prompt)
{
    double number;

    cout << prompt;
    cin >> number;

    while (cin.fail() || number < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
        cin >> number;
    }

    return number;
}

//Slightly alternate function of getPositiveDouble, but now with an extra paramter, which is
//used to display which week it is!
double getPositiveDoubleAlt(string prompt, double weekNum)
{
    double number;

    cout << prompt;
    if (weekNum == 1)
    {
        cout << "One";
    }
    if (weekNum == 2)
    {
        cout << "Two";
    }
    if (weekNum == 3)
    {
        cout << "Three";
    }
    if (weekNum == 4)
    {
        cout << "Four";
    }
    if (weekNum == 5)
    {
        cout << "Five";
    }
    if (weekNum == 6)
    {
        cout << "Six";
    }
    if (weekNum == 7)
    {
        cout << "Seven";
    }
    if (weekNum == 8)
    {
        cout << "Eight";
    }
    if (weekNum == 9)
    {
        cout << "Nine";
    }
    if (weekNum == 10)
    {
        cout << "Ten";
    }

    //To retain the end of the original prompt
    cout << ": $";
    cin >> number;

    while (cin.fail() || number < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number: ";
        cin >> number;
    }

    return number;
}

double calculateTotal(double amount, double price)
{
    return amount * price;
}

double calculateTotalCost(double week[], int weekCount)
{
    double totalCost = 0;

    for (int i = 0; i < weekCount; i++)
    {
        totalCost += week[i];
    }

    return totalCost;
}

void saveReport(string name, string brand, string tool, int emblems, double hours, double cost, double totalHours, double totalCost)
{
    ofstream reportFile;
    reportFile.open("report.txt");

    if (reportFile.is_open())
    {
        reportFile << fixed << setprecision(2);
        reportFile << "===== Restoration Summary Report =====" << endl;
        reportFile << left << setw(25) << "Item" << right << setw(15) << "Value" << endl;
        reportFile << "----------------------------------------" << endl;
        reportFile << left << setw(25) << "Name" << right << setw(15) << name << endl;
        reportFile << left << setw(25) << "Brand" << right << setw(15) << brand << endl;
        reportFile << left << setw(25) << "Tool" << right << setw(15) << tool << endl;
        reportFile << left << setw(25) << "Emblems Restored" << right << setw(15) << emblems << endl;
        reportFile << left << setw(25) << "Hours Per Emblem" << right << setw(15) << hours << endl;
        reportFile << left << setw(25) << "Cost Per Emblem" << right << setw(14) << "$" << cost << endl;
        reportFile << left << setw(25) << "Total Hours" << right << setw(15) << totalHours << endl;
        reportFile << left << setw(25) << "Total Cost" << right << setw(14) << "$" << totalCost << endl;
        reportFile.close();

        cout << endl << "Report saved to report.txt" << endl;
    }
    else
    {
        cout << "Unable to open report.txt." << endl;
    }
}

void displayTable(string name, string brand, string tool, int emblems, double hours, double cost, double totalHours, double totalCost)
{
    cout << fixed << setprecision(2);
    cout << endl;
    cout << left << setw(25) << "Item" << right << setw(15) << "Value" << endl;
    cout << "----------------------------------------" << endl;
    cout << left << setw(25) << "Name" << right << setw(15) << name << endl;
    cout << left << setw(25) << "Brand" << right << setw(15) << brand << endl;
    cout << left << setw(25) << "Tool" << right << setw(15) << tool << endl;
    cout << left << setw(25) << "Emblems Restored" << right << setw(15) << emblems << endl;
    cout << left << setw(25) << "Total Hours" << right << setw(15) << totalHours << endl;
    cout << left << setw(25) << "Total Cost" << right << setw(14) << "$" << totalCost << endl;
}

void summaryReport(double week[], int weekCount, double totalCost, double averageCost)
{
    cout << fixed << setprecision(2);
    cout << endl;
    cout << left << setw(25) << "Week" << right << setw(15) << "Cost" << endl;
    cout << "----------------------------------------" << endl;
    switch (weekCount)
    {
    case 1:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        break;
    case 2:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        break;
    case 3:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        break;
    case 4:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        break;
    case 5:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        break;
    case 6:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        cout << left << setw(25) << "Six" << right << setw(15) << week[5] << endl;
        break;
    case 7:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        cout << left << setw(25) << "Six" << right << setw(15) << week[5] << endl;
        cout << left << setw(25) << "Seven" << right << setw(15) << week[6] << endl;
        break;
    case 8:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        cout << left << setw(25) << "Six" << right << setw(15) << week[5] << endl;
        cout << left << setw(25) << "Seven" << right << setw(15) << week[6] << endl;
        cout << left << setw(25) << "Eight" << right << setw(15) << week[7] << endl;
        break;
    case 9:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        cout << left << setw(25) << "Six" << right << setw(15) << week[5] << endl;
        cout << left << setw(25) << "Seven" << right << setw(15) << week[6] << endl;
        cout << left << setw(25) << "Eight" << right << setw(15) << week[7] << endl;
        cout << left << setw(25) << "Nine" << right << setw(15) << week[8] << endl;
        break;
    case 10:
        cout << left << setw(25) << "One" << right << setw(15) << week[0] << endl;
        cout << left << setw(25) << "Two" << right << setw(15) << week[1] << endl;
        cout << left << setw(25) << "Three" << right << setw(15) << week[2] << endl;
        cout << left << setw(25) << "Four" << right << setw(15) << week[3] << endl;
        cout << left << setw(25) << "Five" << right << setw(15) << week[4] << endl;
        cout << left << setw(25) << "Six" << right << setw(15) << week[5] << endl;
        cout << left << setw(25) << "Seven" << right << setw(15) << week[6] << endl;
        cout << left << setw(25) << "Eight" << right << setw(15) << week[7] << endl;
        cout << left << setw(25) << "Nine" << right << setw(15) << week[8] << endl;
        cout << left << setw(25) << "Ten" << right << setw(15) << week[9] << endl;
        break;
    default:
        break;
    }
}

int main()
{
    string userName;
    string favoriteBrand;
    string favoriteTool;
    int menuChoice;
    int emblemsRestored = 0;
    int weekCount = 1;
    double hoursPerEmblem = 0;
    double costPerEmblem = 0;
    double totalHours = 0;
    double totalCost = 0;
    double averageCost = 0;
    char repeatChoice;
    //New enum used for option 3
    enum restorationLevel {SIMPLE, INTERMEDIATE, COMPLEX};
    restorationLevel currentLevel;

    //New array
    double week[10];
    week[0] = 0;

    changeColor();
    displayBanner();

    cout << "Enter your name: ";
    getline(cin, userName);

    do
    {
        menuChoice = getMenuChoice();
        cin.ignore(1000, '\n');

        switch (menuChoice)
        {
        case 1:
            cout << endl;
            cout << "Enter your favorite car brand to restore: ";
            getline(cin, favoriteBrand);

            cout << "Enter your favorite restoration tool: ";
            getline(cin, favoriteTool);

            emblemsRestored = getPositiveInt("How many emblems did you restore? ");
            hoursPerEmblem = getPositiveDouble("How many hours does each emblem usually take? ");
            costPerEmblem = getPositiveDouble("How much does each emblem cost to restore? ");

            totalHours = calculateTotal(emblemsRestored, hoursPerEmblem);
            totalCost = calculateTotal(emblemsRestored, costPerEmblem);

            displayTable(userName, favoriteBrand, favoriteTool, emblemsRestored, hoursPerEmblem, costPerEmblem, totalHours, totalCost);
            saveReport(userName, favoriteBrand, favoriteTool, emblemsRestored, hoursPerEmblem, costPerEmblem, totalHours, totalCost);
            break;

        case 2:
            //Telling the user that there is a limit on how many weeks they can review

            //Also calling an alternate version of getPositiveInt which has a limit on the 
            //number you enter
            weekCount = getPositiveIntAlt("How many weeks do you want to review? (No more than 10 allowed)\n");
            totalCost = 0;

            for (int i = 0; i <= weekCount - 1; i++)
            {
                //The "i + 1" is very important here, indexes start with 0, so if I displayed
                //just week "i", it would always be one week behind

                //Also, calling alternate version of original getPositiveDouble to help display
                //the accurate week
                week[i] = getPositiveDoubleAlt("Enter restoration cost for Week ", i + 1);
                costPerEmblem = week[i];
            }
            totalCost = calculateTotalCost(week, weekCount);
            averageCost = totalCost / weekCount;


            summaryReport(week, weekCount, totalCost, averageCost);
            cout << fixed << setprecision(2);
            cout << "\nTotal weekly restoration cost: $" << totalCost << endl;
            cout << "Average cost per week: $" << averageCost << endl;
            break;

        case 3:
            emblemsRestored = getPositiveInt("How many emblems did you restore this week? ");
            totalHours = getPositiveDouble("How many total hours did you work this week? ");

            if (emblemsRestored >= 5 && totalHours >= 10)
            {
                currentLevel = COMPLEX;
            }
            else if (emblemsRestored >= 2 && totalHours >= 4)
            {
                currentLevel = INTERMEDIATE;
            }
            else
            {
                currentLevel = SIMPLE;
            }
            switch (currentLevel)
            {
            case SIMPLE:
                cout << "Recommendation: Simple restoration level.\n";
                break;
            case INTERMEDIATE:
                cout << "Recommendation: Intermediate restoration level.\n";
                break;
            case COMPLEX:
                cout << "Recommendation: Complex restoration level.\n";
                break;
            }

            if (totalHours >= 5 && emblemsRestored >= 1)
            {
                cout << "You had a productive restoration week." << endl;
            }
            else
            {
                cout << "Try setting aside more time for your next project." << endl;
            }
            break;

        case 4:
            cout << "Thank you for using the Emblem Restoration App!" << endl;
            break;
        }

        if (menuChoice != 4)
        {
            cout << endl;
            cout << "Would you like to return to the menu? Y/N: ";
            cin >> repeatChoice;
        }
        else
        {
            repeatChoice = 'N';
        }

    } while (repeatChoice == 'Y' || repeatChoice == 'y');

    cout << endl;
    cout << "Program ended. Goodbye!" << endl;

    return 0;
}
