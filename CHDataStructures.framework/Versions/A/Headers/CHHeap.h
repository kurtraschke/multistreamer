/*
 CHDataStructures.framework -- CHHeap.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>
 Copyright (c) 2002, Phillip Morelock <http://www.phillipmorelock.com>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "Util.h"

@protocol CHHeap <NSObject, NSCoding, NSCopying, NSFastEnumeration>

- (id) init;

- (id) initWithArray:(NSArray*)anArray;

- (id) initWithOrdering:(NSComparisonResult)order;

- (id) initWithOrdering:(NSComparisonResult)order array:(NSArray*)anArray;

#pragma mark Querying Contents

- (NSArray*) allObjectsInSortedOrder;

- (BOOL) containsObject:(id)anObject;

- (NSUInteger) count;

- (id) firstObject;

- (BOOL) isEqualToHeap:(id<CHHeap>)otherHeap;

- (NSEnumerator*) objectEnumerator;

#pragma mark Modifying Contents

- (void) addObject:(id)anObject;

- (void) addObjectsFromArray:(NSArray*)anArray;

- (void) removeAllObjects;

- (void) removeFirstObject;

@end