import java.util.Scanner;
import java.io.BufferedReader;

class CharacterStuffing
{
    String flagBit, escSeq;
    CharacterStuffing(){
        flagBit = "ABC";  
        escSeq = "ESC";
    }

    String stuffing(String data)
    {
        int start=0;
        int flagIdx=0;  // to hold the index where flagBit occurs in the sequence..
        int escIdx=0;   // to hold the index where escSeq occurs in the sequence..

        // We need to prefix the escSeq (ESC) either the flagBit comes or escSeq comes..
        while( ((flagIdx = data.indexOf(flagBit, start)) != -1) || ((escIdx = data.indexOf(escSeq, start)) != -1))
        {
            if(flagIdx != -1){
                //System.out.println("idx = "+idx +", str: "+data.substring(idx+troubleSeq.length(), data.length()));
                data = data.substring(0, flagIdx) + escSeq +data.substring(flagIdx+flagBit.length(), data.length());
                start = flagIdx+escSeq.length()+flagBit.length(); // Updating the index from where to search in next turn...
            //System.out.print
            }
            if(escIdx != -1){
                data = data.substring(0, escIdx) + escSeq +data.substring(escIdx+escSeq.length(), data.length());
                start = escIdx + escSeq.length() + escSeq.length(); // Updating the index from where to search in next turn...
            }

        }
        //System.out.println(idx);
        System.out.println("[INFO] Stuffed String: " + data);
        data = flagBit + data + flagBit;
        System.out.println("[INFO] After placing flagbits: "+data);
        return data;
    }
/*
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
    }*/
}

class Worker
{
    public static void main(String args[])
    {
        if(args.length == 0){
            System.out.println("Please pass some data..!! Terminating..!!");
            System.exit(0);
        }
        CharacterStuffing characterStuffing = new CharacterStuffing();   
        String stuffed_frame = characterStuffing.stuffing(args[0]);
        System.out.println("Stuffed frame: " + stuffed_frame);
        //System.out.println("Destuffed frame"+characterStuffing.deStuffing(stuffed_frame));
    }
}

