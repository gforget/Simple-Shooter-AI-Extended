// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/Public/AI/BTDecorator_FloatLowerOrEqual.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_FloatLowerOrEqual() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTDecorator_BlackboardBase();
	AIMODULE_API UEnum* Z_Construct_UEnum_AIModule_EBTBlackboardRestart();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References
	void UBTDecorator_FloatLowerOrEqual::StaticRegisterNativesUBTDecorator_FloatLowerOrEqual()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTDecorator_FloatLowerOrEqual);
	UClass* Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_NoRegister()
	{
		return UBTDecorator_FloatLowerOrEqual::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NotifyObserver_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_NotifyObserver;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator_BlackboardBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTDecorator_FloatLowerOrEqual.h" },
		{ "ModuleRelativePath", "Public/AI/BTDecorator_FloatLowerOrEqual.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_TargetValue_MetaData[] = {
		{ "Category", "BTDecorator_FloatLowerOrEqual" },
		{ "ModuleRelativePath", "Public/AI/BTDecorator_FloatLowerOrEqual.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_TargetValue = { "TargetValue", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTDecorator_FloatLowerOrEqual, TargetValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_TargetValue_MetaData), Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_TargetValue_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_NotifyObserver_MetaData[] = {
		{ "Category", "FlowControl" },
		{ "ModuleRelativePath", "Public/AI/BTDecorator_FloatLowerOrEqual.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_NotifyObserver = { "NotifyObserver", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTDecorator_FloatLowerOrEqual, NotifyObserver), Z_Construct_UEnum_AIModule_EBTBlackboardRestart, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_NotifyObserver_MetaData), Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_NotifyObserver_MetaData) }; // 2971343514
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_TargetValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::NewProp_NotifyObserver,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_FloatLowerOrEqual>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::ClassParams = {
		&UBTDecorator_FloatLowerOrEqual::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual()
	{
		if (!Z_Registration_Info_UClass_UBTDecorator_FloatLowerOrEqual.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTDecorator_FloatLowerOrEqual.OuterSingleton, Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTDecorator_FloatLowerOrEqual.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<UBTDecorator_FloatLowerOrEqual>()
	{
		return UBTDecorator_FloatLowerOrEqual::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_FloatLowerOrEqual);
	UBTDecorator_FloatLowerOrEqual::~UBTDecorator_FloatLowerOrEqual() {}
	struct Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTDecorator_FloatLowerOrEqual_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTDecorator_FloatLowerOrEqual_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTDecorator_FloatLowerOrEqual, UBTDecorator_FloatLowerOrEqual::StaticClass, TEXT("UBTDecorator_FloatLowerOrEqual"), &Z_Registration_Info_UClass_UBTDecorator_FloatLowerOrEqual, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTDecorator_FloatLowerOrEqual), 4022990842U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTDecorator_FloatLowerOrEqual_h_4038205809(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTDecorator_FloatLowerOrEqual_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTDecorator_FloatLowerOrEqual_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
