public class StringSameObjectCheck {
    public static void main(String[] args) {
        String str1 = "hello";
        String str2 = "hello";

        System.out.println("Both variables point to the same object: "+ (str1 == str2));
    }
}
