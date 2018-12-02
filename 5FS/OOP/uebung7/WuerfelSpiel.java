package oop.uebung7;

import java.util.concurrent.TimeUnit;
import java.util.Scanner;

public class WuerfelSpiel {

	protected Wuerfel wuerfel;
	protected Spieler spieler1, spieler2, sieger;

	WuerfelSpiel() {
		this(1, 6, "Test-Spieler1", "Test-Spieler2");
	}

	WuerfelSpiel(int wMin, int wMax, String s1, String s2) {
		this.sieger = new Spieler(" ");
		this.wuerfel = new Wuerfel(wMin, wMax);
		this.spieler1 = new Spieler(s1);
		this.spieler2 = new Spieler(s2);
	}

	public void starten() throws InterruptedException {
		int ergebnisS1, ergebnisS2;
		boolean ende = false;
		this.sieger = new Spieler(" ");
		int round = 1;

		do {
			System.out.println("Runde: " + round);
			ergebnisS1 = this.wuerfel.wuerfeln();
			System.out.println(this.spieler1.name + " würfelt: " + ergebnisS1);
			ergebnisS2 = this.wuerfel.wuerfeln();
			System.out.println(this.spieler2.name + " würfelt: " + ergebnisS2);
			if (ergebnisS1 > ergebnisS2) {
				this.sieger = this.spieler1;
				ende = true;

			} else if (ergebnisS2 > ergebnisS1) {
				this.sieger = this.spieler2;
				ende = true;
			}
			round++;
			TimeUnit.SECONDS.sleep(1);
		} while (!ende);
		this.gewinnerAusdrucken();

	}

	private void gewinnerAusdrucken() {
		System.out.println("Der Sieger ist....." + this.sieger.name);
	}

	public static void main(String[] args) throws InterruptedException {
		// Vars
		Scanner scan = new Scanner(System.in);
		String s1, s2;
		int wMin, wMax;

		//Input
		System.out.println("Spieler 1: ");
		s1 = scan.nextLine();
		System.out.println("Spieler 2: ");
		s2 = scan.nextLine();
		System.out.println("Würfel von: ");
		wMin = scan.nextInt();
		System.out.println("bis: ");
		wMax = scan.nextInt();
		scan.close();
		
		//WuerfelSpiel erzeugen
		WuerfelSpiel spiel = new WuerfelSpiel(wMin, wMax, s1, s2);

		//Firlefanz und danach spiel starten
		System.out.println("generating Setup...");
		TimeUnit.SECONDS.sleep(1);
		System.out.println(".");
		TimeUnit.SECONDS.sleep(1);
		System.out.println(".");
		TimeUnit.SECONDS.sleep(1);
		System.out.println(".");
		TimeUnit.SECONDS.sleep(1);
		System.out.println("lets roll!...");
		spiel.starten();

	}
}
