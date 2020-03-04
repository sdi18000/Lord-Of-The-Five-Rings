compilation: g++ -std==c++11 *.cpp


Cards:

For the cards we used 7 classes.The Card class is an abstract class,from which the 2 main categories of cards,GreenCards and BlackCards,derive.Both GreenCard and BlackCard classes are abstract.Card,BlackCard and GreenCard represent types of
cards,thus we dont have to create object of these classes.Then,we have the Item and Follower classes which derive from GreenCard and the Personality and Holding classes which derive from BlackCard.The getType function returns the type of the
card it is called for.In the Personality class,the getitems and getfollowers functions return a list of the items and followers of the corresponding personality,which makes it easier to access them anytime.The unequipdeadfol function 
removes all the dead followers of the personality,the removebrokenitem function removes the items with 0 durability of the personality and the undo function sets alive the personality or the followers which have been declared as dead from 
the player(this function is used in the battle phase in case the player regrets their choice).

Player:
The player calss represents the player of the game.We use the hand list for keeping the current hand of the player,the provinces list for keeping the current provinces of the player,the army list for keeping the current army of the player,
the attackarmy  list for keeping the army used for attack (which makes it easier to calculate overall attack) and the holdings list for keeping the current holdings of the player.The enemy and enemynum data members keep track of the current enemyplayer
of a player(basically the player they are about to attack).