#include<stdio.h>

int go_back_n(int startFrame, int n){
    // Send the frames..
    for(int frame_count=startFrame; frame_count<n; frame_count++)
        printf("[INFO] Frame_%d transmitted successfully.\n", frame_count);
    
    // Take the acknowldgement..
    int last_recvd_frame=0;
    printf("[INPUT] Enter the last successfully received frame: ");   scanf("%d", &last_recvd_frame);
    if(last_recvd_frame<n-1 && last_recvd_frame > startFrame){
        printf("Re-transmitting frames from: %d.\n", last_recvd_frame);
        return go_back_n(last_recvd_frame, n);
    }
    else if(last_recvd_frame >n-1 || last_recvd_frame <startFrame)  // If mischevious input..
        return 0;                   // To indicate failed transmission..
    else return 1;                  //  To indicate successful transmission..
}

int main(){
    int windowSize=0;

    // Get the user input..
    printf("Enter window size: ");      scanf("%d", &windowSize);
    
    // Send the frames
    printf("\n\nGetting ready to transfer...\nReady to transfer..\n");
    if(go_back_n(0, windowSize))
        printf("[SUCCESS] Frame transmission JOB done succesfully.\n");
    else
        printf("[ERROR] Unexpected error occured.");
    return 0;
}

/*

krishna@Krishna-Brindavan:.../simpleSlidingWindow$ gcc Go_back_N.c -o Go_back_N && ./Go_back_N
Enter window size: 7


Getting ready to transfer...
Ready to transfer..
[INFO] Frame_0 transmitted successfully.
[INFO] Frame_1 transmitted successfully.
[INFO] Frame_2 transmitted successfully.
[INFO] Frame_3 transmitted successfully.
[INFO] Frame_4 transmitted successfully.
[INFO] Frame_5 transmitted successfully.
[INFO] Frame_6 transmitted successfully.
[INPUT] Enter the last successfully received frame: 3
Re-transmitting frames from: 3.
[INFO] Frame_3 transmitted successfully.
[INFO] Frame_4 transmitted successfully.
[INFO] Frame_5 transmitted successfully.
[INFO] Frame_6 transmitted successfully.
[INPUT] Enter the last successfully received frame: 5
Re-transmitting frames from: 5.
[INFO] Frame_5 transmitted successfully.
[INFO] Frame_6 transmitted successfully.
[INPUT] Enter the last successfully received frame: 6
[SUCCESS] Frame transmission JOB done succesfully.
krishna@Krishna-Brindavan:.../simpleSlidingWindow$ gcc Go_back_N.c -o Go_back_N && ./Go_back_N
Enter window size: 3


Getting ready to transfer...
Ready to transfer..
[INFO] Frame_0 transmitted successfully.
[INFO] Frame_1 transmitted successfully.
[INFO] Frame_2 transmitted successfully.
[INPUT] Enter the last successfully received frame: 5
[ERROR] Unexpected error occured.krishna@Krishna-Brindavan:.../simpleSlidingWindow$ gcc Go_back_N.c -o Go_back_N && ./Go_back_N
Enter window size: 3


Getting ready to transfer...
Ready to transfer..
[INFO] Frame_0 transmitted successfully.
[INFO] Frame_1 transmitted successfully.
[INFO] Frame_2 transmitted successfully.
[INPUT] Enter the last successfully received frame: 0
[SUCCESS] Frame transmission JOB done succesfully.
krishna@Krishna-Brindavan:.../simpleSlidingWindow$ gcc Go_back_N.c -o Go_back_N && ./Go_back_N
Enter window size: 3


Getting ready to transfer...
Ready to transfer..
[INFO] Frame_0 transmitted successfully.
[INFO] Frame_1 transmitted successfully.
[INFO] Frame_2 transmitted successfully.
[INPUT] Enter the last successfully received frame: -1
[ERROR] Unexpected error occured.krishna@Krishna-Brindavan:.../simpleSlidingWindow$ 


*/