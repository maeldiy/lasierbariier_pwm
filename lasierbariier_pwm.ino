
// laser barrier pwm
// pwm generation for IR diode to make a laser barrier
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



int debug = 1;  // 1 if debug enable
int time_delay = 32000; // 32 sec between each freq, in fact this is half a delay as 1 min was the object
void setup() {
 pinMode(P2_1, OUTPUT);    
 pinMode(P1_2, OUTPUT); 
 CCTL1 = OUTMOD_7;
 /* Port 1 Resistor Enable Register */
 //    P1REN = BIT2;  to be tested ??? 213/11/2012
 if (debug ==1) pinMode(GREEN_LED, OUTPUT);  
 
 }


void loop() {
   if (debug ==1) {
     digitalWrite(GREEN_LED, HIGH);  // debug purpose
     delay(200);
     digitalWrite(GREEN_LED, LOW);  // debug purpose
   }
   analogFrequency(38000);   //set frequence, 38 khz in case of use of TSOP
   analogWrite(P1_2,128);   // 128 for 50% duty cycle
   analogWrite(P2_1,128); 
   if (debug ==1) {
     digitalWrite(GREEN_LED, HIGH);  // debug purpose
     delay(200);
     digitalWrite(GREEN_LED, LOW);  // debug purpose
   }
  

 
}
