Don't forget to set this directory as the `Current Working Directory` or else the fread() will use the wrong directory.

Each screen is handled by a loop. There's the main menu loop, load game loop, lobby loop, and game loop.

There're also some kind of janky event loop systems which you can fire and catch events that I made
Source code for event system can be seen in `events/` folder and `utils/eventTimer.h`