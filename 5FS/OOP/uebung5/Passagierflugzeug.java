package oop.uebung5;

public class Passagierflugzeug extends Flugzeug {

	static int DELTAFETT = 75;

	int passagiere;
	int maxPassagiere;

	public Passagierflugzeug() {
		super();
		this.passagiere = 0;
		this.maxPassagiere = 0;
	}

	public Passagierflugzeug(String kennzeichen, float mGewicht, float lGewicht, 
			float mTankI, float tankI, int passa, int mPassa) {
		super(kennzeichen, mGewicht, lGewicht, mTankI, tankI);
		this.passagiere = passa;
		if (super.gewicht() + mPassa * DELTAFETT > this.maximalesGewicht) {
			System.out.println("Abspecken! Maximale PAssagieranzahl zu Hoch");
		} else {
			this.maxPassagiere = mPassa;
		}
	}

	public void einsteigen(int leute) {
		if (this.passagiere + leute > this.maxPassagiere) {
			System.out.println("Soviel Leute können nicht einsteigen!");
		}
		this.passagiere += leute;
	}

	public void aussteigen(int leute) {
		if (this.passagiere - leute < 0) {
			System.out.println("Soviel Leute können nicht aussteigen!");
		} else {
			this.passagiere -= leute;	
		}
	}
	
	public float gewicht() {
		return this.leerGewicht + this.tankInhalt + this.passagiere * DELTAFETT;
	}
	
	public String toString() {
		String daten = this.kennzeichen + ": " + this.gewicht() + "kg von " 
				+ this.maximalesGewicht + "kg Gewicht und " + this.passagiere + " Passagieren.";
		return daten;
	}
}
