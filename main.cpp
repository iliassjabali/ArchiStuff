#include <iostream>
#include <bitset>

std::bitset<8> operator + ( const std::bitset<8> num1, const std::bitset<8> num2 ){
	//printf("We are adding the following two numbers %lu+%lu\n",num1.to_ulong(), num2.to_ulong()); 
	//std::cout << "Binnary 1:\t" << num1 << "\t Binnary  2:\t" << num2 << std::endl;
	std::bitset<8> sum, carry; 
	// std::cout << "The size is " << num1.size()<< std::endl;
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
		//std::cout<<"Carry:\t" << carry << std::endl << "Sum:\t" << sum  << std::endl;
	} 
	//std::cout<<"Carry:\t" << carry << std::endl << "Sum:\t" << sum  << std::endl;
	return sum;
}
std::bitset<8> operator + ( const std::bitset<8> num1, const int num2 ){
	//just adds a int to bit 
	// using overloading 
	return num1 + std::bitset<8>(num2);
}
std::bitset<8> operator * ( const std::bitset<8> num1, const std::bitset<8> num2 ){
	// first step is to decalre the sum which should be all zeros 
	std::bitset<8> sum (0), add = num1 ; 
	for(  int i = 0; i < num2.size(); i++ ){
		/*std::cout << "Loop number: " << i + 1;
		if(num2[i] == 1) {
			std::cout << "\tAdding" <<std::endl;
		}
		else  {
			std::cout << "\tNot Adding" <<std::endl;
		}
		std::cout << "Sum:\t" << sum << "\nADD:\t" << add << std::endl;
		*/
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
std::bitset<8> operator * ( const std::bitset<8> num1, const int num2 ){
	//just multiplication a int to bit 
	// using overloading 
	return num1 * std::bitset<8>(num2);
}

std::bitset<8> multiplyTwoBin ( const int N1, const int N2){
	std::bitset<8> B1 (N1),  B2 (N2);
	printf("Multiplaying %lu*%lu\n", B1.to_ulong(), B2.to_ulong());
	std::cout << "Binnary 1:\t" << B1 << "\t Binnary  2:\t" << B2 << std::endl;
	return B1 * B2;
}

int main() {
	unsigned int N1, N2;
	std::cin >> N1 >> N2;
	std::bitset<8> tmp = multiplyTwoBin(N1, N2);
	std::cout<<"The function will give us" <<std::endl<< tmp << "\tWhich is\t" << tmp.to_ulong ()<<std::endl; //no neeed
	return 0;
}

