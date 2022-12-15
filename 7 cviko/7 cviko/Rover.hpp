//
//  Rover.hpp
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef Rover_hpp
#define Rover_hpp
#include <vector>
#include <iostream>

// udelame z toho template classu a nepotrebujeme .cpp soubor = implementace bude tady
// template <i, o> type NazevTridy<i, o> NazevFunkce {}
template <class I, class O> class Rover {
private:
    std::vector<I> m_parcels;
public:
    //BACHA template class nema konstruktor
    void printParcels() const;
    void addParcel(I parcel);
    std::vector<O> processedParcel();
};

template<class I, class O>
void Rover<I, O>::printParcels() const {
    for_each(m_parcels.begin(), m_parcels.end(), [](const I &p){
        p.printInfo();
    });
}

template <class I, class O>void Rover<I, O>::addParcel(I parcel){
    m_parcels.push_back(parcel);
}

template<class I, class O>
std::vector<O> Rover<I, O>::processedParcel() {
    std::vector<O> processedMaterials;                       // prazdny vektor zatim

    while (!m_parcels.empty()) {                             // dokud to neni prazdne
        auto currentlyProcessedMaterial = m_parcels.front(); // get the first material in the storage
        O processedMaterial(currentlyProcessedMaterial);     // processing the input material using the constructor of the output material `O`
        processedMaterials.push_back(processedMaterial);     // adding the output processed material to the result vector
        m_parcels.erase(m_parcels.begin());                  // removing the input material from the storage after it has been processed
    }

    return processedMaterials;
}

#endif /* Rover_hpp */
