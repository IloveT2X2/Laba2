#include "Sign.h"

Sign::Sign()
{
	string firstNam = "";
	string lastName = "";
	string zodiacSign = "";
	int birthday[3] = { 0 };
}

Sign::Sign(const Sign& sg)
{
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
}

void Sign::input()
{
    cout << "¬ведите фамилию: ";
    cin >> lastName;

    cout << "¬ведите им€: ";
    cin >> firstName;

    cout << "¬ведите знак зодиака: ";
    cin >> zodiacSign;

    cout << "¬ведите день рождени€: ";
    cin >> birthday[0];

    cout << "¬ведите мес€ц рождени€: ";
    cin >> birthday[1];

    cout << "¬ведите год рождени€: ";
    cin >> birthday[2];
}

void Sign::output() const
{
    cout << "‘амили€: " << lastName << ", »м€: " << firstName;
    cout << "«нак зодиака: " << zodiacSign;
    cout << "ƒата рождени€: " << birthday[0] << "." << birthday[1] << "." << birthday[2] << endl;
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
