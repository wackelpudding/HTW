package oop.uebung8;

public class IllegalTimeException extends Exception {
	
	private static final long serialVersionUID = 1;
	
	private String wrongTime;
	
	public IllegalTimeException (String reason) {
		super(reason);
	}
	
	public IllegalTimeException (String reason, String wrongTime) {
		super(reason);
		this.wrongTime = wrongTime;
	}

	public String getMessage() {
		return String.format("%s -> %s ", super.getMessage() ,this.wrongTime);
	}
}
