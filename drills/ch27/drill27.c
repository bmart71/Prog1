#include <stdio.h>

void print_val(char* p, int x){
    printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
    char* hel = "Hello";
    char* wor = "World";

    printf("Hello World!\n");
    printf("%s %s!\n", hel, wor);

    int age = 80;
    char* name = "foo";

    print_val(name, age);
    print_val("Geoffrey", 22);
    return 0;
}