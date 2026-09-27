public class CurrentAccount extends Account{
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