#include "LedControl.h"
#include "Fonts.h"
LedControl lc884=LedControl(0,2,1,4);

unsigned long delayTime=280;

volatile int tc;
volatile int dcf_data;
volatile int sekunde59_data;
unsigned char bit_counter=0;
unsigned char bit_dcf[60]; 
unsigned char sec=0;
unsigned char hour_zehner=0,
              hour=3,
              min_zehner=0,
              minute=0; 

ISR(TIM1_COMPA_vect)
{ 
tc++;


  if (bit_is_set(PINB,1))//dcf_modul_pollin invertiert!!!
      {
      dcf_data++;}
      else if (bit_is_clear(PINB,1))//dcf_modul_pollin invertiert!!!
      {
      sekunde59_data++;}
}

void timer1_init(void)
{
  cli();

  TIMSK |= (1<<OCIE1A);      // Timer/Counter1 Output Compare Interrupt Enable
  TCCR1 = 0; //clear TCCR1-Registers
  TCCR1 |= (1 << CTC1);  //Setze CTC-Mod
  //TCCR1 |= (1<<CS12)|(1<<CS11);   //prescaling with 32 = bei 8Mhz = 250.000
  TCCR1 |= (1<<CS12)|(1<<CS11)|(1<<CS10);   //prescaling with 64 = bei 8Mhz = 125.000
  //OCR1C=249;// compare value / Vergleichswert = (CPU Frequenz[8MHZ] : (Vorteiler [32] x Interruptfrequenz[1000])-1
 OCR1C=124;// compare value / Vergleichswert = (CPU Frequenz[8MHZ] : (Vorteiler [64] x Interruptfrequenz[1000])-1

 /*PLLCSR |= (1<<PLLE); 
 delayMicroseconds(100);  // Eine Verzögerung von 100 Mikrosekunden
 while(!(PLLCSR & (1<<PLOCK)));
  PLLCSR |= (1<<PCKE);*/
  sei();
}


void displayChar(byte *x, int displayNumber){
  lc884.clearDisplay(displayNumber);
  for(int j=0; j<=7;j++){
    lc884.setRow(displayNumber,j,x[j]);
  }
}

void displayCharAndWait(byte* x, byte displayNumber){
  lc884.clearDisplay(displayNumber);
  for(int j=0; j<=40;j++){
    lc884.setRow(displayNumber,j,x[j]);
  }
  delay(delayTime);
  lc884.clearDisplay(displayNumber); 
}

void oneMatrix(){
  displayCharAndWait(H,3);
  displayCharAndWait(a,3);
  displayCharAndWait(l,3);
  displayCharAndWait(l,3);
  displayCharAndWait(o,3);
  displayCharAndWait(smile01,3);
}

