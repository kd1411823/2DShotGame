#pragma once
#include "StateBase.h"

template<typename OwnerType> // �e���v���[�g�����ŏ�Ԃ��Ǘ�����Ώۂ̌^���w��
class C_StateMachine
{
public:

	C_StateMachine()
		:m_fnChangeState([]() {})
	{

	}

	// �X�e�[�g�̊J�n�֐�
	void Start(OwnerType* a_p0wner) // ����������owner���Z�b�g
	{
		m_p0wner = a_p0wner;
		m_fnChangeState = []() {};
	}

	// ��Ԃ�ύX����֐�
	// �����̓X�e�[�g�̃R���X�g���N�^�ɓn���l
	// �X�e�[�g�̕ύX�������֐��|�C���^�̒��ɕ����ߍX�V���I�������ɌĂ�
	template<typename StateType, typename...ArgType> // �X�e�[�g�̌^���w�肵����C���X�^���X���쐬���A�R���X�g���N�^�l��n����悤�ɕύX
	void ChangeState(ArgType...a_args)
	{
		// �X�e�[�g�̕ύX���߂��i�[����
		m_fnChangeState = [&]() // �X�e�[�g�̕ύX���߂��֐��|�C���^�Ɋi�[����
			{
				// �I�[�i�[���Z�b�g����ĂȂ���Ή������Ȃ�
				if (m_p0wner == nullptr)
				{
					return;
				}

				// �������łɃX�e�[�g���Z�b�g����Ă�����I������
				if (m_spNowState != nullptr)
				{
					m_spNowState->CallExit(m_p0wner);
					m_spNowState = nullptr;
				}

				// �V�����X�e�[�g���쐬
				m_spNowState = std::make_shared<StateType>(a_args...);
				if (m_spNowState == nullptr)
				{
					return;
				}
				// �V�����X�e�[�g�ɂ��̃}�V�����Z�b�g
				m_spNowState->SetMachine(this);
				// �X�e�[�g�̊J�n
				m_spNowState->CallStart(m_p0wner);
			};
	}


	// �X�V�֐�
	void Update()
	{
		// �X�e�[�g�̕ύX���߂�����Ώ�������
		m_fnChangeState();
		m_fnChangeState = []() {};

		// �X�e�[�g���Z�b�g����Ă�����X�V����
		if (m_spNowState != nullptr)
		{
			m_spNowState->CallUpdate(m_p0wner);
		}
	}



private:

	// ��Ԃ̎�����̃|�C���^
	OwnerType* m_p0wner = nullptr;

	// ���̃X�e�[�g
	std::shared_ptr<C_StateBase<OwnerType>> m_spNowState = nullptr;

	// �X�e�[�g�̕ύX���߂�ۑ����Ă����֐��I�u�W�F�N�g
	std::function<void()> m_fnChangeState;
};