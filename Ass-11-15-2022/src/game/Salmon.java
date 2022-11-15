package game;

public class Salmon extends AnimalType {

	String habitat;
	String animalType;

	public Salmon(String habitat, String animalType) {
		super.types = new String[] { "Sockeye Salmon", "Chinook Salmon" };
		this.habitat = habitat;
		this.animalType = animalType;
	}

	@Override
	public Animal createSpecies(String species, String name, String size) {
		return new Animal(name, size, "Salt Water", this.animalType, species, 2);
	}

}
