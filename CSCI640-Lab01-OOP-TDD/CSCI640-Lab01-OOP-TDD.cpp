// CSCI640-Lab01-OOP-TDD.cpp 
//

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// class
class CPassword {
    public:
        CPassword() {} // constructor
        ~CPassword() {} // destructor 
        
        // Ask user for password
        void askForPassword() {
            string input;
            cout << "Enter a password:";
            cin >> input;
            password = input;
        }

        void setPassword(string str) {
            password = str;
        }
        
        string getPassword() {
            return password;
        }

        // Method “character”: 6 characters long
        bool character(string str) {
            if (str.size() >= 6) {
                return true;
            }
            else {
                return false;
            }
        }

        // Method “lower”: Must contain at least one lower case letter
        bool lower(string str) {
            for (int i = 0; i < str.size(); i++) {
                if (islower(str[i]))
                    return true;
            }

            return false;
        }

        // Method “upper”: one upper case letter
        bool upper(string str) {
            for (int i = 0; i < str.size(); i++) {
                if (isupper(str[i]))
                    return true;
            }

            return false;
        }

        // Method “digit”: one digit
        bool digit(string str) {
            for (int i = 0; i < str.size(); i++) {
                if (isdigit(str[i]))
                    return true;
            }

            return false;
        }

        // Method “special”: and one of these special characters ~!@#$%^&* ()_ +
        bool special(string str) {
            const string specialCharacters = "~!@#$%^&*()_+";

            for (int i = 0; i < specialCharacters.size(); i++) {
                if (str.find_first_of(specialCharacters[i]) != string::npos)
                    return true;
            }

            return false;
        }
    private:
        string password;

        
};


// test class
class TestCPassword {
    public:
        TestCPassword() {}
        ~TestCPassword() {}

        void testAll() {
            testOne(1);
            testOne(2);
            testOne(3);
            testOne(4);
            testOne(5);
        }


    private:
        // class to test
        CPassword cpassword;

        // Method “character”: 6 characters long    
        bool test01() {
            bool expected;

            // less than 6 character
            expected = false;
            if (cpassword.character("1234") != expected) {
                return false;
            }

            if (cpassword.character("1") != expected) {
                return false;
            }


            // 6 character
            expected = true;
            if (cpassword.character("123456") != expected) {
                return false;
            }

            if (cpassword.character("ABCDEF") != expected) {
                return false;
            }


            // more than 6 character
            expected = true;
            if (cpassword.character("12345678") != expected) {
                return false;
            }

            if (cpassword.character("A@2nds1*eo01w") != expected) {
                return false;
            }


            // no character
            expected = false;
            if (cpassword.character("") != expected) {
                return false;
            }

            return true;
        }

        // Method “lower”: Must contain at least one lower case letter
        bool test02() {
            bool expected;

            // contain one lower case letter
            expected = true;
            // lower case at the beginning
            if (cpassword.lower("a1HI29") != expected) {
                return false;
            }
            // lower case at the end
            if (cpassword.lower("A120@j") != expected) {
                return false;
            }
            // lower case in the middle
            if (cpassword.lower("50@aPPLE") != expected) {
                return false;
            }

            // contain more than one lower case letter
            expected = true;
            if (cpassword.lower("ha90a2") != expected) {
                return false;
            }

            // contain no lower case letter
            expected = false;
            if (cpassword.lower("APPLE2") != expected) {
                return false;
            }

            // contain no character
            expected = false;
            if (cpassword.lower("") != expected) {
                return false;
            }

            return true;
        }

        // Method “upper”: one upper case letter
        bool test03() {
            bool expected;

            // contain one upper case
            expected = true;
            // upper case at the start
            if (cpassword.upper("Apple2020") != expected) {
                return false;
            }
            // upper case at the end
            if (cpassword.upper("2020applE") != expected) {
                return false;
            }
            // upper case in the middle
            if (cpassword.upper("20aPple") != expected) {
                return false;
            }

            // contain more than one upper case
            expected = true;
            if (cpassword.upper("ApPlE") != expected) {
                return false;
            }

            // contain no upper case letter
            expected = false;
            if (cpassword.upper("banana2022") != expected) {
                return false;
            }

            // contain no character
            expected = false;
            if (cpassword.upper("") != expected) {
                return false;
            }

            return true;
        }

        // Method “digit”: one digit
        bool test04() {
            bool expected;
            // contain one digit
            expected = true;
            // digit at the start
            if (cpassword.digit("5alqejf") != expected) {
                return false;
            }
            // digit at the end
            if (cpassword.digit("qwefbr8") != expected) {
                return false;
            }
            // digit in the middle
            if (cpassword.digit("kwe1fmee") != expected) {
                return false;
            }

            // contain more than one digit
            expected = true;
            if (cpassword.digit("1ha20@22") != expected) {
                return false;
            }

            // contain no digit
            expected = false;
            if (cpassword.digit("jeatcooking") != expected) {
                return false;
            }

            // contain no character
            expected = false;
            if (cpassword.digit("") != expected) {
                return false;
            }

            return true;
        }

        // Method “special”: and one of these special characters ~!@#$%^&*()_+
        bool test05() {
            bool expected;

            // contain one special character
            expected = true;
            // special character at the start
            if (cpassword.special("#2020happy") != expected) {

                return false; 
            }
            // special character at the end
            if (cpassword.special("happy2020+") != expected) {

                return false; 
            }
            // spcial character in the middle
            if (cpassword.special("jeat@aPple") != expected) {
                return false; 
            }

            // contain more than one special character
            expected = true;
            if (cpassword.special("a+sd~dfj$^") != expected) {
                return false;
            }

            // contain no special character
            expected = false;
            if (cpassword.special("the2022Door") != expected) {
                return false;
            }

            // contain no character
            expected = false;
            if (cpassword.special("") != expected) {
                return false;
            }

            return true;
        }

        void testOne(int num) {
            if (num <= 0 || num > 5) {
                cout << "CPassword: Error: invalid test case number." << endl;
                return;
            }
            else {
                bool result = false;
                switch (num) {
                case 1:
                    result = test01();
                    break;
                case 2:
                    result = test02();
                    break;
                case 3:
                    result = test03();
                    break;
                case 4:
                    result = test04();
                    break;
                case 5:
                    result = test05();
                    break;
                }

                if (result) {
                    cout << "Test0" << num << ": PASSED." << endl;
                }
                else {
                    cout << "Test0" << num << ": FAILED." << endl;
                }
            }
        }
};


// main
int main()
{
    TestCPassword testcpassword; // TestCPassword is a class use for testing methods in CPassword
    testcpassword.testAll(); // run all test cases 

}

