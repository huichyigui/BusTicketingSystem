#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

//constant declaration
#define JB_S 40
#define JB_P 70
#define PP_S2 50
#define PP_P2 95
#define PP_P5 100

//functiion declaration
void menu();
void book_ticket();
void datebusJB(char);
void datebusPP(char);
void calculate(char, char, char, int);
void payment(char, char, char, int, double);
int e_accountcreate();
void receipt();
void invoice();
void report();
void dailysales();
void endOfDay();

//variables
int age[100], qty, order = 1, customerTotal = 0, qtyBTotal = 0, qtyCTotal = 0;
bool monday_booked = false, tuesday_booked = false, thursday_booked = false, friday_booked = false;
double amount[100], amountPaid = 0, amountCharge = 0, monTotal = 0, thursTotal = 0,
tueTotal = 0, friTotal = 0, jbTotal = 0, premiumTotal = 0, standardTotal = 0, ppTotal = 0, sumPay = 0, sumTotal = 0, qtylist[100], paymentlist[100];

int main()
{
    //Bus Logo
    cout << "                     *******************" << endl;
    cout << "                *****************************" << endl;
    cout << "           ***************************************" << endl;
    cout << "          ***********                   ***********" << endl;
    cout << "          *****************************************" << endl;
    cout << "          *****************************************" << endl;
    cout << "          ****          __   ____   ___         ****" << endl;
    cout << "         ****          / _" << char(92) << " (  _ " << char(92) << " / __)        ****" << endl;
    cout << "         ****         /    " << char(92) << " ) _ (( (__         ****" << endl;
    cout << "         ****         " << char(92) << "_/" << char(92) << "_/(____/ " << char(92) << "___)        ****" << endl;
    cout << "         ****          ____  _  _  ____         ****" << endl;
    cout << "         ****         (  _ " << char(92) << "/ )( " << char(92) << "/ ___)        ****" << endl;
    cout << "         ****          ) _ () " << char(92) << "/ (" << char(92) << "___ " << char(92) << "        ****" << endl;
    cout << "        *****         (____/" << char(92) << "____/(____/        *****" << endl;
    cout << "        ******                                 ******" << endl;
    cout << "        *********************************************" << endl;
    cout << "        *********************************************" << endl;
    cout << "        *********************************************" << endl;
    cout << "        *****       **********************       ****" << endl;
    cout << "        ****         ********************         ***" << endl;
    cout << "        ****         ********************         ***" << endl;
    cout << "        *****       **********************       ****" << endl;
    cout << "        *********************************************" << endl;
    cout << "        *********************************************" << endl;
    cout << "            ********                     ********" << endl;
    cout << "            ********                     ********" << endl;
    cout << "            ********                     ********" << endl;
    cout << "               ****                       **** " << endl;



    char ch;
    do {
        cout << "\n***********************************************************************" << endl;
        cout << "**            WELCOME TO ABC BUS EXPRESS ONLINE TICKETING            **" << endl;
        cout << "***********************************************************************" << endl;
        cout << "\t\t[1] Book Ticket" << endl;
        cout << "\t\t[2] Show Bus Schedule" << endl;
        cout << "\t\t[3] Show Report" << endl;
        cout << "\t\t[4] Exit" << endl;
        cout << "\t\t[5] E-wallet Registration" << endl;
        cout << "\nEnter your Choice :: ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case '1':
            book_ticket(); break;
        case '2':
            menu(); break;
        case '3':
            report(); break;
        case '4':
            exit(0); break;
        case '5':
            e_accountcreate(); break;
        default:
            cout << "Invalid Choice!" << endl;
            cout << "Please enter ONLY 1, 2, 3 or 4 !" << endl;
        }
    } while (ch != '4');
}

