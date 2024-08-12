// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_UMMaster.h"
#include "../../Source/Runtime/Engine/Classes/Curves/CurveFloat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_UMMaster() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTreeComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBTService_BlackboardBase();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UMMaster();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UMMaster_NoRegister();
	SIMPLESHOOTER_API UEnum* Z_Construct_UEnum_SimpleShooter_EAIStateEnum();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAIStateEnum;
	static UEnum* EAIStateEnum_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAIStateEnum.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAIStateEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleShooter_EAIStateEnum, (UObject*)Z_Construct_UPackage__Script_SimpleShooter(), TEXT("EAIStateEnum"));
		}
		return Z_Registration_Info_UEnum_EAIStateEnum.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UEnum* StaticEnum<EAIStateEnum>()
	{
		return EAIStateEnum_StaticEnum();
	}
	struct Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enumerators[] = {
		{ "Flee", (int64)Flee },
		{ "LookForHealthPack", (int64)LookForHealthPack },
		{ "LookForAmmo", (int64)LookForAmmo },
		{ "EngageEnemy", (int64)EngageEnemy },
		{ "Explore", (int64)Explore },
		{ "None", (int64)None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EngageEnemy.Name", "EngageEnemy" },
		{ "Explore.Name", "Explore" },
		{ "Flee.Name", "Flee" },
		{ "LookForAmmo.Name", "LookForAmmo" },
		{ "LookForHealthPack.Name", "LookForHealthPack" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
		{ "None.Name", "None" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SimpleShooter,
		nullptr,
		"EAIStateEnum",
		"EAIStateEnum",
		Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_SimpleShooter_EAIStateEnum()
	{
		if (!Z_Registration_Info_UEnum_EAIStateEnum.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAIStateEnum.InnerSingleton, Z_Construct_UEnum_SimpleShooter_EAIStateEnum_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAIStateEnum.InnerSingleton;
	}
	void UBTService_UMMaster::StaticRegisterNativesUBTService_UMMaster()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_UMMaster);
	UClass* Z_Construct_UClass_UBTService_UMMaster_NoRegister()
	{
		return UBTService_UMMaster::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_UMMaster_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugActive_MetaData[];
#endif
		static void NewProp_bDebugActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultEnumState_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultEnumState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlC_HealthPercentCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FlC_HealthPercentCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlC_HaveAValidFleePointBool_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FlC_HaveAValidFleePointBool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlC_TimeSeenEnemyCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FlC_TimeSeenEnemyCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FlC_MaxTimeSeenAnEnemy_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FlC_MaxTimeSeenAnEnemy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LFHPC_HealthPercentCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LFHPC_HealthPercentCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LFHPC_HealthPackDistanceCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LFHPC_HealthPackDistanceCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxDistanceHealthPack_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistanceHealthPack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LFAPC_AmmoReservePercentCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LFAPC_AmmoReservePercentCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LFAPC_AmmoPackDistanceCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LFAPC_AmmoPackDistanceCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxDistanceAmmoPack_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDistanceAmmoPack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EEC_IsLastKnownEnemyLocationIsSetBool_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EEC_IsLastKnownEnemyLocationIsSetBool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EEC_TimeSeenEnemyCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EEC_TimeSeenEnemyCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EEC_AmmoInGunPercentCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EEC_AmmoInGunPercentCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EEC_HealthPercentCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EEC_HealthPercentCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EEC_MaxTimeSeenAnEnemy_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EEC_MaxTimeSeenAnEnemy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExC_EnemyInSightBool_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ExC_EnemyInSightBool;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExC_TimeSeenEnemyCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ExC_TimeSeenEnemyCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExC_MaxTimeSeenAnEnemy_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ExC_MaxTimeSeenAnEnemy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWorldPtr_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentWorldPtr;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInitiated_MetaData[];
#endif
		static void NewProp_bInitiated_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInitiated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwnerCompPtr_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwnerCompPtr;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_UMMaster_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AI/BTService_UMMaster.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	void Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive_SetBit(void* Obj)
	{
		((UBTService_UMMaster*)Obj)->bDebugActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive = { "bDebugActive", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBTService_UMMaster), &Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_DefaultEnumState_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_DefaultEnumState = { "DefaultEnumState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, DefaultEnumState), Z_Construct_UEnum_SimpleShooter_EAIStateEnum, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_DefaultEnumState_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_DefaultEnumState_MetaData) }; // 913484597
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HealthPercentCurve_MetaData[] = {
		{ "Category", "Flee Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Flee considerations\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Flee considerations" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HealthPercentCurve = { "FlC_HealthPercentCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, FlC_HealthPercentCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HealthPercentCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HealthPercentCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HaveAValidFleePointBool_MetaData[] = {
		{ "Category", "Flee Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HaveAValidFleePointBool = { "FlC_HaveAValidFleePointBool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, FlC_HaveAValidFleePointBool), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HaveAValidFleePointBool_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HaveAValidFleePointBool_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_TimeSeenEnemyCurve_MetaData[] = {
		{ "Category", "Flee Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_TimeSeenEnemyCurve = { "FlC_TimeSeenEnemyCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, FlC_TimeSeenEnemyCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_TimeSeenEnemyCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_TimeSeenEnemyCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_MaxTimeSeenAnEnemy_MetaData[] = {
		{ "Category", "Flee Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_MaxTimeSeenAnEnemy = { "FlC_MaxTimeSeenAnEnemy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, FlC_MaxTimeSeenAnEnemy), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_MaxTimeSeenAnEnemy_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_MaxTimeSeenAnEnemy_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPercentCurve_MetaData[] = {
		{ "Category", "Look For Health Pack Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Look for health pack properties\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look for health pack properties" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPercentCurve = { "LFHPC_HealthPercentCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, LFHPC_HealthPercentCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPercentCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPercentCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPackDistanceCurve_MetaData[] = {
		{ "Category", "Look For Health Pack Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPackDistanceCurve = { "LFHPC_HealthPackDistanceCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, LFHPC_HealthPackDistanceCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPackDistanceCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPackDistanceCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceHealthPack_MetaData[] = {
		{ "Category", "Look For Health Pack Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceHealthPack = { "MaxDistanceHealthPack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, MaxDistanceHealthPack), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceHealthPack_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceHealthPack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoReservePercentCurve_MetaData[] = {
		{ "Category", "Look For Ammo Pack Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Look for ammo pack properties\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Look for ammo pack properties" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoReservePercentCurve = { "LFAPC_AmmoReservePercentCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, LFAPC_AmmoReservePercentCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoReservePercentCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoReservePercentCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoPackDistanceCurve_MetaData[] = {
		{ "Category", "Look For Ammo Pack Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoPackDistanceCurve = { "LFAPC_AmmoPackDistanceCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, LFAPC_AmmoPackDistanceCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoPackDistanceCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoPackDistanceCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceAmmoPack_MetaData[] = {
		{ "Category", "Look For Ammo Pack Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceAmmoPack = { "MaxDistanceAmmoPack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, MaxDistanceAmmoPack), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceAmmoPack_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceAmmoPack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_IsLastKnownEnemyLocationIsSetBool_MetaData[] = {
		{ "Category", "Engage Enemy Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Engage Properties\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Engage Properties" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_IsLastKnownEnemyLocationIsSetBool = { "EEC_IsLastKnownEnemyLocationIsSetBool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, EEC_IsLastKnownEnemyLocationIsSetBool), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_IsLastKnownEnemyLocationIsSetBool_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_IsLastKnownEnemyLocationIsSetBool_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_TimeSeenEnemyCurve_MetaData[] = {
		{ "Category", "Engage Enemy Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_TimeSeenEnemyCurve = { "EEC_TimeSeenEnemyCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, EEC_TimeSeenEnemyCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_TimeSeenEnemyCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_TimeSeenEnemyCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_AmmoInGunPercentCurve_MetaData[] = {
		{ "Category", "Engage Enemy Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Engage Enemy Properties\")\n// FRuntimeFloatCurve EEC_AimingPercentCurve;\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Engage Enemy Properties\")\nFRuntimeFloatCurve EEC_AimingPercentCurve;" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_AmmoInGunPercentCurve = { "EEC_AmmoInGunPercentCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, EEC_AmmoInGunPercentCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_AmmoInGunPercentCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_AmmoInGunPercentCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_HealthPercentCurve_MetaData[] = {
		{ "Category", "Engage Enemy Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_HealthPercentCurve = { "EEC_HealthPercentCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, EEC_HealthPercentCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_HealthPercentCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_HealthPercentCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_MaxTimeSeenAnEnemy_MetaData[] = {
		{ "Category", "Engage Enemy Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_MaxTimeSeenAnEnemy = { "EEC_MaxTimeSeenAnEnemy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, EEC_MaxTimeSeenAnEnemy), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_MaxTimeSeenAnEnemy_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_MaxTimeSeenAnEnemy_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_EnemyInSightBool_MetaData[] = {
		{ "Category", "Explore Properties" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Explore properties\n" },
#endif
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explore properties" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_EnemyInSightBool = { "ExC_EnemyInSightBool", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, ExC_EnemyInSightBool), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_EnemyInSightBool_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_EnemyInSightBool_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_TimeSeenEnemyCurve_MetaData[] = {
		{ "Category", "Explore Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_TimeSeenEnemyCurve = { "ExC_TimeSeenEnemyCurve", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, ExC_TimeSeenEnemyCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_TimeSeenEnemyCurve_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_TimeSeenEnemyCurve_MetaData) }; // 3321759441
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_MaxTimeSeenAnEnemy_MetaData[] = {
		{ "Category", "Explore Properties" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_MaxTimeSeenAnEnemy = { "ExC_MaxTimeSeenAnEnemy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, ExC_MaxTimeSeenAnEnemy), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_MaxTimeSeenAnEnemy_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_MaxTimeSeenAnEnemy_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_CurrentWorldPtr_MetaData[] = {
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_CurrentWorldPtr = { "CurrentWorldPtr", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, CurrentWorldPtr), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_CurrentWorldPtr_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_CurrentWorldPtr_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated_MetaData[] = {
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	void Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated_SetBit(void* Obj)
	{
		((UBTService_UMMaster*)Obj)->bInitiated = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated = { "bInitiated", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBTService_UMMaster), &Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_OwnerCompPtr_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/BTService_UMMaster.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_OwnerCompPtr = { "OwnerCompPtr", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_UMMaster, OwnerCompPtr), Z_Construct_UClass_UBehaviorTreeComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_OwnerCompPtr_MetaData), Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_OwnerCompPtr_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTService_UMMaster_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bDebugActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_DefaultEnumState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HealthPercentCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_HaveAValidFleePointBool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_TimeSeenEnemyCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_FlC_MaxTimeSeenAnEnemy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPercentCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFHPC_HealthPackDistanceCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceHealthPack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoReservePercentCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_LFAPC_AmmoPackDistanceCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_MaxDistanceAmmoPack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_IsLastKnownEnemyLocationIsSetBool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_TimeSeenEnemyCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_AmmoInGunPercentCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_HealthPercentCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_EEC_MaxTimeSeenAnEnemy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_EnemyInSightBool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_TimeSeenEnemyCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_ExC_MaxTimeSeenAnEnemy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_CurrentWorldPtr,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_bInitiated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_UMMaster_Statics::NewProp_OwnerCompPtr,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_UMMaster_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_UMMaster>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_UMMaster_Statics::ClassParams = {
		&UBTService_UMMaster::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBTService_UMMaster_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_UMMaster_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UMMaster_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBTService_UMMaster()
	{
		if (!Z_Registration_Info_UClass_UBTService_UMMaster.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_UMMaster.OuterSingleton, Z_Construct_UClass_UBTService_UMMaster_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_UMMaster.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_UMMaster>()
	{
		return UBTService_UMMaster::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_UMMaster);
	UBTService_UMMaster::~UBTService_UMMaster() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::EnumInfo[] = {
		{ EAIStateEnum_StaticEnum, TEXT("EAIStateEnum"), &Z_Registration_Info_UEnum_EAIStateEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 913484597U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_UMMaster, UBTService_UMMaster::StaticClass, TEXT("UBTService_UMMaster"), &Z_Registration_Info_UClass_UBTService_UMMaster, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_UMMaster), 217564598U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_2693936269(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
