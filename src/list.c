#include "list.h"

int main() {
    List *list = init(bool, true, false);
    printf("(bool)\nFront: %s\nBack: %s\n\n", list->front(list) ? "true" : "false", list->back(list) ? "true" : "false");
    List *list2 = init(char, 'c', '9', 'f', '7');
    printf("(char)\nFront: %c\nBack: %c\n\n", list2->front(list2), list2->back(list2));
    List *list3 = init(unsigned char, 'd', 'f');
    printf("(unsigned char)\nFront: %hhc\nBack: %hhc\n\n", list3->front(list3), list3->back(list3));
    List *list4 = init(signed char, 'p', '9');
    printf("(signed char)\nFront: %hhc\nBack: %hhc\n\n", list4->front(list4), list4->back(list4));
    List *list5 = init(short int, 56, 104, 309, 819);
    printf("(short int)\nFront: %hi\nBack: %hi\n\n", list5->front(list5), list5->back(list5));
    List *list6 = init(unsigned short int, 12, 20930);
    printf("(unsigned short int)\nFront: %hi\nBack: %hi\n\n", list5->front(list6), list5->back(list6));
    List *list7 = init(int, 1, 2);
    printf("(int)\nFront: %i\nBack: %i\n\n", list7->front(list7), list7->back(list7));
    List *list8 = init(long int, 12091987, 859291);
    printf("(long int)\nFront: %li\nBack: %li\n\n", list8->front(list8), list8->back(list8));
    List *list9 = init(long long int, 1092019210);
    printf("(long long int)\nFront: %lli\nBack: %lli\n\n", list9->front(list9), list9->back(list9));
    List *list10 = init(unsigned int, 1, 3, 5);
    printf("(unsigned int)\nFront: %u\nBack: %u\n\n", list10->front(list10), list10->back(list10));
    List *list11 = init(unsigned long int, 102981029, 98239, 872782, 61621);
    printf("(unsigned long int)\nFront: %lu\nBack: %lu\n\n", list11->front(list11), list11->back(list11));
    List *list12 = init(unsigned long long int, 29829182981);
    printf("(unsigned long long int)\nFront: %llu\nBack: %llu\n\n", list12->front(list12), list12->back(list12));
    List *list13 = init(char *, "toto", "tata", "titi");
    printf("(char *)\nFront: %s\nBack: %s\n\n", list13->front(list13), list13->back(list13));
    List *list14 = init(int *, "091099120");
    printf("(int *)\nFront: %p\nBack: %p\n\n", list14->front(list14), list14->back(list14));
    List *list15 = init(void *, 0x48129);
    printf("(void *)\nFront: %p\nBack: %p\n\n", list15->front(list15), list15->back(list15));
    return 0;
}