#include <SDL.h>
#include <stdio.h>
#include "Music.h"
#include "BinaryBlob.h"
#include "Map.h"

void musicclass::init()
{
	soundTracks.push_back(move(SoundTrack( "sounds/jump.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/jump2.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/hurt.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/souleyeminijingle.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/coin.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/save.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crumble.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/vanish.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/blip.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/preteleport.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/teleport.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew1.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew2.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew3.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew4.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew5.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crew6.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/terminal.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/gamesaved.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crashing.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/blip2.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/countdown.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/go.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/crash.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/combine.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/newrecord.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/trophy.wav" )));
	soundTracks.push_back(move(SoundTrack( "sounds/rescue.wav" )));

#ifdef VVV_COMPILEMUSIC
	binaryBlob musicWriteBlob;
	musicWriteBlob.AddFileToBinaryBlob("data/music/0levelcomplete.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/1pushingonwards.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/2positiveforce.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/3potentialforanything.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/4passionforexploring.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/5intermission.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/6presentingvvvvvv.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/7gamecomplete.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/8predestinedfate.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/9positiveforcereversed.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/10popularpotpourri.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/11pipedream.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/12pressurecooker.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/13pacedenergy.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/14piercingthesky.ogg");
	musicWriteBlob.AddFileToBinaryBlob("data/music/predestinedfatefinallevel.ogg");

	musicWriteBlob.writeBinaryBlob("data/BinaryMusic.vvv");
#endif

	binaryBlob musicReadBlob;
	if (!musicReadBlob.unPackBinary("mmmmmm.vvv"))
	{
		mmmmmm = false;
		usingmmmmmm=false;
		bool ohCrap = musicReadBlob.unPackBinary("vvvvvvmusic.vvv");
		SDL_assert(ohCrap && "Music not found!");
	}
	else
	{
		mmmmmm = true;
		usingmmmmmm = true;
		int index = musicReadBlob.getIndex("data/music/0levelcomplete.ogg");
		SDL_RWops *rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/1pushingonwards.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/2positiveforce.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/3potentialforanything.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/4passionforexploring.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/5intermission.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/6presentingvvvvvv.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/7gamecomplete.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/8predestinedfate.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/9positiveforcereversed.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/10popularpotpourri.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/11pipedream.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/12pressurecooker.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/13pacedenergy.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/14piercingthesky.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		index = musicReadBlob.getIndex("data/music/predestinedfatefinallevel.ogg");
		rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
		musicTracks.push_back(move(MusicTrack( rw )));

		bool ohCrap = musicReadBlob.unPackBinary("vvvvvvmusic.vvv");
		SDL_assert(ohCrap && "Music not found!");
	}

	int index = musicReadBlob.getIndex("data/music/0levelcomplete.ogg");
	SDL_RWops *rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/1pushingonwards.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/2positiveforce.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/3potentialforanything.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/4passionforexploring.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/5intermission.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/6presentingvvvvvv.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/7gamecomplete.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/8predestinedfate.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/9positiveforcereversed.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/10popularpotpourri.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/11pipedream.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/12pressurecooker.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/13pacedenergy.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/14piercingthesky.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	index = musicReadBlob.getIndex("data/music/predestinedfatefinallevel.ogg");
	rw = SDL_RWFromMem(musicReadBlob.getAddress(index), musicReadBlob.getSize(index));
	musicTracks.push_back(move(MusicTrack( rw )));

	safeToProcessMusic= false;
	m_doFadeInVol = false;
	musicVolume = 128;
	FadeVolAmountPerFrame = 0;

	custompd = false;

	currentsong = 0;
	musicfade = 0;
	musicfadein = 0;
	nicechange = 0;
	nicefade = 0;
	resumesong = 0;
	volume = 0.0f;
	fadeoutqueuesong = -1;
	dontquickfade = false;
}

