/*
 * Program:   rmb0047_1.cpp
 * Name:      Rebecca Brannan
 * Date:      11/10/2017
 * E-mail:    rmb0047@auburn.edu
 * 
 * Description:  This is ta snakes and ladders maze game.
 * */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Node {
	private:
		Node *attachedNodes[4];
		Node *snakeOrLadderNodes;
	public:
	string name;
/*
 * Function:    	Node()     
 * Inputs:			string newname
 * Outputs:			none
 * Description:		The constructor for Nodes.
 * */
		Node(string newname) {
				name = newname;
				attachedNodes[0] = NULL;
				attachedNodes[1] = NULL;
				attachedNodes[2] = NULL;
				attachedNodes[3] = NULL;
		}
/*
 * Function:    	Node()     
 * Inputs:			none
 * Outputs:			none
 * Description:		The default constructor.
 * */
		Node() {
			name = "*";
			attachedNodes[0] = NULL;
			attachedNodes[1] = NULL;
			attachedNodes[2] = NULL;
			attachedNodes[3] = NULL;
		}
/*
 * Function:    	getNodeName()     
 * Inputs:			none
 * Outputs:			a string
 * Description:		Returns the name of a node.
 * */
		string getNodeName() {
			return name;
		}
/*
 * Function:    	attachNode()     
 * Inputs:			Node and int direction
 * Outputs:			none
 * Description:		Attaches a new node in the inputted direction.
 * */
		void attachNewNode(Node *newNode, int direction) {
			attachedNodes[direction] = newNode;
		}      
/*
 * Function:    	getAttachedNode()     
 * Inputs:			int direction
 * Outputs:			a node
 * Description:		Finds the node at the inputted direction.
 * */    
		Node *getAttachedNode(int direction) {
			return attachedNodes[direction];
		}
/*
 * Function:    	attachSnakeLadderNode()     
 * Inputs:			a node
 * Outputs:			none
 * Description:		Attaches the snake or ladder node attached to a node.
 * */         
		void attachSnakeLadderNode(Node *newNode) {
			snakeOrLadderNodes = newNode;
		}
/*
 * Function:    	getSnakeLadderNode()     
 * Inputs:			none
 * Outputs:			a node
 * Description:		Finds the snake or ladder node attached to a node.
 * */
		Node *getSnakeLadderNode() {
			return snakeOrLadderNodes;
		}         
};

class Player {
	private:
		vector<string> nodesVisited;
		string name;
		Node *currentNode;
	public:
		int steps;
/*
 * Function:    	Player()     
 * Inputs:			none
 * Outputs:			none
 * Description:		The default constructor for players.
 * */
		Player() {}
/*
 * Function:    	Player()     
 * Inputs:			string name
 * Outputs:			none
 * Description:		The constructor for players.
 * */
		Player(string nameIn){
			name = nameIn;
		}
/*
 * Function:    	visitNode()     
 * Inputs:			string n
 * Outputs:			none
 * Description:		Keeps track of the nodes the player has visited.
 * */
		void visitNode(string n) {
			nodesVisited.push_back(n);
		}
/*
 * Function:    	getNodesVisited()     
 * Inputs:			none
 * Outputs:			vector<string>
 * Description:		Returns the vector of the names of the nodes the player has visited.
 * */
		vector<string> getNodesVisited() {
			return nodesVisited;
		}
/*
 * Function:    	getName()     
 * Inputs:			none
 * Outputs:			string
 * Description:		Returns the player's name.
 * */
		string getName() {
			return name;
		}
		
/*
 * Function:    	getCurrentNode()     
 * Inputs:			none
 * Outputs:			Node
 * Description:		Returns the current node the player is at.
 * */
		Node *getCurrentNode(){
			return currentNode;
		}

/*
 * Function:    	Player()     
 * Inputs:			Node
 * Outputs:			none
 * Description:		Sets the player's current node.
 * */		
		void setCurrentNode(Node *newNode) {
			currentNode = newNode; 
		}
};


