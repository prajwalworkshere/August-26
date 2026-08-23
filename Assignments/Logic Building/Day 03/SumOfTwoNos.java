import java.util.Scanner;
public class SumOfTwoNos {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        
        System.out.print("Enter First umber: ");
        int num1=sc.nextInt();
        System.out.print("Enter Second Number: ");
        int num2=sc.nextInt();

        int sum=sumOfTwoNumbers(num1, num2);
        System.out.print("The Sum of "+num1+" And "+num2+" is "+sum);

    }
    public static int sumOfTwoNumbers(int a,int b){
        int result=a+b;
        return result;
    }
}
