#include <bits/stdc++.h>
using namespace std;


int main() {
	
	string line1;
	string line2;
	

	while (getline(cin,line1)) {
	getline(cin,line2);

	istringstream sinp1(line1);
	istringstream sinp2(line2);

	vector<int> v1;
	vector<int> v2;
	int i_temp;

	while (sinp1 >> i_temp) {
		v1.push_back(i_temp);
	}
	while (sinp2 >> i_temp) {
		v2.push_back(i_temp);
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());


	bool boolean = true;															// set boolean as true
	for (int i = 0; i < v1.size();++i) {
		if (!binary_search(v2.begin(),v2.end(),v1[i])) {
			boolean = false;														// once we find an element that does not exist in another set, set boolean to false
		}
	}
	
	for (int i = 0; i < v2.size();++i) {
		if (!binary_search(v1.begin(),v1.end(),v2[i])) {
			boolean = false;
		}
	}

	if (boolean) {																	// if boolean is false, this is not our case, we got for next check
		cout << "A equals B" << endl;
		continue;
	}


	boolean = true;
	for (int i = 0; i < v1.size();++i) {
		if (!binary_search(v2.begin(),v2.end(),v1[i])) {
			boolean = false;
		}
	}

	if (boolean) {
		cout << "A is a proper subset of B" << endl;
		continue;
	}
		
		boolean = true;
	for (int i = 0; i < v2.size();++i) {
			if (!binary_search(v1.begin(),v1.end(),v2[i])) {
				boolean = false;
			}
		}

		if (boolean) {
			cout << "B is a proper subset of A" << endl;
			continue;
		}

		boolean = true;
		for (int i =0; i < v1.size();++i) {
			if (binary_search(v2.begin(),v2.end(),v1[i])) {
				boolean = false;
			}
		}
		if (boolean) {
			cout << "A and B are disjoint" << endl;
			continue;
		}
		cout << "I'm confused!" << endl;
	}
	return 0;
}
