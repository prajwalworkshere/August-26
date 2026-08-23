
import java.util.Scanner;


public class AgeCheck {
    public static void main(String[] args) {
        System.out.println("Welcome to Age Check Program:- ");

        Scanner sc =new Scanner(System.in);
        System.out.print("Enter YOur Age:- ");
        int age = sc.nextInt();
        checkAgeCategory(age);
    }

    public static void checkAgeCategory(int age){
        if (age<18) {
            System.out.println("Minor");}
        else if (age>=18&&age<60) {
            System.out.println("Adult");}
        else{
            System.out.println("Senior Citizen");
        }

    }
    
}
