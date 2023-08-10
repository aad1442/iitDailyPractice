package vector;
import java.util.Vector;
import java.util.NoSuchElementException;

public class VectorTest {
	public static final String colors[] = { "red","white", "blue"};
	
	public VectorTest() {
		Vector<String> vector = new Vector<String>();
		printVector(vector);
		
		for(String color: colors)
			vector.add(color);
		printVector(vector);
		
		try {
			System.out.printf("First Element is %s\n",vector.firstElement());
			System.out.printf("Last Element is %s \n",vector.lastElement());
			
		}
		catch(NoSuchElementException exception) {
			exception.printStackTrace();
		}
		
		if(vector.contains("red")) {
			System.out.printf("\n \"red\" found at %d",vector.indexOf("red"));
		}else {
			System.out.println("\n \"red\" not found");
		}
		
		vector.remove("red");
		System.out.println("\n\"red\" is removed");
		printVector(vector);
		if(vector.contains("red")) {
			System.out.println("red is still there");
			
		}else {
			System.out.println("red perfectly removed");
		}
		
		System.out.printf("\n Size%d capacity%d\n",vector.size(),vector.capacity());
		
		
	}
	
	
	
	public static void main(String[] args) {
		System.out.println("Adnan");
		VectorTest v1 = new VectorTest();
	}
	
	private void printVector(Vector<String>vectorToOutput) {
		if(vectorToOutput.isEmpty()) {
			System.out.println("Vector is Empty.");
		}else {
			System.out.println("Vector contains");
			//output elements
			for(String element: vectorToOutput) {
				System.out.printf("%s ",element);
			}System.out.println("\n");
		}
	}

}
