//
//  ASSheetProtocol.h
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/28/11.
//  Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.
//

#import <Cocoa/Cocoa.h>
@protocol ASSheetProtocol 
@optional 
- (void)customSheetDidEnd:(NSWindow *)alert returnCode:(NSInteger)returnCode
			  contextInfo:(id)contextInfo;
- (void)alertSheetDidEnd:(NSAlert *)alert returnCode:(NSInteger)returnCode
			 contextInfo:(id)contextInfo;
- (void)saveSheetDidEnd:(NSSavePanel *)alert returnCode:(NSInteger)returnCode
			contextInfo:(id)contextInfo;
- (void)openSheetDidEnd:(NSOpenPanel *)alert returnCode:(NSInteger)returnCode
			contextInfo:(id)contextInfo;
@end		