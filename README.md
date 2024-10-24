![Screenshot of the projectt](/Screenshot/ProjectHeader.png)</BR>
# Simple Shooter - AIExtended
This project is an extension of the final exercise, 'Simple Shooter,' from the GameDev.TV course 'UE5 C++ Developer: Code Your Own Unreal Games.' It primarily focuses on adding new gameplay mechanics, an original map, and improved AI to the project, similar to what you would expect in a AAA shooter game. The AI acts as a bot that could replace players in a multiplayer match and has the same power and goals as them: to eliminate all other players on the map and be the last survivor. The game also support a team mode (blue vs red) and the goal is to eleminate all member of the enemy team.

# Differences with the original result of the exercice
## Gameplay mechanic
- Added a reload mechanic with an additive animation (the animation was provided with the character, but it had to be modified and implemented to work properly).
- The primary weapon now functions as an automatic weapon, rather than requiring a click for each shot.
- Bullets now spread from the gun with a custom radius, simulating the behavior of an automatic weapon, rather than always hitting the same point.
- Added health packs that the player or the bot can use to heal themselves.
- Added ammo packs that the player or the bot can use to reload their weapon.
- Added Overhead healthbar on the bots so the player know how hurt it is
- Added the notion of team and adapted the victory condition
- Spectator mode when you die and also to watch AI fight each other by default

## AI improvement
- The bot can explore the entire map rather than being limited to a spawn point.
- The bot uses a custom cone of vision and stimuli system to react to senses that would be common to a human player (sight and hearing).
- The bot now has aiming properties, so it doesn't have 100% accuracy. It has an aiming speed and a custom general aim offset that makes it fair to play against.
- The bot now uses Utility AI principles within its Behavior Tree to decide what general strategy it should use at the moment (engage the player, flee from the player, collect health packs, collect ammo, or explore the map).
- The bot can shoot and reload while moving, just like a player.
- The bot calculate engagement position so it know how to approach an enemy. It will shoot from high ground and try to never stay at the same place to make it harder to shoot at
- The bot rotates more naturally, rather than instantly rotating toward its objective.
- The bot recognize who is his ally and who is his enemy, although it is not program to work as a team for now (it will simply be not hostile to member of it own team)
- The bot can now jump from ledges when it is appropriate using a custom NavLink that use the same jump mechanic as the player

## New map
- A new map was created to allow for shooting from high ground and offer more space to fight in. It is also much lighter than the original exercise map.

## What was retained from the exercice
- The core third-person controller was retained (75% of the animation blueprint and the code for the ShooterCharacter class for the main character remain the same).
- The character mesh and textures were all kept as is.
- The sound effects of the gun.
- Particules effect of the gun.
- The gun itself
- The character animations were cleaned up to reduce the overall project size.
  
## Disclaimer
<b>The current version of this project is not finished, and development is still ongoing. The current presentation is mainly to showcase what has already been done and how it has been implemented.</b>

# Useful link

## Videos 
Video Update 2 (Bots fighting each other updated and player vs bot):</br>
https://youtu.be/L5gJRhCyYng</br>

Video Update 1 (Bots fighting each other):</br>
https://youtu.be/YsJn5pIpbIA</br>

Video Introduction: </br>
https://youtu.be/gmx63PSk-uE
  
## Link to the game course
https://www.gamedev.tv/courses/unreal-5-0-c-developer-learn-c-and-make-video-games
