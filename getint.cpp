#include <iostream>
#include <cctype>

using namespace std;

const int SIZE = 10; // Assume an array size of 10

int getint(int *);

int main() {
    int n, array[SIZE] = {-233};

    cout << "Enter integers, separated by spaces or newlines:" << endl;

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        // Get integers one by one and store them in the array
    }

    cout << "Array of obtained integers:" << endl;

    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = cin.get())) /* Skip leading white space */
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        cin.unget(); /* Not a digit, push the character back into the input stream */
        return 0;    /* Return 0 to indicate failure to obtain an integer */
    }

    sign = (c == '-') ? -1 : 1; // Record the sign of the integer

    if (c == '+' || c == '-') // If the character is + or -, get the next character
        c = cin.get();

    for (*pn = 0; isdigit(c); c = cin.get())
        *pn = 10 * *pn + (c - '0'); // Build the integer

    *pn *= sign; // Multiply by the sign to get the correct integer value

    if (c != EOF)
        cin.unget(); // Push back any extra characters read

    return c; // Return the last character
}
