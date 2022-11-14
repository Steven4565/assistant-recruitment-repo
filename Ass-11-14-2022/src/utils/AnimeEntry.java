package utils;

import java.util.ArrayList;

public class AnimeEntry extends Log {
	private String title;
	private String desc;
	private String date;
	private String code;
	private float rating;
	private ArrayList<String> genres;

	public AnimeEntry(String title, String desc, String date, float rating, ArrayList<String> genres) {
		this.title = title;
		this.desc = desc;
		this.date = date;
		this.rating = rating;
		this.code = Game.generateCode(title);
		this.genres = genres;
	}

	public String getTitle() {
		return this.title;
	}

	public String getDesc() {
		return this.desc;
	}

	public String getDate() {
		return this.date;
	}

	public String getCode() {
		return this.code;
	}

	public String getGenres() {
		return String.join(", ", this.genres);
	}

	public void print() {
		System.out.printf("%s | %s | %.2f\n", this.title, this.code, this.rating);
	}

	public void updateRating(float newRating) {
		this.rating = (rating + newRating) / 2;
	}

}
