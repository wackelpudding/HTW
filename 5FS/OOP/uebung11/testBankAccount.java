package oop.uebung11;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class testBankAccount {

	@Test
	public void testWithdrawValid() {
		BankAccount a = new BankAccount(123, 300.0);
		a.deposit(100.0);
		a.withdraw(200.0);
		assertTrue(a.getBalance() == -100.0);
	}
	
	@Test
	public void testDepositValid() {
		BankAccount a = new BankAccount(123, 0.0);
		a.deposit(100.0);
		assertTrue(a.getBalance() == 100.0);
	}
	
	@Test
	public void testTransferValid() {
		BankAccount a = new BankAccount(123, 0.0);
		BankAccount b = new BankAccount(456, 0.0);
		a.deposit(100.0);
		BankAccount.transfer(a, b, 50.0);
		assertTrue(a.getBalance() == 50.0);
		assertTrue(b.getBalance() == 50.0);
	}

}
