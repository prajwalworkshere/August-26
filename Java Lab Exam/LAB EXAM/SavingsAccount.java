public class SavingsAccount extends Account{
    SavingsAccount(int accountNumber,double balance){
        super(accountNumber,balance);
    }
    public void withdraw(double withdrawAmount) throws InsufficientBalanceException{
      if(balance-withdrawAmount<500){ //400<500
         throw new InsufficientBalanceException();
      }else{
      balance=balance-withdrawAmount;
      }
    }
}