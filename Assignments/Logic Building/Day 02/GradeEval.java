import java.util.*;

public class GradeEval{

    public static void main(String[] args) {

        // GradeEval obj1= new GradeEval();
        // double avgMarks = obj1.average(); // for non static method average 

        double avgMarks= average();
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

    public static double average(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter MAths Marks- ");
        int maths =sc.nextInt();
        System.out.println("Enter Science Marks- ");
        int science =sc.nextInt();
        System.out.println("Enter Physics Marks- ");
        int physics =sc.nextInt();

        double avgMarks= (maths+science+physics)/3.0;
        return avgMarks;
    }


    
}