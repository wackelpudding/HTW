package oop.uebung5;

public class Frachtflugzeug extends Flugzeug {
	float ladung;
	
	public Frachtflugzeug() {
		super(null,1,0,0,0);
		this.ladung = 0;
	}
	
	public Frachtflugzeug(String kennzeichen, float mGewicht, float lGewicht, float mTankI, float tankI,float ladung) {
		super(kennzeichen, mGewicht, lGewicht, mTankI, tankI);
		this.ladung = ladung;
	}
	
	public float beladen(float ladung) {
		float temp = 0;
		float actLoad = super.gewicht();
		if(actLoad + ladung > this.maximalesGewicht) {
			temp = Math.abs(this.maximalesGewicht - (actLoad + ladung));
			ladung -= temp;
		}
		return actLoad + ladung;
	}
	
	public void entladen() {
		this.ladung = 0;
	}
	
	public float gewicht() {
		return this.leerGewicht + this.tankInhalt + this.ladung;
	}
}

