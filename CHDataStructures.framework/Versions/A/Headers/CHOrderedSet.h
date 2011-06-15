/*
 CHDataStructures.framework -- CHOrderedSet.h

 Copyright (c) 2009-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "CHMutableSet.h"

@interface CHOrderedSet : CHMutableSet {
	id ordering;
}

#pragma mark Querying Contents

- (NSArray*) allObjects;

- (id) firstObject;

- (NSUInteger) indexOfObject:(id)anObject;

- (BOOL) isEqualToOrderedSet:(CHOrderedSet*)otherOrderedSet;

- (id) lastObject;

- (id) objectAtIndex:(NSUInteger)index;

- (NSEnumerator*) objectEnumerator;

- (NSArray*) objectsAtIndexes:(NSIndexSet*)indexes;

- (CHOrderedSet*) orderedSetWithObjectsAtIndexes:(NSIndexSet*)indexes;

#pragma mark Modifying Contents

- (void) insertObject:(id)anObject atIndex:(NSUInteger)index;

- (void) exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;

- (void) removeFirstObject;

- (void) removeLastObject;

- (void) removeObjectAtIndex:(NSUInteger)index;

- (void) removeObjectsAtIndexes:(NSIndexSet*)indexes;

@end