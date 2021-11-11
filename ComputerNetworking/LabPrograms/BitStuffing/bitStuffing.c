#include <stdio.h>
#include <string.h>
#define MAX 30

// Global declarations of helper functions...
void stuffing(char *frame, char* result_frame);
void deStuffing(char *recvdFrame, char* result_frame);

// main...
int main(int argc, char*argv[])
{
	if(argc!=2)
		printf("Please pass the frame..Terminating..!!\n");
	else // Now got the frame, start the work...
	{
		char *frame = argv[1];		
		printf("[INFO] Received frame: %s\n", frame);

		char stuffed_frame[MAX];
		stuffing(frame, (char*)stuffed_frame);	
		printf("Stuffed frame: %s\n", stuffed_frame);
		
		char deStuffed_frame[MAX];
		deStuffing(stuffed_frame, (char*)deStuffed_frame);
		printf("DeStuffed frame: %s\n", deStuffed_frame); 			
	}
}

// Implementations of the globally declared helper functions..
void stuffing(char *frame, char* stuffed_frame)
{
	printf("[INFO] Received frame for stuffing: %s\n", frame);
	// Case-1: Frame doesn't contains the sequence "011111"..
	int loc=0;
	char *pos;
	if((pos=strstr(frame, "011111")) == NULL)    // Indicates that, no such sequence is in the frame..
		// Go with prefixing flagbits and suffixing..
		//continue;
		printf("[INFO] Sequence \"011111\" not present in the frame.\n");
	// Case-2: Frame contains the the sequence of "011111"..so suffix it with "0" at end..
	else
	{
		printf("[INFO] Sequence \"011111\" present in the frame.\n");
		loc = (int)(pos - frame);   // Find the actual index of sequence 011111.
		char temp[MAX];
		strncpy(temp, frame, loc+6);
		strcat(temp, "0");          // Placing 0..
		strcpy(temp, &frame[loc+7]);
		frame = temp;
		printf("\t[INFO] Intermediate-Stuffed frame: %s\n", temp);
	}
	// Prefix and suffix the flag bits
	printf("[INFO] --- Going for prefxing and suffxing..\n");
	char flagBits[] = "01111110";		
	//char stuffed_frame[MAX];
	strcpy(stuffed_frame, flagBits);   // Prefixing the flagBit..
	printf("[INFO] --- Going for suffxing..\n");
	strcat(stuffed_frame, frame); 	   // Placing the frame..
	strcat(stuffed_frame, flagBits);   // Suffixing the flagBit..	
	
	// Now the frame is properly stuffed.. ready to transfer..
	printf("[INFO] Final stuffed frame: %s\n", stuffed_frame); 
	//return (char*)stuffed_frame;
}

void deStuffing(char *recvdFrame, char* actual_frame)
{
	printf("[INFO] Received frame for de-stuffing: %s\n", recvdFrame);
	// Remove the Prefixed and suffixed flagBits..
	//char actual_frame[MAX];
	printf("Going to remove the flagbits..\n");
	int len = (int)strlen(recvdFrame);
	//for(int i=8; i<=len-8; i++)
	//	strcat(actual_frame, &recvdFrame[i]);   // Removing the prefix and suffix..
	int trim_len = len-16;                          // 2 pairs of flagBits(of length-8) = 16
	printf("-- SAFE''\n");
	strncpy(actual_frame, recvdFrame+8, trim_len);
	actual_frame[trim_len] = '\0';
		
	printf("[INFO] Frame after removing the beg and end flag bits..: %s\n", actual_frame);
	// Now check for the occurance of "011111"..
	char* pos=0;
	int loc=0;
	if((pos = strstr(actual_frame, "011111")) != NULL)  // If contains...
	{
		loc = (int)(pos - actual_frame);         // Find the actual index of sequence 011111.	
		printf("[INFO] Sequence \"011111\" found..!! Removing it..!!\n");
		char temp[MAX];
		strncpy(temp, actual_frame, loc+6);
		//strcat(temp, "0");          // Placing 0..
		strcpy(temp, &actual_frame[loc+7]);
		strcpy(actual_frame, temp);
		printf("\t[INFO] Frame after removing the sequence \"011111\": %s\n", actual_frame);
	}
	
	// Now the frame is ready to understand for an application..
	printf("[INFO] Final frame after de-stuffing: %s\n", actual_frame);
	//return (char*)actual_frame;	
}
