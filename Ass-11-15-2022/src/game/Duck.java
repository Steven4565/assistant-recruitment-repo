package game;

public class Duck extends AnimalType {

	String habitat;
	String animalType;

	public Duck(String habitat, String animalType) {
		super.types = new String[] { "Bali Duck", "Campbell Duck" };
		this.habitat = habitat;
		this.animalType = animalType;
	}

	@Override
	public Animal createSpecies(String species, String name, String size) {
		return new Animal(name, size, habitat, this.animalType, species, 2);
	}

}
