
#include <iostream>
#include "hotelsystem.hpp"

int main() {
    HotelSystem hotel;
    int choice;

    while (true) {
        cout << "\n========== HotelSystem ==========\n";
        cout << "\t1. DisplayRooms information\n";
        cout << "\t2. Book Room\n";
        cout << "\t3. View User Booking\n";
        cout << "\t4. Cancel Booking\n";
        cout << "\t5. Check Bill\n";
        cout << "\t6. Exit\n";
        cout << "Choose(1-6):";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.viewUserBooking();
                break;
            case 4:
                hotel.cancelBooking();
                break;
            case 5:
                hotel.printBill();
                break;
            case 6:
                cout << "\n";
                return 0;
            default:
                cout << "ERRO: please input again!\n";
        }
    }

    return 0;
}