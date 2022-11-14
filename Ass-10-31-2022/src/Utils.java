import java.util.*;

public class Utils extends Log{
	public static Scanner sc;
	public static Random rand;
	static {
		sc = new Scanner(System.in);
		rand = new Random(); 
		rand.setSeed(12350912);
	};
	
	
	public static int inputInt(String errMsg) {
		boolean valid = false;
		int input = 0;
		do {
			try {
				input = sc.nextInt();
				sc.nextLine();
			} catch (Exception e) {
				System.out.println(errMsg);
			}
		} while (!valid);
		return input;
	}
	
	public static void printMenu(String menus[]) {
		for (int i = 0; i < menus.length; i++) {
			log(i+1 + ". " + menus[i]);
		}
	}
	
	public static int get5050() {
		int res = rand.nextInt(2);
		log(res + "");
		return res;
	}
	
}
