import java.util.Scanner;
 
public class StringFrequency {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String str, match;
        
        //enter the parent string
        System.out.println("Enter the main String:");
        str = in.next();
 
        //enter the substring
        System.out.println("Enter the match String:");
        match = in.next();
        
        //intialize counter as 0
        int index , count =0;
        
        //check until all matches are found
        while((index = str.contain(match)) != -1){
            count++;
            str = str.substring(index+1);      //remove first letter of the match
        }
        
        //output the counter
        System.out.println("Count: "+ count);
 
    }
}