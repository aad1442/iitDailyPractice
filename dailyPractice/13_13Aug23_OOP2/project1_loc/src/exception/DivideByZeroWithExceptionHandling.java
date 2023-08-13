package exception;
import java.util.InputMismatchException;
import java.util.Scanner;

public class DivideByZeroWithExceptionHandling {
		
	public static int quotient(int numerator, int denominator)
		throws ArithmeticException{
			return numerator / denominator;
		}
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		boolean continueLoop = true;
		
		do
		{
			try
			{
				System.out.println("Please enter an integer numerator:");
				int numerator = sc.nextInt();
				System.out.println("Please enter an integer denominator:");
				int denominator = sc.nextInt();
				int result = quotient(numerator,denominator);
				System.out.printf("\nResult :%d/%d : %d",numerator, denominator, result);
				continueLoop = false;
			}
			catch(InputMismatchException InputMismatchException) {
				System.err.printf("\n Exception:%s",InputMismatchException);
				sc.nextLine();
				System.out.println("You must enter integer value");
			}
			catch(ArithmeticException arithmecticException) {
				System.err.printf("\n Exception: %s\n",arithmecticException);
				System.out.println("\n Zero ins an invalid number\n");
				
				
			}
			finally {
				System.out.println("\nU are in the OOP2 lab\n");
			}
			
		}while (continueLoop);

	}

}
