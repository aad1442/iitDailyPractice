package projectName1;

import java.util.Arrays;

public class UsingArrays {
	
	private int intArray[]= {1,2,3,4,5,6,7};
	private double doubleArray[]= {1,2,3,4,5,6};
	private int[] filledArray, arrayCopy;
	
	public UsingArrays() {
		filledArray = new int[10];
		arrayCopy = new int[intArray.length];
		
		Arrays.fill(filledArray, 7);
		Arrays.sort(doubleArray);
		
		System.arraycopy(intArray,0,arrayCopy,0,intArray.length);
		
		
	}

}
