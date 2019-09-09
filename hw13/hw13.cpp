/*
Helen Li
October 19, 2018
Homework #13
*/

#include <iostream>
using namespace std;

const int INITIAL_BUGS = 5;
const int INITIAL_ANTS = 100;

const int GRID = 20;
const int BREED_ANT = 3;
const int BREED_BUG = 8;
const int STARVE_BUG = 3;

const int CRITTER_BUG = 1;
const int CRITTER_ANT = 2;

class Organism;
class World;
class Ant;
class Doodlebug;

class Organism
{
	friend class World;

public:
 	Organism();
 	Organism(World *world, int x, int y);
  	virtual int getCritter() = 0;
  	virtual void move() = 0;
  	virtual void breed() = 0;
  	virtual bool starve() = 0;

protected:
  	int x, y;
  	int breedCount;
  	int moved;
  	World* world;
};

class World
{
  	friend class Organism;
  	friend class Doodlebug;
  	friend class Ant;

public:
  	World();
  	Organism* getPosition(int x, int y);
  	void setPosition(int x, int y, Organism* organism);
  	void printGrid();
  	void nextStep();

private:
  	Organism* grid[GRID][GRID];
};

Organism::Organism()
{
  	x = 0;
  	y = 0;
  	breedCount = 0;
  	moved = false;
  	world = NULL;
}

Organism::Organism(World* world, int x, int y)
{
  	this -> x = x;
  	this -> y = y;
  	breedCount = 0;
  	moved = false;
  	this -> world = world;
  	world -> setPosition(x, y, this);
}

World::World()
{
  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      	grid[i][j] = NULL;
    	}
  	}
}

Organism* World::getPosition(int x, int y)
{
  	if((x >= 0) && (x < GRID) && (y >= 0) && (y < GRID))
  	{
    	return grid[x][y];
  	}
  	return NULL;
}

void World::setPosition(int x, int y, Organism* organism)
{
  	if((x >= 0) && (x < GRID) && (y >= 0) && (y < GRID))
  	{
    	grid[x][y] = organism;
  	}
}

void World::printGrid()
{
  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      	if(grid[i][j] == NULL)
        	cout << "-";
      	else if(grid[i][j] -> getCritter() == CRITTER_ANT)
        	cout << "o";
      	else
        	cout << "X";
    	}
	cout << endl;
  	}
}

void World::nextStep()
{
  	cout << endl;

  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      		if(grid[i][j] != NULL)
      		{
        		grid[i][j] -> moved = false;
      		}
    	}
  	}

  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      		if((grid[i][j] != NULL) && (grid[i][j] -> getCritter() == CRITTER_BUG))
      		{
        		if(grid[i][j] -> moved == false)
        		{
          			grid[i][j] -> moved = true;
          			grid[i][j] -> move();
        		}
      		}
    	}
  	}

  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      		if((grid[i][j] != NULL) && (grid[i][j] -> getCritter() == CRITTER_ANT))
      		{
        		if(grid[i][j] -> moved == false)
        		{
          			grid[i][j] -> moved = true;
          			grid[i][j] -> move();
        		}
      		}
    	}
  	}

  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      		if((grid[i][j] != NULL) && (grid[i][j] -> getCritter() == CRITTER_BUG))
      		{
        		if(grid[i][j] -> starve())
        		{
          			grid[i][j] = NULL;
        		}
      		}
    	}
  	}

  	for(int i = 0; i < GRID; i++)
  	{
    	for(int j = 0; j < GRID; j++)
    	{
      		if((grid[i][j] != NULL) && (grid[i][j] -> moved == true))
      		{
        		grid[i][j] -> breed();
      		}
    	}
  	}
}

class Ant : public Organism
{
  	friend class World;

public:
  	Ant();
  	Ant(World* world, int x, int y);
  	int getCritter();
  	void move();
  	void breed();
  	bool starve();
};

Ant::Ant() : Organism() {}

Ant::Ant(World* world, int x, int y) : Organism(world, x, y) {}

int Ant::getCritter()
{
  	return CRITTER_ANT;
}

