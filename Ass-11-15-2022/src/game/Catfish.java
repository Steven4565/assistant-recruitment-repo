package game;

public class Catfish extends AnimalType {
	String habitat;
	String animalType;

	public Catfish(String habitat, String animalType) {
		super.types = new String[] { "Channel Catfish", "Blue Catfish" };
		this.habitat = habitat;
		this.animalType = animalType;
	}

	@Override
	public Animal createSpecies(String species, String name, String size) {
		return new Animal(name, size, "Fresh Water", this.animalType, species, 2);
	}

}
