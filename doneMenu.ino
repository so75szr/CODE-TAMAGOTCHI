#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

enum EtatAffichage { AFFICHER_MENU };

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define brocheResetOLED    -1
#define adresseI2CecranOLED 0x3C

const int PIN_BOUTON_MILIEU = 16;
const int PIN_BOUTON_GAUCHE = 17;
const int PIN_BOUTON_DROITE = 15;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, brocheResetOLED);

const unsigned char Tcosmo [] PROGMEM = {
	0x00, 0xf0, 0x00, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x0f, 0x00, 0x03, 0x0f, 0xff, 0xf0, 0xc0, 0x03, 
	0x0f, 0xff, 0xf0, 0xc0, 0x0c, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x00, 
	0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x00, 0x30, 0x30, 0x30, 0x00, 0x0c, 0x0c, 0x30, 0x30, 0x00, 
	0x0c, 0x0c, 0x30, 0xc0, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x03, 0x0c, 0xc0, 0xcf, 0x00, 0xf3, 
	0x03, 0xc0, 0xcf, 0x00, 0xf3, 0x03, 0xc0, 0xcf, 0x00, 0xf3, 0x03, 0xc0, 0xcf, 0x00, 0xf3, 0x03, 
	0xc0, 0xc0, 0x00, 0x03, 0x03, 0xc0, 0xc0, 0x00, 0x03, 0x03, 0xc0, 0xc0, 0x3c, 0x03, 0x03, 0xc0, 
	0xc0, 0x3c, 0x03, 0x03, 0xc0, 0x30, 0x3c, 0x0c, 0x03, 0xc0, 0x30, 0x3c, 0x0c, 0x03, 0xc0, 0x30, 
	0x00, 0x0c, 0x03, 0xc0, 0x30, 0x00, 0x0c, 0x03, 0x30, 0x30, 0x00, 0x0c, 0x0c, 0x30, 0x30, 0x00, 
	0x0c, 0x0c, 0x0c, 0x30, 0x00, 0x0c, 0x30, 0x0c, 0x30, 0x00, 0x0c, 0x30, 0x03, 0x30, 0x3c, 0x0c, 
	0xc0, 0x03, 0x30, 0x3c, 0x0c, 0xc0, 0x00, 0xcf, 0x00, 0xf3, 0x00, 0x00, 0xcf, 0x00, 0xf3, 0x00, 
	0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00
};
const unsigned char Tfood [] PROGMEM = {
	0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x03, 0xf0, 
	0x00, 0x03, 0xc3, 0xff, 0x00, 0x03, 0xc3, 0xff, 0x00, 0x0c, 0x3f, 0xff, 0x00, 0x0c, 0x3f, 0xff, 
	0x00, 0x30, 0xcf, 0xff, 0x00, 0x30, 0xcf, 0xff, 0x00, 0xc3, 0x03, 0xc0, 0x00, 0xc3, 0x03, 0xc0, 
	0x03, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xc0, 0x0c, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30, 
	0x0c, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30, 0x03, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0xc0, 
	0x03, 0xc0, 0x03, 0x00, 0x03, 0xc0, 0x03, 0x00, 0xff, 0xf0, 0x0c, 0x00, 0xff, 0xf0, 0x0c, 0x00, 
	0xff, 0xfc, 0x30, 0x00, 0xff, 0xfc, 0x30, 0x00, 0xff, 0xc3, 0xc0, 0x00, 0xff, 0xc3, 0xc0, 0x00, 
	0x0f, 0xc0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00
};
const unsigned char Tplay [] PROGMEM = {
		0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x03, 
	0xc0, 0x00, 0x00, 0x3c, 0x00, 0x03, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x3c, 0x00, 0x03, 0xc0, 
	0x00, 0x00, 0x3c, 0x00, 0x0c, 0x00, 0x3f, 0xc0, 0x03, 0x00, 0x0c, 0x00, 0x3f, 0xc0, 0x03, 0x00, 
	0x30, 0x00, 0x30, 0xc0, 0x00, 0xc0, 0x30, 0x00, 0x30, 0xc0, 0x00, 0xc0, 0x30, 0x00, 0x3f, 0xc0, 
	0x00, 0xc0, 0x30, 0x00, 0x3f, 0xc0, 0x00, 0xc0, 0x30, 0x30, 0x00, 0x00, 0xc0, 0xc0, 0x30, 0x30, 
	0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xfc, 0x0f, 0x03, 0x30, 0x30, 0xc0, 0xfc, 0x0f, 0x03, 0x30, 0x30, 
	0xc0, 0x30, 0x00, 0x00, 0xc0, 0x30, 0xc0, 0x30, 0x00, 0x00, 0xc0, 0x30, 0xc0, 0x00, 0xf0, 0xf0, 
	0x00, 0x30, 0xc0, 0x00, 0xf0, 0xf0, 0x00, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x30, 0xc0, 0x00, 
	0x00, 0x00, 0x00, 0x30, 0xc0, 0x03, 0xff, 0xfc, 0x00, 0x30, 0xc0, 0x03, 0xff, 0xfc, 0x00, 0x30, 
	0xc0, 0x03, 0x00, 0x0c, 0x00, 0x30, 0xc0, 0x03, 0x00, 0x0c, 0x00, 0x30, 0x30, 0x0c, 0x00, 0x03, 
	0x00, 0xc0, 0x30, 0x0c, 0x00, 0x03, 0x00, 0xc0, 0x0c, 0x0c, 0x00, 0x03, 0x03, 0x00, 0x0c, 0x0c, 
	0x00, 0x03, 0x03, 0x00, 0x03, 0xf0, 0x00, 0x00, 0xfc, 0x00, 0x03, 0xf0, 0x00, 0x00, 0xfc, 0x00
};
const unsigned char Tsettings [] PROGMEM = {
0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 
	0x03, 0xcf, 0xf3, 0xc0, 0x03, 0xcf, 0xf3, 0xc0, 0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 
	0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 
	0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 
	0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 
	0x03, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 
	0x0f, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xf0, 0x03, 0xcf, 0xf3, 0xc0, 0x03, 0xcf, 0xf3, 0xc0, 
	0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00
};
const unsigned char Tbathroom [] PROGMEM = {
	0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x03, 0x0c, 0x00, 0x00, 0x00, 0x03, 
	0x0c, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x3f, 
	0x00, 0x00, 0x00, 0x0c, 0x3f, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 
	0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x3f, 
	0xff, 0xff, 0xff, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0xff, 
	0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 
	0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 
	0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 
	0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x03, 0x00, 0x30, 
	0x00, 0x00, 0x03, 0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x0c, 0x00, 
	0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x0c, 0x00, 0x03, 0x00, 0x00, 0x30, 0x00, 0x03, 0x00, 0x00, 
	0x30, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x30, 0x03, 0x00, 
	0x00, 0x00, 0x30, 0x03, 0x00, 0x00
};
const unsigned char FDroite [] PROGMEM = {
    0x80, 0x00, 0xe0, 0x00, 0xf8, 0x00, 0xfe, 0x00, 0xff, 0x80, 0xff, 0xe0, 0xff, 0x80, 0xfe, 0x00, 
    0xf8, 0x00, 0xe0, 0x00, 0x80, 0x00
};
const unsigned char FGauche [] PROGMEM = {
    0x00, 0x20, 0x00, 0xe0, 0x03, 0xe0, 0x0f, 0xe0, 0x3f, 0xe0, 0xff, 0xe0, 0x3f, 0xe0, 0x0f, 0xe0, 
    0x03, 0xe0, 0x00, 0xe0, 0x00, 0x20
};

