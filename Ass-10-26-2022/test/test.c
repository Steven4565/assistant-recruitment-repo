#include <stdio.h>
#define lambda(lambda$_ret, lambda$_args, lambda$_body)\
({\
lambda$_ret lambda$__anon$ lambda$_args\
lambda$_body\
&amp;lambda$__anon$;\
})


int add(int n, int y) {
    return n + 5;
}

// this is a function called functionFactory which receives parameter n
// and returns a pointer to another function which receives two ints
// and it returns another int
int (*functionFactory(int n))(int, int) {
    printf("Got parameter %d", n);
    int (*functionPtr)(int,int) = &add;
    return functionPtr;
}
int main() {

    // int (*functionFactory(int n))(int, int)
    int (*fn)(int, int) = functionFactory(5)(5,5);

    return 0;
}