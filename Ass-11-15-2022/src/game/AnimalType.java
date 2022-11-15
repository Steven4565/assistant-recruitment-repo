package game;

public abstract class AnimalType {
	public abstract Animal createSpecies(String species, String name, String size);

	public String[] types;
}
