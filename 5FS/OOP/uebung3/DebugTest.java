package oop.uebung3;

import java.util.Arrays;

class DebugTest {
	
	public static void main(String[] args) {
		int var = Integer.MIN_VALUE;
		int[] array1 = {var, var, var};
		var += Integer.MAX_VALUE;
		int[] array2 = {var+1, ~var, var/2};		
		while(!Arrays.equals(array1, array2)) {
			array1[++var] <<= 1;
		}
	}
}
