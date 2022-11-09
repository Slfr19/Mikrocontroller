/*
  Blink without Delay
  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.
  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products
  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi
  This example code is in the public domain.
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

const int r0 = 32; // pin for row 0
const int r1 = 33; // pin for row 1
const int r2 = 25; // ...
const int r3 = 26;
const int r4 = 27;
const int r5 = 14;
const int r6 = 12;
const int r7 = 13;
const int c0 = 23; // pin for column 0
const int c1 = 22; // pin for column 1
const int c2 = 1; // ...
const int c3 = 3;
const int c4 = 21;
const int c5 = 19;
const int c6 = 18;
const int c7 = 5;

const int x_con = 34;
const int y_con = 35;

int row[] = {r0, r1, r2, r3, r4, r5, r6, r7};
int column[] = {c0, c1, c2, c3, c4, c5, c6, c7};

int n1 = millis();
int n2 = millis();
int n3 = millis();
int n4 = millis();

int lastmillis_1[] = {n1, n2, n3, n4};

int cords_17_289[][] = 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  7,  7,  7,  1,  1,  1,  1,  1,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  7,  2,  7,  1,  7,  7,  7,  1,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  7,  7,  7,  1,  2,  1,  7,  1,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  1,  1,  2,  7,  7,  7,  7,  1,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  1,  7,  7,  7,  1,  1,  1,  1,  1,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  1,  7,  3,  4,  4,  4,  1,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}, //changed into 2 dims 
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}; //changed into 2 dims 


int player_coords[2];
for(int i = 0, i < 17, i++){
  for(int j = 0, j < 17, j++){
    if(cords_17_289[i][j]==3){
      player_coords[0]=i;
      player_coords[1]=j;
    }
  }
}

int goals[17][17];
goals = cords_17_289;

for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if(goals[i][j]==4 || goals[i][j]==5 || goals[i][j]==6) {
					goals[i][j]=1; //speichert goals
				}else {
					goals[i][j]=0;
				}
			}
		}

int timer_player = millis();
int time_past = millis();
            
void setup() {
  for(int i = 0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i = 0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
  clearDisplay();
}


int my_timer(int timer, int numb, int reset){
  time_past = millis() - lastmillis_1[numb];
  if(time_past > timer && reset == 1){
      lastmillis_1[numb] = int(millis()); 
    }
  return time_past;
}


int blink(int x, int y, int j, int i, int blin, int numb){
  if ( x==j && y==i){

    if((millis() % blin) < (blin / 2)){
      switchLED(row[i],column[j],1);
      return 1; 
    }
    
    }
  }
  switchLED(row[i],column[j],0);
  return 0;
}

void refresh(){

  clearDisplay();

  for(int i = 0, i < 8, i++){
  for(int j = 0, j < 8, j++){
    switch(cords_17_289[i+playercoords[0]][j+playercoords[1]]){

        case 1: //WALL
					blink(i,j,i,j,)
					break;
				case 2: //CHEST
					blink(i,j,i,j,)
					break;
				case 3: //PLAYER
					blink(i,j,i,j,)
					break;
				case 4: //GOAL
					blink(i,j,i,j,)
					break;
				case 5: //PLAYER ON GOAL
					blink(i,j,i,j,)
					break;
				case 6: //CHEST ON GOAL
					blink(i,j,i,j,)
					break;
				case 7: 
					labelArray[j][i].setIcon(null);
					labelArray[j][i].setForeground(Color.darkGray);
					break;

				}
  }
  }
}

void enjoystick(){
  if( (millis() - timer_player) >= 1000){
  if (analogRead(x_con)<1000){
    move(-1,0)  }
  if (analogRead(x_con)>3000){
    move(1,0)  }
  if (analogRead(y_con)<1000){  
    move(0,1)  }
  if (analogRead(y_con)>3000){
    move(0,-1)  }
  timer_player = millis();
}
}

void move(int px, int py){
  int locX = playerCoords[0];
  int locY = playerCoords[1];
  
						if (	(cords_17_289[locX + px][locY + py] == 1) //You shall not move
					|| (cords_17_289[locX + px][locY + py] == 2 && cords_17_289[locX + 2 * px][locY + 2 * py] == 1)
					|| (cords_17_289[locX + px][locY + py] == 6 && cords_17_289[locX + 2 * px][locY + 2 * py] == 1)
					|| (cords_17_289[locX + px][locY + py] == 6 && cords_17_289[locX + 2 * px][locY + 2 * py] == 6)
					|| (cords_17_289[locX + px][locY + py] == 2 && cords_17_289[locX + 2 * px][locY + 2 * py] == 2)
					|| (cords_17_289[locX + px][locY + py] == 6 && cords_17_289[locX + 2 * px][locY + 2 * py] == 2)
					|| (cords_17_289[locX + px][locY + py] == 2 && cords_17_289[locX + 2 * px][locY + 2 * py] == 6)) {
				

			} else {

				if (cords_17_289[locX + px][locY + py] == 2 || cords_17_289[locX + px][locY + py] == 6) { //chest move
					cords_17_289[locX + 2 * px][locY + 2 * py] = 2;
				}
				
				cords_17_289[locX + px][locY + py] 
						= 3; //new player location
				
				if(array2[locX][locY]==1) { //restore goal
				cords_17_289[locX][locY] = 4;
				}else {
					cords_17_289[locX][locY] = 0;
				}

				//create chest on goal
				if((cords_17_289[locX + 2*px][locY + 2*py] == 2) && array2[locX + 2*px][locY + 2*py] == 1) {
					cords_17_289[locX + 2*px][locY + 2*py] = 6;
				}
				
			}

  refresh();
      
}

int mapcords( int x, int y){
  int max = 17;
  if( x<0 || x>max || y<0 || y>max){
    return 0;
  }
  return cords_17_289[y][x];
  //row (x) = 17 long
}


int map(int x, int y, int j, int i){
  
  mapcords(x, y);
}


void loop() {
 
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){

      enjoystick();
      
      if(i == 3 && j == 3){ //const player coordinates 
        if( blink(i,j,i,j,1000 , 1) == 1){
          continue;
        }
        switchLED(row[i],column[j],1);
      }
      else{
        switchLED(row[i],column[j],mapcords(j+player_coords[0], i+player_coords[1]));
      }
      
      //switchLED(row[i],column[j],1;);   
      //delay(1); 
      delayMicroseconds(50);   
      switchLED(row[i],column[j],0);
    }
  }
}


void clearDisplay(){
   for(int i = 0; i<=7; i++){
      digitalWrite(row[i],LOW); 
  }
  for(int i = 0; i<=7; i++){
    digitalWrite(column[i], HIGH);
  } 
}
void switchLED(int r, int c, bool ON){
  if(ON){
    digitalWrite(r, HIGH);
    digitalWrite(c, LOW);
  }
  else{
    digitalWrite(r, LOW);
    digitalWrite(c, HIGH);
  }
}