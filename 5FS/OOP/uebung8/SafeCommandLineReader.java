package oop.uebung8;

import java.util.Scanner;
import java.util.InputMismatchException;
import java.util.concurrent.TimeUnit;

public class SafeCommandLineReader {

	static Scanner scan = new Scanner(System.in);

	public static int readInt() throws java.util.InputMismatchException, InterruptedException {
		while (true) {
			try {
				System.out.print("Bitte gib einen Integer ein: ");
				return scan.nextInt();
			} catch (InputMismatchException e) {
				e.printStackTrace();
				scan.next();
				TimeUnit.MICROSECONDS.sleep(1);

			}
		}
	}

	static float readFloat() throws java.util.InputMismatchException, InterruptedException {
		while (true) {
			try {
				System.out.print("Bitte gebe einen Float ein: ");
				return scan.nextFloat();
			} catch (InputMismatchException e) {
				e.printStackTrace();
				scan.next();
				TimeUnit.MICROSECONDS.sleep(1);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		int i = readInt();
		float a = readFloat();
	}
}
