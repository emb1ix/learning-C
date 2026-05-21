#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char commit_message[512];
    char command[1024];

    printf("Enter commit message: ");

    fgets(commit_message, sizeof(commit_message), stdin); // Gets the git-push message
    commit_message[strcspn(commit_message, "\n")] = '\0'; // Removes \n from git-push command
    snprintf(command, sizeof(command), "git commit -m \"%s\"", commit_message); // Writes the actual command for use later


    // Runs the git-push commands
    system("git add .");
    system(command);
    system("git push -u origin main");


    printf("\n\nPushed!\n");
    return 0;
}