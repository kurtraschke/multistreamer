//
//  ASSuperclass.m
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/28/11.
//  Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.
//

#import "ASSuperclass.h"


@implementation ASSuperclass

- (NSDictionary *)fileAttributesToWriteToURL:(NSURL *)absoluteURL
									  ofType:(NSString *)typeName
							forSaveOperation:(NSSaveOperationType)saveOperation
						 originalContentsURL:(NSURL *)absoluteOriginalContentsURL
									   error:(NSError **)outError
{
	
	const OSType kMyAppCreatorCode = 'MSsl'; //Is this correct?
	const OSType kMyDocumentTypeCode = 'MSsl';
	
    NSMutableDictionary *fileAttributes =
	[[super fileAttributesToWriteToURL:absoluteURL
								ofType:typeName forSaveOperation:saveOperation
				   originalContentsURL:absoluteOriginalContentsURL
								 error:outError] mutableCopy];
    [fileAttributes setObject:[NSNumber numberWithUnsignedInt:kMyAppCreatorCode]
					   forKey:NSFileHFSCreatorCode];
    [fileAttributes setObject:[NSNumber numberWithUnsignedInt:kMyDocumentTypeCode]
					   forKey:NSFileHFSTypeCode];
    return [fileAttributes autorelease];
}

- (void)canCloseDocumentWithDelegate:(id)delegate
				 shouldCloseSelector:(SEL)shouldCloseSelector
						 contextInfo:(void *)contextInfo
{
	[self closeAllStreams];
	
	[super canCloseDocumentWithDelegate:delegate 
					shouldCloseSelector:shouldCloseSelector 
							contextInfo:contextInfo];
	
}

@end
