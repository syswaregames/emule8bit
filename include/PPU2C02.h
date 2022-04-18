/*
    ==========================
        Emule - NES Emulator
    ==========================
    8-bit architecture, 6500 processor 

    Patrick Carvalho - 2022
*/

#pragma once

#include "Cartridge.h"
#include "olcPixelGameEngine.h"

class PPU2C02
{

public:
    PPU2C02();
    ~PPU2C02();

    // Main Bus Read & Write
    uint8_t cpuRead(uint16_t addr, bool bReadOnly);
    void cpuWrite(uint16_t addr, uint8_t data);

    // PPU Bus Read & Write
    uint8_t ppuRead(uint16_t addr, bool bReadOnly);
    void ppuWrite(uint16_t addr, uint8_t data);

    // System Interface    
	void ConnectCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void clock();

    // Debugging Utilities
	olc::Sprite& GetScreen();
	olc::Sprite& GetNameTable(uint8_t i);
	olc::Sprite& GetPatternTable(uint8_t i);
	bool frame_complete = false;

    

private:
    std::shared_ptr<Cartridge> cart;

    uint8_t     tblName[2][1024]; // 1kb - VRAM Name Table	
	uint8_t		tblPalette[32];  // 32 entries pallet RAM
    
    uint8_t     tblPattern[2][4096]; // future

    olc::Pixel  palScreen[0x40];
	olc::Sprite sprScreen          =   olc::Sprite(256, 240);
	olc::Sprite sprNameTable[2]    = { olc::Sprite(256, 240), olc::Sprite(256, 240) };
	olc::Sprite sprPatternTable[2] = { olc::Sprite(128, 128), olc::Sprite(128, 128) };

    int16_t scanline = 0; // Row on the screen
	int16_t cycle = 0;    // Colum on the screen

    
    
};