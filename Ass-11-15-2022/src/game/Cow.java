package game;

public class Cow extends AnimalType {

	String habitat;
	String animalType;

	public Cow(String habitat, String animalType) {
		super.types = new String[] { "Angus Cow", "Hereford Cow" };
		this.habitat = habitat;
		this.animalType = animalType;
	}

	@Override
	public Animal createSpecies(String species, String name, String size) {
		return new Animal(name, size, habitat, this.animalType, species, 4);
	}

}
