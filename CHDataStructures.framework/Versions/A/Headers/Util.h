/*
 CHDataStructures.framework -- Util.h

 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>

 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>

 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

 The software is provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import <Foundation/Foundation.h>

#define HIDDEN __attribute__((visibility("hidden")))

#define UNUSED __attribute__((unused))

#pragma mark -

#ifndef NSINTEGER_DEFINED
	#if __LP64__ || NS_BUILD_32_LIKE_64
		typedef long NSInteger;
		typedef unsigned long NSUInteger;
	#else
		typedef int NSInteger;
		typedef unsigned int NSUInteger;
	#endif

	#define NSIntegerMax    LONG_MAX
	#define NSIntegerMin    LONG_MIN
	#define NSUIntegerMax   ULONG_MAX

	#define NSINTEGER_DEFINED 1
#endif

#pragma mark -

#if (TARGET_OS_IPHONE || TARGET_OS_EMBEDDED || !TARGET_OS_MAC)

enum {
    NSScannedOption = (1UL << 0),
    NSCollectorDisabledOption = (1UL << 1),
};

void* __strong NSAllocateCollectable(NSUInteger size, NSUInteger options);

void* __strong NSReallocateCollectable(void *ptr, NSUInteger size, NSUInteger options);

#define objc_memmove_collectable memmove

#else

HIDDEN void* objc_memmove_collectable(void *dst, const void *src, size_t size);

#endif

#pragma mark -

OBJC_EXPORT BOOL kCHGarbageCollectionNotEnabled;

HIDDEN size_t kCHPointerSize;

HIDDEN BOOL objectsAreEqual(id o1, id o2);

HIDDEN BOOL objectsAreIdentical(id o1, id o2);

OBJC_EXPORT BOOL collectionsAreEqual(id collection1, id collection2);

HIDDEN NSUInteger hashOfCountAndObjects(NSUInteger count, id o1, id o2);

#pragma mark -

OBJC_EXPORT void CHIndexOutOfRangeException(Class aClass, SEL method,
                                       NSUInteger index, NSUInteger elements);

OBJC_EXPORT void CHInvalidArgumentException(Class aClass, SEL method, NSString *str);

OBJC_EXPORT void CHNilArgumentException(Class aClass, SEL method);

OBJC_EXPORT void CHMutatedCollectionException(Class aClass, SEL method);

OBJC_EXPORT void CHUnsupportedOperationException(Class aClass, SEL method);

OBJC_EXPORT void CHQuietLog(NSString *format, ...);

#ifndef CHLocationLog
#define CHLocationLog(format,...) \
{ \
	NSString *file = [[NSString alloc] initWithUTF8String:__FILE__]; \
	printf("[%s:%d] ", [[file lastPathComponent] UTF8String], __LINE__); \
	[file release]; \
	CHQuietLog((format),##__VA_ARGS__); \
}
#endif