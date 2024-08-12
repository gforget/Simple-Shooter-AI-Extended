// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/Actors/FleePoint.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFleePoint() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AFleePoint();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_AFleePoint_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void AFleePoint::StaticRegisterNativesAFleePoint()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFleePoint);
	UClass* Z_Construct_UClass_AFleePoint_NoRegister()
	{
		return AFleePoint::StaticClass();
	}
	struct Z_Construct_UClass_AFleePoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFleePoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFleePoint_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFleePoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Actors/FleePoint.h" },
		{ "ModuleRelativePath", "Public/Actors/FleePoint.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFleePoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFleePoint>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFleePoint_Statics::ClassParams = {
		&AFleePoint::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFleePoint_Statics::Class_MetaDataParams), Z_Construct_UClass_AFleePoint_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AFleePoint()
	{
		if (!Z_Registration_Info_UClass_AFleePoint.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFleePoint.OuterSingleton, Z_Construct_UClass_AFleePoint_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFleePoint.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<AFleePoint>()
	{
		return AFleePoint::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFleePoint);
	AFleePoint::~AFleePoint() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_FleePoint_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_FleePoint_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFleePoint, AFleePoint::StaticClass, TEXT("AFleePoint"), &Z_Registration_Info_UClass_AFleePoint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFleePoint), 3149591555U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_FleePoint_h_3967794235(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_FleePoint_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_Actors_FleePoint_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
