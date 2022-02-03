#include <stdio.h>
#include "exception.h"

// RegisterExceptions()

void bar()
{
    throw(TestException, "Ooops, il y a eu une erreur");
    puts("Bar");
}

void foo()
{
    throw(Exception, "Ooops, il y a eu une erreur");
    puts("Foo");
}

int main(int argc, char **argv)
{
    // RegisterException(OtherException);
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
    puts("After second try catch");
    return 0;
}