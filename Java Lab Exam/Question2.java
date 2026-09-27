import java.util.*;
class InsufficientBalanceException extends Exception{
    public InsufficientBalanceException(){
        super("Withdrawal denied due to insufficient balance");
    }
}

class Account{
    protected int accountNumber;
    protected double balance;
    Account(int accountNumber,double balance){
        this.accountNumber=accountNumber;
        this.balance=balance;
    }

    public void withdraw(double withdrawAmount) throws InsufficientBalanceException{
        if(withdrawAmount>balance){
            throw new InsufficientBalanceException();
        }
        balance=balance-withdrawAmount;
    }

    public double getBalance(){
        return balance;
    }
}

class SavingsAccount extends Account{
    SavingsAccount(int accountNumber,double balance){
        super(accountNumber,balance);
    }


    public void withdraw(double withdrawAmount) throws InsufficientBalanceException{
      if(balance-withdrawAmount<500){ //1000-600=400 400<500
         throw new InsufficientBalanceException();
      }else{
      balance=balance-withdrawAmount;
      }
    }
}

class CurrentAccount extends Account{
    CurrentAccount(int accountNumber,double balance){
        super(accountNumber,balance);
    }

    public void withdraw(double withdrawAmount) throws InsufficientBalanceException{
      if(balance-withdrawAmount<0){
         throw new InsufficientBalanceException();
      }
      balance=balance-withdrawAmount;
    }
}

public class Question2{
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