#include <iostream>
#include "Laptop.h"

int intInputWithLabel() {
    std::string value;
    do {
        std::getline(std::cin, value);
        try {
            int iValue = std::stoi(value);
            if (iValue != 0 && iValue != 1) {
                throw std::invalid_argument("");
            }
            return iValue;
        } catch (...) {
            std::cout << "Invalid number entered! Try again\n";
        }
    } while (true);
}

Laptop *initLaptop() {
    std::string vendor;
    std::string cpuModel;
    bool hasGPU;
    bool loop = true;
    while (loop) {
        try {
            std::cout << std::endl << "Input Laptop" << std::endl;
            std::cout << "Vendor name: ";
            std::getline(std::cin, vendor);
            std::cout << "CPU model: ";
            std::getline(std::cin, cpuModel);
            std::cout << "Has gpu (0, 1): ";
            hasGPU = intInputWithLabel();
            return new Laptop(vendor, cpuModel, hasGPU);
        } catch (std::invalid_argument &e) {
            std::cout << "Error during initializing. " << e.what() << std::endl;
            std::cout << "Try again? (0, 1): ";
            loop = intInputWithLabel();
        }
    }
    return nullptr;
}

int main() {
    Laptop laptop1, laptop2("Asus", "china silicon", true);
    laptop1.print();
    laptop2.print();
    Laptop laptop3(laptop2);
    laptop3.print();
    laptop1.setVendor("Apple");
    laptop1.setCpuModel("amd");
    laptop1.print();
    Laptop *laptop4 = initLaptop();
    if (!laptop4) {
        std::cout << "User interrupt laptop4 input" << std::endl;
    } else {
        laptop4->print();
    }
    Laptop *laptop5 = initLaptop();
    if (!laptop5) {
        std::cout << "User interrupt laptop4 input" << std::endl;
    } else {
        laptop5->print();
    }
    delete laptop4;
    delete laptop5;
    return 0;
}
