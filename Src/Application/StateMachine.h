#pragma once
#include "StateBase.h"

template<typename OwnerType> // テンプレート引数で状態を管理する対象の型を指定
class C_StateMachine
{
public:

	C_StateMachine()
		:m_fnChangeState([]() {})
	{

	}

	// ステートの開始関数
	void Start(OwnerType* a_p0wner) // 初期化時にownerをセット
	{
		m_p0wner = a_p0wner;
		m_fnChangeState = []() {};
	}

	// 状態を変更する関数
	// 引数はステートのコンストラクタに渡す値
	// ステートの変更処理を関数ポインタの中に閉じ込め更新が終わった後に呼ぶ
	template<typename StateType, typename...ArgType> // ステートの型を指定したらインスタンスを作成し、コンストラクタ値を渡せるように変更
	void ChangeState(ArgType...a_args)
	{
		// ステートの変更命令を格納する
		m_fnChangeState = [&]() // ステートの変更命令を関数ポインタに格納する
			{
				// オーナーがセットされてなければ何もしない
				if (m_p0wner == nullptr)
				{
					return;
				}

				// もしすでにステートがセットされていたら終了する
				if (m_spNowState != nullptr)
				{
					m_spNowState->CallExit(m_p0wner);
					m_spNowState = nullptr;
				}

				// 新しいステートを作成
				m_spNowState = std::make_shared<StateType>(a_args...);
				if (m_spNowState == nullptr)
				{
					return;
				}
				// 新しいステートにこのマシンをセット
				m_spNowState->SetMachine(this);
				// ステートの開始
				m_spNowState->CallStart(m_p0wner);
			};
	}


	// 更新関数
	void Update()
	{
		// ステートの変更命令があれば処理する
		m_fnChangeState();
		m_fnChangeState = []() {};

		// ステートがセットされていたら更新する
		if (m_spNowState != nullptr)
		{
			m_spNowState->CallUpdate(m_p0wner);
		}
	}



private:

	// 状態の持ち主のポインタ
	OwnerType* m_p0wner = nullptr;

	// 今のステート
	std::shared_ptr<C_StateBase<OwnerType>> m_spNowState = nullptr;

	// ステートの変更命令を保存しておく関数オブジェクト
	std::function<void()> m_fnChangeState;
};