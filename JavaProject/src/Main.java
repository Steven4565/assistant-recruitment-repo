import Utils.Utils;

import Utils.Validator;
import Utils.FileUtils;
import Utils.AES;
import Utils.Log;

import Game.GameUtils;
import Game.Gameplay;
import Game.User;
import java.util.ArrayList;

public class Main extends Log {

	private static String path;
	private static String delim;
	private static User user;

	public Main() {
		path = "SuperS3cr3tFile.dat";
		delim = "#";
	}

	public static void main(String[] args) {
		new Main();

		System.out.println("| ♥   BlueJack    ♠ |");
		System.out.println("| ♦   Card Game   ♣ |");

		while (loginPage())
			;
	}

	public static boolean loginPage() {
		String[] options = { "Login", "Register", "Exit" };
		Integer menuInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] { 1, 2, 3 }, i),
				options, ">> ");
		switch (menuInput) {
		case 1: {
			// Login
			ArrayList<ArrayList<String>> table = FileUtils.readEntriesEncrypted(path, delim);

			// Get user input
			ArrayList<String> entry = new ArrayList<String>();
			Validator.getInputLine((i) -> GameUtils.Validator.loginUsernameValidator(entry, table, i), new String[] {},
					"Input username: ");
			String password = Validator.getInputLine((i) -> true, new String[] {}, "Input password: ");

			// Check user Input
			if (!password.equals(entry.get(1))) {
				log("Incorrect password");
				break;
			}

			// Load user data
			user = new User(entry.get(0), entry.get(1), Integer.parseInt(entry.get(2)));
			log("User successfully logged in");
			Utils.getEnter();

			// Play game
			while (playPage())
				;

			break;
		}
		case 2: {
			// Register
			ArrayList<ArrayList<String>> table = FileUtils.readEntriesEncrypted(path, delim);

			// Get user input
			String username = Validator.getInputLine((i) -> GameUtils.Validator.registerUsernameValidator(table, i),
					new String[] {}, "Input a new username: ");
			String password = Validator.getInputLine((i) -> GameUtils.Validator.registerPasswordValidator(i),
					new String[] {}, "Input a new password: ");

			String entry = String.join(delim, new String[] { username, password, "" + 100 });
			FileUtils.writeRow(path, AES.encrypt(entry));

			user = new User(username, password, 100);
			log("User successfully registered");
			Utils.getEnter();

			while (playPage())
				;
			break;
		}
		case 3:
			log("Exitted program");
			Utils.getEnter();
			return false;
		}
		return true;
	}

	public static boolean playPage() {
		log("Hello, " + user.username);
		log("Points: " + user.points);
		String[] options = { "Play", "Highscore", "Save & Logout" };
		Integer menuInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] { 1, 2, 3 }, i),
				options, ">> ");
		switch (menuInput) {
		case 1: {
			// Gameplay
			Gameplay game = new Gameplay();
			game.start();
			user.points += game.bet;

			// Save data
			ArrayList<ArrayList<String>> table = FileUtils.readEntriesEncrypted(path, delim);
			int userIndex = FileUtils.findRowIndex(table, path, delim, 0, user.username);
			FileUtils.deleteRow(path, delim, userIndex);
			String entryString = String.join(delim,
					new String[] { user.username, user.password, String.valueOf(user.points) });
			FileUtils.writeRow(path, AES.encrypt(entryString));

			break;
		}
		case 2: {
			// Read highscore
			ArrayList<ArrayList<String>> table = FileUtils.readEntriesEncrypted(path, delim);
			for (ArrayList<String> entry : table) {
				entry.remove(1);
			}

			GameUtils.printHighscores(table, path, delim);
			break;
		}
		case 3: {
			// Save and log out
			log("successfully logged out");
			Utils.getEnter();
			return false;
		}
		}
		return true;
	}

}
