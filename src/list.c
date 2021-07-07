#include "list.h"

int main() {
    List *empty = create_list(char *);
    if (empty->empty(empty) && !empty->front(empty))
        printf("Empty list, no value\n\n");
    empty->delete(empty);
    List *list = create_list(bool, false, true);
    printf("(bool)\nFront: %s\nBack: %s\n", list->front(list) ? "true" : "false", list->back(list) ? "true" : "false");
    list->empty(list) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list->size(list));
    Iterator *begin_iterator = list->begin(list);
    Iterator *end_iterator = list->end(list);
    printf("(bool)\nIterator begin: %s\nIterator end: %s\n\n\n", begin_iterator->value(begin_iterator) ? "true" : "false", end_iterator->value(end_iterator) ? "true" : "false");
    begin_iterator->release(begin_iterator);
    end_iterator->release(end_iterator);
    list->delete(list);
    List *list2 = create_list(char, 'c', '9', 'f', '7');
    printf("(char)\nFront: %c\nBack: %c\n", list2->front(list2), list2->back(list2));
    list2->empty(list2) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list2->size(list2));
    Iterator *begin_iterator2 = list2->begin(list2);
    Iterator *end_iterator2 = list2->end(list2);
    printf("(char)\nIterator begin: %c\nIterator end: %c\n\n", begin_iterator2->value(begin_iterator2), end_iterator2->value(end_iterator2));
    printf("Next -> %c\n", begin_iterator2->next(begin_iterator2)->value(begin_iterator2));
    printf("Prev -> %c\n", end_iterator2->prev(end_iterator2)->value(end_iterator2));
    printf("Cycle -> %c\n", begin_iterator2->prev(begin_iterator2)->prev(begin_iterator2)->value(begin_iterator2));
    printf("Cycle -> %c\n\n\n", end_iterator2->next(end_iterator2)->next(end_iterator2)->value(end_iterator2));
    begin_iterator2->release(begin_iterator2);
    end_iterator2->release(end_iterator2);
    list2->delete(list2);
    List *list3 = create_list(unsigned char, 'd', 'f');
    printf("(unsigned char)\nFront: %hhc\nBack: %hhc\n", list3->front(list3), list3->back(list3));
    list3->empty(list3) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list3->size(list3));
    Iterator *begin_iterator3 = list3->begin(list3);
    Iterator *end_iterator3 = list3->end(list3);
    printf("(unsigned char)\nIterator begin: %hhc\nIterator end: %hhc\n\n\n", begin_iterator3->value(begin_iterator3), end_iterator3->value(end_iterator3));
    begin_iterator3->release(begin_iterator3);
    end_iterator3->release(end_iterator3);
    list3->delete(list3);
    List *list4 = create_list(signed char, 'p', '9');
    printf("(signed char)\nFront: %hhc\nBack: %hhc\n", list4->front(list4), list4->back(list4));
    list4->empty(list4) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list4->size(list4));
    Iterator *begin_iterator4 = list4->begin(list4);
    Iterator *end_iterator4 = list4->end(list4);
    printf("(signed char)\nIterator begin: %hhc\nIterator end: %hhc\n\n\n", begin_iterator4->value(begin_iterator4), end_iterator4->value(end_iterator4));
    begin_iterator4->release(begin_iterator4);
    end_iterator4->release(end_iterator4);
    list4->delete(list4);
    List *list5 = create_list(short int, 56, 104, 309, 819);
    printf("(short int)\nFront: %hi\nBack: %hi\n", list5->front(list5), list5->back(list5));
    list5->empty(list5) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list5->size(list5));
    Iterator *begin_iterator5 = list5->begin(list5);
    Iterator *end_iterator5 = list5->end(list5);
    printf("(short int)\nIterator begin: %hi\nIterator end: %hi\n\n", begin_iterator5->value(begin_iterator5), end_iterator5->value(end_iterator5));
    printf("Iterating over list:\n");
    Iterator *it;
    FOR_RANGE(it, list5) {
        printf("- %hi\n", it->value(it));
    }
    printf("\n\n");
    begin_iterator5->release(begin_iterator5);
    end_iterator5->release(end_iterator5);
    list5->delete(list5);
    List *list6 = create_list(unsigned short int, 12, 20930);
    printf("(unsigned short int)\nFront: %hi\nBack: %hi\n", list6->front(list6), list6->back(list6));
    list6->empty(list6) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list6->size(list6));
    Iterator *begin_iterator6 = list6->begin(list6);
    Iterator *end_iterator6 = list6->end(list6);
    printf("(unsigned short int)\nIterator begin: %hi\nIterator end: %hi\n\n\n", begin_iterator6->value(begin_iterator6), end_iterator6->value(end_iterator6));
    begin_iterator6->release(begin_iterator6);
    end_iterator6->release(end_iterator6);
    list6->delete(list6);
    List *list7 = create_list(int, 1, 2);
    printf("(int)\nFront: %i\nBack: %i\n", list7->front(list7), list7->back(list7));
    list7->empty(list7) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list7->size(list7));
    Iterator *begin_iterator7 = list7->begin(list7);
    Iterator *end_iterator7 = list7->end(list7);
    printf("(int)\nIterator begin: %i\nIterator end: %i\n\n\n", begin_iterator7->value(begin_iterator7), end_iterator7->value(end_iterator7));
    begin_iterator7->release(begin_iterator7);
    end_iterator7->release(end_iterator7);
    list7->delete(list7);
    List *list8 = create_list(long int, 12091987, 859291);
    printf("(long int)\nFront: %li\nBack: %li\n", list8->front(list8), list8->back(list8));
    list8->empty(list8) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list8->size(list8));
    Iterator *begin_iterator8 = list8->begin(list8);
    Iterator *end_iterator8 = list8->end(list8);
    printf("(long int)\nIterator begin: %li\nIterator end: %li\n\n\n", begin_iterator8->value(begin_iterator8), end_iterator8->value(end_iterator8));
    begin_iterator8->release(begin_iterator8);
    end_iterator8->release(end_iterator8);
    list8->delete(list8);
    List *list9 = create_list(long long int, 1092019210);
    printf("(long long int)\nFront: %lli\nBack: %lli\n", list9->front(list9), list9->back(list9));
    list9->empty(list9) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list9->size(list9));
    Iterator *begin_iterator9 = list9->begin(list9);
    Iterator *end_iterator9 = list9->end(list9);
    printf("(long long int)\nIterator begin: %lli\nIterator end: %lli\n\n\n", begin_iterator9->value(begin_iterator9), end_iterator9->value(end_iterator9));
    begin_iterator9->release(begin_iterator9);
    end_iterator9->release(end_iterator9);
    list9->delete(list9);
    List *list10 = create_list(unsigned int, 1, 3, 5);
    printf("(unsigned int)\nFront: %u\nBack: %u\n", list10->front(list10), list10->back(list10));
    list10->empty(list10) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list10->size(list10));
    Iterator *begin_iterator10 = list10->begin(list10);
    Iterator *end_iterator10 = list10->end(list10);
    printf("(unsigned int)\nIterator begin: %u\nIterator end: %u\n\n\n", begin_iterator10->value(begin_iterator10), end_iterator10->value(end_iterator10));
    begin_iterator10->release(begin_iterator10);
    end_iterator10->release(end_iterator10);
    list10->delete(list10);
    List *list11 = create_list(unsigned long int, 102981029, 98239, 872782, 61621);
    printf("(unsigned long int)\nFront: %lu\nBack: %lu\n", list11->front(list11), list11->back(list11));
    list11->empty(list11) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list11->size(list11));
    Iterator *begin_iterator11 = list11->begin(list11);
    Iterator *end_iterator11 = list11->end(list11);
    printf("(unsigned long int)\nIterator begin: %lu\nIterator end: %lu\n\n\n", begin_iterator11->value(begin_iterator11), end_iterator11->value(end_iterator11));
    begin_iterator11->release(begin_iterator11);
    end_iterator11->release(end_iterator11);
    list11->delete(list11);
    List *list12 = create_list(unsigned long long int, 29829182981);
    printf("(unsigned long long int)\nFront: %llu\nBack: %llu\n", list12->front(list12), list12->back(list12));
    list12->empty(list12) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list12->size(list12));
    Iterator *begin_iterator12 = list12->begin(list12);
    Iterator *end_iterator12 = list12->end(list12);
    printf("(unsigned long long int)\nIterator begin: %llu\nIterator end: %llu\n\n\n", begin_iterator12->value(begin_iterator12), end_iterator12->value(end_iterator12));
    begin_iterator12->release(begin_iterator12);
    end_iterator12->release(end_iterator12);
    list12->delete(list12);
    List *list13 = create_list(char *, "toto", "tata", "titi");
    printf("(char *)\nFront: %s\nBack: %s\n", list13->front(list13), list13->back(list13));
    list13->empty(list13) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list13->size(list13));
    Iterator *begin_iterator13 = list13->begin(list13);
    Iterator *end_iterator13 = list13->end(list13);
    printf("(char *)\nIterator begin: %s\nIterator end: %s\n\n\n", begin_iterator13->value(begin_iterator13), end_iterator13->value(end_iterator13));
    begin_iterator13->release(begin_iterator13);
    end_iterator13->release(end_iterator13);
    list13->delete(list13);
    List *list14 = create_list(int *, "091099120");
    printf("(int *)\nFront: %p\nBack: %p\n", list14->front(list14), list14->back(list14));
    list14->empty(list14) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list14->size(list14));
    Iterator *begin_iterator14 = list14->begin(list14);
    Iterator *end_iterator14 = list14->end(list14);
    printf("(int *)\nIterator begin: %p\nIterator end: %p\n\n\n", begin_iterator14->value(begin_iterator14), end_iterator14->value(end_iterator14));
    begin_iterator14->release(begin_iterator14);
    end_iterator14->release(end_iterator14);
    list14->delete(list14);
    List *list15 = create_list(void *, 0x48129);
    printf("(void *)\nFront: %p\nBack: %p\n", list15->front(list15), list15->back(list15));
    list15->empty(list15) ? printf("List is empty\n\n") : printf("List size is %u\n\n", list15->size(list15));
    Iterator *begin_iterator15 = list15->begin(list15);
    Iterator *end_iterator15 = list15->end(list15);
    printf("(void *)\nIterator begin: %p\nIterator end: %p\n\n\n", begin_iterator15->value(begin_iterator15), end_iterator15->value(end_iterator15));
    begin_iterator15->release(begin_iterator15);
    end_iterator15->release(end_iterator15);
    list15->delete(list15);
    return 0;
}