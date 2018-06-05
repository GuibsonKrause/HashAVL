#include "file.h"

int main()
{
    clock_t time;
    float hour, minute, second;

    time = clock();

    run(); /*The whole logical part of the job.*/

    second = (clock() - time) / (double)CLOCKS_PER_SEC;
    minute = second / 60;
    hour = minute / 60;
    printf("\nTime: %.3f seconds\n", second);
    printf("Time: %.2f minutes\n", minute);
    printf("Time: %.4f hours\n", hour);

    return 0;
}

