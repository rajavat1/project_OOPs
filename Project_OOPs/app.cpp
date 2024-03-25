#include "header.h"
using namespace std;

// utility functions start
void removeSpaces(string &str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}
int randome()
{
    srand(time(0));
    int ren_price = 999 + rand() % 9999;
    return ren_price;
}
string todaydate()
{
    time_t now = time(0);

    // Convert the current time to the broken-down time format
    struct tm *timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y", timeinfo);

    return buffer;
}
int randome_price()
{
    srand(time(0));
    int ren_price = 15 + rand() % 99;
    return ren_price;
}
struct Address
{
    string citizenship;
    string line1;
    string line2;
    string city;
    string state;
    string pinCode;
};
string datetime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string datetime = to_string(1900 + ltm->tm_year) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(ltm->tm_mday) + " " +
                      to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
    return datetime;
}
// utility functions end
// create account class
class create_Account
{
public:
    int rendome_AC()
    {
        srand(time(0));
        int ren_acc = 1000 + rand() % 9000;
        return ren_acc;
    }
    int rendome_Customer_no()
    {
        srand(time(0));
        int ren_acc = 1000 + rand() % 9000;
        return ren_acc;
    }
    string ifsc_code()
    {
        string ifsc[] = {"AUBU9578", "AUBU9579", "AUBU9580", "AUBU9581", "AUBU9582"};
        int size = sizeof(ifsc) / sizeof(ifsc[0]);
        srand(time(0));
        int idex = (rand() % size);
        string rendifsc = ifsc[idex];
        return rendifsc;
    }
    void create_Ac()
    {
        // file pointer
        fstream fout;
        Address address;

        // opens an existing csv file or creates a new file.
        fout.open("Account_details.csv", ios::out | ios::app);

        cout << "Enter the details " << endl;

        int AC_no, C_no;
        string Ac_open_date, AC_holder_Name, dob, contect_no, mail_ID, Documents, document_no, Occupation, Nominee_Name, Nominee_DOB, Nominee_relation, Account_type, first_time_deposite, ifsc_code, c;

        // Read the inputs
        Ac_open_date = todaydate();
        AC_no = rendome_AC();
        C_no = rendome_Customer_no();
        ifsc_code = this->ifsc_code();
        cout << "Enter Account Holder Name : ";
        getline(cin, AC_holder_Name);
        cout << "Enter Date of birth (dd/mm/yyyy) : ";
        getline(cin, dob);
        cout << "Enter Contect Number : ";
        getline(cin, contect_no);
        cout << "Enter e-Mail ID : ";
        getline(cin, mail_ID);

        cout << "Enter Detail Verification Document : \n"
             << "\t1. Pan Card" << endl
             << "\t2. Passport" << endl
             << "\t3. Driving License" << endl
             << "\t4. Voter's ID" << endl
             << "\t5. Ration Card" << endl
             << "\t6. Aadhaar card" << endl
             << "Enter Your Choice : ";
        getline(cin, c);
        do
        {
            if (c == "1")
            {
                Documents = "Pan Card";
                break;
            }
            else if (c == "2")
            {
                Documents = "Passport";
                break;
            }
            else if (c == "3")
            {
                Documents = "Driving License";
                break;
            }
            else if (c == "4")
            {
                Documents = "Voter's ID";
                break;
            }
            else if (c == "5")
            {
                Documents = "Ration Card";
                break;
            }
            else if (c == "6")
            {
                Documents = "Aadhaar card";
                break;
            }
            else
            {
                cout << "Enter Rigth Choice" << endl;
            }

        } while (true);

        cout << "Enter Document Number : ";
        getline(cin, document_no);

        cout << "Enter Citizenship : ";
        getline(cin, address.citizenship);

        cout << "Enter Full address:- " << endl;
        cout << "\t Line 1 : ";
        getline(cin, address.line1);
        cout << "\t Line 2 : ";
        getline(cin, address.line2);
        cout << "\t City : ";
        getline(cin, address.city);
        cout << "\t State : ";
        getline(cin, address.state);
        cout << "\t Pin code : ";
        getline(cin, address.pinCode);

        cout << "write Occupation :";
        getline(cin, Occupation);

        cout << "Nominee Name : ";
        getline(cin, Nominee_Name);

        cout << "Nominee Date of birth : ";
        getline(cin, Nominee_DOB);

        cout << "Nominee relation : ";
        getline(cin, Nominee_relation);

        cout << "Enter Type Of Account : \n";
        cout << "\t1. Saving Account" << endl
             << "\t2. Current Account" << endl
             << "Enter Your Choice : ";
        getline(cin, c);
        do
        {
            if (c == "1")
            {
                Account_type = "Saving Account";
                break;
            }
            else if (c == "2")
            {
                Account_type = "Current Account";
                break;
            }
            else
            {
                cout << "Enter Rigth Choice" << endl;
            }

        } while (true);
        cout << "Congratulations!! You are only one step short" << endl;
        if (c == "1")
        {
            cout << "First Time depsite Amount is ₹500 ";
            first_time_deposite = "500";
        }
        else
        {

            cout << "First Time depsite Amount is ₹2000 ";
            first_time_deposite = "2000";
        }

        cout << "Do You Want To continue (y/n) : ";
        getline(cin, c);
        for (char &c : c)
        {
            c = tolower(c);
        }
        for (char &c : AC_holder_Name)
        {
            c = toupper(c);
        }
        for (char &c : document_no)
        {
            c = toupper(c);
        }
        for (char &c : Nominee_Name)
        {
            c = toupper(c);
        }
        for (char &c : Nominee_relation)
        {
            c = toupper(c);
        }
        // Insert the data to file
        if (c == "y")
        {
            fout
                << Ac_open_date << ", "
                << "95874682" << AC_no << ", "
                << "3156" << C_no << ", "
                << ifsc_code << ", "
                << AC_holder_Name << ", "
                << dob << ", "
                << contect_no << ", "
                << mail_ID << ", "
                << Documents << ", "
                << document_no << ", "
                << address.citizenship << ", "
                << address.line1 << " " << address.line2 << " " << address.city << " " << address.state << " " << address.pinCode << " "
                << ", "
                << Occupation << ", "
                << Nominee_Name << ", "
                << Nominee_DOB << ", "
                << Nominee_relation << ", "
                << Account_type << ", "
                << first_time_deposite << "\n ";
            fout.close();
            cout << "Your Account open Successfully \n";
            cout << "Account Number : 95874682" << AC_no;
            cout << "\nCustomer Number : 3156" << C_no;
            cout << "\nIFSC code : " << ifsc_code;
            cout << "\nTotal Balance : " << first_time_deposite << endl;
        }
        else
        {
            cout << "\nYour Account is not open Successfully \n";
        }
    }
};

