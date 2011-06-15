/*
 CHDataStructures.framework -- CHSortedDictionary.h

 Copyright (c) 2009-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "CHMutableDictionary.h"
#import "CHSortedSet.h"

@interface CHSortedDictionary : CHMutableDictionary {
	id<CHSortedSet> sortedKeys;
}

#pragma mark Querying Contents

- (id) firstKey;

- (id) lastKey;

- (NSMutableDictionary*) subsetFromKey:(id)start
                                 toKey:(id)end
                               options:(CHSubsetConstructionOptions)options;

@end