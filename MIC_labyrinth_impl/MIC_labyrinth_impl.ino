const int r4 = 32; // Scheinbare random ansprechen von pins um die LED 8x( Matrix richtig anzuschließen in reihe.
const int r6 = 33; // 
const int c1 = 25; // ...
const int c2 = 26;
const int r7 = 27;
const int c4 = 14;
const int r5 = 12;
const int r2 = 13;
const int c7 = 23; 
const int c6 = 22; 
const int r1 = 1; // 
const int c0 = 3;
const int r3 = 21;
const int c5 = 19;
const int c3 = 18;
const int r0 = 5; //neu 23 alt 5 

const int x_con = 34;
const int y_con = 35;

int row[] = {r0, r1, r2, r3, r4, r5, r6, r7};
int column[] = {c0, c1, c2, c3, c4, c5, c6, c7};
int screen_coords[] = {4, 4}; //an dieser variable wird der screen aktualisiert. Es ist der linke obere Pixxel.
int timer_player = millis();
int time_past = millis();

const int nxn_cords = 17;
int goals[nxn_cords][nxn_cords];
int array2[nxn_cords][nxn_cords];
int blink_delay = 50;
            
int cords_17_289[289] = {
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 1 
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 2
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 3
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 4
0,  0,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 5
0,  0,  0,  0,  1,  0,  0,  0,  1,  1,  1,  1,  1,  0,  0,  0,  0, //changed into 2 dims 6
0,  0,  0,  0,  1,  0,  2,  0,  1,  0,  0,  0,  1,  0,  0,  0,  0, //changed into 2 dims 7
0,  0,  0,  0,  1,  0,  0,  0,  1,  2,  1,  0,  1,  0,  0,  0,  0, //changed into 2 dims 8
0,  0,  0,  0,  1,  1,  1,  2,  0,  0,  0,  0,  1,  0,  0,  0,  0, //changed into 2 dims 9
0,  0,  0,  0,  1,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0, //changed into 2 dims 10
0,  0,  0,  0,  0,  1,  0,  3,  4,  4,  4,  1,  0,  0,  0,  0,  0, //changed into 2 dims 11
0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0, //changed into 2 dims 12
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 13
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 14
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 15
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, //changed into 2 dims 16
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};//changed into 2 dims 17

int labyrinth[289] = {
1,  1,  1,  1,  1,  1,  1,  3,  1,  1,  1,  1,  1,  1,  1,  1,  1,
1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,
1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,
1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,  0,  0,  0,  0,  0,  1,
1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,  1,  1,  0,  1,
1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  1,
1,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,
1,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  1,  0,  0,  0,  1,
1,  0,  1,  1,  1,  0,  1,  0,  1,  0,  1,  0,  1,  1,  1,  1,  1,
1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,  0,  1,  0,  0,  0,  1,
1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,  0,  1,  1,  1,
1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  1,  0,  1,  0,  0,  0,  1,
1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  0,  1,
1,  0,  0,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,
1,  0,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2};

int endfeld[289] = {
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
1,  0,  1,  0,  1,  0,  0,  0,  1,  0,  1,  1,  1,  0,  1,  0,  1,
1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  0,  1,  1,  1,
1,  1,  1,  0,  0,  1,  0,  1,  0,  0,  1,  1,  1,  0,  1,  0,  1,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};


