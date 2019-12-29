// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_MyTask.generated.h"

// This lets you create a delegate with no parameters by the struct name of "FMyDelegate".
// DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyDelegate); //So if you want to have a class with a delegate variable of that type, you'd
// declare it as FMyDelegate DelegateVariable; //Finally, if you want to call all functions wired to DelegateVariable, you call
// DelegateVariable.Broadcast();

/* You're not limited to just no-parameter functions either, a delegate that takes functions with a first parameter float and a
 * second parameter int looks like this: */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMyTwoParamDelegate, float, FirstParamName, int32,
	SecondParamName);	// You would then broadcast it like, for example: TwoParamDelegateVariable.Broadcast(20.f, 15);

UCLASS() class UAbilityTask_MyTask : public UAbilityTask
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable) FMyTwoParamDelegate OnCalled;

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks",
		meta = (DisplayName = "ExecuteMyTask", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility",
			BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_MyTask* CreateMyTask(UGameplayAbility* OwningAbility, FName TaskInstanceName, float examplevariable);

	/* This function will call after the BP node has successfully requested the ability task from the static function. You put your
	 * actual functionality here. More on that in a bit. */
	virtual void Activate() override;
};
