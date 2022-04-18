/*
    ==========================
        Emule - NES Emulator
    ==========================
    8-bit architecture, 6500 processor 

    Patrick Carvalho - 2022
*/

#include "Mapper.h";

Mapper::Mapper(uint8_t prgBanks, uint8_t chrBanks)
{
	nPRGBanks = prgBanks;
	nCHRBanks = chrBanks;

	reset();
}


Mapper::~Mapper()
{
}

void Mapper::reset()
{

}