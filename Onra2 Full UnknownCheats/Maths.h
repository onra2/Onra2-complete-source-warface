#include <assert.h> 
#include <math.h>
#include <d3dx9.h>
#define COLLISION_RAY_PIERCABILITY 10
#define RWI_RAY_PIERCABILITY_MASK  0x0F
#define BONE_ATTACH_ENTITY_LINK_PREFIX "@"
#define ENTITY_LINK_NAME_MAX_LENGTH 31

typedef unsigned int EntityId;
struct Matrix33;

float clamp(float X, float Min, float Max)
{
	X = (X + Max - fabsf(X - Max))*0.5f;
	X = (X + Min + fabsf(X - Min))*0.5f;

	return X;
}

int FloatU32(const float x)
{
	union { int ui; float f; } cvt;
	cvt.f = x;

	return cvt.ui;
}

#define FloatU32ExpMask (0xFF << 23)

bool NumberValid(const float& x)
{
	int i = FloatU32(x);
	int expmask = FloatU32ExpMask;
	int iexp = i & expmask;
	bool invalid = (iexp == expmask);

	if (invalid)
	{
		int i = 0x7F800001;
		float fpe = *(float*)(&i);
	}

	return !invalid;
}

float isqrt_tpl(float op) { return 1.0f / sqrt(op); }
float fabs_tpl(float op) { return fabs(op); }
void cry_sincos(float angle, float* pSin, float* pCos) { *pSin = (sin(angle));  *pCos = (cos(angle)); }
void sincos(float angle, float* pSin, float* pCos) { cry_sincos(angle, pSin, pCos); }
float isqrt_safe_tpl(float op) { return 1.0f / sqrt(op + (float)DBL_MIN); }

float asin_tpl(float op) { return asin(clamp(op, -1.0f, +1.0f)); }
float g_PI = 3.14159265358979323846264338327950288419716939937510f;
float atan2_tpl(float op1, float op2) { return atan2(op1, op2); }

struct Vec3
{
	float x;
	float y;
	float z;

	bool IsValid() const
	{
		if (!NumberValid(x)) return false;
		if (!NumberValid(y)) return false;
		if (!NumberValid(z)) return false;

		return true;
	}

	float GetLengthSquared() const { return x*x + y*y + z*z; }

	bool IsUnit(float epsilon = 0.05f) const
	{
		return (fabs_tpl(1 - GetLengthSquared()) <= epsilon);
	}

	Vec3 GetNormalized() const
	{
		float fInvLen = isqrt_safe_tpl(x*x + y*y + z*z);

		Vec3 out = *this;
		out.x *= fInvLen;
		out.y *= fInvLen;
		out.z *= fInvLen;
		return out;
	}

	Vec3 GetNormalizedSafe(const struct Vec3& safe) const
	{
		float fLen2 = x*x + y*y + z*z;

		if (fLen2 > 0.0f)
		{
			float fInvLen = isqrt_tpl(fLen2);
			Vec3 out;
			out.x = safe.x*fInvLen;
			out.y = safe.y*fInvLen;
			out.z = safe.z*fInvLen;
			return out;

		}
		else
		{
			return safe;
		}
	}

	void Normalize()
	{
		assert(this->IsValid());
		float fInvLen = isqrt_safe_tpl(x*x + y*y + z*z);
		x *= fInvLen; y *= fInvLen; z *= fInvLen;
	}

	void Set(float xval, float yval, float zval)
	{
		x = xval;
		y = yval;
		z = zval;
	}

	Vec3& normalize()
	{
		float len2 = x*x + y*y + z*z;
		#if defined(XENON) || (defined(PS3) && !defined(__SPU__))
		const F rlen = isqrt_tpl(len2 + 1E-20f);
		x *= rlen; y *= rlen; z *= rlen;
		const F cRev = -len2;
		x = (F)__fsel(cRev, (F)0.f, x);
		y = (F)__fsel(cRev, (F)0.f, y);
		z = (F)__fsel(cRev, (F)1.f, z);
		#else
		if (len2>1e-20f)
		{
			float rlen = isqrt_tpl(len2);
			x *= rlen; y *= rlen; z *= rlen;
		}
		else
			Set(0, 0, 1);
		#endif
		return *this;

	}

