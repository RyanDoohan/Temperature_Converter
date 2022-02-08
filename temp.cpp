#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int printWelcomeMessage(); // Print the welcome message and obtain starting temperature from user.
int calculateResultTempScale(int startingTempScale); // Obtain the resulting temperature scale from user.
int calculateResultTemp(int startingTempScale); // Wrapper function for generating the result temp, uses generateTemp().
float generateTemp(int startingTempScale, int endingTempScale, int startingTemp); // Generates the final resulting temperature.
void printResultTemp(int startingTempScale, int endingTempScale, int startingTemp, double resultTemp);

string temperature_scales[3] = {"Fahrenheit", "Celcius", "Kelvin"};

int main() {
    int startingTempScale, endingTempScale;
    double resultTemp;

    startingTempScale = printWelcomeMessage();

    resultTemp = calculateResultTemp(startingTempScale);


    return 0;
}

int printWelcomeMessage() {
    int tempChoice = 0; // If tempChoice = 0, user input error has ocurred.

    cout << "1.) Fahrenheit\n2.) Celcius\n3.) Kelvin\n";
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

    tempChoice--; // Decrement tempChoice to align with temperature scale array.
   
    return tempChoice; // Return the int value of the user inputted temperature scale.
}

int calculateResultTempScale(int startingTempScale) {
    int resultTempScale;

    cout << "1.) Fahrenheit\n2.) Celcius\n3.) Kelvin\n";
    cout << "Enter the resulting temperature scale here: ";

    cin >> resultTempScale;

    return resultTempScale;
}

int calculateResultTemp(int startingTempScale) {
    int inputTemp;
    double resultTemp;

    int resultTempScale = calculateResultTempScale(startingTempScale);

    resultTempScale--; // Decrement the result temperature scale to  align with temperature scale array.

    cout << "\n\nEnter your starting temperature in " << temperature_scales[startingTempScale] << " here: ";

    while(1) { // User-input verification.
        cin >> inputTemp; // User-input for temperature.

        if(inputTemp < -10000 || inputTemp > 10000) { // Check the user input is OK. ( +/- 10000).
            cout << "Error! Enter a temperature +/- 10,000 degrees.\n\n";
            cout << "Enter the starting temperature here: ";
        }
        else
            break; // If the user-input is OK.
    }

    resultTemp = generateTemp(startingTempScale, resultTempScale, inputTemp);

    printResultTemp(startingTempScale, resultTempScale, inputTemp, resultTemp);
    return resultTemp;
}

float generateTemp(int startingTempScale, int endingTempScale, int startingTemp) {
    float resultTemp, celciusMult = 1.80;

    switch (startingTempScale)
    {
    case 0:
        if(endingTempScale == 1) {
            resultTemp = (startingTemp - 32) * 0.5556;
        }
        if(endingTempScale == 2) {
            resultTemp = (startingTemp + 459.67) * 5/9;
        }
        break;
    case 1:
        if(endingTempScale == 0) {
            resultTemp = startingTemp * celciusMult;
            resultTemp += 32;
        }
    default:
        break;
    }

    return resultTemp;
}

void printResultTemp(int startingTempScale, int endingTempScale, int startingTemp, double resultTemp) {
    cout << "\n\n" << startingTemp << " degrees " << temperature_scales[startingTempScale]
    << " = " << setprecision (2) << fixed << resultTemp
    << " degrees " << temperature_scales[endingTempScale] << ".\n\n";
}