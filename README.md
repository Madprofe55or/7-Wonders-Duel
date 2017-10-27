# 7-Wonders-Duel
Main git for 7 Wonders Duel fan project

README updated on 26-Oct-2017

FUNCTIONALITY STILL NEEDED:
1. Flesh out Civilian Victory - not all points accounted for yet
2. Effects of the following cards/tokens:
    a. Wonders
        ii.  The Great Library, which allows player to immediately gain a progress token from three random unused ones
        iii. The Mausoleum, which allows player to build a discarded card of choice
3. Need to remove ability to build an 8th wonder (turn it over if and when 7th is built)
4. Military/aggression milestones

REFACTORING PLAN:
1. All decks at world construction will be pointers to cards, instead of copies of cards
2. Take a closer look at world and gameplayingstate classes

POLISHING PLAN:
1. Use symbols instead of text to represent resources
2. Music and sounds - STARTED
3. Card movement, dealing at beginning of game
4. Helper cards AND PTs shown in cardpickerstate
5. Text in cardpickerstate saying what cards do
6. Text with wonder cards saying what cards do

FIXED BUGS:
1. Workshop papyrus cost wrong - changed from 0 to 1
2. Game crash when building a wonder - state was going out of scope due to another check being run
3. Game stuck at card destruction - was not properly popping that game state
4. All cards were being destroyed in a player's city when picking a card to destroy - errant semicolon caused following if block to run for each card in the player city vector instead of just the one that was clicked on
5. Being prompted for card destruction at a new age - was caused by the variables governing this not properly being set back to non-destruction state when building a wonder that allowed card destruction, when the opposing player had no cards of that type to destroy
6. Civilian victory not displaying at end of Age 3
    Fix: Had == not = when changing the bool value for the Player1CivilianVictory and  Player2CivilianVictory. JP.
7. Player Choose State would close without choosing the player for the next age. 
    Fix: Removed event handler for mouse click outside of the main area to pop state. (similar to the function that exists in 
    card picker state, etc.)

CURRENT BUG LIST:

1. Could build Statue of Zeus w/o papyrus or enough coins for trade
2. Play Again? Crashed Program on click after civilian victory.

