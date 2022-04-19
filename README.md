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

![image](https://user-images.githubusercontent.com/35966031/163751387-fe64753e-4836-4271-9bb6-5b31e5617a6f.png)




![image](https://user-images.githubusercontent.com/35966031/163748646-908f9416-7203-49ec-8c9d-06626607c56b.png)

![image](https://user-images.githubusercontent.com/35966031/163905588-715091f2-c217-460d-ac5e-2c2b3154594e.png)


NES Resolution 256 -> X  Pixels
                ^
                | 240 Y

        
