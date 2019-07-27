set(Nesicon_SRCS
    apu.cpp
    cartridge.cpp 
    config.cpp 
    cpu.cpp 
    gui.cpp 
    joypad.cpp 
    main.cpp 
    mapper.cpp 
    menu.cpp 
    ppu.cpp 
    mappers/mapper1.cpp
    mappers/mapper2.cpp
    mappers/mapper3.cpp
    mappers/mapper4.cpp
)

add_executable(nesicon ${Nesicon_SRCS})
target_link_libraries(nesicon nesapu ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
