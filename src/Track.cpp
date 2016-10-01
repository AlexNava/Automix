#include "Track.h"

Track::Track()
{
	buffers[0] = nullptr;
	buffers[1] = nullptr;
}

Track::~Track()
{
	if (buffers[0] != nullptr)
		delete[] buffers[0];
	if (buffers[1] != nullptr)
		delete[] buffers[1];
}
