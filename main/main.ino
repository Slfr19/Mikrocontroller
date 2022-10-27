
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

int n1 = millis();
int n2 = millis();
int n3 = millis();
int n4 = millis();

int lastmillis_1[] = {n1, n2, n3, n4};

bool cords_17_289[] = {1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,
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
1,  0,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  0,  0,  1,  0,  1,
1,  0,  1,  0,  1,  1,  1,  0,  1,  1,  1,  1,  1,  0,  1,  0,  1,
1,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,
1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  1,  1,  1,  1,  1,  1,  1};

int player_coords[] = {4, -5};
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

void enjoystick(){
  if( (millis() - timer_player) >= 500){
  if(analogRead(x_con)<1000){
    if( mapcords(2+player_coords[0], 3+player_coords[1])==0){
      player_coords[0] -=1;
    }
  }
  if (analogRead(x_con)>3000){
    if( mapcords(4+player_coords[0], 3+player_coords[1])==0){
      player_coords[0] +=1;
    }
  }
  if (analogRead(y_con)<1000){
    if( mapcords(3+player_coords[0], 2+player_coords[1])==0){
      player_coords[1] -=1;
    }
  }
  if (analogRead(y_con)>3000){
    if( mapcords(3+player_coords[0], 4+player_coords[1])==0){
      player_coords[1] +=1;
    } 
  }
  timer_player = millis();
}
}

int mapcords( int x, int y){
  int max = 17;
  if( x<0 || x>max || y<0 || y>max){
    return 0;
    //Out of Map
  }
  return cords_17_289[y * max + x];
  //row (x) = 17 long
}

void loop() {
 
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){

      enjoystick();
      
      if(i == 3 && j == 3){
        if((millis() % 500) > 250){
          continue;
        }
        switchLED(row[i],column[j],1);
      }
      else{
        switchLED(row[i],column[j],mapcords(j+player_coords[0], i+player_coords[1]));
      }
      
      delayMicroseconds(50);   
      switchLED(row[i],column[j],0);
    }
  }
}
