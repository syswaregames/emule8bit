/*
    ==========================
        Emule - NES Emulator
    ==========================
    8-bit architecture, 6500 processor 

    Patrick Carvalho - 2022
*/

#pragma once
#include "Mapper.h"

class Mapper_000 : public Mapper
{
public:
    Mapper_000(uint8_t prgBanks, uint8_t chrBanks);
    ~Mapper_000();

    // Transform CPU bus address into PRG ROM offset
	bool cpuMapRead(uint16_t addr, uint32_t &mapped_addr) override;
	bool cpuMapWrite(uint16_t addr, uint32_t &mapped_addr) override;
    
	// Transform PPU bus address into CHR ROM offset
	bool ppuMapRead(uint16_t addr, uint32_t &mapped_addr) override;
	bool ppuMapWrite(uint16_t addr, uint32_t &mapped_addr) override;
};