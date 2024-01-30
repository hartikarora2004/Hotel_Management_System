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
