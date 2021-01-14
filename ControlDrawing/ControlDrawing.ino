
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LedControl.h>

int DIN = 16;
int CS =  5;
int CLK = 4;
LedControl lc=LedControl(DIN,CLK,CS,0);

const char* ssid = "NodeMCU";
const char* password = "123456789";

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

void handle_OnConnect(){
  server.send(200, "text/html", WebHTML());
}

void handleLED(){
  String A,A1,A2,A3,A4,A5,A6,A7,A8;int Avalue = 0;
  A1 = server.arg("A1");A2 = server.arg("A2");A3 = server.arg("A3");A4 = server.arg("A4");
  A5 = server.arg("A5");A6 = server.arg("A6");A7 = server.arg("A7");A8 = server.arg("A8");
  A = A1+A2+A3+A4+A5+A6+A7+A8;char *rowA = &A[0];
  for (int i=0; i< strlen(rowA); i++){Avalue *= 2;if (rowA[i] == '1') Avalue++;}

  String X,X1,X2,X3,X4,X5,X6,X7,X8;int Xvalue = 0;
  X1 = server.arg("B1");X2 = server.arg("B2");X3 = server.arg("B3");X4 = server.arg("B4");
  X5 = server.arg("B5");X6 = server.arg("B6");X7 = server.arg("B7");X8 = server.arg("B8");
  X = X1+X2+X3+X4+X5+X6+X7+X8;char *rowX = &X[0];
  for (int i=0; i< strlen(rowX); i++){Xvalue *= 2;if (rowX[i] == '1') Xvalue++;}

  String C,C1,C2,C3,C4,C5,C6,C7,C8;int Cvalue = 0;
  C1 = server.arg("C1");C2 = server.arg("C2");C3 = server.arg("C3");C4 = server.arg("C4");
  C5 = server.arg("C5");C6 = server.arg("C6");C7 = server.arg("C7");C8 = server.arg("C8");
  C = C1+C2+C3+C4+C5+C6+C7+C8;char *rowC = &C[0];
  for (int i=0; i< strlen(rowC); i++){Cvalue *= 2;if (rowC[i] == '1') Cvalue++;}

  String D,D1,D2,D3,D4,D5,D6,D7,D8;int Dvalue = 0;
  D1 = server.arg("D1");D2 = server.arg("D2");D3 = server.arg("D3");D4 = server.arg("D4");
  D5 = server.arg("D5");D6 = server.arg("D6");D7 = server.arg("D7");D8 = server.arg("D8");
  D = D1+D2+D3+D4+D5+D6+D7+D8;char *rowD = &D[0];
  for (int i=0; i< strlen(rowD); i++){Dvalue *= 2;if (rowD[i] == '1') Dvalue++;}

  String E,E1,E2,E3,E4,E5,E6,E7,E8;int Evalue = 0;
  E1 = server.arg("E1");E2 = server.arg("E2");E3 = server.arg("E3");E4 = server.arg("E4");
  E5 = server.arg("E5");E6 = server.arg("E6");E7 = server.arg("E7");E8 = server.arg("E8");
  E = E1+E2+E3+E4+E5+E6+E7+E8;char *rowE = &E[0];
  for (int i=0; i< strlen(rowE); i++){Evalue *= 2;if (rowE[i] == '1') Evalue++;}

  String F,F1,F2,F3,F4,F5,F6,F7,F8;int Fvalue = 0;
  F1 = server.arg("F1");F2 = server.arg("F2");F3 = server.arg("F3");F4 = server.arg("F4");
  F5 = server.arg("F5");F6 = server.arg("F6");F7 = server.arg("F7");F8 = server.arg("F8");
  F = F1+F2+F3+F4+F5+F6+F7+F8;char *rowF = &F[0];
  for (int i=0; i< strlen(rowF); i++){Fvalue *= 2;if (rowF[i] == '1') Fvalue++;}

  String G,G1,G2,G3,G4,G5,G6,G7,G8;int Gvalue = 0;
  G1 = server.arg("G1");G2 = server.arg("G2");G3 = server.arg("G3");G4 = server.arg("G4");
  G5 = server.arg("G5");G6 = server.arg("G6");G7 = server.arg("G7");G8 = server.arg("G8");
  G = G1+G2+G3+G4+G5+G6+G7+G8;char *rowG = &G[0];
  for (int i=0; i< strlen(rowG); i++){Gvalue *= 2;if (rowG[i] == '1') Gvalue++;}

  String H,H1,H2,H3,H4,H5,H6,H7,H8;int Hvalue = 0;
  H1 = server.arg("H1");H2 = server.arg("H2");H3 = server.arg("H3");H4 = server.arg("H4");
  H5 = server.arg("H5");H6 = server.arg("H6");H7 = server.arg("H7");H8 = server.arg("H8");
  H = H1+H2+H3+H4+H5+H6+H7+H8;char *rowH = &H[0];
  for (int i=0; i< strlen(rowH); i++){Hvalue *= 2;if (rowH[i] == '1') Hvalue++;}

  Serial.println(rowA);Serial.println(rowX);Serial.println(rowC);Serial.println(rowD);
  Serial.println(rowE);Serial.println(rowF);Serial.println(rowG);Serial.println(rowH);
  Serial.println("");
  
  lc.setRow(0,0,Avalue);lc.setRow(0,1,Xvalue);lc.setRow(0,2,Cvalue);lc.setRow(0,3,Dvalue);
  lc.setRow(0,4,Evalue);lc.setRow(0,5,Fvalue);lc.setRow(0,6,Gvalue);lc.setRow(0,7,Hvalue);
  
  String page = "<center><a href='/' type='button'> Go Back </button></center>";
  server.send(200, "text/html", page);
}

