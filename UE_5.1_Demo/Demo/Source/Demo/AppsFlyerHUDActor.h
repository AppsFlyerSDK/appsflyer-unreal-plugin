// AppsFlyer

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppsFlyerHUDActor.generated.h"

UCLASS()
class DEMO_API AAppsFlyerHUDActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppsFlyerHUDActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    
public:
    // Expose the widget to editor so you can assign it
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<class UUserWidget> WidgetClass;

private:
    UPROPERTY()
    UUserWidget* WidgetInstance;

};
