#include <iostream>

#include <string.h>

#include <conio.h>

#define max 100

using namespace std;
// Creating a class named "Customer"
class Customer

{

public:

    char name[100];

    char address[100];

    char phone[12];

    char from_date[20];

    char to_date[20];

    float payment_advance;

    int booking_id;

};
// Creating a class named "Room"
class Room

{

public:

    char type;

    char stype;

    char ac;

    int roomNumber;

    int rent;

    int status;

    class Customer cust;

    class Room addRoom(int);

    void searchRoom(int);

    void displayRoom(Room);

};
// Global Declarations
class Room rooms[max];

int count = 0;

// Details regarding the rooms
Room Room::addRoom(int rno)

{

    class Room room;

    room.roomNumber = rno;

        printf("\n||=======================================================================||");

        printf("\n||          Press [A/N]  AC or NON-AC                                    ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [S/N] COMFORT TYPE                                     ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [B/S] ROOM SIZE                                        ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||         ENTER DAILY RENT                                              ||");

        printf("\n||-----------------------------------------------------------------------||");

        cout<<endl;

        std:: cin >> room.ac;

        std:: cin >> room.type;

         std:: cin >> room.stype;

         std:: cin >> room.rent;

         room.status = 0;

         printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                ROOM ADDED SUCCESSFULLY                                ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

    getch();

    return room;
}
// Searching for the room number and then program displays if it is available or reserved.
void Room::searchRoom(int rno)

{
    int i, found = 0;

    for (i = 0; i < count; i++)

    {

        if (rooms[i].roomNumber == rno)

        {

            found = 1;

            break;

        }

    }

    if (found == 1)

    {

        std:: cout << "Room Details\n";

        if (rooms[i].status == 1)

            {
                std::  cout << "\nRoom is Reserved";
            }
        else

        {

            std::  cout << "\nRoom is available";

        }

        displayRoom(rooms[i]);

        getch();

    }

    else

    {

        std:: cout << "\nRoom not found";

        getch();

    }

}
// Displays details
void Room::displayRoom(Room tempRoom)

{

    std:: cout << "\nRoom Number: \t" << tempRoom.roomNumber;

    std:: cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;

    std:: cout << "\nType Comfort (S/N) " << tempRoom.type;

    std:: cout << "\nType Size (B/S) " << tempRoom.stype;

    std:: cout << "\nRent: " << tempRoom.rent;

}
    // hotel management class
    class HotelMgnt : protected Room
{
public:

    void checkIn();

    void getAvailRoom();

    void searchCustomer(char *);

    void checkOut(int);

    void guestSummaryReport();

};
// displays the guest list and status of room
void HotelMgnt::guestSummaryReport()

{
    if (count == 0)

    {

        std:: cout << "\n No Guest in Hotel !!";

    }

    for (int i = 0; i < count; i++)

    {

        if (rooms[i].status == 1)

        {

            std:: cout << "\n Customer First Name : " << rooms[i].cust.name;

            std:: cout << "\n Room Number : " << rooms[i].roomNumber;

            std:: cout << "\n Address (only city) : " << rooms[i].cust.address;

            std:: cout << "\n Phone : " << rooms[i].cust.phone;

            std:: cout << "\n---------------------------------------";

        }

    }

    getch();

}
// hotel management reservation of room
void HotelMgnt::checkIn()

{

    int i, found = 0, rno;

    class Room room;

    std:: cout << "\nEnter Room number : ";

    std:: cin >> rno;

    for (i = 0; i < count; i++)

    {

        if (rooms[i].roomNumber == rno)

        {
            found = 1;

            break;

        }

    }

    if (found == 1)

    {

        if (rooms[i].status == 1)

            {

                std:: cout << "\nRoom is already Booked";

                getch();

                return ;
            }
        // asking for details
        std:: cout << "\nEnter booking id: ";

        std:: cin >> rooms[i].cust.booking_id;

        std:: cout << "\nEnter Customer Name (First Name): ";

        std:: cin >> rooms[i].cust.name;

        std:: cout << "\nEnter Address (only city): ";

        std:: cin >> rooms[i].cust.address;

        std:: cout << "\nEnter Phone: ";

        std:: cin >> rooms[i].cust.phone;

        std:: cout << "\nEnter From Date: ";

        std:: cin >> rooms[i].cust.from_date;

        std:: cout << "\nEnter to Date: ";

        std:: cin >> rooms[i].cust.to_date;

        std:: cout << "\nEnter Advance Payment: ";

        std:: cin >> rooms[i].cust.payment_advance;

        rooms[i].status = 1;

        std:: cout << "\n Customer Checked-in Successfully..";

        getch();

    }
}
// hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
    int i, found = 0;

    for (i = 0; i < count; i++)

    {
        if (rooms[i].status == 0)

        {

            displayRoom(rooms[i]);

            std:: cout << "\n\nPress enter for next room";

            found = 1;

            getch();

        }
    }

    if (found == 0)

    {

        std:: cout << "\nAll rooms are reserved";

        getch();

    }

}
// hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname)

