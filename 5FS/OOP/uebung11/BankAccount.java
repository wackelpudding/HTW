package oop.uebung11;

public class BankAccount {

	private int number;
	private double balance;
	private double dispo;

	public BankAccount(int number, double dispo) {
		if (number >= 0 && dispo >= 0){
			this.number = number;
			this.dispo = dispo;
		} else {
			this.number = 0;
			this.dispo = 0;
		}

	}
	
	public double getBalance() {
		return this.balance;
	}
	
	public double getDispo() {
		return this.dispo;
	}

	public void deposit(double amount) {
		if( amount > 0){
			balance += amount;
		}
	}
	
	public boolean withdraw(double amount) {
		if (amount > 0 && amount <= balance+dispo) {
			balance -= amount;
			return true;
		}
		return false;
	}

	public int getNumber() {
		return this.number ;
	}
	
	public static void transfer(BankAccount sender, BankAccount receiver, double amount) {
		if (sender.withdraw(amount)) {
			receiver.deposit(amount);
		}
	}
}
