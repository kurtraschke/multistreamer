-- Stream.applescript
-- MultiStreamer

-- Created by Kurt Raschke on 1/27/11.
-- Copyright 2011 Kurt Raschke. See the file LICENSE.txt for license.

property |NSURL| : class "NSURL"
property MyQTMovie : class "MyQTMovie"
property NSNotificationCenter : class "NSNotificationCenter"
property NSTimer : class "NSTimer"
property NSUserDefaults : class "NSUserDefaults"
property NSNumber : class "NSNumber"

script Stream
	property parent : class "NSObject"
	
	property theDocument : missing value
	property streamName : missing value
	property streamURL : missing value
	property streamBalance : 0.0
	property streamVolume : 1.0
	property isPlaying : 0
	property isMuted : 0
	property isPlayable : 0
	
	property duckingActive : false
	property wasMuted : missing value
	property oldVolume : missing value
	
	property audioLevel : 0.0
	property lastAverage : 0.0
	
	property theMovie : missing value
	
	property notifCenter : missing value
	property updateLevelTimer : missing value
	
	on setupStream___(theURL, theName, theDocument)
		set my theDocument to theDocument
		set my streamName to theName
		set my streamURL to theURL's absoluteString()
		tell current application's MyQTMovie to set {theMovie, theError} to movieWithURL_error_(theURL, reference)
		
		if theError is not missing value then
			--These errors are miserable, but it's better than nothing.
			--Blame QuickTime for generating useless messages.
			log "error"
			tell current application's NSApp to presentError_(theError)
			return false
		else
			set my notifCenter to NSNotificationCenter's defaultCenter()
			tell my notifCenter to addObserver_selector_name_object_(me, "loadStateChanged:", "QTMovieLoadStateDidChangeNotification", my theMovie)
			return true
		end if
	end setupStream___
	
	on loadStateChanged_(notification)
		set loadState to my theMovie's attributeForKey_("QTMovieLoadStateAttribute") as integer
		set targetLoadState to current application's QTMovieLoadStatePlaythroughOK as integer
		if loadState is equal to targetLoadState then
			set my isPlayable to 1
			tell my notifCenter to removeObserver_name_object_(me, "QTMovieLoadStateDidChangeNotification", my theMovie)
			
			set autoPlay to current application's NSUserDefaults's standardUserDefaults's objectForKey_("autoPlay")
			if autoPlay's intValue() is 1 then
				tell me to setIsPlaying_(current application's NSNumber's numberWithBool_(1))
			end if
		end if
	end loadStateChanged_
	
	on setIsPlaying_(playingState)
		set isPlaying to playingState
		if playingState's intValue() is 1 then
			tell me to startStream()
		else if playingState's intValue() is 0 then
			tell me to stopStream()
		end if
	end setIsPlaying_
	
	on startStream()
		if my isPlayable is equal to 1 then
			tell my theMovie to setMovieToMaxLoadedAndPlay()
			tell my theMovie to setupAudioMetering()
			set my updateLevelTimer to current application's NSTimer's scheduledTimerWithTimeInterval_target_selector_userInfo_repeats_(0.1, me, "updateLevel:", "", true)
		end if
	end startStream
	
	on updateLevel_(theTimer)
		set theLevel to theMovie's getAudioLevel() as real
		set theAverage to theMovie's getAudioAverage() as real
		
		set theThreshold to (current application's NSUserDefaults's standardUserDefaults's objectForKey_("activityThreshold")'s floatValue())
		
		if theAverage is greater than or equal to theThreshold and lastAverage is less than theThreshold then
			--stream has started talking
			tell theDocument to setStreamTalking_(me)
		else if lastAverage is greater than or equal to theThreshold and theAverage is less than theThreshold then
			--stream has stopped talking
			tell theDocument to setStreamDoneTalking_(me)
		end if
		
		set my lastAverage to theAverage
		set my audioLevel to theLevel
	end updateLevel_
	
	on setAudioLevel_(theLevel)
		set my audioLevel to theLevel
	end setAudioLevel_
	
	on stopStream()
		tell my updateLevelTimer to invalidate()
		tell my theMovie to |stop|()
	end stopStream
	
	on closeStream()
		tell me to stopStream()
		tell my theMovie to invalidate()
	end closeStream
	
	on setIsMuted_(mutedState)
		set my isMuted to mutedState
		tell my theMovie to setMuted_(my isMuted)
	end setIsMuted_
	
	on setStreamBalance_(theBalance)
		set my streamBalance to theBalance
		tell my theMovie to setBalance_(my streamBalance as real)
	end setStreamBalance_
	
	on setStreamVolume_(theVolume)
		set my streamVolume to theVolume
		tell my theMovie to setVolume_(my streamVolume as real)
	end setStreamVolume_
	
	on startDucking()
		if duckingActive is false then
			set duckingMode to current application's NSUserDefaults's standardUserDefaults's objectForKey_("streamActiveMode")'s intValue()
			
			if duckingMode is 1 then
				--mute
				set wasMuted to my isMuted
				tell me to setIsMuted_(1)
			else if duckingMode is 2 then
				set oldVolume to my streamVolume
				set duckingFactor to (current application's NSUserDefaults's standardUserDefaults's objectForKey_("duckingLevel")'s intValue()) / 100
				set newVolume to (my streamVolume as real) * duckingFactor
				tell me to setStreamVolume_(newVolume)
			end if
			set duckingActive to true
		end if
	end startDucking
	
	on stopDucking()
		if duckingActive is true then
			set duckingMode to current application's NSUserDefaults's standardUserDefaults's objectForKey_("streamActiveMode")'s intValue()
			if duckingMode is 1 then
				--restore muting
				tell me to setIsMuted_(my wasMuted)
			else if duckingMode is 2 then
				--restore volume
				tell me to setStreamVolume_(oldVolume)
			end if
			set duckingActive to false
		end if
	end stopDucking
end script
