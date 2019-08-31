#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Threading::Tasks;
namespace Snake
{
	ref class Settings
	{
	public:
		enum class Directions 
		{
			Left, Right, Up, Down
		};

		void SetWidth(int value)
		{
			Width = value;
		}
		static int GetWidth()
		{
			return Width;
		}
		void SetHeigh(int value)
		{
			Height = value;
		}
		static int GetHeight()
		{
			return Height;
		}
		void SetSpeed(int value)
		{
			Speed = value;
		}
		static int GetSpeed()
		{
			return Speed;
		}
		static void SetScore(int value)
		{
			Score = value;
		}
		static int GetScore()
		{
			return Score;
		}
		void SetPoints(int value)
		{
			Points = value;
		}
		static int GetPoints()
		{
			return Points;
		}
		static void SetGameOver(bool value)
		{
			GameOver = value;
		}
		static bool GetGameover()
		{
			return GameOver;
		}
		static void SetDirection(Directions value)
		{
			direction = value;
		}
		static Directions GetDirection()
		{
			return direction;
		}
		 Settings()
		{
			 Width = 16;
			 Height = 16;
			 Speed = 200;
			 Score = 0;
			 Points = 100;
			 GameOver = false;
			 direction = Directions::Down;
		}
	private:
		static int Width;
		static int Height;
		static int Speed;
		static int Score;
		static int Points;
		static bool GameOver;
		static Directions direction;
		
	};
}
