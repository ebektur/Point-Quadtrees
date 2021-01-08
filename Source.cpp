#include "Tree.h"


int main()
{

	const string ITEM_NOT_FOUND = "item is not found";
	string line;
	string line2;

	ifstream myfile2("queries.txt");
	ifstream myfile("cities.txt");
	stringstream ss;
	stringstream queries;
	//Node* rootPtr = nullptr; //root of newly created node with each line

	//data variables from the text
	int upperrightx, upperrighty;
	string city;
	bool blankcheck = false;
	int coord_x, coord_y;
	Tree mytree(ITEM_NOT_FOUND);

	//--for search--
	int searchx, searchy;
	unsigned int radius;

	if (myfile.is_open())
	{
		getline(myfile, line);
		ss << line;
		ss >> upperrightx >> upperrighty; //catch negative numbers

		if (upperrightx > 0 && upperrighty > 0)
		{
			while (getline(myfile, line))
			{
				istringstream ss(line);
				//ss << line;
				ss >> city >> coord_x >> coord_y;

				//City names do not contain space characters and the coordinates cannot assume negative
				//values.
				for (int i = 0; i < city.length(); i++)
				{
					if (isspace(city[i]) == true)
					{
						blankcheck = true;
					}
				}

				if (coord_x >= 0 && coord_y >= 0 && blankcheck == false)
				{
					mytree.insert(coord_x, coord_y, city);

				}
			}
			//myfile.close();
		}
	}
	else { cout << "Unable to open file"; }

	//--



	if (myfile2.is_open())
	{
		//getline(myfile2, line2);
		//queries << line2;
		//queries >> searchx >> upperrighty; //catch negative numbers


		while (getline(myfile2, line2))
		{
			string str2(line2.size(), '0');
			str2.erase(remove_copy(line2.begin(), line2.end(), str2.begin(), ','), str2.end());

			istringstream queries(str2);
			queries >> searchx >> searchy >> radius;

			if (searchx >= 0 && searchy >= 0 && radius >= 0)
			{
				mytree.search(searchx, searchy, radius);
			}
			//catch for coord conditions and city space cond.
			PrintVectors();

		}
		myfile.close();
	}

	else { cout << "Unable to open file"; }

	//PrintVectors();

	return 0;
}