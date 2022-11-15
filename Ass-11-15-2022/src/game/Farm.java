package game;

import java.util.ArrayList;

import utils.Log;

public class Farm extends Log {
	private ArrayList<Animal> animals;
	Cage land;
	Cage fresh;
	Cage salt;
	int money;

	public Farm() {
		this.land = new Cage("Land", 20, 4);
		this.fresh = new Cage("Fresh Water", 10, 2);
		this.salt = new Cage("Salt Water", 10, 2);
		this.animals = new ArrayList<>();
		this.money = 30000;
	}

	public int getMoney() {
		return this.money;
	}

	public int getAnimalCount() {
		return this.animals.size();
	}

	public void sellAnimal(int index) {
		Animal anim = this.animals.get(index);
		log("Successfully sold " + anim.getName());

		this.money += anim.getSellPrice();
		this.animals.remove(index);
	}

	public void sellAll() {
		for (Animal anim : this.animals) {
			this.money += anim.getSellPrice();
		}
		this.animals.clear();
		log("Succesfully sold all animals");
	}

	public Cage getCage(String cageName) {
		if (cageName.equals("Land"))
			return this.land;
		else if (cageName.equals("Salt Water"))
			return this.salt;
		else
			return this.fresh;
	}

	public int getHabitatCapacity(String habitatName) {
		int counter = 0;
		for (Animal anim : this.animals) {
			if (anim.getHabitat().equals(habitatName)) {
				counter += anim.getSpace();
			}
		}
		return counter;
	}

	public void addAnimal(Animal anim, int price) {
		int maxCapacity = this.getCage(anim.getHabitat()).getMaxCapacity();

		if (this.getHabitatCapacity(anim.getHabitat()) + anim.getSpace() <= maxCapacity) {
			animals.add(anim);
			this.money -= price;
			log("Successfully bought " + anim.getName());
		} else {
			log("Not enough space");
		}
	}

	public void feedAll() {
		int animCount = this.animals.size();

		if (animCount == 0) {
			log("No animals to be fed");
			return;
		}

		if (this.money < animCount * 50) {
			log("Not enough money");
			return;
		}
		this.money -= animCount * 50;
		for (Animal anim : this.animals) {
			anim.feed();
		}
		log("Fed all animals");
	}

	public void upgradeFarm(String farmName) {
		Cage cage;
		if (farmName.equals("Land"))
			cage = this.land;
		else if (farmName.equals("Salt Water"))
			cage = this.salt;
		else
			cage = this.fresh;

		if (this.money < cage.getUpgradePrice()) {
			log("Not enough money");
			return;
		} else {
			this.money -= cage.getUpgradePrice();
			cage.upgrade();
			log("Successfully upgraded " + cage.getName());

		}
	}

	public void printFarm() {
		System.out.printf("%-5s | %-20s | %-10s | %-15s | %-15s | %-25s\n", "No.", "Name", "Size", "Habitat",
				"Food Count", "Type");
		int i = 1;
		for (Animal anim : this.animals) {
			System.out.printf("%-5d | %-20s | %-10s | %-15s | %-15d | %-25s\n", i, anim.getName(), anim.getSize(),
					anim.getHabitat(), anim.getFoodCount(), anim.getSpecies());
			i++;
		}
	}

	public void printInfo() {
		log("Your money: " + this.getMoney());
		System.out.printf("%s Size capacity: %d/%d\n", land.getName(), this.getHabitatCapacity(land.getName()),
				land.getMaxCapacity());
		System.out.printf("%s Size capacity: %d/%d\n", salt.getName(), this.getHabitatCapacity(salt.getName()),
				salt.getMaxCapacity());
		System.out.printf("%s Size capacity: %d/%d\n", fresh.getName(), this.getHabitatCapacity(fresh.getName()),
				fresh.getMaxCapacity());

	}

}
