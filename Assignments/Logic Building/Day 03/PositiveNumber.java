import java.util.Scanner;

public class PositiveNumber {
    public static void main(String[] args) {
        askForPositiveNumber();
    }

    public static void askForPositiveNumber(){
        Scanner sc= new Scanner(System.in);
        int input;
        do{
           System.out.println("Enter The Positive Number"); 
           input= sc.nextInt();

        }while(input<=0);

        System.out.println("You ENtered The Positive Number:- "+input);
    }
}
