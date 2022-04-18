/*
    ==========================
        Emule - NES Emulator
    ==========================
    8-bit architecture, 6500 processor 
	
    Patrick Carvalho - 2022
*/

#pragma once

#include <array>
#include <cstdint> 
#include "olc6502.h"
#include "PPU2C02.h"
#include "Cartridge.h"

class Bus
{

public: 
    Bus();
    ~Bus();

public:    
    // Devices on bus
    olc6502 cpu;

    // The 2C02 Picture Processing Unit
    PPU2C02 ppu;

    // The Cartridge or "GamePak"
	std::shared_ptr<Cartridge> cart;

    // CPU RAM 
    // std::array<uint8_t, 2048> cpuRam; // 2kb RAM
   
    // Fake RAM for Board View Simulator
	std::array<uint8_t, 64 * 1024> cpuRam; // 65kb

public:     
    // Bus Read & Write
    void cpuWrite(uint16_t addr, uint8_t data);
    uint8_t cpuRead(uint16_t addr, bool bReadOnly);

    // System Interface 
    void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
    void reset();
    void clock();

private:
	// A count of how many clocks have passed
	uint32_t nSystemClockCounter = 0;
};
