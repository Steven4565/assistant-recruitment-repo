Don't forget to set this directory as the `Current Working Directory` or else the fread() will use the wrong directory.

gameplay is handled by some jank version of an event system, based on timers and flags.
activateTimer() is the equivalent of setInterval in JS but the callback is hardcoded

* `structs.h`: definitions for struct types
* `utils/`: various utilities
* `events/`: event(ish) emitters and handlers
* `globals.c`: definition of global variables

## Todo list:
* Choose spaceship feature
* On gameover:
	* write score to scoreboard
	* display gameOver message
	* add xp
	* handle level, xp/100 = level
	* resave as in `player.dat`
		* cache all the data in `player.dat` in an array
		* rewrite data
* Input buffer for cheatcode
* add bomb
* Handle potions
* Armor (how does armor work???)
* Add colors