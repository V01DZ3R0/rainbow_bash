//Got the pun?

#include <stdio.h>
// #include <string.h> // for strlen, coz sizeof()-1 does not work here
#include <time.h> //for nanosleep
int main(void)
{

    int i, j, k, l;

    struct timespec wait = {0, 1000000}, left; //delay time is set in nano-seconds, variable "left" is useless
                                               /*
   colors

   order of color like in rainbow -- it's number in  \033[3Xm  (instead of X)
                                1 -- 1
                                2 -- 3
                                3 -- 2
                                4 -- 6
                                5 -- 4
                                6 -- 5    
    */

    /*
    //string input - needs fixin'
    char clr[] = "132645";
    printf("Write your string to rainbownize:\n");
    char input_str[100];
     scanf("%s", input_str);
     char str[strlen(input_str)];

     strcpy(str,input_str);

     */

    char str[] = "RAINBOW";

    char clr[] = "546231"; //order is reversed because i said so.
    while (69)
    {
        j = sizeof(str) - 1;
        l = sizeof(clr) - 1;
        for (k = 0; k < l; k++) //iterate over all colors
        {

            for (i = 0; i < j; i++) //iterate over all letters
            {
                if (i + k >= l)
                {
                    printf("\033[3%cm %c", clr[i + k - l], str[i]);
                    continue;
                }
                printf("\033[3%cm %c", clr[i + k], str[i]);
            }
            nanosleep(&wait, &left);
            printf("\r");
        }
    }

    printf("\n");

    //ннада добавить вощще обнуление этих цветов ибаных
    return 0;
}

void cycle() //тут "бесконечность" без обнуления двух размеров (текста и параметра) работает, а у выше нет, ннада пофиксить
{
    int i, j, k;

    char test[] = " A B C D E F G";

    j = sizeof(test) - 1;

    for (k = 0; k <= j; k++) // меньше или равно (<=) только чтобы выводил изначальную строчку и доказывал возможность бесконечного прогона цикла и его блять красоту!
    {
        for (i = 0; i < j; i++)
        {
            if (i + k >= j)
            {
                printf("%c", test[i + k - j]);
                continue;
            }
            printf("%c", test[i + k]);
        }
        printf("\n");
    }
}