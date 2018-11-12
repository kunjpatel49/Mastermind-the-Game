/*  mastermind.cpp
 
 System: C++ in Xcode
 Author: Kunj Patel
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void loopFunc()
{
    int randNum1 = 0, randNum2 = 0, randNum3 = 0;   // three for storing three different random number;
    int userIn2 = 0, userIn3 = 0;                   // var for user inpits for guessed numbers
    int origRand = 0;                               // this var is to store the rand number generated on every loop and is used to assign it to a different var;
    int counter = 1,counter2 = 1;      // counters for loops for random number and player chnaces;
    int placeMatch1 = 0;                            // var for displayin the in place number;
    int placeMatch2 = 0;                            // var for displaying out of place number;
    int varDigit1= 0, varDigit2 = 0, varDigit3 = 0; // var for storing the broken down number to single digit;

        cout << "Input of 000 displays the hidden digits.  Input of 999 exits the program." << endl;
        cout << "\n\n" << setw(50) << "In place  Out of place" << endl;
        cout << setw(50) << "--------  ------------" << endl;
        //Block for generating three random numbers:
        while (counter <= 3)
        {
            origRand = (rand() % 10);
            if (counter == 1) {
                randNum1 = origRand;
            } else if (counter == 2) {
                randNum2 = origRand;
            } else {
                randNum3 = origRand;
            }
            counter++;
        }//****
        
        // code for comparing the random number with the user's guess:
        while (counter2 <= 10)
        {
            placeMatch1 = 0;
            placeMatch2 = 0;
            cout << counter2 << ". Your guess: " << endl;
            cin >> userIn3;
            varDigit1 = userIn3 / 100;
            varDigit2 = userIn3 / 10 % 10;
            varDigit3 = userIn3 % 10;
            
            // this satement outputs desired sentence and exits the loop if the the input is 999;
            if (varDigit1 == 9 && varDigit2 == 9 && varDigit3 == 9)
            {
                cout << setw(3) << "Exiting loop..." << endl;
                cout << "\n" << setw(3) << "Better luck next time." << endl;
                cout << "\nExiting program..." << endl;
                break;
            }//****
            
            /* This block starting from here to line 133 (marked as '****' at the end),
             Compares each digit with the randnum position and deciding the in place
             and out of place scoring by incrementing and decrementing it acordingly:*/
            if (varDigit1 == randNum1)
            {
                placeMatch1++;
                while (placeMatch2 > 0)
                {
                    placeMatch2--;
                }
            }
            if (varDigit2 == randNum2)
            {
                placeMatch1++;
                while (placeMatch2 > 0)
                {
                    placeMatch2--;
                }
            }
            if (varDigit3 == randNum3)
            {
                placeMatch1++;
                while (placeMatch2 > 0)
                {
                    placeMatch2--;
                }
            }
            
            if (varDigit1 == randNum2 || varDigit1 == randNum3)
            {
                placeMatch2++;
                while (placeMatch1 > 0)
                {
                    placeMatch1--;
                }
            }
            if (varDigit2 == randNum1 || varDigit2 == randNum3)
            {
                placeMatch2++;
                while (placeMatch1 > 0)
                {
                    placeMatch1--;
                }
            }
            
            if (varDigit3 == randNum2 || varDigit3 == randNum1)
            {
                placeMatch2++;
                while (placeMatch1 > 0)
                {
                    placeMatch1--;
                }
            } // ****;
            
            // This if statement decides if the input is same as the hidden number and exits the loop:
            if (varDigit1 == randNum1 && varDigit2 == randNum2 && varDigit3 == randNum3)
            {
                placeMatch1 = 3;
                cout << setw(11) << "You entered: " << varDigit1 << varDigit2 << varDigit3;
                cout << setw(5) << placeMatch1 << setw(10) << placeMatch2 << endl;
                cout << "\n*** Congratulations! ***" << endl;
                cout << "\nExiting program..." << endl;
                break;
            }//****;
            
            counter2++; // Incrementing the counter on each iteration;
            
            //if statement which prints the hidden random numbers if the user inputs 000 as guess:
            if (varDigit1 == 0 && varDigit2 == 0 && varDigit3 == 0)
            {
                cout << "\n" << setw(3) << "Hidden digits are: " << randNum1 << randNum2 << randNum3 << endl;
                counter2--;
                placeMatch2--;
            }
            else
            {
                cout << setw(11) << "You entered: " << varDigit1 << varDigit2 << varDigit3;
                cout << setw(5) << placeMatch1 << setw(10) << placeMatch2 << endl;
                
            }
        }//*** end of the second while loop;
    }//****End of main if loop;
    
    //If the user inputs 's' in the very begining then the compiler goes to this if statement:
