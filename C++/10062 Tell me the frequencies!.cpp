#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> my_pair;

struct comparator
{
    bool operator()(my_pair const &a, my_pair const &b) const {
    	return a.second != b.second ? a.second < b.second : a.first > b.first;							// custom comparator for sorting pairs by value
    }
};

int main() {

	string s_temp;
	bool printed_line = false;

	while (getline(cin,s_temp)) {
		if (printed_line) {
			cout << endl;
		}

	map<int,int> container;
		
	for (int i = 0; i < s_temp.length(); ++i) {
		if (container.find(s_temp[i]) == container.end()) {												// push into map
			container.emplace(s_temp[i],1);
		} else {
			container[s_temp[i]]++;
		}
	}

		vector<my_pair> v;
		for (auto e : container) {																		// copy map into vector for easier sorting
			v.push_back(e);
		}

		sort(v.begin(),v.end(),comparator());															// sort by passing our custom comparator as a compare function

		for (auto e : v) {
		cout << e.first << " " << e.second << endl;
		}
		printed_line = true;
	}

	return 0;
}
