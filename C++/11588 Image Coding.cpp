#include <bits/stdc++.h>
using namespace std;

int main() {
	int cases; cin >> cases;
		for (int q = 1; q <= cases;++q) {

		int lines;
		int rows;
		int important_coefficient;
		int non_important_coefficient;

		cin >> lines >> rows >> important_coefficient >> non_important_coefficient;

		map<char,int> container;

		char ch;

		for (int i = 0; i < lines;++i) {
			for (int j = 0; j < rows;++j) {
				cin >> ch;
				if (container.find(ch) == container.end()) {
					container.emplace(ch,1);
				} else {
					container[ch]++;
				}
			}
		}

		vector<int> v;

		for (auto e : container) {
			v.push_back(e.second);								// push values from map to vector
		}

		sort(v.begin(), v.end());								// sort

		int result = 0;

		int max = v[v.size()-1];								// assign max value to the biggest value from sorted vector
		
		for (auto e : v) {
			if (e != max) {										// perform checks on every iteration
				result += e * non_important_coefficient;		// for the case if we have several maximum values
			} else {
				result += e *important_coefficient;
			}
		}

		cout << "Case " << q << ": " << result << endl;
	}
	return 0;
}