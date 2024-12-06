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
    int choice = 0;
    string ln;

    cout << "Введите количество записей: ";
    cin >> n;

    Sign* signs = new Sign[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Запись " << i + 1 << endl;
        signs[i].input();
    }


    for (; choice != 4;)
    {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести исходные данные на экран" << endl;
        cout << "2. Упорядочить данные по датам дней рождения" << endl;
        cout << "3. Вывести на экран информацию о человеке" << endl;
        cout << "4. Выход из программы" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Исходные данные:" << endl;
            for (int i = 0; i < n; ++i)
            {
                signs[i].output();
            }
            break;

        case 2:
            bubbleSort(signs, n);

            cout << "Данные, отсортированые по дате рождения: " << endl;
            for (int i = 0; i < n; ++i)
            {
                signs[i].output();
            }
            break;

        case 3:
            cout << "Введите фамилию человека" << endl;
            cin >> ln;

            for (int i = 0; i <= n; i++)
            {
                if (signs[i].getLastName() == ln)
                {
                    signs[i].output();
                    break;
                }
                if (i == n)
                {
                    cout << "Человека с такой фамилией нет\a" << endl;
                    break;
                }
            }
            break;

        case 4:
            break;

        default:
            cerr << "Некорректный выбор!\a" << endl;
            break;
        }
    }

    delete[] signs;
	
	return 0;
}