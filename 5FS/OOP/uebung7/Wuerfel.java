package oop.uebung7;

import java.util.concurrent.ThreadLocalRandom;

public class Wuerfel {
	private int minAugenZahl = 1;
	private int maxAugenZahl = 6;
	
	Wuerfel(){
		this(0,6);
	}
	
	Wuerfel(int min, int max){
		this.setMinAugenZahl(min);
		this.setMaxAugenZahl(max);
	}
	
	public void setMinAugenZahl(int min) {
		this.minAugenZahl = min;
	}
	
	public void setMaxAugenZahl(int max) {
		this.maxAugenZahl = max;
	}
	
	public int getMinAugenZahl() {
		return this.minAugenZahl;
	}
	
	public int getMaxAugenZahl() {
		return this.maxAugenZahl;
	}
	
	public int wuerfeln() {
		return ThreadLocalRandom.current().nextInt(this.getMinAugenZahl(), this.getMaxAugenZahl());
	}
}
