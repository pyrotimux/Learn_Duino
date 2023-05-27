#define RED 3


typedef enum {
  ONE_BLINK,
  TWO_BLINKS,
  THREE_BLINKS,
  FOUR_BLINKS  
} State_t;


typedef struct {
  State_t State;
  void (*Proc_Func)(void);  
} State_Func_Map_t;


void one_blink(void);
void two_blinks(void);
void three_blinks(void);
void four_blinks(void);


static State_Func_Map_t const State_Func_Map[] = {
  {ONE_BLINK, one_blink},
  {TWO_BLINKS, two_blinks},
  {THREE_BLINKS, three_blinks},
  {FOUR_BLINKS, four_blinks}
};


static State_t Cur_State = ONE_BLINK; 


void blinky_helper(unsigned int num_of_blinks, 
                   unsigned int delay_between_blinks_ms){
  for (int i = 0; i < num_of_blinks; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(RED, HIGH);  
    delay(delay_between_blinks_ms);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(RED, LOW);
    delay(1000);  
  }
}


void one_blink(void){
  blinky_helper(1, 5000);
  Cur_State = TWO_BLINKS;
}


void two_blinks(void){
  blinky_helper(2, 2500);
  Cur_State = THREE_BLINKS;
}


void three_blinks(void){
  blinky_helper(3, 1000);
  Cur_State = FOUR_BLINKS;
}


void four_blinks(void){
  blinky_helper(4, 500);
  Cur_State = ONE_BLINK;
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED, OUTPUT);
}


// the loop function runs over and over again forever
void loop() {
  (*State_Func_Map[Cur_State].Proc_Func)();
}
