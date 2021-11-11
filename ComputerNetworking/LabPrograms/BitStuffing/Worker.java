import java.util.Scanner;
import java.io.BufferedReader;

class BitStuffing
{
    String flagBit, troubleSeq;
    BitStuffing(){
        flagBit = "01111110";  // Tested done with .."ABC"  for ease-of-building the logic..
        troubleSeq = "011111";   // Tested with "345"..  for ease-of-building the logic..
    }

    String stuffing(String data)
    {
        int start=0, idx=0;
        while((idx = data.indexOf(troubleSeq, start)) != -1)
        {
            System.out.println("idx = "+idx +", str: "+data.substring(idx+troubleSeq.length(), data.length()));
            data = data.substring(0, idx+troubleSeq.length()) + "0" +data.substring(idx+troubleSeq.length(), data.length());
            
            start = idx+troubleSeq.length()-1; // Updating the index from where to search in next turn...
            //System.out.print
        }
        System.out.println(idx);
        System.out.println("[INFO] Stuffed String: " + data);
        data = flagBit + data + flagBit;
        System.out.println("[INFO] After placing flagbits: "+data);
        return data;
    }

    String deStuffing(String data)
    {
        // Remove the prefixed flagBit... Here itself can remove the suffixed flagBit, but that won't simulate the real-time working of algorithm..
        data = data.substring(flagBit.length(), data.length());
        // Remove the 
        int start=0, idx=0;
        while((idx = data.indexOf(troubleSeq, start)) != -1)
            if(idx <= data.length()-troubleSeq.length()) // -- this avoids removing bits from flagbits..which are removed in next stage..
            {    //System.out.println("idx = "+idx +", str: "+data.substring(idx+troubleSeq.length(), data.length()));
                data = data.substring(0, idx+troubleSeq.length()) + data.substring(idx+troubleSeq.length()+1, data.length());
                start = idx+troubleSeq.length(); // Updating the index from where to search in next turn...
                //System.out.print
            }
        // Removing the suffixed flagBit..
        data = data.substring(0, data.length()-flagBit.length());
        System.out.println("[INFO] After removing flagbits: "+data);
        return data;
    }
}

class Worker
{
    public static void main(String args[])
    {
        if(args.length == 0){
            System.out.println("Please pass some data..!! Terminating..!!");
            System.exit(0);
        }
        BitStuffing bitStuffing = new BitStuffing();   
        String stuffed_frame = bitStuffing.stuffing(args[0]);
        System.out.println("Stuffed frame: " + stuffed_frame);
        System.out.println("Destuffed frame"+bitStuffing.deStuffing(stuffed_frame));
    }
}

