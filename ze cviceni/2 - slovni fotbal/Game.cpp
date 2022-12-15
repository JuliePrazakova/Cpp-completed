//
// Created by Ivo Pisařovic on 01/10/2020.
//

#include "Game.h"
#include <iostream>


Game::Game() {
    dictionary = new Dictionary();
}


void Game::printIntroduction() const {
 std::cout << "Game started, enter a word..." << std::endl;
}

void Game::printSystemWord(Word word) const {
    std::cout << "System: " << word.getWord() << std::endl;
}

Word Game::waitForInput() const {
    std::cout << "Enter word: ";
    std::string word;
    std::cin >> word;
    return Word(word);
}

void Game::printEndOfGame() const {
    std::cout << "Game ended." << std::endl;
}

void Game::play() {
    int round = 0;
    Word previousSystemWord = Word("");

    printIntroduction();

    while (true) {
        Word userWord = waitForInput();

        if (round > 0 and userWord.isConnectedTo(previousSystemWord) == false) {
            end();
        }

        Word systemWord = dictionary->findConnectedWord(userWord);
        processSystemWord(systemWord);
        previousSystemWord = systemWord;

        round++;
    }
}

void Game::processSystemWord(Word systemWord) const {
    if (systemWord.notFound()) {
        end();
    } else {
        printSystemWord(systemWord);
    }
}

void Game::end() const {
    printEndOfGame();
    exit(0);
}
