#include <iostream>
#include <SDL.h>
#include "Track.h"

using namespace std;

void MyAudioCallback(void *userdata, Uint8 *stream, int len)
{
	cout << "callback" << endl;
}


int main(int argc, char *argv[])
{
	cout << "Automix starting" << endl;
	int ret = SDL_Init(SDL_INIT_AUDIO);

	if (ret < 0)
	{
		cout << "SDL error:" << SDL_GetError() <<  endl;
	}

	Track *tracks[2];

	SDL_Init(SDL_INIT_AUDIO);
	int nDevices = SDL_GetNumAudioDevices(0);
	cout << "Detected " << nDevices << " playback audio devices" << endl;

	for (int iDev = 0; iDev < nDevices; ++iDev)
	{
		cout << "Device " << iDev << " name: " << SDL_GetAudioDeviceName(iDev, 0) << endl;
	}

	SDL_AudioSpec want, have;

	SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
	want.freq = 48000;
	want.format = AUDIO_F32;
	want.channels = 2;
	want.samples = 4096;
	want.callback = MyAudioCallback;  // you wrote this function elsewhere.

	if (SDL_OpenAudio(&want, &have) < 0) {
		cout << "Failed to open audio:  " << SDL_GetError();
	}
	else {
		if (have.format != want.format)
			cout << "We didn't get Float32 audio format." << endl;

		cout << "Obtained:" << endl;
		cout << (int)have.channels << " channels" << endl;
		cout << have.freq << " samples/s" << endl;
		cout << have.samples << " buffer samples" << endl;
		cout << have.format << " format" << endl;
		SDL_PauseAudio(0);  // start audio playing.
		SDL_Delay(500);  // let the audio callback play some sound for 5 seconds.
		SDL_CloseAudio();
	}

	SDL_Quit();
	return 0;
}
