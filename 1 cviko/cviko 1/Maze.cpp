//
//  Maze.cpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Maze.hpp"
#include <iostream>


Maze::Maze(){
    worm = new Worm(3, 3);
    
    plan = std::array<std::array<char, 5>, 5>();
    
    for(auto &row: plan){           // projdeme radky mapy
        for(auto &column: row){     // projdeme sloupce radku
            column = '-';           // vyplnime policka symbolem
        }
    }
    
}
void Maze::print() const{
    for(int y = 0; y < plan.size(); y++){ //musi tu byt klasicky for s intem, potrebujeme cisla indexu
        for(int x = 0; x < plan.at(y).size(); x++){
            
            //jestli je tam worm vykresli worma
            if(worm->getX() == x and worm->getY() == y){
                std::cout << Worm::symbol;
            }else{
                std::cout << plan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}
bool Maze::checkDirection(int x, int y) const{
    int newX = worm->getX() + x;
    int newY = worm->getY() + y;
    
    return (
            newX >= 0
            and newX <= plan.at(0).size()-1 // nebude zavisle na velikosti mapy
            and newY >= 0
            and newY <= plan.at(0).size()-1 // nebude zavisle na velikosti mapy
            );
}
void Maze::moveWorm(int x, int y){
    worm->moveTo(worm->getX() + x, worm->getY() + y);
}
