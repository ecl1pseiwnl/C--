#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double canhHV, cdHCN, crHCN, bkHT;
	cin >> canhHV;
	cin >> cdHCN >> crHCN;
	cin >> bkHT;
	cout <<fixed<<setprecision(2)<< canhHV * canhHV << " " << canhHV * 4 << endl;
	cout << fixed << setprecision(2)<<cdHCN * crHCN << " " << (cdHCN + crHCN) * 2 << endl;
	cout << fixed << setprecision(2)<<bkHT * bkHT * 3.14 << " " << bkHT * 2 * 3.14 << endl;
}