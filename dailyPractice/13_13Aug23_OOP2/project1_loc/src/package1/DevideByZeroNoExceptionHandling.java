package package1;
import java.util.Scanner;

public class DevideByZeroNoExceptionHandling {
	
	public static int quotient(int numerator, int denominator) {
		return numerator / denominator;
	}
	
	

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Please enter an integer:");
		int numerator = sc.nextInt();
		System.out.println("Please enter an integer:");
		int denominator = sc.nextInt();
		
		int result = quotient(numerator,denominator);
		System.out.printf(
				"\n Result: %d/%d=%d\n",numerator,denominator,result);

	}

}
