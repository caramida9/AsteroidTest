# AsteroidTest
 
A simple spaceship shooter game, part of an interview test. The project already contained all the assets and the engine to begin with.
However, it had several compilation errors that I had to fix before it was functional. 
After that there were some crashes and bugs that also needed to be fixed in order to make the game playable.
Finally I made some small improvements and added some additional features as follows:
1. Changing the code so that multiple bullets can be active simultaneously, and added a small delay between them as well as a maximum lifetime.
2. In-game score and Hi Score table at Main Menu
	The player recieves 5 points whenever he hits an asteroid. The game score is kept in Game and rendered on the screen via DrawText.
	The highscore table is a simple array of fixed size (10) kept in System. The new score is inserted in the array on GameOver in PlayingState.
	The table is rendered on screen in MainMenu.
3. Multiple lives for player 
	Player has 3 hit-points on level start. The hit-points are also rendered on Screen underneath Score, via DrawText.
	Added a small invincibility timer when the player gets hit, so he wouldn't immediately take damage from the smaller asteroids that spawn when a big one is destroyed
4. Different weapon types ~ 1 hour
	There are 3 different kinds of weapons that can be changed by pressing 1,2 or 3.
	1 is the standard, 2 is rapid firing but short range weapons with small bullets and 3 is a large cannon that fires a slow projectile at bigger intervals.
	The rate of fire is implemented in Game, while the different characteristics are given in the Bullet constructor based on the weapon type that is passed with SpawnBullet.

