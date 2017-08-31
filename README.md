# 7-Wonders-Duel
Main git for 7 Wonders Duel fan project

README updated on 31-Aug-2017

FUNCTIONALITY STILL NEEDED:
1. Building wonders, and applying their effects
2. Choosing progress tokens when getting a pair of science symbols
3. Game end state, and winner calculations for civilian victories
4. Effects of the following cards/tokens:
    a. Wonders
        i.   Circus Maximus, which allows player to destroy opponent's gray card
        ii.  The Great Library, which allows player to immediately gain a progress token from three random unused ones
        iii. The Mausoleum, which allows player to build a discarded card of choice
        iv.  The Statue of Zeus, which allows player to destroy opponent's brown card
    c. All progress tokens (see #2 above)
5. Code for handling special/trading flags


REFACTORING PLAN:
1. All decks at world construction will be pointers to cards, instead of copies of cards
2. Take a closer look at world and gameplayingstate classes


POLISHING PLAN:
1. Use symbols instead of text to represent resources
2. Music and sounds
