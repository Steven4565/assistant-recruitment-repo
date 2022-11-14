import java.util.ArrayList;

import Game.Data;
import Game.Gameplay;
import Utils.Log;
import Utils.Utils;
import Utils.Validator;
import Utils.FileUtils;

public class Main extends Log {
	public static Data data;
	public static String filePath;
	public static String delim;
	public static boolean endProgram;

	public Main() {
		filePath = "raceHistory.txt";
		delim = "#";

		data = new Data(0, 1, 1);
		endProgram = false;

	}

	public static void main(String[] args) {
		new Main();
		log("Horse Gallop");
		log("=============================");
		data.print();
		log("=============================");

		while (!endProgram) {
			String[] options = { "Begin Race", "View History", "Upgrade Accesories", "Exit" };
			Integer menuInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] { 1, 2, 3, 4 }, i),
					options);
			switch (menuInput) {
			case 1:
				startGame();
				break;
			case 2:
				viewHistory();
				break;
			case 3:
				upgradePage();
				break;
			case 4:
				log("Exitted program");
				Utils.getEnter();
				endProgram = true;
				break;
			}
		}

	}

	public static void startGame() {
		Gameplay game = new Gameplay(data);
		ArrayList<String> result = game.startGame();
		FileUtils.writeRow(filePath, String.join(", ", result));
	}

	public static void viewHistory() {
		log("Race History");
		log("===============================");
		ArrayList<String> result = FileUtils.readRows(filePath, delim);
		for (String row : result) {
			log(row);
		}

		Utils.getEnter();
	}

	public static void upgradePage() {
		log("Upgrade Accessories");
		log("===============================");
		data.print();
		log("===============================");
		String[] options = { "Upgrade Shoe", "Upgrade Leash", "Exit" };
		String[] yesNoOptions = { "Yes", "No" };
		Integer upgradeInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] { 1, 2, 3 }, i),
				options);

		switch (upgradeInput) {
		case 1: {
			int shoePrice = 1000 * data.shoeLv;
			log("You need " + shoePrice + " to upgrade your shoe");
			if (data.bal < shoePrice) {
				log("You do not have enough money to upgrade your shoe");
				Utils.getEnter();
				break;
			}

			String input = Validator.getInputLine((i) -> Validator.validateOptions(yesNoOptions, i),
					"Are you sure you want to continue? [Yes/No] (Case Sensitive): ");
			if (input.equals("Yes")) {
				data.bal -= shoePrice;
				data.shoeLv++;

				log("You have successfully upgraded your shoe");
				break;
			}
		}
		case 2: {
			int leashPrice = 1000 * data.leashLv;
			log("You need " + leashPrice + " to upgrade your shoe");
			if (data.bal < leashPrice) {
				log("You do not have enough money to upgrade your leash");
				Utils.getEnter();
				break;
			}
			String input = Validator.getInputLine((i) -> Validator.validateOptions(yesNoOptions, i),
					"Are you sure you want to continue? [Yes/No] (Case Sensitive): ");

			if (input.equals("Yes")) {
				data.bal -= leashPrice;
				data.leashLv++;
				log("You have successfully upgraded your leash");
				break;
			}
		}
		}
	}

}
