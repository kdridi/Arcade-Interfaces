/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         RenderTarget.hpp
*/

#pragma once

namespace engine
{
	class Sprite;
	class Text;

	class RenderTarget
	{
	public:
		RenderTarget() = default;
		virtual ~RenderTarget() = default;

		RenderTarget(RenderTarget const &) = delete;
		RenderTarget(RenderTarget &&) = default;

		RenderTarget &operator=(RenderTarget const &) = delete;
		RenderTarget &operator=(RenderTarget &&) = default;

		/**
		 * \brief Draw a sprite into the render target.
		 * \param Sprite
		 */
		virtual void drawSprite(Sprite const &sprite) = 0;

		/**
		 * \brief Draw a text into the render target.
		 * \param Text
		 */
		virtual void drawText(Text const &text) = 0;
	};
}
