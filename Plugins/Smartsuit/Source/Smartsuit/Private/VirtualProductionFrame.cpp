// Copyright 2019 Rokoko Electronics. All Rights Reserved.

#include "VirtualProductionFrame.h"
#include "SmartsuitBlueprintLibrary.h"

VirtualProductionFrame::VirtualProductionFrame()
{
}

VirtualProductionFrame::~VirtualProductionFrame()
{
}

FProp::FProp(bool InIsLive, TSharedPtr<FJsonObject> jsonObject)
{
	name = jsonObject->GetStringField("name");
	color = USmartsuitBlueprintLibrary::GetColorField(jsonObject);
	position = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("position"));
	rotation = USmartsuitBlueprintLibrary::GetQuaternionField(jsonObject->GetObjectField("rotation"));
	
	isLive = InIsLive;
}

FProfile::FProfile(TSharedPtr<FJsonObject> jsonObject)
{
	name = jsonObject->GetStringField("name");
	uuid = jsonObject->GetStringField("uuid");
	dimensions = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("dimensions"));
	color = USmartsuitBlueprintLibrary::GetFLinearColorField(jsonObject->GetObjectField("color"));
	trackerOffset = FReferencePoint(jsonObject->GetObjectField("trackeroffset"));
	pivot = FReferencePoint(jsonObject->GetObjectField("pivot"));

	TArray<TSharedPtr<FJsonValue>> gripsarray = jsonObject->GetArrayField("grips");

	for (auto currentgrip : gripsarray)
	{
		grips.Add(FRadiusReferencePoint(currentgrip->AsObject()));
	}

	propType = jsonObject->GetIntegerField("propType");
}

FReferencePoint::FReferencePoint(TSharedPtr<FJsonObject> jsonObject)
{
	position = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("position"));

	FVector TempVector = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("rotation"));
	rotation = TempVector.Rotation().Quaternion();
}

FRadiusReferencePoint::FRadiusReferencePoint(TSharedPtr<FJsonObject> jsonObject)
{
	radius = jsonObject->GetNumberField("radius");
	position = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("position"));
	rotation = USmartsuitBlueprintLibrary::GetQuaternionField(jsonObject->GetObjectField("rotation"));
}

FTracker::FTracker(TSharedPtr<FJsonObject> jsonObject)
{
	name = jsonObject->GetStringField("name");
	connectionId = jsonObject->GetStringField("connectionId");
	position = USmartsuitBlueprintLibrary::GetVectorField(jsonObject->GetObjectField("position"));
	rotation = USmartsuitBlueprintLibrary::GetQuaternionField(jsonObject->GetObjectField("rotation"));
	isLive = jsonObject->GetBoolField("isLive");
	trackingResult = jsonObject->GetIntegerField("trackingResult");
	trackerType = jsonObject->GetIntegerField("trackerType");
	RenderModelName = jsonObject->GetStringField("RenderModelName");
	battery = jsonObject->GetNumberField("battery");
}


FFace::FFace(const FFace& otherFace)
	: profileName(otherFace.profileName)
	, version(otherFace.version)
	, provider(otherFace.provider)
	, faceId(otherFace.faceId)
	, actorName(otherFace.actorName)
	, eyeBlinkLeft(otherFace.eyeBlinkLeft)
	, eyeLookDownLeft(otherFace.eyeLookDownLeft)
	, eyeLookInLeft(otherFace.eyeLookInLeft)
	, eyeLookOutLeft(otherFace.eyeLookOutLeft)
	, eyeLookUpLeft(otherFace.eyeLookUpLeft)
	, eyeSquintLeft(otherFace.eyeSquintLeft)
	, eyeWideLeft(otherFace.eyeWideLeft)
	, eyeBlinkRight(otherFace.eyeBlinkRight)
	, eyeLookDownRight(otherFace.eyeLookDownRight)
	, eyeLookInRight(otherFace.eyeLookInRight)
	, eyeLookOutRight(otherFace.eyeLookOutRight)
	, eyeLookUpRight(otherFace.eyeLookUpRight)
	, eyeSquintRight(otherFace.eyeSquintRight)
	, eyeWideRight(otherFace.eyeWideRight)
	, jawForward(otherFace.jawForward)
	, jawLeft(otherFace.jawLeft)
	, jawRight(otherFace.jawRight)
	, jawOpen(otherFace.jawOpen)
	, mouthClose(otherFace.mouthClose)
	, mouthFunnel(otherFace.mouthFunnel)
	, mouthPucker(otherFace.mouthPucker)
	, mouthLeft(otherFace.mouthLeft)
	, mouthRight(otherFace.mouthRight)
	, mouthSmileLeft(otherFace.mouthSmileLeft)
	, mouthSmileRight(otherFace.mouthSmileRight)
	, mouthFrownLeft(otherFace.mouthFrownLeft)
	, mouthFrownRight(otherFace.mouthFrownRight)
	, mouthDimpleLeft(otherFace.mouthDimpleLeft)
	, mouthDimpleRight(otherFace.mouthDimpleRight)
	, mouthStretchLeft(otherFace.mouthStretchLeft)
	, mouthStretchRight(otherFace.mouthStretchRight)
	, mouthRollLower(otherFace.mouthRollLower)
	, mouthRollUpper(otherFace.mouthRollUpper)
	, mouthShrugLower(otherFace.mouthShrugLower)
	, mouthShrugUpper(otherFace.mouthShrugUpper)
	, mouthPressLeft(otherFace.mouthPressLeft)
	, mouthPressRight(otherFace.mouthPressRight)
	, mouthLowerDownLeft(otherFace.mouthLowerDownLeft)
	, mouthLowerDownRight(otherFace.mouthLowerDownRight)
	, mouthUpperUpLeft(otherFace.mouthUpperUpLeft)
	, mouthUpperUpRight(otherFace.mouthUpperUpRight)
	, browDownLeft(otherFace.browDownLeft)
	, browDownRight(otherFace.browDownRight)
	, browInnerUp(otherFace.browInnerUp)
	, browOuterUpLeft(otherFace.browOuterUpLeft)
	, browOuterUpRight(otherFace.browOuterUpRight)
	, cheekPuff(otherFace.cheekPuff)
	, cheekSquintLeft(otherFace.cheekSquintLeft)
	, cheekSquintRight(otherFace.cheekSquintRight)
	, noseSneerLeft(otherFace.noseSneerLeft)
	, noseSneerRight(otherFace.noseSneerRight)
	, tongueOut(otherFace.tongueOut)
{
}

