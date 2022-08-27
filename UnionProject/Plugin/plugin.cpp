// #include "plugin.h"
// #include "UnionAfx.h"
#include "../zSmartAimAfx.h"

extern cppimport UnionCore::TSaveLoadGameInfo UnionCore::SaveLoadGameInfo;

using namespace Common;
using namespace UnionCore;
using namespace Vdfs32;

cexport void Game_Entry() {
}

cexport void Game_Init() {
}

cexport void Game_Exit() {
}

cexport void Game_PreLoop() {
}

zVEC3 Divide( const zVEC3& v1, const zVEC3& v2 ) {
  return zVEC3(
    v2[VX] == 0.0f ? 0.0f : v1[VX] / v2[VX],
    v2[VY] == 0.0f ? 0.0f : v1[VY] / v2[VY],
    v2[VZ] == 0.0f ? 0.0f : v1[VZ] / v2[VZ]
  );
}


cexport void Game_Loop() {
  static zVEC3 _up( 0.0f, 400.0f, 0.0f );
  static float _scale = 20.0f;

  zVEC3 enemyPosition = zVEC3( 30.0f, 0.0f, 0.0f );
  float enemyCorrectionY = zParabolicTrajectory::GetHeightCorrectionAt( enemyPosition.Length() );
  zVEC3 enemyPositionCorrected = enemyPosition - zVEC3( 0.0f, enemyCorrectionY, 0.0f );

  float distanceFactor = enemyPositionCorrected.Length() / enemyPosition.Length();
  zVEC3 direction = zVEC3( enemyPositionCorrected ).Normalize() * distanceFactor;

  zlineCache->Line3D( enemyPosition * _scale + _up, enemyPosition * _scale + zVEC3(0,10,0) + _up, GFX_GREEN, 0);

  float frametime = Gothic::Game::Timer->frameTimeFloat;
   
  float add_speed = 0.0001f * frametime;


  for( float x = 0; x < 50.0f; x += 0.1f ) {
    zVEC3 v1 = direction * x;
    zVEC3 v2 = direction * (x + 0.1f);

    zVEC3 c1 = v1;
    zVEC3 c2 = v2;

    v1[VY] += zParabolicTrajectory::GetHeightCorrectionAt( x );
    v2[VY] += zParabolicTrajectory::GetHeightCorrectionAt( x + 0.1f );

    zlineCache->Line3D( v1 * _scale + _up, v2 * _scale + _up, GFX_RED, 0 );
  }
}

cexport void Game_PostLoop() {
}

cexport void Game_MenuLoop() {
}

cexport void Game_SaveBegin() {
}

cexport void Game_SaveEnd() {
}

void LoadBegin() {
}

void LoadEnd() {
}

cexport void Game_LoadBegin_NewGame() {
  LoadBegin();
}

cexport void Game_LoadEnd_NewGame() {
  LoadEnd();
}

cexport void Game_LoadBegin_SaveGame() {
  LoadBegin();
}

cexport void Game_LoadEnd_SaveGame() {
  LoadEnd();
}

cexport void Game_LoadBegin_ChangeLevel() {
  LoadBegin();
}

cexport void Game_LoadEnd_ChangeLevel() {
  LoadEnd();
}

cexport void Game_LoadBegin_Trigger() {
}

cexport void Game_LoadEnd_Trigger() {
}

cexport void Game_Pause() {
}

cexport void Game_Unpause() {
}

cexport void Game_DefineExternals() {
}

cexport void Game_ApplyOptions() {
}
