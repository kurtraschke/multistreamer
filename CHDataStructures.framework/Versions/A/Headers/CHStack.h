/*
 CHDataStructures.framework -- CHStack.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>
 Copyright (c) 2002, Phillip Morelock <http://www.phillipmorelock.com>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "Util.h"

@protocol CHStack <NSObject, NSCoding, NSCopying, NSFastEnumeration>

- (id) init;

- (id) initWithArray:(NSArray*)anArray;

#pragma mark Querying Contents

- (NSArray*) allObjects;

- (BOOL) containsObject:(id)anObject;

- (BOOL) containsObjectIdenticalTo:(id)anObject;

- (NSUInteger) count;

- (NSUInteger) indexOfObject:(id)anObject;

- (NSUInteger) indexOfObjectIdenticalTo:(id)anObject;

- (BOOL) isEqualToStack:(id<CHStack>)otherStack;

- (id) objectAtIndex:(NSUInteger)index;

- (NSEnumerator*) objectEnumerator;

- (NSArray*) objectsAtIndexes:(NSIndexSet*)indexes;

- (id) topObject;

#pragma mark Modifying Contents

- (void) exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;

- (void) popObject;

- (void) pushObject:(id)anObject;

- (void) removeAllObjects;

- (void) removeObject:(id)anObject;

- (void) removeObjectAtIndex:(NSUInteger)index;

- (void) removeObjectIdenticalTo:(id)anObject;

- (void) removeObjectsAtIndexes:(NSIndexSet*)indexes;

- (void) replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

@end