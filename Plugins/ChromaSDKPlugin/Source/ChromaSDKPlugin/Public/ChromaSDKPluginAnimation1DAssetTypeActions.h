﻿// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UnrealEd.h"
#include "AssetTypeActions_Base.h"
#include "ChromaSDKPluginAnimation1DObject.h"

class FChromaSDKPluginAnimation1DAssetTypeActions : public FAssetTypeActions_Base
{
	// IAssetTypeActions interface
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;

	// Want the preview thumbnail from ForeceFeedbackEffect
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override;
	virtual void GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder) override;
	virtual void AssetsActivated(const TArray<UObject*>& InObjects, EAssetTypeActivationMethod::Type ActivationType) override;
	virtual TSharedPtr<SWidget> GetThumbnailOverlay(const FAssetData& AssetData) const override;

	/** Return if the specified effect is playing*/
	bool IsEffectPlaying(const TArray<TWeakObjectPtr<UChromaSDKPluginAnimation1DObject>>& Objects) const;

	/** Handler for when PlayEffect is selected */
	void ExecutePlayEffect(TArray<TWeakObjectPtr<UChromaSDKPluginAnimation1DObject>> Objects);

	/** Handler for when StopEffect is selected */
	void ExecuteStopEffect(TArray<TWeakObjectPtr<UChromaSDKPluginAnimation1DObject>> Objects);

	/** Returns true if only one effect is selected to play */
	bool CanExecutePlayCommand(TArray<TWeakObjectPtr<UChromaSDKPluginAnimation1DObject>> Objects) const;
	// End of IAssetTypeActions interface
};
