#include <iostream>

const char* dbsp = "\n\n";
const char* spacer1 = "===========================";

struct even_n {
    int sum = 0;
    int last_sum = 0;
    int pos_n = 1;

    void print_sum(int n) {
        std::cout << "position: " << pos_n << "\n"
                  << "current sum: " << last_sum << "\n"
                  << "number: " << n << "\n"
                  << "sum: " <<  last_sum << " + " << n << " = " << sum << "\n"
                  << "conclusion: " << sum << " = " << pos_n << " x " << pos_n+1
                  << dbsp << spacer1 << dbsp;
    }

    /* generate sum of pos(n) based on a single end-goal number.   
    if not n, default to first 5 odd integers. */

    even_n(int end_n = 10) {
        if (end_n <= 0) { return; } // n must be positive.

        for (int i = 0; i <= end_n; ++i) {
            if ( (i == 0) || (i%2 != 0) ) { continue; }

            sum += i;

            print_sum(i);

            last_sum = sum;
            pos_n++;
        }
    }

};

int main(int argc, char const* argv[]) {
    std::cout << "\nThe sum of all even numbers n = pos(n)" << " x (pos(n)+1)\n"
              << dbsp << spacer1 << dbsp
              << "default : even_n()\n"
              << "~~< NUMBERS 2 - 10 >~~" 
              << dbsp << spacer1 << dbsp;
    even_n();

    std::cout << "~~< NUMBERS 2 - 30 >~~\n"
              << "goal number : even_n(int end_n)\n"
              << dbsp << spacer1 << dbsp;
    even_n(30);

    return 0;
}