
#define r0 2 // pin for row 0
#define r1 3 // pin for row 1
#define r2 4 // ...
#define r3 5
#define r4 6
#define r5 7
#define r6 8
#define r7 9
#define c0 A0 // pin for column 0
#define c1 A1 // pin for column 1
#define c2 A2 // ...
#define c3 A3
#define c4 A4
#define c5 A5
#define c6 A6
#define c7 A7

#define x_con 10
#define y_con 11

int column[] = {r0, r1, r2, r3, r4, r5, r6, r7};
int row[] = {c0, c1, c2, c3, c4, c5, c6, c7};

int cords_17_289[17][17] = {
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
{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}}; //changed into 2 dims 


int player_coords[2];
int timer_player = millis();
int time_past = millis();
int goals[17][17];
int array2[17][17];
            
void setup() {
//teststart
for(int i = 0; i < 17; i++){
  for(int j = 0; j < 17; j++){
    if(cords_17_289[i][j]==3){
      player_coords[0]=i;
      player_coords[1]=j;
    }
  }
}

for(int i = 0; i < 17; i++){
  for(int j = 0; j < 17; j++){
    if(cords_17_289[i][j]==4 || cords_17_289[i][j]==5 || cords_17_289[i][j]==6){
      array2[i][j]=1;
    }else{
      array2[i][j]=0;
    }
  }
}



for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 17; j++) {

       goals[i][j] = cords_17_289[i][j];
      }
}

for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        if(goals[i][j]==4 || goals[i][j]==5 || goals[i][j]==6) {
          goals[i][j]=1; //speichert goals
        }else {
          goals[i][j]=0;
        }
      }
    }


  //Testend
  for(int i = 0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i = 0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
  clearDisplay();
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


int blink(int x, int y, int j, int i, int blin){
  if ( x==j && y==i){

    if((millis() % blin) < (blin / 2)){
      switchLED(row[i],column[j],1);
      return 1; 
    }
    }
  switchLED(row[i],column[j],0);
  return 0;
}

void refresh(){

  clearDisplay();

  for(int i = 0; i < 8; i++){
  for(int j = 0; j < 8; j++){
    switch( cords_17_289[i+player_coords[0]][j+player_coords[1]] ){

        case 1: //WALL
          switchLED(row[i],column[j],1);
          break;
        case 2: //CHEST
          blink(i,j,i,j, 250);
          break;
        case 3: //PLAYER
          blink(i,j,i,j, 125 );
          break;
        case 4: //GOAL
          blink(i,j,i,j, 1000);
          break;
        case 5: //PLAYER ON GOAL
          blink(i,j,i,j,125);
          break;
        case 6: //CHEST ON GOAL
          blink(i,j,i,j, 50);
          break;
        case 7:  //Free Space
          //labelArray[j][i].setIcon(null);
          //labelArray[j][i].setForeground(Color.darkGray);
          switchLED(row[i],column[j],0);
          break;

        }
  }
  }
}

void enjoystick(){
  if( (millis() - timer_player) >= 1000){
  if (analogRead(x_con)<1000){
    move(-1,0);  }
  if (analogRead(x_con)>3000){
    move(1,0);  }
  if (analogRead(y_con)<1000){  
    move(0,1);  }
  if (analogRead(y_con)>3000){
    move(0,-1);  }
  timer_player = millis();
}
}

void move(int px, int py){
  int locX = player_coords[0];
  int locY = player_coords[1];
  
            if (  (cords_17_289[locX + px][locY + py] == 1) //You shall not move
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
        if( blink(i,j,i,j,1000) == 1){
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
