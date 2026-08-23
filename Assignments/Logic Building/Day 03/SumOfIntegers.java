import java.util.Scanner;

public class SumOfIntegers {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter The Number Till You Want Sum:- ");
        int number=sc.nextInt();
        calculateSum(number);
    }
    public static void calculateSum(int num) {
        int sum=0;
        for(int i=1;i<=num;i++){
            sum=sum+i;
        }
        System.out.println("The Sum of 1 "+"to "+num+ " Is "+ sum);
    }
}
