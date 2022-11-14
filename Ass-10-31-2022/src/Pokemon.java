
 public class Pokemon extends Log {
	public int health;
	public int attack;
	String pokemonType;
	public Pokemon(String pokemonType, int health, int attack) {
		this.health = health;
		this.attack = attack;
		this.pokemonType = pokemonType;
	}
	
	public void attack(Pokemon pokemon) {
		pokemon.health -= this.attack;
	}
}