void setup(){
  Serial.begin(115200);
  
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.on("/", handle_OnConnect);
   
  server.begin();
  Serial.println("");
  Serial.println("HTTP server started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.on("/action", handleLED);
  Serial.println("");
}

void loop(void){
  server.handleClient();
}

String WebHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head>\n";
  ptr += "<title>LED Drawing Control</title>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<style type='text/css'>\n";
  ptr += ".btn{\n";
  ptr += "background-color: #242323;text-align: center;color: #242323;width: 40px;\n";
  ptr += "height: 40px;border: 1px;margin: 2px;border-radius: 5%;}\n";
  ptr += ".btn-submit{\n";
  ptr += "font-weight: bold;text-align: center;border: 3px;margin-top: 10px;\n";
  ptr += "color: #242323;width: 408px;height: 30px;}\n";
  ptr += "</style>\n";
  ptr += "<script type='text/javascript'>\n";
  ptr += "var count = 1;\n";
  ptr += "function change_btn(node){\n";
  ptr += "if(count==1){\n";
  ptr += "document.getElementById(node).style.backgroundColor = '#ff0000';\n";
  ptr += "document.getElementById(node).style.color = '#ff0000';\n";
  ptr += "document.getElementById(node).value = '1';\n";
  ptr += "count = 0;}\n";
  ptr += "else{\n";
  ptr += "document.getElementById(node).style.backgroundColor = '';\n";
  ptr += "document.getElementById(node).style.color = '';\n";
  ptr += "document.getElementById(node).value = '0';\n";
  ptr += "count = 1;}}\n";
  ptr += "</script>\n";
  ptr += "<form action='/action'>\n";
  ptr += "<center><h2 style='margin:30px'>LED Control Drawing Pattern</h2></center>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='A1' id='A1' onclick ='change_btn(`A1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A2' id='A2' onclick ='change_btn(`A2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A3' id='A3' onclick ='change_btn(`A3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A4' id='A4' onclick ='change_btn(`A4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A5' id='A5' onclick ='change_btn(`A5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A6' id='A6' onclick ='change_btn(`A6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A7' id='A7' onclick ='change_btn(`A7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='A8' id='A8' onclick ='change_btn(`A8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='B1' id='B1' onclick ='change_btn(`B1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B2' id='B2' onclick ='change_btn(`B2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B3' id='B3' onclick ='change_btn(`B3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B4' id='B4' onclick ='change_btn(`B4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B5' id='B5' onclick ='change_btn(`B5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B6' id='B6' onclick ='change_btn(`B6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B7' id='B7' onclick ='change_btn(`B7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='B8' id='B8' onclick ='change_btn(`B8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='C1' id='C1' onclick ='change_btn(`C1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C2' id='C2' onclick ='change_btn(`C2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C3' id='C3' onclick ='change_btn(`C3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C4' id='C4' onclick ='change_btn(`C4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C5' id='C5' onclick ='change_btn(`C5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C6' id='C6' onclick ='change_btn(`C6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C7' id='C7' onclick ='change_btn(`C7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='C8' id='C8' onclick ='change_btn(`C8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='D1' id='D1' onclick ='change_btn(`D1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D2' id='D2' onclick ='change_btn(`D2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D3' id='D3' onclick ='change_btn(`D3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D4' id='D4' onclick ='change_btn(`D4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D5' id='D5' onclick ='change_btn(`D5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D6' id='D6' onclick ='change_btn(`D6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D7' id='D7' onclick ='change_btn(`D7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='D8' id='D8' onclick ='change_btn(`D8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='E1' id='E1' onclick ='change_btn(`E1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E2' id='E2' onclick ='change_btn(`E2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E3' id='E3' onclick ='change_btn(`E3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E4' id='E4' onclick ='change_btn(`E4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E5' id='E5' onclick ='change_btn(`E5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E6' id='E6' onclick ='change_btn(`E6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E7' id='E7' onclick ='change_btn(`E7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='E8' id='E8' onclick ='change_btn(`E8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='F1' id='F1' onclick ='change_btn(`F1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F2' id='F2' onclick ='change_btn(`F2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F3' id='F3' onclick ='change_btn(`F3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F4' id='F4' onclick ='change_btn(`F4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F5' id='F5' onclick ='change_btn(`F5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F6' id='F6' onclick ='change_btn(`F6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F7' id='F7' onclick ='change_btn(`F7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='F8' id='F8' onclick ='change_btn(`F8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='G1' id='G1' onclick ='change_btn(`G1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G2' id='G2' onclick ='change_btn(`G2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G3' id='G3' onclick ='change_btn(`G3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G4' id='G4' onclick ='change_btn(`G4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G5' id='G5' onclick ='change_btn(`G5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G6' id='G6' onclick ='change_btn(`G6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G7' id='G7' onclick ='change_btn(`G7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='G8' id='G8' onclick ='change_btn(`G8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<div class='form-group'>\n";
  ptr += "<center>\n";
  ptr += "<input name='H1' id='H1' onclick ='change_btn(`H1`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H2' id='H2' onclick ='change_btn(`H2`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H3' id='H3' onclick ='change_btn(`H3`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H4' id='H4' onclick ='change_btn(`H4`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H5' id='H5' onclick ='change_btn(`H5`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H6' id='H6' onclick ='change_btn(`H6`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H7' id='H7' onclick ='change_btn(`H7`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "<input name='H8' id='H8' onclick ='change_btn(`H8`)' type='text' class='btn' value='0' readonly></input>\n";
  ptr += "</center>\n";
  ptr += "</div>\n";
  ptr += "<center><button type='submit' class='btn-submit' style='background-color: #27db3c'>HASIL</button></center>\n";
  ptr += "</form>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
