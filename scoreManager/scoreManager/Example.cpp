#include <iostream>
#include "ScoreManager.h"
using namespace std;
void main() {
	ScoreManager* sm = new ScoreManager();
	sm->addScore(10);
	sm->finishScore();
	sm->addScore(20);
	sm->finishScore();
	sm->getAll();
	cin.get();

}