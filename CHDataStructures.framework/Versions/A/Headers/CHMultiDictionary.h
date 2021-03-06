/*
 CHDataStructures.framework -- CHMultiDictionary.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "CHMutableDictionary.h"

@interface CHMultiDictionary : CHMutableDictionary {
	NSUInteger objectCount;
}

#pragma mark Querying Contents

- (NSUInteger) countForAllKeys;

- (NSUInteger) countForKey:(id)aKey;

- (NSSet*) objectsForKey:(id)aKey;

#pragma mark Modifying Contents

- (void) addObject:(id)anObject forKey:(id)aKey;

- (void) addObjects:(NSSet*)objectSet forKey:(id)aKey;

- (void) removeObject:(id)anObject forKey:(id)aKey;

- (void) removeObjectsForKey:(id)aKey;

- (void) setObjects:(NSSet*)objectSet forKey:(id)aKey;

@end