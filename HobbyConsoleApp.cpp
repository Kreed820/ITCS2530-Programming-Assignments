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

double calculateTotal(double amount, double price)
{
    return amount * price;
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

int main()
{
    string userName;
    string favoriteBrand;
    string favoriteTool;
    int menuChoice;
    int emblemsRestored = 0;
    int weekCount;
    double hoursPerEmblem = 0;
    double costPerEmblem = 0;
    double totalHours = 0;
    double totalCost = 0;
    double averageCost = 0;
    char repeatChoice;

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
            weekCount = getPositiveInt("How many weeks do you want to review? ");
            totalCost = 0;

            for (int week = 1; week <= weekCount; week++)
            {
                costPerEmblem = getPositiveDouble("Enter restoration cost for this week: $");
                totalCost = totalCost + costPerEmblem;
            }

            averageCost = totalCost / weekCount;

            cout << fixed << setprecision(2);
            cout << "Total weekly restoration cost: $" << totalCost << endl;
            cout << "Average cost per week: $" << averageCost << endl;
            break;

        case 3:
            emblemsRestored = getPositiveInt("How many emblems did you restore this week? ");
            totalHours = getPositiveDouble("How many total hours did you work this week? ");

            if (emblemsRestored >= 5 && totalHours >= 10)
            {
                cout << "Recommendation: Advanced restoration level." << endl;
            }
            else if (emblemsRestored >= 2 && totalHours >= 4)
            {
                cout << "Recommendation: Intermediate restoration level." << endl;
            }
            else
            {
                cout << "Recommendation: Beginner restoration level." << endl;
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