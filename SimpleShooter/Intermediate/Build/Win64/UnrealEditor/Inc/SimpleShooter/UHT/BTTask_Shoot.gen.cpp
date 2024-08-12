// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTTask_Shoot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_Shoot() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_Shoot();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_Shoot_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTTask_Shoot::StaticRegisterNativesUBTTask_Shoot()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_Shoot);
	UClass* Z_Construct_UClass_UBTTask_Shoot_NoRegister()
	{
		return UBTTask_Shoot::StaticClass();
	}
	struct Z_Construct_UClass_UBTTask_Shoot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTTask_Shoot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Shoot_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTTask_Shoot_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTTask_Shoot.h" },
		{ "ModuleRelativePath", "Public/AI/BTTask_Shoot.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTTask_Shoot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_Shoot>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_Shoot_Statics::ClassParams = {
		&UBTTask_Shoot::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Shoot_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_Shoot_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTTask_Shoot()
	{
		if (!Z_Registration_Info_UClass_UBTTask_Shoot.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_Shoot.OuterSingleton, Z_Construct_UClass_UBTTask_Shoot_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTTask_Shoot.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTTask_Shoot>()
	{
		return UBTTask_Shoot::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_Shoot);
	UBTTask_Shoot::~UBTTask_Shoot() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Shoot_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Shoot_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_Shoot, UBTTask_Shoot::StaticClass, TEXT("UBTTask_Shoot"), &Z_Registration_Info_UClass_UBTTask_Shoot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_Shoot), 2641402877U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Shoot_h_2407535603(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Shoot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Shoot_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
