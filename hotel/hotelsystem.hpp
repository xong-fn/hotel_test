using namespace std;
#include <vector>
#include <string>

class Room {
public:
    int roomNumber;
    string roomType;
    bool isAvailable;

    Room(int number, const string& type, bool available);
    void display();
};

class User {
public:
    string name;
    string userID;
    int roomNumber;

    User(const string& name, const string& userID, int roomNum);
    void display();
};

class HotelSystem {
private:
    vector<Room> rooms;
    vector<User> users;

public:
    HotelSystem();
    void displayRooms();
    void bookRoom();
    void viewUserBooking();
    void cancelBooking();
    void printBill();
};
