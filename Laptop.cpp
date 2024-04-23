//
// Created by Володя on 23.04.2024.
//

#include "Laptop.h"

void Laptop::init(std::string vendor, std::string cpuModel, bool hasGPU) {
    setVendor(vendor);
    setCpuModel(cpuModel);
    setHasGpu(hasGPU);
}

void Laptop::setVendor(const std::string &vendor) {
    if (vendor.empty() || vendor.size() >= 60)
        throw std::invalid_argument("Vendor size must course in (0, 60]");
    Laptop::vendor = vendor;
}

void Laptop::setCpuModel(const std::string &cpuModel) {
    if (cpuModel.empty() || cpuModel.size() >= 60)
        throw std::invalid_argument("CPU model size must course in (0, 60]");
    Laptop::cpuModel = cpuModel;
}

void Laptop::setHasGpu(bool hasGpu) {
    hasGPU = hasGpu;
}

Laptop::Laptop(Laptop &laptop) {
    Laptop::vendor = laptop.vendor;
    Laptop::cpuModel = laptop.cpuModel;
    Laptop::hasGPU = laptop.hasGPU;
}

void Laptop::print() {
    std::cout << std::endl << "———Laptop info———" << std::endl;
    std::cout << "Vendor: " << vendor << std::endl;
    std::cout << "CPU model: " << cpuModel << std::endl;
    std::cout << "HAS GPU: " << (hasGPU ? "true" : "false") << std::endl;
}

Laptop::Laptop(const std::string &vendor, const std::string &cpuModel, bool hasGPU) {
    init(vendor, cpuModel, hasGPU);
}
