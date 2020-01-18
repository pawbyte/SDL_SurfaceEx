# SDL_SurfaceEx
A small SDL based library for modifying surfaces and creating image effects.

Simply incldue this in your project and make calls via the SDL_SurfaceEx namespace.

Code Examples:

```cpp

#include "SDL_SurfaceEx.h"

//Include gameicon.png in your app directory
SDL_Surface * gameIconSurface = SDL_SurfaceEx::load_surface_image("gameicon.png");
if( gameIconSurface !=NULL )
{
  
  SDL_Surface * gameIconSurfaceGrayScaled = SDL_SurfaceEx::surface_grayscale(gameIconSurface);
  SDL_Surface * gameIconSurfaceInverted = SDL_SurfaceEx::surface_invert(gameIconSurface);
  
  SDL_FreeSurface(gameIconSurface);
  SDL_FreeSurface(gameIconSurfaceGrayScaled);
  SDL_FreeSurface(gameIconSurfaceInverted);
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
Come and  [join our discord server](https://discord.gg/aNX3Fcx)!  Here, you can engage in chats about game pencil, get help and even voice chat the developers and users!

Forums
======
Become a member on our [forum](http://community.pawbyte.com/)!  Here, you can find help and talk directly with the developers of this project!

Developers
----------
[theweirdn8](https://github.com/theweirdn8)
![](https://avatars0.githubusercontent.com/u/3193947?v=4&s=100)