void menu() {
    cout << "***********************************************************************\n";
    cout << "\nFrom KUALA LUMPUR to JOHOR BAHRU" << endl;
    cout << "Day & Date" << right << setw(20) << "Departure Time" << right << setw(15) << "Bus Type" << right << setw(25) << "Price Per Pax (RM)" << endl;
    cout << "Monday, 25" << right << setw(20) << "0800" << right << setw(15) << "Standard" << right << setw(20) << "40" << endl;
    cout << "January 2021" << right << setw(18) << "1400" << right << setw(15) << "Premium" << right << setw(20) << "70" << endl;
    cout << "\nThursday, 28" << right << setw(18) << "1100" << right << setw(15) << "Premium" << right << setw(20) << "70" << endl;
    cout << "January 2021" << right << setw(18) << "1600" << right << setw(15) << "Standard" << right << setw(20) << "40" << endl;

    cout << "\nFrom KUALA LUMPUR to PENANG" << endl;
    cout << "Day & Date" << right << setw(20) << "Departure Time" << right << setw(15) << "Bus Type" << right << setw(25) << "Price Per Pax (RM)" << endl;
    cout << "Tuesday, 26" << right << setw(19) << "0900" << right << setw(15) << "Standard" << right << setw(20) << "50" << endl;
    cout << "January 2021" << right << setw(18) << "1800" << right << setw(15) << "Premium" << right << setw(20) << "95" << endl;
    cout << "\nFriday, 29" << right << setw(20) << "1500" << right << setw(15) << "Premium" << right << setw(20) << "100" << endl;
    cout << "January 2021" << endl;
    cout << "\n***********************************************************************\n\n";
}

void book_ticket()
{
    char dest;
    //check if all the day has been booked
    if (monday_booked == false || tuesday_booked == false || thursday_booked == false || friday_booked == false) {
        do {
            cout << "Enter your Destination :: " << endl;
            cout << "[1] Johor Bahru" << endl;
            cout << "[2] Penang" << endl;
            cout << "[3] Return to Main Page" << endl;
            cout << "[4] End Order and Print Invoice" << endl;
            cout << "Choose your option : ";
            cin >> dest;
            switch (dest)
            {
            case '1': datebusJB(dest); break;
            case '2': datebusPP(dest); break;
            case '3': system("cls"); main(); break;
            case '4': invoice(); break;
            default:
                cout << "Invalid option!\n";
                cout << "Please enter ONLY 1, 2 or 3!\n\n";
                break;
            }
        } while (dest != '3');
    }
    else {
        cout << "=========================ALERT============================";
        cout << "\n All the has been booked, thanks for booking with us :).\n";
        cout << "==========================================================\n";
        cout << "Press Enter to continue..." << endl;
        cin.ignore(10, '\n');
        cin.get();
        system("cls");
        main();
    }

}

