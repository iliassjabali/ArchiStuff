#include <iostream>
#include <bitset>
#include <typeinfo>
#include <string>
using namespace std;

bitset<8> operator + ( const bitset<8> num1, const bitset<8> num2 ){
	//printf("We are adding the following two numbers %lu+%lu\n",num1.to_ulong(), num2.to_ulong()); 
	//cout << "Binnary 1:\t" << num1 << "\t Binnary  2:\t" << num2 << endl;
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
	// using overloading 
	return num1 + bitset<8>(num2);
}

bitset<8> operator * ( const bitset<8> num1, const bitset<8> num2 ){
	// first step is to decalre the sum which should be all zeros 
	bitset<8> sum (0), add = num1 ; 
	for(  int i = 0; i < num2.size(); i++ ){
		/*cout << "Loop number: " << i + 1;
		if(num2[i] == 1) {
			cout << "\tAdding" <<endl;
		}
		else  {
			cout << "\tNot Adding" <<endl;
		}
		cout << "Sum:\t" << sum << "\nADD:\t" << add << endl;*/
		//now we should go over each bit of the num2 and add the numbers only if it equales 1
		if(num2[i] == 1){
			sum = sum + add;
			add  = (add << 1);
		}
		else{
			//we will just have to shift regardless of the thingy 
			add  = (add << 1);
		}	
	}
	return sum;
}
bitset<8> operator * ( const bitset<8> num1, const int num2 ){
	//just multiplication a int to bit 
	// using overloading 
	return num1 * bitset<8>(num2);
}

int main() {
	unsigned int N1 = 96, N2= 2;
	bitset<8> B1 (N1),  B2 (N2);
	printf("Multiplaying %d*%d\n", N1, N2);
	cout << "Binnary 1:\t" << B1 << "\t Binnary  2:\t" << B2 << endl;
	bitset<8>  tmp = B1 * B2;
	cout<<" The function will give us" <<endl<< tmp  << "\tWhich is\t" << tmp.to_ulong ()<<endl; //no neeed
	return 0;
}
