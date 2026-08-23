import java.util.Scanner;

public class AvgOfArrayElements{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numbers = new int[5];
        int sum=0;
        double average=0.0;

        System.out.println("Enter 5 integers: ");

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = sc.nextInt();
        }   
        
        for (int num : numbers) {
            sum=sum+num;
        }
        average=(sum)/numbers.length;
        System.out.println("The Average of All numbers Is "+average);
    }
}