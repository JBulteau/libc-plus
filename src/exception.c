#include <stdio.h>
#include "exception.h"

RegisterException(OtherException)

void bar()
{
    puts("Bar");
}

void foo()
{
    throw(Exception, "Ooops, il y a eu une erreur");
    puts("Foo");
}

int main(int argc, char **argv)
{
    try {
        foo();
    } catch (Exception) {
        puts("Exception catched, continuing...");
    }
    puts("After first try catch");
    try {
        bar();
    } catch (Exception) {
        puts("Exception catched, continuing...");
    }

    throw(OtherException, "Toto");
    puts("After second try catch");
    return 0;
}