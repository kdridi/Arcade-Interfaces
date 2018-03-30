/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         Text.hpp
*/

#pragma once

#include <string>

#include "Color.hpp"
#include "Drawable.hpp"
#include "RenderTarget.hpp"
#include "Transformable.hpp"
#include "Vector.hpp"

namespace engine
{
	class Text : public virtual Drawable
	{
	public:
		Text() = default;
		~Text() override = default;

		Text(Text const &) = delete;
		Text(Text &&) = default;

		Text &operator=(Text const &) = delete;
		Text &operator=(Text &&) = default;

		/**
		 * \brief Draw itself into the given renderer.
		 * \param RenderTarget target
		 */
		virtual void draw(RenderTarget &renderer) const = 0;

		/**
		 * \brief Move the transformable to the given position.
		 * \param Vector2f newPos
		 */
		virtual void moveTo(Vector2f const &newPos) = 0;

		/**
		 * \brief Move the transformable by the given offset.
		 * \param Vector2f offset
		 */
		virtual void move(Vector2f const &offset) = 0;

		/**
		 * \brief Get the transformable current position.
		 * \return Vector2f
		 */
		virtual Vector2f const &getPosition() const = 0;

		/**
		 * \brief Set the text value.
		 * \param std::string text
		 */
		virtual void setText(std::string const &text) = 0;
		
		/**
		 * \brief Set the font path.
		 * \param std::string fontpath
		 */
		virtual void setFont(std::string const &fontpath) = 0;
		
		/**
		 * \brief Set the text size.
		 * \param std::size_t size
		 */
		virtual void setSize(std::size_t size) = 0;
		
		/**
		 * \brief Set the text color.
		 * \param Color color
		 */
		virtual void setColor(Color const &color) = 0;
		
		/**
		 * \brief Get the text value
		 * \return std::string
		 */
		virtual std::string const &getText() const = 0;

		/**
		 * \brief Get the font path.
		 * \return std::string
		 */
		virtual std::string const &getFont() const = 0;

		/**
		 * \brief Get the text size.
		 * \return std::size_t
		 */
		virtual std::size_t getSize() const = 0;

		/**
		 * \brief Get the text color.
		 * \return Color
		 */
		virtual Color const &getColor() const = 0;
	};
}
