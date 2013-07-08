
// laser barrier pwm
// pwm generation for IR diode to make a IR or laser barrier
/*
- * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
- * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
- * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
- * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
- * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
- * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
- * THE SOFTWARE.
- *             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
- <maeldiy@gmail.com>
-
- Everyone is permitted to copy and distribute verbatim or modified
- copies of this license document, and changing it is allowed as long
- as the name is changed.
-
-            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
-   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
-
-  0. You just DO WHAT THE FUCK YOU WANT TO.
-
  */



int debug = 0;  // 1 if debug enable
int led_state = HIGH;  // the led will be on once at startup
int val_alignment=0;  // the "power meter" input
int beam1_1 = 0;  // beam 1_1 state
int beam1_2  = 0;  // beam 1_2 state
int beam2_1 = 0;  // beam 2_1 state
int beam2_2  = 0;  // beam 2_2 state
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds), the value will move with the power on readind
unsigned long currentMillis;
int val_alignment1_1, val_alignment1_2, val_alignment2_2,val_alignment2_1;

void setup() {
  // 2 PWM output channels
 pinMode(PA_2, OUTPUT);   // PWM output :  pin 1
 pinMode(PA_7, OUTPUT);   // PWM output :  pin 10 

 // 4 input channels for beam reading or crossing detection
 pinMode(PA_3, INPUT);   // beam 1_1 digital input : pin 12 
 pinMode(PA_4, INPUT);   // beam 1_2 digital input : pin 13 
 pinMode(PA_5, INPUT);   // beam 2_1 digital input : pin 8
 pinMode(PA_6, INPUT);   // beam 2_2 digital input : pin 9 
 
 // Reading for push button, for beam alignmenet switching
 pinMode(PF_4, INPUT);   // PUSH1 digital input : pin 31
 pinMode(PF_0, INPUT);   // PUSH2 digital input : pin 17
 
 //green and blue led used for alignment, red for beam crossing
 pinMode(GREEN_LED, OUTPUT);  
 pinMode(BLUE_LED, OUTPUT);  
 pinMode(RED_LED, OUTPUT);  
// 4 analog input for beam alignment
 pinMode(PE_2, INPUT);   // Beam 1_2 analog input :  pin 28
 pinMode(PE_1, INPUT);   // Beam 1_2 analog input :  pin 27
 pinMode(PD_3, INPUT);   // Beam 2_1 analog input :  pin 26
 pinMode(PD_2, INPUT);   // Beam 2_2 analog input :  pin 25
 
// CANBUS init missing
 
 }

// initialisation des variables a faire ; code du type noteaps++ a  rajouter
void loop() {
  // analogFrequency(20000);
   analogFrequency(38000);   //set frequence, 38 khz in case of use of TSOP !! !!not working on stellarpad ???!!
   analogWrite(PA_2,128);   // 128 for 50% duty cycle
   analogWrite(PA_7,128); 
   // alignmnent : the aim of this piece of code is to provide alignment information, 
   // the more aligned are the photodiode and the Ir diode, the more blinky will be green diode
   
   val_alignment1_1 = analogRead(PA_3);    // read the value from the sensor on beam 1_1
   val_alignment1_2 = analogRead(PA_4);    // read the value from the sensor on beam 1_2
   val_alignment2_1 = analogRead(PA_5);    // read the value from the sensor on beam 2_1
   val_alignment2_2 = analogRead(PA_6);    // read the value from the sensor on beam 2_2
   
  // check to see if it's time to blink the LED; that is, if the 
  // difference between the current time and last time you blinked 
  // the LED is bigger than the interval at which you want to 
  // blink the LED.
   currentMillis = millis();
 
  if(currentMillis - previousMillis > val_alignment) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (led_state == LOW)
       led_state = HIGH;
       
    else
       led_state = LOW;
       
      
    // set the LED with the ledState of the variable:
         digitalWrite(GREEN_LED, led_state); 
        
    // beam info    
    beam2_1 = digitalRead(PA_3);    
    beam1_2 = digitalRead(PA_4);    
    beam2_1 = digitalRead(PA_5);
    beam2_2 = digitalRead(PA_6);    
  }
}
   
   
   
   
   
   

