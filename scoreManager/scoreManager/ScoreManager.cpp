#include "ScoreManager.h"


bool wayToSort(int i, int j) { return i > j; }
ScoreManager::ScoreManager(){
	_scoreList = new vector<int>();
	_highScore = 0;
	_tempScore = 0;
}
void ScoreManager::addScore(int score) {
	_tempScore += score;
}

void ScoreManager::remScore(int score) {
	_tempScore -= score;
}

void ScoreManager::setScore(int score) {
	_tempScore = score;
}

void ScoreManager::resetScore() {
	setScore(0);
}

void ScoreManager::finishScore() {
	_scoreList->push_back(_tempScore);
	resetScore();
	updateHighScore();
}

void ScoreManager::updateHighScore(){
	for (int i = 0; i < _scoreList->size(); i++){
		if (_highScore < _scoreList->at(i)) {
			_highScore = _scoreList->at(i);
		}
	}
	sort(_scoreList->begin(), _scoreList->end(), wayToSort);
}

int ScoreManager::getScore(int posScore) {
	if(_scoreList->size() > posScore)
	return _scoreList->at(posScore);
	else return NULL;
}

int ScoreManager::getHighScore() {
	return _highScore;
}

void ScoreManager::getAll() {
	for (int i = 0; i < _scoreList->size(); i++) {
		cout << _scoreList->at(i);
	}
}
ScoreManager::~ScoreManager(){
	delete _scoreList;
}
