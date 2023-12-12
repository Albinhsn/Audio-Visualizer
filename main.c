#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define PILLAR_DISTANCE 65
#define PILLAR_WIDTH 38
#define NUMBER_OF_PILLARS 12
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

struct Pillar {
  int x;
  float height;
};

static struct Pillar pillars[10];
static float averageFrequencies[10] = {0.0f};

void InitPillars(int length) {
  for (int i = 0; i < length; i++) {
    pillars[i] = (struct Pillar){25 + PILLAR_DISTANCE * i, 100.0f};
  }
}

void DrawPillars(struct Pillar *pillars, int length) {
  for (int i = 0; i < length; i++) {
    struct Pillar pillar = pillars[i];
    DrawRectangle(pillar.x, SCREEN_HEIGHT - pillar.height, PILLAR_WIDTH,
                  pillar.height, BLUE);
  }
}

void ProcessAudio(void *buffer, unsigned int frames) {
  float *samples = (float *)buffer;
  float average = 0.0f;
  printf("%d\n", frames);
  for (unsigned int frame = 0; frame < frames; frame++) {
    float *left = &samples[frame * 2 + 0], *right = &samples[frame * 2 + 1];
  }
}

int main() {

  char *file_path = "./music/EQ.mp3";

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
             "raylib [core] example - basic window");
  InitPillars(NUMBER_OF_PILLARS);

  InitAudioDevice();

  Music music = LoadMusicStream(file_path);

  AttachAudioStreamProcessor(music.stream, ProcessAudio);

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
