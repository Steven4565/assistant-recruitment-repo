package game;

public class WaterHabitat extends Habitat {
	String habitat;

	public WaterHabitat(String habitat) {
		super.types = new String[] { "Catfish", "Salmon" };
		this.habitat = habitat;
	}

	@Override
	public AnimalType createAnimalType(String species) {
		if (species.equals(types[0])) {
			return new Catfish(habitat, species);
		} else {
			return new Salmon(habitat, species);
		}
	}

}
