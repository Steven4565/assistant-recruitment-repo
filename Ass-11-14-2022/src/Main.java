import utils.Utils;

import utils.Validator;
import utils.AnimeEntry;
import utils.FileUtils;
import utils.Log;
import utils.PrintUtils;

import utils.Game;

import java.util.ArrayList;

public class Main extends Log {
	public static Game game;

	public Main() {
		game = new Game();
	}

	public static void main(String[] args) {
		new Main();

		while (mainMenuPage())
			;
	}

	static boolean mainMenuPage() {
		String[] inputMessages = { "View Anime List", "Add New Anime", "Delete Anime", "Exit VAniList" };

		log("Vanilist");

		PrintUtils.printMenu(inputMessages);
		int choice = Validator.getInputInt(1, 4, "Which one do you wnat to choose [1-4]");

		switch (choice) {
		case 1:
			view();
			break;
		case 2:
			add();
			break;
		case 3:
			delete();
			break;
		case 4:
			return false;
		}
		return true;
	}

	public static void view() {

		log("Title | Code | Rating");
		game.printEntries();
	}

	public static void add() {
		String name = Validator.getInputLine(i -> (i.length() > 5 && i.length() < 50 ? true : false), new String[] {},
				"anime name: ");
		String desc = Validator.getInputLine(i -> (i.length() > 23 ? true : false), new String[] {}, "anime desc: ");
		String date = Validator.getInputLine(i -> true, new String[] {}, "input date: ");
		int genresCount = Validator.getInputInt((i) -> (i > 0 ? true : false), "genre count: ");
		ArrayList<String> genres = new ArrayList<String>();
		for (int i = 0; i < genresCount; i++) {
			genres.add(Validator.getInputLine(in -> (in.length() > 2 ? true : false), new String[] {}, "Genre: "));
		}

		AnimeEntry entry = new AnimeEntry(name, desc, date, 0, genres);

		game.addEntry(entry);
		log("Successfully added");
	}

	public static void delete() {
		view();
		String code = Validator.getInputLine(i -> (game.getCode(i) != null ? true : false), new String[] {},
				"anime code to be deleted");
		game.deleteEntry(code);
		log("Successfully deleted");
	}

}
