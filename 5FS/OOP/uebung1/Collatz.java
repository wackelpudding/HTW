package oop.uebung1;

import java.util.Scanner;

public class Collatz {
	public static void printCollatz(int n) {
		System.out.println("Hier die vesprochene Collatz Folge:");
		System.out.print(n + " ");
		while (n > 1) {
			if ((n % 2) == 0) {
				n = n / 2;
				System.out.print(n + " ");
			} else {
				n = (3 * n) + 1;
				System.out.print(n + " ");
			}
		}
		System.out.print("\n");
	}

	public static void printCollatzFor(int n) {
		System.out.println("\n----------\nHier die vesprochene Collatz Folge, als For-Schleife:");
		System.out.print(n + " ");
		for (int i = 0; i < 500; i++) {
			if (n == 1) {
				break;
			}
			if ((n % 2) == 0) {
				n = n / 2;
				System.out.print(n + " ");
			} else {
				n = (3 * n) + 1;
				System.out.print(n + " ");
			}
		}
		System.out.print("\n");
	}

	public static int printCollatzRek(int n) {
		System.out.print(n + " ");
		if (n == 1) {
			System.out.print("\n");
			return n;
		} else if ((n % 2) == 0) {
			return printCollatzRek(n / 2);
		} else {
			return printCollatzRek((3 * n) + 1);
		}
	}

	public static void main(String[] args) {
		int n;

		System.out.println("Dieses Programm gibt die Collatz Folge aus.");
		System.out.println("Bitte geben sie hierfür eine natürliche Zahl ein:");
		Scanner readInput = new Scanner(System.in);
		try {
			n = Integer.parseInt(readInput.nextLine());
			printCollatz(n);
			printCollatzFor(n);
			System.out.println("\n----------\nHier die vesprochene Collatz Folge, als Rekursion:");
			printCollatzRek(n);
		} catch (NumberFormatException trottel) {
			System.out.println("Keine Zahl eingegeben!\nAbbruch!");
		}
	}
}
