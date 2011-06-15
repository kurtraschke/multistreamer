/*
 CHDataStructures.framework -- CHSortedSet.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>
 Copyright (c) 2002, Phillip Morelock <http://www.phillipmorelock.com>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "Util.h"

typedef enum {

	CHSubsetExcludeLowEndpoint  = 1 << 0,

	CHSubsetExcludeHighEndpoint = 1 << 1
} CHSubsetConstructionOptions;

@protocol CHSortedSet <NSObject, NSCoding, NSCopying, NSFastEnumeration>

- (id) init;

- (id) initWithArray:(NSArray*)anArray;

#pragma mark Querying Contents

- (NSArray*) allObjects;

- (id) anyObject;

- (NSUInteger) count;

- (BOOL) containsObject:(id)anObject;

- (id) firstObject;

- (BOOL) isEqualToSortedSet:(id<CHSortedSet>)otherSortedSet;

- (id) lastObject;

- (id) member:(id)anObject;

- (NSEnumerator*) objectEnumerator;

- (NSEnumerator*) reverseObjectEnumerator;

- (NSSet*) set;

- (id<CHSortedSet>) subsetFromObject:(id)start
							toObject:(id)end
							 options:(CHSubsetConstructionOptions)options;

#pragma mark Modifying Contents

- (void) addObject:(id)anObject;

- (void) addObjectsFromArray:(NSArray*)anArray;

- (void) removeAllObjects;

- (void) removeFirstObject;

- (void) removeLastObject;

- (void) removeObject:(id)anObject;

@end