bool cosmoBienvenueAffiche = true; 
bool menuAffiche = false; // Indique si le menu est actuellement affiché ou non

int selectionMenu = 0; // Indique l'élément actuellement sélectionné dans le menu

void CosmoBienvenue() {
    display.clearDisplay();
    display.setTextSize(1);     
    display.setTextColor(WHITE); 
    display.setCursor(0, 2);    
    display.println("Bonjour ici CosmoGone !");
    display.drawBitmap(42, 24, Tcosmo, 40, 34, WHITE);
    display.display();
}

void afficherMenuPrincipal() {
    display.clearDisplay();
    
    // Affichez le bouton du milieu
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(100, 2);
    display.print("Menu");

    // Affichez le bouton gauche et le bouton droit
    display.drawBitmap(2, 42, FGauche, 11, 11, WHITE);
    display.drawBitmap(115, 42, FDroite, 11, 11, WHITE);

    // Afficher les éléments du menu
    switch (selectionMenu) {
        case 0: // Jouer
            display.drawBitmap(40, 24, Tplay, 44, 32, WHITE);
            display.setTextSize(1);     
            display.setTextColor(WHITE); 
            display.setCursor(0, 2);    
            display.println("Jouer");
            break;
        case 1: // Manger
            display.drawBitmap(42, 24, Tfood, 32, 32, WHITE);
            display.setTextSize(1);     
            display.setTextColor(WHITE); 
            display.setCursor(0, 2);    
            display.println("Manger");
            break;
        case 2: // Laver
            display.drawBitmap(42, 18, Tbathroom, 34, 46, WHITE);
            display.setTextSize(1);     
            display.setTextColor(WHITE); 
            display.setCursor(0, 2);    
            display.println("Laver");
            break;
        case 3: // Parametres
            display.drawBitmap(42, 24, Tsettings, 32, 32, WHITE);
            display.setTextSize(1);     
            display.setTextColor(WHITE); 
            display.setCursor(0, 2);    
            display.println("Parametres");
            break;
    }

    // Affichage sur l'écran
    display.display();
}

