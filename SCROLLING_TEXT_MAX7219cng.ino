


byte charToPrint[95][5]
{
  {0, 0, 0, 0, 0}, //SPACE
  {95, 0, 0, 0, 0}, //!
  {7, 7, 0, 0, 0}, //"
  {20, 62, 20, 62, 20}, //#
  {36, 42, 107, 42, 18}, //$
  {76, 44, 16, 104, 100}, //%
  {52, 74, 84, 32, 80}, //&
  {7, 0, 0, 0, 0}, //'
  {62, 65, 0, 0, 0}, //(
  {65, 62, 0, 0, 0}, //)
  {21, 14, 14, 21, 0}, //*
  {8, 8, 62, 8, 8}, //+
  {128, 96, 0, 0, 0}, //,
  {8, 8, 8, 8, 8}, //-
  {64, 0, 0, 0, 0}, //.
  {32, 16, 8, 4, 2}, ///
  {62, 81, 73, 69, 62}, //0
  {68, 66, 127, 64, 64}, //1
  {66, 97, 81, 73, 70}, //2
  {65, 73, 73, 73, 54}, //3
  {8, 12, 10, 127, 8}, //4
  {71, 69, 69, 69, 57}, //5
  {62, 73, 73, 73, 48}, //6
  {97, 17, 9, 5, 3}, //7
  {54, 73, 73, 73, 54}, //8
  {6, 73, 73, 73, 62}, //9
  {34, 0, 0, 0, 0}, //:
  {64, 34, 0, 0, 0}, //;
  {8, 20, 34, 0, 0}, //<
  {20, 20, 20, 20, 20}, //=
  {34, 20, 8, 0, 0}, //>
  {2, 1, 81, 9, 6}, //?
  {62, 73, 85, 93, 94}, //@
  {126, 9, 9, 9, 126}, //A
  {127, 73, 73, 73, 54}, //B
  {62, 65, 65, 65, 34}, //C
  {127, 65, 65, 65, 62}, //D
  {127, 73, 73, 73, 73}, //E
  {127, 9, 9, 9, 9}, //F
  {62, 65, 65, 81, 50}, //G
  {127, 8, 8, 8, 127}, //H
  {65, 65, 127, 65, 65}, //I
  {33, 65, 65, 63, 1}, //J
  {127, 8, 20, 34, 65}, //K
  {127, 64, 64, 64, 64}, //L
  {127, 2, 4, 2, 127}, //M
  {127, 2, 4, 8, 127}, //N
  {62, 65, 65, 65, 62}, //O
  {127, 9, 9, 9, 6}, //P
  {62, 65, 81, 62, 64}, //Q
  {127, 9, 9, 25, 102}, //R
  {38, 73, 73, 73, 50}, //S
  {1, 1, 127, 1, 1}, //T
  {63, 64, 64, 64, 63}, //U
  {31, 32, 64, 32, 31}, //V
  {127, 32, 16, 32, 127}, //W
  {99, 20, 8, 20, 99}, //X
  {3, 4, 120, 4, 3}, //Y
  {97, 81, 73, 69, 67}, //Z
  {127, 65, 0, 0, 0}, //[
  {2, 4, 8, 16, 32}, //\
  {65, 127, 0, 0, 0}, //]
  {4, 2, 1, 2, 4}, //^
  {64, 64, 64, 64, 64}, //_
  {1, 2, 0, 0, 0}, //`
  {32, 84, 84, 84, 120}, //a
  {127, 72, 72, 72, 48}, //b
  {56, 68, 68, 68, 68}, //c
  {48, 72, 72, 72, 127}, //d
  {56, 84, 84, 84, 24}, //e
  {68, 126, 69, 1, 2}, //f
  {24, 164, 164, 164, 124}, //g
  {127, 8, 8, 8, 112}, //h
  {64, 68, 125, 64, 64}, //i
  {64, 128, 132, 125, 4}, //j
  {127, 8, 20, 34, 64}, //k
  {64, 65, 127, 64, 64}, //l
  {120, 8, 48, 8, 112}, //m
  {120, 8, 8, 8, 112}, //n
  {56, 68, 68, 68, 56}, //o
  {252, 20, 20, 20, 8}, //p
  {8, 20, 20, 20, 252}, //q
  {120, 8, 8, 8, 16}, //r
  {72, 84, 84, 84, 36}, //s
  {8, 8, 126, 72, 8}, //t
  {56, 64, 64, 64, 56}, //u
  {24, 32, 64, 32, 24}, //v
  {56, 64, 32, 64, 56}, //w
  {68, 40, 16, 40, 68}, //x
  {156, 160, 64, 32, 28}, //y
  {68, 100, 84, 76, 68}, //z
  {8, 54, 65, 0, 0}, //{
  {127, 0, 0, 0, 0}, //|
  {65, 54, 8, 0, 0}, //}
  {8, 8, 16, 16, 0} //~
};

# define numberOfDisplays  2