class view_data
{
public:
    void search_account_data()
    {

        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Account_details.csv", ios::in);

        int count = 0;
        string input_value, document_no, AC_no, C_no, dob_input, dob;
        cout << "Enter the Account Number,Customer Number or Document Number to display details: ";

        getline(cin, input_value);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        removeSpaces(input_value);
        for (char &c : input_value)
        {
            c = tolower(c);
        }
        for (char &c : dob_input)
        {
            c = tolower(c);
        }

        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            removeSpaces(row[1]); // account no.
            removeSpaces(row[2]); // customer no.
            removeSpaces(row[5]); // DOB
            removeSpaces(row[9]); // document no.
            for (char &c : row[9])
            {
                c = tolower(c);
            }
            AC_no = row[1];
            C_no = row[2];
            dob = row[5];
            document_no = row[9];
            if ((AC_no == input_value && dob == dob_input) || (C_no == input_value && dob == dob_input) || (document_no == input_value && dob == dob_input))
            {
                for (char &c : row[9])
                {
                    c = toupper(c);
                }
                // Print the found data
                cout << endl
                     << endl
                     << "Details of Account No. #" << row[1] << " :" << endl
                     << " | "
                     << "CUSTOMER NO : " << row[2] << endl
                     << " | "
                     << "IFSC CODE : " << row[3] << endl
                     << " | "
                     << "A/C HOLDER NAME: " << row[4] << endl
                     << " | "
                     << "A/C HOLDER DOB : " << row[5] << endl
                     << " | "
                     << "CONTECT NO : " << row[6] << endl
                     << " | "
                     << "MAIL_ID  : " << row[7] << endl
                     << " | "
                     << "DOCUMENT : " << row[8] << endl
                     << " | "
                     << "DOCUMENT NO: " << row[9] << endl
                     << " | "
                     << "Citizenship : " << row[10] << endl
                     << " | "
                     << "ADDRESS : " << row[11] << endl
                     << " | "
                     << "Occupation : " << row[12] << endl
                     << " | "
                     << "Nominee Name : " << row[13] << endl
                     << " | "
                     << "Nominee DOB : " << row[14] << endl
                     << " | "
                     << "Nominee Relation : " << row[15] << endl
                     << " | "
                     << "Account type : " << row[16] << endl
                     << " | "
                     << "TOTAL BALANCE : " << row[17] << endl
                     << endl;
                count = 1;
            }
        }
        // Close the file
        fin.close();

