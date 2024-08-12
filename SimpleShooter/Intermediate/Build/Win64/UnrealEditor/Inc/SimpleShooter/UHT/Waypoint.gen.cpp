// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/Actors/Waypoint.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaypoint() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AWaypoint();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AWaypoint_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void AWaypoint::StaticRegisterNativesAWaypoint()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWaypoint);
	UClass* Z_Construct_UClass_AWaypoint_NoRegister()
	{
		return AWaypoint::StaticClass();
	}
	struct Z_Construct_UClass_AWaypoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWaypoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaypoint_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWaypoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/Waypoint.h" },
		{ "ModuleRelativePath", "Public/Actors/Waypoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWaypoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaypoint>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaypoint_Statics::ClassParams = {
		&AWaypoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaypoint_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaypoint_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AWaypoint()
	{
		if (!Z_Registration_Info_UClass_AWaypoint.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaypoint.OuterSingleton, Z_Construct_UClass_AWaypoint_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWaypoint.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AWaypoint>()
	{
		return AWaypoint::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWaypoint);
	AWaypoint::~AWaypoint() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_Waypoint_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_Waypoint_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWaypoint, AWaypoint::StaticClass, TEXT("AWaypoint"), &Z_Registration_Info_UClass_AWaypoint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaypoint), 2638710776U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_Waypoint_h_2832324069(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_Waypoint_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_Waypoint_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
