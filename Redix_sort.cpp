#include <iostream>
using namespace std;

void Redix(int array[], int digit, int size)
{
    int new_Array[10] = {0};
    int divisor = pow(10,digit);
    for (int j = 0; j < size; j++)
    {
        // int x = array[j] / pow(10, digit);
        // int y = x % 10;
        // cout << y << " ";
        new_Array[(array[j]/ divisor) % 10]++;
        // cout<<new_Array[j];
    }
    // cout << endl;
    for(int l=1;l<10;l++){
        new_Array[l]+=new_Array[l-1];
        // cout<<new_Array[l];
    }
    // cout << "Array  : ";
    // for (int j = 0; j < 10; j++)
    // {
    //     cout << new_Array[j] << " ";
    // }
    // cout<<endl;
    int sorted[size];
    for(int i=size-1;i>=0;i--){
        int index=new_Array[(array[i]/divisor)%10]-1;
        sorted[index]=array[i];
        new_Array[(array[i]/divisor)%10]--;
    }
    // cout << "Array  : ";
    for (int j = 0; j < size; j++)
    {
        array[j]=sorted[j];
    }
    cout<<endl;
}

int main()
{
    int n;
    cout << "Number of Elements in arrey : ";
    cin >> n;
    int array[n];
    int values;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " Element : ";
        cin >> values;
        array[i] = values;
    };
    // For MAX Elememt in Array
    int max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    cout << "Max Element is : " << max << endl;

    // For No. of Digits in Max Elelment
    int count = 0;
    while (max != 0)
    {
        max = max / 10;
        count++;
    };
    cout << "No. of Digits in Max Elelment : " << count << endl;

    // For Redix Sort
    for (int k = 0; k < count; k++)
    {
        Redix(array, k, n);
    }

    // For Print Array
    cout << "Array  : ";
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << " ";
    }
}