// Author: Gilberto Stankiewicz (hello@kiewic.com)
//
// Problem:
//
// Write a function that accepts a Unicode string and returns a string of characters that are duplicated.
//
// Solution:
//
// Sort the characters in the input string so repeated characters end on adjacent positions. Then, going through the
// array one more time is enough to find the repeated characters.
//
// Usage:
//
// `GetDuplicates.exe` executes a simple set of tests.
//
// `GetDuplicates.exe foo` finds the duplicated characters in `foo`.

#include <cstdio>
#include <cstring>
#include <memory>

void Swap(wchar_t* a, wchar_t* b)
{
    wchar_t temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort algorithm inner method.
int Partition(wchar_t* values, int low, int high)
{
    wchar_t pivot = values[high];
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (values[j] <= pivot)
        {
            Swap(&values[i], &values[j]);
            i++;
        }
    }
    Swap(&values[i], &values[high]);
    return i;
}

// QuickSort algorithm.
void QuickSort(wchar_t* values, int low, int high)
{
    if (low < high)
    {
        int i = Partition(values, low, high);
        QuickSort(values, low, i - 1);
        QuickSort(values, i + 1, high);
    }
}

void GetDuplicates(wchar_t* input, int inputLen, wchar_t* output, int outputLen)
{
    // Zero-length string cannot be sorted, and cannot have repeated characters.
    if (inputLen == 0)
    {
        output[0] = '\0';
        return;
    }

    // Make a copy of the input string that can be modified.
    std::unique_ptr<wchar_t []> inputCopy(new wchar_t[inputLen + 1]);
    if (!inputCopy.get())
    {
        // TODO: Return an out of memory error.
        return;
    }
    wcscpy_s(inputCopy.get(), inputLen + 1, input);

    // Sort Values.
    QuickSort(inputCopy.get(), 0, inputLen - 1);

    // Find repeated characters.
    wchar_t* data = inputCopy.get();
    for (int i = 0; i < inputLen;)
    {
        int j = i;

        while (data[i] == data[j])
        {
            i++;
        }

        if (i - j > 1)
        {
            swprintf(output, outputLen, L"%c", data[j]);
            output++;
            outputLen--;
        }
    }

    // Finish the output with a null character.
    output[0] = '\0';
}

void GetDuplicates(wchar_t* input)
{
    int inputLen = wcslen(input);

    // In the worst case, the output will be the half of the input length.
    int outputLen = inputLen / 2 + 1;
    std::unique_ptr<wchar_t []> output(new wchar_t[outputLen]);
    if (!output.get())
    {
        // TODO: Return an out of memory error.
        return;
    }

    GetDuplicates(input, inputLen, output.get(), outputLen);

    wprintf(L"Input:  %s\r\n", input);
    wprintf(L"Output: %s\r\n", output);
    wprintf(L"\r\n");
}


int wmain(int argc, wchar_t *argv [])
{
    if (argc >= 2)
    {
        GetDuplicates(argv[1]);
    }
    else
    {
        // Original example.
        GetDuplicates(L"AABCCDd");

        // Zero repeated characters.
        GetDuplicates(L"QWERTY");

        // One repeated character.
        GetDuplicates(L"Microsoft");

        // Two repeated characters.
        GetDuplicates(L"GOOGLE");

        // Three repeated characters.
        GetDuplicates(L"LOLAPALOOZA");

        // One character long string.
        GetDuplicates(L"A");

        // Character repeated three times.
        GetDuplicates(L"CBBBA");

        // Character repeated three times.
        GetDuplicates(L"CBBBA");

        // String with Unicode characters.
        GetDuplicates(L"\xF1o\xF1");
    }

    return 0;
}