void fourMatrices(){
  for(int j=0; j<=40; j++){
    int currentMatrix = -1;
    /*if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(I,currentMatrix+j);
    }*/
     currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(I,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(c,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(h,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(s,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(c,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(h,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(a,currentMatrix+j);
    }
   currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(l,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(t,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(e,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(m,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(i,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(c,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(h,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(a,currentMatrix+j);
    }
       currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(b,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(u,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(n,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(d,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(s,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(u,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(c,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(h,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(e,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(d,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(i,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(e,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(frei,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(Z,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(e,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(i,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(t,currentMatrix+j);
    }
    currentMatrix--;
    if( ((currentMatrix+j)>=0) && ((currentMatrix+j)<4) ){
      displayChar(smile01,currentMatrix+j);
    }
    delay(delayTime);
    for(int i=0; i<=4; i++){
      lc884.clearDisplay(i);
    }
  }  
}



void setup() {
  for(int i=0;i<4;i++){
    lc884.shutdown(i,false);
    lc884.setIntensity(i,1);
    lc884.clearDisplay(i);
  }
}
   
void loop() { 
          timer1_init();
  
          //////////////////
          //internal clock//
          /////////////////

            if (tc>998) {sec++;tc=0;}
            if (sec==60) {sec=0; minute++;}
            if (minute>9) {minute=0; min_zehner++;}
            if (min_zehner>5) {min_zehner=0;hour++;}
            if (hour>9) {hour=0; hour_zehner++;}
            if (hour_zehner>1){if (hour>3){hour_zehner=0;hour=0;} 
          }
        
          
    
        ///////////////////////////////////////////////////////////////
        //Zwei Uhr Nachts: Laufschrift Ankündigung Display abschalten//
        ///////////////////////////////////////////////////////////////

        if (hour_zehner==0 && hour==3 && min_zehner==0 && minute==0){
          //Digit 1 bis 4 Matrix LEDs aus
          for(int x=0;x<8;x++) {
             lc884.setRow (0,0+x,zahl[10] [0+x]); //Digit4 alle LEDs aus
             lc884.setRow (1,0+x,zahl[10] [0+x]);//Digit3 alle LEDs aus
             lc884.setRow (2,0+x,zahl[10] [0+x]);//Digit2 alle LEDs aus
             lc884.setRow (3,0+x,zahl[10] [0+x]);//Digit1 alle LEDs aus
              }
        
            oneMatrix();
            fourMatrices();
            delay(1000);
             
        }
        
        ///////////////////////////////////////////////////////////
        //Schleife bis DCF Signal mit Prüfbits komplett empfangen//
        ///////////////////////////////////////////////////////////
        
      if (hour_zehner==0 && hour==3 && min_zehner==0 && minute==0){  
          while (1){
          unsigned char pruefbit_1;// minuten 21-27+ Prüfbit 28
          unsigned char pruefbit_2;// Stunden 29-34 + Prüfbit 35
          unsigned char pruefbit_3;// Jahr    36-57 + Prüfbit 58
          pinMode(1, INPUT);
          tc=0;//!!!!!!!!- sonst hängt eventuell die Zeit für 20 bis 30 Sekunden nach verlassen der Schleife!!!! 
  
      /////////////////////
      //Prüfbit_1 Minuten//
      /////////////////////
      
      if ((bit_dcf[21]+bit_dcf[22]+bit_dcf[23]+bit_dcf[24]+bit_dcf[25]+bit_dcf[26]+bit_dcf[27]+bit_dcf[28])%2 == 0){
      pruefbit_1=1;}else{
      pruefbit_1=0;}
      
      /////////////////////
      //Prüfbit_2 Stunden//
      /////////////////////
      
      if ((bit_dcf[29]+bit_dcf[30]+bit_dcf[31]+bit_dcf[32]+bit_dcf[33]+bit_dcf[34]+bit_dcf[35])%2 == 0){
      pruefbit_2=1;}else{
      pruefbit_2=0;}
      
      //////////////////
      //Prüfbit_3 Jahr//
      //////////////////
      
      if ((bit_dcf[36]+bit_dcf[37]+bit_dcf[38]+bit_dcf[39]+bit_dcf[40]+bit_dcf[41]+bit_dcf[42]+bit_dcf[43]
      +bit_dcf[44]+bit_dcf[45]+bit_dcf[46]+bit_dcf[47]+bit_dcf[48]+bit_dcf[49]+bit_dcf[50]+bit_dcf[51]
      +bit_dcf[52]+bit_dcf[53]+bit_dcf[54]+bit_dcf[55]+bit_dcf[56]+bit_dcf[57]+bit_dcf[58])%2 == 0){
      pruefbit_3=1;}else{
      pruefbit_3=0;}
  
      ///////////////////////
      //DCF-Signal einlesen//
      ///////////////////////  
      
      //59te_Sekunde
      if (bit_is_set(PINB,1))//dcf_modul_pollin invertiert!!!
        {
        if(sekunde59_data>=1760 && dcf_data<=1940 ) // 59 Sekunde; 40ms Abweichung
        {
        
        bit_counter=-1;
        } 
      sekunde59_data=0;
      }

      //0te-59te_Sekunde
      if (bit_is_clear(PINB,1))//dcf_modul_pollin invertiert!!!
        {
        
        if(dcf_data>160 && dcf_data<=240) //bit = 1; 40ms Abweichung
        {
          bit_counter++;
          bit_dcf[bit_counter]=1;
        }
        
        else if(dcf_data>=60 && dcf_data<=140)  //bit = 0; 40ms Abweichung
        {   
            
          bit_counter++;
          bit_dcf[bit_counter]=0;
        }
        
        if(bit_counter>59)  // Absicherung Überzählen 
          {
            bit_counter=0;
            
          }
      dcf_data=0;
      }
      
     /////////////////
     //minutenanfang//
     /////////////////
  
    if((sekunde59_data>=1760 && dcf_data<=1920) && bit_counter==58 && pruefbit_1==1 && pruefbit_2==1 && pruefbit_3==1) {
     pinMode(1, OUTPUT); pruefbit_1=0;pruefbit_2=0; pruefbit_3=0;
     
      
    /////////////////
    //minuten_Einer//
    /////////////////
    
    if    (bit_dcf[21]==0   &&  bit_dcf[22]==0   &&   bit_dcf[23]==0 && bit_dcf[24]==0 )  {minute=0;}
    else if (bit_dcf[23]==1   &&  bit_dcf[22]==1  &&  bit_dcf[21]==1)         {minute=7;}
    else if (bit_dcf[21]==1   &&  bit_dcf[22]==1)                   {minute=3;}
    else if (bit_dcf[23]==1   &&  bit_dcf[21]==1)                   {minute=5;}
    else if (bit_dcf[23]==1   &&  bit_dcf[22]==1)                   {minute=6;}
    else if (bit_dcf[24]==1   &&  bit_dcf[21]==1)                   {minute=9;}
    else if (bit_dcf[21]==1)                            {minute=1;}              
    else if (bit_dcf[22]==1)                            {minute=2;}                      
    else if (bit_dcf[23]==1)                            {minute=4;}                  
    else if (bit_dcf[24]==1)                            {minute=8;}  
  
    //////////////////
    //Minuten_Zehner//
    //////////////////
    
    if    (bit_dcf[25]==0   && bit_dcf[26]==0     && bit_dcf[27]==0)  {min_zehner=0;} 
    else if (bit_dcf[25]==1   && bit_dcf[26]==1)          {min_zehner=3;}
    else if (bit_dcf[27]==1   && bit_dcf[25]==1)            {min_zehner=5;}
    else if (bit_dcf[25]==1)                    {min_zehner=1;}               
    else if (bit_dcf[26]==1)                    {min_zehner=2;}               
    else if (bit_dcf[27]==1)                    {min_zehner=4;}             
    
    /////////////////
    //Stunde_Zehner//
    /////////////////
    
    if    (bit_dcf[33]==0   && bit_dcf[34]==0 )   {hour_zehner=0;} 
    else if (bit_dcf[33]==1)          {hour_zehner=1;} 
    else if (bit_dcf[34]==1)            {hour_zehner=2;} 
    
    ////////////////
    //Stunde_Einer//
    ////////////////
    
    if    (bit_dcf[29]==0  &&   bit_dcf[30]==0   &&   bit_dcf[31]==0  && bit_dcf[32]==0)        {hour=0;} 
    else if (bit_dcf[31]==1  &&   bit_dcf[30]==1  &&  bit_dcf[29]==1)             {hour=7;} 
    else if (bit_dcf[29]==1  &&   bit_dcf[30]==1)                       {hour=3;}  
    else if (bit_dcf[31]==1  &&   bit_dcf[29]==1)                       {hour=5;}  
    else if (bit_dcf[31]==1  &&   bit_dcf[30]==1)                       {hour=6;}
    else if (bit_dcf[32]==1  &&   bit_dcf[29]==1)                       {hour=9;} 
    else if (bit_dcf[29]==1)                                  {hour=1;}                            
    else if (bit_dcf[30]==1)                                {hour=2;}                                         
    else if (bit_dcf[31]==1)                                  {hour=4;}                    
    else if (bit_dcf[32]==1)                                  {hour=8;}                         

    
    break;
    }
    } 
    
  }     
        ///////////////////////////////////
        //Digit 1,2,3 und 4 Zeit ausgeben//
        ///////////////////////////////////

          if (sec==0) { 
                  for(int x=0;x<8;x++) {

                  lc884.setColumn (0,1+x,zahl[0+minute] [0+x]);//Digit4
                  lc884.setColumn (1,1+x, zahl[0+min_zehner] [0+x]); // Digit3
                  lc884.setColumn (2,0+x, zahl[0+hour] [0+x]);//Digit2
                  if (hour_zehner==0){
                        lc884.setColumn (3,0+x,zahl[10] [0+x]);//Digit1 alle LEDs aus
                        }else{lc884.setColumn (3,0+x,zahl[0+hour_zehner] [0+x]);// Digit1
                      }         
                }
          }
           
           //Colon blink
          if (tc<500){
                  lc884.setLed(2,2,7,true);// colon 1 on
                  lc884.setLed(2,5,7,true);// colon 2 on
          }else{  lc884.setLed(2,2,7,false);// colon 1 off
                  lc884.setLed(2,5,7,false);// colon 2 off
              
          }    
} //Ende Void loop