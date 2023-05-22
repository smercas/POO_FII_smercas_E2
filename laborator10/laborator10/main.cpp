#include <iostream>
#include "Array.h"

int main() {
    Compare* x;
    x = new CompareGreater<int>();

    Array<int> arr(5);
    arr.Insert(0, 8);
    arr.Insert(1, 4);
    arr += 2;
    arr.Delete(1);
    arr.Insert(2, 1);

    arr.Sort();
    arr.Sort(x);

    printf("Searching binary for 8: Index:%llu\n", arr.BinarySearch(8));
    for (auto it : arr)
    {
        printf("%d ", it);
    }
}
