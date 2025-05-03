#pragma once
#include "GameObjectBase.h"
#include "Time_ClockCircle.h"
#include "Time_ClockHands.h"
#include "Time_ClockNumber.h"

class C_TimeManager :public C_GameObject
{
public:

	C_TimeManager();
	~C_TimeManager();

	void Init()override;
	void Draw()override;
	void Update()override;
	void Action()override;
	void Timer();

	void SetTimer(int a_timer) { m_timer = a_timer; }
	void SetIsTimeLeftFlg(bool a_isTimeLeftFlg) { m_isTimeLeftFlg = a_isTimeLeftFlg; }

	C_Time_ClockCircle* GetTimeClockCircle() { return &m_timeClockCircle; }
	C_Time_ClockHands* GetTimeClockHands()	 { return &m_timeClockHands; }
	C_Time_ClockNumber* GetTimeClockNumber(int a_no) { return &m_timeClockNumber[a_no]; }

	int GetTimer() { return m_timer; }
	bool GetIsTimeLeftFlg() { return m_isTimeLeftFlg; }

private:

	KdTexture numberTex;

	C_Time_ClockCircle m_timeClockCircle;
	C_Time_ClockHands	m_timeClockHands;
	C_Time_ClockNumber m_timeClockNumber[timeDigits];

	int m_frameTime; // �t���[��
	int m_timer; // �^�C�}�[
	bool m_isTimeLeftFlg; // �^�C�����c���Ă��邩���Ȃ���(true:�c���Ă��� false:�c���Ă��Ȃ�)
};

