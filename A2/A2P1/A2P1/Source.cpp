#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class book
{
public:
	string name;
	string auther;
	int year;
	string version;
	book(string n, string a, int y, string v)
	{
		name = n;
		auther = a;
		year = y;
		version = v;
	}
};

class FCI_library
{
private:
	vector<book> newBook;
public:
	void pushData(book data) {
		newBook.push_back(data);
	}
	int getVectorSize(){
		return newBook.size();
	}
	void print(){
		for (int i = 0; i < getVectorSize(); i++)
		{
			cout << newBook[i].name << endl;
			cout << newBook[i].auther << endl;
			cout << newBook[i].year << endl;
			cout << newBook[i].version << endl;
			cout << "----------------------" << endl;
		}

	}

	void Sorting()
	{
		for (int i = 0; i < getVectorSize(); i++)
		{
			for (int j = 0; j < getVectorSize() - i - 1; j++)
			{
				if (newBook[j].name.compare(newBook[j + 1].name) > 0)
				{
					swap(newBook[j], newBook[j + 1]);
				}
			}
		}
	}

	void searchByName(string name)
	{
		for (int i = 0; i < getVectorSize(); i++)
		{
			if (newBook[i].name == name)
			{
				cout << "The Search Result:" << endl;
				cout << "Book Name: "<<newBook[i].name << endl;
				cout << "Book Auther: " << newBook[i].auther << endl;
				cout << "Book Year: " << newBook[i].year << endl;
				cout << "Book Version: " << newBook[i].version << endl;
				break;
			}
		}
	}

	void searchByAuther(string auther)
	{
		for (int i = 0; i < getVectorSize(); i++)
		{
			if (newBook[i].auther == auther)
			{
				cout << "The Search Result:" << endl;
				cout << "Book Name: " << newBook[i].name << endl;
				cout << "Book Auther: " << newBook[i].auther << endl;
				cout << "Book Year: " << newBook[i].year << endl;
				cout << "Book Version: " << newBook[i].version << endl;
				break;
			}
		}
	}

	void updateVersion(string name, string version)
	{
		for (int i = 0; i < getVectorSize(); i++)
		{
			if (newBook[i].name == name)
			{
				newBook[i].version = version;
				cout << "The Result After Updating The Book of :" << name << " version.." << endl;
				cout << "Book Name: " << newBook[i].name << endl;
				cout << "Book Auther: " << newBook[i].auther << endl;
				cout << "Book Year: " << newBook[i].year << endl;
				cout << "Book Version: " << newBook[i].version << endl;
				break;
			}
		}
	}

	void theHighestVersion(){
		string highVersion = "";

		for (int i = 0; i < getVectorSize(); i++)
		{
			for (int j = 0; j < getVectorSize(); j++)
			{
				if (newBook[i].version.compare(newBook[j].version) < 0)
				{
					highVersion = newBook[j].version;
				}
			}
		}
		cout << "The Highest Version: " << highVersion << endl;
	}
};

int main()
{
	FCI_library db;
	bool next = true;
	while (next)
	{

		int ch;
		cout << "1.	Add book" << endl;
		cout << "2.	Search book by name" << endl;
		cout << "3.	Search book by author" << endl;
		cout << "4.	List books in alphabetical order" << endl;
		cout << "5.	Update available number of versions of a book" << endl;
		cout << "6.	Find the books which have the highest number of versions and print books information." << endl;
		cout << ">> ";
		cin >> ch;
		if (ch == 1)
		{
			bool flag = true;
			while (flag)
			{

				string name, auther, version;
				int year;
				cout << "Enter The Book Name: ";
				cin >> name;
				cout << "Enter The Book Auther: ";
				cin >> auther;
				cout << "Enter The Book Year: ";
				cin >> year;
				cout << "Enter The Book Version: ";
				cin >> version;

				book b(name, auther, year, version);
				db.pushData(b);

				cout << "Are You Want To Add A New Book? \n1.Yes.\n2.No" << endl;
				int x = 0;
				cin >> x;
				if (x == 2)
				{
					flag = false;
				}
			}

		}
		else if (ch == 2)
		{
			string name;
			cout << "Enter The Book Name: ";
			cin >> name;
			db.searchByName(name);
		}
		else if (ch == 3)
		{
			string auther;
			cout << "Enter The Book auther: ";
			cin >> auther;
			db.searchByAuther(auther);
		}
		else if (ch == 4)
		{
			db.Sorting();
			db.print();
		}
		else if (ch == 5)
		{
			string name, version;
			cout << "Enter The Book Name: ";
			cin >> name;
			cout << "Enter The New Version: ";
			cin >> version;
			db.updateVersion(name, version);
		}
		else if (ch == 6)
		{
			db.theHighestVersion();
		}
		else
		{
			cout << "Enter Your Choice Again !" << endl << endl;
		}

		cout << "Are You Want to continue ?" << endl;
		cout << "1.Yes\n2.No\n";
		int x;
		cin >> x;
		if (x== 2)
		{
			cout << endl << endl << "The Program Ended.." << endl << endl;
			break;
		}

	}//end while loop for continue
	system("pause");
	return 0;
}