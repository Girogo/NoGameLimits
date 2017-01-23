#include "Mapa.h"
#include "Tile.h"
//#include <fstream>



CMapa::CMapa(char* mapSrc)
{
	this->rutaMapa = mapSrc;
	//this->rutaMapa += mapSrc;
}

bool CMapa::setTiles(CTile CtileSet[])
{

	//Success flag
	bool tilesLoaded = true;

	//Lector archivo JSON
	std::ifstream ifs("ids.json");//Ruta archivo JSON con ids
	json j = json::parse(ifs);
	
	//Tiles del mapa
	int TOTAL_TILES = 168, TILE_WIDTH = 32, TILE_HEIGTH = 32, TOTAL_TILESWIDTH = 14, TOTAL_TILESHEIGHT = 12;

	int x = 0, y = 0;

	int pixelX, pixelY;

	int width = 0;
	int height = 0;

	//Abre el archivo del mapa
	std::ifstream map(rutaMapa);

	//Si el mapa no se puede cargar lo informa
	if (!map.is_open())
	{
		printf("No se ha podido cargar el mapa\n");
		tilesLoaded = false;
	}

	else
	{
		//Inicializa las Tiles
		for (int i = 0; i < TOTAL_TILES; ++i)
		{
			//Variable para determinar el tipo de Tile (ID)
			int tileType = -1;

			//Lee el archivo mapa y pasa la lectura a la variable tileType
			map >> tileType;

			//En caso de error...
			if (map.fail())
			{
				//Deja de cargar el mapa
				printf("Error loading map: Unexpected end of file!\n");
				tilesLoaded = false;
				break;
			}

			//Si el numero que lee (ID) es valido... | 2 = TOTAL DE TILES EN EL SPRITESHEET (IDS)
			if ((tileType >= 0) && (tileType < 2))
			{
				//Lee el archivo Json y recupera los datos de la Tile

				std::string id; //String para convertir tileType de int a string.

				std::stringstream convert; // stringstream para la conversion.

				convert << tileType;//a�ade el valor de tileType al stream de convert.

				id = convert.str();//introduce el valor en id.

				// (id) = lectura recibida por el mapa.
				pixelX = j.at(id).at("x");
				pixelY = j.at(id).at("y");
				width = j.at(id).at("width");
				height = j.at(id).at("height");
				std::string tipo = j.at(id).at("tipo");

				CtileSet[i] = *(new CTile(tileType, x, y, pixelX, pixelY, width, height, tipo)); // id, posicion en mapa, posicion en sprite, width, height, tipo
			}
			//Si no se reconoce la id
			else
			{
				//Deja de cargar el mapa y lo informa
				printf("Error loading map: Invalid tile type at %d!\n", i);
				tilesLoaded = false;
				break;
			}
			//Aumenta el valor de X con el tama�o de la Tile para as� poder ubicar la siguiente Tile en el sitio correcto
			x += TILE_WIDTH;

			//Si la X ha ido mas lejos del tama�o del mapa | 800 = LEVEL WIDTH
			if (x >= (TILE_WIDTH * TOTAL_TILESWIDTH))
			{
				//Mueve X y Y a la siguiente linea de tiles:
				x = 0;
				y += TILE_HEIGTH;
			}
		}

		// FALTA LA PARTE DE LOS gTileClips


	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return tilesLoaded;
}

void CMapa::renderMap(CTile tiles[], SDL_Renderer* m_WindowRenderer)
{
	SDL_Texture* textura = Sprite::Load("sprites/atlas.bmp", m_WindowRenderer);


	for (int i = 0; i < 168; i++)
	{

		SDL_Rect rectOrigen = tiles[i].getRectOrigen();
		SDL_Rect rectDestino = tiles[i].getRectDestino();

		Sprite::Draw(m_WindowRenderer, textura, rectOrigen, rectDestino);

	}
	SDL_RenderPresent(m_WindowRenderer);


}