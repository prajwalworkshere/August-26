import java.util.*;
public class BankSystem{
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        System.out.println("Enter The Details:");
        System.out.println("Enter Account Type");
        String accountType= sc.nextLine();
        System.out.println("Enter Account Number");
        int accountNumber= sc.nextInt();
        System.out.println("Enter the Balance");
        double balance= sc.nextDouble();
        System.out.println("Enter Account to Withdraw");
        double withdrawAmount= sc.nextDouble();

        Account account;
        
        if(accountType.equalsIgnoreCase("savings")){
           account = new SavingsAccount(accountNumber, balance);
        }
        else{
             account= new CurrentAccount(accountNumber, balance);
        }

        try {
            account.withdraw(withdrawAmount);
            System.out.println("Withdrawal successful");
            System.out.println("Remaining Balance:" + account.getBalance());
        } catch (InsufficientBalanceException e) {
            System.out.println(e.getMessage());           
        }

    }
}