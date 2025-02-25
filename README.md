# Pokémon Emerald Speedchoice - Full Item Randomizer Edition 

This is a version of the Pokemon Emerald Speedchoice by Revo (https://github.com/ProjectRevoTPP/pokeemerald-speedchoice) that will be compatible with the Pokemon Emerald Full Item Randomizer once finished.

This project is currently active and ongoing as of 3/29/2022. 

It builds the following ROM:

* pokeemerald-speedchoice.gba

To set up the repository, see [INSTALL.md](INSTALL.md).

## Changelog

* Creating a mach bike path on Route 103 to allow travel across the water without Surf. To be used with Early Mach Path modifier in the Item Randomizer.
* Creating an acro bike path on Route 115 to allow early access to Meteor Falls. To be used with Early Acro Path modifier in the Item Randomizer.
* Removing the "Start with Bike" and "Super Bike" features, as those would defeat the purpose of the item rando.
* Shifting the locations of the Kecleon on Route 120 in order to require the Devon Scope item (not just talking to Steven) in order to pass between the two halves of the route.
* Each Frontier Brain can be fought immediately (Factory, Pike), after one additional fight (Palace, Arena, Tower), or at the end of one run through of the facility (Dome). 
* The Battle Pyramid Brain can be fought after completing one floor of the pyramid.
* Level/Mon restrictions for Frontier are removed. 
* Created event scripts for every obtainable item, badge, frontier symbol. This also includes the Pokedex, National Dex, PokeNav, Running Shoes, Frontier Pass.
* Converted all item ball scripts to allow obtaining badges, frontier symbols, and other non-standard items.
* The Pokedex and National Dex will be obtained progressively from Regional Dex to National Dex, regardless of which you find first.
* The SSTidal will be available as soon as you have access to Slateport and have the SSTicket in your inventory. This allows early access to Lilycove.
* New speedchoice menu preset for Item Rando, set as default.

## Planned Changes/Features

### High Priority:

* Reworking items given by NPCs to be compatible with the new item scripts.
* Steven's Room in Meteor Falls will be modified to open when talking to Scott at his house in the Battle Frontier after beating Champion, obtaining all 7 silver symbols, or obtaining 7 gold symbols. To be used with the Race End modifier in the Item Randomizer. 
* The Frontier Pass will be repurposed to allow access to the Battle Frontier when paired with the SSTicket.
* Removing the group of Wailmer blocking Route 124 and the old man blocking Cave of Origin from the start. 
* Rayquaza event in Sootopolis will be skipped, and Rayquaza will be available as soon as you talk to Wallace in Cave of Origin.
* Sootopolis Gym will always be open.
* Magma Emblem will not only unlock the Magma Hideout in Jagged Pass, but it will also remove the guards blocking the Aqua Hideout and Seafloor Hideout. 
* You will not be able to hand Steven the letter for his item unless the Letter is in your inventory.
* Dock in Slateport will not acknowledge the Devon Goods unless you have them in your inventory, making them required to access the Slateport Museum, as well as Route 110 without a bike.  
* Battle Frontier facilities will have one check each for defeating the brain. No progress items will be placed beyond the first brain fights. 
* New "vanilla" locations for event items.
* Create new scripts for berry trees in order to allow compatibility with the rest of the item pool.

### Low(er) Priority:

* Releasing Groudon or Kyogre from Magma Hideout/Seafloor Hideout, plus having their respective orb (Red or Blue), will cause the post-game event to catch the respective legendary to be available instead of them going to Sootopolis for the event. 
* Changing how hidden items are handled in order to allow for badges, etc. Or find a workaround.


## See also

* [Original decompilation by pret](https://github.com/pret/pokeemerald)

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)