{

    int i, found = 0;

    for (i = 0; i < count; i++)

    {

        if (rooms[i].status == 1 && stricmp(rooms[i].cust.name, pname) == 0)

        {

            cout << "\nCustomer Name: " << rooms[i].cust.name;

            cout << "\nRoom Number: " << rooms[i].roomNumber;

            cout << "\n\nPress enter for next record";

            found = 1;

            getch();

        }

    }

    if (found == 0)

    {

        cout << "\nPerson not found.";

        getch();

    }

}
// hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)

{

    int i, found = 0, days, rno;

    float billAmount = 0;

    for (i = 0; i < count; i++)

    {

        if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)

        {
            // rno = rooms[i].roomNumber;
            found = 1;
            // getch();
            break;

        }

    }

    if (found == 1)

    {

        cout << "\nEnter Number of Days:\t";

        cin >> days;

        billAmount = days * rooms[i].rent;

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||               CHECK OUT DETAILS                                       ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

         cout<<"\n||          CUSTOMER NAME                                                ||"<<rooms[i].cust.name;

         cout<<"\n||-----------------------------------------------------------------------||";

         cout<<"\n||          ROOM NUMBER                                                  ||"<<rooms[i].roomNumber;

         cout<<"\n||-----------------------------------------------------------------------||";

         cout<<"\n||          ADDRESS                                                      ||"<<rooms[i].cust.address;

         cout<<"\n||-----------------------------------------------------------------------||";

        cout<< "\n||          PHONE NUMBER                                                 ||"<<rooms[i].cust.phone;

        cout<< "\n||-----------------------------------------------------------------------||";

        cout<< "\n||          AMOUNT DUE                                                   ||"<<billAmount;

         cout<<"\n||-----------------------------------------------------------------------||";

        cout<< "\n||          ADVANCE PAID:                                                ||"<<rooms[i].cust.payment_advance;

        cout<< "\n||-----------------------------------------------------------------------||";

        cout<< "\n||          TOTAL PAYABLE                                                ||"<<billAmount - rooms[i].cust.payment_advance<< "/ only" ;

        printf("\n||-----------------------------------------------------------------------||");

        rooms[i].status = 0;

    }

    getch();

}
// managing rooms (adding and searching available rooms)
void manageRooms()
{
    class Room room;

    int opt, rno, i, flag = 0;

    char ch;

    do

    {

        system("cls");

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                  HOTEL MANAGEMENT                                     ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

        printf("\n||          Press [1]  TO ADD ROOMS                                      ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [2] SEARCH ROOM                                        ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [3] BACK TO MAIN MENU                                  ||");

        printf("\n||-----------------------------------------------------------------------||");

        cout << "\n\nEnter Option: ";

        cin >> opt;
        // switch statement

        switch (opt)

        {

        case 1:

            cout << "\nEnter Room Number: ";

            cin >> rno;

            for (i = 0; i < count; i++)

            {

                if (rooms[i].roomNumber == rno)

                {

                    flag = 1;

                }

            }

            if (flag == 1)

            {

                cout << "\nRoom Number is Present.\nPlease enter unique Number";

                flag = 0;

                getch();

            }

            else

            {

                rooms[count] = room.addRoom(rno);

                count++;

            }

            break;

        case 2:

            cout << "\nEnter room number: ";

            cin >> rno;

            room.searchRoom(rno);

            break;

        case 3:

            // nothing to do
            break;

        default:

            cout << "\nPlease Enter correct option";

            break;

        }

    }
     while (opt != 3);

}

using namespace std;

int main()

{

    class HotelMgnt hm;

    int i, j, opt, rno;

    char ch;

    char pname[100];

    system("cls");

    do

    {

        system("cls");

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                Welcome to  HOTEL MANAGEMENT SYSTEM                    ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

        printf("\n||          Press [1]  TO MANAGE ROOMS                                   ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [2] To CHECK IN ROOM                                   ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [3] AVAILABLE ROOM                                     ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [4]  SEARCH CUSTOMER                                   ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [5] To CHECK OUT                                       ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [6] GUEST SUMMARY REPORT                               ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [7] To EXIT                                            ||");

        printf("\n||-----------------------------------------------------------------------||");

        cout << "\n\nEnter Option: ";

        cin >> opt;

        switch (opt)

        {

        case 1:

            manageRooms();

            break;

        case 2:

            if (count == 0)

            {

                cout << "\nRooms data is not available.\nPlease add the rooms first.";

                getch();

            }

            else

                hm.checkIn();

            break;

        case 3:

            if (count == 0)

            {
                cout << "\nRooms data is not available.\nPlease add the rooms first.";

                getch();

            }

            else

                hm.getAvailRoom();

            break;

        case 4:

            if (count == 0)

            {

                cout << "\nRooms are not available.\nPlease add the rooms first.";

                getch();

            }

            else

            {

                cout << "Enter Customer Name: ";

                cin >> pname;

                hm.searchCustomer(pname);

            }

            break;

        case 5:

            if (count == 0)

            {

                cout << "\nRooms are not available.\nPlease add the rooms first.";

                getch();

            }

            else

            {

                cout << "Enter Room Number : ";

                cin >> rno;

                hm.checkOut(rno);

            }

            break;

        case 6:

            hm.guestSummaryReport();

            break;

        case 7:

            cout << "\nTHANK YOU! FOR USING SOFTWARE";

            break;

        default:

            cout << "\nPlease Enter correct option";

            break;

        }

    }
    while (opt != 7);

    getch();

}
