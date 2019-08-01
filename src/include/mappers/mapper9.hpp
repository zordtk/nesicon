#pragma once
#include "mapper.hpp"


class Mapper9 : public Mapper
{
    u8 prg_bank;
    u8 latch0[2], latch1[2];
    u16 prev_ppu_addr;

    bool chr_low_uses_C000, chr_high_uses_E000;
    bool horizMirroring;

    void apply();

  public:
    Mapper9(u8* rom) : Mapper(rom)
    {
        map_prg<8>(1, -3);
        map_prg<8>(2, -2);
        map_prg<8>(3, -1);

        prg_bank = 0;
        latch0[0] = latch1[0] = 0;
        latch0[1] = latch1[1] = 0;
        chr_low_uses_C000 = chr_high_uses_E000 = false;
        prev_ppu_addr = 0;

        apply();
    }


    u8 write(u16 addr, u8 v);
    void ppu_tick_callback(u16 addr);
};
