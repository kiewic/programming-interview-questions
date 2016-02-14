#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "Playlist.h"
#include "UnitTests.h"

void RunUnitTests()
{
    std::srand(std::time(0));

    UnitTests unitTests;

    {
        // Empty playlist.
        Playlist playlist;
        unitTests.Verify("", playlist);
    }

    {
        // Stringify of lists with two digits elements.
        Playlist playlist;
        playlist.Create(11);
        unitTests.Verify("1,2,3,4,5,6,7,8,9,10,11", playlist);
    }

    {
        Playlist playlist;
        playlist.Create(5);
        unitTests.Verify("1,2,3,4,5", playlist);

        // Delete an element in the middle of the playlist.
        playlist.Delete(2);
        unitTests.Verify("1,3,4,5", playlist);
    }

    {
        // Insert in the middle of the playlist.
        Playlist playlist;
        playlist.Create(5);
        playlist.Insert(2, 5);
        unitTests.Verify("1,5,2,3,4,5", playlist);
    }

    {
        // Play song in the middle of the playlist.
        Playlist playlist;
        playlist.Create(5);
        playlist.Play(2);
        unitTests.Verify("1,2*,3,4,5", playlist);

        // Change playing song.
        playlist.Play(3);
        unitTests.Verify("1,2,3*,4,5", playlist);

        // Reset playlist.
        playlist.Create(5);
        unitTests.Verify("1,2,3,4,5", playlist);
    }

    {
        // Delete track at the beginning of the playlist.
        Playlist playlist;
        playlist.Create(5);
        playlist.Play(3);
        playlist.Delete(1);
        unitTests.Verify("2,3*,4,5", playlist);

        // Delete track in the middle of the paylist.
        playlist.Delete(2);
        unitTests.Verify("2,4,5", playlist);
    }

    {
        Playlist playlist;
        playlist.Create(5);
        playlist.Play(3);
        playlist.Insert(3, 4);
        unitTests.Verify("1,2,4,3*,4,5", playlist);
    }

    {
        Playlist playlist;
        playlist.Create(5);

        // Delete the element at the beginning of the paylist.
        playlist.Delete(1);
        unitTests.Verify("2,3,4,5", playlist);

        // Delete the element at the end of the paylist.
        playlist.Delete(4);
        unitTests.Verify("2,3,4", playlist);

        // Insert an element at the beginning of the paylist.
        playlist.Insert(1, 6);
        unitTests.Verify("6,2,3,4", playlist);

        // Insert an element at the end of the paylist.
        playlist.Insert(5, 7);
        unitTests.Verify("6,2,3,4,7", playlist);

        // Insert in am empty playlist.
        playlist.Create(0);
        playlist.Insert(1, 1);
        unitTests.Verify("1", playlist);

        // Delete an element from a single element playlist.
        playlist.Delete(1);
        unitTests.Verify("", playlist);
    }

    {
        // Shuffle.
        Playlist playlist;
        playlist.Create(5);
        playlist.Shuffle();
        unitTests.Verify("4,3,1,5,2", playlist);
    }


    {
        // Shuffle and playing middle track.
        Playlist playlist;
        playlist.Create(9);
        playlist.Play(5);
        playlist.Shuffle();
        unitTests.Verify("2,9,7,6,5*,3,4,1,8", playlist);
    }

    {
        // Shuffle and playing first element.
        Playlist playlist;
        playlist.Create(5);
        playlist.Play(1);
        playlist.Shuffle();
        unitTests.Verify("1*,2,4,5,3", playlist);
    }

    {
        // Shuffle and playing last element.
        Playlist playlist;
        playlist.Create(5);
        playlist.Play(5);
        playlist.Shuffle();
        unitTests.Verify("2,4,1,3,5*", playlist);
    }

    {
        // Shuffle 1 element.
        Playlist playlist;
        playlist.Create(1);
        playlist.Shuffle();
        unitTests.Verify("1", playlist);
    }

    {
        // Shuffle 2 elements
        UnitTests unitTests;
        Playlist playlist;
        playlist.Create(2);
        playlist.Shuffle();
        unitTests.Verify("2,1", playlist);
    }

    {
        // Shuffle and playing 1 element.
        Playlist playlist;
        playlist.Create(1);
        playlist.Play(1);
        playlist.Shuffle();
        unitTests.Verify("1*", playlist);
    }

    unitTests.PrintSummary();
}

void PrintUsage()
{
    printf("Usage: playlists.exe [ test | help ]\r\n");
    printf("\r\n");
    printf("Options:\r\n");
    printf("    test    Runs unit tests.\r\n");
    printf("    help    Prints this help.\r\n");
    printf("    <none>  Runs interactive mode.\r\n");
    printf("\r\n");
    printf("Interactive mode commands:\r\n");
    printf("     create m\r\n");
    printf("     delete m\r\n");
    printf("     insert m x\r\n");
    printf("     shuffle\r\n");
    printf("     play m\r\n");
    printf("     exit\r\n");
    printf("\r\n");
}

void RunInteractiveMode()
{
    Playlist playlist;

    while (true)
    {
        printf("Type command ...\r\n");

        char input[100];
        scanf_s("%s", input, _countof(input));
        if (_stricmp(input, "create") == 0)
        {
            int m;
            scanf_s("%d", &m);
            playlist.Create(m);
            playlist.Print();
        }
        else if (_stricmp(input, "delete") == 0)
        {
            int m;
            scanf_s("%d", &m);
            playlist.Delete(m);
            playlist.Print();
        }
        else if (_stricmp(input, "insert") == 0)
        {
            int m;
            int x;
            scanf_s("%d %d", &m, &x);
            playlist.Insert(m, x);
            playlist.Print();
        }
        else if (_stricmp(input, "shuffle") == 0)
        {
            playlist.Shuffle();
            playlist.Print();
        }
        else if (_stricmp(input, "play") == 0)
        {
            int m;
            scanf_s("%d", &m);
            playlist.Play(m);
            playlist.Print();
        }
        else if (_stricmp(input, "exit") == 0)
        {
            return;
        }
        else
        {
            PrintUsage();
        }

    }
}

int main(int argc, char* argv[])
{
    char* option = "";
    if (argc >= 2)
    {
        option = argv[1];
    }

    if (_stricmp(option, "/?") == 0 || _stricmp(option, "-h") == 0 || _stricmp(option, "help") == 0)
    {
        PrintUsage();
    }
    else if (_stricmp(option, "test") == 0)
    {
        RunUnitTests();
    }
    else
    {
        RunInteractiveMode();
    }

    return 0;
}

