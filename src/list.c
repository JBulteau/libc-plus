#include "list.h"

int main() {
    init(bool, true, false);
    init(char, 'c');
    init(unsigned char, 'd', 'f');
    init(signed char, 'p', '9');
    init(short int, 56, 104, 309, 819);
    init(unsigned short int, 12, 20930);
    init(int, 1, 2);
    init(long int, 12091987, 859291);
    init(long long int, 1092019210);
    init(unsigned int, 1, 3, 5);
    init(unsigned long int, 102981029, 98239, 872782, 61621);
    init(unsigned long long int, 29829182981);
    init(float, 14.9, 1.01);
    init(double, 12.4, 10.3, 17.9);
    init(long double, 10920192.982198);
    init(char *, "toto");
    init(int *, "091099120");
    init(void *, 0x48129);
    return 0;
}