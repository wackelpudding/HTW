package oop.uebung8;

public abstract class AbstractTime {
	
	protected int hours, minutes, seconds;
	
	/**
	 * @return the time in seconds
	 */
	public abstract int toSeconds();
	
	/**
	 * @param hours the number of hours to add 
	 * @param minutes the number of minutes to add
	 * @param seconds the number of seconds to add
	 */
	public abstract void turnForward(int hours, int minutes, int seconds);
	
	/**
	 * @param hours the number of hours to subtract 
	 * @param minutes the number of minutes to subtract
	 * @param seconds the number of seconds to subtract
	 */
	public abstract void turnBackward(int hours, int minutes, int seconds);
}
