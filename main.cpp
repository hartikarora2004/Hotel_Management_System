// Include header files
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ios>   
#include <limits>
#include<vector>
#include <iomanip>
using namespace std;

// Hotel Class
class Hotel {
private:
    int roomNo;
    string name;
    string address;
    string phone;
    int days;
    float fare;

public:
    void displayMenu();
    void bookRoom();
    void displayRecords();
    void displayAllottedRooms();
    void editRecord();
    void modifyRecord(int);
    void deleteRecord(int);
    int checkRoom(int);
    void readFromCSV();
    void writeToCSV();
};
// Function to display main menu
void Hotel::displayMenu() {
    int choice;
    while (choice != 5) {
        cout << "\n\n\t\t\t\t*************";
        cout << "\n\t\t\t\t* MAIN MENU *";
        cout << "\n\t\t\t\t*************";
        cout << "\n\n\n\t\t\t1. Book A Room";
        cout << "\n\t\t\t2. Customer Record";
        cout << "\n\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t4. Edit Record";
        cout << "\n\t\t\t5. Exit";
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                displayAllottedRooms();
                break;
            case 4:
                editRecord();
                break;
            case 5:
                break;
            default:
                cout << "\n\n\t\t\tWrong choice.....!!!";
                cout << "\n\t\t\tPress any key to continue....!!";
                cin.ignore();
                cin.get();
                break;
        }
    }
}

// Function to book a room
void Hotel::bookRoom() {
    ofstream fout("Record.csv", ios::app);
    int r, flag;
    cout << "\n Enter Customer Details";
    cout << "\n ----------------------";
    cout << "\n\n Room no: ";
    cin >> r;
    flag = checkRoom(r);
    if (flag)
        cout << "\n Sorry..!!!Room is already booked";
    else {
        roomNo = r;
        cout << " Name: ";
        cin >> name;
        cout << " Address: ";
        cin >> address;
        cout << " Phone No: ";
        cin >> phone;
        cout << " No of Days to Checkout: ";
        cin >> days;
        fare = days * 900; // Assuming default price per day is 900
        writeToCSV();
        cout << "\n Room is booked...!!!";
    }

    cout << "\n Press any key to continue.....!!";
    cin.ignore();
    cin.get();
    fout.close();
}
