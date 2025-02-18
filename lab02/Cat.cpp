#include <iostream>
using namespace std

class Cat{
    private:
    int lives;

    public:
    Cat(int numLives){
        lives = numLives;
    }

    void ReportLives(){
        cout << "The cat has " << lives << " lives." << endl;
    }

    void loseLife() {
        if (lives > 0) {
            lives--;
            cout << "The cat lost a life! " << lives << " lives remaining." << endl;
        } else {
            cout << "The cat has no lives left." << endl;
        }
    }    
};

int main(){
    Cat myCat(9);
    myCat.ReportLives();
    myCat.loseLife();
    myCat.loseLife();
    myCat.ReportLives();

}