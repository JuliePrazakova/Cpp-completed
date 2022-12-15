#include <memory>
#include "RoverTest.hpp"
#include "../Rover.h"
#include "../materials/Ice.h"
#include "../materials/Water.h"
#include "../materials/Soil.h"
#include "../materials/Concrete.h"

void RoverTest::run() {
    testProcessMaterialInStorageWithIce();
    testProcessMaterialInStorageWithSoil();
}

void RoverTest::testProcessMaterialInStorageWithIce() {
    // 1. prepare data

    // a rover converting Ice to Water
    auto rover = new Rover<Ice, Water>();

    // some ice blocks found under the surface of Mars loaded to the rover
    auto ice1 = std::make_unique<Ice>(Ice{1.2, -62.5}); // making an instance of Ice wrapped into unique pointer, so only one object can own the reference to this Ice
    rover->loadMaterial(std::move(ice1));
    auto ice2 = std::make_unique<Ice>(Ice{0.9, -65.5}); // making an instance of Ice wrapped into unique pointer, so only one object can own the reference to this Ice
    rover->loadMaterial(std::move(ice2));
    rover->printStorageInfo();

    // 2. call the tested method
    auto result = rover->processMaterialInStorage();

    // 3. verify the result
    test_(result.size() == 2);
    test_(1.2f - result.at(0).m_volume <= 0.15); // there is some loss during the conversion from Ice to Water
    test_(0.9f - result.at(1).m_volume <= 0.1); // there is some loss during the conversion from Ice to Water

    delete rover;
}

void RoverTest::testProcessMaterialInStorageWithSoil() {
    // 1. prepare data

    // a rover converting Ice to Water
    auto rover = new Rover<Soil, Concrete>();

    // some ice blocks found under the surface of Mars loaded to the rover
    auto soil1 = std::make_unique<Soil>(Soil{4.05, "stone"}); // making an instance of Soil wrapped into unique pointer, so only one object can own the reference to this Soil
    rover->loadMaterial(std::move(soil1));
    auto soil2 = std::make_unique<Soil>(Soil{2.8, "stone,sand"}); // making an instance of Soil wrapped into unique pointer, so only one object can own the reference to this Soil
    rover->loadMaterial(std::move(soil2));
    rover->printStorageInfo();

    // 2. call the tested method
    auto result = rover->processMaterialInStorage();

    // 3. verify the result
    test_(result.size() == 2);
    test_(4.05f * 0.2 - result.at(0).m_weight <= 1.3); // there is some loss during the conversion from Ice to Water
    test_(2.8f * 0.2 - result.at(1).m_weight <= 0.9); // there is some loss during the conversion from Ice to Water

    delete rover;
}