	float Dot(const Vec3 &vec1, const Vec3 &vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	float Dot(const Vec3 &vec) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	Vec3 operator+(const Vec3 &vector) const
	{
		return Vec3{ x + vector.x, y + vector.y, z + vector.z };
	}

	void operator+=(const Vec3 &vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}

	Vec3 operator-(const Vec3 &vector) const
	{
		return Vec3{ x - vector.x, y - vector.y, z - vector.z };
	}

	void operator-=(const Vec3 &vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}

	Vec3 operator*(const Vec3 &vector) const
	{
		return Vec3{ x * vector.x, y * vector.y, z * vector.z };
	}

	void operator*=(const float &value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	Vec3 operator/(const float &value) const
	{
		return Vec3{ x / value, y / value, z / value };
	}

	void operator/=(const float &value)
	{
		x /= value;
		y /= value;
		z /= value;
	}
};

struct Vec3Constants
{
	static const Vec3 fVec3_Zero;
	static const Vec3 fVec3_OneX;
};

struct Matrix33
{
	float m00, m01, m02;
	float m10, m11, m12;
	float m20, m21, m22;

	bool IsValid() const
	{
		if (!NumberValid(m00)) return false;
		if (!NumberValid(m01)) return false;
		if (!NumberValid(m02)) return false;

		if (!NumberValid(m10)) return false;
		if (!NumberValid(m11)) return false;
		if (!NumberValid(m12)) return false;

		if (!NumberValid(m20)) return false;
		if (!NumberValid(m21)) return false;
		if (!NumberValid(m22)) return false;

		return true;
	}

	void SetRotationVDir(const Vec3& vdir)
	{
		m00 = 1;
		m01 = 0;
		m02 = 0;

		m10 = 0;
		m11 = 0;
		m12 = -vdir.z;

		m20 = 0;
		m21 = vdir.z;
		m22 = 0;

		float l = sqrt(vdir.x*vdir.x + vdir.y*vdir.y);

		if (l > 0.0001)
		{
			float xl = -vdir.x / l; float yl = vdir.y / l;

			m00 = (yl);
			m01 = (vdir.x);
			m02 = (xl*vdir.z);

			m10 = (xl);
			m11 = (vdir.y);
			m12 = (-vdir.z*yl);

			m20 = 0;
			m21 = (vdir.z);
			m22 = (l);
		}
	}

	Matrix33(const Vec3& vx, const Vec3& vy, const Vec3& vz)
	{
		m00 = (vx.x);
		m01 = (vy.x);
		m02 = (vz.x);

		m10 = (vx.y);
		m11 = (vy.y);
		m12 = (vz.y);

		m20 = (vx.z);
		m21 = (vy.z);
		m22 = (vz.z);
	}
};

struct Ang3
{
	float x;
	float y;
	float z;

	void Set(float xval, float yval, float zval) { x = xval; y = yval; z = zval; }
	void operator () (float vx, float vy, float vz) { x = vx; y = vy; z = vz; };

	Ang3(const Matrix33& m)
	{
		y = asin_tpl(max(-1.0f, min(1.0f, -m.m20)));
		if (fabs_tpl(fabs_tpl(y) - (g_PI*0.5f))<0.01f)
		{
			x = 0;
			z = atan2_tpl(-m.m01, m.m11);
		}
		else {
			x = atan2_tpl(m.m21, m.m22);
			z = atan2_tpl(m.m10, m.m00);
		}
	}

	bool IsValid() const
	{
		if (!NumberValid(x)) return false;
		if (!NumberValid(y)) return false;
		if (!NumberValid(z)) return false;

		return true;
	}
};

class Quat
{
	public:
	Vec3 v;
	float w;

	bool IsValid() const
	{
		if (!NumberValid(v.x)) return false;
		if (!NumberValid(v.y)) return false;
		if (!NumberValid(v.z)) return false;
		if (!NumberValid(w)) return false;

		return true;
	}

	friend float operator | (const Quat& q, const Quat& p)
	{
		assert(q.v.IsValid());
		assert(p.v.IsValid());
		return (q.v.x*p.v.x + q.v.y*p.v.y + q.v.z*p.v.z + q.w*p.w);
	}

	friend Quat operator - (const Quat &q, const Quat &p)
	{
		Quat ret;
		ret.w = q.w - p.w;

		ret.v.x = q.v.x - p.v.x;
		ret.v.y = q.v.y - p.v.y;
		ret.v.z = q.v.z - p.v.z;

		return ret;
	}

	void Normalize(void)
	{
		float d = isqrt_tpl(w*w + v.x*v.x + v.y*v.y + v.z*v.z);

		w *= d;

		v.x *= d;
		v.y *= d;
		v.z *= d;
	}

	void SetNlerp(const Quat &p, const Quat &tq, float t)
	{
		Quat q = tq;

		assert(p.IsValid());
		assert(q.IsValid());

		if ((p | q) < 0)
		{
			float qx = -q.v.x;
			float qy = -q.v.y;
			float qz = -q.v.z;

			q.v.x = qx;
			q.v.y = qy;
			q.v.z = qz;
		}

		v.x = p.v.x*(1.0f - t) + q.v.x*t;
		v.y = p.v.y*(1.0f - t) + q.v.y*t;
		v.z = p.v.z*(1.0f - t) + q.v.z*t;

		w = p.w  *(1.0f - t) + q.w  *t;

		Normalize();
	}

	void SetSlerp(const Quat &tp, const Quat &tq, float t)
	{
		assert(tp.IsValid());

		Quat p, q;
		p = tp;
		q = tq;
		Quat q2;

		float cosine = (p | q);

		if (cosine < 0.0f)
		{
			float qx = -q.v.x;
			float qy = -q.v.y;
			float qz = -q.v.z;

			cosine = -cosine;

			q.v.x = qx;
			q.v.y = qy;
			q.v.z = qz;
		}

		if (cosine > 0.9999f)
		{
			SetNlerp(p, q, t);
			return;
		}

		q2.w = q.w - p.w*cosine;
		q2.v.x = q.v.x - p.v.x*cosine;
		q2.v.y = q.v.y - p.v.y*cosine;
		q2.v.z = q.v.z - p.v.z*cosine;

		float sine = sqrt(q2 | q2);
		float s, c;

		sincos(atan2(sine, cosine)*t, &s, &c);

		w = (p.w*c + q2.w*s / sine);
		v.x = (p.v.x*c + q2.v.x*s / sine);
		v.y = (p.v.y*c + q2.v.y*s / sine);
		v.z = (p.v.z*c + q2.v.z*s / sine);
	}

	static Quat CreateSlerp(const Quat &p, const Quat &tq, float t)
	{
		Quat d;
		d.SetSlerp(p, tq, t);
		return d;
	}

	Quat(const Matrix33& m)
	{
		float s, p, tr = m.m00 + m.m11 + m.m22;
		w = 1, v.x = 0, v.y = 0, v.z = 0;

		if (tr>0)
			s = sqrt(tr + 1.0f), p = 0.5f / s, w = s*0.5f, v.x = (m.m21 - m.m12)*p, v.y = (m.m02 - m.m20)*p, v.z = (m.m10 - m.m01)*p;
		else if ((m.m00 >= m.m11) && (m.m00 >= m.m22))
			s = sqrt(m.m00 - m.m11 - m.m22 + 1.0f), p = 0.5f / s, w = (m.m21 - m.m12)*p, v.x = s*0.5f, v.y = (m.m10 + m.m01)*p, v.z = (m.m20 + m.m02)*p;
		else if ((m.m11 >= m.m00) && (m.m11 >= m.m22))
			s = sqrt(m.m11 - m.m22 - m.m00 + 1.0f), p = 0.5f / s, w = (m.m02 - m.m20)*p, v.x = (m.m01 + m.m10)*p, v.y = s*0.5f, v.z = (m.m21 + m.m12)*p;
		else if ((m.m22 >= m.m00) && (m.m22 >= m.m11))
			s = sqrt(m.m22 - m.m00 - m.m11 + 1.0f), p = 0.5f / s, w = (m.m10 - m.m01)*p, v.x = (m.m02 + m.m20)*p, v.y = (m.m12 + m.m21)*p, v.z = s*0.5f;
	}

	void SetRotationVDir(const Vec3& vdir)
	{
		w = (0.70710676908493042f);
		v.x = (vdir.z*0.70710676908493042f);
		v.y = (0.0f);
		v.z = (0.0f);

		float l = sqrt(vdir.x*vdir.x + vdir.y*vdir.y);

		if (l>(0.00001))
		{
			Vec3 hv;

			hv.x = vdir.x / l;
			hv.y = vdir.y / l + 1.0f;
			hv.z = l + 1.0f;

			float r = sqrt(hv.x*hv.x + hv.y*hv.y);
			float s = sqrt(hv.z*hv.z + vdir.z*vdir.z);
			float hacos0 = 0.0;
			float hasin0 = -1.0;

			if (r>(0.00001)) { hacos0 = hv.y / r; hasin0 = -hv.x / r; }

			float hacos1 = hv.z / s;
			float hasin1 = vdir.z / s;

			w = (hacos0*hacos1);
			v.x = (hacos0*hasin1);
			v.y = (hasin0*hasin1);
			v.z = (hasin0*hacos1);
		}
	}

	static Quat CreateRotationVDir(const Vec3& vdir) { Quat q; q.SetRotationVDir(vdir); return q; }
	Quat CreateRotationVDir_(const Vec3& vdir, float roll) { Quat q; q.SetRotationVDir_2(vdir, roll); return q; }

	void SetRotationVDir_2(const Vec3& vdir, float r)
	{
		SetRotationVDir(vdir);
		float sy, cy;  sincos(r*0.5f, &sy, &cy);
		float vx = v.x, vy = v.y;
		v.x = (vx*cy - v.z*sy); v.y = (w*sy + vy*cy); v.z = (v.z*cy + vx*sy); w = (w*cy - vy*sy);
	}

	Quat Quat::CreateRotationXYZ(const Ang3 &a)
	{
		assert(a.IsValid());
		Quat q; 
		q.SetRotationXYZ(a);
		
		return q;
	}

	void Quat::SetRotationXYZ(const Ang3 &a)
	{
		assert(a.IsValid());
		float sx, cx;  sincos((a.x*0.5f), &sx, &cx);
		float sy, cy;  sincos((a.y*0.5f), &sy, &cy);
		float sz, cz;  sincos((a.z*0.5f), &sz, &cz);
		w = cx*cy*cz + sx*sy*sz;
		v.x = cz*cy*sx - sz*sy*cx;
		v.y = cz*sy*cx + sz*cy*sx;
		v.z = sz*cy*cx - cz*sy*sx;
	}

	void Quat::SetRotationZ(float r)
	{
		float s, c;
		sincos((r*0.5f), &s, &c);
		w = c;
		v.x = 0;
		v.y = 0;
		v.z = s;
	}

	Quat Quat::CreateRotationZ(float r)
	{
		Quat q;
		q.SetRotationZ(r);
		return q;
	}

	Quat(){}
};

class QuatT
{
	public:
		Quat q;
		Vec3 t;

		bool IsValid() const
		{
			if (!t.IsValid()) return false;
			if (!q.IsValid()) return false;
			return true;
		}

		QuatT(){}
};

struct Matrix34
{
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;

	Matrix34() {}

	Vec3 GetTranslation(){ Vec3 mf; mf.x = m03; mf.y = m13; mf.z = m23; return Vec3(mf); }

	Vec3 GetColumn1() { Vec3 F; F.x = m01; F.y = m11; F.z = m21; return Vec3(F); }

	void SetTranslation(Vec3 Vector){ m03 = Vector.x; m13 = Vector.y; m23 = Vector.z; }

	Matrix34(const QuatT& q)
	{
		assert(q.q.IsValid());

		Vec3 v2 = {0, 0, 0};
		v2.x = (q.q.v.x) + (q.q.v.x);

		float xx = 1 - v2.x*q.q.v.x; float yy = v2.y*q.q.v.y; float xw = v2.x*q.q.w;
		float xy = v2.y*q.q.v.x;   float yz = v2.z*q.q.v.y; float  yw = v2.y*q.q.w;
		float xz = v2.z*q.q.v.x;   float zz = v2.z*q.q.v.z; float  zw = v2.z*q.q.w;

		m00 = float(1 - yy - zz);     m01 = float(xy - zw);     m02 = float(xz + yw);   m03 = float(q.t.x);
		m10 = float(xy + zw);      m11 = float(xx - zz);     m12 = float(yz - xw);   m13 = float(q.t.y);
		m20 = float(xz - yw);      m21 = float(yz + xw);     m22 = float(xx - yy);   m23 = float(q.t.z);
	}

	void SetTranslationAndRotation(Vec3 Pos, const Vec3& Rotation)
	{
		float sinX = sin(Rotation.x);
		float cosX = cos(Rotation.x);
		float sinY = sin(Rotation.y);
		float cosY = cos(Rotation.y);
		float sinZ = sin(Rotation.z);
		float cosZ = cos(Rotation.z);

		m00 = cosY * cosZ;
		m01 = sinX * sinY * cosZ - cosX * sinZ;
		m02 = cosX * sinY * cosZ + sinX * sinZ;
		m03 = Pos.x;

		m10 = cosY * sinZ;
		m11 = sinX * sinY * sinZ + cosX * cosZ;
		m12 = cosX * sinY * sinZ - sinX * cosZ;
		m13 = Pos.y;

		m20 = -sinY;
		m21 = sinX * cosY;
		m22 = cosX * cosY;
		m23 = Pos.z;
	}

	void SetRotationXYZ(const Vec3& radian)
	{
		float sinX = sin(radian.x);
		float cosX = cos(radian.x);
		float sinY = sin(radian.y);
		float cosY = cos(radian.y);
		float sinZ = sin(radian.z);
		float cosZ = cos(radian.z);

		m00 = cosY * cosZ;
		m01 = sinX * sinY * cosZ - cosX * sinZ;
		m02 = cosX * sinY * cosZ + sinX * sinZ;
		m03 = 0.f;
		
		m10 = cosY * sinZ;
		m11 = sinX * sinY * sinZ + cosX * cosZ;
		m12 = cosX * sinY * sinZ - sinX * cosZ;
		m13 = 0.f;
		
		m20 = -sinY;
		m21 = sinX * cosY;
		m22 = cosX * cosY;
		m23 = 0.f;
	}

	bool GetRotationXYZ(Vec3* radian)
	{
		float yRadian = asin(-m20);
		radian->y = yRadian;

		if (yRadian < (D3DX_PI/2))
		{
			if (yRadian > -(D3DX_PI / 2))
			{
				radian->x = atan2(m21, m22);
				radian->z = atan2(m10, m00);
				return true;
			}
			else
			{
				radian->x = -atan2(m01, m11);
				radian->z = 0.f;
				return false;
			}
		}
		else
		{
			radian->x = atan2(m01, m11);
			radian->z = 0.f;
			return false;
		}
	}

	bool IsValid() const
	{
		if (!NumberValid(m00)) return false;	if (!NumberValid(m01)) return false;	if (!NumberValid(m02)) return false;	if (!NumberValid(m03)) return false;
		if (!NumberValid(m10)) return false;	if (!NumberValid(m11)) return false;	if (!NumberValid(m12)) return false;	if (!NumberValid(m13)) return false;
		if (!NumberValid(m20)) return false;	if (!NumberValid(m21)) return false;	if (!NumberValid(m22)) return false;	if (!NumberValid(m23)) return false;
		return true;
	}

	friend Matrix34 operator * (const Matrix34& l, const Matrix34& r)
	{
		assert(l.IsValid());
		assert(r.IsValid());

		Matrix34 m = r;

		m.m00 = l.m00*r.m00 + l.m01*r.m10 + l.m02*r.m20;
		m.m10 = l.m10*r.m00 + l.m11*r.m10 + l.m12*r.m20;
		m.m20 = l.m20*r.m00 + l.m21*r.m10 + l.m22*r.m20;
		m.m01 = l.m00*r.m01 + l.m01*r.m11 + l.m02*r.m21;
		m.m11 = l.m10*r.m01 + l.m11*r.m11 + l.m12*r.m21;
		m.m21 = l.m20*r.m01 + l.m21*r.m11 + l.m22*r.m21;
		m.m02 = l.m00*r.m02 + l.m01*r.m12 + l.m02*r.m22;
		m.m12 = l.m10*r.m02 + l.m11*r.m12 + l.m12*r.m22;
		m.m22 = l.m20*r.m02 + l.m21*r.m12 + l.m22*r.m22;
		m.m03 = l.m00*r.m03 + l.m01*r.m13 + l.m02*r.m23 + l.m03;
		m.m13 = l.m10*r.m03 + l.m11*r.m13 + l.m12*r.m23 + l.m13;
		m.m23 = l.m20*r.m03 + l.m21*r.m13 + l.m22*r.m23 + l.m23;

		return m;
	}
};

struct AABB {
	Vec3 min;
	Vec3 max;
};

struct Quat_R{
	float x;
	float y;
	float z;
	float w;
};

Matrix33 ConvertToMatrix33(const Matrix34& Input)
{
	Vec3 vNULL = { 0, 0, 0 };

	assert(Input.IsValid());

	Matrix33 Output = Matrix33(vNULL, vNULL, vNULL);

	Output.m00 = (Input.m00);
	Output.m01 = (Input.m01);
	Output.m02 = (Input.m02);
	Output.m10 = (Input.m10);
	Output.m11 = (Input.m11);
	Output.m12 = (Input.m12);
	Output.m20 = (Input.m20);
	Output.m21 = (Input.m21);
	Output.m22 = (Input.m22);

	return Output;
}