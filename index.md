## Tanki Fund Tracker

A convenient tool made with Python using the Plotly and Streamlit libraries to track Tanki Funds over time.

Provides the following analytics:
- At-a-glance stats: Current Fund, Recent Fund Growth, Final Fund Estimates.
- Checkpoint Information: Next Checkpoint, Final Checkpoint, Time to Next Checkpoint.
- Daily Fund changes in a table.
- Hourly and overall plots for the Tanki Fund.

### More Information

Fund estimates are made with multiple linear regression on the elapsed time. Features were chosen as follows:
- `Fund["Days"]`: primary source of information. When used alone, it creates a linear prediction.
- `Fund["Days (Log)"]`: used to account for the fast growth towards the beginning of the fund. A logarithmic graph grows quickly at first, then slows down, similar to the Tanki Fund - initial hype makes the fund grow quickly, but then the fund evens out over time.
- `Fund["Days^2"]`: used to account for the fast fund growth rate towards the end. This is similar to the logarithmic feature, but the rate of growth is slower.

Checkpoint Estimates are made with (modified) Newton's method. We have a smooth prediction graph that is mostly accurate from the linear model above; now let's put it to use here.

Newton's method works basically like this:
```python
def newton(f, df, p0, tol):
    # estimates the zero of the function using Newton's method within tol
    while True:
        p = p0 - f(p0) / df(p0) # fixed point iteration
        if abs(p - p0) <= tol:
            break
        p = p0
    return p
```
Since the regression model isn't easily differentiable, I used a modified method that generates similar results without `df`, the derivative of the function. Putting it all together, running (modified) Newton's method with a shift to account for the next checkpoint gives us an accurate prediction of the time to reach the next checkpoint.

Interested in learning more and checking out the fund tracker for yourself? You can find the fund tracker [here](https://fund-vis-v2.herokuapp.com).

(Made by Person_Random)

## Tanki Star Calculator Algorithm

### What is a Challenge Star Calculator?

A challenge star calculator is a program which allows you to calculate the number of remaining stars you should get within the remaining days, along with an idea of the number of stars per day to earn. It is a C program which was built.

### How to use the Challenge Star Calculator?

First of all, click [here](https://www.onlinegdb.com/online_c_compiler).

It should look like this: ![Image](https://cdn.discordapp.com/attachments/609269720805408788/1004879401189642301/unknown.png)

Once you are here, you have to delete the code written on the page. Instead you'll have to replace it with this code:
```C
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
```

Once your code has been pasted on the website, you have to write arguments, here's how it has to look like:

Argument 1 = Your current number of stars
Argument 2 = Number of days elapsed

Here's an example:
![Image](https://cdn.discordapp.com/attachments/609269720805408788/1004880872895414303/unknown.png)

In this example, my first argument is 200, which means I have 200 stars. My second argument is 12, which means there are 12 days elapsed.

### Planned changes/Work in progress

Here is a list of the planned changes in order to make it easier:

- Plan to make a website in order to implement this algorithm
- Simulator mode -> A simulator mode based on the most realistic statistics.
- Improve the statistics system


If you have any suggestion in order to help to improve the Challenge calculator, please contact [143] Sabry#5972

(Made by Sabry.Superman)
