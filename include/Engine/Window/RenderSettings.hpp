/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
**         RenderSettings.hpp
*/

#pragma once

#include <cstddef>
#include "Engine/Renderer/Vector.hpp"

namespace engine
{
	struct RenderSettings final
	{
		// Render resolution
		Vector2u size;

		// Enable fullscreen
		bool fullscreen;
	};
}
