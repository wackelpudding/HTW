package oop.uebung6;

public class Time extends AbstractTime implements Comparable, Printable {

	public Time() {
		this(0, 0, 0);
	}

	public Time(int hours, int minutes, int seconds) {
		setHours(hours);
		setMinutes(minutes);
		setSeconds(seconds);

	}

	public int getHours() {
		return this.hours;
	}

	public int getMinutes() {
		return this.minutes;

	}

	public int getSeconds() {
		return this.seconds;
	}

	public void setHours(int h) {
		if (hours < 24 && hours >= 0) {
			this.hours = h;
		} else {
			System.out.println("Ungültiger Wert:\n H: " + hours);
		}
	}

	public void setMinutes(int m) {
		if (minutes < 60 && minutes >= 0) {
			this.minutes = m;
		} else {
			System.out.println("Ungültiger Wert:\n M: " + m);
		}
	}

	public void setSeconds(int s) {
		if (seconds >= 0 && seconds < 60) {
			this.seconds = s;
		} else

		{
			System.out.println("Ungültiger Wert:\n s: " + s);
		}
	}

	public int toSeconds() {
		return this.hours * 3600 + this.minutes * 60 + this.seconds;
	}

	public void turnForward(int hours, int minutes, int seconds) {
		int tempm, temph;
		tempm = ((this.seconds + seconds) / 60);
		temph = (((this.minutes + minutes) / 60) + (this.hours + hours) % 24);
		this.setSeconds(((this.getSeconds() + seconds) % 60));
		this.setMinutes(tempm + ((this.minutes + minutes) % 60));
		this.setHours(temph);

	}

	public void turnBackward(int hours, int minutes, int seconds) {
		int tempm, temph; // carry
		this.setSeconds(Math.abs(((this.getSeconds() - seconds + 60) % 60)));
		tempm = ((this.seconds + seconds) / 60);
		this.setMinutes(Math.abs(((this.minutes - minutes - tempm + 60) % 60)));
		temph = ((this.minutes + minutes + 60) / 60);
		this.setHours(Math.abs((this.hours - hours - temph + 24) % 24));
	}

	@Override
	public int compareTo(Object comparable) {
		Time toCompare = (Time) comparable;

		if (this.getHours() == toCompare.getHours()) {
			if (this.getMinutes() == toCompare.getMinutes()) {
				if (this.getSeconds() == toCompare.getSeconds()) {
					return 0;
				} else {
					if (this.getSeconds() > toCompare.getSeconds()) {
						return 1;
					} else {
						return -1;
					}
				}
			} else {
				if (this.getMinutes() > toCompare.getMinutes()) {
					return 1;
				} else {
					return -1;
				}
			}
		} else {
			if (this.getHours() > toCompare.getHours()) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	@Override
	public String toString() {
		String hh, mm, ss, time;
		if (this.hours < 10) {
			hh = "0" + String.valueOf(hours);
		} else {
			hh = String.valueOf(hours);
		}
		if (minutes < 10) {
			mm = "0" + String.valueOf(minutes);
		} else {
			mm = String.valueOf(minutes);
		}
		if (seconds < 10) {
			ss = "0" + String.valueOf(seconds);
		} else {
			ss = String.valueOf(seconds);
		}
		time = hh + ":" + mm + ":" + ss;
		return time;
	}
}
