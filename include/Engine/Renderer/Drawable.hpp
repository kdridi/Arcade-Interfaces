/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         Drawable.hpp
*/

#pragma once

namespace engine
{
	class RenderTarget;

	class Drawable
	{
	public:
		Drawable() = default;
		virtual ~Drawable() = default;

		Drawable(Drawable const &) = delete;
		Drawable(Drawable &&) = default;

		Drawable &operator=(Drawable const &) = delete;
		Drawable &operator=(Drawable &&) = default;

		/**
		 * \brief Draw itself into the given renderer.
		 * \param RenderTarget target
		 */
		virtual void draw(RenderTarget &renderer) const = 0;
	};
}
