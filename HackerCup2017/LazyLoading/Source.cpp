#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <algorithm>

int length = 11;
int items[101];
int taken[101];

int recu(int index, int left)
{
    if (left == 0)
    {
        return 0;
    }

    if (index >= length) {
        return 0; // TODO: Review if it is ok that the left items will need to be added to any of the other bags.
    }

    int bags = 0;
    int needed = (50 + items[index] - 1) / items[index];
    if (left >= needed)
    {
        return std::max(
            recu(index + 1, left - needed) + 1,
            recu(index + 1, left));
    }

    return recu(index + 1, left);
}

int solveDay()
{
    scanf("%d", &length);
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &items[i]);
    }

    return recu(0, length);
}

int main()
{
    int days;
    scanf("%d", &days);

    for (int i = 1; i <= days; i++)
    {
        auto result = 1;
        printf("Case #%d: %d\n", i, solveDay());
    }

    return 0;
}
