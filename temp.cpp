#include <iostream>
#include <string>

using namespace std;

int printWelcomeMessage(); // Print the welcome message and obtain starting temperature from user.

int main() {
    int startingTempScale, endingTempScale;

    printWelcomeMessage();


    return 0;
}

int printWelcomeMessage() {
    int tempChoice = 0; // If tempChoice = 0, user input error has ocurred.

    cout << "1.) Fahrenheit\n2.) Celcius\n3.) Kelvin\n\n";
    cout << "Enter the starting temperture scale here: ";

    while(1) { // User-input verification.
        cin >> tempChoice; // User-input for temperature scale selection.

        if(tempChoice < 1 || tempChoice > 3) { // Check the user input is OK. (Between 1 - 3).
            cout << "Error! Enter a number 1-3.\n\n";
            cout << "Enter the starting temperature scale here: ";
        }
        else
            break; // If the user-input is OK.
    }
   
    return tempChoice; // Return the int value of the user inputted temperature scale.
}