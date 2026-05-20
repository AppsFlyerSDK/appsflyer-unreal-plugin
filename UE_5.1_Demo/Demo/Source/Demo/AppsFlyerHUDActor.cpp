// Fill out your copyright notice in the Description page of Project Settings.


#include "AppsFlyerHUDActor.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "AppsFlyerSDKBlueprint.h"

// Sets default values
AAppsFlyerHUDActor::AAppsFlyerHUDActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AAppsFlyerHUDActor::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Log, TEXT("[AppsFlyerHUDActor] BeginPlay"));

    /*
    UAppsFlyerSDKBlueprint::SetConsentData(
        EAFBooleanState::ValueTrue,
        EAFBooleanState::ValueFalse,
        EAFBooleanState::ValueUnset,
        EAFBooleanState::ValueTrue
    );

    UAppsFlyerSDKBlueprint::SetConsentDataTOptional(
        TOptional<bool>(true),   // IsUserSubjectToGDPR
        TOptional<bool>(false),  // HasConsentForDataUsage
        TOptional<bool>(),       // HasConsentForAdsPersonalization (unset)
        TOptional<bool>(true)    // HasConsentForAdStorage
    );*/

    FAFAdRevenueData AdRevenueData;
    AdRevenueData.MonetizationNetwork = TEXT("ironsource");
    AdRevenueData.MediationNetwork    = EAFMediationNetwork::IronSource;
    AdRevenueData.CurrencyIso4217Code = TEXT("USD");
    AdRevenueData.EventRevenue        = 0.01;
    TMap<FString, FString> AdRevenueParams;
    AdRevenueParams.Add(TEXT("country"),    TEXT("US"));
    AdRevenueParams.Add(TEXT("ad_unit"),    TEXT("test_ad_unit"));
    AdRevenueParams.Add(TEXT("ad_type"),    TEXT("banner"));
    AdRevenueParams.Add(TEXT("placement"),  TEXT("main_menu"));
    UAppsFlyerSDKBlueprint::logAdRevenue(AdRevenueData, AdRevenueParams);
    UE_LOG(LogTemp, Log, TEXT("[AppsFlyerHUDActor] logAdRevenue called"));

    if (MainMenuWidgetClass)
    {
        MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    } else {
        UE_LOG(LogTemp, Log, TEXT("[AppsFlyerHUDActor] No MainMenuWidgetClass found"));
    }
}

// Called every frame
void AAppsFlyerHUDActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

