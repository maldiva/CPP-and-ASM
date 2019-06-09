#include <bits/stdc++.h>
using namespace std;

bool compare_sortness(string a, string b) {
	int sortness_of_a = 0;
	for (int i = 0; i < a.length();++i) {
		for (int j = i+1;j < a.length();++j) {
			if (a[i] > a[j])
			sortness_of_a++;											// if a character, starting from left, is greater than any character on right from it, increase sortness
		}																// should be performed for all characters
	}

	int sortness_of_b = 0;
	for (int i = 0; i < b.length();++i) {
		for (int j = i+1;j < b.length();++j) {
			if (b[i] > b[j])
			sortness_of_b++;											// the same is done for the second word	
		}	
	}
	return sortness_of_a < sortness_of_b;								// compare function in stable sort operates with < operand, therefore we return <
}

int main() {
	int cases; cin >> cases;
	while (cases--) {
		int i_temp;

		cin >> i_temp >> i_temp >> ws;								    // because input is read by string, we dont need to know amount of chars, so we can just skip it		
		string s_temp;

		vector<string> v;
		while (i_temp--) {
			cin >> s_temp;
			v.push_back(s_temp);
		}

		stable_sort(v.begin(),v.end(),compare_sortness);

		for (auto e: v) {
			cout << e << endl;
		}
		if (cases != 0)
		cout << endl;
	}
	return 0;
}
