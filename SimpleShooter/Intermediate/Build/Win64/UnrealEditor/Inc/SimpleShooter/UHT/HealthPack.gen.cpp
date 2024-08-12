// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/Actors/HealthPack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHealthPack() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AHealthPack();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AHealthPack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	DEFINE_FUNCTION(AHealthPack::execOnOverlapBegin)
	{
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor);
		P_NATIVE_END;
	}
	void AHealthPack::StaticRegisterNativesAHealthPack()
	{
		UClass* Class = AHealthPack::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &AHealthPack::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics
	{
		struct HealthPack_eventOnOverlapBegin_Parms
		{
			AActor* OverlappedActor;
			AActor* OtherActor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedActor;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPack_eventOnOverlapBegin_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPack_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::NewProp_OverlappedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHealthPack, nullptr, "OnOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::HealthPack_eventOnOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::HealthPack_eventOnOverlapBegin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AHealthPack_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHealthPack_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHealthPack);
	UClass* Z_Construct_UClass_AHealthPack_NoRegister()
	{
		return AHealthPack::StaticClass();
	}
	struct Z_Construct_UClass_AHealthPack_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeToRecharge_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeToRecharge;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthPackActiveMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthPackActiveMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthPackInactiveMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthPackInactiveMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoxComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoxComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RechargeTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RechargeTimer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHealthPack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AHealthPack_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHealthPack_OnOverlapBegin, "OnOverlapBegin" }, // 418372567
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/HealthPack.h" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_TimeToRecharge_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_TimeToRecharge = { "TimeToRecharge", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, TimeToRecharge), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_TimeToRecharge_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_TimeToRecharge_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_HealAmount_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_HealAmount = { "HealAmount", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, HealAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_HealAmount_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_HealAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackActiveMaterial_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackActiveMaterial = { "HealthPackActiveMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, HealthPackActiveMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackActiveMaterial_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackActiveMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackInactiveMaterial_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackInactiveMaterial = { "HealthPackInactiveMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, HealthPackInactiveMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackInactiveMaterial_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackInactiveMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_Root_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_Root_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_Root_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_BoxComponent_MetaData[] = {
		{ "Category", "HealthPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_BoxComponent = { "BoxComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, BoxComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_BoxComponent_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_BoxComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHealthPack_Statics::NewProp_RechargeTimer_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actors/HealthPack.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHealthPack_Statics::NewProp_RechargeTimer = { "RechargeTimer", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPack, RechargeTimer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::NewProp_RechargeTimer_MetaData), Z_Construct_UClass_AHealthPack_Statics::NewProp_RechargeTimer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealthPack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_TimeToRecharge,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_HealAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackActiveMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_HealthPackInactiveMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_Root,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_BoxComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPack_Statics::NewProp_RechargeTimer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHealthPack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealthPack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHealthPack_Statics::ClassParams = {
		&AHealthPack::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHealthPack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::Class_MetaDataParams), Z_Construct_UClass_AHealthPack_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPack_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AHealthPack()
	{
		if (!Z_Registration_Info_UClass_AHealthPack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHealthPack.OuterSingleton, Z_Construct_UClass_AHealthPack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHealthPack.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AHealthPack>()
	{
		return AHealthPack::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHealthPack);
	AHealthPack::~AHealthPack() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_HealthPack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_HealthPack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHealthPack, AHealthPack::StaticClass, TEXT("AHealthPack"), &Z_Registration_Info_UClass_AHealthPack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHealthPack), 3830563594U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_HealthPack_h_2776552341(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_HealthPack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_HealthPack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
