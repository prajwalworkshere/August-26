public class StringIntern {
    public static void main(String[] args) {
        String str1 = new String("hello");
        String str2 = str1.intern();
        String str3 = "hello";
        boolean result= str2==str3;

        System.out.println(" str2 and str3 pointing to the same object? "+result);
    }
}