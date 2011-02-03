//
//  QTHelper.m
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "QTHelper.h"


@implementation QTHelper
+ (void)setBalanceOnMovie: (QTMovie *) qtm toBalance: (Float32) balance
{
	//Balance runs from -1.0 (full left) to 1.0 (full right)
	Movie m = [qtm quickTimeMovie];
	SetMovieAudioBalance(m, balance, 0);	
}


+ (void)setMovieToMaxLoadedAndPlay: (QTMovie *) qtm
{
	Movie theMovie = [qtm quickTimeMovie];
	TimeValue loadedTime = -1;
	
	GetMaxLoadedTimeInMovie(theMovie, &loadedTime);
	TimeScale scale = GetMovieTimeScale(theMovie);
	TimeValue newTime = loadedTime - (2 * scale);
	SetMovieTimeValue(theMovie, newTime);
	[qtm play];
}

+ (void)setupMeteringOnMovie: (QTMovie *) qtm
{
	Movie theMovie = [qtm quickTimeMovie];
	UInt32 numBands = 1;
	SetMovieAudioFrequencyMeteringNumBands(theMovie, kQTAudioMeter_MonoMix, &numBands);
}

+ (Float32)getLevelForMovie: (QTMovie *) qtm
{
	Movie theMovie = [qtm quickTimeMovie];
	QTAudioFrequencyLevels *levels;
	Float32 theLevel;
	
	levels = malloc(offsetof(QTAudioFrequencyLevels, level[1]));
	levels->numChannels = 1;
	levels->numFrequencyBands = 1;
	
	GetMovieAudioFrequencyLevels(theMovie, kQTAudioMeter_MonoMix, levels);
	theLevel = levels->level[0];
	free(levels);
	return theLevel;
}
@end
