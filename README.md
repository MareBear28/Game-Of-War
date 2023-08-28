# Game-Of-War 🃏⚔️
This program simulates the card game War. The game of War is a card game where a deck(s) is split evenly to all players and in each round, all players will flip the top card of their deck onto the table. From all the cards placed down, the player with the highest card would inherit all cards on the table. 

## Rules of War 💡
Before playing War, player must enter the number of players playing and the number of decks being used.

During each round:
1. All players place top card of their pile onto the table.
2. Find which player has the highest card inherits all cards on the table. (Ace = 1, 2 = 2, ..., K = 13)
    - If there are 2 or more players have the highest value card, there is a war. These players would lay down 3 cards faced down on the table and place the fourth card face up onto the table. The card facing up will be used as the battle card. Whoever has the highest battle card wins the war and all cards on the table.
3. Game continues until one person obtains all the cards.

## Stats 📈
After each round, stats of each player will be displayed. Stats that would be displayed include:
- Fierceness = The average value of their hand
    - (ex. If a hand has a King, Queen, 9, and 3, then the Fierceness is 9.25)
- Cards = The number cards the player has
- Battles = The number of battles the player has participated in
- Won = The number of battles/wars the player has won