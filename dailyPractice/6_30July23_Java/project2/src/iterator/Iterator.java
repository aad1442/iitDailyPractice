package iterator;
import java.util.ArrayList;
import java.util.ListIterator;

public class Iterator {
	
	public void IteratorCheck() {
		ListIterator iterator = new 
	}
	
	public static void main(String[] args) {
		final String[] array= {"adfg","dfgdfg","sdfgsd","dfgdf"};
		
		ArrayList<String>list = new ArrayList<>();
		for(String n: array) {
			list.add(n);
		}
		
		ListIterator<String> iterator = list.listIterator();
		
		while(iterator.hasNext()) {
			System.out.println(iterator.next());
			System.out.println(iterator.next().toUpperCase());
			if(iterator.next().equals("adfg")) {
				System.out.println("Adnan");
			}
			list.add(iterator.next());
			//list.remove(iterator.nextIndex());
		}
		System.out.println(list);
		

	}

}
