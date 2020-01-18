/*
main.cpp
This file is part of:
SDL_SurfaceEx
https://www.pawbyte.com/opensource
Copyright (c) 2014-2020 Nathan Hurde, Chase Lee.

Copyright (c) 2014-2020 PawByte LLC.
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-SDL_SurfaceEx <https://www.pawbyte.com/opensource>


*/
#include "SDL_SurfaceEx.h"


//Make to include SDL2 into your compiler/build system for this to work.

int main( int argc, char* args[] )
{
	if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
	{
        return false;
	}

	SDL_Window * gameWindow = SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_SHOWN| SDL_WINDOW_RESIZABLE   );

	if( gameWindow == NULL )
	{
        return -1;
	}

	//Inits the renderer
	SDL_Renderer * sdlRenderer = SDL_CreateRenderer( gameWindow, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE );//  | SDL_RENDERER_PRESENTVSYNC );

	if( sdlRenderer == NULL )
	{
		return -2;
	}

	//Include gameicon.png in your app directory
	SDL_Surface * gameIconSurface = SDL_SurfaceEx::load_surface_image("gameicon.png");
	if( gameIconSurface == NULL )
	{
	    SDL_Quit();
        return 0;
    }

    //Now we commence using the library

    //First we grayscale the icon
    SDL_Surface * gameIconSurfaceGrayScaled = SDL_SurfaceEx::surface_grayscale(gameIconSurface);

    //Next we invert the colors of the original icon
    SDL_Surface * gameIconSurfaceInverted = SDL_SurfaceEx::surface_invert(gameIconSurface);

    //Now since it's SDL2 we make them into a textures.
    SDL_Texture * gameIconGrayTexture = SDL_SurfaceEx::create_texture_from_surface( sdlRenderer, gameIconSurfaceGrayScaled);
    SDL_Texture * gameIconInvertedTexture = SDL_SurfaceEx::create_texture_from_surface( sdlRenderer, gameIconSurfaceInverted);


    //Clears the screen
    SDL_RenderSetViewport( sdlRenderer, NULL );
    SDL_Rect fillRect = {0,0,640, 480};
    SDL_SetRenderDrawColor( sdlRenderer, 0, 0, 0, 255 );
    SDL_RenderFillRect( sdlRenderer, &fillRect );

    //Our rectangle to render the icons on
    SDL_Rect renderRect = {0,0,320, 480};
    SDL_RenderCopy( sdlRenderer, gameIconGrayTexture, NULL, &renderRect );

    //To have em side by side we just add half of the screen( 640px)
    renderRect.x = 320;
    SDL_RenderCopy( sdlRenderer, gameIconInvertedTexture, NULL , &renderRect );

    //We should see two textures,grayscaled on the left and inverted on the right

    //Updates the screen
    SDL_RenderPresent( sdlRenderer );
    SDL_SetRenderTarget( sdlRenderer, NULL );

    //Delay by 5000 ms since this is just a test app
    SDL_Delay( 5000 );

    //Deletes our surfaces
    if(gameIconSurface!=NULL)
    {
        SDL_FreeSurface(gameIconSurface);
        gameIconSurface = NULL;
    }

    if(gameIconSurfaceGrayScaled!=NULL)
    {
        SDL_FreeSurface(gameIconSurfaceGrayScaled);
        gameIconSurfaceGrayScaled = NULL;
    }

    if(gameIconSurfaceInverted!=NULL)
    {
        SDL_FreeSurface(gameIconSurfaceInverted);
        gameIconSurfaceInverted = NULL;
    }

    //Deletes our textures
    if(gameIconGrayTexture!=NULL)
    {
        SDL_DestroyTexture(gameIconGrayTexture);
        gameIconGrayTexture = NULL;
    }

    if(gameIconInvertedTexture!=NULL)
    {
        SDL_DestroyTexture(gameIconInvertedTexture);
        gameIconInvertedTexture = NULL;
    }

    SDL_Quit();
    return 1;

}
