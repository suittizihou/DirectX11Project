#pragma once

namespace EvaEngine {
	class MainApp {
	private:
		MainApp() = default; 
		MainApp(const MainApp&);
		MainApp& operator=(const MainApp&);
		~MainApp() = default;

	public:
		static MainApp& Instance() {
			static MainApp instance{};
			return instance;
		}

		/// <summary>
		/// �E�B���h�E�ADirectX�A�Q�[���G���W���̏�������S�����
		/// </summary>
		/// <returns></returns>
		bool Init();

		/// <summary>
		/// ���C�����[�v�ɓ���
		/// </summary>
		/// <returns></returns>
		int Run();
	};
}