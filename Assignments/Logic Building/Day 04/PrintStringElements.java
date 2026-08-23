import java.util.Scanner;

public class PrintStringElements {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] names = new String[5];

        System.out.println("Enter 5 Names: ");

        for (int i = 0; i < names.length; i++) {
            names[i] = sc.next();
        }   
        
        for (String name : names) {
            System.out.print(name + " ");
        }
    }
}