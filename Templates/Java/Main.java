import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * Only classes with 'Main' name are accepted in CodeChef and some other online judges
 */
public class Main {

	/*
	 * In a Programming contest, you are expected to print the output at the
	 * end, so `output` variable will hold all the processed results till the
	 * end
	 */
	public static String output = "";

	// Program's starting point
	public static void main(String[] args) {

		/*
		 * A Scanner class slows down Input/Output a LOT ,thereby increasing
		 * your code execution time , Hence for best results that is Fast I/O
		 * try to use BufferedReader
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		/*
		 * Generally Code Chef, Hacker Rank gives X number of test cases so we
		 * process the input for each.
		 */
		final int cases;
		try {
			cases = Integer.parseInt(br.readLine().trim());
			/*
			 * Logic of the program must be separated from the meta code to
			 * increase readability and help debugging easier
			 * Also note that Solver object is created inside for loop to
			 * avoid multiple object creation that drastically increases 
			 * execution time and memory usage
			 */
			Solver solver = new Solver();
			for (int i = 0; i < cases; i++) {				
				solver.solve(br.readLine());
			}

		} catch (IOException e) {
			
			e.printStackTrace();
		}
		System.out.println(output);
	}

}
class Solver {

	/*
	 * Logic goes here ...
	 * Add to the global variables after processing the input
	 * Maybe reverse a string or parse to an integer or , etc.
	 */	
	public void solve(String input) {					
		Main.output.concat(input);	
	}

}
