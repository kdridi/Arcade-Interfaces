/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         Window.hpp
*/

#pragma once

#include <string>

#include "Engine/Renderer/Drawable.hpp"
#include "Engine/Renderer/RenderTarget.hpp"
#include "Engine/System/Event.hpp"
#include "RenderSettings.hpp"

namespace engine
{
	class Window : public RenderTarget
	{
	public:
		Window() = default;
		virtual ~Window() = default;

		Window(Window const &) = delete;
		Window(Window &&) = default;

		Window &operator=(Window const &) = delete;
		Window &operator=(Window &&) = default;

		/**
		 * \brief Create the window.
		 * \param std::string title       -> Window's title.
		 * \param RenderSettings settings -> Render settings.
		 */
		virtual void create(std::string const &title, RenderSettings const &settings) = 0;

		/**
		 * \brief Close the window and destroy all of its resources
		          (ie. native handles). It can be re-opened by calling
		 *        create() once again. Once closed, the instance remains
		 *        valid, but some functions such as pollEvent() and
		 *        display() will have no effect.
		 */
		virtual void close() = 0;

		/**
		 * \brief Tell whether or not the window is open.
		 * \return bool
		 */
		virtual bool isOpen() const = 0;

		/**
		 * \brief Pop the event on top of the event queue, if any.
		 * \param Event event
		 * \return bool -> false if no event was found, true otherwise.
		 */
		virtual bool pollEvent(Event &event) = 0;

		/**
		 * \brief Clear the window. Must be called before each call to
		 *        display(). A cleared window should be black.
		 */
		virtual void clear() = 0;

		/**
		 * \brief Display into the window what have been rendered.
		 */
		virtual void display() = 0;
	};
}
