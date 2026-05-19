#include <stdlib.h>

int main(void) {
    system("rm -rf ./compiled/program");
    system("gcc source/main.c -o ./compiled/program $(pkg-config --cflags --libs gtk+-3.0)");
    system("./compiled/program");
    return 0;
}