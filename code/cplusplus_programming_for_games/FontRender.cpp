#include "FontRender.h"

using namespace std;

// The noted version is here + the header file.
FontRender::FontRender(SDL_Renderer* sdlRendererF) // Accessing the class and its attribute
{
	Renderer = sdlRendererF; // a method
}

void FontRender::init()
{
	int init = TTF_Init();
	
	if (init != 0)
	{
		cout << "TTF Error" << SDL_GetError() << endl;
	}

	Font = TTF_OpenFont("Assets/OpenSans-Regular.ttf", 12); // Opens the ttf file from the assets folder and sets the size to 12

	if (Font == NULL)
	{
		cout << "Font not opened" << SDL_GetError() << endl;
	}

}

void FontRender::clean()
{
	TTF_CloseFont(Font); // Frees up the resources to make some space for memory. 
}

void FontRender::render(string text)
{
	SDL_Color colour = SDL_Color();

	colour.r = 120;
	colour.g = 0;
	colour.b = 0;
	colour.a = 225; // Transparency

	// Creates an image that represents the text that is inputed
	SDL_Surface* textImg = TTF_RenderText_Solid(Font, text.c_str(), colour); 

	// Render the image
	SDL_Texture* FontTexture = SDL_CreateTextureFromSurface(Renderer, textImg);

	SDL_RenderCopy(Renderer, FontTexture, NULL, NULL);

	// Destroys the texture that was used then frees up the screen of the image.
	SDL_DestroyTexture(FontTexture);
	SDL_FreeSurface(textImg);
}