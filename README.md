# SDL_SurfaceEx
A small SDL based library for modifying surfaces and creating image effects.

Simply include this in your project and make calls via the SDL_SurfaceEx namespace.

Code Example ( main.cpp):

```cpp


#include "sdl_surfaceex.h"


//Make sure to include SDL2 into your compiler/build system for this to work.

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
	SDL_Surface * gameIconSurface = sdl_surface_ex::load_surface_image("gameicon.png");
	if( gameIconSurface == NULL )
	{
	    SDL_Quit();
        return 0;
    }

    //Now we commence using the library

    //First we grayscale the icon
    SDL_Surface * gameIconSurfaceGrayScaled = sdl_surface_ex::surface_grayscale(gameIconSurface);

    //Next we invert the colors of the original icon
    SDL_Surface * gameIconSurfaceInverted = sdl_surface_ex::surface_invert(gameIconSurface);

    //Now since it's SDL2 we make them into a textures.
    SDL_Texture * gameIconGrayTexture = sdl_surface_ex::create_texture_from_surface( sdlRenderer, gameIconSurfaceGrayScaled);
    SDL_Texture * gameIconInvertedTexture = sdl_surface_ex::create_texture_from_surface( sdlRenderer, gameIconSurfaceInverted);


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

```

Donate to make SDL_SurfaceEx greater
=========================================
Work on open source projects like this is not possible without funding. The amount of time it takes to update the codebases, create examples, tutorials and more is quite expensive. Please consider either a one-time or monthly donation to keep this engine going and more frequently updated. 

We have a [Patron Page](https://www.patreon.com/pawbyte?ty=h) that you can help fund future open source projects and the updates to this one.

There is also a [PayPal](http://gamepencil.pawbyte.com/donate/) one time donation method as well. 

I appreciate your generousity and moving this project forward. 



Discord Chat
======
Come and  [join our discord server](https://discord.gg/aNX3Fcx)!  Bounce ideas off each other, hangout and discord open source,gaming, etc.

Forums
======
Become a member on our [forum](http://community.pawbyte.com/)!  Here, you can find help and talk directly with the developers of this project!

Developers
----------
[theweirdn8](https://github.com/theweirdn8)
![](https://avatars0.githubusercontent.com/u/3193947?v=4&s=100)
