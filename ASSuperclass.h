//
//  ASSuperclass.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/28/11.
//  Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.
//

#import <Cocoa/Cocoa.h>
#import "ASSheetProtocol.h"

@interface ASSuperclass : NSDocument  <ASSheetProtocol>  {

}

- (NSDictionary *)fileAttributesToWriteToURL:(NSURL *)absoluteURL
									  ofType:(NSString *)typeName
							forSaveOperation:(NSSaveOperationType)saveOperation
						 originalContentsURL:(NSURL *)absoluteOriginalContentsURL
									   error:(NSError **)outError;
@end
