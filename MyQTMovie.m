//
//  MyQTMovie.m
//  MultiStreamer
//
//  Created by Kurt Raschke on 2/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MyQTMovie.h"


@implementation MyQTMovie
- (void)setBalance: (Float32) balance
{
	//Balance runs from -1.0 (full left) to 1.0 (full right)
	Movie m = [self quickTimeMovie];
	SetMovieAudioBalance(m, balance, 0);	
}


- (void)setMovieToMaxLoadedAndPlay
{
	Movie theMovie = [self quickTimeMovie];
	TimeValue loadedTime = -1;
	
	GetMaxLoadedTimeInMovie(theMovie, &loadedTime);
	TimeScale scale = GetMovieTimeScale(theMovie);
	TimeValue newTime = loadedTime - (2 * scale);
	SetMovieTimeValue(theMovie, newTime);
	[self play];
}

- (void)setupAudioMetering
{
	Movie theMovie = [self quickTimeMovie];
	UInt32 numBands = 1;
	SetMovieAudioFrequencyMeteringNumBands(theMovie, kQTAudioMeter_MonoMix, &numBands);
}

- (Float32)getAudioLevel
{
	Movie theMovie = [self quickTimeMovie];
	QTAudioFrequencyLevels *levels;
	Float32 theLevel;
	const int numChannels = 1;
	const int numBands = 1;
	
	levels = malloc(offsetof(QTAudioFrequencyLevels, level[numChannels * numBands]));
	levels->numChannels = numChannels;
	levels->numFrequencyBands = numBands;
	
	GetMovieAudioFrequencyLevels(theMovie, kQTAudioMeter_MonoMix, levels);
	theLevel = levels->level[0];
	free(levels);
	return theLevel;
}

@end
