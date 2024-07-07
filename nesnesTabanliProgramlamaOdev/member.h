#include <iostream>
#include <string>
#include <map>
#include "human.h"

using namespace std;


class member : human
{
	string memberID;
	map<string, string> book;
public:
	
	member() {};
	member(string,string,string);
	void printAll(map<string, string>);
	void printOne(map<string, string>);
	map<string, string> borrowABooks(map<string, string>, map<string, string>);
	map<string, string> returnTheBooks(map<string, string>, map<string, string>);
	map<string, string> returnBook();
};

member::member(string firstName,string lastName,string memberID) :human(firstName,lastName) {
	this->memberID = memberID;
}

void member::printOne(map<string, string>books) {
	string bookID, emptyException;
	int noFoundException = 1;

	try {
		cout << "Bulmak istediginiz kitabin id sini giriniz";
		cin >> bookID;
		
		if (bookID == "")
			throw emptyException;

		if (books[bookID] == "")
			throw noFoundException;

		cout << "ID    |     Kitap Adi" << endl;
		cout << books[bookID] << endl;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
}

void member::printAll(map<string, string>books) {
	map<string, string>::iterator itr;

	cout << "ID    |     Kitap Adi" << endl;

	for (itr = books.begin(); itr != books.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}

map<string, string>member::returnTheBooks(map<string, string>books, map<string, string>borrowedBooks) {
	string bookID, bookName, emptyExeption;
	int noFoundExeption = 1;
	
	try
	{
		cout << "Geri b�rakmak istedi�iniz kitab�n id sini giriniz:";
		cin >> bookID;

		if (bookID == "")
			throw emptyExeption;
		
		if (borrowedBooks[bookID] == "")
			throw noFoundExeption;

		bookName = borrowedBooks[bookID];

		borrowedBooks.erase(bookID);
		books.insert(pair<string, string>(bookID, bookName));
		
		this->book = books;

		return borrowedBooks;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
	return borrowedBooks;
}

map<string, string> member::borrowABooks(map<string, string>books, map<string, string>borrowedBooks) {
	string bookID,bookName, emptyException;
	int noFoundException = 1;

	map<string, string>::iterator itr;

	cout << "ID    |     Kitap Adi" << endl;

	for (itr = books.begin(); itr != books.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}

	try {
		cout << "Od�n� almak istedi�iniz kitab�n id sini giriniz : ";
		cin >> bookID;

		if (bookID == "")
			throw emptyException;

		if (books[bookID] == "")
			throw noFoundException;

		bookName = books[bookID];
		
		borrowedBooks.insert(pair<string, string>(bookID, bookName));

		books.erase(bookID);
		this->book = books;
		return borrowedBooks;
	}
	catch (string emptyException) {
		cerr << "Bo� de�er giremezsiniz" << endl;
	}
	catch (int noFoundException) {
		cerr << "Girilen id ye sahip �ye bulunamam��t�r" << endl;
	}
	return borrowedBooks;
}

map<string, string>member::returnBook() {
	return book;
}