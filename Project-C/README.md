Don't forget to set this directory as the `Current Working Directory` or else the fread() will use the wrong directory.

gameplay is handled by some jank version of an event system, based on timers and flags.
activateTimer() is the equivalent of setInterval in JS but the callback is hardcoded

* `structs.h`: definitions for struct types
* `utils/`: various utilities
* `events/`: event(ish) emitters and handlers
* `globals.c`: definition of global variables

Todo list:
* Choose spaceship feature
* Update database on exit lobby
* Input buffer for cheatcode
* Item shop
* Upgrade shop
* View backpack
* Sort leaderboard
* add bomb
* Handle potions
* Armor (how does armor work???)
* Add colors