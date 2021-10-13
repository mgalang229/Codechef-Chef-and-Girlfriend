#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string time1, time2;
		cin >> time1 >> time2;
		double dist;
		cin >> dist;
		double g_hr = stoi(time1.substr(0, 2));
		double g_mins = stoi(time1.substr(3, 2));
		double c_hr = stoi(time2.substr(0, 2));
		double c_mins = stoi(time2.substr(3, 2));
		// for the first plan: find the total minutes between 'time1' and 'time2' plus the waiting time for the girlfriend
		double first = (60 - c_mins) + (60 * (g_hr - (c_hr + 1))) + g_mins + dist;
		cout << fixed << setprecision(1) << first << " ";
		// for the second plan: there are two (2) cases
		// case 1:
		// if the total minutes of Chef going home and back to the station is less than
		// or equal to the total minutes between Chef and his girlfriend, then the 
		// answer is total minutes between Chef and his girlfriend
		// case 2:
		// if the total minutes of Chef going home and back to the station is strictly
		// greater than the total minutes between Chef and his girlfriend, then it means
		// they will meet at some point on the road, and to solve this, we need to
		// calculate the middle point of the trip
		// note: don't forget to remove the 'dist' from 'first' to remove the waiting time
		// for chef's girlfriend
		first -= dist;
		if (dist * 2 <= first) {
			cout << first;
		} else {
			cout << (first + (dist * 2)) / 2;
		}
		cout << '\n';
	}
	return 0;
}
