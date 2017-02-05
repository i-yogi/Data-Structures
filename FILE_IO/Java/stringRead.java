import java.util.*;
import java.io.*;

public class stringRead{

	public static void main(String[] args) throws IOException{
		private String filename = "char.txt";

		BufferedReader br = new BufferedReader(new FileReader(filename));

		Scanner in = new Scanner(br);

		while(in.hasNext()){
			String name = in.next();

			System.out.println(name);
		}
	}
}