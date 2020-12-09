
//the pins of 4-digit 7-segment display
int a = 2;
int b = 4;
int c = 25;
int d = 26;
int e = 32;
int f = 33;
int g = 18;
int p = 19;
int d4 = 15;
int d3 = 14;
int d2 = 13;
int d1 = 12;

// n represents the value displayed on the LED display. for example 
int n = -900;
//Set del as 5; the value is the degree of fine tuning for the clock
int del = 5;
void setup()
{
  Serial.begin(115200);
  //set all the pins of the LED display as output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);

}
/***************************************/ 
void loop()
{
  displaySegments(n);
  delay(1);
  n += 1;
}
/**************************************/ 


int getdigit(int number, int digit)
{
    return (number / ((int) pow(10, digit)) % 10);
}

void displaySegments(int n) {
    //clear the 7-segment display screen
    clearLEDs();
    delay(del);

    // display - if number is negative
    if(n < 0) {
        pickDigit(0);
        pickNumber(-1);
        
        // set n positive in order for the rest of the code to read it well
        n *= -1;
        delay(del);
    }

    // Display the three last digits
    pickDigit(1);
    pickNumber(getdigit(n,2));
    delay(del);
    pickDigit(2);
    pickNumber(getdigit(n,1));
    delay(del);
    pickDigit(3);
    pickNumber(getdigit(n, 0));
    delay(del);
}

void pickDigit(int x) //light up a 7-segment display
{
  //The 7-segment LED display is a common-cathode one. So also use digitalWrite to  set d1 as high and the LED will go out
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
    case 0: 
    digitalWrite(d1, HIGH);//Light d1 up 
    digitalWrite(p, HIGH);
    break;
    case 1: 
    digitalWrite(d2, HIGH); //Light d2 up
    digitalWrite(p, HIGH); 
    break;
    case 2: 
    digitalWrite(d3, HIGH); //Light d3 up 
    // display point 
    digitalWrite(p, LOW);
    break;
    default: 
    digitalWrite(d4, HIGH); //Light d4 up 
    digitalWrite(p, HIGH);
    break;
  }
}
//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9 
void pickNumber(int x)
{
    switch(x)
    {
        default:
            hash();
            break;
        case -1:
            minus();
            break;
        case 0: 
            zero(); 
            break;
        case 1: 
            one(); 
            break;
        case 2: 
            two(); 
            break;
        case 3: 
            three(); 
            break;
        case 4: 
            four(); 
            break;
        case 5: 
            five(); 
            break;
        case 6: 
            six(); 
            break;
        case 7: 
            seven(); 
            break;
        case 8: 
            eight(); 
            break;
        case 9: 
            nine(); 
            break;
    }
} 
void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(p, HIGH);
}

void hash() //the 7-segment led display 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void minus() //the 7-segment led display 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one() //the 7-segment led display 1
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two() //the 7-segment led display 2
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
void three() //the 7-segment led display 3
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four() //the 7-segment led display 4
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five() //the 7-segment led display 5
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six() //the 7-segment led display 6
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
