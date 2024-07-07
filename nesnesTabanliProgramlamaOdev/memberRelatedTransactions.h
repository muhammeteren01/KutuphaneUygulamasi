#include <iostream>
#include <string>
#include <map>
#include "IOperations.h"

using namespace std;


class memberRelatedTransactions : public IOperations
{
public:
	virtual map<string, string> add(map<string, string>)override;
	virtual map<string, string> update(map<string, string>)override;
	virtual map<string, string> remove(map<string, string>)override;
	virtual void printAll(map<string, string>)override;
	virtual void printOne(map<string, string>)override;
};

map<string, string> memberRelatedTransactions::add(map<string, string>members) {
	string firstNameAndLastName, memberID, emptyException;
	try
	{
		cout << "Üyenin adý ve soyadýný giriniz : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, firstNameAndLastName);

		if (firstNameAndLastName == "")
			throw emptyException;

		memberID = to_string(100000 + (rand() % 999999));

		members.insert(pair<string, string>(memberID, firstNameAndLastName));
		return members;
	}
	catch (string emptyException)
	{
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	return members;
}

map<string, string> memberRelatedTransactions::remove(map<string, string>members) {
	string memberID, emptyException;
	int noFoundException = 1;
	try {
		cout << "Silmek istediðiniz üyenin id sini giriniz : ";
		cin >> memberID;

		if (memberID == "")
			throw emptyException;

		if (members[memberID] == "")
			throw noFoundException;

		members.erase(memberID);
		return members;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip üye bulunamamýþtýr" << endl;
	}
	return members;
}

map<string, string> memberRelatedTransactions::update(map<string, string>members) {
	string memberID1, memberID2, firstNameAndLastName, emptyException;
	int noFoundException = 1;
	try {
		cout << "Güncellemek istediðiniz üyenin id sini giriniz : ";
		cin >> memberID1;

		if (memberID1 == "")
			throw emptyException;

		if (members[memberID1] == "")
			throw noFoundException;

		cout << "Yeni id yi giriniz : ";
		cin >> memberID2;

		cout << "Yeni üye adýný ve soyadýný  yi giriniz : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, firstNameAndLastName);

		if (firstNameAndLastName == "")
			throw emptyException;

		members.erase(memberID1);

		members.insert(pair<string, string>(memberID2, firstNameAndLastName));
		return members;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip üye bulunamamýþtýr" << endl;
	}
	return members;
}

void memberRelatedTransactions::printOne(map<string, string>members) {
	string memberID, emptyException;
	int noFoundException = 1;
	try {
		cout << "Bulmak istediðiniz üyenin id sini giriniz";
		cin >> memberID;

		if (memberID == "")
			throw emptyException;

		if (members[memberID] == "")
			throw noFoundException;

		cout << "ID    |     Üye Adi" << endl;
		cout << members[memberID] << endl;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip üye bulunamamýþtýr" << endl;
	}
}

void memberRelatedTransactions::printAll(map<string, string>members) {
	map<string, string>::iterator itr;

	cout << "ID    |     Üye Adi" << endl;

	for (itr = members.begin(); itr != members.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}