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
class validation
{
public:
    // validate the Enter name is not a intiger
    bool hasInteger(const string &str)
    {
        for (char c : str)
        {
            if (!isalpha(c))
            {
                return true;
            }
        }
        return false;
    }

    // validate the enter DOB formate
    bool isValidDateOfBirthFormat(const string &dob)
    {
        // Check if the length of the input string is exactly 10 characters
        if (dob.length() != 10)
            return false;

        // Check if the positions of '/' are correct
        if (dob[2] != '/' || dob[5] != '/')
            return false;

        // Extract day, month, and year from the input string
        int day, month, year;
        stringstream ss(dob);
        char slash;
        ss >> day >> slash >> month >> slash >> year;

        // Check if the extraction was successful and values are within valid ranges
        if (ss.fail() || ss.bad())
            return false;

        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
            return false;

        // Additional checks for specific month lengths
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;

        if (month == 2)
        {
            bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if ((leapYear && day > 29) || (!leapYear && day > 28))
                return false;
        }

        // If all checks pass, return true
        return true;
    }

    // mobile number
    bool isValidMobilenumber(const string &mobile)
    {

        if (mobile.length() != 10)
        {
            return false;
        }
        for (char c : mobile)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    bool isValidEmail(const string &email)
    {
        // Check if the email is not empty
        if (email.empty())
            return false;

        bool hasAt = false;
        bool hasDot = false;
        bool atFirst = false;

        // Iterate over each character in the email
        for (char c : email)
        {
            // Check for special characters and their positions
            if (c == '@')
            {
                if (hasAt) // More than one '@'
                    return false;
                if (atFirst) // '@' at the beginning
                    return false;
                hasAt = true;
            }
            else if (c == '.')
            {
                hasDot = true;
            }
            else if (c == ' ')
            {
                return false; // Space not allowed
            }
            else if (c == '@' && hasAt)
            {
                return false; // '@' not allowed after the first occurrence
            }
            else if (c == '@')
            {
                atFirst = true; // '@' at the beginning of the email
            }
        }

        // Check if the last character is not a '.'
        if (email.back() == '.')
            return false;
        if (email.front() == '@')
            return false;

        // Check if both '@' and '.' are present
        return hasAt && hasDot;
    }

    // document number validation
    bool isvalidAadharnumber(const string &aadhar)
    {
        if (aadhar.length() != 12)
        {
            return false;
        }
        for (char c : aadhar)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    bool isvalidpannumber(const string &pan)
    {
        if (pan.length() != 10)
        {
            return false; // PAN should be 10 characters long
        }

        // Check first five characters are uppercase letters
        for (int i = 0; i < 5; ++i)
        {
            if (!isupper(pan[i]))
            {
                return false;
            }
        }

        // Check next four characters are digits
        for (int i = 5; i < 9; ++i)
        {
            if (!isdigit(pan[i]))
            {
                return false;
            }
        }

        // Check last character is an uppercase letter
        if (!isupper(pan[9]))
        {
            return false;
        }

        return true; // If the PAN passes all checks, it's valid
    }

    bool isvalidVoternumber(const string &votarId)
    {
        if (votarId.length() != 10)
        {
            return false;
        }

        for (int i = 0; i < 3; ++i)
        {
            if (!isupper(votarId[i]))
            {
                return false;
            }
        }

        for (int i = 3; i < 9; ++i)
        {
            if (!isdigit(votarId[i]))
            {
                return false;
            }
        }

        return true;
    }
    bool isvalidpassportNumber(const string &passport)
    {
        if (passport.length() != 8)
        {
            return false;
        }

        for (int i = 0; i < 1; ++i)
        {
            if (!isupper(passport[i]))
            {
                return false;
            }
        }

        for (int i = 1; i < 7; ++i)
        {
            if (!isdigit(passport[i]))
            {
                return false;
            }
        }

        return true;
    }
};

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
class create_Account : public validation
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
        cin.ignore();
        do
        {
            cout << "Enter Account Holder Name : ";
            getline(cin, AC_holder_Name);

            if (hasInteger(AC_holder_Name))
            {
                cout << endl
                     << "Account Holder Name Is Not a Number Value || Please Enter Right Name" << endl;
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Enter Date of birth (dd/mm/yyyy) : ";
            getline(cin, dob);

            if (!isValidDateOfBirthFormat(dob))
            {
                cout << endl
                     << "Date Of Birth is Wrong || Please enter in DD/MM/YYYY format." << endl;
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Enter Contect Number : ";
            getline(cin, contect_no);

            if (!isValidMobilenumber(contect_no))
            {
                cout << endl
                     << "Mobile Number is Wrong || Please enter 10 digit mobile number." << endl;
            }
            else
            {
                break;
            }
        } while (true);
        do
        {
            cout << "Enter e-Mail ID : ";
            getline(cin, mail_ID);

            if (isValidEmail(mail_ID))
            {
                break;
            }
            else
            {
                cout << endl
                     << "Invalid email address || Please Enter Valid Email Address" << endl;
            }
        } while (true);

        cout << "Enter Detail Verification Document : \n"
             << "\t1. Pan Card" << endl
             << "\t2. Passport" << endl
             << "\t3. Voter's ID" << endl
             << "\t4. Aadhaar card" << endl
             << "Enter Your Choice : ";
        getline(cin, c);
        do
        {
            if (c == "1")
            {
                Documents = "Pan Card";
                string panNumber;
                do
                {
                    cout << "Enter Pan Card Number : ";
                    getline(cin, panNumber);
                    for (char &c : panNumber)
                    {
                        c = toupper(c);
                    }
                    if (isvalidpannumber(panNumber))
                    {
                        document_no = panNumber;
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid PAN Number || Please Enter Valid PAN number" << endl;
                    }
                } while (true);

                break;
            }
            else if (c == "2")
            {
                Documents = "Passport";
                string passportNumber;

                do
                {
                    cout << "Enter Indian Passport Number : ";
                    getline(cin, passportNumber);
                    for (char &c : passportNumber)
                    {
                        c = toupper(c);
                    }
                    if (isvalidpassportNumber(passportNumber))
                    {
                        document_no = passportNumber;
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid Passport Number || Please Enter Valid Passport number" << endl;
                    }
                } while (true);

                break;
            }
            else if (c == "3")
            {
                Documents = "Voter's ID";

                string voterId;

                do
                {
                    cout << "Enter Voter Card Number (Voter ID) : ";
                    getline(cin, voterId);
                    for (char &c : voterId)
                    {
                        c = toupper(c);
                    }
                    if (isvalidVoternumber(voterId))
                    {
                        document_no = voterId;
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid Voter ID || Please Enter Valid Voter ID" << endl;
                    }
                } while (true);

                break;
            }

            else if (c == "4")
            {
                Documents = "Aadhaar card";

                string aadharNumber;
                do
                {
                    cout << "Enter Voter Card Number (Voter ID) : ";
                    getline(cin, aadharNumber);
                    for (char &c : aadharNumber)
                    {
                        c = toupper(c);
                    }
                    if (isvalidAadharnumber(aadharNumber))
                    {
                        document_no = aadharNumber;
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid aadhar number || Please Enter Valid 12 digit aadhar number" << endl;
                    }
                } while (true);

                break;
            }
            else
            {
                cout << "Enter Rigth Choice" << endl;
            }

        } while (true);

        // cout << "Enter Document Number : ";
        // getline(cin, document_no);

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

        do
        {
            cout << "Nominee Name : ";
            getline(cin, Nominee_Name);

            if (hasInteger(Nominee_Name))
            {
                cout << endl
                     << "Account Holder Name Is Not a Number Value || Please Enter Right Name" << endl;
            }
            else
            {
                break;
            }
        } while (true);

        do
        {
            cout << "Enter Nominee Date of birth (dd/mm/yyyy) : ";
            getline(cin, Nominee_DOB);

            if (!isValidDateOfBirthFormat(Nominee_DOB))
            {
                cout << endl
                     << "Date Of Birth is Wrong || Please enter in DD/MM/YYYY format." << endl;
            }
            else
            {
                break;
            }
        } while (true);

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

class view_data : public create_Account
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
        cin.ignore();
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

class edit : public view_data
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
        cin.ignore();
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
             << "Enter the Property : ";
        getline(cin, property);

        // Determine the index of the subject
        if (property == "1")
        {
            index = 4;
            do
            {
                cout << "Enter New NAME : ";
                getline(cin, newdetails);

                if (hasInteger(newdetails))
                {
                    cout << endl
                         << "Account Holder New Name Is Not a Number Value || Please Enter Right Name" << endl;
                }
                else
                {
                    break;
                }
            } while (true);
        }
        else if (property == "2")
        {
            index = 5;

            do
            {
                cout << "Enter Date of birth (dd/mm/yyyy) : ";
                getline(cin, newdetails);

                if (!isValidDateOfBirthFormat(newdetails))
                {
                    cout << endl
                         << "Date Of Birth is Wrong || Please enter in DD/MM/YYYY format." << endl;
                }
                else
                {
                    break;
                }
            } while (true);
        }
        else if (property == "3")
        {
            index = 6;
            do
            {
                cout << "Enter New Contect Number : ";
                getline(cin, newdetails);

                if (!isValidMobilenumber(newdetails))
                {
                    cout << endl
                         << "Mobile Number is Wrong || Please enter 10 digit mobile number." << endl;
                }
                else
                {
                    break;
                }
            } while (true);
        }
        else if (property == "4")
        {
            index = 7;
            do
            {
                cout << "Enter New Mail ID : ";
                getline(cin, newdetails);

                if (isValidEmail(newdetails))
                {
                    break;
                }
                else
                {
                    cout << endl
                         << "Invalid email address || Please Enter Valid Email Address" << endl;
                }
            } while (true);
        }
        else if (property == "5")
        {
            cout << "Enter Detail Verification Document : \n"
                 << "\t1. Pan Card" << endl
                 << "\t2. Passport" << endl
                 << "\t3. Voter's ID" << endl
                 << "\t4. Aadhaar card" << endl
                 << "Enter Your Choice : ";
            getline(cin, c);
            do
            {
                if (c == "1")
                {
                    newdetails = "Pan Card";
                    string panNumber;
                    do
                    {
                        cout << "Enter Pan Card Number : ";
                        getline(cin, panNumber);
                        for (char &c : panNumber)
                        {
                            c = toupper(c);
                        }
                        if (isvalidpannumber(panNumber))
                        {
                            new_document_no = panNumber;
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid PAN Number || Please Enter Valid PAN number" << endl;
                        }
                    } while (true);

                    break;
                }
                else if (c == "2")
                {
                    newdetails = "Passport";
                    string passportNumber;

                    do
                    {
                        cout << "Enter Indian Passport Number : ";
                        getline(cin, passportNumber);
                        for (char &c : passportNumber)
                        {
                            c = toupper(c);
                        }
                        if (isvalidpassportNumber(passportNumber))
                        {
                            new_document_no = passportNumber;
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid Passport Number || Please Enter Valid Passport number" << endl;
                        }
                    } while (true);

                    break;
                }
                else if (c == "3")
                {
                    newdetails = "Voter's ID";

                    string voterId;

                    do
                    {
                        cout << "Enter Voter Card Number (Voter ID) : ";
                        getline(cin, voterId);
                        for (char &c : voterId)
                        {
                            c = toupper(c);
                        }
                        if (isvalidVoternumber(voterId))
                        {
                            new_document_no = voterId;
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid Voter ID || Please Enter Valid Voter ID" << endl;
                        }
                    } while (true);

                    break;
                }

                else if (c == "4")
                {
                    newdetails = "Aadhaar card";

                    string aadharNumber;
                    do
                    {
                        cout << "Enter Voter Card Number (Voter ID) : ";
                        getline(cin, aadharNumber);
                        for (char &c : aadharNumber)
                        {
                            c = toupper(c);
                        }
                        if (isvalidAadharnumber(aadharNumber))
                        {
                            new_document_no = aadharNumber;
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Invalid aadhar number || Please Enter Valid 12 digit aadhar number" << endl;
                        }
                    } while (true);

                    break;
                }
                else
                {
                    cout << "Enter Rigth Choice" << endl;
                }

            } while (true);
            // cout << "Enter New Document Number : ";
            // getline(cin, new_document_no); // index=9
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

class transact : public edit
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
        cin.ignore();
        cout << "Enter the Account Number : ";
        getline(cin, AC_no_input);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        cout << "Enter Contect Number : ";
        getline(cin, contect_no_input);

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

                cout << endl
                     << "---| Account Details are find |---" << endl
                     << endl;

                cout << "Enter Withdrawal Amount : ";
                getline(cin, withdrawl_amount);
                int withdrawl_amount1;
                stringstream convert(withdrawl_amount);
                convert >> withdrawl_amount1;

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
        cin.ignore();
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

                cout << endl
                     << "---| Account Details are find |---" << endl
                     << endl;

                cout << "Enter Deposite Amount : ";
                getline(cin, deposite_amount);

                int deposite_amount1;
                stringstream convert(deposite_amount);
                convert >> deposite_amount1;

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

        cout << "\nDeposite Successful\n";
        cout << "Your Total balance is : "
             << total_after << endl;
    }

    int op()
    {
        do
        {
            int c;

            cout << "1. Withdrawal" << endl
                 << "2. Deposite" << endl
                 << "0. Exit" << endl
                 << "Enter Your Choise : ";
            cin >> c;
            switch (c)
            {
            case 1:
                withdrawal();
                break;
            case 2:
                diposite();
                break;
            case 0:
                return 0;
            default:
                cout << endl
                     << "Please Enter Right Choise" << endl;
                break;
            }
        } while (true);
    }
};

class erase : public transact
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
        cin.ignore();
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
            cout << "Operation cancel";
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

class see : public erase
{
public:
    void read_all_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Account_details.csv", ios::in);

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

            // Print the found data
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << " | " << row[8] << " | " << row[9] << " | " << row[10] << " | " << row[11] << " | " << row[12] << " | " << row[13] << " | " << row[14] << " | " << row[15] << " | " << row[16] << " | " << row[17] << " | " << row[18] << endl;
        }
        // Close the file
        fin.close();
    }
    void Balance_chack()
    {

        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Account_details.csv", ios::in);

        int count = 0;
        string input_value, document_no, AC_no, C_no, dob_input, dob;
        cout << "Enter the Account Number,Customer Number or Document Number to display Account Balance: ";
        cin.ignore();
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

class loan : public see
{
public:
    void new_loan()
    {
        fstream fin_acc, fin_trans, fout_acc, fout_trans;

        fin_acc.open("Account_details.csv", ios::in);
        fin_trans.open("loan_details.csv", ios::in);
        fout_trans.open("loan_details.csv", ios::app);

        int AC_no, loan_AC_no;
        float EMI, r;
        string loan_Ac_open_date, AC_holder_Name, dob, contect_no, mail_ID, Documents, document_no, Occupation, Nominee_Name, Nominee_DOB, Nominee_relation, c, AC_no_input, dob_input, contect_no_input, type_of_loan, C_no, loan_amount, Duration_of_loan;

        cin.ignore();
        cout << "Enter the Current opened Account Number : ";
        getline(cin, AC_no_input);
        cout << "Enter Date of Birth  (dd/mm/yyyy) : ";
        getline(cin, dob_input);
        cout << "Enter Contect Number : ";
        getline(cin, contect_no_input);

        string line;
        bool find = false;
        // Update Account_details_in_loan_file.csv
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
            C_no = row[2];
            string dob = row[5];
            string contect_no = row[6];
            removeSpaces(AC_no);
            removeSpaces(dob);
            removeSpaces(contect_no);

            if (AC_no == AC_no_input && dob == dob_input && contect_no == contect_no_input)
            {
                find = true;
                cout << endl
                     << "---| Account Details are find |---" << endl
                     << "---| Please Enter below all Details |---" << endl;
                // Read the inputs
                loan_Ac_open_date = todaydate();
                loan_AC_no = rendome_AC();
                do
                {
                    cout << "Enter Account Holder Name : ";
                    getline(cin, AC_holder_Name);

                    if (hasInteger(AC_holder_Name))
                    {
                        cout << endl
                             << "Account Holder Name Is Not a Number Value || Please Enter Right Name" << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);

                do
                {
                    cout << "Enter Date of birth (dd/mm/yyyy) : ";
                    getline(cin, dob);

                    if (!isValidDateOfBirthFormat(dob))
                    {
                        cout << endl
                             << "Date Of Birth is Wrong || Please enter in DD/MM/YYYY format." << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);

                do
                {
                    cout << "Enter Contect Number : ";
                    getline(cin, contect_no_input);

                    if (!isValidMobilenumber(contect_no_input))
                    {
                        cout << endl
                             << "Mobile Number is Wrong || Please enter 10 digit mobile number." << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);
                do
                {
                    cout << "Enter e-Mail ID : ";
                    getline(cin, mail_ID);

                    if (isValidEmail(mail_ID))
                    {
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid email address || Please Enter Valid Email Address" << endl;
                    }
                } while (true);

                cout << "Enter Detail Verification Document : \n"
                     << "\t1. Pan Card" << endl
                     << "\t2. Passport" << endl
                     << "\t3. Voter's ID" << endl
                     << "\t4. Aadhaar card" << endl
                     << "Enter Your Choice : ";
                getline(cin, c);
                do
                {
                    if (c == "1")
                    {
                        Documents = "Pan Card";
                        string panNumber;
                        do
                        {
                            cout << "Enter Pan Card Number : ";
                            getline(cin, panNumber);
                            for (char &c : panNumber)
                            {
                                c = toupper(c);
                            }
                            if (isvalidpannumber(panNumber))
                            {
                                document_no = panNumber;
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "Invalid PAN Number || Please Enter Valid PAN number" << endl;
                            }
                        } while (true);

                        break;
                    }
                    else if (c == "2")
                    {
                        Documents = "Passport";
                        string passportNumber;

                        do
                        {
                            cout << "Enter Indian Passport Number : ";
                            getline(cin, passportNumber);
                            for (char &c : passportNumber)
                            {
                                c = toupper(c);
                            }
                            if (isvalidpassportNumber(passportNumber))
                            {
                                document_no = passportNumber;
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "Invalid Passport Number || Please Enter Valid Passport number" << endl;
                            }
                        } while (true);

                        break;
                    }
                    else if (c == "3")
                    {
                        Documents = "Voter's ID";

                        string voterId;

                        do
                        {
                            cout << "Enter Voter Card Number (Voter ID) : ";
                            getline(cin, voterId);
                            for (char &c : voterId)
                            {
                                c = toupper(c);
                            }
                            if (isvalidVoternumber(voterId))
                            {
                                document_no = voterId;
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "Invalid Voter ID || Please Enter Valid Voter ID" << endl;
                            }
                        } while (true);

                        break;
                    }

                    else if (c == "4")
                    {
                        Documents = "Aadhaar card";

                        string aadharNumber;
                        do
                        {
                            cout << "Enter Voter Card Number (Voter ID) : ";
                            getline(cin, aadharNumber);
                            for (char &c : aadharNumber)
                            {
                                c = toupper(c);
                            }
                            if (isvalidAadharnumber(aadharNumber))
                            {
                                document_no = aadharNumber;
                                break;
                            }
                            else
                            {
                                cout << endl
                                     << "Invalid aadhar number || Please Enter Valid 12 digit aadhar number" << endl;
                            }
                        } while (true);

                        break;
                    }
                    else
                    {
                        cout << "Enter Rigth Choice" << endl;
                    }

                } while (true);

                // cout << "Enter Document Number : ";
                // getline(cin, document_no);

                cout << "write Occupation :";
                getline(cin, Occupation);

                do
                {
                    cout << "Nominee Name : ";
                    getline(cin, Nominee_Name);

                    if (hasInteger(Nominee_Name))
                    {
                        cout << endl
                             << "Account Holder Name Is Not a Number Value || Please Enter Right Name" << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);

                do
                {
                    cout << "Enter Nominee Date of birth (dd/mm/yyyy) : ";
                    getline(cin, Nominee_DOB);

                    if (!isValidDateOfBirthFormat(Nominee_DOB))
                    {
                        cout << endl
                             << "Date Of Birth is Wrong || Please enter in DD/MM/YYYY format." << endl;
                    }
                    else
                    {
                        break;
                    }
                } while (true);

                cout << "Nominee relation : ";
                getline(cin, Nominee_relation);

                cout << "How many Amount do you want : ";
                getline(cin, loan_amount);

                int loan_amount_int = stoi(loan_amount);

                cout << "Enter Duration of loan (In months) : ";
                getline(cin, Duration_of_loan);
                int Duration_of_loan_int = stoi(Duration_of_loan);

                cout
                    << "Enter Type of loan : \n"
                    << "\t1. Home Loans [7.5%]" << endl
                    << "\t2. Education Loans[9.36%]" << endl
                    << "\t3. Car/Auto Loans[9.50%]" << endl
                    << "\t4. Personal Loans[13%]" << endl
                    << "\t5. Business Loans[22.26%]" << endl
                    << "\t6. Gold Loans [9.00%]" << endl
                    << "Enter Your Choice : ";
                getline(cin, c);
                do
                {
                    if (c == "1")
                    {
                        type_of_loan = "Home Loans";
                        r = 7.5 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else if (c == "2")
                    {
                        type_of_loan = "Education Loans";
                        r = 9.36 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else if (c == "3")
                    {
                        type_of_loan = "Car/Auto Loans";
                        r = 9.50 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else if (c == "4")
                    {
                        type_of_loan = "Personal Loans";
                        r = 13.00 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else if (c == "5")
                    {
                        type_of_loan = "Business Loans";
                        r = 22.26 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else if (c == "6")
                    {
                        type_of_loan = "Gold Loans";
                        r = 9.00 / (12 * 100);
                        EMI = (loan_amount_int * r * pow(1 + r, Duration_of_loan_int)) / (pow(1 + r, Duration_of_loan_int) - 1);
                        break;
                    }
                    else
                    {
                        cout << "Enter Rigth Choice" << endl;
                    }

                } while (true);
            }
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
        bool pass = false;
        // Update Account_details_in_loan_file.csv

        if (find == true)
        {
            fout_trans << loan_Ac_open_date << ","
                       << C_no << ","
                       << AC_no_input << ","
                       << "987654320" << loan_AC_no << ","
                       << dob_input << ","
                       << AC_holder_Name << "," // name
                       << contect_no_input << ","
                       << mail_ID << ","     // mail
                       << Documents << ","   // document
                       << document_no << "," // document_no
                       << Occupation << ","
                       << Nominee_Name << ","
                       << Nominee_DOB << ","
                       << Nominee_relation << ","
                       << type_of_loan << ","
                       << loan_amount << ","
                       << Duration_of_loan << ","
                       << EMI << ","
                       << "Loan Pass"
                       << ","
                       << "\n";
            pass = true;
        }

        fin_acc.close();
        fout_acc.close();
        fin_trans.close();
        fout_trans.close();
        if (pass == true)
        {
            cout << endl
                 << "Your Loan is Pass Successfully!!!" << endl
                 << "Your monthaly EMI is : " << EMI << endl
                 << "Account Number is : 987654320" << loan_AC_no << endl
                 << "Customer Number is : " << C_no << endl;
        }
        else
        {
            cout << "Account Not Found!!" << endl
                 << "Please Enter rigth details";
        }
    }
};

int admin()
{
    loan allobj;
    string username, password;
    cout << endl
         << " ***********************************" << endl
         << " * Welcome to Bank Inventory System *" << endl
         << " ***********************************" << endl
         << endl;

    cout << "Please enter admin username: ";
    cin >> username;

    cout << "Enter admin password: ";
    char pass;
    password = "";
    while ((pass = _getch()) != '\r') // Carriage return
    {
        if (pass == '\b')
        {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b"; // Move cursor back, erase character, move cursor back again
            }
        }
        else
        {
            password += pass;
            cout << '*'; // Print '*' instead of actual character
        }
    }
    cout << endl;

    if (username == "admin" && password == "AUBI$2024")
    {
        int choice;
        cout << "*  You Are Successfully Logged In  *" << endl;
        do
        {
            cout << endl
                 << "1. Create New Account" << endl
                 << "2. Search Account" << endl
                 << "3. Update Detail" << endl
                 << "4. Transact" << endl
                 << "5. Delete Account" << endl
                 << "6. See All Data" << endl
                 << "7. Apply Loan" << endl
                 << "0. Exit" << endl
                 << "Enter Your Choice : ";
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                allobj.create_Ac();
                break;
            case 2:
                allobj.search_account_data();
                break;
            case 3:
                allobj.update_AC_record();
                break;
            case 4:
                allobj.op();
                break;
            case 5:
                allobj.close_account();
                break;
            case 6:
                allobj.read_all_record();
                break;
            case 7:
                allobj.new_loan();
                break;
            case 0:
                return 0;
            default:
                cout << "Please Enter Right Choice";
                continue;
            }
        } while (true);
    }
    else
    {
        cout << "Incorrect username or password. Please try again." << endl;
        admin(); // Retry login
    }

    return 0;
}

int customer()
{
    loan allobj;
    cout << endl
         << endl
         << " ***********************************" << endl
         << " * Welcome to Bank Inventory System *" << endl
         << " ***********************************" << endl
         << endl;

    int n;
    do
    {
        cout << endl
             << "1. Create New Account" << endl
             << "2. View Detail" << endl
             << "3. Update Detail" << endl
             << "4. Get My Balance" << endl
             << "0. Exit" << endl
             << "Enter Your Choice : ";
        cin >> n;
        cout << endl;
        switch (n)
        {
        case 1:
            allobj.create_Ac();
            break;
        case 2:
            allobj.search_account_data();
            break;
        case 3:
            allobj.update_AC_record();
            break;
        case 4:
            allobj.Balance_chack();
            break;
        case 0:
            return 0;
        default:
            cout << "Please Enter Right Choice";
            continue;
        }
    } while (true);

    return 0;
}

int main()
{

    do
    {
        int c;

        cout << "1. Admin" << endl
             << "2. User" << endl
             << "0. Exit" << endl
             << "Enter Your Choise : ";
        cin >> c;
        switch (c)
        {
        case 1:
            admin();
            break;
        case 2:
            customer();
            break;
        case 0:
            cout << endl
                 << "Byy! I See You Again....";
            cout << endl
                 << "****************************************" << endl
                 << "*              DEVELOPED BY            *" << endl
                 << "*           ___________________        *" << endl
                 << "*          | Aaditya Raj Singh |       *" << endl
                 << "*           ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾        *" << endl
                 << "*                THANKYOU              *" << endl
                 << "****************************************" << endl;
            return 0;
        default:
            cout << endl
                 << "Please Enter Right Choise" << endl;
            break;
        }
    } while (true);

    return 0;
}