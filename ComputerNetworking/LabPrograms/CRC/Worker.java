class CRC
{
	public int divisor, divisorLen;
	CRC(int divisor, int divisorLen){
		this.divisor=divisor;
		this.divisorLen=divisorLen;
	}
	public String encoder(int dataWord)
	{
		// Making the dividend by suffixing the divisorLength-1 '0' bits..
		int dividend = Integer.parseInt(Integer.toBinaryString(dataWord)+String.format("%1$"+(divisorLen-1)+ "s", "0").replace(" ", "0"), 2);		// will be in integer format..
		System.out.println("[INFO] dividend (after suffixing redundant bits): "+Integer.toBinaryString(dividend));
		// Get the remainder...
		int syndrome = dividend % divisor;	//syndrome (technically..!!), remainder generally...!!

		// Form the codeword..
		return Integer.toBinaryString(dataWord)+Integer.toBinaryString(syndrome);	// returning the codeword (in string format)

	}

	public String decoder(int codeWord)
	{
		System.out.println("[INFO] Received CodeWord: "+Integer.toBinaryString(codeWord));
		int syndrome = codeWord % divisor;
		System.out.println("codeWord: "+Integer.toBinaryString(codeWord)+", divisor: " +Integer.toBinaryString(divisor)+", syndrome: "+Integer.toBinaryString(syndrome));
		if(syndrome == 0){
			System.out.println("[INFO] Data transmission done properly..!!");
			String acceptedWord = Integer.toBinaryString(codeWord);
			acceptedWord = acceptedWord.substring(0, acceptedWord.length()-divisorLen-1);
			System.out.println("[INFO] Data after discarding redundant bits: "+acceptedWord);
			return acceptedWord;
		}
		else{
			System.out.println("[INFO] Some error might have occured while transmitting..!! Please re-send the data.");
			return "ERROR";
		}
	}
}

class Worker
{
	public static void main(String args[])
	{
		int dataWord = Integer.parseInt(args[0], 2);
		int divisor = Integer.parseInt(args[1], 2);
		int divisorLength = 4;

		CRC crc = new CRC(divisor, divisorLength);
		//String encodedString = crc.encoder(dataWord);
		//System.out.println("Encoded String: "+ encodedString);
		System.out.println("Decoded String: "+ crc.decoder(Integer.parseInt(args[0], 2)));
	}
}

/*
TESTS......
/*
		int num1 = 0b1010;
		int num2 = 0b0010;
		System.out.println(Integer.toBinaryString(num1/num2));		// Checking binary representation on a console..

		// working on division with numbers...
		int dataWord = 0b11;
		int divisor = 0b0101;
		int divisorLength=2;	// 4bits
		//System.out.println(Integer.toBinaryString(dataWord)+String.format("%1$"+(divisorLength-1)+ "s", "0").replace(" ", "0"));
		int dividend = Integer.parseInt(Integer.toBinaryString(dataWord)+String.format("%1$"+(divisorLength-1)+ "s", "0").replace(" ", "0"), 2);

		System.out.println("Dividend: "+ dividend);
		int syndrome = dividend%divisor;	//syndrome (technically..!!), remainder generally...!!
		System.out.println(Integer.toBinaryString(syndrome));

Output:		
110
Dividend: 6
1   //6%5
 working as expected...
		*/
