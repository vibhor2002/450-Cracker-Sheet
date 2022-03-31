// Method 3
// Compare in pairs

// Time Complexity: O(n)

#include <iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    if (n % 2 == 0)
    {
        if (arr[0] < arr[1])
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        else
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }

        i = 2;
    }
    else
    {
        minmax.max = arr[0];
        minmax.min = arr[0];

        i = 1;
    }

    while (i < n - 1)
    {

        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }
            if (arr[i+1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i+1] > minmax.max)
            {
                minmax.max = arr[i+1];
            }
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
        }
        i=i+2;
    }

    return minmax;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    struct Pair minmax = getMinMax(arr, size);

    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;

    return 0;
}
