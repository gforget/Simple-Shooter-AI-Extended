// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_UpdateSelfHealth.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_UpdateSelfHealth() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService_BlackboardBase();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UpdateSelfHealth();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UpdateSelfHealth_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTService_UpdateSelfHealth::StaticRegisterNativesUBTService_UpdateSelfHealth()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_UpdateSelfHealth);
	UClass* Z_Construct_UClass_UBTService_UpdateSelfHealth_NoRegister()
	{
		return UBTService_UpdateSelfHealth::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_UpdateSelfHealth.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_UpdateSelfHealth.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_UpdateSelfHealth>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::ClassParams = {
		&UBTService_UpdateSelfHealth::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTService_UpdateSelfHealth()
	{
		if (!Z_Registration_Info_UClass_UBTService_UpdateSelfHealth.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_UpdateSelfHealth.OuterSingleton, Z_Construct_UClass_UBTService_UpdateSelfHealth_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_UpdateSelfHealth.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_UpdateSelfHealth>()
	{
		return UBTService_UpdateSelfHealth::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_UpdateSelfHealth);
	UBTService_UpdateSelfHealth::~UBTService_UpdateSelfHealth() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateSelfHealth_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateSelfHealth_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_UpdateSelfHealth, UBTService_UpdateSelfHealth::StaticClass, TEXT("UBTService_UpdateSelfHealth"), &Z_Registration_Info_UClass_UBTService_UpdateSelfHealth, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_UpdateSelfHealth), 1973781345U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateSelfHealth_h_543384957(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateSelfHealth_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateSelfHealth_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
