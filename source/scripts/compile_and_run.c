#include <stdlib.h>

int main(void) {
    system("rm -rf ./compiled/calculator");
    system("gcc source/main.c -o ./compiled/calculator $(pkg-config --cflags --libs gtk+-3.0)");
    system("./compiled/calculator");
    return 0;
}