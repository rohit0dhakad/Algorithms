#include <iostream>
using namespace std;
void buildheap(int arr[], int n, int current_i)
{   int left=2*current_i-1;
    int right=2*current_i;
    int parent=current_i-1;
    if (current_i > 0)
    {

        if ((arr[left] > arr[right]) && (arr[parent] < arr[left]))
        {
            swap(arr[parent], arr[left]);
        }
        if ((arr[right] > arr[left]) && (arr[parent] < arr[right]))
        {
            swap(arr[parent], arr[right]);
        }
        if (right < n && arr[parent] < arr[left])
        {
            swap(arr[parent], arr[left]);
        }
        buildheap(arr, n, current_i-1);
    }
}
void heapcheck(int arr[], int n)
{
    int current_i = n / 2;
    for (int i = n/2; i >=0; i--)
    {
        buildheap(arr, n, current_i);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapcheck(arr,(i-1));
    }
}
int main()
{
    int n = 7;

    int arr[7] = {2, 3, 6, 8, 4, 7, 5};
    for (int i = 0; i < n; i++)
        cout << " " << arr[i] << " ";
    cout << endl;
    heapcheck(arr, n);
    cout << "Heap array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
    cout << endl;

    heapsort(arr, n);
    cout << "Sorted Heap array: \n";
    for (int i = 0; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
