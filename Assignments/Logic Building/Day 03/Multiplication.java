import java.util.Scanner;

public class Multiplication {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter The Number Of which you want Table:- ");
        int number= sc.nextInt();
        printMultiplicationTable(number);
    }
    public static void printMultiplicationTable(int input) {
        int start=1;
        int end=10;
        int number=input;
        for(int i=start;i<=end;i++){
            System.out.println(number+" * "+i+" = "+number*i);
        }
    }
}
