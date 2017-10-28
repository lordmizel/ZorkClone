# ZorkClone
Aka Zorkemon: Rusty Pebble Version


## WHAT IS THIS?

This is an assignment for the Master Degree in Videogame Design and Development (2017-2018 edition) at 
'Universitat Politecnica de Catalunya'.
The assignment consisted in making a clone of the classic videogame Zork. I decided to transform it
into a Pokèmon parody. This version of Zork contains NPC dialogues that change as you progress with the 
game, monsters with randomly generated descriptions, and a rock-paper-scissors type of battle event.


## LINK TO THE REPOSITORY

https://github.com/lordmizel/ZorkClone


## HOW TO PLAY

Just like in regular Zork fashion, the player must type action commands in order for the character to
comply. This is a text-based game with no images whatsoever. The actions the player can take are as follows:

**Quit**<br />
Quits the game.

**Inventory**<br />
Shows the player inventory.

**Look**<br />
If used alone, it will describe the current room and everything in it. If an object name is added, it will
describe said object. The player can use this on objects contained in the room or on items currently in
the inventory.

**Go**<br />
Allows the player to move between rooms.

**Talk**<br />
Allows the player to talk to NPCs.

**Attack**<br />
Allows the player to try and attack an NPC or monster.

**Grab**<br />
Allows the player to grab an object from the room if possible. If the object is contained inside another
object, the format "GRAB [X] FROM [Y]" must be used.

**Put**<br />
Allows the player to put an object that's in the inventory inside another object if possible.

**Drop**<br />
Allows the player to drop an object currently in the inventory.

**Use**<br />
Allows the player to use an item currently in the inventory. Some of them must be used on other objects 
in order for them to have any effect.

**Strong / Fast / Sneaky**<br />
These three commands only have effect in battle. They determine which battle stance you want your monster
to take in it's next attack.


## HOW TO WIN

The objective of the player is to capture a monster and win a battle against another trainer. In order to
win, the following actions must be taken:

* (Optional) Grab book from bookcase
* (Optional) Use book
* Go down
* Go town
* Go backyard
* Grab key
* Go town
* Go warehouse
* Talk professor
* Go town
* Go lab
* Talk professor (This will give the player the CAPSULE item)
* Go town
* Go backyard
* Use capsule on [monster name] (The name of the monster is random. This will capture the monster)
* Go town
* Talk larry

This will start the battle event. In order to win, one must remember STRONG beats FAST, FAST beats
SNEAKY, and SNEAKY beats STRONG. The text during battle actually tells you which stance your opponent
is going to use:

* If the monster is popping a vein, that means it's using a STRONG attack: Type SNEAKY
* If the monster is skipping around, that means it's using a FAST attack: Type STRONG
* If the monster has a glint in it's eyes, that means it's using a SNEAKY attack: Type FAST

The player has to win three times in order for Larry's monster to faint. Once the player wins, he'll
have won the game, though he can still go around the town and talk to the rest of NPCs who will
offer their congratulations.


## LICENSE

MIT License

Copyright (c) 2017 Daniel Romero Aylagas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
