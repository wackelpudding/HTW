package oop.uebung5;

public class Flugzeug {
	String kennzeichen;
	float maximalesGewicht;
	float leerGewicht;
	float maxTankInhalt;
	float tankInhalt;

	public Flugzeug() {
		this("Bitte Werte ändern!", 1, 0, 0, 0);
	}

	public Flugzeug(String kennzeichen, float mGewicht, float lGewicht, 
			float mTankI, float tankI) {

		if (lGewicht + mTankI >= mGewicht) {
			System.out.println("Unzulässiges Maximalgewicht, bitte "
					+ "geben Sie ein gültiges Maximalgewicht an!");
		} else {
			this.maximalesGewicht = mGewicht;
			this.kennzeichen = kennzeichen;
			this.leerGewicht = lGewicht;
			this.maxTankInhalt = mTankI;
			this.tankInhalt = tankI;
		}

	}

	public float gewicht() {
		return this.leerGewicht + this.tankInhalt;
	}

	public void tanken(float treibstoff) {
		float temp;
		temp = this.gewicht() + treibstoff;
		if (temp > this.maximalesGewicht || treibstoff < 0 || 
				this.tankInhalt + treibstoff > this.maxTankInhalt) {
			System.out.println(treibstoff + "kg können Sie nicht tanken.");
		} else {
			this.tankInhalt += treibstoff;
		}

	}
	
	public String toString() {
		String daten = this.kennzeichen + ": " + this.gewicht() + "kg von " 
				+ this.maximalesGewicht + "kg Gewicht.";
		return daten;
	}

}