void setup() {
//teststart 
for(int i = 0; i < nxn_cords; i++){ // Get Player Coordinates
  for(int j = 0; j < nxn_cords; j++){
    if(cords_17_289[i+nxn_cords*j]==3){
      screen_coords[0]=i-3;
      screen_coords[1]=j-3;
      //screen_coords[0] = j;
      //screen_coords[1] = i;
    }
  }
}

for(int i = 0; i < nxn_cords; i++){ // Get goal locations
  for(int j = 0; j < nxn_cords; j++){
    if(cords_17_289[i+nxn_cords*j]==4 || cords_17_289[i+nxn_cords*j]==5 || cords_17_289[i+nxn_cords*j]==6){
      array2[i][j]=1;
    }else{
      array2[i][j]=0;
    }
  }
}

for (int i = 0; i < nxn_cords; i++) {  
      for (int j = 0; j < nxn_cords; j++) {

       goals[i][j] = cords_17_289[i+nxn_cords*j];
      }
}

for (int i = 0; i < nxn_cords; i++) { // Get goal locations
      for (int j = 0; j < nxn_cords; j++) {
        if(goals[i][j]==4 || goals[i][j]==5 || goals[i][j]==6) {
          goals[i][j]=1; 
        }else {
          goals[i][j]=0;
        }
      }
    }


  for(int i = 0; i<=7; i++){
    pinMode(row[i], OUTPUT); //Defines Output-Pins
  }
  for(int i = 0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
  clearDisplay();
} //setup end


int blink(int blin, int fak = 2){ // Function to make a specific LED blink with a certain frequency
  if((millis() % blin) <= (blin / fak))
    {
    return 1; 
    }
  return 0;
}


int mapcords( int x, int y){
  int nxn_cords = 17;
  if( x<0 || x>nxn_cords || y<0 || y>nxn_cords){
    return 0;
    //Out of Map
  }
switch( cords_17_289[y * nxn_cords + x] ){
        case 0: //FREE SPACE OUT GAME
          return 0;
          break;
        case 1: //WALL
          return 1;
          break;
        case 2: //CHEST
          return blink( 250);
          break;
        case 3: //PLAYER
          return blink( 125 );
          break;
        case 4: //GOAL
          return blink(1000);
          break;
        case 5: //PLAYER ON GOAL
          return blink(125);
          break;
        case 6: //CHEST ON GOAL
          return blink( 50);
          break;
        case 7:  //FREE SPACE INGAME
          return 0;
          break;
        default:  //ERROR SET FREE SPACE
          return 0;
          break;
        }
} 
 // return cords_17_289[y * max + x];
  //row (x) = 17 long
//}


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




void enjoystick(){ // Reads Joystick input
  if ((analogRead(x_con)>=1000)&&(analogRead(x_con)<=1000)&& (analogRead(y_con)>=1000) && (analogRead(y_con)<=3000)){
    timer_player = 0;
  }
  if( (millis() - timer_player) >= 500){
  if (analogRead(x_con)<1000){
    move(1,0);  } //Oben
  if (analogRead(x_con)>3000){
    move(-1,0);  }  //Unten
  if (analogRead(y_con)<1000){  
    move(0,-1);  }  //Links
  if (analogRead(y_con)>3000){
    move(0,1);  } //Rechts
  timer_player = millis();
}
}

void move(int px, int py){ //Movement Logic
  px = -px;
  int locX = screen_coords[0]+3;
  int locY = screen_coords[1]+3;
  
            if (  (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 1) //You shall not move
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 2 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 1)
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 6 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 1)
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 6 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 6)
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 2 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 2)
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 6 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 2)
          || (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 2 && cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] == 6)) {
        

      } else { //Bitte Moven
        screen_coords[0] +=px; 
        screen_coords[1] +=py;

        if (cords_17_289[locX + px+ nxn_cords *(locY + py)] == 2 || cords_17_289[locX + px+ nxn_cords *(locY + py)] == 6) { //chest move
          cords_17_289[locX + 2*px+ nxn_cords *(locY + 2*py)] = 2;
        }
        cords_17_289[locX + px+ nxn_cords *(locY + py)] = 3; //new player location
        cords_17_289[locX+nxn_cords*locY] = 0; //old player loc is now free
        
            //
        
        if(array2[locX][locY]==1) { //restore goal
        cords_17_289[locX+nxn_cords*locY] = 4;
        }else {
          cords_17_289[locX+ nxn_cords*locY] = 0;
        }

        //create chest on goal
        if((cords_17_289[locX + 2*px+(locY + 2*py)*nxn_cords] == 2) && array2[locX + 2*px][locY + 2*py] == 1) {
          cords_17_289[locX + 2*px+17*(locY + 2*py)] = 6;
        }
        }
}

int won(){
  if(cords_17_289[0 + 15*nxn_cords] == 3){
    endscreen();
  }
  for (int i = 0; i < nxn_cords; i++) { // Get goal locations
      for (int j = 0; j < nxn_cords; j++) {
        if(cords_17_289[j + i*nxn_cords] == 2) {
          return 0;
      }
   }
}
if(blink_delay > 50){
  if(blink_delay > 51){  
  return 0;
}
  blink_delay +=1;
  endscreen();
  return 0;
}

for (int i = 0; i < nxn_cords; i++) { // Get goal locations
      for (int j = 0; j < nxn_cords; j++) {
        
          cords_17_289[j + i*nxn_cords]= labyrinth[j + i*nxn_cords];
   }
}
screen_coords[0] = 4;
screen_coords[1] = -3;
blink_delay = 51;
return 0;
}

void endscreen(){
  for (int i = 0; i < nxn_cords; i++) { // Get goal locations
      for (int j = 0; j < nxn_cords; j++) {
        
          cords_17_289[j + i*nxn_cords]= endfeld[j + i*nxn_cords];
   }
}
int endscore = millis();
for (int i = 0; i < nxn_cords; i++){
if(endscore % 2 ==1){
   cords_17_289[17-i]= 1;
}
endscore = endscore /2;
 }
 screen_coords[0] = 0;
screen_coords[1] = 0;
}

void loop() {
  enjoystick();
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){
      if(i == 3 && j == 3){ //Blinkfunktion für den dot in der mitte. bei [3|3]
        switchLED(row[i],column[j], blink(125));
      }
      else{ //Else means, wenn es um alles nur nicht um den Dot in der Mitte geht. 
        switchLED(row[i],column[j],mapcords(j+screen_coords[0], i+screen_coords[1]));
      }
      
      delayMicroseconds(blink_delay);   //Die LEDs brauchen den Delay um nicht zu dimm zu wirken. 
      
      switchLED(row[i],column[j],0); //Die LEDs werden bei jedem programmzyklus kurz ein und aus geschalten um die wiedergabe zu ermöglichen. 
    }
  }
  won();
}
