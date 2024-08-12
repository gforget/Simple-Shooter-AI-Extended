// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_TestPathLength.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_TestPathLength() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_TestPathLength();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_TestPathLength_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTService_TestPathLength::StaticRegisterNativesUBTService_TestPathLength()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_TestPathLength);
	UClass* Z_Construct_UClass_UBTService_TestPathLength_NoRegister()
	{
		return UBTService_TestPathLength::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_TestPathLength_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_TestPathLength_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_TestPathLength_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_TestPathLength_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_TestPathLength.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_TestPathLength.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_TestPathLength_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_TestPathLength>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_TestPathLength_Statics::ClassParams = {
		&UBTService_TestPathLength::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_TestPathLength_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_TestPathLength_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTService_TestPathLength()
	{
		if (!Z_Registration_Info_UClass_UBTService_TestPathLength.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_TestPathLength.OuterSingleton, Z_Construct_UClass_UBTService_TestPathLength_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_TestPathLength.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_TestPathLength>()
	{
		return UBTService_TestPathLength::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_TestPathLength);
	UBTService_TestPathLength::~UBTService_TestPathLength() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_TestPathLength_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_TestPathLength_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_TestPathLength, UBTService_TestPathLength::StaticClass, TEXT("UBTService_TestPathLength"), &Z_Registration_Info_UClass_UBTService_TestPathLength, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_TestPathLength), 696321957U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_TestPathLength_h_492301692(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_TestPathLength_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_TestPathLength_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
