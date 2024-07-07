#include <map>
#include <iostream>
#include "book.h"
#include "member.h"
#include "worker.h"
#include "memberRelatedTransactions.h"


using namespace std;

map<string, string>workers;
map<string, string>members;
map<string, string>books{

{"123456", "gizemli g�ky�z�"}
,{"789012", "kaybolmu� �ehir"}
,{"345678", "sonsuz s�rlar"}
,{"901234", "geceye veda"}
,{"567890", "kay�p d��ler"}
,{"234567", "unutulmu� zaman"}
,{"890123", "karanl�k gizemler"}
,{"456789", "gece yeli"}
,{"112345", "izler aras�nda"}
,{"678901", "k�r�k notalar"}
,{"210987", "yitik y�ld�z"}
,{"876543", "gece perisi"}
,{"543210", "g�lgelerin dans�"}
,{"987654", "son sayfa"}
,{"654321", "yabanc� r�ya"}};
map<string, string>borrowedBooks;

int main()
{
	setlocale(LC_ALL, "Turkish");
	book book;
	member member;
	worker worker;
	memberRelatedTransactions memberRelatedTransactions;

	while (true) {

		int number1 = 0, number2 = 0, number3 = 0;
		string a;
		try
		{
			cout << "��lemi kim yap�yor? \n1-�al��an \n2-�ye" << endl;
			cin >> number1;
			
			if (number1 == 1) {
				string value = "ss";
				cout << "Hangi i�lemi yapmak istersiniz?\n1-�ye ��lemleri\n2-�alisan ��lemleri\n3-Kitap ��lemleri" << endl;
				cin >> number2;

				if (number2 == 1) {
					cout << "Hangi i�lemi yapmak istersiniz?\n1-�ye Ekle\n2-�ye Sil\n3-�ye G�ncelle\n4-�ye Ara\n5-�yeleri Yazd�r" << endl;
					cin >> number3;

					if (number3 == 1)
					{
						members = memberRelatedTransactions.add(members);
					}
					else if (number3 == 2) {
						members = memberRelatedTransactions.remove(members);
					}
					else if (number3 == 3) {
						members = memberRelatedTransactions.update(members);
					}
					else if (number3 == 4) {
						memberRelatedTransactions.printOne(members);
					}
					else if (number3 == 5) {
						memberRelatedTransactions.printAll(members);
					}
					else
						throw number3;

				}
				else if (number2 == 2) {
					cout << "Hangi i�lemi yapmak istersiniz?\n1-�al��an Ekle\n2-�al��an Sil\n3-�al��an Guncelle\n4-�al��an Ara\n5-�al��anlari Yazdir" << endl;
					cin >> number3;

					if (number3 == 1) {
						workers = worker.add(workers);
					}
					else if (number3 == 2) {
						workers = worker.remove(workers);
					}
					else if (number3 == 3) {
						workers = worker.update(workers);
					}
					else if (number3 == 4) {
						worker.printOne(workers);
					}
					else if (number3 == 5) {
						worker.printAll(workers);
					}
					else
						throw number3;
				}
				else if (number2 == 3) {
					cout << "Hangi i�lemi yapmak istersiniz?\n1-Kitap Ekle\n2-Kitap Sil\n3-Kitap G�ncelle\n4-Kitap Ara\n5-Kitaplar� Yazd�r\n6-�d�n� Al�nan Kitaplar" << endl;
					cin >> number3;

					if (number3 == 1) {
						books = book.add(books);
					}
					else if (number3 == 2) {
						books = book.remove(books);
					}
					else if (number3 == 3) {
						books = book.update(books);
					}
					else if (number3 == 4) {
						book.printOne(books);
					}
					else if (number3 == 5) {
						book.printAll(books);
					}
					else if (number3 == 6) {
						book.borrowedBooks(borrowedBooks);
					}
					else
						throw number3;
				}
				else
					throw value;
			}
			else if (number1 == 2) {
				long character = 1111;
				cout << "Hangi i�lemi yapmak istersiniz?\n1-Kitap �d�n� al\n2-Kitap Geri Ver \n3-Kitap bul\n4-T�m Kitaplar� yazd�r" << endl;
				cin >> number2;

				if (number2 == 1) {
					borrowedBooks = member.borrowABooks(books, borrowedBooks);
					books = member.returnBook();
				}
				else if (number2 == 2) {
					borrowedBooks = member.returnTheBooks(books, borrowedBooks);
					books = member.returnBook();
				}
				else if (number2 == 3) {
					member.printOne(books);
				}
				else if (number2 == 4) {
					member.printAll(books);
				}
			
				else
					throw character;
			}
			else
				throw number1;

		}
		catch (int number1)
		{
			cerr << "Hatal� De�er Girdiniz" << endl;
		}
		catch (string value) {
			cerr << "Hatal� De�er Girdiniz" << endl;

		}
		catch (long character) {
			cerr << "Hatal� De�er Girdiniz" << endl;

		}
		while (true) {
			cout << "Yeni i�lem yapmak ister misiniz?\n1-Evet\n2-Hay�r" << endl;
			cin >> number1;


			if (number1 == 1) {
				break;
			}
			else if (number1 == 2) {
				cout << "�yi G�nler" << endl;
				break;
			}
			else
				cout << "Hatali deger girdiniz tekrar deneyiniz" << endl;
		}

		if (number1 == 2) {
			break;
		}
	}
}