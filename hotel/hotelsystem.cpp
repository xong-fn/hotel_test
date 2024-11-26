#include "hotelsystem.hpp"

#include <iostream>


Room::Room(int number, const string& type, bool available)
        : roomNumber(number), roomType(type), isAvailable(available) {}

void Room::display() 
    {
        cout << "RoomNumber: " << roomNumber << ", RoomType: " << roomType;
        cout << ", Is available: " << 
        (isAvailable ? "Free" : "Is Booked") << endl;
    }

User::User(const string& name, const string& userID, int roomNum)
        : name(name), userID(userID), roomNumber(roomNum) {}

void User::display() {
        cout << "User Name: " << name << ", User ID: " << userID;
        cout << ", Which RoomNumber to choose: " << roomNumber << endl;
    }


HotelSystem::HotelSystem() {
        rooms.push_back(Room(101, "Type1", true));
        rooms.push_back(Room(102, "Type2", true));
        rooms.push_back(Room(103, "Type3", true));
        rooms.push_back(Room(104, "Type4", true));
    }

void HotelSystem::displayRooms() 
    {
        cout << "\nCurrent room situation:\n";
        for (auto room = rooms.begin(); room != rooms.end(); room++) {
            (*room).display();
        }
    }

void HotelSystem::bookRoom() 
    {
        string name, userID;
        int roomNumber;

        cout << "\nEnter User's name: ";
        cin >> name;
        cout << "Enter Uesr's ID: ";
        cin >> userID;
        cout << "Enter the reservation RoomNumber: ";
        cin >> roomNumber;

        bool roomFound = false;
        for (auto room = rooms.begin(); room != rooms.end(); room++)
        {
            if ((*room).roomNumber == roomNumber && (*room).isAvailable) 
            {
                (*room).isAvailable = false;
                users.push_back(User(name, userID, roomNumber));
                cout << "Book successfuly!\n";
                roomFound = true;
                break;
            }
        }

        if (!roomFound) {
            cout << "RoomNumber Error,Enter again!\n";
        }
    }

void HotelSystem::viewUserBooking() 
    {
        string userID;
        cout << "\nEnter userID view reservaton information: ";
        cin >> userID;

        bool userFound = false;
        for (auto user = users.begin(); user != users.end(); user++) {
            if ((*user).userID == userID) 
            {
                (*user).display();
                userFound = true;
                break;
            }
        }

        if (!userFound) {
            cout << "Not find user!\n";
        }
    }

void HotelSystem::cancelBooking() 
    {
        string userID;
        cout << "\nEnter userID cancel Booking: ";
        cin >> userID;

        bool userFound = false;
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->userID == userID) 
            {
                for (auto& room : rooms) 
                {
                    if (room.roomNumber == it->roomNumber) 
                    {
                        room.isAvailable = true;
                        break;
                    }
                }
                users.erase(it);
                cout << "Cancel sucessfully!\n";
                userFound = true;
                break;
            }
        }

        if (!userFound) 
        {
            cout << "Not find user's Booking!\n";
        }
    }

void HotelSystem::printBill() 
    {
        string userID;
        cout << "\nEnter userID check  Bills: ";
        cin >> userID;

        bool userFound = false;
        for (auto& user : users) 
        {
            if (user.userID == userID) 
            {
                int roomPrice = 0;
                for (auto& room : rooms) 
                {
                    if (room.roomNumber == user.roomNumber) 
                    {
                        if (room.roomType == "Type1") roomPrice = 100;
                        else if (room.roomType == "Type2") roomPrice = 200;
                        else if (room.roomType == "Type3") roomPrice = 500;
                        else if (room.roomType == "Type4") roomPrice = 1000;
                    }
                }

                cout << "\nBill:\n";
                cout << "User name: " << user.name << "\n";
                cout << "Room Number: " << user.roomNumber << ", RoomType: " << 
                    (user.roomNumber == 101 ? "Type1" : 
                    user.roomNumber == 102 ? "Type2" : 
                    user.roomNumber == 103 ? "Type3" : "Type4") << "\n";
                cout << "Room Price: " << roomPrice << "\n";
                userFound = true;
                break;
            }
        }

        if (!userFound) {
            cout << "Not find user's Booking!\n";
        }
    }



