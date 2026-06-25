#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string favoriteBrand;
    string favoriteBadge;
    int badgesRestored;
    int hoursPerWeek;

    // Ask user questions
    //i think it finally works
    cout << "What is your favorite automotive brand? ";
    cin >> favoriteBrand;

    cout << "What is your favorite badge or emblem to restore? ";
    cin >> favoriteBadge;

    cout << "How many badges have you restored? ";
    cin >> badgesRestored;

    cout << "How many hours per week do you spend customizing? ";
    cin >> hoursPerWeek;

    // Simple calculation
    int totalHours = badgesRestored * hoursPerWeek;

    // Display results
    cout << endl;
    cout << "You enjoy restoring " << favoriteBadge
         << " emblems from " << favoriteBrand << "." << endl;

    cout << "You have restored "
         << badgesRestored
         << " badges and spend "
         << hoursPerWeek
         << " hours per week customizing vehicles." << endl;

    cout << "Estimated total hobby hours: "
         << totalHours << endl;

    return 0;
}