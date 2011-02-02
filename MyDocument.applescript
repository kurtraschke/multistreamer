-- MyDocument.applescript
-- MultiStreamer

-- Created by Kurt Raschke on 1/28/11.
-- Copyright __MyCompanyName__ 2011. All rights reserved.

--property NSKeyedArchiver : class "NSKeyedArchiver"
--property NSError : class "NSError"
property |NSURL| : class "NSURL"

script MyDocument
	property parent : class "ASSuperclass"
	
	property mainWindow : missing value
	property addStreamSheet : missing value
	
	property theArrayController : missing value
	
	property theTableView : missing value
	property theData : {}
	
	property savedData : missing value
	
	property nameField : missing value
	property addressField : missing value
	
	property nameFieldValue : ""
	property addressFieldValue : ""
	
	on init()
		continue init()
		
		-- Add your subclass-specific initialization here.
		-- If an error occurs here, return missing value.
		
		return me
	end init
	
	on windowNibName()
		-- Override returning the nib file name of the document
		-- If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
		return "MyDocument"
	end windowNibName
	
	on windowControllerDidLoadNib_(aController)
		continue windowControllerDidLoadNib_(aController)
		-- Add any code here that needs to be executed once the windowController has loaded the document's window.
		if my savedData is not missing value then
			loadSavedData(savedData)
			set my savedData to missing value
		end if
	end windowControllerDidLoadNib_
	
	on dataOfType_error_(typeName, outError)
		
		set streams to {}
		
		repeat with theStream in theArrayController's arrangedObjects()
			set end of streams to {streamName:theStream's streamName, streamURL:theStream's streamURL, streamBalance:theStream's streamBalance, streamVolume:theStream's streamVolume}
			
		end repeat
		
		return current application's NSKeyedArchiver's archivedDataWithRootObject_({streams})
	end dataOfType_error_
	
	on readFromData_ofType_error_(theData, typeName, outError)
		try
			set theResult to (current application's NSKeyedUnarchiver's unarchiveObjectWithData_(theData))
			set {my savedData} to theResult as list
			
			if theArrayController is not missing value then
				--if we get here, then the nib has been initialized; we must be doing a revert
				--therefore we have to clear out theArrayController
				repeat with theStream in theArrayController's arrangedObjects()
					theStream's closeStream()
				end repeat
				theArrayController's removeObjects_(theArrayController's arrangedObjects())
				loadSavedData(savedData)
				set my savedData to missing value
			end if
			
			return true
		on error errmess
			log errmess
			return false
		end try
	end readFromData_ofType_error_
	
	on loadSavedData(theData)
		repeat with theStream in theData
			set newStream to current application's Stream's alloc()'s init()
			set theURL to |NSURL|'s URLWithString_(theStream's streamURL)
			
			newStream's setupStream__(theURL, theStream's streamName)
			set newStream's streamBalance to theStream's streamBalance
			set newStream's streamVolume to theStream's streamVolume
			my theArrayController's addObject_(newStream)
		end repeat
	end loadSavedData
	
	
	on playAllStreams_(sender)
		repeat with theStream in theArrayController's arrangedObjects()
			if theStream's isPlayable as integer is equal to 1 then
				set theStream's isPlaying to true
			end if
		end repeat
	end playAllStreams_
	
	on stopAllStreams_(sender)
		repeat with theStream in theArrayController's arrangedObjects()
			if theStream's isPlaying as integer is equal to 1 then
				set theStream's isPlaying to false
			end if
		end repeat
	end stopAllStreams_
	
	--Make sure there isn't already a stream with that URL
	on validateURL(theURL)
		repeat with theStream in theArrayController's arrangedObjects()
			if theURL as text is equal to theStream's streamURL as text then
				return false
			end if
		end repeat
		return true
	end validateURL
	
	--Make sure there isn't already a stream with that name
	on validateName(theName)
		repeat with theStream in theArrayController's arrangedObjects()
			if theName as text is equal to theStream's streamName as text then
				return false
			end if
		end repeat
		return true
	end validateName
	
	on showAddStreamSheet_(sender) -- triggered by button in window
		tell current application's NSApp to beginSheet_modalForWindow_modalDelegate_didEndSelector_contextInfo_(addStreamSheet, mainWindow, me, "addStreamSheetDidEnd:returnCode:contextInfo:", missing value)
	end showAddStreamSheet_
	
	on AddStreamSheetButtonPushed_(sender) -- triggered by button in sheet
		set returnCode to 0 --  use different numbers for different buttons
		
		set theName to nameFieldValue as text
		set theURLString to addressFieldValue as text
		
		if not validateURL(theURLString) then
			display dialog "A stream with that URL already exists." with icon 0 buttons {"OK"} default button 1
			return
		end if
		
		set theURL to |NSURL|'s URLWithString_(theURLString)
		
		if theURL is missing value then
			display dialog "The URL is invalid." with icon 0 buttons {"OK"} default button 1
			return
		end if
		
		if not validateName(theName) then
			display dialog "A stream with that name already exists." with icon 0 buttons {"OK"} default button 1
		end if
		
		nameField's setStringValue_("")
		addressField's setStringValue_("")
		
		set newStream to current application's Stream's alloc()'s init()
		set returnValue to newStream's setupStream__(theURL, theName) as integer
		if returnValue is 1 then
			theArrayController's addObject_(newStream)
		end if
		
		-- collect any other info
		-- the following call closes the window and results in AddStreamSheetDidEnd_returnCode_contextInfo_ being called
		tell current application's NSApp to endSheet_returnCode_(addStreamSheet, returnCode)
	end AddStreamSheetButtonPushed_
	
	on AddStreamSheetCancelButtonPushed_(sender)
		--if the sheet is cancelled, clear the fields and do nothing more
		set returnCode to 0
		nameField's setStringValue_("")
		addressField's setStringValue_("")
		
		tell current application's NSApp to endSheet_returnCode_(addStreamSheet, returnCode)
	end AddStreamSheetCancelButtonPushed_
	
	on AddStreamSheetDidEnd_returnCode_contextInfo_(theSheet, returnCode, unUsed)
		--we have nothing to do but close the sheet
		tell theSheet to orderOut_(me)
	end AddStreamSheetDidEnd_returnCode_contextInfo_
	
	on deleteStream_(sender)
		set theStream to first item of (theArrayController's selectedObjects())
		tell theStream to closeStream()
		tell theArrayController to removeObject_(theStream)
	end deleteStream_
	
	
end script
