#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef set<int> si;
typedef map<int, int> mii;
#define MOD 1000000007
#define endl "\n"
#define mp make_pair
#define pb push_back

void display(const string songLyric, int typeSpeed, int pauseDur, bool clearConsole) {
	for (int i = 0; i < songLyric.size(); i++) {
		cout << songLyric[i] << flush;
		Sleep(typeSpeed);
	}
	Sleep(pauseDur);
	if (clearConsole) {
		system("cls");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	display("I couldn't wait for you", 75, 50, false);
	display(" to come clear the cupboard", 75, 4250, true);
	display("But now you're gone and leaving nothing", 75, 50, false);
	display(" but a sign", 75, 3000, true);
	display("Another evening i'll be sitting reading", 75, 50, false);
	display(" in between your lines", 75, 3500, true);
	display("Because i miss you all the time <3", 75, 3000, true);
	display("So", 75, 50, false);
	display(", get away", 75, 100, true);
	display("Another way to feel", 75, 75, false);
	display(" what you didn't want yourself to know", 75, 125, true);
	display("And let yourself go", 75, 2000, true);
	display("You know you didn't lose your self-control", 75, 100, true);
	display("Let's start at the rainbow", 75, 1000, true);
	for (int i = 1; i <= 5; i++) {
		if (i == 3) {
			display("I really want to stay at your house - Rosa Walton, Hallie Coggins", 75, 100, false);
		}
		else if (i == 5) {
			display("Coded by ecl1pseiwnl", 75, 100, false);
		}
		cout << "\n";
		
	}
	return 0;
}