void datebusJB(char dest)
{
    char date, time;
    do {
        cout << "\nDay & Date List" << endl;
        cout << "\n[1] Monday, 25 January 2021" << endl;
        cout << "[2] Thursday, 28 January 2021" << endl;
        cout << "[3] Back" << endl;
        cout << "[0] Return to Main Page" << endl;
        cout << "Choose your option: ";
        cin >> date;
        switch (date)
        {
        case '1':
            do {
                cout << "\nTime available and Bus type" << endl;
                cout << "\n[1] 0800 - Standard" << endl;
                cout << "[2] 1400  - Premium" << endl;
                cout << "[3] Return to Main Page" << endl;
                cout << "Choose your option: ";
                cin >> time;
                switch (time)
                {
                case '1':
                case '2':
                    if (monday_booked != true) {
                        do {
                            cout << "Number of ticket: ";
                            cin >> qty;
                        } while (qty <= 0);
                        monday_booked = true;
                        calculate(dest, date, time, qty);
                    }
                    else {
                        system("cls");
                        cout << "=============================ALERT================================";
                        cout << "\nThe current date has been booked, please book on a different date.\n";
                        cout << "==================================================================\n";
                        book_ticket();
                    }

                case '3': system("cls"); main(); break;
                default:
                    cout << "Wrong Choice!\n";
                    cout << "Please enter ONLY 1, 2 or 3!\n\n";
                }
            } while (time != '3'); break;
        case '2':
            do {
                cout << "\nTime available and Bus type" << endl;
                cout << "\n[1] 1100 - Premium" << endl;
                cout << "[2] 1600  - Standard" << endl;
                cout << "[3] Return to Main Page" << endl;
                cout << "Choose your option: ";
                cin >> time;
                switch (time)
                {
                case '1':
                case '2':
                    if (thursday_booked != true) {
                        do {
                            cout << "Number of ticket: ";
                            cin >> qty;
                        } while (qty <= 0);
                        thursday_booked = true;
                        calculate(dest, date, time, qty);
                    }
                    else {
                        system("cls");
                        cout << "=============================ALERT================================";
                        cout << "\nThe current date has been booked, please book on a different date.\n";
                        cout << "==================================================================\n";
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore(10, '\n');
                        cin.get();
                        system("cls");
                        book_ticket();
                    }

                case 3: system("cls"); main(); break;
                default:
                    cout << "Wrong Choice!\n";
                    cout << "Please enter ONLY 1, 2 or 3!\n\n";
                }
            } while (time != '3'); break;
        case '3': system("cls"); book_ticket(); break;
        case '0': system("cls"); main(); break;
        default:
            cout << "Wrong Choice!\n";
            cout << "Please enter ONLY 1, 2, 3 or 0!\n\n";
        }
    } while (date != '3');
}

void datebusPP(char dest)
{
    char date, time;
    do {
        cout << "\nDay & Date List" << endl;
        cout << "\n[1] Tuesday, 26 January 2021" << endl;
        cout << "[2] Friday, 29 January 2021" << endl;
        cout << "[3] Back" << endl;
        cout << "[0] Return to Main Page" << endl;
        cout << "Choose your option: ";
        cin >> date;
        switch (date)
        {
        case '1':
            do {
                cout << "\nTime available and Bus type" << endl;
                cout << "\n[1] 0900 - Standard" << endl;
                cout << "[2] 1800  - Premium" << endl;
                cout << "[3] Return to Main Page" << endl;
                cout << "Choose your option: ";
                cin >> time;
                switch (time)
                {
                case '1':
                case '2':
                    if (tuesday_booked != true) {
                        do {
                            cout << "Number of ticket: ";
                            cin >> qty;
                        } while (qty <= 0);
                        tuesday_booked = true;
                        calculate(dest, date, time, qty);
                    }
                    else {
                        system("cls");
                        cout << "=============================ALERT================================";
                        cout << "\nThe current date has been booked, please book on a different date.\n";
                        cout << "==================================================================\n";
                        book_ticket();
                    }
                case '3': system("cls"); main(); break;
                default:
                    cout << "Wrong Choice!\n";
                    cout << "Please enter ONLY 1, 2 or 3!\n\n";
                }
            } while (time != '3');
        case '2':
            do {
                cout << "\nTime available and Bus type" << endl;
                cout << "\n[1] 1500 - Premium" << endl;
                cout << "[2] Return to Main Page" << endl;
                cout << "Choose your option: ";
                cin >> time;
                switch (time)
                {
                case '1':
                    if (friday_booked != true) {
                        do {
                            cout << "Number of ticket: ";
                            cin >> qty;
                        } while (qty <= 0);
                        friday_booked = true;
                        calculate(dest, date, time, qty);
                    }
                    else {
                        system("cls");
                        cout << "=============================ALERT================================";
                        cout << "\nThe current date has been booked, please book on a different date.\n";
                        cout << "==================================================================\n";
                        cout << "Press Enter to continue..." << endl;
                        cin.ignore(10, '\n');
                        cin.get();
                        book_ticket();
                    }
                case '2': system("cls");  main(); break;
                default:
                    cout << "Wrong Choice!\n";
                    cout << "Please enter ONLY 1 or 2!\n\n";
                }
            } while (time != '3');
        case '3': system("cls"); book_ticket(); break;
        case '0': system("cls"); main(); break;
        default:
            cout << "Wrong Choice!\n\n";
        }
    } while (date != '3');
}

