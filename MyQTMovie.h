//
//  MyQTMovie.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 2/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QTKit/QTKit.h>
#import <QuickTime/QuickTime.h>
#import <AudioToolbox/AudioToolbox.h>

@interface MyQTMovie : QTMovie {

}
- (void)setBalance: (Float32) balance;
- (void)setMovieToMaxLoadedAndPlay;
- (void)setupAudioMetering;
- (Float32)getAudioLevel;
@end