void loopFunc2()
    {
        int counter3 = 1;
        int placeMatch1 = 0;                            // var for displayin the in place number;
        int placeMatch2 = 0;                            // var for displaying out of place number;
        int sinDigit1=0, sinDigit2=0,sinDigit3=0;       // similar usage as last declaration for input 's';
        int userIn2 = 0, userIn3 = 0;
            cout << "Enter three distinct digits each in the range 0..9 (e.g. 354): " << endl;
            cout << "Input of 000 displays the hidden digits.  Input of 999 exits the program." <<endl;
            cin >> userIn2;
            
            /*this three lines breaks the single number inputed by user
             to set as hidden digits into 3 different digits for comparing*/
            sinDigit1= userIn2/100;
            sinDigit2= userIn2/10%10;
            sinDigit3= userIn2 % 10;//****
            
            cout << "\n\n"<< setw(50) <<"In place  Out of place" << endl;
            cout << setw(50) << "--------  ------------" << endl;
            
            // code for comparing the set number with the user's guess:
            while (counter3 <= 10) {
                placeMatch1 = 0;
                placeMatch2 = 0;
                cout << counter3 << "." << setw(1) << "Your guess: " << endl;
                cin >> userIn3;
                int varDigit1= 0, varDigit2 = 0, varDigit3 = 0; // var for storing the broken down number to single digit;
                /*this three lines breaks the single number inputed by user
                 as guess into 3 different digits for comparing it with hidden (set) number*/
                varDigit1 = userIn3 / 100;
                varDigit2 = userIn3 / 10 % 10;
                varDigit3 = userIn3 % 10;//****
                
                // this satement outputs desired sentence and exits the loop if the the input is 999;
                if (varDigit1 == 9 && varDigit2 == 9 && varDigit3 == 9) {
                    cout << setw(3) << "Exiting loop..." << endl;
                    cout << "\n" << setw(3) << "Better luck next time." << endl;
                    cout << "\nExiting program..." << endl;
                    break;
                }//****
                
                /* This block starting from here to line 133 (marked as '****' at the end),
                 Compares each digit with the randnum position and deciding the in place
                 and out of place scoring by incrementing and decrementing it acordingly:*/
                if (varDigit1 == sinDigit1) {
                    placeMatch1++;
                    while (placeMatch2 > 0) {
                        placeMatch2--;
                    }
                }
                if (varDigit2 == sinDigit2) {
                    placeMatch1++;
                    while (placeMatch2 > 0) {
                        placeMatch2--;
                    }
                }
                if (varDigit3 == sinDigit3) {
                    placeMatch1++;
                    while (placeMatch2 > 0) {
                        placeMatch2--;
                    }
                }
                
                if (varDigit1 == sinDigit2 || varDigit1 == sinDigit3) {
                    placeMatch2++;
                    while (placeMatch1 > 0) {
                        placeMatch1--;
                    }
                }
                if (varDigit2 == sinDigit1 || varDigit2 == sinDigit3) {
                    placeMatch2++;
                    while (placeMatch1 > 0) {
                        placeMatch1--;
                    }
                }
                
                if (varDigit3 == sinDigit2 || varDigit3 == sinDigit1) {
                    placeMatch2++;
                    while (placeMatch1 > 0) {
                        placeMatch1--;
                    }
                }
                if ((varDigit1 == sinDigit1) && (varDigit2 == sinDigit3 || varDigit3 == sinDigit2)) {
                    placeMatch1++;
                }
                if ((varDigit2 == sinDigit2) && (varDigit3 == sinDigit1 || varDigit1 == sinDigit3)) {
                    placeMatch1++;
                }
                if ((varDigit3 == sinDigit3) && (varDigit1 == sinDigit2 || varDigit2 == sinDigit1)) {
                    placeMatch1++;
                }//****
                
                // This if statement decides if the input is same as the hidden number and exits the loop:
                if (varDigit1 == sinDigit1 && varDigit2 == sinDigit2 && varDigit3 == sinDigit3) {
                    placeMatch1 = 3;
                    placeMatch2 = 0;
                    cout << setw(11) << "You entered: " << varDigit1 << varDigit2 << varDigit3;
                    cout << setw(5) << placeMatch1 << setw(10) << placeMatch2 << endl;
                    cout << "\n*** Congratulations! ***" << endl;
                    cout << "\nExiting program..." << endl;
                    exit(0);
                }//****
                
                counter3++; // Incrementing counter on each iteration;
                
                //if statement which prints the hidden random numbers if the user inputs 000 as guess:
                if (varDigit1 == 0 && varDigit2 == 0 && varDigit3 == 0) {
                    cout << "\n" << setw(3) << "Hidden digits are: " << sinDigit1 << sinDigit2 << sinDigit3 << endl;
                    counter3--;
                    placeMatch2--;
                }
                else{
                    cout << setw(11) << "You entered: " << varDigit1 << varDigit2 << varDigit3;
                    cout << setw(5) << placeMatch1 << setw(10) << placeMatch2 << endl;
                }
                
            }//end of main while loop;
            
            // this prints if the player is not able to guess the right number in 10 moves:
            cout << "\n" << setw(3) << "Better luck next time." << endl;
            cout << "\nExiting program..." << endl;
    }//End Of The VOID Function;



//------------------------------------------------------------------------------------------
int main()
{
    char userInput=' ';
    // Introduction of the game:
    cout << "Program: 2 MasterMind" << endl;
    cout << "The program selects 3 distinct random digits 0..9."<<endl;
    cout << "On each turn you guess 3 digits.  The program indicates"<<endl;
    cout << "how many are correct. You have 10 moves to guess the number." << endl;
    cout << "Good luck!\n" << endl;
    cout << "Press 's' to set the three digits, or 'r' to randomize them: \n" <<endl;
    
    // taking input of either 'r' or 's' which will decide which loop to go in:
    cin >> userInput;
    /*Calling the function which will loop,
     print messages accordingly and decide in place and out of place score:*/
    if (userInput == 'r')
    {
        loopFunc();
    }
    if (userInput == 's')
    {
        loopFunc2();
    }
    
    return 0; // keeping c++ happy as always;
} // end main

