set(APU_Lib_SRCS
    apu_snapshot.cpp 
    Blip_Buffer.cpp 
    Multi_Buffer.cpp 
    Nes_Apu.cpp 
    Nes_Namco.cpp 
    Nes_Oscs.cpp 
    Nes_Vrc6.cpp 
    Nonlinear_Buffer.cpp 
    Sound_Queue.cpp 
)

add_library(nesapu ${APU_Lib_SRCS})