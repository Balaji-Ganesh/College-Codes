// C++ Program to generate CRC codeword
#include<stdio.h>
#include<iostream>
#include<math.h>			// ceill() and log2l            -- suffix "l", MAY be for 'l'ong

using namespace std;

// function to convert integer to binary string
string toBin(long long int num){
	string bin = "";
	while (num){
		if (num & 1)
			bin = "1" + bin;
		else
			bin = "0" + bin;
		num = num>>1;
	}
	return bin;
}

// function to convert binary string to decimal
long long int toDec(string bin){
	long long int num = 0;
	for (int i=0; i<bin.length(); i++)
		if (bin.at(i)=='1')
			num += 1 << (bin.length() - i - 1);
	return num;
}

// function to compute CRC and codeword
string CRC(string dataword, string generator, bool to_check=false){
	int l_gen = generator.length();
	long long int gen = toDec(generator);

	long long int dword = toDec(dataword);
	long long int dividend;
	
	if (to_check == false)				// To generate CRC..
		// append 0s to dividend
		dividend = dword << (l_gen-1);	
	else								// To check generated CRC..
		dividend = dword;

	// shft specifies the no. of least
	// significant bits not being XORed
	int shft = (int) ceill(log2l(dividend+1)) - l_gen;
	long long int rem;

	while ((dividend >= gen) || (shft >= 0)){

		// bitwise XOR the MSBs of dividend with generator
		// replace the operated MSBs from the dividend with
		// remainder generated
		rem = (dividend >> shft) ^ gen;			
		dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);

		// change shft variable
		shft = (int) ceill(log2l(dividend + 1)) - l_gen;
	}

	// finally, AND the initial dividend with the remainder (=dividend)
	if(to_check == false){				// TO print the results of generated CRC...
		long long int codeword = (dword << (l_gen - 1)) | dividend;
		cout << "Codeword : " << toBin(codeword) << endl;
		cout << "\t\t[INFO] Remainder: " << toBin(dividend) << endl;
		// Send response as codeword...
		return toBin(codeword);
	}
	else{	// When one is interested in checking CRC..
		//cout << "[INFO] Obtained remainder: " << dividend <<endl;
		return toBin(dividend);		// Return the remainder..
	}
}

int main(int argc, char **argv){
	if(argc !=3){
		cout << "[ERROR] Please pass the <dataword> <generator> as arguments respectively..!!"<<endl;
		return 0;
	}
	string dataword=argv[1], generator=argv[2];
	//dataword = "1001";
	//generator = "1011";
	//cin >> dataword>> generator;
	cout << "Generating CRC...." << endl;
	string codeword = CRC(dataword, generator);
	
	cout<<"\t[INFO] Generated codeword: "<<codeword << endl;
	
	// Transmitting data.. along with CRC.. set "to_check=true"..
	cout << "Checking generated CRC.. " << endl;
	string syndrome=CRC(codeword, generator, true);
	cout << "\t[INFO] Received remainder: " << toDec(syndrome) <<".\n";
	if(toDec(syndrome) == 0) // remainder(syndrome) as 0, indicates that: it has transmitted properly..
		cout << "\t[SUCCESS] Data has transmitted properly..!!"<<endl;
	else	
		cout << "\t[INFO] Obtained remainder: " << syndrome <<endl
			 << "\t[ERROR] Some error occured in data transmission, try re-sending the data." << endl;
	return 0;
}
/*IDEA from GFG: https://www.geeksforgeeks.org/modulo-2-binary-division/ -- via bit manipulation method.

    code is SO SOO SOOOOOOOOOOOOOOOOO WELL WRITTEN .. awesome logic..\
    trace it to have the taste..
NOTES...
    log2 tells the no. of digits present in the binary number... (but didn't understood why dividend "+1")..
    Why needed to do the log2 and subtract length..??
        Remember that, normal operations happen from right---to--left.
            But the division happens from left---to---right.. so, to divide only with the divisor length no's at left, 
                and discard the rest, this was used.
            why (1<<shift) -  .. recollect that to represent the 2^n number, we get all left(n-1) as zeroes, and the left-next as 1.
                we get that by 1<<shift.
                    But we need the 111's at right.. so -1 helps in that..
	
	----------------------------
	Code modified to also work as "CRC check" --- on 8th October, Friday

*/