// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ChromaSDKPlugin.h"
#include "Engine.h"
#include "ChromaSDKPluginTypes.h"
#if PLATFORM_WINDOWS
#include <map>
#endif
#include "ChromaSDKPluginBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UCLASS()
class CHROMASDKPLUGIN_API UChromaSDKPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsPlatformWindows", Keywords = "Returns true on the Windows Platform"), Category = "ChromaSDK")
	static bool IsPlatformWindows();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxLeds", Keywords = "Get the max led size for the device"), Category = "ChromaSDK")
	static int GetMaxLeds(const EChromaSDKDevice1DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxRow", Keywords = "Get the max row size for the device"), Category = "ChromaSDK")
	static int GetMaxRow(const EChromaSDKDevice2DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxColumn", Keywords = "Get the max column size for the device"), Category = "ChromaSDK")
	static int GetMaxColumn(const EChromaSDKDevice2DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateColors1D", Keywords = "Create a blank one-dimensional color array"), Category = "ChromaSDK")
	static TArray<FLinearColor> CreateColors1D(const EChromaSDKDevice1DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateColors2D", Keywords = "Create a blank two-dimensional color array"), Category = "ChromaSDK")
	static TArray<FChromaSDKColors> CreateColors2D(const EChromaSDKDevice2DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColors1D", Keywords = "Create a random one-dimensional color array"), Category = "ChromaSDK")
	static TArray<FLinearColor> CreateRandomColors1D(const EChromaSDKDevice1DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColors2D", Keywords = "Create a random two-dimensional color array"), Category = "ChromaSDK")
	static TArray<FChromaSDKColors> CreateRandomColors2D(const EChromaSDKDevice2DEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyboardKeyColor", Keywords = "Set the key to the supplied color"), Category = "ChromaSDK")
	static const TArray<FChromaSDKColors>& SetKeyboardKeyColor(const EChromaSDKKeyboardKey& key, const FLinearColor& color, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetMouseLedColor", Keywords = "Set the led to the supplied color"), Category = "ChromaSDK")
	static const TArray<FChromaSDKColors>& SetMouseLedColor(const EChromaSDKMouseLed& led, const FLinearColor& color, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsInitialized", Keywords = "Return true if the blueprint library is initialized"), Category = "ChromaSDK")
	static bool IsInitialized();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Init", Keywords = "Initialize the ChromaSDK"), Category = "ChromaSDK")
	static int ChromaSDKInit();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnInit", Keywords = "Uninitialize the ChromaSDK"), Category = "ChromaSDK")
	static int ChromaSDKUnInit();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DebugGetString", Keywords = "Get Debug String From Effect Id"), Category = "ChromaSDK")
	static FString DebugToString(const FChromaSDKGuid& effectId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectNone", Keywords = "Clear the color effect"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectNone(const EChromaSDKDeviceEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectStatic", Keywords = "Create a static color effect"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectStatic(const EChromaSDKDeviceEnum& device, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectCustom1D", Keywords = "Create a custom color effect using one-dimensional array"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectCustom1D(const EChromaSDKDevice1DEnum& device, const TArray<FLinearColor>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectCustom2D", Keywords = "Create a custom color effect using two-dimensional array"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectCustom2D(const EChromaSDKDevice2DEnum& device, const TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetEffect", Keywords = "Set Effect with Effect Id"), Category = "ChromaSDK")
	static int ChromaSDKSetEffect(const FChromaSDKGuid& effectId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DeleteEffect", Keywords = "Delete Effect with Effect Id"), Category = "ChromaSDK")
	static int ChromaSDKDeleteEffect(const FChromaSDKGuid& effectId);

	// library methods

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationId", Keywords = "Get the animation id"), Category = "ChromaSDK")
	static int GetAnimationId(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationName", Keywords = "Get the animation name"), Category = "ChromaSDK")
	static FString GetAnimationName(const int animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LoadAnimation", Keywords = "Load the *.chroma Animation"), Category = "ChromaSDK")
	static void LoadAnimation(const int animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LoadAnimationName", Keywords = "Load the *.chroma Animation"), Category = "ChromaSDK")
	static void LoadAnimationName(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CloseAnimation", Keywords = "Close the *.chroma Animation"), Category = "ChromaSDK")
	static void CloseAnimation(const int animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CloseAnimationName", Keywords = "Close the *.chroma Animation"), Category = "ChromaSDK")
	static void CloseAnimationName(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnloadAnimation", Keywords = "Unload the *.chroma Animation"), Category = "ChromaSDK")
	static void UnloadAnimation(const int animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnloadAnimationName", Keywords = "Unload the *.chroma Animation"), Category = "ChromaSDK")
	static void UnloadAnimationName(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimation", Keywords = "Play the *.chroma Animation"), Category = "ChromaSDK")
	static void PlayAnimation(const FString& animationName, bool loop);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimation", Keywords = "Stop the *.chroma Animation"), Category = "ChromaSDK")
	static void StopAnimation(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimationType", Keywords = "Stop playing the Animation type"), Category = "ChromaSDK")
	static void StopAnimationType(const EChromaSDKDeviceEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAll", Keywords = "Stop playing all animations"), Category = "ChromaSDK")
	static void StopAll();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearAnimationType", Keywords = "Clear the device"), Category = "ChromaSDK")
	static void ClearAnimationType(const EChromaSDKDeviceEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearAll", Keywords = "Clear all devices"), Category = "ChromaSDK")
	static void ClearAll();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationCount", Keywords = "Get the number of open animations"), Category = "ChromaSDK")
	static int GetAnimationCount();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationIdByIndex", Keywords = "Get the animationId for the open animation index"), Category = "ChromaSDK")
	static int GetAnimationIdByIndex(int index);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetPlayingAnimationCount", Keywords = "Get the number of playing animations"), Category = "ChromaSDK")
	static int GetPlayingAnimationCount();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetPlayingAnimationId", Keywords = "Get the animationId for the playing animation index"), Category = "ChromaSDK")
	static int GetPlayingAnimationId(int index);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsAnimationPlaying", Keywords = "Is the *.chroma Animation playing?"), Category = "ChromaSDK")
	static bool IsAnimationPlaying(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsAnimationTypePlaying", Keywords = "Is the Animation type playing?"), Category = "ChromaSDK")
	static bool IsAnimationTypePlaying(const EChromaSDKDeviceEnum& device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimations", Keywords = "Play an array of *.chroma Animations"), Category = "ChromaSDK")
	static void PlayAnimations(const TArray<FString>& animationNames, bool loop);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimations", Keywords = "Stop an array *.chroma Animations"), Category = "ChromaSDK")
	static void StopAnimations(const TArray<FString>& animationNames);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimationComposite", Keywords = "Play a set of *_Device.chroma Animations"), Category = "ChromaSDK")
	static void PlayAnimationComposite(const FString& animationName, bool loop);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimationComposite", Keywords = "Stop a set of *_Device.chroma Animations"), Category = "ChromaSDK")
	static void StopAnimationComposite(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyColor", Keywords = "Get the color from the animation frame's key"), Category = "ChromaSDK")
	static FLinearColor GetKeyColor(int animationId, int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyColorName", Keywords = "Get the color from the animation frame's key"), Category = "ChromaSDK")
	static FLinearColor GetKeyColorName(const FString& animationName, const int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColor", Keywords = "Set the animation frame's key to the supplied color"), Category = "ChromaSDK")
	static void SetKeyColor(int animationId, int frameIndex, const EChromaSDKKeyboardKey& key, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorName", Keywords = "Set the animation frame's key to the supplied color"), Category = "ChromaSDK")
	static void SetKeyColorName(const FString& animationName, const int frameIndex, const EChromaSDKKeyboardKey& key, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColor", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
//	static void SetKeysColor(int animationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys, const FLinearColor& color); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void SetKeysColor(int animationId, int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys, const FLinearColor& color); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorName", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
//	static void SetKeysColorName(const FString& animationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys, const FLinearColor& color); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void SetKeysColorName(const FString& animationName, const int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys, const FLinearColor& color); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorAllFrames", Keywords = "Set the key to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeyColorAllFrames(int animationId, const EChromaSDKKeyboardKey& key, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorAllFramesName", Keywords = "Set the key to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeyColorAllFramesName(const FString& animationName, const EChromaSDKKeyboardKey& key, const FLinearColor& color);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFrames", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
//	static void SetKeysColorAllFrames(int animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys, const FLinearColor& color); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void SetKeysColorAllFrames(int animationId, const TArray<EChromaSDKKeyboardKey>& keys, const FLinearColor& color); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFramesName", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
//	static void SetKeysColorAllFramesName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys, const FLinearColor& color); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void SetKeysColorAllFramesName(const FString& animationName, const TArray<EChromaSDKKeyboardKey>& keys, const FLinearColor& color); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeyColor", Keywords = "Copy color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyKeyColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeyColorName", Keywords = "Copy color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColor", Keywords = "Copy color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
//	static void CopyKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorName", Keywords = "Copy color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
//	static void CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorAllFrames", Keywords = "Copy color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
//	static void CopyKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorAllFramesName", Keywords = "Copy color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
//	static void CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeyColor", Keywords = "Copy nonzero color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyNonZeroKeyColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeyColorName", Keywords = "Copy nonzero color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyNonZeroKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const EChromaSDKKeyboardKey& key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColor", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
//	static void CopyNonZeroKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyNonZeroKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorName", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
//	static void CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorAllFrames", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
//	static void CopyNonZeroKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyNonZeroKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorAllFramesName", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
//	static void CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey>>& keys); //(support 4.13 and below)___HACK_UE4_WANTS_GAME_MODE
	static void CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<EChromaSDKKeyboardKey>& keys); //(support above 4.13)___HACK_UE4_WANTS_BASE_GAME_MODE

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameCount", Keywords = "Get the .chroma animation frame count"), Category = "ChromaSDK")
	static int GetFrameCount(const int animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameCountName", Keywords = "Get the .chroma animation frame count"), Category = "ChromaSDK")
	static int GetFrameCountName(const FString& animationName);

#if PLATFORM_WINDOWS
private:
	static void ToString(const RZEFFECTID& effectId, FString& effectString);
	static void ToEffect(const FString& effectString, RZEFFECTID& effectId);
	static std::map<EChromaSDKKeyboardKey, int> _sKeyboardEnumMap;
	static std::map<EChromaSDKMouseLed, ChromaSDK::Mouse::RZLED2> _sMouseEnumMap;

	static bool _sInitialized;
#endif
};
