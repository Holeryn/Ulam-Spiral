#include "primes.h"
#include "include/gfx.h"

#define SIZE 500
#define PADDING 150

// quadratic polynomials that descrives the Diagonals
// taked counter clocwirse order
#define FIRSTD(n) (4*n*n - 2*n + 1)
#define SECONDD(n)(4*n*n + 1)
#define THIRDD(n) (4*n*n + 2*n + 1)
#define QUADD(n) (4*n*n - 4*n + 1)

enum DIRECTIONS{LEFT,DOWN,RIGHT,UP};

void spiral(void);

// maybe not a good practise...
static int primes[LENGTH];

int main(void){
  // collect the prime
  Gprimes(primes);

  // open the Xorg window and set the color
  gfx_open(SIZE, SIZE, "Ulam Spiral");
  gfx_color(255,255,255);

  // create the spiral
  puts("Creating the spiral...");
  spiral();

  // flush the points
  puts("Drawing the spiral...");
  gfx_flush();

  while(1);

  return 0;
}

void spiral(void){
  int Pcounter = 1;
  int X = 0, Y = 0;
  int state = 0;
  int times = 0;
  int row = 1;
  // a exist because we start in UP
  int a = 1;
  gfx_point(SIZE / 2 + 1 + PADDING, SIZE / 4);

  for(int i = 3; i <= 100000; i++){
    if(times == 4 - a){
      a = 0;
      times = 0;
      row++;
    }

    if(i == FIRSTD(row)){
      state = LEFT;
      times++;
    }else if(i == SECONDD(row)){
      state = DOWN;
      times++;
    }else if(i == THIRDD(row)){
      state = RIGHT;
      times++;
    }else if(i == QUADD(row)){
      state = UP;
      times++;
    }

    switch(state){
    	case LEFT: 	X--; 	break;
    	case RIGHT: X++; 	break;
    	case DOWN:	Y--;	break;
    	case UP:	Y++;	break;
    }

    if(i == primes[Pcounter]){
      gfx_point(SIZE / 2 + X + PADDING, SIZE / 4 + Y);
      Pcounter++;
    }
  }
}