void calculate(char dest, char date, char time, int qty)
{
    //calculate pricings and stuff
    //variable initialization
    double sum = 0;
    cout << "Enter the Age of The " << qty << " Passenger(s) :: ";
    for (int i = 1; i <= qty; i++) {
        cout << "\nAge for Passenger " << i << " :: ";
        cin >> age[i];
        while (age[i] <= 0) {
            cout << "Please enter valid age!" << endl;
            cout << "\nAge for Passenger " << i << " :: ";
            cin >> age[i];
        }
    }
    cout << "\n^^^^^^^^^^^^^^^^^^^^^^THE RATE FOR BUS^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    for (int i = 1; i <= qty; i++) {
        if (age[i] >= 5 && age[i] <= 15) {
            cout << "Children between the ages of 5-15 have a 20% discount." << endl;
            if (dest == '1') {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = 0.8 * JB_S; break;
                    case '2': amount[i] = 0.8 * JB_P; break;
                    default:
                        break;
                    }
                    break;
                case '2':
                    switch (time)
                    {
                    case '1': amount[i] = 0.8 * JB_P; break;
                    case '2': amount[i] = 0.8 * JB_S; break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
            else {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = 0.8 * PP_S2; break;
                    case '2': amount[i] = 0.8 * PP_P2; break;
                    default:
                        break;
                    }
                    break;
                case '2': amount[i] = 0.8 * PP_P5; break;
                default:
                    break;
                }
            }
        }
        else if (age[i] < 5 && age[i] > 0) {
            cout << "Children between the ages of 1-4 have a 50% discount." << endl;
            if (dest == '1') {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = 0.5 * JB_S; break;
                    case '2': amount[i] = 0.5 * JB_P; break;
                    default:
                        break;
                    }
                    break;
                case '2':
                    switch (time)
                    {
                    case '1': amount[i] = 0.5 * JB_P; break;
                    case '2': amount[i] = 0.5 * JB_S; break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
            else {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = 0.5 * PP_S2; break;
                    case '2': amount[i] = 0.5 * PP_P2; break;
                    default:
                        break;
                    }
                    break;
                case '2': amount[i] = 0.5 * PP_P5; break;
                default:
                    break;
                }
            }
        }
        else {
            cout << "Age above 15, the price is fix." << endl;
            if (dest == '1') {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = JB_S; break;
                    case '2': amount[i] = JB_P; break;
                    default:
                        break;
                    }
                    break;
                case '2':
                    switch (time)
                    {
                    case '1': amount[i] = JB_P; break;
                    case '2': amount[i] = JB_S; break;
                    default:
                        break;
                    }
                default:
                    break;
                }
            }
            else {
                switch (date)
                {
                case '1':
                    switch (time)
                    {
                    case '1': amount[i] = PP_S2; break;
                    case '2': amount[i] = PP_P2; break;
                    default:
                        break;
                    }
                    break;
                case '2': amount[i] = PP_P5; break;
                default:
                    break;
                }
            }
        }
        sum += amount[i];
    }
    cout << "\n^^^^^^^^^^^^^^^^^^^^^^TOTAL PRICE^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "Total Price of Ticket is :: RM " << fixed << setprecision(2) << sum << endl;

    char back, leave;
pay:
    cout << "\n[1] Pay Now" << endl;
    cout << "[0] Return to Main Page" << endl;
    cin >> back;
    if (back == '1')
        payment(dest, date, time, qty, sum);
    else if (back == '0') {
        cout << "\nYou have pending order. Are you sure you want to leave page now?" << endl;
    pending:
        cout << "[1] Stay on Page" << endl;
        cout << "[0] Leave Page" << endl;
        cin >> leave;
        if (leave == '1')
            goto pay;
        else if (leave == '0') {
            system("cls");
            main();
        }
        else {
            cout << "\nInvalid Input!" << endl;
            cout << "Please enter ONLY 1 or 0!\n\n";
            goto pending;
        }
    }
    else {
        cout << "\nInvalid Input!" << endl;
        cout << "Please enter ONLY 1 or 0!\n\n";
        goto pay;
    }
    system("pause>0");
}

