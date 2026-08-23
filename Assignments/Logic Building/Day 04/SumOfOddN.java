import java.util.Scanner;
public class SumOfOddN {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter Number :- ");
        int number= sc.nextInt();
        int sum=0;
        for(int i=1;i<=number;i++){
            if (i%2!=0) {
                sum=sum+i;
            }
        }
    System.out.println("The Sum of odd Numbers from 1 to "+number+" Is "+ sum);
    }
}