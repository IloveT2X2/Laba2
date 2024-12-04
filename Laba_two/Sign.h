#ifndef SIGN
#define SIGN
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Sign
{
public:

	Sign();
	Sign(const Sign& sg);
	~Sign();

	void input();
	void output() const;

	string getLastName();
	string getFirstName();
	string getZodiacSign();
	int* getBirthDay();

	friend istream& operator>>(istream& is, Sign& sign);
	friend ostream& operator<<(ostream& os, const Sign& sign);

	bool operator<(const Sign& other) const;

private:

	string firstName;
	string lastName;
	string zodiacSign;
	int birthday[3];
};
#endif SIGN
