// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/Actors/EnemySpawnPoint.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemySpawnPoint() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AEnemySpawnPoint();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AEnemySpawnPoint_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ARoomTriggerBox_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void AEnemySpawnPoint::StaticRegisterNativesAEnemySpawnPoint()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemySpawnPoint);
	UClass* Z_Construct_UClass_AEnemySpawnPoint_NoRegister()
	{
		return AEnemySpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_AEnemySpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnedRoomTriggerBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedRoomTriggerBox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemySpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawnPoint_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemySpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/EnemySpawnPoint.h" },
		{ "ModuleRelativePath", "Public/Actors/EnemySpawnPoint.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemySpawnPoint_Statics::NewProp_SpawnedRoomTriggerBox_MetaData[] = {
		{ "Category", "EnemySpawnPoint" },
		{ "ModuleRelativePath", "Public/Actors/EnemySpawnPoint.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemySpawnPoint_Statics::NewProp_SpawnedRoomTriggerBox = { "SpawnedRoomTriggerBox", nullptr, (EPropertyFlags)0x0010000000000801, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawnPoint, SpawnedRoomTriggerBox), Z_Construct_UClass_ARoomTriggerBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawnPoint_Statics::NewProp_SpawnedRoomTriggerBox_MetaData), Z_Construct_UClass_AEnemySpawnPoint_Statics::NewProp_SpawnedRoomTriggerBox_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemySpawnPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawnPoint_Statics::NewProp_SpawnedRoomTriggerBox,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemySpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemySpawnPoint>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemySpawnPoint_Statics::ClassParams = {
		&AEnemySpawnPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEnemySpawnPoint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawnPoint_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawnPoint_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemySpawnPoint_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawnPoint_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AEnemySpawnPoint()
	{
		if (!Z_Registration_Info_UClass_AEnemySpawnPoint.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemySpawnPoint.OuterSingleton, Z_Construct_UClass_AEnemySpawnPoint_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemySpawnPoint.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AEnemySpawnPoint>()
	{
		return AEnemySpawnPoint::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemySpawnPoint);
	AEnemySpawnPoint::~AEnemySpawnPoint() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_EnemySpawnPoint_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_EnemySpawnPoint_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemySpawnPoint, AEnemySpawnPoint::StaticClass, TEXT("AEnemySpawnPoint"), &Z_Registration_Info_UClass_AEnemySpawnPoint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemySpawnPoint), 3143022787U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_EnemySpawnPoint_h_1309877365(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_EnemySpawnPoint_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_EnemySpawnPoint_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
