package Game;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import Utils.Log;
import Utils.PrintUtils;
import Utils.Utils;

public class GameUtils extends Log {

	public static class Validator {
		public static boolean loginUsernameValidator(ArrayList<String> output, ArrayList<ArrayList<String>> table,
				String username) {
			if (!usernameFound(output, table, username)) {
				log("Username is not registered");
				return false;
			}
			return true;
		}

		public static boolean registerUsernameValidator(ArrayList<ArrayList<String>> table, String username) {
			if (usernameFound(table, username)) {
				log("Username has already been registered");
				return false;
			}

			if (username.length() < 4 || username.length() > 10) {
				log("Username must be between 4-10 characters long (inclusive)");
				return false;
			}
			return true;
		}

		public static boolean registerPasswordValidator(String password) {
			if (password.length() < 8 || password.length() > 16) {
				log("Password must be between 8-16 characters long (inclusive)");
				return false;
			}

			if (!password.matches("^[a-zA-Z0-9]*$")) {
				log("Password must be alphanumeric");
				return false;
			}

			return true;
		}

		public static boolean usernameFound(ArrayList<String> entryOutput, ArrayList<ArrayList<String>> table,
				String username) {
			for (ArrayList<String> entry : table) {
				if (entry.get(0).equals(username)) {
					entryOutput.add(username);
					entryOutput.add(entry.get(1));
					entryOutput.add(entry.get(2));
					return true;
				}
			}
			return false;
		}

		public static boolean usernameFound(ArrayList<ArrayList<String>> table, String username) {
			for (ArrayList<String> entry : table) {
				if (entry.get(0).equals(username)) {
					return true;
				}
			}
			return false;
		}
	}

	public static ArrayList<Card> generateDeck() {
		List<String> symbols = Arrays.asList("H", "S", "D", "C");
		List<String> tenPoints = Arrays.asList("J", "Q", "K");
		List<String> faceValues = Arrays.asList("2", "3", "4", "5", "6", "7", "8", "9", "10");

		ArrayList<Card> deck = new ArrayList<Card>();
		for (String symbol : symbols) {
			for (String string : tenPoints) {
				deck.add(new Card(string + symbol, 10));
			}
			for (String string : faceValues) {
				deck.add(new Card(string + symbol, Integer.valueOf(string)));
			}
			deck.add(new Card("A" + symbol, 11));
		}

		for (int i = 0; i < deck.size(); i++) {
			int randIndex = Utils.getRandRange(0, deck.size() - 1);

			Card temp = deck.get(i);
			deck.set(i, deck.get(randIndex));
			deck.set(randIndex, temp);
		}

		return deck;
	}

	public static void printHighscores(ArrayList<ArrayList<String>> table, String path, String delim) {
		Utils.sort(table, 1, (str1, str2) -> Integer.valueOf(str1).compareTo((Integer.valueOf(str2))) > 0);
		PrintUtils.printTable(table, 15, new String[] { "Username", "Points" }, true);
	}
}
