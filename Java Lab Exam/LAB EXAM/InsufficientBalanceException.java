public class InsufficientBalanceException extends Exception{
    public InsufficientBalanceException(){
        super("Withdrawal denied due to insufficient balance");
    }
}