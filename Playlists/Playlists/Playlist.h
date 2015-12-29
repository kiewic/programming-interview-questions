#pragma once

typedef int Track;
const Track NoTrack = -1;
const int ErrorOutOfMemory = 1;
const int ErrorOutOfIndex = 1;
const int ErrorElementNotFound = 1;

struct Node
{
    Track Number;
    Node* Next;
};

class Playlist
{
public:
    Playlist();
    ~Playlist();
    int Create(int n);
    int Delete(int position);
    int Insert(int position, int n);
    int Shuffle();
    int Play(int position);
    int Stringify(char* output, size_t length);
    void Print();

private:
    Node* head;
    Node* tail;
    Node* playing;

    int Count();
    int Random(int maxNumber);
    void Dispose();
};
