import java.util.Scanner;

public class Factorial {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter The Number:- ");
        int number=sc.nextInt();
        int product=1;
        for(int i=1;i<=number;i++){
            product=product*i;
        }
        System.out.println("The Factorial Of "+number+" Is s "+ product);
    }
}
