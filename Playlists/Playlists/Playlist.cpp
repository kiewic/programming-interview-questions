#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include "Playlist.h"

Playlist::Playlist() :
    head(nullptr),
    tail(nullptr),
    playing(nullptr)
{
}

Playlist::~Playlist()
{
    Dispose();
}

int Playlist::Create(int n)
{
    Dispose();

    for (int i = 1; i <= n; i++)
    {
        Node* temp = new Node();
        if (!temp)
        {
            return ErrorOutOfMemory;
        }

        temp->Number = i;
        temp->Next = nullptr;

        if (tail == nullptr)
        {
            head = temp;
        }
        else
        {
            tail->Next = temp;
        }

        tail = temp;
    }

    return 0;
}

int Playlist::Delete(int position)
{
    if (this->head == nullptr)
    {
        return ErrorOutOfIndex;
    }

    Node* temp = nullptr;

    if (position == 1)
    {
        temp = this->head;
        this->head = this->head->Next;
        delete temp;
        return 0;
    }

    Node* current = this->head;
    for (int i = 2; i < position; i++)
    {
        if (current == nullptr)
        {
            return ErrorOutOfIndex;
        }

        current = current->Next;
    }

    if (current->Next != nullptr)
    {
        temp = current->Next;
        current->Next = current->Next->Next;
        delete temp;
        return 0;
    }

    return ErrorOutOfIndex;
}

int Playlist::Insert(int position, int n)
{
    Node* temp = new Node;
    temp->Number = n;

    if (this->head == nullptr || position == 1)
    {
        temp->Next = head;
        head = temp;

        if (tail == nullptr)
        {
            tail = temp;
        }

        return 0;
    }

    Node* current = head;
    for (int i = 2; i < position; i++)
    {
        if (current->Next != nullptr)
        {
            current = current->Next;
        }
    }

    temp->Next = current->Next;
    current->Next = temp;

    if (current->Next->Next == nullptr)
    {
        tail == current->Next;
    }

    return 0;
}

int Playlist::Shuffle()
{
    int count = Count();

    if (this->playing)
    {
        count--;
    }

    if (count <= 1)
    {
        // There is nothing to sort.
        return 0;
    }

    // Use an array to keep the algorithm linear. Otherwise, it could
    // be necessary to go through the list multiple times.
    Track* tracks = new Track[count + 1];

    int index = 1;
    Node* current = this->head;
    while (current)
    {
        if (current != this->playing)
        {
            tracks[index++] = current->Number;
        }

        current = current->Next;
    }


    while (index > 1)
    {
        int randomIndex = Random(--index);
        Track temp = tracks[randomIndex];
        tracks[randomIndex] = tracks[index]; // Move the last track to the front.
        tracks[index] = temp; // Move the randomIndex track to the back.
    }

    index = 1;
    current = head;
    while (current)
    {
        if (current != this->playing)
        {
            current->Number = tracks[index++];
        }

        current = current->Next;
    }

    // TODO: Use auto_ptr
    delete[] tracks;

    return 0;
}

int Playlist::Play(int position)
{
    int index = 1;
    Node* current = this->head;
    while (current)
    {
        if (index == position)
        {
            this->playing = current;
            return 0;
        }

        current = current->Next;
        index++;
    }

    return ErrorOutOfIndex;
}

int Playlist::Stringify(char* output, size_t length)
{
    size_t charsWritten = 0;
    bool addComma = false;
    int index = 1;
    Node* current = head;

    charsWritten += sprintf_s(output, length, "");

    while (current != nullptr)
    {
        if (addComma)
        {
            charsWritten += sprintf_s(output + charsWritten, length - charsWritten, ",");
        }
        else
        {
            addComma = true;
        }

        charsWritten += sprintf_s(output + charsWritten, length - charsWritten, "%d", current->Number);

        if (current == playing)
        {
            charsWritten += sprintf_s(output + charsWritten, length - charsWritten, "*", current->Number);
        }

        current = current->Next;
        index++;
    }

    return charsWritten;
}

void Playlist::Print()
{
    char output[501];
    const size_t length = sizeof(output) - 1;

    Stringify(output, length);
    printf("%s\r\n", output);
}

int Playlist::Count()
{
    int count = 0;

    Node* current = this->head;
    while (current)
    {
        count++;
        current = current->Next;
    }

    return count;
}

int Playlist::Random(int maxNumber)
{
    return std::rand() % maxNumber + 1;
}

void Playlist::Dispose()
{
    Node* current = this->head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->Next;
        delete temp;
    }

    this->head = this->tail = this->playing = nullptr;
}
