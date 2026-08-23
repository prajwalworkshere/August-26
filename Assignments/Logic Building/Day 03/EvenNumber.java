import java.util.Scanner;

public class EvenNumber {
   public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the number till you want even numberss:- ");
    int num= sc.nextInt();
    printEvenNumbers(num);
   } 

   public static void printEvenNumbers(int num){
    int start=1;
    while (start<=num) {
        // for(int i=0; i<range+1;i++){
        //     System.out.print(i);
        // }
        if (start%2==0) {
            System.out.print(start+" ");
        }
        start++;
    }
   }
}
