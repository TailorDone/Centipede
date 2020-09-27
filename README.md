<h1> Centipede </h1>
<h2> CS6010 Final Project </h2>

## Project Description
<p>
  <ul>
    <li><b>The Prompt:</b> "Create a game using CMake that includes the SFML library." </li>
    <li><b>The Set-Up:</b> 4 weeks into our Intro to Software Development Course, we were assigned this final project. This project was created by Taylor Dunn and Tyler Speegle. Assigned on Monday, due on Friday, we are incredibly happy with our final result! </li>
    <li><b>The Tools:</b> This project was created in XCode using C++ with use of CMake and the terminal to run and compile the project. This project involed pair-programming through Zoom.</li> 
    <li><b>The Idea:</b> As we brainstormed games we wanted to create we ultimately landed on a Centipede remake. We wanted a project that would test our logic on movement, collisions, removal of objects, changing states of objects, and different windows (start, game over, new level).</li>
  </ul>
 </p>
 
 ## GamePlay
 <p>
  <ul>
    <li><b>Game Mechanics:</b> Upon launch the player will see a press enter screen. Press enter to start the game. The centipede will begin moving towards the player moving from left to right zig-zagging down the screen. When the centipede hits a wall or a mushroom the centipede will move down a row closer to the player and change direction.Your goal as the player is to shoot the blue head of the centipede. Each successful hit of the head will remove a section of the centipede from the end. You may also shoot mushrooms 3 times to try and clear the screen so you have longer for the centipede to reach the bottom. If you successfully hit the centipede enough times to remove all of the centipede segments you will see a "You Win" screen. Press enter again to start the next level, which will spawn more mushrooms on top of any mushrooms you left behind in the previous level as well as add 2 more segments to the centipede. The game ends if the centipede reaches the player row before the player can shoot all the segments.</li>
   <li><b>Controls:</b> Use the left and right arrow keys to navigate your ship. Press space bar to shoot bullets upwards. Press enter to begin the game or start the next level. Press the exit button of the window to end the game at any time.</li>
  </ul>
</p>

## GamePreview
<p align="center">
  <img src=https://media.giphy.com/media/mbOv2fpjfWj7ZRwa7k/giphy.gif>
</p>

## Additional Information
<p>
  <ul>
    <li><b>Testing:</b> Due to cancelled class days from a windstorm the testing portion of the project was removed so this project was not through TDD. Although that was the case we know that testing is an integral part of the coding process. Although not a requirement, we decided to install and use the Catch testing library for the few tests that we wrote. 
    <li><b>The Challenges:</b> For those of you familiar with Centipede, you'll see some differences between the original game and our own. Due to the time crunch of the project we had to make some decisions on how our game would differ from the original game. We decided that the player would only be able to shoot the head and we would remove the end of the centipede when the head was shot. We decided not to spawn a mushroom when the head was shot. We also ran into issues with adjacent mushrooms as well as veritcally placed mushrooms, so we added logic to avoid these scenarios to improve the movement of our centipede. As far as testing went, we quickly realized the difficulties of trying to test a moving project and we look forward to learning more about what that process will look like in the future.</li>
    <li><b>What We Would Improve:</b> If we were to come back to this project to improve it we would love to be able to shoot the middle of the centipede to create 2 new centipedes that move independently from one another. We also have a known bug that if you shoot a mushroom that the middle of the centipede is in the process of coliding with then the remaining body parts become disconnected from the part of the centipede that has already colided with the mushroom. We'd also love to add the random spawning enemies that show on the screen in the original game play. We would also like to add more tests had we been given more time. </li>
  </ul>
</p>

