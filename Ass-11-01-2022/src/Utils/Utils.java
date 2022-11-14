package Utils;

import java.util.Random;
import java.util.Scanner;

public class Utils extends Log{
	public static Scanner sc;
	public static Random rand;
	static {
		sc = new Scanner(System.in);
		rand = new Random(); 
		rand.setSeed(System.nanoTime());
	};
	
	
	public static int inputInt(String errMsg) {
		boolean valid = false;
		int input = 0;
		do {
			try {
				input = sc.nextInt();

			} catch (Exception e) {
				System.out.println(errMsg);
			}
			sc.nextLine();
		} while (!valid);
		sc.nextLine();
		return input;
	}
	
	public static void getEnter() {
		log("Press ENTER to continue");
		sc.nextLine();
	}
	
	public static void printMenu(String menus[]) {
		for (int i = 0; i < menus.length; i++) {
			log(i+1 + ". " + menus[i]);
		}
	}
	
	public static int getRandRange(int min, int max) {
		int res = rand.nextInt(max+1) + min;
		return res;
	}
	
	public static boolean get5050() {
		int res = rand.nextInt(2); 
		return (res == 1 ? true : false);
	}
	
}