void musicclass::play(int t)
{
	t = (t % 16);

	if(mmmmmm)
	{
		if(!usingmmmmmm)
		{
			t += 16;
		}
	}
	safeToProcessMusic = true;
	Mix_VolumeMusic(128);
	if (currentsong !=t)
	{
		if (t != -1)
		{
			currentsong = t;
			if (currentsong == 0 || currentsong == 7 || (!map.custommode && (currentsong == 16 || currentsong == 23)))
			{
				// Level Complete theme, no fade in or repeat
				if(Mix_FadeInMusic(musicTracks[t].m_music, 0, 0)==-1)
				{
					printf("Mix_PlayMusic: %s\n", Mix_GetError());
				}
			}
			else
			{
				if (Mix_FadingMusic() == MIX_FADING_OUT) {
					// We're already fading out
					fadeoutqueuesong = t;
					currentsong = -1;
					if (!dontquickfade)
						Mix_FadeOutMusic(500); // fade out quicker
					else
						dontquickfade = false;
				}
				else if(Mix_FadeInMusic(musicTracks[t].m_music, -1, 3000)==-1)
				{
					printf("Mix_FadeInMusic: %s\n", Mix_GetError());
				}
			}
		}
		else
		{
			currentsong = -1;
		}
	}
}

void musicclass::haltdasmusik()
{
	Mix_HaltMusic();
	currentsong = -1;
}

void musicclass::silencedasmusik()
{
	Mix_VolumeMusic(0) ;
	musicVolume = 0;
}

void musicclass::fadeMusicVolumeIn(int ms)
{
	m_doFadeInVol = true;
	FadeVolAmountPerFrame =  MIX_MAX_VOLUME / (ms / 33);
}

void musicclass::fadeout()
{
	Mix_FadeOutMusic(2000);
	currentsong = -1;
}

void musicclass::processmusicfadein()
{
	musicVolume += FadeVolAmountPerFrame;
	Mix_VolumeMusic(musicVolume);
	if (musicVolume >= MIX_MAX_VOLUME)
	{
		m_doFadeInVol = false;
	}
}

void musicclass::processmusic()
{
	if(!safeToProcessMusic)
	{
		return;
	}

	if (fadeoutqueuesong != -1 && Mix_PlayingMusic() == 0) {
		play(fadeoutqueuesong);
		fadeoutqueuesong = -1;
	}

	if (nicefade == 1 && Mix_PlayingMusic() == 0)
	{
		play(nicechange);
		nicechange = -1; nicefade = 0;
	}

	if(m_doFadeInVol)
	{
		processmusicfadein();
	}
}


void musicclass::niceplay(int t)
{
	// important: do nothing if the correct song is playing!
	if((!mmmmmm && currentsong!=t) || (mmmmmm && usingmmmmmm && currentsong!=t) || (mmmmmm && !usingmmmmmm && currentsong!=t+16))
	{
		if(currentsong!=-1)
		{
			dontquickfade = true;
			fadeout();
		}
		nicefade = 1;
		nicechange = t;
	}
}

void musicclass::changemusicarea(int x, int y)
{
	switch(musicroom(x, y))
	{
	case musicroom(11, 4):
		niceplay(2);
		break;

	case musicroom(2, 4):
	case musicroom(7, 15):
		niceplay(3);
		break;

	case musicroom(18, 1):
	case musicroom(15, 0):
		niceplay(12);
		break;

	case musicroom(0, 0):
	case musicroom(0, 16):
	case musicroom(2, 11):
	case musicroom(7, 9):
	case musicroom(8, 11):
	case musicroom(13, 2):
	case musicroom(17, 12):
	case musicroom(14, 19):
	case musicroom(17, 17):
		niceplay(4);
		break;

	default:
		niceplay(1);
		break;
	}
}

void musicclass::playef(int t)
{
	int channel;

	channel = Mix_PlayChannel(-1, soundTracks[t].sound, 0);
	if(channel == -1)
	{
		fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
	}
}
