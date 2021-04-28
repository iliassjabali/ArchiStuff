#include <iostream>
#include <bitset>
using namespace std;

string BinnaryMulti (int a, int b ){
	bitset<8> B1 (a),  B2 (b);
	bitset<8> sum = B1&= B2;

	return sum.to_string();
}

int main() {
	
	cout << BinnaryMulti(20, 4 ) <<endl;
	return 0;
}
