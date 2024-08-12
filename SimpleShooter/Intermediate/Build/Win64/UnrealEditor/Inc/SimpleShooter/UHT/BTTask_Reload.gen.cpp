// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTTask_Reload.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_Reload() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_Reload();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_Reload_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTTask_Reload::StaticRegisterNativesUBTTask_Reload()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_Reload);
	UClass* Z_Construct_UClass_UBTTask_Reload_NoRegister()
	{
		return UBTTask_Reload::StaticClass();
	}
	struct Z_Construct_UClass_UBTTask_Reload_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTTask_Reload_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Reload_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTTask_Reload_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTTask_Reload.h" },
		{ "ModuleRelativePath", "Public/AI/BTTask_Reload.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTTask_Reload_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_Reload>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_Reload_Statics::ClassParams = {
		&UBTTask_Reload::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_Reload_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_Reload_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTTask_Reload()
	{
		if (!Z_Registration_Info_UClass_UBTTask_Reload.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_Reload.OuterSingleton, Z_Construct_UClass_UBTTask_Reload_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTTask_Reload.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTTask_Reload>()
	{
		return UBTTask_Reload::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_Reload);
	UBTTask_Reload::~UBTTask_Reload() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Reload_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Reload_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_Reload, UBTTask_Reload::StaticClass, TEXT("UBTTask_Reload"), &Z_Registration_Info_UClass_UBTTask_Reload, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_Reload), 3254346697U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Reload_h_1352816353(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Reload_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_Reload_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
