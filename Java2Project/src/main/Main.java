package main;

import java.util.ArrayList;

import utils.Print;
import utils.General;
import utils.Input;
import utils.Log;

import game.*;
import game.templates.DishTemplates;
import interfaces.VoidSam;

import java.nio.file.Paths;

public class Main extends Log {

	static GamePlay game;

	public static String foodPath = "./food.txt";
	public static String drinkPath = "./drink.txt";

	public Main() {
		game = new GamePlay();
		DishTemplates.initializeLists(foodPath, drinkPath);
	}

	public static void init() {

		new Main();
		game.start();

	}

	public static void test() {
//		log(Paths.get(".").toAbsolutePath().normalize().toString());
//		General.getEnter();
	}

	public static void main(String[] args) {
		test();
		init();
		// I don't know why but the user input does not work and I don't time to fix it.
	}

}
