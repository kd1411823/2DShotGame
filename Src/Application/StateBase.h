#pragma once

template<typename OwnerType>
class C_StateMachine;

template<typename OwnerType> // テンプレート引数で状態を管理する対象の型を指定
class C_StateBase
{
protected:

	friend class C_StateMachine<OwnerType>; // ステートマシン以外から呼び出し関数などにアクセスできないように

	// ステートが始まるときに一度だけ呼ばれる関数
	virtual void OnStart(OwnerType* a_p0wner) {} // ステートの持ち主を引数から取得できるように

	// ステートが更新されたときに呼ばれる関数
	virtual void OnUpdate(OwnerType* a_p0wner) {}

	// ステートが終了するときに一度だけ呼ばれる関数
	virtual void OnExit(OwnerType* a_p0wner) {}

private:

	// この状態を管理しているステートマシンをセット
	void SetMachine(C_StateMachine<OwnerType>* a_pMachine)
	{
		m_pMachine = a_pMachine;
	}

	// 開始関数をマシンから呼ぶための関数
	void CallStart(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnStart(a_p0wner);
	}

	// 更新関数をマシンから呼ぶための関数
	void CallUpdate(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnUpdate(a_p0wner);
	}

	// 終了関数をマシンから呼ぶための関数
	void CallExit(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnExit(a_p0wner);
	}

protected:

	C_StateMachine<OwnerType>* m_pMachine = nullptr; // このステートを管理しているステートマシンのポインタを保存

	OwnerType* m_p0wner = nullptr;
};