byte xShift[numberOfDisplays][8];
byte yShift[8];
const int clockPin = 10;
const int dataPin = 9;
const int latchPin = 8;
byte shutDown = 0x0C;
byte scanLimit = 0x0B;
byte intensity = 0x0A;
byte decodeMode = 0x09;
byte displayTest = 0x0F;


void setup() 
{
 pinMode(clockPin, OUTPUT);
 pinMode(dataPin, OUTPUT);
 pinMode(latchPin, OUTPUT);
 for(int i = 1; i < 9; i++)
 {
  yShift[i - 1] = i;
 }
 

  setUpMax();

}

void loop() 
{
  
 scrollText("Hello World!", 75);


}

void setUpMax()
{
 digitalWrite(latchPin, LOW);

 shiftByte(scanLimit);
 shiftByte(0x07);

 shiftByte(scanLimit);
 shiftByte(0x07);

 digitalWrite(latchPin, HIGH);


 


 digitalWrite(latchPin, LOW);

 shiftByte(decodeMode);
 shiftByte(0x00);
 
 shiftByte(decodeMode);
 shiftByte(0x00);

 digitalWrite(latchPin, HIGH);

 digitalWrite(latchPin, LOW);

 shiftByte(shutDown);
 shiftByte(0x01);

 shiftByte(shutDown);
 shiftByte(0x01);

 digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);
 
 shiftByte(displayTest);
 shiftByte(0x00);

 shiftByte(displayTest);
 shiftByte(0x00);

 digitalWrite(latchPin, HIGH);

  digitalWrite(latchPin, LOW);

 shiftByte(intensity);
 shiftByte(0x0F);

 shiftByte(intensity);
 shiftByte(0x0F);

 digitalWrite(latchPin, HIGH);

 for(int i = 0; i < 8; i++)
 {
  digitalWrite(latchPin, LOW);
  shiftByte(yShift[i]);
  shiftByte(0);
  shiftByte(yShift[i]);
  shiftByte(0);
  digitalWrite(latchPin, HIGH);
 }
}

void shiftByte(byte byteToShift)
{
  
  for(int i = 7; i > -1; i--)
  {
    digitalWrite(clockPin, LOW);
    byte mask = 1<<i;
    if(byteToShift & mask)
    {
      digitalWrite(dataPin, HIGH);
    }else
    {
      digitalWrite(dataPin, LOW);
    }

    digitalWrite(clockPin, HIGH);
    
  }

  
}


void scrollText(String stringToPrint, int scrollSpeed)
{




  for (int i = 0; i < stringToPrint.length(); i++)
  {
   
    for(int j = 0; j < 5; j++)
    {
      for(int h = numberOfDisplays-1; h > -1; h--)
      {
      for(int l = 0; l < 8; l++)
      {
        if(l == 7 && h == 0)
        {
          xShift[h][l] = charToPrint[stringToPrint.charAt(i) - 32][j];
        }else if(l == 7 && h != 0)
        {
          xShift[h][l] = xShift[h-1][0];
        }else
        {
          xShift[h][l] = xShift[h][l+1];
        }

      }
    }
     for(int l = 0; l < numberOfDisplays; l++)
    {
     for(int k = 0; k < 8; k++)
      {
        sendToMax(xShift[l][k], yShift[k], l);
      }
    }
      delay(scrollSpeed);

     
      
    }
  for(int j = numberOfDisplays -1; j > -1; j--)
  {
     for(int l = 0; l < 8; l++)
      {
         if(l == 7 && j == 0)
      {
        xShift[j][l] = 0;
      }else if(l == 7 && j != 0)
      {
        xShift[j][l] = xShift[j-1][0];
      }else
      {
        xShift[j][l] = xShift[j][l+1];
      }
       
      }
  }
      for(int l = 0; l < numberOfDisplays; l++)
    {
     for(int k = 0; k < 8; k++)
      {
        sendToMax(xShift[l][k], yShift[k], l);
      }
    }

       delay(scrollSpeed);
  }

  for(int i = 0; i < 8 * numberOfDisplays; i++)
  {
    for(int l = numberOfDisplays-1; l > -1; l--)
    {
    for(int j = 0; j < 8; j++)
    {
      if(j == 7 && l == 0)
      {
        xShift[l][j] = 0;
      }else if(j == 7 && l != 0)
      {
        xShift[l][j] = xShift[l-1][0];
      }else
      {
        xShift[l][j] = xShift[l][j+1];
      }
    }
    }
    for(int l = 0; l < numberOfDisplays; l++)
    {
     for(int k = 0; k < 8; k++)
      {
        sendToMax(xShift[l][k], yShift[k], l);
      }
    }
       delay(scrollSpeed);
  }
}

void sendToMax(byte byteToSendX, byte byteToSendY, int whichMax )
{
  for(int i = 0; i < numberOfDisplays; i++)
  {
    shiftByte(0);
    shiftByte(0);
  }
  digitalWrite(latchPin, LOW);

  shiftByte(byteToSendY);
  shiftByte(byteToSendX);

  for(int i = 0; i < whichMax; i++)
  {
    shiftByte(0);
    shiftByte(0);
  }

  digitalWrite(latchPin, HIGH);
}

