//
//  Maze.cpp
//  cviko 1
//
//  Created by Julie Pražáková on 11.12.2022.
//

#include "Maze.hpp"
#include <iostream>


Maze::Maze(){
    tesla = new Tesla(3, 3);
    
    plan = std::array<std::array<char, 5>, 5>();
    
    for(auto &row: plan){           // projdeme radky mapy
        for(auto &column: row){     // projdeme sloupce radku
            column = '-';           // vyplnime policka symbolem
        }
    }
    
    plan.at(1).at(1) = '+';         // nastavime dobijeci stanice
    plan.at(2).at(4) = '+';
    plan.at(4).at(2) = '+';
}
void Maze::print() const{
    for(int y = 0; y < plan.size(); y++){ //musi tu byt klasicky for s intem, potrebujeme cisla indexu
        for(int x = 0; x < plan.at(y).size(); x++){
            
            //jestli je tam worm vykresli worma
            if(tesla->getX() == x and tesla->getY() == y){
                std::cout << Tesla::symbol;
            }else{
                std::cout << plan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}
bool Maze::checkDirection(int x, int y) const{
    int newX = tesla->getX() + x;
    int newY = tesla->getY() + y;
    
    return (
            newX >= 0
            and newX <= plan.at(0).size()-1 // nebude zavisle na velikosti mapy
            and newY >= 0
            and newY <= plan.at(0).size()-1 // nebude zavisle na velikosti mapy
            );
}
void Maze::moveTesla(int x, int y){
    if(tesla->getBatery() == 0){
        std::cout << "Nemate energii, nelze jezdit";
    }else {
        tesla->moveTo(tesla->getX() + x, tesla->getY() + y);
    }
    if(isSupercharger(tesla->getX(), tesla->getY())){
        tesla->addBatery();
    }
}
bool Maze::isSupercharger(int x, int y){
    return plan.at(x).at(y) == '+';
}
void Maze::printBatery(){
    std::cout << "Baterie tesly: " << tesla->getBatery() << std::endl;
}
char Maze::getField(int x, int y) const{
    return plan.at(x).at(y);
}
Tesla* Maze::getTesla() const{
    return tesla;
}
