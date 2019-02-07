/*
 * Author       : Victor Truong
 * CS 2         : MTWR, 7:30a – 12:30p
 * Assignment 11: Breakfast Billing System
 * Due date     : 2/8/19
 */
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MenuItemType
{
    string menuItem;
    double menuPrice;
};

/*
 * FUNCTION: getData
 * 
 * Pulls menu information from the specified file and saves it into a list for
 * the program to use
 */
void getData(string menuFilename,
             vector<MenuItemType>& menuItems);
/*
 * FUNCTION: showMenu
 * 
 * Prints out menu items to user
 */
void showMenu(const vector<MenuItemType> menuItems);
/*
 * FUNCTION: printCheck
 * 
 * Prints out the check for the user's ordered items
 */
void printCheck(const vector<MenuItemType> menuItems,
                const vector<MenuItemType> orderedItems);

/*
 * Breakfast Billing System
 *
 * This program helps a local restaurant automate its breakfast billing system.
 * 
 * IN:
 *   menuFilename: Name of file to pull menu from
 *   choice      : User's item selection
 *   quantity    : User's item selection quantity
 */
int main()
{
    vector<MenuItemType> menuItems;    // IN: List of menu items
    vector<MenuItemType> orderedItems; // IN: List of ordered items
    string menuFilename;               // IN: Name of file to pull menu from
    int choice;                        // IN: User's item selection
    int quantity;                      // IN: User's item selection quantity

    // IN: Get menu file
    cout << "Enter filename: ";
    cin >> menuFilename;
    cout << endl;

    // PROC: Populate menu with items
    getData(menuFilename, menuItems);

    // PROC: Collect all of user's orders
    do
    {
        // OUT: Show menu items
        showMenu(menuItems);

        // IN: Get item selection
        cout << "Enter the item number: ";
        cin >> choice;
        cout << endl;

        // PROC: Process if it's a menu item selection and not exit code
        if (choice != 0)
        {
            // IN: Get item quantity
            cout << "How many would you like to order? ";
            cin >> quantity;
            cout << endl;

            // PROC: Add items to order list
            for (int i = 0; i < quantity; i++)
            {
                int menuItemsIndex = choice - 1; // Map choice number to index
                orderedItems.push_back(menuItems.at(menuItemsIndex));
            }
        }
        
        cout << endl;
    } while (choice != 0);

    // OUT: Print ordered items
    printCheck(menuItems, orderedItems);

    return 0;
}

/*
 * FUNCTION: getData
 * 
 * Pulls menu information from the specified file and saves it into a list for
 * the program to use
 *
 * IN:
 *   menuFilename: Name of file to pull menu from
 *   menuItems   : List to store menu items in
 */
void getData(string menuFilename, vector<MenuItemType>& menuItems)
{
    string rawMenuItem; // PROC: Line directly from file
    fstream file;       // PROC: Menu file object

    // PROC: Open menu file
    file.open(menuFilename.c_str());

    // PROC: Read each line of the file
    while (getline(file, rawMenuItem))
    {
        int priceStartPos = rawMenuItem.find('$');
        string name = rawMenuItem.substr(0, priceStartPos - 1);
        double price = atof(rawMenuItem.substr(priceStartPos + 1).c_str());
        MenuItemType menuItem = { name, price };
        menuItems.push_back(menuItem);
    }

    // PROC: Close file
    file.close();
}

/*
 * FUNCTION: showMenu
 * 
 * Prints out menu items to user
 *
 * IN:
 *   menuItems: List of menu items
 */
void showMenu(const vector<MenuItemType> menuItems)
{
    cout << endl;
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << endl;
    cout << "             Menu" << endl;
    cout << endl;

    // PROC: Print all items on menu
    for (int i = 0; i < menuItems.size(); i++)
    {
        MenuItemType item = menuItems.at(i);
        cout << (i + 1) << ". "
            << left << setw(20) << item.menuItem
            << "$" << right << setw(5) << fixed << setprecision(2) << item.menuPrice << endl;
    }

    cout << endl;
    cout << "Enter 0 when you finish your order." << endl;
    cout << endl;
}

/*
 * FUNCTION: printCheck
 * 
 * Prints out the check for the user's ordered items
 *
 * IN:
 *   menuItems   : List of menu items
 *   orderedItems: List of ordered items
 */
void printCheck(const vector<MenuItemType> menuItems, const vector<MenuItemType> orderedItems)
{
    double subtotal = 0; // PROC: Cost total before tax
    double tax;          // PROC: Tax calculated from subtotal
    double total;        // PROC: Cost total after tax

    cout << endl;
    cout << "Welcome to Johnny's Restaurant" << endl;
    cout << endl;
    cout << "             SALE" << endl;
    cout << endl;

    // PROC: Calculate quantity and subtotal
    for (int i = 0; i < menuItems.size(); i++)
    {
        int itemCount = 0;                   // PROC: Total quantity of the item
        double itemTotal = 0;                // PROC: Total cost of this specific item
        MenuItemType item = menuItems.at(i); // PROC: Current menu item

        // PROC: Tally up ordered items
        for (int j = 0; j < orderedItems.size(); j++)
        {
            // PROC: Increase counter if ordered item matches the current menu item we're counting
            MenuItemType orderedItem = orderedItems.at(j);
            if (orderedItem.menuItem == item.menuItem)
            {
                itemCount++;
            }
        }

        // OUT: Print if user bought at least one
        if (itemCount > 0)
        {
            itemTotal = item.menuPrice * itemCount;
            subtotal += itemTotal;
            cout << left << setw(3) << itemCount << setw(20) << item.menuItem
                << "$" << right << setw(5) << fixed << setprecision(2) << itemTotal << endl;
        }
    }

    // PROC: Calculate final total with tax
    tax = subtotal * 0.05;
    total = subtotal + tax;

    // OUT: Print tax and total
    cout << left << setw(23) << "Tax"
        << "$" << right << setw(5) << fixed << setprecision(2) << tax << endl;
    cout << "-----------------------------" << endl;
    cout << left << setw(23) << "Amount Due"
        << "$" << right << setw(5) << fixed << setprecision(2) << total << endl;
    cout << endl;
}