FFace::FFace(FFace&& otherFace)
	: profileName(MoveTemp(otherFace.profileName))
	, version(otherFace.version)
	, provider(MoveTemp(otherFace.provider))	
	, faceId(MoveTemp(otherFace.faceId))
	, actorName(MoveTemp(otherFace.actorName))
	, eyeBlinkLeft(otherFace.eyeBlinkLeft)
	, eyeLookDownLeft(otherFace.eyeLookDownLeft)
	, eyeLookInLeft(otherFace.eyeLookInLeft)
	, eyeLookOutLeft(otherFace.eyeLookOutLeft)
	, eyeLookUpLeft(otherFace.eyeLookUpLeft)
	, eyeSquintLeft(otherFace.eyeSquintLeft)
	, eyeWideLeft(otherFace.eyeWideLeft)
	, eyeBlinkRight(otherFace.eyeBlinkRight)
	, eyeLookDownRight(otherFace.eyeLookDownRight)
	, eyeLookInRight(otherFace.eyeLookInRight)
	, eyeLookOutRight(otherFace.eyeLookOutRight)
	, eyeLookUpRight(otherFace.eyeLookUpRight)
	, eyeSquintRight(otherFace.eyeSquintRight)
	, eyeWideRight(otherFace.eyeWideRight)
	, jawForward(otherFace.jawForward)
	, jawLeft(otherFace.jawLeft)
	, jawRight(otherFace.jawRight)
	, jawOpen(otherFace.jawOpen)
	, mouthClose(otherFace.mouthClose)
	, mouthFunnel(otherFace.mouthFunnel)
	, mouthPucker(otherFace.mouthPucker)
	, mouthLeft(otherFace.mouthLeft)
	, mouthRight(otherFace.mouthRight)
	, mouthSmileLeft(otherFace.mouthSmileLeft)
	, mouthSmileRight(otherFace.mouthSmileRight)
	, mouthFrownLeft(otherFace.mouthFrownLeft)
	, mouthFrownRight(otherFace.mouthFrownRight)
	, mouthDimpleLeft(otherFace.mouthDimpleLeft)
	, mouthDimpleRight(otherFace.mouthDimpleRight)
	, mouthStretchLeft(otherFace.mouthStretchLeft)
	, mouthStretchRight(otherFace.mouthStretchRight)
	, mouthRollLower(otherFace.mouthRollLower)
	, mouthRollUpper(otherFace.mouthRollUpper)
	, mouthShrugLower(otherFace.mouthShrugLower)
	, mouthShrugUpper(otherFace.mouthShrugUpper)
	, mouthPressLeft(otherFace.mouthPressLeft)
	, mouthPressRight(otherFace.mouthPressRight)
	, mouthLowerDownLeft(otherFace.mouthLowerDownLeft)
	, mouthLowerDownRight(otherFace.mouthLowerDownRight)
	, mouthUpperUpLeft(otherFace.mouthUpperUpLeft)
	, mouthUpperUpRight(otherFace.mouthUpperUpRight)
	, browDownLeft(otherFace.browDownLeft)
	, browDownRight(otherFace.browDownRight)
	, browInnerUp(otherFace.browInnerUp)
	, browOuterUpLeft(otherFace.browOuterUpLeft)
	, browOuterUpRight(otherFace.browOuterUpRight)
	, cheekPuff(otherFace.cheekPuff)
	, cheekSquintLeft(otherFace.cheekSquintLeft)
	, cheekSquintRight(otherFace.cheekSquintRight)
	, noseSneerLeft(otherFace.noseSneerLeft)
	, noseSneerRight(otherFace.noseSneerRight)
	, tongueOut(otherFace.tongueOut)
{
}

