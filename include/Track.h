#ifndef TRACK_H
#define TRACK_H

#include <SDL.h>
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
