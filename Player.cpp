#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

class Track
{
	std::string name = " ";
	std::time_t t = std::time(nullptr);
	std::tm date = *std::localtime(&t);
	int trackDuration = 0;
	/*std::cin >> std::get_time(&in.date, "%d/%m");*/

public:

	std::string getName()
	{
		return name;
	}
	void getDate()
	{
		std::cout << std::put_time(&date, "%d/%m/%y") << std::endl;
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

};

class Player
{
	Track playList[8]{};
	bool play = false;
	bool pause = false;
	Track current;

public:
	void setList()
	{

		for (int i = 0; i < 8; i++)
		{
			std::string name;
			int dur;
			std::cout << "Enter Track's name: ";
			std::cin >> name;
			playList[i].setName(name);
			std::cout << "Enter Day of creation(d/m/y): ";
			std::time_t t = std::time(nullptr);
			std::tm date = *std::localtime(&t);
			std::cin >> std::get_time(&date, "%d/%m/%y");
			playList[i].setDate(date);
			std::cout << "Enter Track's duration: ";
			std::cin >> dur;
			playList[i].setDuration(dur);

			//delete track;
		}
	}

	void pl()
	{
		if (!play && !pause)
		{
			std::string name;
			std::cout << "Enter track's name: ";
			std::cin >> name;
			for (int i = 0; i < 8; i++)
			{
				if (playList[i].getName() == name)
				{
					std::cout << "Track name: " << playList[i].getName() << std::endl;
					playList[i].getDate();
					std::cout << "Duration: " << playList[i].getDuration() << std::endl;
					current = playList[i];
				}
			}
			play = true;

		}
		else if (pause)
		{
			std::cout << "Pause off!" << std::endl;
			std::cout << "Track name: " << current.getName() << std::endl;
			current.getDate();
			std::cout << "Duration: " << current.getDuration() << std::endl;

			pause = false;
		}

	}

	void pa()
	{
		if (!pause)
		{
			std::cout << "Pause on!" << std::endl;
			pause = true;
		}
	}

	void ne()
	{
		int nextTrack = rand() % 8;
		std::cout << "Track name: " << playList[nextTrack].getName() << std::endl;
		playList[nextTrack].getDate();
		std::cout << "Duration: " << playList[nextTrack].getDuration() << std::endl;
		current = playList[nextTrack];
		play = true;
		pause = false;
	}

	void st()
	{
		if (play)
		{
			std::cout << "Stop!" << std::endl;
			play = false;
			pause = false;
		}
	}

	
};

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
	Player player;
	std::cout << "Loading tracks: " << std::endl;
	player.setList();
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
				player.pl();
				break;
			case operation::pause:
				player.pa();
				break;
			case operation::next:
				player.ne();
				break;
			case operation::stop:
				player.st();
				break;
			case operation::ex:
				
				return 0;

			}
		}


	}


}
