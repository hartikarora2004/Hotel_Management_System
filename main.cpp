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
// Function to display customer records
void Hotel::displayRecords() {
    ifstream fin("Record.csv");
    int r, flag;
    cout << "\n Enter room no: ";
    cin >> r;
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');

        getline(ss, token, ',');
        days = stoi(token);

        getline(ss, token);
        fare = stof(token);

        if (roomNo == r) {
            cout << "\n Customer Details";
            cout << "\n ----------------";
            cout << "\n Room no: " << roomNo;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Phone no: " << phone;
            cout << "\n Days: " << days;
            cout << "\n Total Fare: " << fare;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "\n Sorry Room no. not found or vacant....!!";
    cout << "\n\n Press any key to continue....!!";
    cin.ignore();
    cin.get();
    fin.close();
}

// Function to display allotted rooms
void Hotel::displayAllottedRooms() {
    ifstream fin("Record.csv");
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    ----------------------";
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');

        getline(ss, token, ',');
        days = stoi(token);

        getline(ss, token);
        fare = stof(token);

        cout << "\n Room no: " << roomNo << "\n Name: " << name;
        cout << "\n Address: " << address << "\n Phone: " << phone;
        cout << "\n Days: " << days << "\n Total: " << fare;
        cout << "\n**********************************";
    }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    cin.ignore();
    cin.get();
    fin.close();
}

// Function to edit customer record
void Hotel::editRecord() {
    int choice, r;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1.Modify Customer Record";
    cout << "\n 2.Delete Customer Record";
    cout << "\n Enter your choice: ";
    cin >> choice;
    cout << "\n Enter room no: ";
    cin >> r;
    switch (choice) {
        case 1:
            modifyRecord(r);
            break;
        case 2:
            deleteRecord(r);
            break;
        default:
            cout << "\n Wrong Choice.....!!";
            break;
    }
    cout << "\n Press any key to continue....!!!";
    cin.ignore();
    cin.get();
}

// Function to check room status
int Hotel::checkRoom(int r) {
    ifstream fin("Record.csv");
    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        if (roomNo == r) {
            fin.close();
            return 1; // Room is already booked
        }
    }
    fin.close();
    return 0; // Room is vacant
}

// Function to modify customer record
void Hotel::modifyRecord(int r) {
    ifstream fin("Record.csv");
    ofstream fout("temp.csv", ios::out | ios::app);

    string line;
    bool found = false;

    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        if (roomNo == r) {
            found = true;

            cout << "Modify Customer Details" << endl;
            cout << "------------------------" << endl;

            cout << "Name: ";
            cin >> name;
            cout << "Address: ";
            cin >> address;
            cout << "Phone No: ";
            cin >> phone;
            cout << "No of Days to Checkout: ";
            cin >> days;
            fare = days * 900; // Assuming default price per day is 900

            fout << roomNo << ","
                 << name << ","
                 << address << ","
                 << phone << ","
                 << days << ","
                 << fare << "\n";

            cout << "\nRecord modified successfully!" << endl;
        } else {
            fout << line << endl;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    fin.close();
    fout.close();

    remove("Record.csv");
    rename("temp.csv", "Record.csv");
}

void Hotel::deleteRecord(int r) {
    ifstream fin("Record.csv");
    ofstream fout("temp.csv", ios::out | ios::app);

    string line;
    bool found = false;

    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        if (roomNo == r) {
            found = true;
            cout << "Record deleted successfully!" << endl;
        } else {
            fout << line << endl;
        }
    }

    if (!found) {
        cout << "Record not found!" << endl;
    }

    fin.close();
    fout.close();

    remove("Record.csv");
    rename("temp.csv", "Record.csv");
}

void Hotel::readFromCSV() {
    ifstream fin("Record.csv");

    if (!fin.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        roomNo = stoi(token);

        getline(ss, name, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');

        getline(ss, token, ',');
        days = stoi(token);

        getline(ss, token);
        fare = stof(token);

        // Displaying the read data
        cout << "Room No: " << roomNo << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Days: " << days << endl;
        cout << "Total Fare: " << fare << endl;
        cout << "-----------------" << endl;
    }

    fin.close();
}


// Function to write data to CSV
void Hotel::writeToCSV() {
    ofstream file("Record.csv", ios::app);

    file << roomNo << ","
         << name << ","
         << address << ","
         << phone << ","
         << days << ","
         << fare << "\n";

    file.close();
}

int main() {
    Hotel h;
    h.readFromCSV(); // Load data from CSV on startup
    h.displayMenu();
    h.writeToCSV(); // Save data to CSV before exiting
    return 0;
}
