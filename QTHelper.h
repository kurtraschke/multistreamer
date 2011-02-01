//
//  QTHelper.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/31/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QTKit/QTKit.h>
#import <QuickTime/QuickTime.h>
#import <AudioToolbox/AudioToolbox.h>


@interface QTHelper : NSObject {

}

+ (void)setBalanceOnMovie: (QTMovie *) qtm toBalance: (Float32) balance;
+ (void)setMovieToMaxLoadedAndPlay: (QTMovie *) qtm;
+ (void)setupMeteringOnMovie: (QTMovie *) qtm;
+ (Float32)getLevelForMovie: (QTMovie *) qtm;

@end