        if (count == 0)
            cout << "Record not Found\n"
                 << "Please Enter Right Details\n";
    }
};

class edit
{
public:
    void update_AC_record()
    {
        // File pointers
        fstream fin, fout;
        Address address;
        // Open an existing record
        fin.open("Account_details.csv", ios::in);

        // Create a new file to store updated data
        fout.open("Account_details_new.csv", ios::out);

        int count = 0, i, index;
        vector<string> row;
        string property, input_value, document_no, new_document_no, AC_no, C_no, dob_input, dob, line, word, newdetails, c;
        cout << "Enter the Account Number, Customer Number or Document Number to Update details: ";
        getline(cin, input_value);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        removeSpaces(input_value);
        for (char &c : input_value)
        {
            c = tolower(c);
        }
        for (char &c : dob_input)
        {
            c = tolower(c);
        }

        // Get the subject to be updated
        cout << "[1] NAME" << endl
             << "[2] DOB" << endl
             << "[3] Contact Number" << endl
             << "[4] Mail ID" << endl
             << "[5] DOCUMENT" << endl
             << "[6] Address" << endl
             << "Enter the Madicine Property : ";
        getline(cin, property);

        // Determine the index of the subject
        if (property == "1")
        {
            index = 4;
            // Get the new marks
            cout << "Enter New NAME : ";
            cin >> newdetails;
        }
        else if (property == "2")
        {
            index = 5;
            cout << "Enter Date of birth : ";
            cin >> newdetails;
        }
        else if (property == "3")
        {
            index = 6;
            cout << "Enter New Contect Number : ";
            cin >> newdetails;
        }
        else if (property == "4")
        {
            index = 7;
            cout << "Enter New Mail ID : ";
            cin >> newdetails;
        }
        else if (property == "5")
        {
            cout << "Enter Detail Verification Document : \n"
                 << "\t1. Pan Card" << endl
                 << "\t2. Passport" << endl
                 << "\t3. Driving License" << endl
                 << "\t4. Voter's ID" << endl
                 << "\t5. Ration Card" << endl
                 << "\t6. Aadhaar card" << endl
                 << "Enter Your Choice : ";
            getline(cin, c);
            do
            {
                if (c == "1")
                {
                    newdetails = "Pan Card";
                    break;
                }
                else if (c == "2")
                {
                    newdetails = "Passport";
                    break;
                }
                else if (c == "3")
                {
                    newdetails = "Driving License";
                    break;
                }
                else if (c == "4")
                {
                    newdetails = "Voter's ID";
                    break;
                }
                else if (c == "5")
                {
                    newdetails = "Ration Card";
                    break;
                }
                else if (c == "6")
                {
                    newdetails = "Aadhaar card";
                    break;
                }
                else
                {
                    cout << "Enter Rigth Choice" << endl;
                }

            } while (true);
            cout << "Enter New Document Number : ";
            getline(cin, new_document_no); // index=9
            index = 8;
        }
        else if (property == "6")
        {
            index = 11;
            cout << "Enter Full address:- " << endl;
            cout << "\t Line 1 : ";
            getline(cin, address.line1);
            cout << "\t Line 2 : ";
            getline(cin, address.line2);
            cout << "\t City : ";
            getline(cin, address.city);
            cout << "\t State : ";
            getline(cin, address.state);
            cout << "\t Pin code : ";
            getline(cin, address.pinCode);

            newdetails = address.line1 + " " + address.line2 + " " + address.city + " " + address.state + " " + address.pinCode;
        }
        else
        {
            cout << "Wrong choice. Enter again\n";
            update_AC_record();
            return;
        }
        for (char &c : newdetails)
        {
            c = toupper(c);
        }
        for (char &c : new_document_no)
        {
            c = toupper(c);
        }
        // Traverse the file
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            removeSpaces(row[1]); // account no.
            removeSpaces(row[2]); // customer no.
            removeSpaces(row[5]); // DOB
            removeSpaces(row[9]); // document no.
            for (char &c : row[9])
            {
                c = tolower(c);
            }
            AC_no = row[1];
            C_no = row[2];
            dob = row[5];
            document_no = row[9];

            if ((AC_no == input_value && dob == dob_input) || (C_no == input_value && dob == dob_input) || (document_no == input_value && dob == dob_input))
            {
                count = 1;
                row[index] = newdetails;
                if (property == "5")
                {
                    row[9] = new_document_no;
                }

                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write updated row to new file
                }
                fout << row.back() << "\n";
            }
            else
            {
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write existing row to new file
                }
                fout << row.back() << "\n";
            }
        }
        fin.close();
        fout.close();

        // Remove the existing file
        if (remove("Account_details.csv") != 0)
        {
            perror("Error deleting file");
        }

        // Rename the updated file
        if (rename("Account_details_new.csv", "Account_details.csv") != 0)
        {
            perror("Error renaming file");
        }

        if (count == 0)
            cout << "\nRecord not found\n";
        else
            cout << "\nDetail Updated Successful\n";
    }
};

