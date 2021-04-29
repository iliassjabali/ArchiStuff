#include <iostream>
#include <bitset>
#include <typeinfo>
#include <string>
using namespace std;





// this works for 
bitset<8> operator + ( const bitset<8> num1, const bitset<8> num2 ){
	bitset<8> sum, carry; 
	// cout << "The size is " << num1.size()<< endl;
	for (int i = 0; i< num1.size(); i++){
		carry[i+1] = num1[i]&num2[i];
		sum[i] = num1[i]^num2[i];
		if (carry[i]){
			// see if the carry has a 1 bit
			if (num1[i] | num2[i]) {
				// Binary OR Operator copies a bit if it exists in either operand.
				if (num1[i] & num2[i]){
					// Binary AND Operator copies a bit to the result if it exists in both operands.
					carry[i+1] = 1;
					sum[i] = 1;
					carry[i] = 1;
				}
				else{
					carry[i+1] = 1;
					sum[i] = 0;
				}

			}
			else {
				sum[i] = carry[i];	//so we don't have caries 
			}
		}
		//cout<<"Carry:\t" << carry << endl << "Sum:\t" << sum  << endl;
	} 
	//cout<<"Carry:\t" << carry << endl << "Sum:\t" << sum  << endl;
	return sum;
}
bitset<8> operator + ( const bitset<8> num1, const int num2 ){
	//just adds a int to bit 
	return num1 + bitset<8>(num1);
}

bitset<8> operator * ( const bitset<8> num1, const bitset<8> num2 ){

}

int main() {
	unsigned int N1 = 9, N2= 3;
	bitset<8> B1 (N1),  B2 (N2), carry; 
	cout<< "Binnary  1:\t" << B1<< endl<< "Binnary  2:\t" << B2<< endl;
	bitset<8>  tmp = B1 + B2;
	cout<<" The function will give us" <<endl<< tmp <<endl; //no neeed
	return 0;
}
