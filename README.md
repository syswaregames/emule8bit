# emule8bit
Emule - NES Emulator, 8-bit architecture, 6500 processor 
Optimized for MACOSX

8-bits
Binary: 11111111 (FF)

The only requirement is having X11 installed. X11 is no longer included in macOS, but X11 server and client libraries are available from the XQuartz project (see https://support.apple.com/en-us/HT201341).

You can download X11 from https://www.xquartz.org/ and easily install it. Typical installation path is /usr/X11 and it contains includes and libraries for X11 and OpenGL.

16kb Chunks = ROM -> Cpu maps reads


PPU

 -> Patern Memory "CHR ROM" 8kb 0x0000 - 0x1FFF (Sprites)
   -> Name Table Memory "VRAM" 2kb 0x2000 - 0x3EFF (Layout of Background)
    -> Palett Memory 0xF00 - 0x3FFF (decide which colors are displayed on the screen )

  Tile is 8 * 8 bitmap, 2 bits per pixel, (16bytes) four colors per pixel


    // Characters on NES
	// ~~~~~~~~~~~~~~~~~
	// The NES stores characters using 2-bit pixels. These are not stored sequentially
	// but in singular bit planes. For example:
	//
 	// 2-Bit Pixels       LSB Bit Plane     MSB Bit Plane
	// 0 0 0 0 0 0 0 0	  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0
	// 0 1 1 0 0 1 1 0	  0 1 1 0 0 1 1 0   0 0 0 0 0 0 0 0
	// 0 1 2 0 0 2 1 0	  0 1 1 0 0 1 1 0   0 0 1 0 0 1 0 0
	// 0 0 0 0 0 0 0 0 =  0 0 0 0 0 0 0 0 + 0 0 0 0 0 0 0 0
	// 0 1 1 0 0 1 1 0	  0 1 1 0 0 1 1 0   0 0 0 0 0 0 0 0
	// 0 0 1 1 1 1 0 0	  0 0 1 1 1 1 0 0   0 0 0 0 0 0 0 0
	// 0 0 0 2 2 0 0 0	  0 0 0 1 1 0 0 0   0 0 0 1 1 0 0 0
	// 0 0 0 0 0 0 0 0	  0 0 0 0 0 0 0 0   0 0 0 0 0 0 0 0
	//
	// The planes are stored as 8 bytes of LSB, followed by 8 bytes of MSB

PPU - Palett

The NES PPU uses a background palette with up to 13 of these colors at a time, consisting of one common backdrop color and four subpalettes of three colors, chosen from the above set. The PPU's video memory layout allows choosing one subpalette for each 16×16 pixel area of the background. (A special video mode of the MMC5 mapper overrides this, assigning a subpalette to each 8×8-pixel tile.) Sprites have an additional set of four 3-color subpalettes (with color 0 being transparent in each) and every 8x8 or 8x16 pixels can have their own subpalette, allowing for a total of 12 different colors to use for sprites at any given time, or a total of 25 on-screen colors.

Because of the constraints mentioned above, converting a photograph often results in attribute clash at 16×16-pixel boundaries. Conversions with and without dithering follow, using the hex palette 0F160608 0F162720 0F090010 0F0A1910 (the repeated 0F represents black as the common backdrop color).

![image](https://user-images.githubusercontent.com/35966031/163751387-fe64753e-4836-4271-9bb6-5b31e5617a6f.png)




![image](https://user-images.githubusercontent.com/35966031/163748646-908f9416-7203-49ec-8c9d-06626607c56b.png)

![image](https://user-images.githubusercontent.com/35966031/163905588-715091f2-c217-460d-ac5e-2c2b3154594e.png)


NES Resolution 256 -> X  Pixels
                ^
                | 240 Y

        
8-bit graphics refers to the capability of every pixel to use 8 bits for storing the amount of colors that can be displayed. In a nutshell, 8-bit graphics refers to maximum 256 colors that can be displayed, whereas 16 bit means 65,536 colors and 34 bit means 16,777,215 colors.

Color-wise, the NES used a palette of 56 colors across the board for all games. Rather than being mathematically created by 2-bit RGB values (like the Sega Master System's 64 color palette), instead the NES's palette seems to have been hand-selected and is a bit different.

How many colors did NES sprites have? 4 colors
Number of Colors Per Sprite
Sprites on the NES were limited to 4 colors (or 3 colors + transparency)


original 1985 Front-Loading NES motherboard.
https://github.com/Redherring32/OpenTendo