#include <stdio.h>
#include <string.h>

// Good explanations for printf with color:
// https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
// https://c-for-dummies.com/blog/?p=5270

// foreground: red, background: yellow
#define RED_ON_YELLOW   "\x1B[31;43m"

#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
//#define RESET "\x1B[0m"

//             CODE F;Bm
#define RESET "\x1b[0;0m"




int main()
{
    printf("\033[0;31m"); //Set the text to the color red
    printf("Hello\n"); //Display Hello in red
    printf("\033[0m"); //Resets the text to default color

    printf(RED_ON_YELLOW "red text with yellow background\n"     RESET);
    printf(GRN "green\n"   RESET);
    printf(YEL "yellow\n"  RESET);
    printf(BLU "blue\n"    RESET);
    printf(MAG "magenta\n" RESET);
    printf(CYN "cyan\n"    RESET);
    printf(WHT "white\n"   RESET);

    char zk[500];
    strcat(zk, "\x1B[32;47m");
    strcat(zk, "#");
    strcat(zk, "\x1B[32;47m");
    strcat(zk, "#");
    strcat(zk, "\x1B[32;47m");
    strcat(zk, "#");
    strcat(zk, "\x1B[0;0m" );


    printf("zk = %s\n", zk);


}