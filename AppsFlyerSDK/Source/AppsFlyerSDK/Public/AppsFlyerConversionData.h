#pragma once
#include "AppsFlyerConversionData.generated.h"
USTRUCT(BlueprintType)
struct FAppsFlyerConversionData
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(Category = AppsFlyerSDK, VisibleAnywhere, BlueprintReadOnly)
	TMap<FString, FString> InstallData;
};
