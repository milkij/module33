#include <iostream>

using namespace std;

//no class
template<typename T>
T avg(T arr[8])
{
    T result=0;
    for (int i=0; i<8; ++i)
    {
        result+=arr[i];
    }
    return result/8;
}

template<typename T>
void setArr(T arr[8])
{
    cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        T value;
        cout << "Input " << i+1 << "value: ";
        cin >> value;
        arr[i]=value;
    }
}
int main()
{
    int arr[8];
    setArr(arr);
    cout << "AVG is " << avg(arr);
}