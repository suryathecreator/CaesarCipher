/*
This program is about Caesar Cypher. A Caeser Cypher is a way to encode messages. 
A Caesar Cypher takes a message and shifts each character a fixed number of
characters in the alphabet. For example, if the message is "I love pizza!" and the
cypher takes a right shift of 1, then the encrypted message becomes "J mpwf qjaab!".
Notice how the letter 'z' wraps around to become letter 'a'. Also notice how
punctuation and spaces remain the same.
*/

#include <iostream>
#include <string>
using namespace std;

// Function prototypes.
char rotate(unsigned char, int);
string encipher(string, int);
string decipher(string);
double letterScore(char);

int main() {

    // User's choice for what the program should do.
    int choice = 1;
    // Keeps running the program loop until the user exits.
    while (choice != 3)
    {
            cout << endl;
            cout << "Welcome. Please choose from the following options. " << endl;
            cout << "1. Encrypt a message" << endl;
            cout << "2. Decode a message" << endl;
            cout << "3. End program" << endl; 
            cout << "Enter your choice: ";
            cin >> choice;
            // Clears input so it does not overflow when it hits a space.
            cin.ignore();
        
        // If condition for each option.
        if (choice == 1)
        {
            // Variable str is the user's input.
            // Variable encrypted is the encrypted message returned to the user.
            string messageToEncrypt, encrypted; 
            // Variable n is the number of Caesar Shift's
            int caesarShift; 
            cout << "Enter a message to encrypt: ";
            // Using getline because if we use Cin, it will get stops when it hits a whitespace.
            getline(cin, messageToEncrypt);
            cout << "Enter a caesar shift from 1 to 25: ";
            cin >> caesarShift;
            cin.ignore();

            // To make sure the user does not enter a Caesar Shift more than 25 or less than 1 since they will be the same shifts repeating past that; less efficient.
            if ((caesarShift < 1) || (caesarShift > 25)) 
            {
                cout << "Invalid input. Rerun." << endl;
                exit(1);
            }
            // Encrypting the message.
            encrypted = encipher(messageToEncrypt, caesarShift); 
            cout << "Your encrypted message is: " << encrypted << endl;
        }
        else if (choice == 2)
        {
            // Variable str is the user's input. 
            // Variable deciphered is the probable decrypted string.
            string messageToDecipher, deciphered; 
            cout << "Enter a message to decode: ";
            // Using getline because if we use Cin, it will get stops when it hits a whitespace.
            getline(cin, messageToDecipher); 
            // Deciphering the message.
            deciphered = decipher(messageToDecipher); 
            cout << "Your deciphered message is: " << deciphered << endl;
        }
        // If the user wants to exit the program.
        else if (choice == 3)
        {
            cout << "Goodbye!" << endl;
            cout << endl;
            exit(1);
        }
        // If the user entering an input other than 1, 2, or 3.
        else 
        {
            cout << "Invalid input. Rerun." << endl;
            exit(1);
        }

    }

    return 0;

}
    

// This is the function which shifts each character.
char rotate(unsigned char ch, int n)
{
    // Counter to keep track of whether or not we have reached the wanted number of Caesar Shift's.
    int counter = 1;
   
    while (counter <= n)
    {
        // For lowercase scenarios.
        if ((ch >= 'a') && (ch <= 'z'))
        {
            if (ch == 'z')
            {
                // For the case when we need to wrap around to a.
                ch = 'a';
            }
            else 
                ch++;
        }
        // For uppercase scenarios.
        else if ((ch >= 'A') && (ch <= 'Z'))
        {
            if (ch == 'Z')
            {
                // For the case when we need to wrap around to A.
                ch = 'A';
            }
            else
                ch++;
        }
    // For cases where the character is not in the alphabet such as a period.
        else
            break;
        counter++;
    }
    return ch;
}

// Function that will encrypt the message that the user inputs using Caesar Shift.
string encipher(string str, int n) 
{
    // Variable index is the character position in the string.
    int index = 0;
    unsigned char ans;
    while (index < str.length())
    {   
        // Variable ans is the rotated character. 
        ans = rotate(str[index], n);
        // Replacing the character position with the rotated character.
        str[index] = ans;

        index++;
    }

    return str;

}
// Deciphering the message that the user entered.
string decipher(string str)
{
    // Variable probablestring is the string the decoded message is most likely to be.
    string probablestring;
    // Variable score is the score for each character.
    double score;
    // Variable counter for keeping track of each time we increase the amount of Caesar Shift's.
    int counter = 1;
    // Variable gettingscored as a holder for the character currently passing through the function letterScore.
    char gettingscored;
    // Variable sum for the score for each string as a whole.
    double sum;
    // Variable highestsumsofar for holding the score of the string with the highest score which is the most probable string.
    double highestsumsofar = 0;
    // String tester to hold the string of the result in each Caesar Shift.
    string tester;
    while (counter <= 25)
    {
        sum = 0;
        // Getting the Caesar Shifted string for each increment on the counter.
        tester = encipher(str, counter);
        // Transversing the string.
        for (int i = 0; i < tester.length(); i++) 
        {
            gettingscored = tester[i];
            // The character getting scored.
            score = letterScore(gettingscored);
            // Adding the score onto the overall sum for the string.
            sum = sum + score;
        }
        // If condition to check if the string just scored is higher than the most probable string up to now.
        if (sum > highestsumsofar)
        {
            highestsumsofar = sum;
            probablestring = tester;

        }
        counter++;
    }
    return probablestring;
} 

// Helper function to score the characters passed through it.
double letterScore(char ch)
{ 
    if (ch == 'A' || ch == 'a') return .0684; 
    if (ch == 'B' || ch == 'b') return .0139;
    if (ch == 'C' || ch == 'c') return .0146; 
    if (ch == 'D' || ch == 'd') return .0456; 
    if (ch == 'E' || ch == 'e') return .1267; 
    if (ch == 'F' || ch == 'f') return .0234; 
    if (ch == 'G' || ch == 'g') return .0180; 
    if (ch == 'H' || ch == 'h') return .0701; 
    if (ch == 'I' || ch == 'i') return .0640; 
    if (ch == 'J' || ch == 'j') return .0033; 
    if (ch == 'K' || ch == 'k') return .0093; 
    if (ch == 'L' || ch == 'l') return .0450; 
    if (ch == 'M' || ch == 'm') return .0305; 
    if (ch == 'N' || ch == 'n') return .0631; 
    if (ch == 'O' || ch == 'o') return .0852; 
    if (ch == 'P' || ch == 'p') return .0136; 
    if (ch == 'Q' || ch == 'q') return .0004; 
    if (ch == 'R' || ch == 'r') return .0534; 
    if (ch == 'S' || ch == 's') return .0659; 
    if (ch == 'T' || ch == 't') return .0850; 
    if (ch == 'U' || ch == 'u') return .0325; 
    if (ch == 'V' || ch == 'v') return .0084; 
    if (ch == 'W' || ch == 'w') return .0271; 
    if (ch == 'X' || ch == 'x') return .0007; 
    if (ch == 'Y' || ch == 'y') return .0315; 
    if (ch == 'Z' || ch == 'z') return .0004; 
    return 0.0;  
} 