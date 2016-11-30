#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>
struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
	/* SQL_Surface* loadImage
	 * Loads an image into the _spriteSheets map if it does not exist
	 * return the image from the map regardless of whether or not it was just loaded
	 */
	SDL_Surface * loadImage (const std::string & filePath);

	/* void blitSurface
	 * draws a texture to a certain part of the screen
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	/* void flip
	 * Renders everything to the screen
	 */
	void flip();

	/* void clear
	 * Clears the screen
	 */
	void clear();

	/* SDL_Renderer* getRenderer
	 * return renderer
	 */

	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::map<std::string, SDL_Surface*> _charSHeet;
};

#endif
