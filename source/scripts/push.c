#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char commit_message[100];
    char command[200];

    printf("Enter commit message: ");

    fgets(commit_message, sizeof(commit_message), stdin);
    snprintf(command, sizeof(command), "git commit -m \"%s\"", commit_message);
    

    system("git add .");
    system(command);
    system("git push -u origin main");

    printf("\n\nPushed!\n");
    return 0;
}