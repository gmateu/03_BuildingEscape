// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	ActorThatOpens=GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor(float angle)
{
	//Find the owning Actor
	AActor* Owner = GetOwner();

	// create a rotator
	FRotator NewRotation = FRotator(0.f, angle, 0.f);
	//set the door totation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame,,,
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//Poll the trigger volumen
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		UE_LOG(LogTemp, Warning, TEXT("tick"));
		OpenDoor(-60.f);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("not tick"));
		OpenDoor(0.f);

	}
	
}

