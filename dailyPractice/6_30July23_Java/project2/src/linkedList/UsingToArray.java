package linkedList;

import java.util.Arrays;
import java.util.LinkedList;

public class UsingToArray {
	public UsingToArray() {
		String colors[]= {"Red","Green","Blue"};
		LinkedList<String> links = new LinkedList<String>(Arrays.asList(colors));
		
		links.addLast("Black");
		links.add("pink");
		links.add(3, "green");
		links.addFirst("cyan");
		
		colors = links.toArray(new String[links.size()]);
		
		System.out.println("Colors: ");
		
		for(String s: colors) {
			System.out.print(s+", ");
		}
	}
	
	public static void main(String args[]) {
		new UsingToArray();
	}

}
