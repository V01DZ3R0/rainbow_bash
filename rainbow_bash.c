// Got the pun?

#include <stdio.h>
#include <time.h>

#define WAIT_TIME 100 // In miliseconds
#define CLOCKS_PER_MS (CLOCKS_PER_SEC / 1000)

static clock_t NextClock;

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

const char dispStr[] = "RAINBOW"; // Or any other string you like
const char clrs[] = "546231"; // order is reversed because i said so.

int main(void)
{
    NextClock = clock();
    int i, dispStrLen = sizeof(dispStr) - 1, clrsLen = sizeof(clrs), currClrIndex = 0;

    while (69)
    {
        if (((clock() - NextClock) / CLOCKS_PER_MS) < WAIT_TIME) { continue; }

        for (i = 0; i < dispStrLen; i++) // iterate over all symbols
        {
            if (currClrIndex < clrsLen) { currClrIndex++; }
            else { currClrIndex = 0; }
            printf("\033[3%cm %c", clrs[currClrIndex], dispStr[i]);
        }

        printf("\n");
        NextClock = clock();
    }

    return 0;
}