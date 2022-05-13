//drill27

/*
1. Write a “Hello, World!” program in C, compile it, and run it.
2. Define two variables holding “Hello” and “World!” respectively; concatenate them with a space in between; and output them as Hello World!.
3. Define a C function that takes a char* parameter p and an int parameter x and print out their values in this format: p is
"foo" and x is 7. Call it with a few argument pairs.*/

//gcc drill27.c -o drill27

#include <stdlib.h>
#include <stdio.h>

void print_out(const char* p, const int x)
{
    printf("p is\"%s\" and x is %i\n", p, x);
}

int main()
{
    //1.
    printf("Hello World!\n");

    //2.
    char* first = "Hello";
    char* last = "World!";
    
    printf("%s %s\n", first, last); 

    //3.
    print_out("May", 6);
    print_out("Chris", 39);
    print_out("C", 89);
    return 0;
}
