#ifndef TRACK_H
#define TRACK_H

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif // WIN32
#include "CommonDefs.h"
#include <string>

class Track
{
	public:
		Track();
		virtual ~Track();

		bool load(std::string filename);
		bool decode();

	protected:
		uint16_t *buffers[2];
};

#endif // TRACK_H
