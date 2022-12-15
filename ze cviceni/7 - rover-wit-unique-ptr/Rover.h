//
// Created by ivo on 24/10/22.
//

#ifndef COMPLETE_ROVER_H
#define COMPLETE_ROVER_H

#include <array>
#include <vector>
#include <memory>

template <class I, class O> class Rover {
private:
    std::vector<std::unique_ptr<I>> m_storage; // the rover's storage contains unprocessed material
public:
    void loadMaterial(std::unique_ptr<I> material);
    std::vector<O> processMaterialInStorage();
    void printStorageInfo() const;
};


// --- IMPLEMENTATION ---
// --- the template class must have its implementation in header file ---

template<class I, class O>
void Rover<I, O>::loadMaterial(std::unique_ptr<I> material) {
    m_storage.push_back(std::move(material)); // when using the unique_ptr, we must use std::move everywhere we pass the variable to another place
}

template<class I, class O>
std::vector<O> Rover<I, O>::processMaterialInStorage() {
    std::vector<O> processedMaterials;

    while (!m_storage.empty()) {
        auto currentlyProcessedMaterial = std::move(m_storage.front()); // move the pointer from the vector to a local variable
        O processedMaterial(std::move(currentlyProcessedMaterial)); // moving the pointer of the current input material to the constructor of output material
        processedMaterials.push_back(processedMaterial); // adding the output processed material to the result vector
        m_storage.erase(m_storage.begin()); // removing the input material from the storage after it has been processed
    }

    return processedMaterials;
}

template<class I, class O>
void Rover<I, O>::printStorageInfo() const {
    for (auto it = m_storage.begin(); it != m_storage.end(); it++) {
        (**it).printInfo(); // double `*` to unwrap both the iterator and the unique_ptr inside
    }
}


#endif //COMPLETE_ROVER_H