class System {
	private:
		int numOfPlayers;
		int numOfNodes;
		Node *startNode;
		Node *destinationNode;
		Player* winner;
	public:
		std::vector<Node*> nodes;
		std::vector<Player*> players;
/*
 * Function:    	getNumOfPlayers()     
 * Inputs:			none
 * Outputs:			int
 * Description:		Returns the number of players.
 * */
		int getNumOfPlayers() {
			return numOfPlayers;
		}
/*
 * Function:    	setWinner()     
 * Inputs:			Player 
 * Outputs:			none
 * Description:		Sets the winner of the game.
 * */
		void setWinner(Player* p) {
			winner = p;
		}

/*
 * Function:    	getWinner()     
 * Inputs:			none
 * Outputs:			Player
 * Description:		Returns the winner of the game.
 * */
		Player* getWinner() {
			return winner;
		}

/*
 * Function:    	setNumOfPlayers()     
 * Inputs:			int
 * Outputs:			none
 * Description:		Sets the number of players to the inputted number.
 * */
		void setNumOfPlayers(int num) {
			numOfPlayers = num;
		}
		
/*
 * Function:    	getStartNode()     
 * Inputs:			none
 * Outputs:			Node
 * Description:		Returns the starting node.
 * */
		Node *getStartNode() {
			return startNode;
		}

/*
 * Function:    	getNode()     
 * Inputs:			string n
 * Outputs:			Node
 * Description:		Returns a node with the inputted string as a name.
 * */
		Node *getNode(string n) {
			for (int i = 0; i < (int)nodes.size(); i++) {
				if (nodes[i]->getNodeName() == n) {
					return nodes[i];
				}
			}
			return new Node();
		}

/*
 * Function:    	setStartNode()     
 * Inputs:			Node
 * Outputs:			none
 * Description:		Sets the start node for the game.
 * */
		void setStartNode(Node *newNode) {
			startNode = newNode;
		}
		
/*
 * Function:    	getDestinationNode()     
 * Inputs:			none
 * Outputs:			Node
 * Description:		Returns the destination node.
 * */
		Node *getDestinationNode() {
			return  destinationNode;
		}
		
/*
 * Function:    	setDestinationNode()     
 * Inputs:			Node
 * Outputs:			none
 * Description:		Sets the destination node for the game.
 * */
		void setDestinationNode(Node *newNode){
			destinationNode = newNode;
		}
		
/*
 * Function:    	getPlayers()     
 * Inputs:			none
 * Outputs:			vector<Player*>
 * Description:		Returns the players of the game.
 * */
		vector<Player*> getPlayers(){
			return players;
		}
		
/*
 * Function:    	generateGraph()     
 * Inputs:			string 
 * Outputs:			none
 * Description:		Generates the graph for the game.
 * */
		void generateGraph(string file) {
			//ifstream fileReader(file.c_str()); escape white space
			string line = "";
			string attached[6] = {"", "", "", "", "", ""};

			if (fileExists(file)) {
				ifstream fileReader(file.c_str());
				getline(fileReader, line, '\n');
				stringstream ss(line);
				int n;
				ss >> n;
				setNumOfNodes(n);
				
				getline(fileReader, line, '\n');
				Node* start = new Node(line);
				setStartNode(start);
					
				getline(fileReader, line, '\n');
				Node* end = new Node(line);
				setDestinationNode(end);
					
				while(!fileReader.eof()) {
						getline(fileReader, line, '\n');
						attached[0] = line.substr(0, 2);
							int index = 1;
							for (int i = 1; i < (int)line.length(); i++) {
								int s = line.find_first_of(' ', i);
								int s2 = line.find(' ', s + 1);
								if (s2 == -1) {
									s2 = line.length();
								}
								if (s2 - s == 2) {
									attached[index] = "*";
								}
								else if (s2 - s > 2) {
									attached[index] = line.substr(s + 1, 2);
								}
								i = s2 - 1;
								if (s2 == (int)line.length() - 1 || index == 6) {
									break;
								}
								index++;
							}
							Node* n;
							for (int i = 0; i < 6; i++) {
								if (i == 0) { 
									n = new Node(attached[i]);
								}
								if (i > 0 && i != 5) {
									Node* node = new Node(attached[i]);
									int d = i - 1;
									n -> attachNewNode(node, d);
								}
								if (i == 5) {
									Node* sl = new Node(attached[i]);
									n-> attachSnakeLadderNode(sl);
									nodes.push_back(n);
									if (start -> name == n -> name) {
										setStartNode(n);
									}
								}
							}
					}
					
				}
			 else {
				
			}
		}
	
/*
 * Function:    	generateDiceRoll()     
 * Inputs:			none
 * Outputs:			int
 * Description:		Returns a random number from 1 - 6.
 * */
		int generateDiceRoll() {
			int num = rand() % 7;
			return num;
		}

/*
 * Function:    	addPlayer()     
 * Inputs:			Player
 * Outputs:			none
 * Description:		Adds a player to the game.
 * */
		void addPlayer(Player* p) {
			players.push_back(p);
		}
		
/*
 * Function:    	setNumOfNodes()     
 * Inputs:			int n
 * Outputs:			none
 * Description:		Sets the number of nodes in the graph.
 * */
		void setNumOfNodes(int n) {
			numOfNodes = n;
		}

/*
 * Function:    	getNumOfNodes()     
 * Inputs:			none
 * Outputs:			int
 * Description:		Returns the number of nodes in the graph.
 * */
		int getNumOfNodes(){
			return numOfNodes;
		}
		
/*
 * Function:    	fileExists()     
 * Inputs:			string file
 * Outputs:			boolean
 * Description:		Returns whether or not a file exists.
 * */
		bool fileExists(string file) {
			ifstream f(file.c_str());
			return f.good();
		}
		
/*
 * Function:    	playerTurn()     
 * Inputs:			Player and int
 * Outputs:			boolean
 * Description:		Controls the player's turn and returns whether they are at the destination or not.
 * */
		bool playerTurn(Player* p, int indexNum) {
			bool atDestination = false;
			string output = "";
			cout << "\n=====================" << endl;
			cout << "| " << p->getName() << "'s turn.   |" << endl;
			cout << "===================== " << endl;
			cout << "\nEnter 'Q' to quit the game when prompted for direction." << endl;
			cout << "\n" << p->getName() << "'s turn to throw the dice. Just hit enter.";
			
			
		    int diceRoll = generateDiceRoll();
		    cout << "\n" << p->getName() << "'s dice roll is " << diceRoll << endl;
		    cout << p->getName() << " can move to " << diceRoll << " nodes" << endl;
		   
		   for (int k = 0; k < diceRoll; k++) {
			p->visitNode(p->getCurrentNode()->getNodeName());
			//if(p->getCurrentNode()->getSnakeLadderNode()->getNodeName() != "*") {
		//		p->setCurrentNode(p->getCurrentNode()->getSnakeLadderNode());
		//		cout << "\n" << p->getName() << " took a snake or ladder node to " << p->getCurrentNode()->getNodeName() << endl;
		//	}
		//    else {
			vector<string> directions = getValidDirections(p->getCurrentNode());
		  
		    cout << "\n" << p->getName() << " is in node " << p->getCurrentNode() -> getNodeName() << " of the Maze Game, you can go ";
		    for (int i = 0; i < (int)directions.size(); i++) {
				if ((int)directions.size() == 1) {
					cout << directions[i];
				} else {
					cout << directions[i] << " ";
				}
			}
			cout << ". What is your choice? ";
			char choice;
			cin >> choice;
			p = move(choice, p);
			players[indexNum] = p;
			directions.clear();
			p->steps++;
			if (p->getCurrentNode()->getNodeName() == getDestinationNode()->getNodeName()) {
				cout << "winner!" << endl;
				atDestination = true;
				setWinner(p);
				break;
			}
		   }
	 //  }
		   return atDestination;
		}

/*
 * Function:    	quit()     
 * Inputs:			Player
 * Outputs:			none
 * Description:		Allows the player to quit and displays their stats.
 * */
		void quit(Player* p) {
			string visited = "";
			cout << "\n" << p->getName() << " took " << p->steps << " steps." << endl;
			vector<string> v = p->getNodesVisited();
			for (unsigned i = 0; i < v.size(); i++) {
			visited += v[i] + " ";
			}
			cout << "The nodes you visited are " << visited << endl;
			cout << "Thank you for playing!" << endl;
			exit(0);
			}

/*
 * Function:    	move()     
 * Inputs:			char c and Player
 * Outputs:			Player
 * Description:		Moves the inputted player in the direction of char and returns the player with an updated currentNode.
 * */
		Player* move(char c, Player* p) {
			switch (c) {
				case 'N': 
					p->setCurrentNode(getNode(p->getCurrentNode() -> getAttachedNode(0) -> getNodeName()));
					break;
				case 'E':
					p->setCurrentNode(getNode(p->getCurrentNode() -> getAttachedNode(1) ->getNodeName()));
					break;
				case 'S': 
					p->setCurrentNode(getNode(p->getCurrentNode() -> getAttachedNode(2)-> getNodeName()));
					break;
				case 'W':
					p->setCurrentNode(getNode(p->getCurrentNode() -> getAttachedNode(3)-> getNodeName()));
					break;
				case 'Q':
					quit(p);
				default:
				    break;
			}
			
			return p;
		}
		
/*
 * Function:    	getValidDirections()     
 * Inputs:			Node
 * Outputs:			vector<string>
 * Description:		Returnst the valid directions that a player can move in for a given node.
 * */		
		vector<string> getValidDirections(Node* newNode) {
			vector<string> valid;
			if (newNode -> getAttachedNode(0) -> name != "*") {
				valid.push_back("North");
			}
			if (newNode -> getAttachedNode(1) -> name != "*") {
				valid.push_back("East");
			}
			if (newNode -> getAttachedNode(2) -> name != "*") {
				valid.push_back("South");
			}
			if (newNode -> getAttachedNode(3) -> name != "*") {
				valid.push_back("West");
			}
			return valid;
		}
};


