package oop.uebung5;

public class Frachtflugzeug extends Flugzeug {
	float ladung;

	public Frachtflugzeug() {
		super("Bitte Werte ändern!", 1, 0, 0, 0);
		this.ladung = 0;
	}

	public Frachtflugzeug(String kennzeichen, float mGewicht, float lGewicht, float mTankI, float tankI, float ladung) {
		super(kennzeichen, mGewicht, lGewicht, mTankI, tankI);
		if (super.gewicht() + ladung > mGewicht) {
			System.out.println("Unzulässige Ladung!");
		} else {
			this.ladung = ladung;
		}
	}

	public void beladen(float zuLaden) {
		if (this.gewicht() + zuLaden > this.maximalesGewicht) {
			System.out.println(zuLaden + "kg kann nicht geladen werden.");
		} else {
			this.ladung += zuLaden;
		}
	}

	public void entladen() {
		this.ladung = 0;
		System.out.println("Flugzeug entladen!");
	}

	public float gewicht() {
		return this.leerGewicht + this.tankInhalt + this.ladung;
	}
	
	public String toString() {
		String daten = this.kennzeichen + ": " + this.gewicht() + "kg von " 
				+ this.maximalesGewicht + "kg Gewicht und " + this.ladung + "kg Ladung.";
		return daten;
	}
}
