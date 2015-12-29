#pragma once

class UnitTests
{
public:
    UnitTests();
    void Verify(char* expected, Playlist& playlist);
    static void PrintSummary();

private:
    static int succeeded;
    static int failed;
};
