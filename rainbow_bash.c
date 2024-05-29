// Got the pun?

#include <stdio.h>
#include <time.h> //for nanosleep
int main(void)
{

    int i, j, k, l;

    struct timespec wait = {0, 100000000}, left; // delay time is set in nano-seconds, variable "left" is useless

    /*
   colors
   order of color like in rainbow -- its' number in  \033[3Xm  (instead of X)
                                1 -- 1
                                2 -- 3
                                3 -- 2
                                4 -- 6
                                5 -- 4
                                6 -- 5
     */

    char str[] = "RAINBOW"; // Or any other string you like

    char clr[] = "546231"; // order is reversed because i said so.
    while (69)
    {
        j = sizeof(str) - 1;
        l = sizeof(clr) - 1;
        for (k = 0; k < l; k++) // iterate over all colors
        {

            for (i = 0; i < j; i++) // iterate over all letters
            {
                if (i + k >= l)
                {
                    printf("\033[3%cm %c", clr[i + k - l], str[i]);
                    continue;
                }
                printf("\033[3%cm %c", clr[i + k], str[i]);
            }
            nanosleep(&wait, &left);
            printf("\r\n");
        }
    }

    printf("\n");

    return 0;
}
