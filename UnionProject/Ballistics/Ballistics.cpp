#include "../zSmartAimAfx.h"


zParabolicTrajectory::zParabolicTrajectory( const zVEC3& start, const zVEC3& end, const float& speed ) {
  Start = start;
  End = end;
  Direction = (End - Start).Normalize();
  Speed = speed;
  Position = 0.0f;
  CurrentProjectile = start;
  PreviousProjectile = start;
}


float zParabolicTrajectory::GetHeightCorrectionAt( const float& position ) {
  if( position <= 1.0f )
    return 0.0;

  return powf( position - 1.0f, 2.0f ) * -0.125f;
}


zVEC3 zParabolicTrajectory::GetProjectileAt( const float& position ) const {
  zVEC3 proj = Start + Direction * position;
  proj[VY] += GetHeightCorrectionAt( position );
  return proj;
}


void zParabolicTrajectory::DoFrame() {
  Position += Speed * ztimer->frameTimeFloat;
  PreviousProjectile = CurrentProjectile;
  CurrentProjectile = GetProjectileAt( Position );
  // TODO
}


zVEC3 zParabolicTrajectory::GetCurrentProjectile() const {
  return CurrentProjectile;
}