FFace::FFace(TSharedPtr<FJsonObject> jsonObject, const FString& InActorName)
{
	faceId = InActorName;
	actorName = InActorName;
	if (!jsonObject->TryGetStringField("profileName", profileName))
	{
		profileName = "NOPROFILENAME for " + faceId;
	}

	constexpr float scale{ 0.01f };

	eyeBlinkLeft = jsonObject->GetNumberField("eyeBlinkLeft") * scale;
	eyeLookDownLeft = jsonObject->GetNumberField("eyeLookDownLeft") * scale;
	eyeLookInLeft = jsonObject->GetNumberField("eyeLookInLeft") * scale;
	eyeLookOutLeft = jsonObject->GetNumberField("eyeLookOutLeft") * scale;
	eyeLookUpLeft = jsonObject->GetNumberField("eyeLookUpLeft") * scale;
	eyeSquintLeft = jsonObject->GetNumberField("eyeSquintLeft") * scale;
	eyeWideLeft = jsonObject->GetNumberField("eyeWideLeft") * scale;
	eyeBlinkRight = jsonObject->GetNumberField("eyeBlinkRight") * scale;
	eyeLookDownRight = jsonObject->GetNumberField("eyeLookDownRight") * scale;
	eyeLookInRight = jsonObject->GetNumberField("eyeLookInRight") * scale;
	eyeLookOutRight = jsonObject->GetNumberField("eyeLookOutRight") * scale;
	eyeLookUpRight = jsonObject->GetNumberField("eyeLookUpRight") * scale;
	eyeSquintRight = jsonObject->GetNumberField("eyeSquintRight") * scale;
	eyeWideRight = jsonObject->GetNumberField("eyeWideRight") * scale;
	jawForward = jsonObject->GetNumberField("jawForward") * scale;
	jawLeft = jsonObject->GetNumberField("jawLeft") * scale;
	jawRight = jsonObject->GetNumberField("jawRight") * scale;
	jawOpen = jsonObject->GetNumberField("jawOpen") * scale;
	mouthClose = jsonObject->GetNumberField("mouthClose") * scale;
	mouthFunnel = jsonObject->GetNumberField("mouthFunnel") * scale;
	mouthPucker = jsonObject->GetNumberField("mouthPucker") * scale;
	mouthLeft = jsonObject->GetNumberField("mouthLeft") * scale;
	mouthRight = jsonObject->GetNumberField("mouthRight") * scale;
	mouthSmileLeft = jsonObject->GetNumberField("mouthSmileLeft") * scale;
	mouthSmileRight = jsonObject->GetNumberField("mouthSmileRight") * scale;
	mouthFrownLeft = jsonObject->GetNumberField("mouthFrownLeft") * scale;
	mouthFrownRight = jsonObject->GetNumberField("mouthFrownRight") * scale;
	mouthDimpleLeft = jsonObject->GetNumberField("mouthDimpleLeft") * scale;
	mouthDimpleRight = jsonObject->GetNumberField("mouthDimpleRight") * scale;
	mouthStretchLeft = jsonObject->GetNumberField("mouthStretchLeft") * scale;
	mouthStretchRight = jsonObject->GetNumberField("mouthStretchRight") * scale;
	mouthRollLower = jsonObject->GetNumberField("mouthRollLower") * scale;
	mouthRollUpper = jsonObject->GetNumberField("mouthRollUpper") * scale;
	mouthShrugLower = jsonObject->GetNumberField("mouthShrugLower") * scale;
	mouthShrugUpper = jsonObject->GetNumberField("mouthShrugUpper") * scale;
	mouthPressLeft = jsonObject->GetNumberField("mouthPressLeft") * scale;
	mouthPressRight = jsonObject->GetNumberField("mouthPressRight") * scale;
	mouthLowerDownLeft = jsonObject->GetNumberField("mouthLowerDownLeft") * scale;
	mouthLowerDownRight = jsonObject->GetNumberField("mouthLowerDownRight") * scale;
	mouthUpperUpLeft = jsonObject->GetNumberField("mouthUpperUpLeft") * scale;
	mouthUpperUpRight = jsonObject->GetNumberField("mouthUpperUpRight") * scale;
	browDownLeft = jsonObject->GetNumberField("browDownLeft") * scale;
	browDownRight = jsonObject->GetNumberField("browDownRight") * scale;
	browInnerUp = jsonObject->GetNumberField("browInnerUp") * scale;
	browOuterUpLeft = jsonObject->GetNumberField("browOuterUpLeft") * scale;
	browOuterUpRight = jsonObject->GetNumberField("browOuterUpRight") * scale;
	cheekPuff = jsonObject->GetNumberField("cheekPuff") * scale;
	cheekSquintLeft = jsonObject->GetNumberField("cheekSquintLeft") * scale;
	cheekSquintRight = jsonObject->GetNumberField("cheekSquintRight") * scale;
	noseSneerLeft = jsonObject->GetNumberField("noseSneerLeft") * scale;
	noseSneerRight = jsonObject->GetNumberField("noseSneerRight") * scale;
	tongueOut = jsonObject->GetNumberField("tongueOut") * scale;
}
