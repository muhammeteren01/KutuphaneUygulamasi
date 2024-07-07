#include <map>
#include <iostream>
#include <string>


using namespace std;

class workerOperations
{
public:

	map<string, string> addWorker(map<string, string>);
	map<string, string> deleteWorker(map<string, string>);
	map<string, string> updateWorker(map<string, string>);
	void findWorker(map<string, string>);
	void printAllWorkers(map<string, string>);
};

map<string, string>workerOperations:: addWorker(map<string, string>myMap) {
	string firstNameAndLastName,workerID;

	cout << "Kullanicinin adi ve soyadini giriniz : ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, firstNameAndLastName);

	myMap.insert(pair<string, string>(workerID, firstNameAndLastName));

	return myMap;
}

map<string, string>workerOperations::deleteWorker(map<string, string>myMap) {
	string workerID;

	cout << "Silmek istediginiz ogrencinin id sini giriniz : ";
	cin >> workerID;

	myMap.erase(workerID);

	return myMap;
}

map<string, string>workerOperations::updateWorker(map<string, string>myMap) {
	string workerID1, workerID2, firstNameAndLastName;

	cout << "Guncellemek istediginiz uyenin id sini giriniz : ";
	cin >> workerID1;

	cout << "Yeni id yi giriniz : ";
	cin >> workerID2;

	cout << "Yeni uye adini ve soyadini  yi giriniz : ";
	cin >> firstNameAndLastName;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, firstNameAndLastName);

	myMap.erase(workerID1);

	myMap.insert(pair<string, string>(workerID2, firstNameAndLastName));

	return myMap;
}

void workerOperations::findWorker(map<string, string>myMap) {
	string workerID;

	cout << "Bulmak istediginiz uyenin id sini giriniz";
	cin >> workerID;

	cout << "      ID      |     Uye Adi";
	cout << myMap[workerID] << endl;
}

void workerOperations::printAllWorkers(map<string, string>myMap) {
	map<string, string>::iterator itr;

	cout << "      ID      |     Kitap Adi";

	for (itr = myMap.begin(); itr != myMap.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
}