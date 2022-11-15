package game;

public class LandHabitat extends Habitat {
	String habitat;

	public LandHabitat(String habitat) {
		super.types = new String[] { "Cow", "Duck" };
		this.habitat = habitat;
	}

	@Override
	public AnimalType createAnimalType(String type) {
		if (type.equals(types[0])) {
			return new Cow(habitat, type);
		} else {
			return new Duck(habitat, type);
		}
	}

}
