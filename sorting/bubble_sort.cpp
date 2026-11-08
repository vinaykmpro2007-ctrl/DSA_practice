#include <bits/stdc++.h>
using namespace std;

void bubblesort(int n, int arr[])
{
    int temp, swapped;

    for (int i = n - 1; i >= 1; i--)
    {
        swapped = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            cout << "Array is already sorted!\n";
            return;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubblesort(n, arr);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}