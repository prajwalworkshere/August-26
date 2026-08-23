import java.util.Scanner;
public class LargestArrayElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] numbers = new int[5];
        int largest=0;

        System.out.println("Enter 5 integers: ");

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = sc.nextInt();
        }   

        for (int num : numbers){
            if(num>largest){
                largest=num;
            }
        }
        System.out.println("Largest Element:- "+largest);
    }
}
