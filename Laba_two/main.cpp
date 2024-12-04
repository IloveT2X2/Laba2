#include <iostream>
#include <mutex>
#include <thread>
#include "Sign.h"

using namespace std;

void bubbleSort(Sign* signs, int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (signs[j] < signs[j + 1]) 
            {
                swap(signs[j], signs[j + 1]);
            }
        }
    }
}

int main()
{
	setlocale(LC_ALL, "Rus");
    int n;

    cout << "Введите количество записей: ";
    cin >> n;

    Sign* signs = new Sign[n];

    for (int i = 0; i < n; ++i) 
    {
        cout << "Запись " << i + 1 << endl;
        signs[i].input();
    }

    cout << "\nДанные:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        signs[i].output();
    }
    
    bubbleSort(signs, n);

    cout << "\nДанные отсортированы по дате рождения:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        signs[i].output();
    }

    delete[] signs;
	
	return 0;
}