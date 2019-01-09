package oop.uebung11;

public class BankAccount {

	private int number;
	private double balance;
	private double dispo;

	public BankAccount(int number, double dispo) {
		this.number = number;
		this.dispo = dispo;
	}
	
	public double getBalance() {
		return this.balance;
	}
	
	public double getDispo() {
		return this.dispo;
	}

	public void deposit(double amount) {
		balance += amount;
	}
	
	public void withdraw(double amount) {
		balance -= amount;
	}
	
	public static void transfer(BankAccount sender, BankAccount receiver, double amount) {
		sender.withdraw(amount);
		receiver.deposit(amount);
	}
}
