#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int printWelcomeMessage(); // Print the welcome message and obtain starting temperature from user.
int calculateResultTempScale(); // Obtain the resulting temperature scale from user.
float calculateResultTemp(int startingTempScale); // Wrapper function for generating the result temp, uses generateTemp().
float generateTemp(int startingTempScale, int endingTempScale, double startingTemp); // Generates the final resulting temperature.
void printResultTemp(int startingTempScale, int endingTempScale, int startingTemp, float resultTemp); // Print the starting and resulting temperature.

string temperature_scales[3] = {"Fahrenheit", "Celcius", "Kelvin"}; // Array of different temperature scales.

int main() {
    bool repeat = true; // Boolean flag used to escape repeat loop.     True - Repeat / False - Terminate
    char userRepeatSelection; // Character to hold user-input.

    while(1) { // Allow the user to convert multiple temperatures until they are done.
        if(repeat) {
            int startingTempScale;  // Hold the placeholder value for starting temperature scale.
                                    // 0 - Fahrenheit
                                    // 1 - Celcius
                                    // 2 - Kelvin
            startingTempScale = printWelcomeMessage(); // Obtain the users starting temperature scale.

            calculateResultTemp(startingTempScale);
        }
        cout << "\n\nWould you like to convert another temperature?\n";
        cout << "[y/n]: ";

        cin >> userRepeatSelection; // User-input for repeating or terminating.

        while(userRepeatSelection != 'y' && userRepeatSelection != 'n') { // User-input validation.
            cout << "Invalid input. Enter 'y' or 'n' here: ";

            cin >> userRepeatSelection; // Allow user to input correct value.
        }

        if(userRepeatSelection == 'n') { // If the user choses no, terminate.
            break;
        }
    }

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

int calculateResultTempScale() {
    int resultTempScale;

    cout << "1.) Fahrenheit\n2.) Celcius\n3.) Kelvin\n";
    cout << "Enter the resulting temperature scale here: ";

    while(1) { // User-input verification.
        cin >> resultTempScale; // User-input for temperature scale selection.

        if(resultTempScale < 1 || resultTempScale > 3) { // Check the user input is OK. (Between 1 - 3).
            cout << "Error! Enter a number 1-3.\n\n";
            cout << "Enter the starting temperature scale here: ";
        }
        else
            break; // If the user-input is OK.
    }

    return resultTempScale;
}

float calculateResultTemp(int startingTempScale) {
    double inputTemp; // Holds in user-inputted starting temperature.
    float resultTemp; // Floating point value to hold the final resulting temperature after conversion.

    int resultTempScale = calculateResultTempScale(); // Obtain the desired result temperature scale from the user.

    resultTempScale--; // Decrement the result temperature scale to  align with temperature scale array.

    cout << "\n\nEnter your starting temperature in " << temperature_scales[startingTempScale] << " here: "; // User prompt to enter temperature.

    while(1) { // User-input verification.
        cin >> inputTemp; // User-input for temperature.

        if(inputTemp < -10000 || inputTemp > 10000) { // Check the user input is OK. ( +/- 10000).
            cout << "Error! Enter a temperature +/- 10,000 degrees.\n\n";
            cout << "Enter the starting temperature here: ";
        }
        else
            break; // If the user-input is OK.
    }

    resultTemp = generateTemp(startingTempScale, resultTempScale, inputTemp); // Generate the resulting temperature after conversion.

    printResultTemp(startingTempScale, resultTempScale, inputTemp, resultTemp); // Print the resulting temperature after conversion to the user.

    return resultTemp; // Return the resulting temperature after conversion.
}

float generateTemp(int startingTempScale, int endingTempScale, double startingTemp) {
    float resultTemp;
    const float cTofMult = 1.80, // Multiplier used when converting between celcius and fahrenheit.
                fTocMult = 0.5555556, // Multiplier used when converting between fahrenheit to celcius.
                kelvinOffset = 273.15, // Offset used in conversion to and from kelvin.
                tempOffset = 32; // General temperature offset used in conversion between temperature scales.

    switch (startingTempScale) // Switch between the starting temperature scale chosen by the user.
    {
    case 0: // Starting with fahrenheit.
        if(endingTempScale == 1) {
            resultTemp = (startingTemp - tempOffset) * fTocMult; // Convert fahrenheit to celcius.
        }
        if(endingTempScale == 2) {
            resultTemp = (startingTemp - tempOffset) * fTocMult + kelvinOffset; // Convert fahrenheit to kelvin.
        }
        break;
    case 1: // Starting with celcius.
        if(endingTempScale == 0) {
            resultTemp = (startingTemp * cTofMult) + tempOffset; // Convert celcius to fahrenheit.
        }
        if(endingTempScale == 2) {
            resultTemp = startingTemp + kelvinOffset; // Convert celcius to kelvin.
        }
        break;
    case 2: // Starting with kelvin.
        if(endingTempScale == 0) {
            resultTemp = (startingTemp - kelvinOffset) * cTofMult + tempOffset; // Convert fahrenheit to kelvin.
        }
        if(endingTempScale == 1) {
            resultTemp = startingTemp + kelvinOffset; // Convert celcius to kelvin.
        }
        break;
    default:
        resultTemp = startingTemp; // User has chosen not to convert the starting temperature scale to another.
        break;
    }

    return resultTemp; // Return the floating point value of the resulting temperature after conversion.
}

void printResultTemp(int startingTempScale, int endingTempScale, int startingTemp, float resultTemp) {
    cout << "\n\n" << startingTemp << " degrees " << temperature_scales[startingTempScale]
    << " = " << setprecision (3) << fixed << resultTemp
    << " degrees " << temperature_scales[endingTempScale] << ".\n\n"; // Display starting temperature and resulting temperature after conversion.
}