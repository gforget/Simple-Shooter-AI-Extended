// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/Actors/AmmoPack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAmmoPack() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AAmmoPack();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AAmmoPack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	DEFINE_FUNCTION(AAmmoPack::execOnOverlapBegin)
	{
		P_GET_OBJECT(AActor,Z_Param_OverlappedActor);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedActor,Z_Param_OtherActor);
		P_NATIVE_END;
	}
	void AAmmoPack::StaticRegisterNativesAAmmoPack()
	{
		UClass* Class = AAmmoPack::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &AAmmoPack::execOnOverlapBegin },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics
	{
		struct AmmoPack_eventOnOverlapBegin_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::NewProp_OverlappedActor = { "OverlappedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AmmoPack_eventOnOverlapBegin_Parms, OverlappedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AmmoPack_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::NewProp_OverlappedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AAmmoPack, nullptr, "OnOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::AmmoPack_eventOnOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::AmmoPack_eventOnOverlapBegin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AAmmoPack_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AAmmoPack_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAmmoPack);
	UClass* Z_Construct_UClass_AAmmoPack_NoRegister()
	{
		return AAmmoPack::StaticClass();
	}
	struct Z_Construct_UClass_AAmmoPack_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoAmount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AmmoAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoPackActiveMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AmmoPackActiveMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoPackInactiveMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AmmoPackInactiveMaterial;
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
	UObject* (*const Z_Construct_UClass_AAmmoPack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AAmmoPack_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AAmmoPack_OnOverlapBegin, "OnOverlapBegin" }, // 489652643
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/AmmoPack.h" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_TimeToRecharge_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_TimeToRecharge = { "TimeToRecharge", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, TimeToRecharge), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_TimeToRecharge_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_TimeToRecharge_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoAmount_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoAmount = { "AmmoAmount", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, AmmoAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoAmount_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackActiveMaterial_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackActiveMaterial = { "AmmoPackActiveMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, AmmoPackActiveMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackActiveMaterial_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackActiveMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackInactiveMaterial_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackInactiveMaterial = { "AmmoPackInactiveMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, AmmoPackInactiveMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackInactiveMaterial_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackInactiveMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_Root_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_Root_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_Root_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_BoxComponent_MetaData[] = {
		{ "Category", "AmmoPack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_BoxComponent = { "BoxComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, BoxComponent), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_BoxComponent_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_BoxComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAmmoPack_Statics::NewProp_RechargeTimer_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actors/AmmoPack.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAmmoPack_Statics::NewProp_RechargeTimer = { "RechargeTimer", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAmmoPack, RechargeTimer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::NewProp_RechargeTimer_MetaData), Z_Construct_UClass_AAmmoPack_Statics::NewProp_RechargeTimer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAmmoPack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_TimeToRecharge,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackActiveMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_AmmoPackInactiveMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_Root,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_BoxComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAmmoPack_Statics::NewProp_RechargeTimer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAmmoPack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAmmoPack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAmmoPack_Statics::ClassParams = {
		&AAmmoPack::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AAmmoPack_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::Class_MetaDataParams), Z_Construct_UClass_AAmmoPack_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAmmoPack_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AAmmoPack()
	{
		if (!Z_Registration_Info_UClass_AAmmoPack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAmmoPack.OuterSingleton, Z_Construct_UClass_AAmmoPack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAmmoPack.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AAmmoPack>()
	{
		return AAmmoPack::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAmmoPack);
	AAmmoPack::~AAmmoPack() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_AmmoPack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_AmmoPack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAmmoPack, AAmmoPack::StaticClass, TEXT("AAmmoPack"), &Z_Registration_Info_UClass_AAmmoPack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAmmoPack), 2051764478U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_AmmoPack_h_2375944326(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_AmmoPack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_AmmoPack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
