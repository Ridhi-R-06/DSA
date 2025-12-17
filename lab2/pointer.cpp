#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Function declarations
int* countdigits(int*);
int* storenum(int*, int);
int isPalindrome(int*, int*);
int isArmstrong(int*, int*, int*);
int isPerfect(int*);

int main(int argc, char* argv[]) {
    int* num = new int[1]; // Pointer for the input number
    cout << "Enter the number: ";
    cin >> *num;

    int* count = countdigits(num); // Pointer for digit count

    int* digits = storenum(num, *count); // Pointer for storing digits

    int* choice = new int[1]; // Pointer for menu choice

    while (true) {
        cout << "\n1. Palindrome\n";
        cout << "2. Armstrong Number\n";
        cout << "3. Perfect Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> *choice;

        if (*choice == 4) {
            cout << "Exiting the program.\n";
            break;
        }

        switch (*choice) {
            case 1:
                if (isPalindrome(digits, count) == 1) {
                    cout << "Number is a palindrome.\n";
                } else {
                    cout << "Number is not a palindrome.\n";
                }
                break;

            case 2:
                if (isArmstrong(digits, count, num) == 1) {
                    cout << "Number is an Armstrong number.\n";
                } else {
                    cout << "Number is not an Armstrong number.\n";
                }
                break;

            case 3:
                if (isPerfect(num) == 1) {
                    cout << "Number is a Perfect Number.\n";
                } else {
                    cout << "Number is not a Perfect Number.\n";
                }
                break;

            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    }

    // Free dynamically allocated memory
    delete[] num;
    delete[] count;
    delete[] digits;
    delete[] choice;

    return 0;
}

// Function to count the number of digits
int* countdigits(int* num) {
    int* count = new int[1];
    *count = 0;

    int* temp = new int[1];
    *temp = *num;

    while (*temp > 0) {
        *temp = *temp / 10;
        *count = *count + 1;
    }

    delete[] temp; // Free temporary memory
    return count;
}

// Function to store digits of a number in an array
int* storenum(int* num, int digitcount) {
    int* temp = new int[1];
    *temp = *num;

    int* digits = new int[digitcount]; // Array to store digits
    int* i = new int[1];

    for (*i = 0; *i < digitcount; (*i)++) {
        *(digits + *i) = *temp % 10; // Extract digit
        *temp = *temp / 10;
    }

    delete[] i;   // Free temporary memory
    delete[] temp;
    return digits;
}

// Function to check if a number is a palindrome
int isPalindrome(int* digits, int* count) {
    int* i = new int[1];
    for (*i = 0; *i < *count / 2; (*i)++) {
        if (*(digits + *i) != *(digits + (*count - 1 - *i))) {
            delete[] i;
            return 0; // Not a palindrome
        }
    }
    delete[] i;
    return 1; // Palindrome
}

// Function to check if a number is an Armstrong number
int isArmstrong(int* digits, int* count, int* num) {
    int* i = new int[1];
    int* sum = new int[1];
    *sum = 0;

    for (*i = 0; *i < *count; (*i)++) {
        *sum = *sum + (int)pow(*(digits + *i), *count);
    }

    if (*sum == *num) {
        delete[] i;
        delete[] sum;
        return 1; // Armstrong number
    } else {
        delete[] i;
        delete[] sum;
        return 0; // Not an Armstrong number
    }
}

// Function to check if a number is a Perfect Number
int isPerfect(int* num) {
    int* sum = new int[1];
    *sum = 0;

    int* i = new int[1];
    for (*i = 1; *i <= *num / 2; (*i)++) {
        if (*num % *i == 0) {
            *sum = *sum + *i;
        }
    }

    if (*sum == *num) {
        delete[] sum;
        delete[] i;
        return 1; // Perfect number
    } else {
        delete[] sum;
        delete[] i;
        return 0; // Not a perfect number
    }
}
