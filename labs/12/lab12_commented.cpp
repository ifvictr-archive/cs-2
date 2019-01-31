/******************************************************************************
 * AUTHOR    : Hongyuan Zhang, Victor Truong
 * LAB #12   : cStrings
 * CLASS     : CS002
 * SECTION   : M-Thurs: 7:30a-12:30p
 * DUE DATE  : 1/29/19
******************************************************************************/
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

const int INPUT_SIZE = 100;
/******************************************************************************
 * printPrompt
 *  This function prints the menu
 *****************************************************************************/
void printPrompt();
/******************************************************************************
 * getInputStr
 *  This function gets input from user
 *****************************************************************************/
void getInputStr(char str[],            //IN - a cstring
                 bool isNew);           //IN - a boolean
/******************************************************************************
 * getConsonantCount
 *  This function counts and returns number of consonants in a cstring
 *****************************************************************************/
int getConsonantCount(char str[]);      //IN - a cstring
/******************************************************************************
 * getVowelCount
 *  This function counts and returns number of vowels in a cstring
 *****************************************************************************/
int getVowelCount(char str[]);          //IN - a cstring
/******************************************************************************
 * strToLower
 *  This function convert all characters in a cstring to lowercase
 *****************************************************************************/
void strToLower(char str[]);            //IN - a cstring
/******************************************************************************
 * strToUpper
 *  This function convert all characters in a cstring to uppercase
 *****************************************************************************/
void strToUpper(char str[]);            //IN - a cstring
/******************************************************************************
 * isVowel
 *  This function returns a boolean deppending on whether the letter is vowel
 *****************************************************************************/
bool isVowel(char letter);              //IN - user's choice of letter

/******************************************************************************
*
* cStrings
*
*______________________________________________________________________________
* The program runs exercise for lab 12
*______________________________________________________________________________
* INPUT:
* inputStr: user's choice of input
* choice; user's choice under menu
*
******************************************************************************/
int main()
{
   char inputStr[INPUT_SIZE + 1];       //INPUT - User input of cstring
   char choice;                         //INPUT - User's choice in menu

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
               cout << "Number of consonants: " << getConsonantCount(inputStr)
                    << endl;
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

/*******************************************************************************
*
* FUNCTION getInputStr
*_________________________________________________________
*
* This function gets input from user
*
* _________________________________________________________
* PRE-CONDITIONS
*  str[]: Variable to hold user input in
*  isNew: Determine which message to send out
*
* POST-CONDITIONS
*  Will store the result of the user input in str
******************************************************************************/

void getInputStr(char str[],                //IN - a cstring
                 bool isNew)                //IN - a boolean
{
   if (!isNew)
   {
       cout << "Input a line of text, up to " << INPUT_SIZE << " characters: "
            << endl;
   }
   else
   {
       cout << "Input a new line of text, up to " << INPUT_SIZE
            << " characters: " << endl;
   }

   cin.getline(str, INPUT_SIZE);
}


/******************************************************************************
*
* Function printPrompt
*------------------------------------------------------------------------------
* This function This function prints the menu
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need no previously defined values
*
* POST-CONDITIONS
*       This function prints the menu
******************************************************************************/
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

/******************************************************************************
*
* Function isVowel
*------------------------------------------------------------------------------
* This function This function verifies if a letter is a vowel and returns a
*   boolean
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       letter : a character
*
* POST-CONDITIONS
*       This function verifies if a letter is a vowel and returns a boolean
******************************************************************************/
bool isVowel(char letter)               //IN - a character
{
   return letter == 'a' ||
       letter == 'e' ||
       letter == 'i' ||
       letter == 'o' ||
       letter == 'u';
}

/******************************************************************************
*
* Function getConsonantCount
*------------------------------------------------------------------------------
* This function This function counts and returns number of Consonants in a
*   cstring
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       str : a cstring
*
* POST-CONDITIONS
*       This function counts and returns number of Consonants in a cstring
******************************************************************************/
int getConsonantCount(char str[])       //IN - a cstring
{
   int count;                           //CALC - number of consonants
   char currChar;                       //CALC - current character in iteration
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

/******************************************************************************
*
* Function getVowelCount
*------------------------------------------------------------------------------
* This function This function counts and returns number of vowels in a cstring
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       str : a cstring
*
* POST-CONDITIONS
*       This function counts and returns number of vowels in a cstring
******************************************************************************/
int getVowelCount(char str[])         //IN - a cstring
{
   int count=0;                       //CALC - number of vowels
   char currChar;                     //CALC - current character in iteration
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
/******************************************************************************
*
* Function strTolower
*------------------------------------------------------------------------------
* This function This function convert all characters in a cstring to lower case
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       str : a cstring
*
* POST-CONDITIONS
*       This function convert all characters in a cstring to lower case
******************************************************************************/
void strToLower(char str[])             //IN - a cstring
{
   for (int i = 0; i < strlen(str); i++)
   {
       str[i] = tolower(str[i]);
   }
}
/******************************************************************************
*
* Function strToUpper
*------------------------------------------------------------------------------
* This function This function convert all characters in a cstring to uppercase
*------------------------------------------------------------------------------
* PRE-CONDITIONS
*   The following need previously defined values:
*       str : a cstring
*
* POST-CONDITIONS
*       This function convert all characters in a cstring to uppercase
******************************************************************************/
void strToUpper(char str[])             //IN - a cstring
{
   for (int i = 0; i < strlen(str); i++)
   {
       str[i] = toupper(str[i]);
   }
}
