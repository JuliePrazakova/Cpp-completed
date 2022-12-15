#include "Game.hpp"
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
    Word previousSystemWord = Word(""); //pocatecni slovo

    printIntroduction();        //uvod

    while (true) {
        Word userWord = waitForInput();     //uzivatelovo slovo

        if (round > 0 and userWord.isConnectedTo(previousSystemWord) == false) { //pokud zadal spatne slovo
            end();
        }

        Word systemWord = dictionary->findConnectedWord(userWord); //hledame odpoved
        processSystemWord(systemWord);   // kontrola jestli jsme nasli odpoved
        previousSystemWord = systemWord; // do minuleho slova dame to aktualni -> jdem na dalsi kolo

        round++;            // dalsi kolo
    }
}

void Game::processSystemWord(Word systemWord) const {
    if (systemWord.notFound()) {        //pokud nenajdem slovo = konec
        end();
    } else {                            //pokud najdem slovo = vyprintujem
        printSystemWord(systemWord);
    }
}

void Game::end() const {
    printEndOfGame();     //napis konec
    exit(0);              //vypni
}
