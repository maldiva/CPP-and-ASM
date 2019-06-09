#include <bits/stdc++.h>
using namespace std;

int main() {

	int people;	cin >> people;

	map<int,string> names;

	for (int i = 0; i < people; ++i) {
		string name;

		int day,month,year;

		cin >> name;
		
		cin >> day >> month >> year;
		int temp = year * 1000 + month * 12 + day;						// convert 3 separate int inputs into a single one
		names.emplace(temp,name);											
	}
						
	cout << max_element(names.begin(),names.end())->second << endl;		
	cout << min_element(names.begin(),names.end())->second << endl;								

	return 0;
}