class transact
{
public:
    void withdrawal()
    {
        fstream fin_acc, fin_trans, fout_acc, fout_trans;

        fin_acc.open("Account_details.csv", ios::in);
        fout_acc.open("Account_details_new.csv", ios::out);
        fin_trans.open("Transact_details.csv", ios::in);
        fout_trans.open("Transact_details.csv", ios::app);

        string AC_no_input, dob_input, contect_no_input, withdrawl_amount;
        int total_before, total_after;

        cout << "Enter the Account Number : ";
        getline(cin, AC_no_input);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        cout << "Enter Contect Number : ";
        getline(cin, contect_no_input);
        cout << "Enter Withdrawal Amount : ";
        getline(cin, withdrawl_amount);

        int withdrawl_amount1 = stoi(withdrawl_amount);

        // Current date and time

        string line;
        bool account_updated = false, balance = false;

        // Update Account_details.csv
        while (getline(fin_acc, line))
        {
            vector<string> row;
            stringstream s(line);
            string word;
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            string AC_no = row[1];
            string dob = row[5];
            string contect_no = row[6];
            int total;
            stringstream convert(row[17]);
            convert >> total;
            total_before = total;
            removeSpaces(AC_no);
            removeSpaces(dob);
            removeSpaces(contect_no);

            if (AC_no == AC_no_input && dob == dob_input && contect_no == contect_no_input)
            {
                account_updated = true;
                if (total >= withdrawl_amount1)
                {
                    total -= withdrawl_amount1;
                    row[17] = to_string(total);
                    balance = true;
                    total_after = total;
                }
            }
            for (size_t i = 0; i < row.size(); i++)
            {
                fout_acc << row[i];
                if (i != row.size() - 1)
                    fout_acc << ",";
            }
            fout_acc << "\n";
        }

        if (!account_updated)
        {
            cout << "\nRecord not found\n";
            return;
        }
        if (!balance)
        {
            cout << "\nSufficient Balance are not available\n";
            cout << "Your Total balance is : "
                 << total_before << endl;
            return;
        }

        // Write withdrawal details to Transact_details.csv
        fout_trans << datetime() << ","
                   << AC_no_input << ","
                   << dob_input << ","
                   << contect_no_input << ","
                   << "Withdrawl"
                   << ","
                   << withdrawl_amount << ","
                   << total_after << "\n";
        fin_acc.close();
        fout_acc.close();
        fin_trans.close();
        fout_trans.close();

        if (remove("Account_details.csv") != 0)
        {
            perror("Error deleting file");
        }

        if (rename("Account_details_new.csv", "Account_details.csv") != 0)
        {
            perror("Error renaming file");
        }

        cout << "\nWithdrawal Successful\n";
        cout << "Your Total balance is : "
             << total_after << endl;
    }

