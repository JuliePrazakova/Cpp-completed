#include "priklad2.h"

/// Konstruktor (2 body)
Hero::Hero(const std::string name){
    m_name = name;
    Weapon* w = NULL;
    m_w = w;
}

/// Destruktor (3 body)
Hero::~Hero(){
    delete (m_w);
}
Weapon& Hero::operator*(){
    return *m_w;
}

/// Pridani zbrane do seznamu zbrani (4 bodu)
void Hero::addWeapon(Weapon* weapon){
//    std::unique_ptr<Weapon> weapon2(weapon);
    m_weapons.push_back(weapon);
}


/// Vypise jmena zbrani na obrazovku (3 body)
void Hero::printWeapons(){
    for_each(m_weapons.begin(), m_weapons.end(), [](const Weapon &w){
        std::cout << "Name: "<< w.getName() << " Strenght: " << w.getStrength() << std::endl;
    });
}
