Legends of the five rings
---------------------------

-Goxhaj Marios
    sdi1800031
-Smith Pavlos
    sdi1800181




COMPILATION
-----------

compilation: g++ -std==c++11 *.cpp

RUN
---

./a.out




------------
DESCRIPTION
-------------

CARDS
-----

For the cards we used 7 classes. The Card class is an abstract class, from which the 2 main categories of cards, GreenCards and BlackCards derive. Both GreenCard and BlackCard classes are abstract. Card, BlackCard and GreenCard represent types of
cards, thus we don't have to create objects of these classes. 
Then, we have the Item and Follower classes which derive from GreenCard and the Personality and Holding classes which derive from BlackCard. 
The getType function returns the type of the
card it is called for.In the Personality class,the getitems and getfollowers functions return a list of the items and followers of the corresponding personality, which makes it easier to access them at any time. The unequipdeadfol function 
removes all the dead followers of the personality, the removebrokenitem function removes the items with 0 durability of the personality and the undo function sets as alive the personality or the followers which have been declared as dead from 
the player (this function is used in the battle phase in case the player regrets their choice).

PLAYER
------

The player class represents the player of the game. We use the hand list for keeping the current hand of the player, the provinces list for keeping the current provinces of the player, the army list for keeping the current army of the player,
the attackarmy  list for keeping the army used for attack (which makes it easier to calculate overall attack) and the holdings list for keeping the current holdings of the player. The enemy and enemynum data members keep track of the current enemyplayer
of a player(basically the player they are about to attack).



PHASES
------

Starting Phase
---------------

Every player untaps their cards, draw a fate card and reveal their provinces
No input, output is the player's hand and provinces.

Equip Phase
-----------

The player first has to choose to tap a number of their holdings to earn money (you can also not choose any holdings)
This is done by selecting a holding by the order they appear in the ouput and enter
Type 'done' to confirm your selection and move on.
Desired input (example): <1> <enter> <3> <enter> ... <done>
Money earned only lasts for the phase
Then he can choose followers/items to equip his personalities with.
Selection is done likewise, except there will be a yes or no prompt asking whether you want to upgrade said follower/item.
Type 'done' to end phase

Battle Phase
------------

Every Player has to assign an attack army by choosing from the personalities in their army.
The personalities not chosen are then assigned to defence.
Then, if an attack army was chosen the players have to choose which player and province to attack.
After this is over, all the attacks begin in order.
    
    Player 1 vs Player 2
    ---------------------
     
     <oa> := Player 1's overall attack
     <od> := Player 2's overall defence
     <id> := Player 2's stronghold's initial defence
     
     The battle is determined by the following cases:
    -> <oa>-<od>-<id> > <id>
    ------------------------
          Player 1 wins, destroys chosen province and Player 2 is left with no personalities
          
    -> <oa>-<od> > 0
    ----------------
          Player 2 loses his personalities but Player 1 has to choose enough followers/personalities to sacrifice
          to reach <oa>-<od> attack points.
          
    -> <oa>-<od> = 0
    ----------------
          All players lose their personalities
          
    -> <oa>-<od> < 0
    ----------------
          Player 1 loses his personalities but Player 2 has to choose enough followers/personalities to sacrifice
          to reach <oa>-<od> defence points.
          
    To choose the i follower that belongs to j personality (in the order they're presented in starting from 1)
    Type: i-j
    To choose the i personality
    Type: i
    To confirm selection
    Type: done
    

Economy Phase
-------------

Player can choose to tap some of his holdings to receive money and spend it on new Personalities/Holdings
Money earned lasts only for the phase.
Desired Input: 
               "tap" to select cards to tap
               "buy" to select cards to buy
               "done" to end phase
Selection is done the same as in every other selection, in equip phase e.g.


Last Phase
----------

If player has more than 6 cards in his hand, he must choose one to discard.
This is done like every other selection.
After that player's information and stats are shown.


Victory
-------

The last player remaining in the game is the winner
