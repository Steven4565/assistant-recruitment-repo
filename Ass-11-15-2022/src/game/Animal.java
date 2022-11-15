package game;

public class Animal {

	private String name;
	private String size;
	private String habitat;
	private String type;
	private String species;
	private int space;
	private int foodCount;

	public Animal(String name, String size, String habitat, String type, String species, int space) {
		this.name = name;
		this.size = size;
		this.habitat = habitat;
		this.type = type;
		this.species = species;
		this.space = space;
		this.foodCount = 0;
	}

	public String getType() {
		return this.type;
	}

	public String getHabitat() {
		return this.habitat;
	}

	public int getSpace() {
		return this.space;
	}

	public String getName() {
		return this.name;
	}

	public String getSize() {
		return this.size;
	}

	public int getFoodCount() {
		return this.foodCount;
	}

	public String getSpecies() {
		return this.species;
	}

	public int getSellPrice() {
		int baseSellPrice;
		if (this.type.equals("Cow")) {
			baseSellPrice = 500;
		} else if (this.type.equals("Duck")) {
			baseSellPrice = 280;
		} else if (this.species.equals("Catfish")) {
			baseSellPrice = 120;
		} else {
			baseSellPrice = 1000;
		}

		int sizePrice;
		if (this.size.equals("Small")) {
			sizePrice = 70;
		} else if (this.size.equals("Medium")) {
			sizePrice = 350;
		} else {
			sizePrice = 800;
		}

		return baseSellPrice * sizePrice;
	}

	public void feed() {
		this.foodCount += 1;
		if (this.size.equals("Small") && this.foodCount > 2) {
			this.size = "Medium";
			this.foodCount = 0;
		} else if (this.size.equals("Medium") && this.foodCount > 3) {
			this.size = "Large";
			this.foodCount = 0;
		}
	}

}
