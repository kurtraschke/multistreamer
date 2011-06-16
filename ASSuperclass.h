//
//  ASSuperclass.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/28/11.
//  Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.
//

#import <Cocoa/Cocoa.h>
#import "CloseStreams.h"

@interface ASSuperclass : NSDocument <CloseStreams>  {

}

- (NSDictionary *)fileAttributesToWriteToURL:(NSURL *)absoluteURL
									  ofType:(NSString *)typeName
							forSaveOperation:(NSSaveOperationType)saveOperation
						 originalContentsURL:(NSURL *)absoluteOriginalContentsURL
									   error:(NSError **)outError;

- (void)canCloseDocumentWithDelegate:(id)delegate
				 shouldCloseSelector:(SEL)shouldCloseSelector
						 contextInfo:(void *)contextInfo;

@end
