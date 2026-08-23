import java.util.Scanner;

public class PositiveNegativeElements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numbers = new int[5];
        int positive =0;
        int negative=0;

        System.out.println("Enter 5 integers: ");

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = sc.nextInt();
        }   
        
        for (int num : numbers) {
            if(num>0){
                positive=positive+1;
            }
            else{
                negative=negative+1;
            }
        }
        System.out.println("The Number of Postive Elements "+positive);
        System.out.println("The Number of Negative Elements "+negative);
    }
}