#include "priklad2.h"

/// Konstruktor (2 body)
Hero::Hero(const std::string name){
    m_name = name;
    m_weapons = {};
}

/// Destruktor (3 body)
Hero::~Hero(){
    m_weapons.empty();
}

/// Pridani zbrane do seznamu zbrani (4 bodu)
//void Hero::addWeapon(){ }
void Hero::addWeapon(Weapon weapon) {
    m_weapons.push_back(weapon);
}

/// Vypise jmena zbrani na obrazovku (3 body)
void Hero::printWeapons(){
    std::for_each(m_weapons.begin(), m_weapons.end(), [](const Weapon &weapon) -> void {
        std::cout << "nazev: " << weapon.getName() << std::endl;
    });
}
