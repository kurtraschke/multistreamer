//
//  MyQTMovie.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 2/5/11.
//  Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.
//

#import <Cocoa/Cocoa.h>
#import <QTKit/QTKit.h>
#import <QuickTime/QuickTime.h>
#import <AudioToolbox/AudioToolbox.h>
#import <CHDataStructures/CHDataStructures.h>

@interface MyQTMovie : QTMovie {
	int averageDepth;
	id volumeLevels;
}
- (id)initWithURL:(NSURL *)url error:(NSError **)errorPtr;
- (void)setBalance: (Float32) balance;
- (void)setMovieToMaxLoadedAndPlay;
- (void)setupAudioMetering;
- (Float32)getAudioLevel;
- (Float32)getAudioAverage;
@end
