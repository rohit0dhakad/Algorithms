#include <iostream>
#include <cmath>
using namespace std;

void count_sort(int array[], int divisor, int Size)
{
    int output[Size];
    int arr[10] = {0};
    for (int l = 0; l < Size; l++)
    {
        arr[(array[l] / divisor) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        arr[i] += arr[i - 1];
    }
    for (int k = Size - 1; k >= 0; k--)
    {
        output[arr[(array[k] / divisor) % 10] - 1] = array[k];
        arr[(array[k] / divisor) % 10]--;
    }
    for (int j = 0; j < Size; j++)
        array[j] = output[j];
}
void redix_sort(int array[], int Max, int Size)
{
    int count = 1;
    int divisor;
    while (Max > 10)
    {
        Max = Max / 10;
        count++;
    }
    cout<<"Count is: "<<count<<endl;
    for (int i = 0; i <count; i++)
    {
        divisor = pow(10, i);
        count_sort(array, divisor, Size);
    }
    
}
int main()
{
    int Size;
    cout << "\nEnter Number of Element(Size)in Array : ";
    cin >> Size;
    int array[Size];
    cout << endl;
    for (int k = 0; k < Size; k++)
    {
        int value;
        cout << "Enter Array's " << k + 1 << " Element : ";
        cin >> value;
        array[k] = value;
    }
    int Max = array[0];
    for (int j = 0; Size >= j; j++)
    {
        if (Max < array[j])
        {
            Max = array[j];
        }
    }
    cout<<"Max is: "<<Max<<endl;
    redix_sort(array, Max, Size);

    cout << "\nArray is : ";
    for (int i = 0; i < Size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}