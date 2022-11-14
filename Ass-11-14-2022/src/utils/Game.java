package utils;

import java.util.ArrayList;

public class Game {
	private ArrayList<AnimeEntry> entries;

	public Game() {
		this.entries = new ArrayList<AnimeEntry>();
	}

	public void printEntries() {
		for (AnimeEntry animeEntry : this.entries) {
			animeEntry.print();
		}
	}

	public void addEntry(AnimeEntry newEntry) {
		this.entries.add(newEntry);
	}

	public void deleteEntry(String code) {
		for (int i = 0; i < this.entries.size(); i++) {
			if (this.entries.get(i).getCode().equals(code)) {
				this.entries.remove(i);
			}
		}
	}

	public AnimeEntry getCode(String code) {
		for (AnimeEntry anime : this.entries) {
			if (anime.getCode().equals(code)) {
				return anime;
			}
		}
		return null;
	}

	public static String generateCode(String title) {
		return ("" + title.charAt(0) + title.charAt(1) + Utils.getRandRange(100, 999));

	}

}
