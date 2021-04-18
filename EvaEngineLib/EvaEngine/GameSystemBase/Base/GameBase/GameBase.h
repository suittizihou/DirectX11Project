#pragma once

namespace EvaEngine {
	/// <summary>
	/// ������G���g���[�|�C���g�̂悤�ȃN���X�BInit���I�[�o�[���[�h���ăV�[����o�^�����肷��̂Ɏg���B
	/// </summary>
	class GameBase {
	public:
		GameBase(const unsigned int windowWidth, const unsigned int windowHeight);
		~GameBase();

		/// <summary>
		/// �Q�[���J�n���ɂ���Ă������������������Ƃ����I�[�o�[���[�h���ď���
		/// </summary>
		virtual void Init() = 0;

		static GameBase* Instance();

	private:
		static GameBase* m_GameBase;
	};
}