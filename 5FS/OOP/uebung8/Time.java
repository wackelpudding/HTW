package oop.uebung8;

public class Time extends AbstractTime implements Comparable, Printable {

	public Time(int hours, int minutes, int seconds) throws IllegalTimeException {
		super();
		this.setHours(hours);
		this.setMinutes(minutes);
		this.setSeconds(seconds);
	}

	public int getHours() {
		return hours;
	}

	public void setHours(int hours) throws IllegalTimeException {
		if (hours < 24 && hours >= 0) {
			this.hours = hours;
		} else {
			throw new IllegalTimeException("Ungültige Stunden eingegeben!", Integer.toString(hours));
		}
	}

	public int getMinutes() {
		return minutes;
	}

	public void setMinutes(int minutes) throws IllegalTimeException {
		if (minutes < 60 && minutes >= 0) {
			this.minutes = minutes;
		} else {
			throw new IllegalTimeException("Ungültige Minuten eingegeben!", Integer.toString(minutes));
		}

	}

	public int getSeconds() {
		return seconds;
	}

	public void setSeconds(int seconds) throws IllegalTimeException {
		if (seconds < 60 && seconds >= 0) {
			this.seconds = seconds;
	} else {
		throw new IllegalTimeException("Ungültige Sekunden eingegeben!", Integer.toString(seconds));
	}
	}

	@Override
	public int toSeconds() {
		return this.seconds + this.minutes * 60 + this.hours * 3600;
	}

	@Override
	public void turnForward(int hours, int minutes, int seconds) {
		int newSeconds = (this.seconds + seconds) % 60;
		minutes += (this.seconds + seconds) / 60;
		this.seconds = newSeconds;
		int newMinutes = (this.minutes + minutes) % 60;
		hours += (this.minutes + minutes) / 60;
		this.minutes = newMinutes;
		this.hours = (this.hours + hours) % 24;
	}

	@Override
	public void turnBackward(int hours, int minutes, int seconds) {
		int newSeconds = (this.seconds - seconds) % 60;
		newSeconds = newSeconds >= 0 ? newSeconds : 60 + newSeconds;
		minutes += (this.seconds - seconds) < 0 ? ((this.seconds - seconds - 60) / -60) : 0;
		this.seconds = newSeconds;
		int newMinutes = (this.minutes - minutes) % 60;
		newMinutes = newMinutes >= 0 ? newMinutes : 60 + newMinutes;
		hours += (this.minutes - minutes) < 0 ? ((this.minutes - minutes - 60) / -60) : 0;
		this.minutes = newMinutes;
		this.hours = (this.hours - hours) % 24;
		this.hours = this.hours >= 0 ? this.hours : 24 + this.hours;
	}

	@Override
	public int compareTo(Object obj) {
		try {
			Time time = (Time) obj;
			if (this.toSeconds() < time.toSeconds()) {
				return -1;
			} else if (this.toSeconds() == time.toSeconds()) {
				return 0;
			}
			return 1;
		} catch (ClassCastException e) {
			System.out.printf("\n%s\n", e.getMessage());
		}
		return 42;
	}

	public String toString() {
		String hoursPrefix = this.hours < 10 ? "0" : "";
		String minutesPrefix = this.minutes < 10 ? "0" : "";
		String secondsPrefix = this.seconds < 10 ? "0" : "";
		return hoursPrefix + this.hours + ":" + minutesPrefix + this.minutes + ":" + secondsPrefix + this.seconds;
	}
}
