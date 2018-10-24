package oop.uebung1;

import java.util.Scanner;

public class WhoIsThere {
	public static void main(String[] args) {
		String name;

		do {
			System.out.println("Wer ist da?");
			Scanner readInput = new Scanner(System.in);
			name = readInput.nextLine();
			if (!name.isEmpty()) {
				System.out.println("Hallo " + name + "!");
			} else {
				System.out.println("....Hallo?");
			}
		} while (name.isEmpty());
	}
}
