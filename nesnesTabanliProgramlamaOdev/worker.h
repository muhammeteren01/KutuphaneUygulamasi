#include <iostream>
#include <string>
#include <map>
#include "IOperations.h"

using namespace std;


class worker :public IOperations
{
public:
	virtual map<string, string> add(map<string, string>)override;
	virtual map<string, string> update(map<string, string>)override;
	virtual map<string, string> remove(map<string, string>)override;
	virtual void printAll(map<string, string>)override;
	virtual void printOne(map<string, string>)override;
};

map<string, string> worker::add(map<string, string>workers) {
	string firstNameAndLastName, workerID, emptyException;

	try
	{
		cout << "�al��an�n ad� ve soyad�n� giriniz : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, firstNameAndLastName);
		if (firstNameAndLastName == "")
			throw emptyException;

		workerID = to_string(100000 + (rand() % 999999));

		workers.insert(pair<string, string>(workerID, firstNameAndLastName));
		return workers;

	}
	catch (string emptyException)
	{
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	return workers;
}

map<string, string> worker::remove(map<string, string>workers) {
	string workerID, emptyException;
	int noFoundException = 1;

	try {
		cout << "Silmek istedi�iniz �al��an�n id sini giriniz : ";
		cin >> workerID;

		if (workerID == "")
			throw emptyException;

		if (workers[workerID] == "")
			throw noFoundException;

		workers.erase(workerID);
		return workers;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
	return workers;
}

map<string, string> worker::update(map<string, string>workers) {
	string workerID1, workerID2, firstNameAndLastName, emptyException;
	int noFoundException = 1;

	try {
		cout << "G�ncellemek istedi�iniz �al��an�n id sini giriniz : ";
		cin >> workerID1;

		if (workerID1 == "")
			throw emptyException;

		if (workers[workerID1] == "")
			throw noFoundException;

		cout << "Yeni id yi giriniz : ";
		cin >> workerID2;
		
		if (workerID2 == "")
			throw emptyException;

		cout << "Yeni �al��an�n ad�n� ve soyad�n� giriniz : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, firstNameAndLastName);
		
		if (firstNameAndLastName == "")
			throw emptyException;

		workers.erase(workerID1);

		workers.insert(pair<string, string>(workerID2, firstNameAndLastName));
		return workers;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
	return workers;
}

void worker::printOne(map<string, string>workers) {
	string workerID, emptyException;
	int noFoundException = 1;

	try {
		cout << "Bulmak istedi�iniz �al��an�n id sini giriniz";
		cin >> workerID;

		if (workerID == "")
			throw emptyException;

		if (workers[workerID] == "")
			throw noFoundException;

		cout << "ID      |     �al��an Ad�" << endl;
		cout << workers[workerID] << endl;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
}

void worker::printAll(map<string, string>workers) {
	map<string, string>::iterator itr;

	cout << "ID      |     �al��an Ad�" << endl;

	for (itr = workers.begin(); itr != workers.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}