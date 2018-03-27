# Game Loop

Here we'll create a classic game loop :
1. We handle all events that happened during the last frame,
2. We update the game (physics, AI, etc.),
3. And then we draw every necessary game object into the window.

### Instantiation

We instantiate both game and render window :

```cpp
std::unique_ptr<arcade::Game> game{ /* Game */ };
std::unique_ptr<engine::Window> window{ /* Window */ };
```

### Window creation

Then we create a window with a render resolution of 640x480px :

```cpp
window->create("Arcade", engine::Vector2i{ 640, 480 }, engine::RenderSettings{ 640, 480, false });
```

### Main loop

And there's the main loop :

```cpp
while (window->isOpen()) {
	engine::Event evt;
	while (window->pollEvent(evt)) {
		// We delegate event handling to our Game class:
		game->handleEvent(evt);
	}

	if (game->isRunning()) {
		game->update();
		window->clear();
		game->render(window);
		window->display();
	}
	else {
		// If the game has terminated, we close the window:
		window->close();
	}
}
```

It's a very basic game loop. You'll have to make some changes, especially to handle render engines switches.

# Drawing

In the game loop above, you surely have noticed the line `game->render(window);`. Here, we pass as a reference the window to the game. It makes the game able to draw its components into the window.

### Implementing the `Game::draw()` function

There's basically nothing much to do. We call the `Window::draw()` function with the object we want to render as a parameter :

```cpp
class Pacman : public Game
{
public:
	void draw(std::unique_ptr<engine::Window> &window) const override
	{
		window->draw(m_text);
		window->draw(m_sprite);
		// ...
	}

private:
	engine::Text m_text;
	engine::Sprite m_sprite;
	// ...
};
```

# Rendering

Now, things are going to get a little bit more harder. We need to make the `Window::draw()` function able to render any `Drawable` object.

### The render target

The render target is basically the engine you will use to render objects to the screen (SFML, nCurses, OpenGL, etc.) :

```cpp
class RenderTarget
{
public:
	virtual void drawSprite(Sprite const &sprite) = 0;
	// ...
};

class SFMLRenderer : public RenderTarget
{
public:
	void drawSprite(Sprite const &sprite) override {}
	// ...
};
```

At this time, we're able to draw `Sprite`s into the window, using SFML. You'll have to implement at least one function for each `Drawable` object you want to render.

Be careful to **NOT** recreate the native handle (here, the couple sf::Spirte and sf::Texture) each time you call `drawSprite()` ! Think of a way to avoid this, or your game will run at 5 FPS.

### The render window

Now that we have implemented the render target, we need to implement the render window, which will call `Drawable::draw()` function to do the rendering.

A `Drawable` class **must** implement a `draw()` function which take as a parameter a `RenderTarget`. It will allow to call the right `RenderTarget` member function. For instance, `Sprite::draw()` will call `RenderTarget::drawSprite()`.

Here's a basic implementation of the `Window::draw()` function :

```cpp
class RenderWindow : public Window
{
public:
	void draw(Drawable const &drawable)
	{
		drawable.draw(m_renderer);
	}

private:
	SFMLRenderer m_renderer;
};
```

### Implementing a `Drawable` class

We're talking about `Drawable` classes since earlier, but let's see how to implement their `draw()` member function :

```cpp
class Sprite : public Transformable, public Drawable
{
public:
	void draw(RenderTarget &renderer) const override
	{
		renderer.drawSprite(*this);
	}
};
```

Nothing more, nothing less. Our `Drawable` object passes itself as a parameter to the right `RenderTarget`'s member function. This function is therefore capable to draw a sprite using SFML's native handles (sf::Sprite and sf::Texture) by retrieving all the information it needs from our `Sprite` class.

# Highscores

Now that we have both our game and renderer functional, it would be nice if we could load and save highscores for each game we have.

Back in our game loop, we can have something like that :

```cpp
// Load your highscores
Game::Scores scores{ /* ... */ };

game->loadHighscores(scores);

while (window->isOpen()) {
	// ...
}

scores = game->highscores();
// Then save them
```

Here, `Game::Scores` is a `std::multimap<std::uint64_t, std::string>`.

# Events

In order to comply with all render engines, it's recommended to make your games fully playable (including menus) with the keyboard. Indeed, some render engines may not implement joystick or mouse handling.
