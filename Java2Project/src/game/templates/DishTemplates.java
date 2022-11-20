package game.templates;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

import game.dishes.*;
import utils.General;
import utils.Log;

public class DishTemplates extends Log {

	public static ArrayList<Drinks> drinksList;
	public static ArrayList<Food> foodList;

	public static void initializeLists(String foodPath, String drinkPath) {
		// initialize
		foodList = new ArrayList<>();
		drinksList = new ArrayList<>();

		try {
			File handle;
			Scanner sc;

			// load food

			handle = new File(foodPath);
			sc = new Scanner(handle);

			while (sc.hasNextLine()) {
				String[] entries = sc.nextLine().split("#");
				log(entries[0]);
				foodList.add(new Food(entries[0], Integer.parseInt(entries[2])));
			}
			sc.close();

			// load drinks

			handle = new File(drinkPath);
			sc = new Scanner(handle);

			while (sc.hasNextLine()) {
				String[] entries = sc.nextLine().split("#");
				drinksList.add(new Drinks(entries[0], Integer.parseInt(entries[2])));
			}
			sc.close();
		} catch (FileNotFoundException e) {
			log("Error opening file");
		}
	}

	public static Drinks createDrink() {
		Drinks randDrink = drinksList.get(General.getRandRange(0, drinksList.size() - 1));
		return new Drinks(randDrink.name, randDrink.price);
	}

	public static Food createFood() {
		Food randFood = foodList.get(General.getRandRange(0, foodList.size() - 1));
		return new Food(randFood.name, randFood.price);
	}
}
