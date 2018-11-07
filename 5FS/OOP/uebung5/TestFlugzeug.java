package oop.uebung5;

public class TestFlugzeug {

	public static void main(String[] args) {
		
		Flugzeug eins = new Flugzeug ("A-B2324", 50000, 20000, 25000, 20000);
		System.out.println(eins.kennzeichen + " " + eins.gewicht() + " von " + eins.maximalesGewicht);
		eins.tanken(20000);
		System.out.println("tanken...");
		System.out.println(eins.kennzeichen + " " + eins.gewicht() + " von " + eins.maximalesGewicht);
		
		//Frachtflugzeug

	}

}
