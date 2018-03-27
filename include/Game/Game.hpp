/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         Game.hpp
*/

#pragma once

#include <map>
#include <memory>
#include <string>

#include "Engine/System/Event.hpp"
#include "Engine/Window/Window.hpp"

namespace arcade
{
	class Game
	{
	public:
		using Scores = std::multimap<std::uint64_t, std::string>;

		Game() = default;
		virtual ~Game() = default;

		Game(Game const &) = delete;
		Game(Game &&) = default;

		Game &operator=(Game const &) = delete;
		Game &operator=(Game &&) = default;

		/**
		 * \brief Load the highscores into the game. If this function
		 *        has already been called, current highscores must be
		 *        erased.
		 * \param Scores scores
		 */
		virtual void loadHighscores(Scores const &scores) = 0;

		/**
		 * \brief Get the current highscores.
		 * \return Scores
		 */
		virtual Scores const &highscores() const = 0;

		/**
		 * \brief Handle event.
		 * \param Event event
		 */
		virtual void handleEvent(engine::Event const &event) = 0;

		/**
		 * \brief Update the game. This function should have no effect
		 *        when the game is paused.
		 */
		virtual void update() = 0;

		/**
		 * \brief Pause the game.
		 */
		virtual void pause() = 0;

		/**
		 * \brief Resume the game.
		 */
		virtual void resume() = 0;

		/**
		 * \brief Quit the game. The game is not required to quit
		 *        instantly (eg. display a confirmation menu).
		 */
		virtual void quit() = 0;

		/**
		* \brief Restart the game. The game is not required to restart
		*        instantly (eg. display a confirmation menu).
		*/
		virtual void restart() = 0;

		/**
		 * \brief Tell whether or not the game is paused.
		 * \return bool
		 */
		virtual bool isPaused() const = 0;

		/**
		 * \brief Tell whether or not the game is running. If not, the
		 *        window should close itself.
		 * \return bool
		 */
		virtual bool isRunning() const = 0;

		/**
		 * \brief Draw each game object into the render window.
		 * \param std::unique_ptr<Window> window
		 */
		virtual void render(std::unique_ptr<engine::Window> &window) const = 0;
	};
}
