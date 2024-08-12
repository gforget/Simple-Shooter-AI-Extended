// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTTask_ChooseAmmoPack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_ChooseAmmoPack() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_BlackboardBase();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_ChooseAmmoPack();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTTask_ChooseAmmoPack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTTask_ChooseAmmoPack::StaticRegisterNativesUBTTask_ChooseAmmoPack()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_ChooseAmmoPack);
	UClass* Z_Construct_UClass_UBTTask_ChooseAmmoPack_NoRegister()
	{
		return UBTTask_ChooseAmmoPack::StaticClass();
	}
	struct Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTask_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTTask_ChooseAmmoPack.h" },
		{ "ModuleRelativePath", "Public/AI/BTTask_ChooseAmmoPack.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_ChooseAmmoPack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::ClassParams = {
		&UBTTask_ChooseAmmoPack::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTTask_ChooseAmmoPack()
	{
		if (!Z_Registration_Info_UClass_UBTTask_ChooseAmmoPack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_ChooseAmmoPack.OuterSingleton, Z_Construct_UClass_UBTTask_ChooseAmmoPack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTTask_ChooseAmmoPack.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTTask_ChooseAmmoPack>()
	{
		return UBTTask_ChooseAmmoPack::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_ChooseAmmoPack);
	UBTTask_ChooseAmmoPack::~UBTTask_ChooseAmmoPack() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_ChooseAmmoPack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_ChooseAmmoPack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_ChooseAmmoPack, UBTTask_ChooseAmmoPack::StaticClass, TEXT("UBTTask_ChooseAmmoPack"), &Z_Registration_Info_UClass_UBTTask_ChooseAmmoPack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_ChooseAmmoPack), 730718245U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_ChooseAmmoPack_h_1763410203(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_ChooseAmmoPack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTTask_ChooseAmmoPack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