void payment(char dest, char date, char time, int qty, double sum)
{
    //variable declaration and initalization
    double payAmount, balance;
    int cardNum, ewallet_accept = 0, i = 0, find = 0;
    char paymentType, ewallet, bankType;
    string psw, id, idArray[100], passwordArray[100];

    //load password and id file
    ifstream idFile("id.txt");
    ifstream passFile("password.txt");

payment:
    cout << "\nPlease select your payment type:" << endl;
    cout << "[1] E-Wallet" << endl;
    cout << "[2] Cash" << endl;
    cout << "[3] Credit Card" << endl;
    cout << "[4] Return To Main Page" << endl;
    cout << "Choose your Payment Type :: ";
    cin >> paymentType;

    switch (paymentType)
    {
    case '1':
    ewallet:
        cout << "\n^^^^^^^^^^^^^^^^^^^^^^^E-Wallet Support^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "[1] Grab Pay" << endl;
        cout << "[2] Touch 'n Go" << endl;
        cout << "[3] Boost" << endl;
        cout << "\nChoose your E-Wallet :: ";
        cin >> ewallet;
        switch (ewallet)
        {
        case '1':
        case '2':
        case '3':
            system("cls");
            //id and password verifications
            do {
                //user input password and id
                cout << "Enter your e-wallet ID ('0' to return): ";
                cin >> id;
                cout << "Enter your e-wallet Password: ";
                cin >> psw;

                //load the ids and passwords into arrays.
                for (int n = 0; n < 100; n++) {
                    idFile >> idArray[n];
                    passFile >> passwordArray[n];
                    //check if the id exists
                    if (id == idArray[n]) {
                        cout << "ALERT: ID confirmed" << endl;
                        //check if the password is correct
                        if (psw == passwordArray[n]) {
                            cout << "ALERT: Password Confirmed" << endl;
                            ewallet_accept = 1;
                            break;
                        }
                        else {
                            cout << "ALERT: Password Incorrect" << endl;
                            break;
                        }
                    }
                    //Cancel payment
                    else if (id == "0") {
                        system("cls");
                        goto ewallet;
                    }
                    //display message when id is not found
                    else if (n == 99) {
                        cout << "ID not found" << endl;
                    }
                }

            } while (ewallet_accept != 1);
            balance = 0;
            payAmount = sum;
            cout << "Payment Successful" << endl;

            //update sales and payment details
            sumTotal += sum;
            sumPay += payAmount;
            amountCharge += sum;
            amountPaid += sum;
            qtyBTotal += qty;
            break;
        case '4':
            e_accountcreate(); break;
        default:
            cout << "Please enter ONLY 1, 2 or 3!\n\n";
            goto ewallet;
        }
        break;
    case '2':
        cout << "Pay Amount: RM ";
        cin >> payAmount;
        while (payAmount < sum) {
            cout << "\nPayment Status Not Available! Please Try Again!\n";
            cout << "Pay Amount: RM ";
            cin >> payAmount;
        }
        balance = payAmount - sum;
        cout << "Balance: RM " << fixed << setprecision(2) << balance;

        //update sales and payment details
        sumTotal += sum;
        sumPay += payAmount;
        amountCharge += sum;
        amountPaid += payAmount;
        qtyBTotal += qty;
        break;
    case '3':
    bank:
        cout << "\n\n^^^^^^^^^^^^^^^^^^^^^^^Bank Support^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        cout << "[1] Maybank" << endl;
        cout << "[2] Public Bank" << endl;
        cout << "[3] CIMB Bank" << endl;
        cout << "[4] RHB Bank" << endl;
        cout << "\nEnter your Bank Type ::";
        cin >> bankType;
        switch (bankType)
        {
        case '1':
        case '2':
        case '3':
        case '4':
            cout << "Enter your card number (only numeric value): ";
            cin >> cardNum;
            payAmount = sum;
            balance = 0;
            cout << "Payment Successful" << endl;
            amountCharge += sum;
            amountPaid += sum;
            qtyBTotal += qty;
            sumTotal += sum;
            sumPay += payAmount;
            receipt();
            break;
        default:
            cout << "Please enter ONLY 1, 2, 3 or 4!\n\n";
            goto bank;
        }
    default:
        cout << "Please enter ONLY 1, 2, 3 or 4!\n\n";
        goto payment;
    }

    //Metrics for sales report statistics
    if (dest == '1') {
        jbTotal += sum;
        if (date == '1') {
            monTotal += sum;
            if (time == '1')
                standardTotal += sum;
            else
                premiumTotal += sum;
        }
        else {
            thursTotal += sum;
            if (time == '1')
                premiumTotal += sum;
            else
                standardTotal += sum;
        }
    }
    else {
        ppTotal += sum;
        if (date == '1') {
            tueTotal += sum;
            if (time == '1') {
                standardTotal += sum;
            }
            else {
                premiumTotal += sum;
            }
        }
        else
        {
            friTotal += sum;
            if (time == '1')
                premiumTotal += sum;
        }
    }
    receipt();
}

