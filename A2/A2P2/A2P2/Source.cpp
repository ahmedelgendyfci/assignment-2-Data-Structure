#include <iostream> 
#include <iterator> 
#include <map> 
#include <string>
using namespace std;
int main()
{
	map<string, int> mymap;
	string word = "";
	cout << "Enter Your Word !" << endl;
	cin >> word;

	while (word != "done")
	{

		if (mymap.find(word) != mymap.end())
		{
			mymap[word]++;
		}
		else
		{
			mymap.insert(pair<string, int>(word, 1));
		}

		cout << "Enter Your Word !" << endl;
		cin >> word;
	}

	map<string, int>::iterator itr;
	for (itr = mymap.begin(); itr != mymap.end(); ++itr) {
		cout << "The word: " << itr->first << endl;
		cout << "The word count: " << itr->second << endl;
	}



	cout << "\n\nAfter Erasing the words that begin with a" << endl;

	for (itr = mymap.begin(); itr != mymap.end(); ++itr) {

		//cout << itr->first.substr(0, 1) << endl;

		if (itr->first.substr(0, 1) == "a" || itr->first.substr(0, 1) == "A")
		{
			mymap.erase(itr++);
			itr--;
		}
		cout << "The word: " << itr->first << endl;
		cout << "The word count: " << itr->second << endl;
	}







	system("pause");
	return 0;
}