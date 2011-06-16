//
//  main.m
//  MultiStreamer
//
//  Created by Kurt Raschke on 1/28/11.
//  Copyright Kurt Raschke 2011. See the file LICENSE.txt for license.
//

#import <Cocoa/Cocoa.h>
#import <AppleScriptObjC/AppleScriptObjC.h>

int main(int argc, char *argv[])
{
	[[NSBundle mainBundle] loadAppleScriptObjectiveCScripts];

	return NSApplicationMain(argc, (const char **) argv);
}
