#include <stdio.h>
#include <time.h>

int main() {
    while (1) {
        // Get the current time
        time_t currentTime = time(NULL);
        struct tm *timeInfo = localtime(&currentTime);

        // Display the digital clock
        printf("%02d:%02d:%02d\r", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

        // Sleep for 1 second to update the clock
        sleep(1);
    }

    return 0;
}
