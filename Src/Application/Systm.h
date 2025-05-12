#pragma once
#define BIT18 18
#define BIT24 24
#define BIT32 32
#define BIT40 40
#define BIT64 64
#define BIT72 72
#define BIT108 108
#define BIT120 120
#define BIT128 128
#define BIT240 240
#define BIT256 256
#define BIT340 340
#define BIT512 512
#define WhlUp 120
#define WhlDwn -120
#define ScrnWid 1280
#define ScrnHgt 720
#define ScrnTop 360
#define ScrnBtm -360
#define ScrnRht 640
#define ScrnLft -640
#define PlayerBaseScl 0.15f
#define EnemyBaseScl 0.7f
#define EnemyMax 4
#define EnemyHpCircleScl 0.25f
#define EnemyCircleAlpha 0.6f
#define BulletNum 18
#define ebulletNum 6
#define pBulletLineNum 14
#define DropBulletNum 18
#define afterImageNum 7
#define pHighSpd 3.0f
#define pDefaultSpd 2.0f
#define pSlowSpd 0.8f
#define eHighSpd 1.2f
#define eDefaultSpd 0.7f
#define eSlowSpd 0.4f
#define EnemyHp 5.0f
#define DecreaseGCnt 7
#define OneScorescl 0.199f
#define TwoScorescl 0.49f
#define ThreeScorescl 0.75f
#define OneRadius 68.0f
#define TwoRadius 135.0f
#define ThreeRadius 203.0f
#define FourRadius 273.0f
#define oneTargetScore 500.0f
#define twoTargetScore 2000.0f
#define threeTargetScore 2600.0f
#define PredictionLineDistance 30.0f
#define ShotInterval 4
#define afterImageInterval 8
#define OneNumDistance 18.0f
#define TwoNumDistance 38.0f
#define ThreeNumDistance 38.0f
#define FourNumDistance 45.0f
#define OneNumScl 1.0f
#define TwoNumScl 2.0f
#define ThreeNumScl 2.0f
#define FourNumScl 2.5f
#define OnescoreTextScl 0.5f
#define TwoscoreTextScl 1.0f
#define ThreescoreTextScl 1.0f
#define FourscoreTextScl 1.5f
#define scoreDigits 4
#define scoreDrawDigits 3
#define timeDigits 3
#define timeScore 150.0f
#define initPos { 0, 0 }
#define gameNameText 2
#define gameStartText 2
#define keyNum 5
#define titleText 3
#define WHITE  1.0f,1.0f,1.0f
#define BLACK  0.0f,0.0f,0.0f
#define RED    1.00f, 0.08f, 0.50f
#define intenseRed 1.00f, 0.12f, 0.30f
#define GREEN  0.01f, 0.97f, 0.60f
#define BLUE   0.0f,0.0f,1.0f
#define YELLOW   1.0f,1.0f,0.0f

// �V�[���^�C�v
enum eSceneType
{
	TitleScene,
	GameScene
};

// �L�[�^�C�v
enum eKeyType
{
	Spaccekey,
	Dkey,
	Akey,
	Downkey,
	Rightkey,
	Leftkey,
	KeyNum
};

// �v���C���[���C�t
enum ePlayerLife
{
	OneLife,
	TwoLife,
	ThreeLife,
	FourLife,
	FiveLife,
};

// �G�̍s���p�^�[��
enum eEnemyMovCmd
{
	DefaultMov,
	HighMov
};

// �G�̓���(����)
enum eEnemyMovDir
{
	LeftDir,
	RightDir
};

// �z�u
enum AlgnType
{
	LtAlgn,	// �@������
	RtAlgn,	// �@�E����
	CtAlgn,	// ��������
};

// �s��
struct tMat
{
	Math::Matrix scalemat;
	Math::Matrix rotmat;
	Math::Matrix transmat;
	Math::Matrix compmat;
};

// �`��֌W
struct tDraw
{
	KdTexture* pTex;
	Math::Rectangle rct;
	Math::Color clr;
};

// �X�e�[�^�X
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

// �p�[�e�B�N���X�e�[�^�X
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

// �O�p�֐�
struct tTry
{
	float base;
	float hght;
	float hypn;
};

// �T�E���h�\����
struct tSnd
{
	std::shared_ptr<KdSoundEffect>	 data;	// �f�[�^
	std::shared_ptr<KdSoundInstance> inst;	// �X�s�[�J�[
	bool endFlg;							// �����I��������t���O (�d�����s��h��)
};

class C_Systm
{
public:

	C_Systm();
	~C_Systm();

	void Init();

	tMat CreateMat(Math::Vector2 a_scl, float a_rot, Math::Vector2 a_pos, Math::Vector2 a_scroll = { 0, 0 });
	POINT GetMousePos(POINT a_mousepos);
	tTry CalcPythag(Math::Vector2 a_trgtpos, Math::Vector2 a_pos);
	float GetDeg(Math::Vector2 a_trgtpos, Math::Vector2 a_pos);
	float CnvrtToRadians(float a_deg);
	int	  RndBtwn(int a_arg1, int a_arg2);	// �Q�̈����̊Ԃ̗����擾
	void  DrawStringGg(Math::Vector2 a_pos, Math::Vector2 a_scl, std::wstring a_str,
		Math::Color a_clr = { 1.0f, 1.0f, 1.0f, 1.0f }, float a_rot = 0, float a_distance = 30.0f);		// �I���W�i��DrawString


private:

	KdTexture ggfontTex;

};

