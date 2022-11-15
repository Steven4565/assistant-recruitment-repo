package main;

import java.util.ArrayList;

import utils.Print;
import utils.General;
import utils.Input;
import utils.Log;

import game.*;

import interfaces.VoidSam;

public class Main extends Log {
	static Farm farm;

	public Main() {
		farm = new Farm();
	}

	public static void main(String[] args) {
		new Main();
		test();

		while (mainMenuPage())
			;
	}

	public static void test() {
		farm.addAnimal(new Animal("asdf", "Small", "Land", "Cow", "Angus Cow", 4), 4000);
		farm.addAnimal(new Animal("my samon", "Medium", "Salt Water", "Salmon", "Sockeye Salmon", 2), 10000);
	}

	static boolean mainMenuPage() {

		farm.printFarm();
		log("");
		farm.printInfo();
		log("");

		String[] inputMessages = { "Buy Animal", "Feed All Animal(s)", "Sell Animal", "Sell All Animal(s)",
				"Upgrade Farm", "Exit" };
		VoidSam functions[] = { () -> {
			buyAnimal();
		}, () -> {
			feedAll();
		}, () -> {
			sell();
		}, () -> {
			sellAll();
		}, () -> {
			upgrade();
		}, () -> {
			General.getEnter();
		} };

		return Input.pageInput("Main Menu", inputMessages, functions);
	}

	public static void buyAnimal() {
		Habitat habObj = GameUtils
				.createHabitat(Input.getInputChoice(GameUtils.placeTypes, "Input habitat (Land/Water)"));

		String type = Input.getInputChoice(habObj.types,
				"Input Animal Type [" + String.join(" | ", habObj.types) + "]");
		AnimalType animType = habObj.createAnimalType(type);

		String species = Input.getInputChoice(animType.types,
				"Input Animal Species [" + String.join(" | ", animType.types) + "]");
		String size = Input.getInputChoice(GameUtils.sizeTypes,
				"Input Animal Size [" + String.join(" | ", GameUtils.sizeTypes) + "]");
		String name = Input.getInputRestrictLength(3, 15, "Input animal name: ");
		Animal animal = animType.createSpecies(species, name, size);

		int basePrice;
		if (type.equals("Cow"))
			basePrice = 400;
		else if (type.equals("Duck"))
			basePrice = 200;
		else if (type.equals("Catfish"))
			basePrice = 100;
		else
			basePrice = 800;

		int sizePrice;
		if (size.equals("Small"))
			sizePrice = 50;
		else if (size.equals("Medium"))
			sizePrice = 300;
		else
			sizePrice = 650;

		if (farm.getMoney() < basePrice + sizePrice) {
			log("Not enough money");
			return;
		}

		farm.addAnimal(animal, basePrice + sizePrice);
	}

	public static void feedAll() {
		farm.feedAll();
	}

	public static void sell() {
		if (farm.getAnimalCount() == 0) {
			log("There are no animals");
			return;
		}

		farm.printFarm();
		int index = Input.getInputInt(1, farm.getAnimalCount(), "Input index you want to sell");
		farm.sellAnimal(index);
	}

	public static void sellAll() {
		if (farm.getAnimalCount() == 0) {
			log("There are no animals");
			return;
		}

		farm.sellAll();
	}

	public static void upgrade() {
		String farmName = Input.getInputChoice(GameUtils.habitatTypes,
				"Input Habitat [" + String.join(" | ", GameUtils.habitatTypes) + "]");
		farm.upgradeFarm(farmName);
	}

}
