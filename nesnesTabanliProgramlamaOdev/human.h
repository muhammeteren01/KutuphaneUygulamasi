#include <map>
#include <iostream>

using namespace std;

class human
{
	string firstName, lastName;
public:
	human() {};
	human(string,string);
};

human::human(string firstName,string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}