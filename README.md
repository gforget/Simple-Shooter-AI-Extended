# Simple Shooter - AIExtended
This project is an extension of the final exercice 'Simple Shooter' of the GameDev.TV course 'UE5 C++ Developer: Code Your Own Unreal Games'. It mainly focus on adding new gameplay mechanic , an original map and an improved AI to the project that could be in a AAA shooter game. The AI act as a bot that could replace players in a multiplayer match and have the same power and goal as them, which is to eleminate all the other player in the map and be the last survivor. 

# Difference with the original result of the exercice
## Gameplay mechanic
- Added a reload mechanic with an additive animation (the animation was already provided with the provided character, but had to be modified and implemented to work properly)
- Made the primary weapon act like an automatic weapon, rather than having shoot one bullet per click
- Bullet now spread from the gun with a custom radius rather than always shoot at the same point, like an automatic weapon would behave
- Added health pact that the player or the bot can use to heal themself.

## AI improvement
- The bot can explore the whole map rather than being limited to a spawn point
- The bot use a custom cone of vision and stimuli system so that it react to senses that would be common to human player (Sight and hearing)
- The bot now have aimin properties so it doesn't have 100% accuracy. It has an aiming speed and a custom general aimoffset that make it fair to play against
- The bot now uses Utility AI principal within it Behaviour Tree to decide what general strategy it should use at the current moment (engaged the player, flee from the player, collect health pack, collect ammo or explore the map)
- The bot can shoot and reload while moving, like a player can do
- The bot rotate in a more natural manner rather than immediately rotate toward what is it objective.

## New map
- A new map was created so that it is possible to shoot from the high ground and offer more space to fight in. It is also much lighter than the original exercice map.

# What was kept from the exercice
- The core third person controller was kept (75% of the animation blueprint and the code for ShooterCharacter class for the main character remain the same)
- The character mesh and textures were all kept
- The sound effect of the gun
- The animation of the character were cleaned out so the overall project would weight less

## Disclaimer
<b>The current version of this project is not finished and development is still ongoing, the current presentation is mainly to showcase what already had been done and the way it is implemented </b>

## Useful link

### Introduction

Initial Presentation:</br>
<i> coming soon </i>

### Link to the game course
https://www.gamedev.tv/courses/unreal-5-0-c-developer-learn-c-and-make-video-games
