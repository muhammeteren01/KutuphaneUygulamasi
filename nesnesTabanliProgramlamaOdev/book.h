#include <iostream>
#include <string>
#include <map>
#include "IOperations.h"

using namespace std;

class book : public IOperations
{
public:
	virtual map<string, string> add(map<string, string>)override;
	virtual map<string, string> update(map<string, string>)override;
	virtual map<string, string> remove(map<string, string>)override;
	virtual void printAll(map<string, string>)override;
	virtual void printOne(map<string, string>)override;
	void borrowedBooks(map<string, string>);
};

map<string, string> book::add(map<string, string>books) {
	string bookID = to_string(100000 + (rand() % 999999));
	string bookName, emptyException;

	try
	{
		cout << "Kitap adýný giriniz" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, bookName);

		if (bookName == "")
			throw emptyException;

		books.insert(pair<string, string>(bookID, bookName));
		return books;

	}
	catch (string emptyException)
	{
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	return books;
}

map<string, string> book::remove(map<string, string>books) {
	string id, emptyException;
	int noFoundException = 1;

	try
	{
		cout << "Silmek istediðiniz kitabýn id sini giriniz" << endl;
		cin >> id;

		if (id == "")
			throw emptyException;

		if (books[id] == "")
			throw noFoundException;

		books.erase(id);
		return books;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip kitap bulunamamýþtýr" << endl;
	}
	return books;
}

map<string, string> book::update(map<string, string>books) {
	string id, id2, bookName, emptyException;
	int noFoundException = 1;
	try
	{

		cout << "Güncellemek istediðiniz kitabýn id sini giriniz" << endl;
		cin >> id;

		if (id == "")
			throw emptyException;


		if (books[id] == "")
			throw noFoundException;

		cout << "Yeni id giriniz" << endl;
		cin >> id2;

		if (id2 == "")
			throw emptyException;

		cout << "Yeni kitap adini giriniz" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, bookName);

		if (bookName == "")
			throw emptyException;

		books.erase(id);

		books.insert(pair<string, string>(id2, bookName));
		return books;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip kitap bulunamamýþtýr" << endl;
	}
	return books;
}

void book::printOne(map<string, string>books) {

	string id,emptyException;
	int noFoundException = 1;
	try
	{
		cout << "Bulmak istediðiniz kitabýn id sini giriniz" << endl;
		cin >> id;

		if (id == "")
			throw emptyException;

		if (books[id] == "")
			throw noFoundException;

		cout << "ID    | Kitap Adi" << endl;
		cout << books[id] << endl;
	}
	catch (string emptyException) {
		cerr << "Boþ deðer giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip kitap bulunamamýþtýr" << endl;
	}
}

void book::printAll(map<string, string>books) {
	map<string, string>::iterator itr;

	cout << "ID    | Kitap Adi" << endl;

	for (itr = books.begin(); itr != books.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}

void book::borrowedBooks(map<string, string>borrowedBooks) {
	map<string, string>::iterator itr;

	cout << "Odünç alýnan kitaplar" << endl;
	cout << "ID      |    Kitap Adi" << endl;

	for (itr = borrowedBooks.begin(); itr != borrowedBooks.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}