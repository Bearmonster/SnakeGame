#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
namespace Snake
{
	ref class Circle
	{
	public:
		/*ref class X
	   {
	   public:
		   void SetX(int value)
		   {
			   x = value;
		   }
		   int GetX()
		   {
			   return x;
		   }
	   private:
			int x;
	   };
		ref class Y
		{
			void SetY(int value)
			{
				y = value;
			}
			int GetY()
			{
				return y;
			}
		private:
			int y;
		};*/
		Circle()
		{
			X = 0;
			Y = 0;
		}
		Circle(int x, int y)
		{
			X = x;
			Y = y;
		}
		void SetX(int value)
		{
			X = value;
		}
		void SetY(int value)
		{
			Y = value;
		}
		int GetX()
		{
			return X;
		}
		int GetY()
		{
			return Y;
		}
	private:
		int X, Y;
	};
}

