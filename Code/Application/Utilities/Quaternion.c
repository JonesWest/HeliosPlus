#include "Quaternion.h"

void Quaternion_Normalize(Quaternion_t q)
{
  float length = Quaternion_Norm(q);

  if (length == 0)
    return;
  q[QUAT_W] /= length;
  q[QUAT_X] /= length;
  q[QUAT_Y] /= length;
  q[QUAT_Z] /= length;
}

void Quaternion_QuaternionToEuler(const Quaternion_t q, Vector3_t v)
{
  float pole = M_PI/2.0f - 0.05f;                           // fix roll near poles with this tolerance

  v[VEC3_Y] = asin(2.0f * (q[QUAT_W] * q[QUAT_Y] - q[QUAT_X] * q[QUAT_Z]));

  if ((v[VEC3_Y] < pole) && (v[VEC3_Y] > -pole))
	  v[VEC3_X] = atan2(2.0f * (q[QUAT_Y] * q[QUAT_Z] + q[QUAT_W] * q[QUAT_X]),
                    1.0f - 2.0f * (q[QUAT_X] * q[QUAT_X] + q[QUAT_Y] * q[QUAT_Y]));

  v[VEC3_Z] = atan2(2.0f * (q[QUAT_X] * q[QUAT_Y] + q[QUAT_W] * q[QUAT_Z]),
                    1.0f - 2.0f * (q[QUAT_Y] * q[QUAT_Y] + q[QUAT_Z] * q[QUAT_Z]));
}

void Quaternion_EulerToQuaternion(const Vector3_t v, Quaternion_t q)
{
  float cosX2 = cos(v[VEC3_X] / 2.0f);
  float sinX2 = sin(v[VEC3_X] / 2.0f);
  float cosY2 = cos(v[VEC3_Y] / 2.0f);
  float sinY2 = sin(v[VEC3_Y] / 2.0f);
  float cosZ2 = cos(v[VEC3_Z] / 2.0f);
  float sinZ2 = sin(v[VEC3_Z] / 2.0f);

  q[QUAT_W] = cosX2 * cosY2 * cosZ2 + sinX2 * sinY2 * sinZ2;
  q[QUAT_X] = sinX2 * cosY2 * cosZ2 - cosX2 * sinY2 * sinZ2;
  q[QUAT_Y] = cosX2 * sinY2 * cosZ2 + sinX2 * cosY2 * sinZ2;
  q[QUAT_Z] = cosX2 * cosY2 * sinZ2 - sinX2 * sinY2 * cosZ2;
  Quaternion_Normalize(q);
}

void Quaternion_Conjugate(const Quaternion_t s, Quaternion_t d)
{
  d[QUAT_W] = s[QUAT_W];
  d[QUAT_X] = -s[QUAT_X];
  d[QUAT_Y] = -s[QUAT_Y];
  d[QUAT_Z] = -s[QUAT_Z];
}

void Quaternion_Multiply(const Quaternion_t qa, const Quaternion_t qb, Quaternion_t qd)
{
  Vector3_t va;
  Vector3_t vb;
  float dotAB;
  Vector3_t crossAB;

  va[VEC3_X] = qa[QUAT_X];
  va[VEC3_Y] = qa[QUAT_Y];
  va[VEC3_Z] = qa[QUAT_Z];

  vb[VEC3_X] = qb[QUAT_X];
  vb[VEC3_Y] = qb[QUAT_Y];
  vb[VEC3_Z] = qb[QUAT_Z];

  Vector3_DotProduct(va, vb, &dotAB);
  Vector3_CrossProduct(va, vb, crossAB);

  qd[QUAT_W] = qa[QUAT_W] * qb[QUAT_W] - dotAB;
  qd[QUAT_X] = qa[QUAT_W] * vb[VEC3_X] + qb[QUAT_W] * va[VEC3_X] + crossAB[VEC3_X];
  qd[QUAT_Y] = qa[QUAT_W] * vb[VEC3_Y] + qb[QUAT_W] * va[VEC3_Y] + crossAB[VEC3_Y];
  qd[QUAT_Z] = qa[QUAT_W] * vb[VEC3_Z] + qb[QUAT_W] * va[VEC3_Z] + crossAB[VEC3_Z];
}

inline float Quaternion_Norm(Quaternion_t q)
{
  return sqrt(q[QUAT_W] * q[QUAT_W] + q[QUAT_X] * q[QUAT_X] +
		  	  q[QUAT_Y] * q[QUAT_Y] + q[QUAT_Z] * q[QUAT_Z]);
}
