// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_DebugPath.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_DebugPath() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_DebugPath();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_DebugPath_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTService_DebugPath::StaticRegisterNativesUBTService_DebugPath()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_DebugPath);
	UClass* Z_Construct_UClass_UBTService_DebugPath_NoRegister()
	{
		return UBTService_DebugPath::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_DebugPath_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_DebugPath_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_DebugPath_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_DebugPath_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_DebugPath.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_DebugPath.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_DebugPath_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_DebugPath>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_DebugPath_Statics::ClassParams = {
		&UBTService_DebugPath::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_DebugPath_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_DebugPath_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTService_DebugPath()
	{
		if (!Z_Registration_Info_UClass_UBTService_DebugPath.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_DebugPath.OuterSingleton, Z_Construct_UClass_UBTService_DebugPath_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_DebugPath.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_DebugPath>()
	{
		return UBTService_DebugPath::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_DebugPath);
	UBTService_DebugPath::~UBTService_DebugPath() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_DebugPath_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_DebugPath_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_DebugPath, UBTService_DebugPath::StaticClass, TEXT("UBTService_DebugPath"), &Z_Registration_Info_UClass_UBTService_DebugPath, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_DebugPath), 1818831826U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_DebugPath_h_2303890697(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_DebugPath_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_DebugPath_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
