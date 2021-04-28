#include <iostream>
#include <bitset>
using namespace std;

bitset<8> BinAddition (const bitset<8> a, const bitset<8> b ){
	return 	a+b ; 
}

/*string BinnaryMulti (const int a, const int b ){
	bitset<8> B1 (a),  B2 (b);
	bitset<8> sum;
	cout<< B1.to_string()<< endl;
	cout<< B2.to_string()<<endl;
	return B1.to_string();
}*/

int main() {
	bitset<8> B1 (8),  B2 (16);
	cout <<  B1+B2 <<endl;
	return 0;
}
