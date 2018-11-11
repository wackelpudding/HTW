package oop.uebung5;

public class Flugzeug {
	String kennzeichen;
	float maximalesGewicht;
	float leerGewicht;
	float maxTankInhalt;
	float tankInhalt;
	
	public Flugzeug() {
		this("Test",1,0,0,0);
	}
	
	public Flugzeug(String kennzeichen, float mGewicht, float lGewicht, float mTankI, float tankI) {
		this.kennzeichen = kennzeichen;
		if (lGewicht + mTankI >= mGewicht) {
			this.maximalesGewicht = lGewicht + mTankI + 1;
		} else {
			this.maximalesGewicht = mGewicht;
		}
		this.leerGewicht = lGewicht;
		this.maxTankInhalt = mTankI;
		this.tankInhalt = tankI;
	}
	
	public float gewicht() {
		return this.leerGewicht + this.tankInhalt;
	}
	
	public void tanken(float treibstoff) {
		float temp;
		if (this.tankInhalt + treibstoff > this.maxTankInhalt){
			temp =  Math.abs(this.maxTankInhalt - (this.tankInhalt + treibstoff));
			this.tankInhalt += temp;
		} else {
			temp = treibstoff;	
			this.tankInhalt += temp;
		}
		if (this.gewicht() > this.maximalesGewicht) {
			temp = Math.abs(this.maximalesGewicht - this.gewicht());
			this.tankInhalt -= temp;
		}
		
	}
	
	
}
