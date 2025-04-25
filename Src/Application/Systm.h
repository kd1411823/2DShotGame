#pragma once
#define BIT18 18
#define BIT24 24
#define BIT64 64
#define BIT128 128
#define BIT240 240
#define BIT256 256
#define BIT512 512
#define WhlUp 120
#define WhlDwn -120
#define ScrnHgt 1280
#define ScrnWid 720
#define ScrnTop 360
#define ScrnBtm -360
#define ScrnRht 640
#define ScrnLft -640
#define EnemyMax 3
#define EnemyHpCircleScl 0.3f
#define BulletNum 18
#define ebulletNum 6
#define DropBulletNum 18
#define pHighSpd 3.0f
#define pDefaultSpd 2.0f
#define pSlowSpd 0.8f
#define eHighSpd 2.0f
#define eDefaultSpd 1.5f
#define eSlowSpd 0.8f
#define EnemyHp 7.0f
#define ZeroLifescl 0.0f
#define OneLifescl 0.25f
#define TwoLifescl 0.5f
#define ThreeLifescl 0.7f
#define FourLifescl 0.9f
#define ZeroRadius 0.0f
#define OneRadius 85.0f
#define TwoRadius 170.0f
#define ThreeRadius 238.0f
#define FourRadius 305.0f
#define ShotInterval 4
#define initPos { 0, 0 }
#define WHITE { 1.0f,1.0f,1.0f,1.0f }
#define BLACK { 0.0f,0.0f,0.0f,1.0f }
#define RED   { 1.0f,0.0f,0.0f,1.0f }
#define GREEN { 0.0f,1.0f,0.0f,1.0f }
#define BLUE  { 0.0f,0.0f,1.0f,1.0f }
#define YELLOW  { 1.0f,1.0f,0.0f,1.0f }

// プレイヤーライフ
enum ePlayerLife
{
	ZeroLife,
	OneLife,
	TwoLife,
	ThreeLife,
	FourLife,
	FiveLife,
};

// 敵の行動パターン
enum eEnemyMovCmd
{
	DefaultMov,
	HighMov
};

// 敵の動き(方向)
enum eEnemyMovDir
{
	LeftDir,
	RightDir
};
// 行列
struct tMat
{
	Math::Matrix scalemat;
	Math::Matrix rotmat;
	Math::Matrix transmat;
	Math::Matrix compmat;
};

// 描画関係
struct tDraw
{
	KdTexture* pTex;
	Math::Rectangle rct;
	Math::Color clr;
};

// ステータス
struct Bsst
{
	Math::Vector2 pos;
	Math::Vector2 mov;
	Math::Vector2 scl;
	float rot;
	bool alive;
	tMat mat;
	tDraw draw;
};

// パーティクルステータス
struct ParticleSt
{
	Math::Vector2 pos;
	Math::Vector2 mov;
	Math::Vector2 scl;
	float rot;
	bool alive;
	int  lifespan;
	bool repeat;
	tMat mat;
	tDraw draw;
};

// 三角関数
struct tTry
{
	float base;
	float hght;
	float hypn;
};

// サウンド構造体
struct tSnd
{
	std::shared_ptr<KdSoundEffect>	 data;	// データ
	std::shared_ptr<KdSoundInstance> inst;	// スピーカー
	bool endFlg;							// 流し終わったかフラグ (重複実行を防ぐ)
};

class C_Systm
{
public:

	C_Systm() {}
 	virtual ~C_Systm() {}

	tMat CreateMat(Math::Vector2 a_scl, float a_rot, Math::Vector2 a_pos, Math::Vector2 a_scroll = { 0, 0 });
	POINT GetMousePos(POINT a_mousepos);
	tTry CalcPythag(Math::Vector2 a_trgtpos, Math::Vector2 a_pos);
	float GetDeg(Math::Vector2 a_trgtpos, Math::Vector2 a_pos);
	float CnvrtToRadians(float a_deg);
	int	  RndBtwn(int a_arg1, int a_arg2);	// ２つの引数の間の乱数取得

private:



};

