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
	class Text final : public Transformable, public Drawable
	{
	public:
		Text() = default;
		virtual ~Text() = default;

		Text(Text const &) = delete;
		Text(Text &&) = default;

		Text &operator=(Text const &) = delete;
		Text &operator=(Text &&) = default;

		/**
		 * \brief Draw itself into the given renderer.
		 * \param RenderTarget target
		 */
		void draw(RenderTarget &renderer) const;

		/**
		 * \brief Move the transformable to the given position.
		 * \param Vector2f newPos
		 */
		void moveTo(Vector2f const &newPos);

		/**
		 * \brief Move the transformable by the given offset.
		 * \param Vector2f offset
		 */
		void move(Vector2f const &offset);

		/**
		 * \brief Get the transformable current position.
		 * \return Vector2f
		 */
		Vector2f const &getPosition() const;

		/**
		 * \brief Set the text value.
		 * \param std::string text
		 */
		void setText(std::string const &text);
		
		/**
		 * \brief Set the font path.
		 * \param std::string fontpath
		 */
		void setFont(std::string const &fontpath);
		
		/**
		 * \brief Set the text size.
		 * \param std::size_t size
		 */
		void setSize(std::size_t size);
		
		/**
		 * \brief Set the text color.
		 * \param Color color
		 */
		void setColor(Color const &color);
		
		/**
		 * \brief Get the text value
		 * \return std::string
		 */
		std::string const &getText() const;

		/**
		 * \brief Get the font path.
		 * \return std::string
		 */
		std::string const &getFont() const;

		/**
		 * \brief Get the text size.
		 * \return std::size_t
		 */
		std::size_t getSize() const;

		/**
		 * \brief Get the text color.
		 * \return Color
		 */
		Color const &getColor() const;

	private:
		// Text value
		std::string m_text;

		// Font path
		std::string m_font;

		// Text position
		Vector2f m_position;

		// Font size
		std::size_t m_size;

		// Font color
		Color m_color;
	};
}
