#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;

using namespace System::Collections;
using namespace System::Windows::Forms;

namespace Snake
{
	ref class Imput
	{
	private:
		static Hashtable^ keyTable = gcnew Hashtable();
	public:
		static bool KeyPress(Keys key)
		{
			if (keyTable[key] == nullptr)
			{
				return false;
			}
			return (bool)keyTable[key];
		}
		static void changeState(Keys key, bool state)
		{
			keyTable[key] = state;
		}
	};
}
