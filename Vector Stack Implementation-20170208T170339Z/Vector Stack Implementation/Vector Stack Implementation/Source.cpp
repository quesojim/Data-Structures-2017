#include <iostream>
#include <vector>
using namespace std;

void Print(vector <int>);

int main() {
	
	vector <int>L;
	L.push_back(5);
	L.push_back(7);
	L.pop_back();
	L.push_back(16);
	L.back();
	Print(L);
	L.pop_back();
	L.push_back(8);
	L.push_back(11);
	L.push_back(3);
	L.push_back(5);
	Print(L);
	L.pop_back();
	L.pop_back();
	L.push_back(13);
	L.push_back(15);
	L.push_back(10);
	Print(L);
	system("pause");
	return 0;

}

void Print(vector<int> L) {

	for (int i = 0; i <= L.size() - 1; i++) {
		cout << L[i] << " ";
	}

	cout << endl;
}