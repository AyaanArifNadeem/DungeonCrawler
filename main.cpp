#include "raylib.h"
#include "Player.hpp"
#include "Star.hpp"
#include "Platform.hpp"
#include "Room.hpp"
#include "Dungeon.hpp"
#include<stdexcept>
#include <vector>
#include <cstring>
#include<algorithm>


//Leaderboard utility
struct Gamer {
    char name[8];
    double value;
};

void SortLB(std::vector<Gamer> &LB, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (LB[j].value > LB[j + 1].value) {
                std::swap(LB[j], LB[j + 1]);
            }
        }
    }
}


int main() {

//Intialization of Main values and Objects

    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Dungeon Escape");
    SetTargetFPS(60);
    InitAudioDevice();
    Music bgMusic = LoadMusicStream("resources/bgmusic.wav"); 
    PlayMusicStream(bgMusic);
    
    int charCount = 0;
    char username[15]={'P','l','a','y','e','r'}; 
    Rectangle Room_exit={1200,680,80,120};

    std::vector<Gamer> Leaderboard = { {"Ayaan", 45.3}, {"Qadrain", 47.6}, {"Ukyo", 46.7} };


    Texture2D Background = LoadTexture("resources/21.png") ;
    Texture2D Background2 = LoadTexture("resources/12.png") ;
    Texture2D Background3 = LoadTexture("resources/22.png") ;
    
    Player player;
    Dungeon Game;

    Room* R1 = new Room(Background2, {100,100}, Room_exit);
    Star S1(620,150);
    Star S2(040,750);
    R1->AddStar(S1);
    R1->AddStar(S2);
    Platform P0(000,390,0);
    Platform P1(320,590,0);
    Platform P4(980,390,0);
    Platform P5(660,590,0);
    Platform P3(320,190,600,70,0);
    Platform P2(610,240,50,700,1);
    Platform P6(100,700,20,100,1,1);
    Platform P7(001,700,100,20,0,1);
    R1->AddPlatform(P0);
    R1->AddPlatform(P1);
    R1->AddPlatform(P2);
    R1->AddPlatform(P3);
    R1->AddPlatform(P4);
    R1->AddPlatform(P5);
    R1->AddPlatform(P6);
    R1->AddPlatform(P7);
        
    Room* R2 = new Room(Background3,{100,100},Room_exit);    
    Star S3(510,540);
    Star S4(030,340);
    Star S5(870,340);
    Star S6(1140,540);
    Star S7(600,150);
    R2->AddStar(S3);
    R2->AddStar(S4);
    R2->AddStar(S5);
    R2->AddStar(S6);
    R2->AddStar(S7);
    Platform P8(000,390,0);
    Platform P9(360,590,0);
    Platform P10(720,390,0);
    Platform P11(1080,590,0);
    Platform P12(000,390,0);
    Platform P13(80,310,20,80,1,1);
    Platform P14(001,290,100,20,0,1);
    R2->AddPlatform(P8);
    R2->AddPlatform(P9);
    R2->AddPlatform(P10);
    R2->AddPlatform(P11);
    R2->AddPlatform(P12);
    R2->AddPlatform(P13);
    R2->AddPlatform(P14);

    Room* R3 = new Room(Background2,{10,10},Room_exit);    
    Star S8(150,50);
    Star S9(300,150);
    Star S10(450,250);
    Star S11(600,350);
    Star S12(750,450);
    Star S13(900,550);
    Star S14(1050,650);
    Star S15(1200,450);
    Star S16(1200,250);
    R3->AddStar(S8);
    R3->AddStar(S9);
    R3->AddStar(S10);
    R3->AddStar(S11);
    R3->AddStar(S12);
    R3->AddStar(S13);
    R3->AddStar(S14);
    R3->AddStar(S15);
    R3->AddStar(S16);
    Platform P15(001,100,0);
    Platform P16(150,200,0);
    Platform P17(300,300,0);
    Platform P18(450,400,0);
    Platform P19(600,500,0);
    Platform P20(750,600,0);
    Platform P21(900,700,0);
    Platform P22(1050,500,0);
    Platform P23(1200,300,0);
    R3->AddPlatform(P15);
    R3->AddPlatform(P16);
    R3->AddPlatform(P17);
    R3->AddPlatform(P18);
    R3->AddPlatform(P19);
    R3->AddPlatform(P20);
    R3->AddPlatform(P21);
    R3->AddPlatform(P22);
    R3->AddPlatform(P23);


    Room* R4 = new Room(Background3,{10,10},Room_exit);    
    Star S17(150,250);
    Star S18(300,450);
    Star S19(450,650);
    Star S20(600,550);
    Star S21(750,450);
    Star S22(900,350);
    Star S23(1050,250);
    Star S24(1200,150);
    Star S25(1200,50);
    R4->AddStar(S17);
    R4->AddStar(S18);
    R4->AddStar(S19);
    R4->AddStar(S20);
    R4->AddStar(S21);
    R4->AddStar(S22);
    R4->AddStar(S23);
    R4->AddStar(S24);
    R4->AddStar(S25);
    Platform P24(001,300,0);
    Platform P25(150,500,0);
    Platform P26(300,700,0);
    Platform P27(450,600,0);
    Platform P28(600,500,0);
    Platform P29(750,400,0);
    Platform P30(900,300,0);
    Platform P31(1050,200,0);
    Platform P32(1200,100,0);
    R4->AddPlatform(P24);
    R4->AddPlatform(P25);
    R4->AddPlatform(P26);
    R4->AddPlatform(P27);
    R4->AddPlatform(P28);
    R4->AddPlatform(P29);
    R4->AddPlatform(P30);
    R4->AddPlatform(P31);
    R4->AddPlatform(P32);

    Room* R5 = new Room(Background2,{1240,10},Room_exit); 
    Star S26(150,750);
    Star S27(300,750);
    Star S28(450,750);
    Star S29(600,750);
    Star S30(750,750);
    Star S31(900,750);
    Star S32(1050,750);
    Star S33(150,300);
    Star S34(300,300);
    Star S35(450,300);
    Star S36(600,300);
    Star S37(750,300);
    Star S38(900,300);
    Star S39(1050,300);
    Star S40(150,90);
    Star S41(300,90);
    Star S42(450,90);
    Star S43(600,90);
    Star S44(750,90);
    Star S45(900,90);
    Star S46(1050,90);
    Star S47(150,550);
    Star S48(300,550);
    Star S49(450,550);
    Star S50(600,550);
    Star S51(750,550);
    Star S52(900,550);
    Star S53(1050,550);
    R5->AddStar(S26);
    R5->AddStar(S27);
    R5->AddStar(S28);
    R5->AddStar(S29);
    R5->AddStar(S30);
    R5->AddStar(S31);
    R5->AddStar(S32);
    R5->AddStar(S33);
    R5->AddStar(S34);
    R5->AddStar(S35);
    R5->AddStar(S36);
    R5->AddStar(S37);
    R5->AddStar(S38);
    R5->AddStar(S39);
    R5->AddStar(S40);
    R5->AddStar(S41);
    R5->AddStar(S42);
    R5->AddStar(S43);
    R5->AddStar(S44);
    R5->AddStar(S45);
    R5->AddStar(S46);
    R5->AddStar(S47);
    R5->AddStar(S48);
    R5->AddStar(S49);
    R5->AddStar(S50);
    R5->AddStar(S51);
    R5->AddStar(S52);
    R5->AddStar(S53);
    Platform P33(1160,440,20,200,1,1);
    Platform P34(940,440,20,200,1,1);
    Platform P35(720,440,20,200,1,1);
    Platform P36(500,440,20,200,1,1);
    Platform P37(280,440,20,200,1,1);
    Platform P38(60,440,20,200,1,1);
    Platform P39(100,140,1180,60,0,1);
    Platform P40(001,380,1180,60,0,1);
    Platform P41(100,620,1180,60,0,1);
    R5->AddPlatform(P33);
    R5->AddPlatform(P34);
    R5->AddPlatform(P35);
    R5->AddPlatform(P36);
    R5->AddPlatform(P37);
    R5->AddPlatform(P38);
    R5->AddPlatform(P39);
    R5->AddPlatform(P40);    
    R5->AddPlatform(P41);



    Game.Enqueue(R1);
    Game.Enqueue(R2);
    Game.Enqueue(R3);
    Game.Enqueue(R4);
    Game.Enqueue(R5);

      

//Intro Block


    Texture2D titlescreen = LoadTexture("resources/title2.png");

    while (!WindowShouldClose()) {
     UpdateMusicStream(bgMusic); 

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(titlescreen,(Rectangle){0, 0, (float)titlescreen.width, (float)titlescreen.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);

        DrawText("DUNGEON ESCAPE", 180, 200, 100, LIGHTGRAY);
        DrawText("Press ENTER to start game", 300, 470, 50, WHITE);
        DrawText("AYAAN ARIF NADEEM(30546) ", 900, 700 , 20, WHITE);
        
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) break;
    }

    while (!WindowShouldClose()) {
     UpdateMusicStream(bgMusic); 

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(titlescreen,(Rectangle){0, 0, (float)titlescreen.width, (float)titlescreen.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);

         
            DrawText("Instructions", 100, 100, 100, LIGHTGRAY);
            DrawText("Collect all skulls ", 150, 300 , 40, WHITE);
            DrawText("Reach the angel statue to go to the next level", 150, 370, 40, WHITE);
            DrawText("Use arrow Keys to move & left shift to sprint", 150, 440, 40, WHITE);
            DrawText("Use Z to attack and break certain walls", 150, 510, 40, WHITE);
            DrawText("Press ENTER TO proceed", 150, 580, 40, WHITE);
        
        
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) break;
    }
    
    while (!WindowShouldClose()) {
        UpdateMusicStream(bgMusic); 

        int key = GetCharPressed();
        while (key > 0) {
            if (key >= 32 && key <= 126 && charCount < 14) {
                username[charCount] = (char)key;
                username[charCount + 1] = '\0'; 
                charCount++;
            }
            key = GetCharPressed();  
        }

        if (IsKeyPressed(KEY_BACKSPACE) && charCount > 0) {
            charCount--;
            username[charCount] = '\0';
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(titlescreen,(Rectangle){0, 0, (float)titlescreen.width, (float)titlescreen.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);

            
            DrawText("Enter Username", 100, 100, 100, LIGHTGRAY);
            DrawRectangle(350, 440, 500, 100, LIGHTGRAY);
            DrawRectangleLines(350, 440, 500, 100, DARKGRAY);
            DrawText(username,370, 450, 90, MAROON);
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) break;

    }
    try{
        if(charCount>8){throw std::out_of_range("Username too large");}
        for(int i = 0; i<8;i++){
            player.name[i] = username [i];
        }
    }

    catch(const std::out_of_range& e){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(titlescreen,(Rectangle){0, 0, (float)titlescreen.width, (float)titlescreen.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);
        DrawText(e.what(), 150, 300, 100, LIGHTGRAY);
        EndDrawing();
        WaitTime(3.0); 
       
    }



    
//Intro Ends Main Game Loop

double startTime = GetTime(); 
double elapsedTime = 0.0;
    
while(Game.GetCurrentRoom()!=nullptr){
    
if(!(Game.GetCurrentRoom()->levelcomplete)){

    Player::allPlatforms = &(Game.GetCurrentRoom()->plat);
    Player::allStars = &(Game.GetCurrentRoom()->skull);
    Vector2 pos = Game.GetCurrentRoom()->get_playerspawn();
    player.setpositon(pos);
    
    
    
    while (!WindowShouldClose() && !(Game.GetCurrentRoom()->levelcomplete)){
        
        UpdateMusicStream(bgMusic); 
        player.update();
        elapsedTime = GetTime() - startTime;

        

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(Background,(Rectangle){0, 0, (float)Background.width, (float)Background.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);
        Game.GetCurrentRoom()->Draw(player);
        DrawText(TextFormat("Elapsed time: %.2f seconds", elapsedTime), 10, 40, 20, WHITE);
        EndDrawing();

    }

    Game.ProceedToNextRoom();
    player.stars_collected = 0;


    } 
}

//LeaderBoard Entry & Sort & Display
Gamer current;
strncpy(current.name, player.name, sizeof(current.name) - 1); 
current.name[sizeof(current.name) - 1] = '\0';
current.value = elapsedTime; 
Leaderboard.push_back(current);
SortLB(Leaderboard, Leaderboard.size());


 while (!WindowShouldClose()) {
     UpdateMusicStream(bgMusic); 

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(titlescreen,(Rectangle){0, 0, (float)titlescreen.width, (float)titlescreen.height},(Rectangle){0, 0, screenWidth, screenHeight},(Vector2){0, 0},0.0f,WHITE);

       DrawText("LEADERBOARD", 300, 150, 100, GOLD);

int y = 300;
int rank = 1;
for (const Gamer& g : Leaderboard) {
    DrawText(TextFormat("%d. %s - %.2f seconds", rank, g.name, g.value), 400, y, 40, WHITE);
    y += 50;  
    rank++;
}
        DrawText("Press ENTER to exit", 900, 700 , 20, WHITE);

        
        EndDrawing();
        if (IsKeyPressed(KEY_ENTER)) break;

}

    
    UnloadTexture(titlescreen);
    UnloadTexture(Background2);
    UnloadMusicStream(bgMusic); 
    UnloadTexture(Background);

    CloseWindow();
    return 0;
}