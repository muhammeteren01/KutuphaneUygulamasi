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

{"123456", "gizemli gökyüzü"}
,{"789012", "kaybolmuþ þehir"}
,{"345678", "sonsuz sýrlar"}
,{"901234", "geceye veda"}
,{"567890", "kayýp düþler"}
,{"234567", "unutulmuþ zaman"}
,{"890123", "karanlýk gizemler"}
,{"456789", "gece yeli"}
,{"112345", "izler arasýnda"}
,{"678901", "kýrýk notalar"}
,{"210987", "yitik yýldýz"}
,{"876543", "gece perisi"}
,{"543210", "gölgelerin dansý"}
,{"987654", "son sayfa"}
,{"654321", "yabancý rüya"}};
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
			cout << "Ýþlemi kim yapýyor? \n1-Çalýþan \n2-Üye" << endl;
			cin >> number1;
			
			if (number1 == 1) {
				string value = "ss";
				cout << "Hangi iþlemi yapmak istersiniz?\n1-Üye Ýþlemleri\n2-Çalisan Ýþlemleri\n3-Kitap Ýþlemleri" << endl;
				cin >> number2;

				if (number2 == 1) {
					cout << "Hangi iþlemi yapmak istersiniz?\n1-Üye Ekle\n2-Üye Sil\n3-Üye Güncelle\n4-Üye Ara\n5-Üyeleri Yazdýr" << endl;
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
					cout << "Hangi iþlemi yapmak istersiniz?\n1-Çalýþan Ekle\n2-Çalýþan Sil\n3-Çalýþan Guncelle\n4-Çalýþan Ara\n5-Çalýþanlari Yazdir" << endl;
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
					cout << "Hangi iþlemi yapmak istersiniz?\n1-Kitap Ekle\n2-Kitap Sil\n3-Kitap Güncelle\n4-Kitap Ara\n5-Kitaplarý Yazdýr\n6-Ödünç Alýnan Kitaplar" << endl;
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
				cout << "Hangi iþlemi yapmak istersiniz?\n1-Kitap Ödünç al\n2-Kitap Geri Ver \n3-Kitap bul\n4-Tüm Kitaplarý yazdýr" << endl;
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
			cerr << "Hatalý Deðer Girdiniz" << endl;
		}
		catch (string value) {
			cerr << "Hatalý Deðer Girdiniz" << endl;

		}
		catch (long character) {
			cerr << "Hatalý Deðer Girdiniz" << endl;

		}
		while (true) {
			cout << "Yeni iþlem yapmak ister misiniz?\n1-Evet\n2-Hayýr" << endl;
			cin >> number1;


			if (number1 == 1) {
				break;
			}
			else if (number1 == 2) {
				cout << "Ýyi Günler" << endl;
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