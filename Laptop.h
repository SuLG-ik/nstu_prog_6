//
// Created by Володя on 23.04.2024.
//

#pragma once

#include <iostream>

class Laptop {
    std::string vendor, cpuModel;
    bool hasGPU;

private:
public:
    Laptop(Laptop &laptop);

    Laptop(const std::string &vendor = "NO DATA", const std::string &cpuModel = "NO DATA", bool hasGPU = false);

private:
    void init(std::string vendor, std::string cpuModel, bool hasGPU);

public:
    void setVendor(const std::string &vendor);

    void setCpuModel(const std::string &cpuModel);

    void setHasGpu(bool hasGpu);

    void print();
};