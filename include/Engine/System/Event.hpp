/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         Event.hpp
*/

#pragma once

#include <cstddef>
#include <cstdint>

#include "Keyboard.hpp"
#include "Joystick.hpp"
#include "Mouse.hpp"

namespace engine
{
	enum class EventType
	{
		// Invalid event
		None,

		// The OS requested the program to close
		Closed,

		// The window was resized
		Resized,

		// The window lost focus
		// Can be used to pause the game
		LostFocus,

		// The window gained focus
		GainedFocus,

		// A printable key combinaison was pressed
		TextEntered,

		// A key was pressed or released
		KeyPressed,
		KeyReleased,

		// The mouse moved across the window
		MouseMoved,

		// The mouse wheel was scrolled
		MouseWheelScrolled,

		// A mouse button was pressed or released
		MouseButtonPressed,
		MouseButtonReleased,

		// A joystick button was pressed or released
		JoystickButtonPressed,
		JoystickButtonReleased,

		// One of the joystick's axes moved
		JoystickMoved
	};

	struct KeyEvent final
	{
		KeyCode code;

		// Are those keys also pressed?
		bool alt;
		bool control;
		bool shift;
		bool system;
	};

	struct MouseMoveEvent final
	{
		// Position of the mouse pointer, relative to the window
		// The top-left corner of the window is the point (0, 0)
		std::int32_t x;
		std::int32_t y;
	};

	struct MouseButtonEvent final
	{
		MouseButton button;

		// Position of the mouse pointer, relative to the window
		std::int32_t x;
		std::int32_t y;
	};


	struct MouseWheelEvent final
	{
		// Number of ticks the wheel has moved
		// Positive is up, negative is down
		float delta;

		// Position of the mouse pointer, relative to the window
		std::int32_t x;
		std::int32_t y;
	};

	struct JoystickMoveEvent final
	{
		JoystickAxis axis;

		// Interval [-1.0, 1.0]
		float position;
	};

	struct JoystickButtonEvent final
	{
		// Joystick button ID
		unsigned button;
	};

	struct ResizeEvent final
	{
		// New window size
		std::size_t width;
		std::size_t height;
	};

	struct TextEvent final
	{
		// UTF-8 value of the character
		std::uint32_t unicode;
	};

	struct Event final
	{
		EventType type{ EventType::None };

		union {
			// Joystick
			JoystickButtonEvent joystickButton;
			JoystickMoveEvent joystickMove;

			// Mouse
			MouseButtonEvent mouseButton;
			MouseMoveEvent mouseMove;
			MouseWheelEvent mouseWheel;

			// Keyboard
			KeyEvent key;
			TextEvent text;

			// Window
			ResizeEvent resize;
		};
	};
}
