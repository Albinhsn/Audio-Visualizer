#include <raylib.h>
#include <stdio.h>

#define PILLAR_DISTANCE 65
#define PILLAR_WIDTH 38
#define NUMBER_OF_PILLARS 12
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

struct Pillar {
  int x;
  int height;
};

void InitPillars(struct Pillar *pillars, int length) {
  for (int i = 0; i < length; i++) {
    pillars[i] = (struct Pillar){25 + PILLAR_DISTANCE * i, 100};
  }
}

void DrawPillars(struct Pillar *pillars, int length) {
  for (int i = 0; i < length; i++) {
    struct Pillar pillar = pillars[i];
    DrawRectangle(pillar.x, SCREEN_HEIGHT - pillar.height, PILLAR_WIDTH,
                  pillar.height, BLUE);
  }
}

int main() {

  char *file_path = "./music/EQ.mp3";

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
             "raylib [core] example - basic window");
  struct Pillar pillars[NUMBER_OF_PILLARS];
  InitPillars(pillars, NUMBER_OF_PILLARS);

  InitAudioDevice();

  Music music = LoadMusicStream(file_path);

  PlayMusicStream(music);
  float timePlayed = 0.0f;
  bool pause = false;

  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    UpdateMusicStream(music);

    timePlayed = GetMusicTimePlayed(music) / GetMusicTimeLength(music);

    if (timePlayed > 1.0f) {
      timePlayed = 1.0f;
    }

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawPillars(pillars, NUMBER_OF_PILLARS);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  UnloadMusicStream(music);
  CloseAudioDevice();
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------orld\n");
}
