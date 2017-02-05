import java.util.*;
import java.io.*;

// int x;

public class intRead{

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new FileReader("int.txt"));

		Scanner in = new Scanner(br);

		int a[] = new int[5];
		int i=0;

		while(in.hasNext()){
			a[i] = in.nextInt();
			i++;
		}

		System.out.println(Arrays.toString(a));
	}
}