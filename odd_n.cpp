#include <iostream>

const char* stSqr = "\u00B2"; // unicode for ^2
const char* spacer1 = "\n===========================\n\n";

struct odd_n {
    int sum = 0;
    int pos_n = 1;

    void print_sum(int n) {
        std::cout << "position: " << pos_n << "\n"
                  << "number: " << n << "\n"
                  << "sum: " << sum << " + " << n << " = " << sum+n << "\n"
                  << "conclusion: " << sum+n << " = " << pos_n << stSqr << "\n"
                  << spacer1;
    }

    /* generate sum of pos(n) based on a single end-goal number.   
    if not n, default to first 5 odd integers. */

    odd_n(int end_n = 9) {
        if (end_n <= 0) { return; } // n must be positive.

        for (int n = 1; n <= end_n; n += 2) {
            print_sum(n);
            sum += n;
            pos_n++;
        }
    }

};

int main(int argc, char const* argv[]) {
    std::cout << "\nThe sum of all odd numbers n = pos(n)" << stSqr << "\n"
              << spacer1
              << "default : odd_n()\n"
              << "~~< NUMBERS 1 - 9 >~~" 
              << spacer1;
    odd_n();

    std::cout << "~~< NUMBERS 1 - 29 >~~\n"
              << "goal number : odd_n(int end_n)\n"
              << spacer1;
    odd_n(30);

    return 0;
}
