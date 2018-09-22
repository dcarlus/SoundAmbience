# Sound Ambience
Sound Ambience is a software that generates a sound atmosphere all around you. You put the sound files you want into the software and that's it!

![Sound Ambience v0.1a](https://raw.githubusercontent.com/dcarlus/SoundAmbience/master/resources/screenshots/SoundAmbiance_0.1a.png)

## How does it work?
You select a sound that will be the base of your ambience. This sound is ideally long enough because it will loop other again and again until you stop the ambiance generation.
Then you select a list of small sounds that are randomly played in a 3D space, around you. You can get it if you have a 5.1 or 7.1 sound system for example, but Sound Ambience will work with headphones and stereo speakers as well.

Notice that the additional sounds should be in mono format. Otherwise, you could not experiment surrounding sounds! :wink:

## How to build it?
For now, Sound Ambience can only be compiled on Windows systems. In the future, it should be available on Linux systems.

Requirements:
- Qt5.10
- OpenAL 1.1
- libsndfile
