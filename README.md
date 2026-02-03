Bomberman ASCII

BomberMan ASCII is a terminal-based game written in C++ inspired by the classic Bomberman.
The game uses ASCII graphics and features 5 interconnected levels, enemies, bomb mechanics, power-ups, a scoring system, and a global timer, all playable directly in the terminal.

Design choice:
  The project intentionally avoids STL containers to practice low-level memory management and manual game loop handling.

⌨️ Controls

    Movement: Arrow keys (↑ ↓ ← →)

    Place bomb: Spacebar

    Menu selection / confirm: Enter

  All controls are handled via ncurses input.

📌 Features

    Fully playable in the terminal

    ASCII-based graphics

    5 interconnected levels

    Multiple enemy types with different stats

    Bomb mechanics with upgradeable range and damage

    Random power-ups

    Global timer

    Scoring system and persistent leaderboard

🎮 Main Menu

  At startup, the game displays a main menu with the following options:

  1. New Game

    Enter the player name

    Start a new game with default values

  2. Leaderboard

    Choose a number N

    Displays the top N players

    Only the best score for each player is shown

  3. Exit

    Closes the game

👤 Player Initial Stats

    Lives: 3 (maximum 5)

    Global timer: 200 seconds

    Bomb range: 1×

    Bomb damage: 1×

👾 Enemies

    Type	Health	Damage
     O	    1	      1
     Q	    2	      2
     
🧱 Destructible Walls

    Destroying a wall grants 10 points
    Walls may contain a random power-up

🔋 Power-ups

    Item	Effect	                              Notes
     T	   +15 seconds to the global timer	  Time boost
     R	   +1 bomb range	                     Max 3×
     D	   +1 bomb damage	                     Max 2×

Additional notes:

  If a power-up has already reached its maximum value:

    That power-up will no longer drop

    All existing items of that type on the map are removed

  When the player loses a life:

    All power-ups are reset to their initial values

🚪 Levels and Doors

  The game consists of 5 levels connected by doors

  A level is completed when all enemies are defeated

Exiting a level through a door:

    Removes the level

    Grants +200 points

    Grants +1 life (up to a maximum of 5)

    Grants +25 seconds to the global timer

If no level exists in a given direction, the corresponding door disappears

🏆 Scoring System

    Action	                         Points
 
    Destroy a wall	                  +10
    Defeat an enemy	                  +100
    Complete a level                  +200
    Remaining time at game end	      Bonus
  
✅ Win & Lose Conditions

    Victory: all enemies across the 5 levels are defeated

    Defeat: running out of lives or the global timer reaches zero


📊 Leaderboard

    At the end of the game, the total score is recorded

    Only the highest score per player is stored

🖥️ Game UI

    Top border: Time | Lives | Score

    Bottom border: Range ×n | Damage ×n | Level n

    Doors clearly indicate available directions

⚙️ Build & Run

  🐧 Linux
  
    g++ *.cpp -o bomberman -lncurses
    ./bomberman

  🪟 Windows
  
    g++ *.cpp -o bomberman -lpdcurses
    .\bomberman

📦 Dependencies
 
    C++

    ncurses (Linux)

    pdcurses (Windows)
