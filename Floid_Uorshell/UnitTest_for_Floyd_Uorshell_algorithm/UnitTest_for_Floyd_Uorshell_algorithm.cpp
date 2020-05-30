#include "pch.h"
#include "CppUnitTest.h"
#include"../Input_data_from_file_function.h"
#include"../List.h"
#include"../Floyd_Uorshell_algorithm.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforFloydUorshellalgorithm
{
	TEST_CLASS(UnitTestforFloydUorshellalgorithm)
	{
	public:
		
		TEST_METHOD(TestExamplePath_is_avaible)
		{
			List<string>* list_fly = new List<string>();
			string city_Start = "Sochi";
			string city_End = "Moscow";
			InputDataFromFile(list_fly, "C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\LR3\\Floid_Uorshell\\UnitTest_for_Floyd_Uorshell_algorithm\\input1.txt");
			Matrix* matrix_floid_uorshell = new Matrix(list_fly);
			string cur = "The best route for the price: 30.000000\nRoute: Sochi -> Saint Petersburg -> Moscow ";
			Assert::AreEqual(matrix_floid_uorshell->Floid_Uorshell(city_Start, city_End), cur);
		}
		TEST_METHOD(TestExamplePath_is_not_avaible)
		{
			List<string>* list_fly = new List<string>();
			string city_Start = "Chita";
			string city_End = "Saint Petersburg";
			InputDataFromFile(list_fly, "C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\LR3\\Floid_Uorshell\\UnitTest_for_Floyd_Uorshell_algorithm\\input2.txt");
			Matrix* matrix_floid_uorshell = new Matrix(list_fly);
			string cur = "This route can't be built, try waiting for the flight schedule for tomorrow!";
			Assert::AreEqual(matrix_floid_uorshell->Floid_Uorshell(city_Start, city_End), cur);
		}
		TEST_METHOD(TestException_the_path_to_itself)
		{
			try {
				List<string>* list_fly = new List<string>();
				string city_Start = "Chita";
				string city_End = "Chita";
				InputDataFromFile(list_fly, "C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\LR3\\Floid_Uorshell\\UnitTest_for_Floyd_Uorshell_algorithm\\input2.txt");
				Matrix* matrix_floid_uorshell = new Matrix(list_fly);
			}
			catch (exception & ex) {
				string cur = "The path to itself is impossible!";
				Assert::AreEqual(ex.what(), cur.c_str());
			}
		}
		TEST_METHOD(TestException_file_is_missing)
		{
			try {
				List<string>* list_fly = new List<string>();
				InputDataFromFile(list_fly, "C:\\Users\\chere\\Desktop\\ÀèÑÄ-4ñåì\\LR3\\Floid_Uorshell\\UnitTest_for_Floyd_Uorshell_algorithm\\inpu.txt");
				string city_Start = "Chita";
				string city_End = "Chita";				
				Matrix* matrix_floid_uorshell = new Matrix(list_fly);
			}
			catch (exception & ex) {
				string cur = "File is  missing!";
				Assert::AreEqual(ex.what(), cur.c_str());
			}
		}
	};
}
