const int OutputPin = 12; // Output pin for mosfet

const int Dip1 = 4;
const int Dip2 = 5;
const int Dip3 = 3;

const int ShifterInput = 14;

// Dip Switches To Raisee/Lower Shift Delay
bool Dip1Active = false;
bool Dip2Active = false;
bool Dip3Active = false;

bool CutEnabled = false;

int DipValue = 50; // Value In Milliseconds
int BaseDelayValue = 100; // Value With No Dip Switches Active In Milliseconds

void setup() {
  Serial.begin(115200); // open the serial port at 115200 bps

  // Input Pins
  pinMode(Dip1, INPUT_PULLUP);
  pinMode(Dip2, INPUT_PULLUP);
  pinMode(Dip3, INPUT_PULLUP);

  pinMode(ShifterInput, INPUT_PULLUP);


  // Output Pin
  pinMode(OutputPin, OUTPUT);

}

void loop() {
  if (digitalRead(Dip1) == LOW && Dip1Active == false) {
    Dip1Active = true;
    BaseDelayValue = BaseDelayValue + DipValue;
  }
  else if (digitalRead(Dip1) == HIGH && Dip1Active == true) {
    Dip1Active = false;
    BaseDelayValue = BaseDelayValue - DipValue;
  }

  if (digitalRead(Dip2) == LOW  && Dip2Active == false) {
    Dip2Active = true;
    BaseDelayValue = BaseDelayValue + DipValue;
  }
  else if (digitalRead(Dip2) == HIGH && Dip2Active == true) {
    Dip2Active = false;
    BaseDelayValue = BaseDelayValue - DipValue;
  }

  if (digitalRead(Dip3) == LOW  && Dip3Active == false) {
    Dip3Active = true;
    BaseDelayValue = BaseDelayValue + DipValue;
  }
  else if (digitalRead(Dip3) == HIGH && Dip3Active == true) {
    Dip3Active = false;
    BaseDelayValue = BaseDelayValue - DipValue;
  }
  

  // Shift Logic
  if (digitalRead(ShifterInput) == LOW && CutEnabled == false) {
    CutEnabled = true;
    digitalWrite(OutputPin, HIGH);
    delay(BaseDelayValue);
    digitalWrite(OutputPin, LOW);
  }
  else if (digitalRead(ShifterInput) == HIGH && CutEnabled == true) {
    delay(10);
    CutEnabled = false;
  }
  



}
