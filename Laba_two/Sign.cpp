#include "Sign.h"

Sign::Sign()
{
    cout << "Вызван конструктор без параметров объекта класса Sign" << endl;

	string firstNam = "";
	string lastName = "";
	string zodiacSign = "";
	int birthday[3] = { 0 };
}

Sign::Sign(const Sign& sg)
{
    cout << "Вызван конструктор копирования объекта класса Sign" << endl;

    firstName = sg.firstName;
    lastName = sg.lastName;
    zodiacSign = sg.zodiacSign;
    for (int i = 0; i < 3; i++)
    {
        birthday[i] = sg.birthday[i];
    }
}

Sign::~Sign()
{
    cout << "Вызван деструктор объекта класса Sign" << endl;
}

void Sign::input()
{
    cout << "Введите фамилию: ";
    cin >> lastName;

    cout << "Введите имя: ";
    cin >> firstName;

    cout << "Введите знак зодиака: ";
    cin >> zodiacSign;

    cout << "Введите день рождения: ";
    cin >> birthday[0];

    cout << "Введите месяц рождения: ";
    cin >> birthday[1];

    cout << "Введите год рождения: ";
    cin >> birthday[2];
}

void Sign::output() const
{
    cout << "Фамилия: " << lastName << ", Имя: " << firstName;
    cout << "Знак зодиака: " << zodiacSign;
    cout << "Дата рождения: " << birthday[0] << "." << birthday[1] << "." << birthday[2] << endl;
}

string Sign::getLastName()
{
    return lastName;
}

string Sign::getFirstName()
{
    return firstName;
}

string Sign::getZodiacSign()
{
    return zodiacSign;
}

int* Sign::getBirthDay()
{
    return birthday;
}

bool Sign::operator<(const Sign& other) const
{
    if (birthday[2] != other.birthday[2]) 
    {
        return birthday[2] < other.birthday[2];
    }

    if (birthday[1] != other.birthday[1]) 
    {
        return birthday[1] < other.birthday[1];
    }

    return birthday[0] < other.birthday[0];
}

istream& operator>>(istream& is, Sign& sign)
{
    sign.input();
    return is;
}

ostream& operator<<(ostream& os, const Sign& sign)
{
    sign.output();
    return os;
}
