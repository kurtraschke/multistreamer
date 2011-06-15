/*
 CHDataStructures.framework -- CHOrderedDictionary.h

 Copyright (c) 2009-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "CHMutableDictionary.h"

@interface CHOrderedDictionary : CHMutableDictionary {
	id keyOrdering;
}

#pragma mark Querying Contents

- (id) firstKey;

- (id) lastKey;

- (NSUInteger) indexOfKey:(id)aKey;

- (id) keyAtIndex:(NSUInteger)index;

- (NSArray*) keysAtIndexes:(NSIndexSet*)indexes;

- (id) objectForKeyAtIndex:(NSUInteger)index;

- (NSArray*) objectsForKeysAtIndexes:(NSIndexSet*)indexes;

- (CHOrderedDictionary*) orderedDictionaryWithKeysAtIndexes:(NSIndexSet*)indexes;

- (NSEnumerator*) reverseKeyEnumerator;

#pragma mark Modifying Contents

- (void) exchangeKeyAtIndex:(NSUInteger)idx1 withKeyAtIndex:(NSUInteger)idx2;

- (void) insertObject:(id)anObject forKey:(id)aKey atIndex:(NSUInteger)index;

- (void) removeObjectForKeyAtIndex:(NSUInteger)index;

- (void) removeObjectsForKeysAtIndexes:(NSIndexSet*)indexes;

- (void) setObject:(id)anObject forKey:(id)aKey;

- (void) setObject:(id)anObject forKeyAtIndex:(NSUInteger)index;

@end