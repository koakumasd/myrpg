using namespace std;

const int globalMapX=200;
const int globalMapY=200;
const int countMob=1000;
typedef unsigned short int suint;
const int maximalItems=10;
enum whatIsIt {HERO=1, MOB=2};

// enum INP {UP=72, DOWN=80, LEFT=75, RIGHT=77, ESC=27, ONE=49, TWO=50, THREE=51};
enum INPUT {UP=119, DOWN=115, LEFT=97, RIGHT=100, ESC=27, ONE=49, TWO=50, THREE=51,FOUR=52};

enum Stepcheck {DONTWALK, WALK, FIGHT};