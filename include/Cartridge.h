/*
    ==========================
        Emule - NES Emulator
    ==========================
    8-bit architecture, 6500 processor 

    Patrick Carvalho - 2022
*/

#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
#include "Mapper_000.h"

class Cartridge
{
    public:
    Cartridge(const std::string& sFileName);
    ~Cartridge();

    bool ImageValid();

    enum MIRROR
	{
		HORIZONTAL,
		VERTICAL,
		ONESCREEN_LO,
		ONESCREEN_HI,
	} mirror = HORIZONTAL;

    // Main Bus Read & Write
    bool cpuRead(uint16_t addr, uint8_t &data);
    bool cpuWrite(uint16_t addr, uint8_t data);

    // PPU Bus Read & Write
    bool ppuRead(uint16_t addr, uint8_t &data);
    bool ppuWrite(uint16_t addr, uint8_t data);

    private:

    bool bImageValid = false;

    uint8_t nMapperID = 0;
	uint8_t nPRGBanks = 0;
	uint8_t nCHRBanks = 0;

    std::vector<uint8_t> vPRGMemory;
	std::vector<uint8_t> vCHRMemory;

    std::shared_ptr<Mapper> pMapper;
};