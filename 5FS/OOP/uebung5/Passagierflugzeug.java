package oop.uebung5;

public class Passagierflugzeug extends Flugzeug {
	
	static float deltafett = 75;
	
	int passagiere;
	int maxPassagiere;
	
	public Passagierflugzeug() {
		super();
		this.passagiere = 0;
		this.maxPassagiere = 0;
	}
	
	public Passagierflugzeug(String kennzeichen, float mGewicht, float lGewicht, float mTankI, float tankI, int passa, int mPassa) {
		super(kennzeichen, mGewicht, lGewicht, mTankI, tankI);
		this.passagiere = passa;
		if (super.gewicht() + mPassa * deltafett > this.maximalesGewicht) {
			System.out.println("Abspecken! Maximale PAssagieranzahl zu Hoch");
		} else {
			this.maxPassagiere = mPassa;
		}	
	}
	
	public void einsteigen (int leute) {
		float temp = 0;
		if (this.passagiere + leute > this.maxPassagiere) {
			temp = Math.abs(this.maxPassagiere - leute - this.passagiere);
			leute -= temp;
		}
		this.passagiere += leute;
	}
	
	public void aussteigen(int leute) {
		float temp = 0;
		if (this.passagiere - leute < 0) {
			temp = Math.abs(this.passagiere - leute);
			leute -= temp;
		}
		this.passagiere -= leute;
	}
}
