#include <bits/stdc++.h>
using namespace std;

int main() {

	int courses;
	int categories;
	int i_temp;
	
	while (cin >> courses >> categories) {
		if (courses == 0 && categories == 0) {
			return 0;
		}

		vector<int> taken_courses;

		for (int i =0; i < courses; ++i) {
			cin >> i_temp;
			taken_courses.push_back(i_temp);
		}

		sort(taken_courses.begin(),taken_courses.end());

		vector<vector<int>> courses_by_categories (categories);		
		
		bool result = true;

		for (int j = 0; j < categories; ++j) {

			int required;

			cin >> courses >> required;

			for (int i = 0; i < courses; ++i) {
				cin >> i_temp;
				courses_by_categories[j].push_back(i_temp);
			}

			int counter = 0;

			for (int i = 0; i < courses_by_categories[j].size();++i) {
				if (binary_search(taken_courses.begin(), taken_courses.end(), courses_by_categories[j][i])) {
					counter++;                                 // if found, increase counter
				}
			}

			if (counter < required) {
				result = false;							   	  // if counter does not reach number of required courses, set result to false										  	
			}
		
		}

		if (result) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
		

	}

	return 0;
}