[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8913295&assignment_repo_type=AssignmentRepo)

# Fantasma (A Text-Based Role-Playing Game (RPG))

 
 > Authors: 
 > [Parth Desai](https://github.com/pdesa018), 
 > [Nicholas Karalis](https://github.com/Googoo03), 
 > [Shrey Verma](https://github.com/shreyvermz),
 > [Anthony Montano](https://github.com/Tonio-Codes)


## Project Description
We chose to do our project on a RPG game as we found that to be the most interactive and creative project choice. As of now, we are planning on using C++, Git, Github, and Linux. THe input of our project will be the player choosing their character and accessories who will then be taken on a certain storyline where they will have to select attacks, items etc., and the output will be the corresponding consequence of that particular choice. The project will provide the player with the ability to pick their character, customize their inventory, and interact with certain storylines or game characteristics thorugh their actions.  

 >
## Class Diagram
>Combined UML Diagram:

>![UML Diagram drawio](https://user-images.githubusercontent.com/114703300/202583184-0e41e66f-d126-409a-8b1f-fa27f6faa7e2.png)

>UML Diagram Descriptions:
>
 > Terrain Description:
 The terrain is made of two core classes, the Map class and the PerlinNoise class. The Map contains a vector of data that will be used throughout the game for a variety of purposes including enemies, obstacles, and locations like towns and dungeons. The Map is generated using the PerlinNoise algorithm, which is properly organized into its own class. The class implements both standard Perlin Noise and Octave Perlin noise. Both may exist on their own, but the Map class is dependent on the PerlinNoise class. The Perlin Noise alorithm retruns a value 0.0 to 1.0 which using several cutoffs can be segmented into water, land, trees, towns, and dungeons.
>
 > Item Description
 My class diagram outlines the items that the player will acquire and use throughout the game. There will be a handful of items usable across all characters, but for the most part your chosen class will dictate the stats your items will have and the degree to which their stats are tuned, for example bards will use instruments with a jamScale to determine how swayed the enemy is by their music, and no other class will be able to achieve this attack. My UML diagram will be in an aggregation relationship with the base class, as they can exist without each other but the user will have the option to pick up, store, and drop certain items. They will exist without the user being required to get them, as some items will only be attainable through certain enemies.
 >
 > Character Description:
 > My class diagram establishes the base class that the main character's type will be derived from. Regardless of what character type the user chooses(tank, bard, mage, or fighter), they all share the attributes listed in the character class. My UML diagram relates to the item class(as shown above) in that the characters will all have things in their inventory of type "item" and can use them in certain ways.
 > 
>Menu Description:
>My class diagram sets up the menu that the users will see upon entering the game. They will first be shown the title of the Game and then given the option to either start the game or quit the game. Regardless of their choice, these attributes will all be present in the Menu class. When they are in the game, they will have the option to call this Menu again if they would like to restart the game or quit it inbetween. Otherwise, the game will automatically end when the final boss is defeated.


 
 > ## Phase III

>Combined UML Diagram:

>![UML Diagram drawio](https://user-images.githubusercontent.com/114703300/202583184-0e41e66f-d126-409a-8b1f-fa27f6faa7e2.png)

 > ## Final deliverable
 
 ## Updated UML class diagram
 > ![uml classdiagram drawio (1)](https://user-images.githubusercontent.com/71724547/205156278-4d1c1e20-7c7f-4f89-aaa3-1ed78ad812cb.png)
 
 >Terrain Description:
 The terrain is made of two core classes, the Map class and the PerlinNoise class. The Map contains a vector of data that will be used throughout the game for a variety of purposes including enemies, obstacles, and locations like towns and dungeons. The Map is generated using the PerlinNoise algorithm, which is properly organized into its own class. The class implements both standard Perlin Noise and Octave Perlin noise. Both may exist on their own, but the Map class is dependent on the PerlinNoise class. The Perlin Noise alorithm retruns a value 0.0 to 1.0 which using several cutoffs can be segmented into water, land, trees, towns, and dungeons.

 >Location Description:
 The two main locations in Fantasma include the town and the dungeon, both of which are subclasses of the Location class. These inherit the basic properties of a location, being its name and subsequent function to create the location, aptly named CreateLocation. The town utilizes the Item class, of which it develops its shop and keeps track of its inventory. The Dungeon does not utilize the Item class, being used solely for player feedback, which is outputted to the console.

 >Item Description:
 The Item class establishes the stats and class-specific nature of the items we integrate and use throughout the game. Each class has items that only they can use, and these unique items contain two extra stats that are native to the class only. For example, a fighter item includes a rage stat that bolsters a character’s base damage, as well as their aptitude to regain health when they consume a potion. This Item class is in an aggregation relationship with the Character class, as it can exist without it but still uses it throughout the program. The other classes I was responsible for were the Bandit and Boss classes, which are very similar and the Boss inherits from the Bandit, as he is simply a boosted and stronger bandit with the extra perk of health regeneration throughout a fight. These classes are standalone and able to function without the creation of the rest of the program, but they do interact with the user’s Character in dungeons and boss fights.
 >
 > Character Description:
 > The character class is the class that the character's type will be derived from. Regardless of what character type the user chooses(tank, bard, mage, or fighter), they all share the attributes listed in the character class. My UML diagram does share a composition type relationship with the Item class (as seen by the hollow diamond connecting the two classes) due to the fact that one of the Characters private members (inventory) is made up of Item pointers, so Characters do rely on Items existing in order to work properly.

>Menu Description:
>My class diagram sets up the menu that the users will see upon entering the game. They will first be shown the title of the Game and then given the option to either start the game or quit the game. Regardless of their choice, these attributes will all be present in the Menu class. When they are in the game, they will have the option to call this Menu again if they would like to restart the game or quit it inbetween. Otherwise, the game will automatically end when the final boss is defeated.


 
 ## Screenshots
 > Screenshots of the input/output after running your application!
 > [FantasmaTitle](https://user-images.githubusercontent.com/114453356/205163030-a78f5981-9bb6-440f-a5f1-27d23fe7770f.png)
 >![FantasmaStory](https://user-images.githubusercontent.com/114453356/205163126-346de1d2-73e4-434a-a80a-8c0b80f52081.png)
 >![FantasmaMap](https://user-images.githubusercontent.com/114453356/205163250-6b563ab3-ab42-4660-a546-e8a8404456ce.png)
 >![FantasmaTown](https://user-images.githubusercontent.com/114453356/205163369-d540616b-f350-4609-8181-e329795aefa9.png)
 >![FantasmaInventory](https://user-images.githubusercontent.com/114453356/205163452-e8ced32a-e54f-4656-abb7-3a358bd197c4.png)
 >![FantasmaFight](https://user-images.githubusercontent.com/114453356/205163533-3e0ecc40-8ace-41b3-9418-d6373bd1057e.png)
 >![FantasmaWin](https://user-images.githubusercontent.com/114453356/205163610-3610a7ea-c5b9-4a4f-af98-44102edbee33.png)


 ## Installation/Usage
 > Instructions on installing and running your application
 
 Thank you for choosing to play FANTASMA, a text-based RPG.
 
 Our game can be run on any compiler that supports C++, and all the interactions for the game is done via text based inputs and outputs. To install the program, you will run the code from our main.cpp file into a compiler of your choice, and once you press run, the game will run continuously until you either beat the final boss or choose to quit the game. You will first be greeted by a menu that will give you the title of our game (FANTASMA), and you will be able to choose wheter to start playing or quit the game. If you choose to start playing, you will go on to choose your character and their respective attributes, and then continue on to the terrain and the game's various challenges. 
 
 As a player you have the following options during character selection: fighter, bard, tank and mage. All four characters have individual traits, strengths, and items, as well as differences in attack and mana points. Mana is a character's health points, and they are affected by attack points inflicted on the character. These points are used during battles to determine which character survives and which does not, and selecting the right character for your individual play style can mean the difference victory and defeat. This is because each character has access to different items, and only certain characters can use certain items. For example, the "tank" character has access to armor that reduces attack damage done to them, while the "mage" character has access to self-healing items that can allow it to regain lost mana points. 
 
 After you select your character and specic item, you are free to explore the various terrains of the game, all laid out on a map with different towns. Due to the use of ASCII, players get an actual 2D view of the different buildings in the town, and even have the option to enter stores and explore the game map to their own desire.
 
 The main goal of the game is to defeat the final boss with your character, and once you do so, you have officially won the game and this will conclude the storyline. However, you can always choose to start over and challaenge yourself with a different character and totally different playstyle. 
 
 FANTASMA transports players into a magical and medieval world filled with both awe and danger, and their survival and success depends on how well they can guide their chosen character through all the tasks and challenges in the game. Capable of running on multiple machines with minimum requirements, amazing 2D graphics, and an interactive and engaging storyline, FANTASMA will be a game you won't forget!
 
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
  Our project was tested using googletests for each specific element of our game, as well as using valgrind to debug and reduce memory leaks.
 
  For the Item, Bandit, and Boss classes, the approaches to their testing methodologies were all similar in the sense that they utilized googletest as the main locomotive for the testing ground, and it required multiple series of EXPECT_EQs as the item class was a class that the Character draws from and doesn't interact with the direct gameplay very often, but rather provides and adds stats to the Character object itself, so most of the Item class tests consisted of getters. For the bandit and boss testing, it was slightly different in the sense that I had to interact with an object that would directly fight with a character, so I had to simulate a fight and situation where they deal and lose damage. In addition to googletesting, I ran valgrind across all my files and they were devoid of memory leaks.
  
  For the PerlinNoise, NameGenerator, and Town classes, each was approached most hands off, as their constructors use autonomous parameters. However, the tests that were used were EXPECT_EQ, EXPECT_LT, EXPECT_EXIT and others of the same character to ensure that all developed values were within the set bounds of the program. In addition to this, Valgrind was used on the main executable to find any memory leaks in our interconnected systems, which in turn helped to develop more secure code and classes.
 
 For the character class and its subclasses, they utilized the google test framework to run unit tests. Each of the classes had their own test suite with each suite containing tests checking if the characters are able to take damage, attack with the appropriate damage rating, add items into their inventory’s, etc. Furthermore, the character tests utilized EXPECT_EQ, EXPECT_NO_THROW, and ASSERT_EQ to ensure everything was functioning properly.
 
 For the fightScreen tests, I also utilized google test. Mainly these tests consisted of using EXPECT_NO_THROW to ensure nothing was going wrong when passing parameters to the functions within that class. The classes within fightScreen don't return anything, so testing was interaction-based.
 
 For the menu class and it's subclasses, I used the google test framework to run unit tests. These tests checked to see whether the menu would appear, whther the title would appear, and if the correct selection of options to either start or end the game would result in their correct actions. Valgrind was also used to find anny memory leaks after integrating the menu class and it's subclasses with the rest of the code relevant to the game, allowing us to develop more secure and efficient code. 


  
  
