//SISTEM LAMPU LALU LINTAS
//4 JALUR
//BY MUHAMMAD VICKY FIRNANSYAH 
//https://github.com/VICKYFIRNANSYAH

// Setelan untuk setiap lampu lalu lintas
int lampu[4][3] = {
  {2, 3, 4},   // Jalur 1: Merah, Kuning, Hijau
  {5, 6, 7},   // Jalur 2: Merah, Kuning, Hijau
  {8, 9, 10},  // Jalur 3: Merah, Kuning, Hijau
  {11, 12, 13} // Jalur 4: Merah, Kuning, Hijau
};
int GoTime = 5000;
int TransisiTime = 2000;

void setup() {
  // Set semua pin LED sebagai output
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(lampu[i][j], OUTPUT);
    }
  }
}
//https://github.com/VICKYFIRNANSYAH

void loop() {
  for (int i = 0; i < 4; i++) {
    // Nyalakan lampu hijau untuk jalur aktif
    digitalWrite(lampu[i][2], HIGH);
    digitalWrite(lampu[i][0], LOW);
    
    // Semua jalur lain lampu merah
    for (int j = 0; j < 4; j++) {
      if (j != i) {
        digitalWrite(lampu[j][0], HIGH);
        digitalWrite(lampu[j][2], LOW);
      }
    }
    
    delay(GoTime); // Lampu hijau menyala selama 5 detik
    
    // Lampu kuning sebelum berganti
    digitalWrite(lampu[i][2], LOW);
    digitalWrite(lampu[i][1], HIGH);
    delay(TransisiTime);
    digitalWrite(lampu[i][1], LOW);
  }
}
