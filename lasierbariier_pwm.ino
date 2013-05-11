
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
+ * http://www.lauridmeyer.com
  * 
- * 
- *             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
-
- Copyright (C) 2013 Mael REYMOND <maeldiy@gmail.com>
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
int beam1 = 0;  // beam 1 state
int beam2  = 0;  // beam 2 state
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds), the value will move with the power on readind
unsigned long currentMillis;

void setup() {
  // 2 PWM output channels
 pinMode(P2_1, OUTPUT);    
 pinMode(P2_2, OUTPUT); 
 // 2 input channels for beam reading
 pinMode(P2_4, INPUT); 
 pinMode(P2_5, INPUT);   
//  CCTL1 = OUTMOD_7; to be removed or not ?
 /* Port 1 Resistor Enable Register */
 //green and red led used for alignment
 pinMode(GREEN_LED, OUTPUT);  
 pinMode(RED_LED, OUTPUT);  
// 2 analog input for beam alignment
 pinMode(P1_3, INPUT);    
 pinMode(P1_4, INPUT); 
 
 digitalWrite(GREEN_LED, led_state); // let light the green led 
 
 }

// initialisation des variables a faire ; code du type noteaps++ a  rajouter
void loop() {
   
   analogFrequency(38000);   //set frequence, 38 khz in case of use of TSOP
   analogWrite(P2_1,128);   // 128 for 50% duty cycle
   analogWrite(P2_2,128); 
   // alignmnent : the aim of this piece of code is to provide alignment information, 
   // the more aligned are the photodiode and the Ir diode, the more blinky will be green diode
   
   val_alignment = analogRead(P1_3);    // read the value from the sensor
   
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
    beam1 = digitalRead(P2_4);    
    digitalWrite(RED_LED, beam1);
  }
}
   
   
   
   
   
   
