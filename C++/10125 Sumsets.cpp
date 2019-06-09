#include <bits/stdc++.h>
using namespace std;

void my_func(int n,vector<int>& v) {

	for (int i = n-1; i > 0;--i) {
			for (int j = 0; j < n;++j) {
				if (j == i) {
					continue;
				}
				for (int k = j+1; k < n;++k) {
					if (k == i) {
						continue;
					}
					for (int l = k+1;l <n;++l) {
						if (l == i) {
							continue;
						}
						if (v[i] == v[j]+v[k]+v[l]) {
							cout << v[i] << endl;
							return;
						}
					}
				}
			}
		}

		cout << "no solution" << endl;
}




int main() {

	int n; 
	while (cin >> n) {
		if (n == 0) {
			return 0;
		}
		int i_temp;
		vector<int> v;
		for (int i = 0; i < n;++i) {
			cin >> i_temp;
			v.push_back(i_temp);
		}
		sort(v.begin(),v.end());

		my_func(n,v);
	}
	return 0;
}