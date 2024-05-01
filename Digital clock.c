#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() 
{
    time_t currentTime;
    struct tm *localTime;
    while (1) 
    {
        // Get current time
        currentTime = time(NULL);
        localTime = localtime(&currentTime);

        // Display time in HH:MM:SS format
        printf("\r%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
        fflush(stdout);
        sleep(1);
    }
    return 0;
}
