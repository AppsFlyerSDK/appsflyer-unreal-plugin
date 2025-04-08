// Fill out your copyright notice in the Description page of Project Settings.


#include "AppsFlyerHUDActor.h"
#include "Blueprint/UserWidget.h"
// #include "AppsFlyerSDKBlueprint.h"

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

    if (WidgetClass)
    {
        WidgetInstance = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
        if (WidgetInstance)
        {
            WidgetInstance->AddToViewport();
        }
    }
}

// Called every frame
void AAppsFlyerHUDActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

