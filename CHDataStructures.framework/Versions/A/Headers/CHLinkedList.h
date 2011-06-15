/*
 CHDataStructures.framework -- CHLinkedList.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "Util.h"

@protocol CHLinkedList <NSObject, NSCoding, NSCopying, NSFastEnumeration>

- (id) init;

- (id) initWithArray:(NSArray*)anArray;

#pragma mark Querying Contents

- (NSArray*) allObjects;

- (BOOL) containsObject:(id)anObject;

- (BOOL) containsObjectIdenticalTo:(id)anObject;

- (NSUInteger) count;

- (id) firstObject;

- (id) lastObject;

- (NSUInteger) indexOfObject:(id)anObject;

- (NSUInteger) indexOfObjectIdenticalTo:(id)anObject;

- (BOOL) isEqualToLinkedList:(id<CHLinkedList>)otherLinkedList;

- (id) objectAtIndex:(NSUInteger)index;

- (NSEnumerator*) objectEnumerator;

- (NSArray*) objectsAtIndexes:(NSIndexSet*)indexes;

#pragma mark Modifying Contents

- (void) addObject:(id)anObject;

- (void) addObjectsFromArray:(NSArray*)anArray;

- (void) exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;

- (void) insertObject:(id)anObject atIndex:(NSUInteger)index;

- (void) insertObjects:(NSArray *)objects atIndexes:(NSIndexSet *)indexes;

- (void) prependObject:(id)anObject;

- (void) removeFirstObject;

- (void) removeLastObject;

- (void) removeObject:(id)anObject;

- (void) removeObjectAtIndex:(NSUInteger)index;

- (void) removeObjectIdenticalTo:(id)anObject;

- (void) removeObjectsAtIndexes:(NSIndexSet*)indexes;

- (void) removeAllObjects;

- (void) replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

@end