void Ant::move()
{
  	int num = rand() % 4;

  	switch(num)
  	{
    	case 0:
      		if((y > 0) && (world -> getPosition(x, y - 1) == NULL))
      		{
        		world -> setPosition(x, y - 1, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		y--;
      		}
      		break;
    	case 1:
      		if((y < GRID - 1) && (world -> getPosition(x, y + 1) == NULL))
      		{
        		world -> setPosition(x, y + 1, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		y++;
      		}
      		break;
    	case 2:
      		if((x > 0) && (world -> getPosition(x - 1, y) == NULL))
      		{
        		world -> setPosition(x - 1, y, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		x--;
      		}
      		break;
    	case 3:
      		if((x < GRID - 1) && (world -> getPosition(x + 1, y) == NULL))
      		{
        		world -> setPosition(x + 1, y, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		x++;
      		}
      		break;
    	default:
      		cout << "Invalid agrument" << endl;
      		break;
  	}
}

void Ant::breed()
{
  	breedCount++;

  	if(breedCount == BREED_ANT)
  	{
    	breedCount = 0;
    	if((y > 0) && (world -> getPosition(x, y - 1) == NULL))
      		Ant* ant = new Ant(world, x, y - 1);
    	else if((y < GRID - 1) && (world -> getPosition(x, y + 1) == NULL))
      		Ant* ant = new Ant(world, x, y + 1);
    	else if((x > 0) && (world -> getPosition(x - 1, y) == NULL))
      		Ant* ant = new Ant(world, x - 1, y);
    	else if((x < GRID - 1) && (world -> getPosition(x + 1, y) == NULL))
      		Ant* ant = new Ant(world, x + 1, y);
  	}
}

bool Ant::starve()
{
  	return false;
}

class Doodlebug : public Organism
{
  	friend class World;

public:
  	Doodlebug();
  	Doodlebug(World* world, int x, int y);
  	int getCritter();
  	void move();
  	void breed();
  	bool starve();

private:
  	int starveCount;
};

Doodlebug::Doodlebug() : Organism()
{
  	starveCount = 0;
}

Doodlebug::Doodlebug(World* world, int x, int y) : Organism(world, x, y)
{
  	starveCount = 0;
}

int Doodlebug::getCritter()
{
  	return CRITTER_BUG;
}

void Doodlebug::move()
{
  	if((y > 0) && (world -> getPosition(x, y - 1) != NULL) && (world -> getPosition(x, y - 1) -> getCritter() == BREED_ANT))
  	{
    	world -> grid[x][y - 1] = this;
    	world -> setPosition(x, y, NULL);
    	starveCount = 0;
    	y--;
    	return;
  	}
  	else if((y < GRID - 1) && (world -> getPosition(x, y + 1) != NULL) && (world -> getPosition(x, y + 1) -> getCritter() == BREED_ANT))
  	{
    	world -> grid[x][y + 1] = this;
    	world -> setPosition(x, y, NULL);
    	starveCount = 0;
    	y++;
    	return;
  	}
  	else if((x > 0) && (world -> getPosition(x - 1, y) != NULL) && (world -> getPosition(x - 1, y) -> getCritter() == BREED_ANT))
  	{
    	world -> grid[x - 1][y] = this;
    	world -> setPosition(x, y, NULL);
    	starveCount = 0;
    	x--;
    	return;
  	}
  	else if((x < GRID - 1) && (world -> getPosition(x + 1, y) != NULL) && (world -> getPosition(x + 1, y) -> getCritter() == BREED_ANT))
  	{
    	world -> grid[x + 1][y] = this;
    	world -> setPosition(x, y, NULL);
    	starveCount = 0;
    	x++;
    	return;
  	}

  	int num = rand() % 4;

  	switch(num)
  	{
    	case 0:
      		if((y > 0) && (world -> getPosition(x, y - 1) == NULL))
      		{
        		world -> setPosition(x, y - 1, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		y--;
      		}
      		break;
    	case 1:
      		if((y < GRID - 1) && (world -> getPosition(x, y + 1) == NULL))
      		{
        		world -> setPosition(x, y + 1, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		y++;
      		}
      		break;
    	case 2:
      		if((x > 0) && (world -> getPosition(x - 1, y) == NULL))
      		{
        		world -> setPosition(x - 1, y, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		x--;
      		}
      		break;
    	case 3:
      		if((x < GRID - 1) && (world -> getPosition(x + 1, y) == NULL))
      		{
        		world -> setPosition(x + 1, y, world -> getPosition(x, y));
        		world -> setPosition(x, y, NULL);
        		x++;
      		}
      		break;
    	default:
      		cout << "Invalid agrument" << endl;
      		break;
  	}

  	starveCount++;
}

void Doodlebug::breed()
{
  	breedCount++;

  	if(breedCount == BREED_BUG)
  	{
    	breedCount = 0;
    	if((y > 0) && (world -> getPosition(x, y - 1) == NULL))
      		Doodlebug* doodlebug = new Doodlebug(world, x, y - 1);
    	else if((y < GRID - 1) && (world -> getPosition(x, y + 1) == NULL))
      		Doodlebug* doodlebug = new Doodlebug(world, x, y + 1);
    	else if((x > 0) && (world -> getPosition(x - 1, y) == NULL))
      		Doodlebug* doodlebug = new Doodlebug(world, x - 1, y);
    	else if((x < GRID - 1) && (world -> getPosition(x + 1, y) == NULL))
      		Doodlebug* doodlebug = new Doodlebug(world, x + 1, y);
  	}
}

bool Doodlebug::starve()
{
  	if(starveCount > STARVE_BUG)
    	return true;
  	else
    	return false;
}

int main()
{
  	srand(time(0));

  	World worlds;
  	int antCount = 0;
  	int bugCount = 0;
  	int x, y;
  	string generateStep;

  	while(antCount < INITIAL_ANTS)
  	{
    	x = rand() % GRID;
    	y = rand() % GRID;

    	if(worlds.getPosition(x, y) == NULL)
    	{
      		antCount++;
      		Ant* ants = new Ant(&worlds, x, y);
    	}
  	}

  	while(bugCount < INITIAL_BUGS)
  	{
    	x = rand() % GRID;
    	y = rand() % GRID;

    	if(worlds.getPosition(x, y) == NULL)
    	{
      		bugCount++;
      		Doodlebug* doodlebugs = new Doodlebug(&worlds, x, y);
    	}
  	}

  	cout << endl;

  	while(true)
  	{
  		worlds.printGrid();
  		worlds.nextStep();

  		cout << "Press 'enter' to generate the next step" << endl;
  		getline(cin, generateStep);
  	}

  	return 0;
}
