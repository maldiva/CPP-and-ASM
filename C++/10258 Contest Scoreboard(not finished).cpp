#include <bits/stdc++.h>
using namespace std;

struct Participant {

	int number;
	set<int> problems;
	int timePenalty;
	bool submitted;
	Participant() : number(0), timePenalty(0), submitted(false)
	{
	}

};


int main() {

	int n; 
	cin >> n >> ws; 
	while (n--) {
		
		vector<Participant> v(100);
		for (int i = 0; i < 100;++i) {
			v[i].number = i;
		}
		
		string temp;

		while (getline(cin,temp)) {
			if (temp == "")
				break;
		istringstream sinp(temp);

		int number, problem, penalty;
		char ch;
		sinp >> number >> problem >> penalty >> ch;
		number--;
			if (ch == 'I' && v[number].problems.find(problem) == v[number].problems.end()) {
				v[number].timePenalty += 20;
			} else if (ch == 'C') {
				v[number].timePenalty += penalty;
				v[number].problems.insert(problem);
			}
			v[number].submitted = true;
		}

		sort(v.begin(), v.end(), [](const Participant & a, const Participant & b) { 
			if (a.problems.size() == b.problems.size() && a.timePenalty == b.timePenalty) {
				return a.number < b.number; 
			}
			if (a.problems.size() != b.problems.size()) {
			return a.problems.size() > b.problems.size();
			}
			return a.timePenalty < b.timePenalty; 	});

		for (int i = 0; i < 100;++i) {
			if (v[i].submitted == true) {
				int temporary = v[i].timePenalty;
				if (v[i].problems.size() == 0)
					temporary = 0;
				cout << v[i].number+1 << " " << v[i].problems.size() << " " << temporary  << endl;
			}
		}
		if (n != 0)
		cout << endl;
	}

	return 0;
}