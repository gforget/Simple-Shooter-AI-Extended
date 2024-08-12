// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_UpdateAmmoInGunPercent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_UpdateAmmoInGunPercent() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService_BlackboardBase();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTService_UpdateAmmoInGunPercent::StaticRegisterNativesUBTService_UpdateAmmoInGunPercent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_UpdateAmmoInGunPercent);
	UClass* Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_NoRegister()
	{
		return UBTService_UpdateAmmoInGunPercent::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_UpdateAmmoInGunPercent.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_UpdateAmmoInGunPercent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_UpdateAmmoInGunPercent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::ClassParams = {
		&UBTService_UpdateAmmoInGunPercent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent()
	{
		if (!Z_Registration_Info_UClass_UBTService_UpdateAmmoInGunPercent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_UpdateAmmoInGunPercent.OuterSingleton, Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_UpdateAmmoInGunPercent.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_UpdateAmmoInGunPercent>()
	{
		return UBTService_UpdateAmmoInGunPercent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_UpdateAmmoInGunPercent);
	UBTService_UpdateAmmoInGunPercent::~UBTService_UpdateAmmoInGunPercent() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateAmmoInGunPercent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateAmmoInGunPercent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_UpdateAmmoInGunPercent, UBTService_UpdateAmmoInGunPercent::StaticClass, TEXT("UBTService_UpdateAmmoInGunPercent"), &Z_Registration_Info_UClass_UBTService_UpdateAmmoInGunPercent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_UpdateAmmoInGunPercent), 843066297U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateAmmoInGunPercent_h_3433480088(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateAmmoInGunPercent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UpdateAmmoInGunPercent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
