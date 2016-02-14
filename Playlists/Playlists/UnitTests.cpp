#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "Playlist.h"
#include "UnitTests.h"

UnitTests::UnitTests()
{
    // Use a static random seed to have predictable random results.
    std::srand(24);
};

void UnitTests::Verify(char* expected, Playlist& playlist)
{
    char output[101];
    const size_t length = sizeof(output) - 1;

    playlist.Stringify(output, length);

    printf("Expected: %s\r\n", expected);
    printf("Result:   %s\r\n", output);
    if (strcmp(expected, output) == 0)
    {
        succeeded++;
        printf("OK\r\n");
    }
    else
    {
        failed++;
        printf("FAIL\r\n");
    }
    printf("\r\n");
}

void UnitTests::PrintSummary()
{
    printf("Summary: %d succeeded and %d failed.\r\n", succeeded, failed);
}

int UnitTests::succeeded = 0;
int UnitTests::failed = 0;
