#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

const int INPUT_SIZE = 100;

void printPrompt();
void getInputStr(char str[], bool isNew);
int getConsonantCount(char str[]);
int getVowelCount(char str[]);
void strToLower(char str[]);
void strToUpper(char str[]);
bool isVowel(char letter);

int main()
{
    char inputStr[INPUT_SIZE + 1]; // Extra character to accomodate for null char
    char choice;

    getInputStr(inputStr, false);
    printPrompt();
    cout << endl;

    do
    {
        cout << "Enter your menu selection: ";
        cin >> choice;
        cout << endl;
        choice = tolower(choice);
        switch (choice)
        {
            case 'a':
                cout << "Number of vowels: " << getVowelCount(inputStr) << endl;
                break;
            case 'b':
                cout << "Number of consonants: " << getConsonantCount(inputStr) << endl;
                break;
            case 'c':
                strToUpper(inputStr);
                break;
            case 'd':
                strToLower(inputStr);
                break;
            case 'e':
                cout << inputStr << endl;
                break;
            case 'f':
                cin.clear();
                cin.ignore();
                getInputStr(inputStr, true);
                break;
            case 'm':
                printPrompt();
                break;
        }
        if (!(choice == 'c' || choice == 'd' || choice == 'f' || choice == 'x'))
        {
            cout << endl;
        }
    } while (choice != 'x');

    return 0;
}

void getInputStr(char str[], bool isNew)
{
    if (!isNew)
    {
        cout << "Input a line of text, up to " << INPUT_SIZE << " characters: " << endl;
    }
    else
    {
        cout << "Input a new line of text, up to " << INPUT_SIZE << " characters: " << endl;
    }

    cin.getline(str, INPUT_SIZE);
}

void printPrompt()
{
    cout << "A)  Count the number of vowels in the string" << endl
        << "B)  Count the number of consonants in the string" << endl
        << "C)  Convert the string to uppercase" << endl
        << "D)  Convert the string to lowercase" << endl
        << "E)  Display the current string" << endl
        << "F)  Enter another string" << endl
        << endl
        << "M)  Display this menu" << endl
        << "X)  Exit the program" << endl;
}

int getConsonantCount(char str[])
{
    int count;
    char currChar;
    count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        currChar = tolower(str[i]);
        if (isalpha(currChar) && !isVowel(currChar))
        {
            count++;
        }
    }

    return count;
}

int getVowelCount(char str[])
{
    int count;
    char currChar;
    count = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        currChar = tolower(str[i]);
        if (isVowel(currChar))
        {
            count++;
        }
    }

    return count;
}

void strToLower(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void strToUpper(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
}

bool isVowel(char letter)
{
    return letter == 'a' ||
        letter == 'e' ||
        letter == 'i' ||
        letter == 'o' ||
        letter == 'u';
}