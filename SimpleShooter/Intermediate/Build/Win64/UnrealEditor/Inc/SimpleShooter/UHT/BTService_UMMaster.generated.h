// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/BTService_UMMaster.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLESHOOTER_BTService_UMMaster_generated_h
#error "BTService_UMMaster.generated.h already included, missing '#pragma once' in BTService_UMMaster.h"
#endif
#define SIMPLESHOOTER_BTService_UMMaster_generated_h

#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_SPARSE_DATA
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_ACCESSORS
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBTService_UMMaster(); \
	friend struct Z_Construct_UClass_UBTService_UMMaster_Statics; \
public: \
	DECLARE_CLASS(UBTService_UMMaster, UBTService_BlackboardBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(UBTService_UMMaster)


#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBTService_UMMaster(UBTService_UMMaster&&); \
	NO_API UBTService_UMMaster(const UBTService_UMMaster&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBTService_UMMaster); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBTService_UMMaster); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UBTService_UMMaster) \
	NO_API virtual ~UBTService_UMMaster();


#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_29_PROLOG
#define FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_SPARSE_DATA \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_ACCESSORS \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_INCLASS_NO_PURE_DECLS \
	FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLESHOOTER_API UClass* StaticClass<class UBTService_UMMaster>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Gabriel_Unreal_Project_SimpleShooterAIExtendedGit_SimpleShooter_Source_SimpleShooter_Public_AI_BTService_UMMaster_h


#define FOREACH_ENUM_EAISTATEENUM(op) \
	op(Flee) \
	op(LookForHealthPack) \
	op(LookForAmmo) \
	op(EngageEnemy) \
	op(Explore) \
	op(None) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
