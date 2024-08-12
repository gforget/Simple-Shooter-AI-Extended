// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTService_Shoot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_Shoot() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_Shoot();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_Shoot_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTService_Shoot::StaticRegisterNativesUBTService_Shoot()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_Shoot);
	UClass* Z_Construct_UClass_UBTService_Shoot_NoRegister()
	{
		return UBTService_Shoot::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_Shoot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AimOffset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_Shoot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Shoot_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_Shoot_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_Shoot.h" },
		{ "ModuleRelativePath", "Public/AI/BTService_Shoot.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_Shoot_Statics::NewProp_AimOffset_MetaData[] = {
		{ "Category", "BTService_Shoot" },
		{ "ModuleRelativePath", "Public/AI/BTService_Shoot.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_Shoot_Statics::NewProp_AimOffset = { "AimOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_Shoot, AimOffset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Shoot_Statics::NewProp_AimOffset_MetaData), Z_Construct_UClass_UBTService_Shoot_Statics::NewProp_AimOffset_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTService_Shoot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_Shoot_Statics::NewProp_AimOffset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_Shoot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_Shoot>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_Shoot_Statics::ClassParams = {
		&UBTService_Shoot::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBTService_Shoot_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Shoot_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Shoot_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_Shoot_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_Shoot_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBTService_Shoot()
	{
		if (!Z_Registration_Info_UClass_UBTService_Shoot.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_Shoot.OuterSingleton, Z_Construct_UClass_UBTService_Shoot_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_Shoot.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_Shoot>()
	{
		return UBTService_Shoot::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_Shoot);
	UBTService_Shoot::~UBTService_Shoot() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_Shoot_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_Shoot_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_Shoot, UBTService_Shoot::StaticClass, TEXT("UBTService_Shoot"), &Z_Registration_Info_UClass_UBTService_Shoot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_Shoot), 3814639094U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_Shoot_h_1534696983(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_Shoot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_Shoot_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
