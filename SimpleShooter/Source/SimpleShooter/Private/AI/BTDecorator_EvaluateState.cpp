// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTDecorator_EvaluateState.h"

#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_EvaluateState::UBTDecorator_EvaluateState()
{
	NodeName = TEXT("State =");
	NotifyObserver = EBTBlackboardRestart::ResultChange;
}

bool UBTDecorator_EvaluateState::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (StateEvaluated == EAIStateEnum::None) return false;
	
	const bool bReturnValue = OwnerComp.GetBlackboardComponent()->GetValueAsEnum(GetSelectedBlackboardKey()) == StateEvaluated;
	return bReturnValue;
}

EBlackboardNotificationResult UBTDecorator_EvaluateState::OnBlackboardKeyValueChange(
	const UBlackboardComponent& Blackboard, FBlackboard::FKey ChangedKeyID)
{
	UBehaviorTreeComponent* BehaviorComp = (UBehaviorTreeComponent*)Blackboard.GetBrainComponent();
	if (BehaviorComp == nullptr)
	{
		return EBlackboardNotificationResult::RemoveObserver;
	}

	if (BlackboardKey.GetSelectedKeyID() == ChangedKeyID)
	{
		// can't simply use BehaviorComp->RequestExecution(this) here, we need to support condition/value change modes

		const EBTDecoratorAbortRequest RequestMode = (NotifyObserver == EBTBlackboardRestart::ValueChange) ? EBTDecoratorAbortRequest::ConditionPassing : EBTDecoratorAbortRequest::ConditionResultChanged;
		ConditionalFlowAbort(*BehaviorComp, RequestMode);
	}

	return EBlackboardNotificationResult::ContinueObserving;
}
