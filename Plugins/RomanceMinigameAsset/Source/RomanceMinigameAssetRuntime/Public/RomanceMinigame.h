#pragma once
#include "CoreMinimal.h"
#include "RomanceMinigame.generated.h"

//Object Type Enum
UENUM(BlueprintType)
enum class EObjectType : uint8
{
	//Null Object
	Null,
	RedBomb,
	//Sleepy Bomb You need to sneek past it or it will explode
	OrangeBomb,
	//Super Bomb has a larger detonation radius and is persistent even after detonation
	BlueBomb,
	//You can only see where it is at the begining and while holding a button that also locks imput, they are 
	HiddenBomb,
	//These bombs move around and are green
	MovingBomb,
	//These bombs Freeze the pinata when they explode for a short time
	WhiteBomb,
	//OilBomb that makes the pinata slide for a short time (Has to have a cowboy hat)
	BrownBomb,
	//These bombs make the pinata move in the opposite direction for a short time
	PurpleBomb,
	//These bombs force the pinata move faster for a short time (Good for speed runs)
	YellowBomb,
	//These bombs make smoke obscuring the players vision for a breef time
	BlackBomb,
	//Magnetic bombs that will pull the player towards them
	GrayBomb,
	//These bombs are 2D and look like a shadow with the loather face, it will move in the direction of the player slowly then pop out of the ground and explode.
	ShadowBomb,
	//Pink bombs destracts the end pinata make makes them follow
	PinkBomb,
	//Collectable that you need to collect to obtain master romancer
	Heart,
	//Gives the player 10 coin
	Coins_T1, 
	//Gives the player 50 coins
	Coins_T2, 
	//Gives the player 100 coins
	Coins_T3, 
	//Gives the player 200 coins
	Coins_T4, 
	//Where the player starts
	Spawner, 
	//End of the the level
	Exit
};

//Location Enum
UENUM(BlueprintType)
enum class ELocation : uint8
{
	LandGarden,
	SeaGarden,
	SnowGarden,
	DesertGarden,
	JungleGarden,
	TrenchGarden
};

USTRUCT(BlueprintType)
struct FMinigameObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EObjectType ObjectType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rotation;
};

UCLASS(BlueprintType)
class ROMANCEMINIGAMEASSETRUNTIME_API URomanceMinigame : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FMinigameObject> Objects;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELocation Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeLimit; //Time limit in seconds
};