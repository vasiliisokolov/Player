#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>


class Track;
class Player;

enum operation
{
	play = 0,
	pause = 1,
	next = 2,
	stop = 3,
	ex = 4
};

int main()
{
	int op;
	std::cout << "Audio Player." << std::endl;
	Player* player = new Player();
	std::cout << "Loading tracks: " << std::endl;
	player->setList();
	while (true)
	{
		std::cout << "Choose the operation: ";
		std::cin >> op;
		if (op > 4 || op < 0)
		{
			std::cerr << "Error! Wrong operation! Try again!" << std::endl;
		}
		else
		{
			switch (op)
			{
			case operation::play:
				player->pl();
				break;
			case operation::pause:

				break;
			case operation::next:

				break;
			case operation::stop:

				break;
			case operation::ex:
				delete player;
				return 0;

			}
		}


	}


}

class Track
{
	std::string name = "";
	std::time_t t = std::time(nullptr);
	std::tm date = *std::localtime(&t);
	int trackDuration = 0;
	/*std::cin >> std::get_time(&in.date, "%d/%m");*/

public:

	std::string getName()
	{
		return name;
	}
	std::tm getDate()
	{
		return date;
	}
	int getDuration()
	{
		return trackDuration;
	}
	void setName(std::string& newName)
	{
		name = newName;
	}
	void setDate(std::tm& newDate)
	{
		date = newDate;
	}
	void setDuration(int& newDuration)
	{
		trackDuration = newDuration;
	}
	void getInfo(Track* track)
	{
		std::cout << "Track name: " << track->name << " , track date: "
			<< std::put_time(&track->date, "%d/%m/%y") << " , duration: " << track->trackDuration << std::endl;
	}
};

class Player
{
	std::map<std::string, Track> playList{};
	bool play = false;

public:
	void setList()
	{
		
		for (int i = 0; i < 8; i++)
		{
			std::string name;
			int dur;
			Track* track = new Track();
			std::cout << "Enter Track's name: ";
			std::cin >> name;
			track->setName(name);
			std::cout << "Enter Day of creation: ";
			std::time_t t = std::time(nullptr);
			std::tm date = *std::localtime(&t);
			std::cin >> std::get_time(&date, "%d/%m/%y");
			track->setDate(date);
			std::cout << "Enter Track's duration: ";
			std::cin >> dur;
			track->setDuration(dur);
			playList.insert(std::pair<std::string, Track>(name, *track));
			//delete track;
		}
	}

	void pl()
	{
		if (!play)
		{
			std::string name;
			std::cout << "Enter track's name: ";
			std::cin >> name;
			std::map<std::string, Track> :: iterator it = playList.find(name);
			Track temp = (it->second);
			std::cout << "Track name: " << Track::getName() << " , track date: "
				<< std::put_time(&track->date, "%d/%m/%y") << " , duration: " << track->trackDuration << std::endl;
			play = true;

		}
		
	}


};


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