/*
 * Function:    	main()     
 * Inputs:			none
 * Outputs:			none
 * Description:		The main function for the maze game.
 * */
int main() {
	System* sys = new System;
	string num = "";
	int n = 0;
	bool hasWon = false;
	bool quit = false;
	string filename = "";
	cout << "=====================================================" << endl;
	cout << "|   Welcome to the Snakes and Ladders Maze Game     |" << endl;
	cout << "=====================================================" << endl;
	cout << "Enter file name (make sure there are no spaces in the file name): ";
	cin >> filename;
	while (!sys->fileExists(filename)) {
		cout << "That file does not exist. Try again." << endl;
		cout << "\nEnter file name: ";
		cin >> filename;
		if (sys->fileExists(filename)) {
			break;
		}
	}
	sys->generateGraph(filename); 
	cout << "\nEnter the number of players: ";
	cin >> num;
	
	
	stringstream ss(num);
	ss >> n;
	sys->setNumOfPlayers(n);
	
	int i = 0;
	while (i < sys->getNumOfPlayers()) {
		string n = "";
		cout << "\nEnter the name of Player #" << i + 1 << ": ";
		cin >> n;
		Player* newP = new Player(n);
		sys->addPlayer(newP);
		i++;
	}
	
	std::vector<Player*> p = sys->getPlayers();
	for (unsigned i = 0; i < p.size(); i++) {
		p[i]->setCurrentNode(sys->nodes[0]);
	}
	
	while (hasWon == false){
		for (unsigned i = 0; i < p.size(); i++) {
			hasWon = sys->playerTurn(p[i], i);
			if (hasWon == true) {
				break;
			}
		}
	}
	
	if (hasWon == true) {
		string visited = "";
		Player* w = sys->getWinner();
		cout << "\nCongratulations, " << w->getName() << " is the winner! You have reached the destination." << endl;
		cout << "You took " << w->steps << " steps."<< endl;
		vector<string> v = w->getNodesVisited();
		for (unsigned i = 0; i < v.size(); i++) {
			visited += v[i] + " ";
		}
		cout << "The nodes you visited are " << visited << endl;
	}
	
}

