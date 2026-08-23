import java.util.Scanner;

class CheckLeapYear{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Year to CHeck:- ");
        int year = sc.nextInt();

        if ((year%4==0 && year%100!=0) || year%400==0 ) {
            System.out.println(year +" is Leap Year ");            
        }
        else{
            System.out.println("Year is not a leap Year ");
        }
    }
}