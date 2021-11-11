#include<stdio.h>
#define MAX_FRAME_SIZE 20

int sendFrames(int windowSize, int numFrames, int frames[]){
    int i=0;
    for(int sentFrame=0; sentFrame < numFrames; ){
        // Send the frames of count, windowSize..
        for(i=0; i<windowSize && sentFrame < numFrames; i++)
            printf("Frame_%d: \"%d\" transmitting......... Transmitted successfully\n", sentFrame++, frames[sentFrame]);

        // Area of receiving acknowledgement...
        printf("\nAcknowlegement received for %d frames. Sending next frames if left.\n", i);
    }
    return 1;       // As done job successfully.
}

int main(){
    int windowSize=0, numFrames=0;
    int frames[MAX_FRAME_SIZE] = {};    // Initializes to 0 (default value)

    // Get the user input..
    printf("Enter window size: ");                  scanf("%d", &windowSize);
    printf("Enter number of frames to transmit: "); scanf("%d", &numFrames);
    for(int i=0; i<numFrames; i++)
        scanf("%d", &frames[i]);

    // Send the frames..
    printf("\n\nGetting ready to transfer...\nReady to transfer..\n");
    sendFrames(windowSize, numFrames, frames);
    return 0;
}

/*

krishna@Krishna-Brindavan:.../simpleSlidingWindow$ gcc simpleSlidingWindow.c -o simpleSlidingWindow && ./simpleSlidingWindow
Enter window size: 4
Enter number of frames to transmit: 6
898 786 908 675 234 235


Getting ready to transfer...
Ready to transfer..
Frame_0: "898" transmitting......... Transmitted successfully
Frame_1: "786" transmitting......... Transmitted successfully
Frame_2: "908" transmitting......... Transmitted successfully
Frame_3: "675" transmitting......... Transmitted successfully

Acknowlegement received for 4 frames. Sending next frames if left.
Frame_4: "234" transmitting......... Transmitted successfully
Frame_5: "235" transmitting......... Transmitted successfully

Acknowlegement received for 2 frames. Sending next frames if left.

*/