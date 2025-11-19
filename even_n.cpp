#include <iostream>

const char* spacer1 = "\n===========================\n\n";

struct even_n {
    int sum = 0;
    int pos_n = 1;

    void print_sum(int n) {
        std::cout << "position: " << pos_n << "\n"
                  << "number: " << n << "\n"
                  << "sum: " << sum << " + " << n << " = " << sum+n << "\n"
                  << "conclusion: " << sum+n << " = " << pos_n << " x " << pos_n+1 << "\n"
                  << spacer1;
    }

    /* generate sum of pos(n) based on a single end-goal number.   
    if not n, default to first 5 even integers. */

    even_n(int end_n = 10) {
        if (end_n <= 0) { return; } // n must be positive.

        for (int n = 0; n < end_n; ++n) {
            if ( (n == 0) || (n%2 != 0) ) { continue; }
            print_sum(n);
            sum += n;
            pos_n++;
        }
    }

};

int main(int argc, char const* argv[]) {
    std::cout << "\nThe sum of all even numbers n = pos(n) x (pos(n)+1)\n"
              << spacer1
              << "~~< NUMBERS 2 - 10 >~~\n"
              << "default : even_n()\n"
              << spacer1;
    even_n();

    std::cout << "~~< NUMBERS 2 - 30 >~~\n"
              << "goal number : even_n(int end_n)\n"
              << spacer1;
    even_n(30);

    return 0;
}