int e_accountcreate() {
    //display and input
    string password, rpassword, id;
    cout << "=================================" << endl;
    cout << "  E-wallet Account Registration" << endl;
    cout << "=================================" << endl;
    cout << "Please enter your new id    : " << endl;
    cin >> id;
    cout << "Please create a new password: " << endl;
    cin >> password;

    //repeat password 
    cout << "please repeat your password : " << endl;
    do {
        cin >> rpassword;
        if (password != rpassword) {
            cout << "Password do not match, please repeat your password: ";
        }
    } while (password != rpassword);

    //write password and id to files
    ofstream textfile;
    textfile.open("id.txt", ios::app);
    textfile << id << " ";
    textfile.close();
    textfile.open("password.txt", ios::app);
    textfile << password << " ";
    textfile.close();

    //account create successful
    cout << "Account successfully created!\n";
    cout << "Press Enter to continue..." << endl;
    cin.ignore(10, '\n');
    cin.get();
    system("cls");
    return 0;
}

void receipt()
{
    char continue_order;
    do {
        cout << "\nContinue Ordering? (Y/N) : ";
        cin >> continue_order;
        if (toupper(continue_order) == 'Y') {
            system("cls");
            cout << "================== (New Order) ==================\n\n";
            book_ticket();
        }
        else if (toupper(continue_order) == 'N') {
            invoice();
        }
        else {
            cout << "Please ONLY type Y/N!";
        }
    } while (toupper(continue_order) != 'Y' && toupper(continue_order) != 'N');
}

void invoice() {
    cout << "\n\n----------------------------------------------------\n";
    cout << "|             ABC BUS EXPRESS INVOICE              |\n";
    cout << "|--------------------------------------------------|\n";
    cout << " Order No.\t\t: " << order << "\n";
    cout << fixed << setprecision(2);
    cout << " Total\t\t\t: RM " << sumTotal << "\n";
    cout << " Pay\t\t\t: RM " << sumPay << "\n";
    cout << " Change\t\t\t: RM " << sumPay - sumTotal << "\n";
    cout << "|--------------------------------------------------|\n";
    cout << "Thank You, Have a nice day.\n\n";

    //save order to array if the customer has made an order
    if (qtyBTotal > 0) {
        qtylist[order] = qtyBTotal;
        paymentlist[order] = sumTotal;
        order++;
    }

    //reset the booking status for the next customer
    monday_booked = false;
    tuesday_booked = false;
    thursday_booked = false;
    friday_booked = false;
    sumTotal = 0;
    sumPay = 0;
    qtyCTotal += qtyBTotal;
    qtyBTotal = 0;

    system("pause");//hold the page
    system("cls");
    main();
}
void report()
{
    int ch;
    do {
        cout << "^^^^^^^^^^^^^^^^^Report Type^^^^^^^^^^^^^^^^^\n";
        cout << "[1] Daily Sales Report\n";
        cout << "[2] End-of-Day Report\n";
        cout << "[3] Return to Main Page\n";
        cout << "Choose your option :: ";
        cin >> ch;
        switch (ch)
        {
        case 1: dailysales(); break;
        case 2: endOfDay(); break;
        case 3: system("cls"); main(); break;

        default:
            cout << "Wrong Input! Please Try Again!" << endl;
            break;
        }
    } while (ch != 3);
}

