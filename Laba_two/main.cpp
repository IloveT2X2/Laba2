#include <iostream>
#include <fstream>
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

string findLongestWordAndCountOccurrences(ifstream& fin, const string& path) {
    fin.open(path);
    if (!fin.is_open()) 
    {
        cerr << "Не удалось открыть файл!" << endl;
        return "";
    }

    char ch;
    string longWord, word;
    int maxLength = 0;
    int maxCount = 0;

    while (fin.get(ch)) {
        if (isspace(ch) || ch == '\n') 
        {
            if (word.length() > maxLength) 
            {
                longWord = word;
                maxLength = word.length();
                maxCount = 1;
            }
            else if (word.length() == maxLength) 
            {
                if (word == longWord) 
                {
                    maxCount++;
                }
            }
            word = "";
        }
        else 
        {
            word += ch;
        }
    }

    if (!word.empty()) 
    {
        if (word.length() > maxLength) 
        {
            longWord = word;
            maxLength = word.length();
            maxCount = 1;
        }
        else if (word.length() == maxLength) 
        {
            if (word == longWord) 
            {
                maxCount++;
            }
        }
    }

    fin.close();

    cout << "Самое длинное слово: " << longWord << endl;
    cout << "Длина самого длинного слова: " << maxLength << endl;
    cout << "Количество вхождений этого слова: " << maxCount << endl;

    return longWord;
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
        cout << endl;
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

    choice = 0;
    string a;

    string path = "myFile.txt";

    ofstream fout;
    ifstream fin;

    for (; choice != 5;)
    {
        cout << endl;
        cout << "1. Ввести данные файл" << endl;
        cout << "2. Найти самое длинное слово и определить, сколько раз оно встретилось в тексте файла" << endl;
        cout << "3. Вывести данные на экран" << endl;
        cout << "4. Очистить данные" << endl;
        cout << "5. Выход из программы" << endl;

        cin >> choice;
        cin.ignore();

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода! Пожалуйста, введите число от 1 до 4." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            fout.open(path, ofstream::app);
            if (!fout.is_open()) 
            {
                cerr << "Не удалось открыть файл!" << endl;
                break;
            }

            cout << "Введите текст: ";
            getline(cin, a); 
            fout << a << "\n";
            cout << "Данные добавлены." << endl;

            fout.close();
            break;

        case 2:
            findLongestWordAndCountOccurrences(fin, path);
            break;

        case 3:
            fin.open(path);

            if (!fin.is_open())
            {
                cerr << "Не удалось открыть файл!" << endl;
                break;
            }

            char ch;
            while (!fin.eof())
            {
                if (fin.get(ch)) 
                { 
                cout << "Содержимое файла:" << endl;
                while (fin.get(ch))
                {
                     cout << ch;
                }
                } else 
                {
                    cerr << "Файл пуст!" << endl;
                }
            }
            fin.close();
            break;

        case 4:
            fout.open(path, ofstream::trunc);
            fout.close();

            cout << "Данные очищены." << endl;
            break;

        case 5:
            break;

        default:
            cout << "Неккоректные данные\a" << endl;
            cin.clear();
            break;
        }
    }

	return 0;
}