    void diposite()
    {
        ifstream fin_acc, fin_trans;
        ofstream fout_acc, fout_trans;

        fin_acc.open("Account_details.csv", ios::in);
        fout_acc.open("Account_details_new.csv", ios::out);
        fin_trans.open("Transact_details.csv", ios::in);
        fout_trans.open("Transact_details.csv", ios::app);

        string AC_no_input, ifsc_input, contect_no_input, deposite_amount;
        int total_after;

        cout << "Enter the Account Number : ";
        getline(cin, AC_no_input);
        cout << "Enter IFSC Code : ";
        getline(cin, ifsc_input);

        for (char &c : ifsc_input)
        {
            c = toupper(c);
        }

        cout << "Enter Contect Number : ";
        getline(cin, contect_no_input);
        cout << "Enter Deposite Amount : ";
        getline(cin, deposite_amount);

        int deposite_amount1 = stoi(deposite_amount);

        string line;
        bool account_updated = false;

        // Update Account_details.csv
        while (getline(fin_acc, line))
        {
            vector<string> row;
            stringstream s(line);
            string word;
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            string AC_no = row[1];
            string ifsc = row[3];
            string contect_no = row[6];
            int total;
            stringstream convert(row[17]);
            convert >> total;
            removeSpaces(AC_no);
            removeSpaces(ifsc);
            removeSpaces(contect_no);

            if (AC_no == AC_no_input && ifsc == ifsc_input && contect_no == contect_no_input)
            {
                account_updated = true;
                total += deposite_amount1;
                row[17] = to_string(total);
                total_after = total;
            }
            for (size_t i = 0; i < row.size(); i++)
            {
                fout_acc << row[i];
                if (i != row.size() - 1)
                    fout_acc << ",";
            }
            fout_acc << "\n";
        }

        if (!account_updated)
        {
            cout << "\nRecord not found\n";
            return;
        }

        // Write withdrawal details to Transact_details.csv
        fout_trans << datetime() << ","
                   << AC_no_input << ","
                   << ifsc_input << ","
                   << contect_no_input << ","
                   << "Deposite"
                   << ","
                   << deposite_amount << ","
                   << total_after << "\n";
        fin_acc.close();
        fout_acc.close();
        fin_trans.close();
        fout_trans.close();

        if (remove("Account_details.csv") != 0)
        {
            perror("Error deleting file");
        }

        if (rename("Account_details_new.csv", "Account_details.csv") != 0)
        {
            perror("Error renaming file");
        }

        cout << "\nWithdrawal Successful\n";
        cout << "Your Total balance is : "
             << total_after << endl;
    }
};

class erase
{
public:
    void close_account()
    {
        ifstream fin("Account_details.csv");
        ofstream fout("Account_details_new.csv");

        if (!fin.is_open())
        {
            cerr << "Error opening input file\n";
            return;
        }

        if (!fout.is_open())
        {
            cerr << "Error opening output file\n";
            return;
        }

        int count = 0;
        string AC_no_input, dob_input, contect_no_input, line, word;

        vector<string> row;

        cout << "Enter the Account Number : ";
        getline(cin, AC_no_input);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        cout << "Enter Contact Number : ";
        getline(cin, contect_no_input);
        bool cnf = true;
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);
            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            string AC_no = row[1];
            string dob = row[5];
            string contect_no = row[6];
            removeSpaces(AC_no);
            removeSpaces(dob);
            removeSpaces(contect_no);

            if (AC_no == AC_no_input && dob == dob_input && contect_no == contect_no_input)
            {
                cout << "Account found. Are you sure you want to delete this account? (y/n): ";
                string confirmation;
                cin >> confirmation;
                count = 1;
                if (confirmation == "y" || confirmation == "Y")
                {
                    cnf = true;
                }
                else if (confirmation == "n" || confirmation == "N")
                {
                    for (size_t i = 0; i < row.size() - 1; ++i)
                    {
                        fout << row[i] << ", ";
                    }
                    fout << row.back() << "\n";
                    cnf = false;
                }
            }
            else
            {
                for (size_t i = 0; i < row.size() - 1; ++i)
                {
                    fout << row[i] << ", ";
                }
                fout << row.back() << "\n";
            }
        }

        if (count = 0)
        {
            cout << "Account not found\n";
        }
        if (cnf == true)
        {
            cout << "Account deleted\n";
        }
        else
        {
            cout << "Operation Cancle";
        }

        fin.close();
        fout.close();

        if (remove("Account_details.csv") != 0)
        {
            perror("Error deleting file");
        }

        if (rename("Account_details_new.csv", "Account_details.csv") != 0)
        {
            perror("Error renaming file");
        }
    }
};

int main()
{
    // create_Account cAC;
    // cAC.create_Ac();
    // view_data vd;
    // vd.search_account_data();
    // edit edt;
    // edt.update_AC_record();
    // transact tr;
    // tr.withdrawal();
    // tr.diposite();

    erase ers;
    ers.close_account();
    return 0;
}