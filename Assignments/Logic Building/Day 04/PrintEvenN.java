import java.util.Scanner;

public class PrintEvenN {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter Number :- ");
        int number= sc.nextInt();
        for(int i=1;i<=number;i++){
            if (i%2==0) {
                System.out.print(i+" ");
            }
        }
    }
}