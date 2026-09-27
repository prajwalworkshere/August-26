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
