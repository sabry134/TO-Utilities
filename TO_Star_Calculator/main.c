#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char const *help_str = "-h";

    if (argc == 2 && strcmp(help_str, argv[1]) == 0) {
        help();
        return (0);
    } else if (argc == 1) {
        write(2, "You must add arguments\n", 24);
        exit (84);
    } else {
        calculator(argc, argv);
    }
}


void help(void)
{
    write(1, "USAGE          Click on run -> Add the arguments in the text box below\n\n", 73);
    write(1, "Arguments = [Number of Stars] [Number of days left before the challenge ends] [-p]\n\n", 84);
    write(1, "The -p option is the premium simulation, to enable this mode, just add `-p` at the end of the arguments\n", 105);
}

void calculator(int argc, char **argv)
{
    if ((argc != 3) && (argc != 4)) {
        printf("Invalid arguments\n");
        exit(84);
    }
    int stars = atoi(argv[1]);
    int days = atoi(argv[2]);
    char const *premium = "-p";
    if (argc == 4 && strcmp(premium, argv[3]) == 0) {
        premium_mode(stars, days);
        return (0);
    }
    error_handling(stars, days);
    calculator_mode(stars, days);
}

int error_handling(int stars, int days)
{
    if (stars >= 3000) {
        printf("You have finished the challenge\n");
    }
    if (stars < 0) {
        printf("Invalid Number of stars\n");
    }
    if (days < 0 || days > 15) {
        printf("Invalid number of days\n");
    }
}

void premium_mode(int stars, int days)
{
    float percentage = stars;
    float step1 = (percentage / 3000) * 100;
    days = 15 - days;
    stars = 3000 - stars;
    double stars_to_do = stars;
    double days_to_do = days;
    double result = stars_to_do / days_to_do;
    printf("Percentage achieved: %.2f%\n", step1);
    printf("Number of days left: %d\n", days);
    printf("Number of stars left: %d\n", stars);
    printf("Stars to do per day: %.0f\n", result);
    printf("With premium mode: From 2 to 6 stars available per battle\n");
}

int calculator_mode(int stars, int days)
{
    float percentage = stars;
    float step1 = (percentage / 3000) * 100;
    days = 15 - days;
    stars = 3000 - stars;
    double stars_to_do = stars;
    double days_to_do = days;
    double result = stars_to_do / days_to_do;
    printf("Percentage achieved: %.2f%\n", step1);
    printf("Number of days left: %d\n", days);
    printf("Number of stars left: %d\n", stars);
    printf("Stars to do per day: %.0f\n", result);
    printf("Without premium mode: From 1 to 3 stars available per battle\n");
}