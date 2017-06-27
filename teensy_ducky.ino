/* USB Prank program
   Teensy becomes a USB keyboard and types characters

   You must select Keyboard from the "Tools > USB Type" menu
*/

#define KEYPRESS_DELAY 20 

int count = 0;
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  delay(3000);

  
  hackaway();
}

void sendkey(int key) {
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(KEYPRESS_DELAY);
  // release all the keys at the same instant
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(KEYPRESS_DELAY);
}

void combokey(int mod, int key) {
  Keyboard.set_modifier(mod);
  Keyboard.send_now();
  delay(KEYPRESS_DELAY);
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(KEYPRESS_DELAY);
  // release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(KEYPRESS_DELAY);
}

void alert() {
  combokey(MODIFIERKEY_GUI, KEY_R);
  delay(400);
  Keyboard.println("mshta javascript:alert(\"SHAME, SHAME, SHAME! YOUR COMPUTER WAS UNLOCKED WHILE YOU WERE AWAY.\\n\\n*** THIS IS JUST A WARNING, YOUR COMPUTER IS FINE ***\\nJUST REMEMBER TO LOCK IT NEXT TIME.\\n\\n -- THE MASKED HIPAA DEFENDER\");close();");
}


void notepad() {
  combokey(MODIFIERKEY_GUI, KEY_R);
  delay(400);
  Keyboard.println("notepad");
  delay(400);
  Keyboard.println("SHAME, SHAME, SHAME! YOUR COMPUTER WAS UNLOCKED WHILE YOU WERE AWAY.");
  Keyboard.println("*** THIS IS JUST A WARNING, YOUR COMPUTER IS FINE ***");
  combokey(MODIFIERKEY_CTRL, KEY_A);
  combokey(MODIFIERKEY_CTRL, KEY_C);
  sendkey(KEY_END);
  for(int i = 0; i < 8; i++) {
    combokey(MODIFIERKEY_CTRL, KEY_V);
  }
}

void hackaway() {
  digitalWrite(ledPin, HIGH);
  combokey(MODIFIERKEY_GUI, KEY_R);
  delay(400);

  // Type and run Powershell
  Keyboard.println("powershell");
  delay(400);

  // Download wallpaper
  
  Keyboard.println("$client = new-object System.Net.WebClient");
  Keyboard.println("$client.DownloadFile('http://i.imgur.com/l4yvh5a.jpg',\"$env:TEMP\\hahalockyourcomputer001.jpg\")");
  Keyboard.println("mspaint \"$env:TEMP\\hahalockyourcomputer001.jpg\"; exit");
  delay(700);

  combokey(MODIFIERKEY_ALT, KEY_F);
  delay(200);
  sendkey(KEY_K);
  delay(200);
  sendkey(KEY_C);
  delay(200);
  
  combokey(MODIFIERKEY_ALT, KEY_F4);

  combokey(MODIFIERKEY_GUI, KEY_D);
  
  alert();
  
  combokey(MODIFIERKEY_GUI, KEY_L);
  
  digitalWrite(ledPin, LOW);
}

void loop() {
  delay(100);
}
