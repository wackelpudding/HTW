package oop.uebung11;

import org.junit.jupiter.api.Test;

import static oop.uebung11.BankAccount.*;
import static org.junit.jupiter.api.Assertions.*;

public class TestBankAccount {


    @Test
    void testDeposit(){
        BankAccount a = new BankAccount(0, 0);
        a.deposit(100);
        assertEquals(true, a.getBalance() == 100);
    }

    @Test
    void testWithdraw(){
        BankAccount b = new BankAccount(0, 0);
        b.deposit(100);
        b.withdraw(1);
        assertEquals(true, b.getBalance() == 99);
    }

    @Test
    void testTransfer(){
        BankAccount c = new BankAccount(0, 2000);
        BankAccount d = new BankAccount(1,300);
        transfer(c,d,200);
        assertEquals(true, c.getBalance()== -200);
        assertEquals(true, d.getBalance()== 200);
    }

    @Test
    void testNegativeWithdraw(){
        BankAccount e = new BankAccount(0, 0);
        e.withdraw(-20);
        assertEquals(true, e.getBalance() == 0);
    }

    @Test
    void testNegativeDeposit(){
        BankAccount f = new BankAccount(0, 0);
        f.deposit(-20);
        assertTrue(f.getBalance() == 0);
    }

    @Test
    void testBalanceExceededFromWithdraw(){
        BankAccount g = new BankAccount(0, 0);
        g.withdraw(2);
        assertTrue(g.getBalance() == 0);
    }

    @Test
    void testBalanceExceededFromTransfer(){
        BankAccount h = new BankAccount(0, 0);
        BankAccount j = new BankAccount(1,0);
        transfer(h,j, 2);
        assertTrue(h.getBalance()== 0);
        assertTrue(j.getBalance() == 0);
    }

    @Test
    void testCreateNegativeDispo(){
        BankAccount k = new BankAccount(0, -500);
        assertTrue(k.getDispo() == 0);
    }

    @Test
    void testNegativeTransfer(){
        BankAccount l = new BankAccount(0, 50);
        BankAccount m = new BankAccount(1,0);
        transfer(l,m, -50);
        assertTrue(l.getBalance()== 0);
        assertTrue(m.getBalance() == 0);
    }

    @Test
    void testCreateNegativeAccountNumber(){
        BankAccount o = new BankAccount(-1,0);
        assertTrue(o.getNumber() == 0);
    }


}