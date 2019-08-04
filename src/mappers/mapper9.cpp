#include "ppu.hpp"
#include "mappers/mapper9.hpp"
#include <stdio.h>

void Mapper9::apply()
{
    map_prg<8>(0, prg_bank);
    map_chr<4>(0, latch0[chr_low_uses_C000]);
    map_chr<4>(1, latch1[chr_high_uses_E000]);

    set_mirroring(horizMirroring ? PPU::HORIZONTAL : PPU::VERTICAL);
}

u8 Mapper9::write(u16 addr, u8 v)
{
    if( !(addr & 0x8000) ) return v;

    switch( (addr >> 12) & 7 )
    {
        case 2: prg_bank        = v & 0x0F; break;
        case 3: latch0[0]       = v & 0x1F; break; 
        case 4: latch0[1]       = v & 0x1F; break; 
        case 5: latch1[0]       = v & 0x1F; break; 
        case 6: latch1[1]       = v & 0x1F; break; 
        case 7: horizMirroring  = v & 1;    break; 
    }

    apply();
    return v;
}

void Mapper9::ppu_tick(u16 addr)
{
    unsigned const magic = addr & 0x2FF8;

    if( magic != 0x0FD8 && magic != 0x0FE8 )
    {
        switch( prev_ppu_addr )
        {
            case 0x0FD8:            chr_low_uses_C000  = false; apply(); break;
            case 0x0FE8:            chr_low_uses_C000  = true;  apply(); break;
            case 0x1FD8 ... 0x1FDF: chr_high_uses_E000 = false; apply(); break;
            case 0x1FE8 ... 0x1FEF: chr_high_uses_E000 = true;  apply(); break;
        }
    }
    
    prev_ppu_addr = addr;
}