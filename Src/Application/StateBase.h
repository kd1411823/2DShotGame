#pragma once

template<typename OwnerType>
class C_StateMachine;

template<typename OwnerType> // �e���v���[�g�����ŏ�Ԃ��Ǘ�����Ώۂ̌^���w��
class C_StateBase
{
protected:

	friend class C_StateMachine<OwnerType>; // �X�e�[�g�}�V���ȊO����Ăяo���֐��ȂǂɃA�N�Z�X�ł��Ȃ��悤��

	// �X�e�[�g���n�܂�Ƃ��Ɉ�x�����Ă΂��֐�
	virtual void OnStart(OwnerType* a_p0wner) {} // �X�e�[�g�̎��������������擾�ł���悤��

	// �X�e�[�g���X�V���ꂽ�Ƃ��ɌĂ΂��֐�
	virtual void OnUpdate(OwnerType* a_p0wner) {}

	// �X�e�[�g���I������Ƃ��Ɉ�x�����Ă΂��֐�
	virtual void OnExit(OwnerType* a_p0wner) {}

private:

	// ���̏�Ԃ��Ǘ����Ă���X�e�[�g�}�V�����Z�b�g
	void SetMachine(C_StateMachine<OwnerType>* a_pMachine)
	{
		m_pMachine = a_pMachine;
	}

	// �J�n�֐����}�V������ĂԂ��߂̊֐�
	void CallStart(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnStart(a_p0wner);
	}

	// �X�V�֐����}�V������ĂԂ��߂̊֐�
	void CallUpdate(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnUpdate(a_p0wner);
	}

	// �I���֐����}�V������ĂԂ��߂̊֐�
	void CallExit(OwnerType* a_p0wner)
	{
		if (m_pMachine == nullptr || a_p0wner == nullptr)
		{
			return;
		}
		OnExit(a_p0wner);
	}

protected:

	C_StateMachine<OwnerType>* m_pMachine = nullptr; // ���̃X�e�[�g���Ǘ����Ă���X�e�[�g�}�V���̃|�C���^��ۑ�

	OwnerType* m_p0wner = nullptr;
};