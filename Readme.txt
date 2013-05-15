// laser barrier pwm
// pwm generation for IR diode to make a IR or laser barrier
// based on msp 430 launchpad for pwm generation and reception for development only, see msp 430 directory
// based on stellaris launchpad for pwm generation, signal reception and CANBUS transmission, see stellarpad directory
/*
- * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
- * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
- * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
- * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
- * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
- * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
- * THE SOFTWARE.

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
MSP 430 launchpad

Set p2_1, P2_2,  as output for PWM
set green and red led as output for debug and alignment
set P1_3, P1_4 as analog input for alignment purpose
set P2,4,P2_5 as digital input (beam 1 and 2)
green led blinks faster based on 1st analog input
red led lights if beam1 input is high

at the moment :
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
