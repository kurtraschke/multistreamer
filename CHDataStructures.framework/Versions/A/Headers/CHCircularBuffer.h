/*
 CHDataStructures.framework -- CHCircularBuffer.h

 Copyright (c) 2009-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "Util.h"

@interface CHCircularBuffer : NSMutableArray {
	__strong id *array;
	NSUInteger arrayCapacity;
	NSUInteger count;
	NSUInteger headIndex;
	NSUInteger tailIndex;
	unsigned long mutations;
}

- (id) initWithArray:(NSArray*)anArray;

- (NSArray*) allObjects;
- (BOOL) containsObject:(id)anObject;
- (BOOL) containsObjectIdenticalTo:(id)anObject;
- (void) exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (id) firstObject;
- (NSUInteger) indexOfObject:(id)anObject;
- (NSUInteger) indexOfObjectIdenticalTo:(id)anObject;
- (id) lastObject;
- (NSEnumerator*) objectEnumerator;
- (NSArray*) objectsAtIndexes:(NSIndexSet*)indexes;
- (void) removeAllObjects;
- (void) removeFirstObject;
- (void) removeLastObject;
- (void) removeObject:(id)anObject;
- (void) removeObjectIdenticalTo:(id)anObject;
- (void) removeObjectsAtIndexes:(NSIndexSet*)indexes;
- (void) replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;
- (NSEnumerator*) reverseObjectEnumerator;

#pragma mark Adopted Protocols

- (void) encodeWithCoder:(NSCoder*)encoder;
- (id) initWithCoder:(NSCoder*)decoder;
- (id) copyWithZone:(NSZone*)zone;
- (NSUInteger) countByEnumeratingWithState:(NSFastEnumerationState*)state
                                   objects:(id*)stackbuf
                                     count:(NSUInteger)len;

@end