void dailysales()
{
    cout << "\n\n--------------------------------------------\n";
    cout << "|             ABC BUS EXPRESS              |\n";
    cout << "|            DAILY SALES REPORT            |\n";
    cout << "|------------------------------------------|\n";
    cout << "| Order.no  |     Qty       |  Sales       |\n";
    cout << "|------------------------------------------|\n";
    //for every order made, qty and sales will be displayed.
    for (int i = 1; qtylist[i] != 0; i++) {
        if (qtylist[i] != 0) {
            cout << "|" << setw(11) << left << i << "|" << setw(15) << left << qtylist[i] << "|"
                << setw(14) << paymentlist[i] << "|" << endl;
            cout << "|------------------------------------------|" << endl;
        }
    }
    cout << setw(32) << "Total of Quantity Tickets Sold: " << setw(15) << right << qtyCTotal << endl;
    cout << setw(32) << "Total Amounts Paid            : " << setw(15) << right << premiumTotal + standardTotal << endl;
    system("pause");
    system("cls");
    main();
}

void endOfDay()
{
    char newday;
    cout << "\n\n--------------------------------------------------------\n";
    cout << "|                   ABC BUS EXPRESS                    |\n";
    cout << "|                  END-OF-DAY REPORT                   |\n";
    cout << "|------------------------------------------------------|\n";
    cout << " Total Customer\t\t\t\t:: " << setw(10) << order << "\n";
    cout << fixed << setprecision(2);
    cout << "|------------------------------------------------------|\n";
    cout << "\n ****Ticket Sales****\n";
    cout << " By Destination:- \n";
    cout << " From Kuala Lumpur To Johor Bahru \t:: RM " << setw(7) << jbTotal << endl;
    cout << " From Kuala Lumpur To Penang \t\t:: RM " << setw(7) << ppTotal << endl;
    cout << "\n\n";
    cout << "\n By Dates of Trips Bought:- \n";
    cout << " Monday, 25 January 2021 \t\t:: RM " << setw(7) << monTotal << endl;
    cout << " Thursday, 28 January 2021 \t\t:: RM " << setw(7) << thursTotal << endl;
    cout << " Tuesday, 26 January 2021 \t\t:: RM " << setw(7) << tueTotal << endl;
    cout << " Friday, 29 January 2021 \t\t:: RM " << setw(7) << friTotal << endl;
    cout << "\n\n";
    cout << " By Bus Type Chosen: \n";
    cout << " Standard \t\t\t\t:: RM " << setw(7) << standardTotal << endl;
    cout << " Premium \t\t\t\t:: RM " << setw(7) << premiumTotal << endl;
    cout << "\n|------------------------------------------------------|\n\n";

    //Reset For The Day
    do {
        cout << "\n\nStart New Day? (Y/N):  ";
        cin >> newday;
    } while (isalpha(newday) == 0);

    if (toupper(newday) == 'Y') {
        for (int i = 0; i < 100; i++) {
            qtylist[i] = 0;
            paymentlist[i] = 0;
        }
    }
    else {
        cout << "\n\nNew Day will not be initiated" << endl;
    }
    system("pause");
    system("cls");
    main();
}
