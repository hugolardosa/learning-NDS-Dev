 /*
	This is game dev buy Hugo Leal

	Using NightFox's Lib
*/

// Includes C
#include <stdio.h>
// Nds
#include <nds.h>
// nightFox
#include <nf_lib.h>


int main(int argc, char **argv) {

	// Initializing the 2 screens in 2D
	NF_Set2D(0, 0);
	NF_Set2D(1, 0);	
	consoleDemoInit();
	iprintf("\n NitroFS init. Please wait.\n\n");
	iprintf(" Iniciando NitroFS,\n por favor, espere.\n\n");
	swiWaitForVBlank();

	// Define el ROOT e inicializa el sistema de archivos
	NF_SetRootFolder("NITROFS");	// Define la carpeta ROOT para usar NITROFS

	// Inicializa el motor 2D
	NF_Set2D(0, 0);				// Modo 2D_0 en ambas pantallas
	NF_Set2D(1, 0);

	// Inicializa el engine de audio de la DS
	soundEnable();

	// Inicializa los fondos tileados
	NF_InitTiledBgBuffers();	// Inicializa los buffers para almacenar fondos
	NF_InitTiledBgSys(0);		// Inicializa los fondos Tileados para la pantalla superior
	NF_InitTiledBgSys(1);		// Iniciliaza los fondos Tileados para la pantalla inferior

	// Inicializa el motor de texto
	NF_InitTextSys(0);			// Inicializa el texto para la pantalla superior

	// Inicializa los buffers de sonido
	NF_InitRawSoundBuffers();

	// Carga los archivos de fondo desde la FAT / NitroFS a la RAM
	NF_LoadTiledBg("bg/layer3", "moon", 256, 256);		// Carga el fondo para la capa 3, pantalla inferior

	// Carga la fuente por defecto para el texto
	NF_LoadTextFont("fnt/default", "normal", 256, 256, 0);	// Carga la seccion "normal" de la fuente

	// Carga los samples de sonido en formato RAW
	NF_LoadRawSound("sfx/Save_Circus", 0, 8000, 0);
	NF_LoadRawSound("sfx/Main_Circus", 1, 8000, 0);

	// Crea los fondos de la pantalla superior
	NF_CreateTiledBg(0, 3, "moon");
	// Crea los fondos de la pantalla inferior
	NF_CreateTiledBg(1, 3, "moon");

	// Crea una capa de texto
	NF_CreateTextLayer(0, 0, 0,	"normal");

	// Exp text
	//NF_WriteText(0, 0, 1, 1, "L or R play voice.");
	NF_WriteText(0, 0, 1, 2, "A or B STOP/PLAY music.");
	

	// Actualiza las capas de texto
	NF_UpdateTextLayers();

	// Variables
	u16 newpress = 0;
	u8 main_circus = 0;
	u8 save_circus = 0;

	// Inicia la musica de fondo
	
	
    main_circus = NF_PlayRawSound(0,127,64,true,0);
	save_circus = NF_PlayRawSound(1, 127, 64, true, 0);
	// Bucle (repite para siempre)
	while(1) {

		// Listener for keys
		scanKeys();
		newpress = keysDown();

		// Play the save circus sound
		if (newpress & KEY_A){
			
			soundPause(main_circus);
			soundResume(save_circus);

		} 
		// play the main sound
		if (newpress & KEY_B){
			
			soundPause(save_circus);
			soundResume(main_circus);

		} 
		// Play a SFX like a jump sound
		//if (newpress & KEY_R) NF_PlayRawSound(0, 127, 127, false, 0);
		//if (newpress & KEY_L) NF_PlayRawSound(0, 127, 0, false, 0);

		swiWaitForVBlank();			// Wait vertical Sync
	
	}

	return 0; 

}
