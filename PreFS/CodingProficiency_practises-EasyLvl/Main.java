import java.util.Scanner;
import java.lang.Math;
class Main{
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        int length=scanner.nextInt();
        int boxes[] = new int[length];
        for(int i=0; i<length; i++)
            boxes[i] = scanner.nextInt();
        int k=scanner.nextInt();
        
        // logic..
        int step=k, idx=0;                          // to work on the array..
        int flag_1=0, flag_2=0;                     // To store the status of finding..
        for(int i=0; i<length; i++)
            for(int j=i+1; j<length; j++)             // Here.... the condition of being <=k is applied.. hence no need of abs()
                if(boxes[i] == boxes[j] && i!=j &&Math.abs(i-j)==k){   // When the values on the boxes are found to be same (and those are of not same box...!!)
                    System.out.println("i="+i+", j="+j);
                    return;
                }
        System.out.println(false);     // Printing the final result obtained..
    
    }
}


    /*
    
    for(int i=0; i<length; i++)
        {
            System.out.print("i="+i);
            for(int j=i+1; j<length; j++)             // Here.... the condition of being <=k is applied.. hence no need of abs()
            {
                System.out.println(", j="+j);
                if(boxes[i] == boxes[j] && i!=j){   // When the values on the boxes are found to be same (and those are of not same box...!!)
                    flag_1=i;
                    flag_2=j;
                    
                    if(Math.abs(i-j) == k){
                    System.out.println("Found");
                    break;}
                }
            }
        }
        System.out.println(flag_1+", "+flag_2);     // Printing the final result obtained..
    */
