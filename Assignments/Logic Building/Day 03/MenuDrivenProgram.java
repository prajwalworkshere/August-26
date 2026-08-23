import java.util.Scanner;

public class MenuDrivenProgram {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in); 
        //for continue the loop until we want then use do while loop and set condition choice !=0 for exit 
        System.out.println("Enter The Number of Operation you want to perfrom:\n 1. Grade Evaluation System\n 2. Leap Year Check\n 3. Day Of Week\n 4. Identity default Values ");

        int chioce= sc.nextInt();

        switch (chioce) {
            case 1:
                gradeEvalution();
                 break;
            case 2:
                leapYearCheck();
                break;
            case 3:
                dayOfWeeks();
                break;
            case 4:
                defaultValue();
                break;        
            default:
                System.out.println("Invalid Choice ");
                break;
        }
    }

        public static void gradeEvalution(){
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter MAths Marks- ");
            int maths =sc.nextInt();
            System.out.println("Enter Science Marks- ");
            int science =sc.nextInt();
            System.out.println("Enter Physics Marks- ");
            int physics =sc.nextInt();

            double avgMarks= (maths+science+physics)/3.0;

            System.out.println("Your Average Marks :- "+ avgMarks);

            if (avgMarks>=90) {
                System.out.println("Grade A");
            }
            else if (avgMarks<=89&&avgMarks>=70) {
                System.out.println("Grade B");
            }
            else if (avgMarks<=69&&avgMarks>=50) {
                System.out.println("Grade C");
            }
            else if (avgMarks<=49&&avgMarks>=30) {
                System.out.println("Grade D");
            }
            else{
                System.out.println("Failed");
            }
        }

        public static void leapYearCheck() {
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

        public static void dayOfWeeks() {
            Scanner sc= new Scanner(System.in);
            System.out.println("ENTER THE NO TO GET RESPECTIVE DAY: ");
            int number= sc.nextInt();

            switch (number) {
                case 1:
                    System.out.println("Monday");
                    break;
                case 2:
                    System.out.println("Tuesday");
                    break;
                case 3:
                    System.out.println("Wednesday");
                    break;
                case 4:
                    System.out.println("Thursday");
                    break;
                case 5:
                    System.out.println("Friday");
                    break;
                case 6:
                    System.out.println("Saturdaay");
                    break;
                case 7:
                    System.out.println("Sunday");
                    break;
                default:
                    System.out.println("Invalid Day Number");
                    break;
            }
        }

        public static void defaultValue() {
            byte a = 10;
            short b = 740;
            int c = 4562;
            long d = 18600L;
            float e = 10.5f;
            double f = 99.99;
            char g = 'p';
            boolean h = true;
            System.out.println("byte a: " + a);
            System.out.println("short b: " + b);
            System.out.println("int c: " + c);
            System.out.println("long d: " + d);
            System.out.println("float e: " + e);
            System.out.println("double f: " + f);
            System.out.println("char g: " + g);
            System.out.println("boolean h: " + h);
        }
    
}



