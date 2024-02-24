#include <iostream>
using namespace std;
int portion(int array[], int start, int end)
{
    int pivot = array[end];
    int i = (start - 1);
    for (int j = start; j < end; j++)
    {
        if (pivot > array[j])
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return (i + 1);
}
void quicksort(int array[], int start, int end)
{
    if (start < end)
    {
        int p = portion(array, start, end);
        quicksort(array, start, p - 1);
        quicksort(array, p + 1, end);
    }
}
int main()
{
    int Size;
    cout << "\nEnter Number of Element(Size)in Array : " ;
    cin >> Size;
    int array[Size];
    cout<<endl;
    for (int k = 0; k < Size; k++)
    {
        int value;
        cout << "Enter Array's "<<k+1<<" Element : " ;
        cin >> value;
        array[k] = value;
    }

    cout << "\nArray is : " ;
    for (int i = 0; i < Size; i++)
    {
        cout << array[i] << " ";
    }cout <<endl;
    quicksort(array, 0, Size - 1);
    cout << "\nNew Sorted Array : " ;
    for (int i = 0; i < Size; i++)
    {
        cout << array[i] << " ";
    }
}