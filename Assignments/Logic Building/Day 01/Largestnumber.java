public class Largestnumber {
    public static void main(String[] args) {
        int num1,num2;
        double num3;
        num1=20;
        num2=65;
        num3=20.31;

        if (num1>num2&&num1>num3) {
            System.out.println(num1+ " Is the largest number among 3");
        }
        else if(num2>num1&&num2>num3){
            System.out.println(num2+ " Is the largest number among 3");
        }
        else{
            System.out.println(num3+ " Is the largest number among 3");
       
        }
    
    }

}
