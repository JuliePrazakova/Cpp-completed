//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_ROVER_H
#define COMPLETE_ROVER_H

#include <array>
#include <vector>

template <class I, class O> class Rover {
private:
    std::vector<I> m_storage; // the rover's storage contains unprocessed material
public:
    void loadMaterial(I material);
    std::vector<O> processMaterialInStorage();
    void printStorageInfo() const;
};


// --- IMPLEMENTATION ---
// --- the template class must have its implementation in header file ---

template<class I, class O>
void Rover<I, O>::loadMaterial(I material) {
    m_storage.push_back(material);
}

template<class I, class O>
std::vector<O> Rover<I, O>::processMaterialInStorage() {
    std::vector<O> processedMaterials;

    while (!m_storage.empty()) {
        auto currentlyProcessedMaterial = m_storage.front(); // get the first material in the storage
        O processedMaterial(currentlyProcessedMaterial); // processing the input material using the constructor of the output material `O`
        processedMaterials.push_back(processedMaterial); // adding the output processed material to the result vector
        m_storage.erase(m_storage.begin()); // removing the input material from the storage after it has been processed
    }

    return processedMaterials;
}

template<class I, class O>
void Rover<I, O>::printStorageInfo() const {
    for (auto it = m_storage.begin(); it != m_storage.end(); it++) {
        (*it).printInfo(); // `*` to unwrap the iterator
    }
}


#endif //COMPLETE_ROVER_H