void setup() {
    pinMode(PIN_BOUTON_MILIEU, INPUT_PULLUP);
    pinMode(PIN_BOUTON_GAUCHE, INPUT_PULLUP);
    pinMode(PIN_BOUTON_DROITE, INPUT_PULLUP);
    display.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED);
    display.clearDisplay();
    Serial.begin(9600);
}

void loop() {
    // Si le bouton du milieu est pressé et que le menu n'est pas déjà affiché, affichez-le
    if (digitalRead(PIN_BOUTON_MILIEU) == LOW && !menuAffiche) {
        delay(250); // Délai pour éviter la détection multiple de l'appui sur le bouton
        menuAffiche = true;
        afficherMenuPrincipal();
    }

    // Si le menu est affiché, vérifiez les boutons gauche et droit pour naviguer dans le menu
    if (menuAffiche) {
        // Vérifiez si le bouton gauche est pressé
        if (digitalRead(PIN_BOUTON_GAUCHE) == LOW) {
            // Sélectionner l'élément précédent dans le menu
            selectionMenu = (selectionMenu - 1 + 3) % 3;
            afficherMenuPrincipal();
            delay(250); // Délai pour éviter la détection multiple de l'appui sur le bouton
        }

        // Vérifiez si le bouton droit est pressé
        if (digitalRead(PIN_BOUTON_DROITE) == LOW) {
            // Sélectionner l'élément suivant dans le menu
            selectionMenu = (selectionMenu + 1) % 3;
            afficherMenuPrincipal();
            delay(250); // Délai pour éviter la détection multiple de l'appui sur le bouton
        }

        // Si le bouton du milieu est pressé alors que le menu est affiché, cachez-le
        if (digitalRead(PIN_BOUTON_MILIEU) == LOW) {
            delay(250); // Délai pour éviter la détection multiple de l'appui sur le bouton
            menuAffiche = false;
            CosmoBienvenue();
        }
    }
}
