// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/GameMode/SimpleShooterGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleShooterGameModeBase() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AAmmoPack_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AEnemySpawnPoint_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AHealthPack_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterCharacter_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ASimpleShooterGameModeBase();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ASimpleShooterGameModeBase_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AWaypoint_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void ASimpleShooterGameModeBase::StaticRegisterNativesASimpleShooterGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASimpleShooterGameModeBase);
	UClass* Z_Construct_UClass_ASimpleShooterGameModeBase_NoRegister()
	{
		return ASimpleShooterGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ASimpleShooterGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnEnemy_MetaData[];
#endif
		static void NewProp_SpawnEnemy_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_SpawnEnemy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnemyShooterCharacterClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EnemyShooterCharacterClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AllEnemySpawnPoints_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllEnemySpawnPoints_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AllEnemySpawnPoints;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AllWayPoints_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllWayPoints_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AllWayPoints;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AllAmmoPacks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllAmmoPacks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AllAmmoPacks;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AllHealthPacks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AllHealthPacks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AllHealthPacks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameMode/SimpleShooterGameModeBase.h" },
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy_MetaData[] = {
		{ "Category", "SimpleShooterGameModeBase" },
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	void Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy_SetBit(void* Obj)
	{
		((ASimpleShooterGameModeBase*)Obj)->SpawnEnemy = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy = { "SpawnEnemy", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ASimpleShooterGameModeBase), &Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_EnemyShooterCharacterClass_MetaData[] = {
		{ "Category", "SimpleShooterGameModeBase" },
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_EnemyShooterCharacterClass = { "EnemyShooterCharacterClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleShooterGameModeBase, EnemyShooterCharacterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AShooterCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_EnemyShooterCharacterClass_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_EnemyShooterCharacterClass_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints_Inner = { "AllEnemySpawnPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AEnemySpawnPoint_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints = { "AllEnemySpawnPoints", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleShooterGameModeBase, AllEnemySpawnPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints_Inner = { "AllWayPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AWaypoint_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints = { "AllWayPoints", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleShooterGameModeBase, AllWayPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks_Inner = { "AllAmmoPacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AAmmoPack_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks = { "AllAmmoPacks", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleShooterGameModeBase, AllAmmoPacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks_Inner = { "AllHealthPacks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AHealthPack_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks_MetaData[] = {
		{ "ModuleRelativePath", "Public/GameMode/SimpleShooterGameModeBase.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks = { "AllHealthPacks", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASimpleShooterGameModeBase, AllHealthPacks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks_MetaData), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_SpawnEnemy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_EnemyShooterCharacterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllEnemySpawnPoints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllWayPoints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllAmmoPacks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::NewProp_AllHealthPacks,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASimpleShooterGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::ClassParams = {
		&ASimpleShooterGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASimpleShooterGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton, Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<ASimpleShooterGameModeBase>()
	{
		return ASimpleShooterGameModeBase::StaticClass();
	}
	ASimpleShooterGameModeBase::ASimpleShooterGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASimpleShooterGameModeBase);
	ASimpleShooterGameModeBase::~ASimpleShooterGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_GameMode_SimpleShooterGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_GameMode_SimpleShooterGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASimpleShooterGameModeBase, ASimpleShooterGameModeBase::StaticClass, TEXT("ASimpleShooterGameModeBase"), &Z_Registration_Info_UClass_ASimpleShooterGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASimpleShooterGameModeBase), 4167539874U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_GameMode_SimpleShooterGameModeBase_h_491442307(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_GameMode_SimpleShooterGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_GameMode_SimpleShooterGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
