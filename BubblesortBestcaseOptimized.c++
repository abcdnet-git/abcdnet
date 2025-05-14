#include <bits/stdc++.h>

using namespace std;

void bubblesort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
        cout << "runs" << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter Array Size" << "\n";
    cin >> n;

    int arr[n];

    cout << "Enter Array Elements: ", "\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubblesort(arr, n);

    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
}
