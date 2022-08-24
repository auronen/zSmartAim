#pragma once

class zParabolicTrajectory {
  zVEC3 Start;              // Shoot point
  zVEC3 End;                // Target point
  zVEC3 Direction;          // Trajectory direction
  float Speed;              // Speed of the projectile
  float Position;           // Current distance from the start
  zVEC3 CurrentProjectile;  // Current position of the projectile
  zVEC3 PreviousProjectile; // Previous porition of the projectile
public:

  zParabolicTrajectory( const zVEC3& start, const zVEC3& end, const float& speed );
  zVEC3 GetProjectileAt( const float& position ) const;
  void DoFrame();
  zVEC3 GetCurrentProjectile() const;

  static float GetHeightCorrectionAt( const float& position );
  static float GetHeightCorrectionAtEX( const float& position, float a );
};