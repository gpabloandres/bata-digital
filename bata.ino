#include </home/santiago/sketchbook/libraries/MIDI/src/MIDI.h>

/**
 * Alvaro Lopez Revuelta para http://geekytheory.com/
 * http://alvarorevuelta.net/
 * 
 * Este ejemplo sirve para enviar midi a nuestro ordenador
 * Sera necesario emplear el firmware hiduino para que funcione correctamente
 * https://github.com/ddiakopoulos/hiduino
 * Ojo con usar mas de 11 botones empleando la resistencia de pullup interna
 * Para el pin 13 debe usarse una resistencia de pullup externa
 */
int valorLeido=0; 
int notas[6]={42,38,36,49,50,45};

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  MIDI.begin();                // Inicializamos la comunicacion midi (realmente es serial)
  for(int i=0; i<2; i++) {
    pinMode(i, INPUT);
  }
}

void loop(){
  for(int i=0; i<6; i++) {
  valorLeido = map(analogRead(i), 0, 1024, 0, 127);
    if(valorLeido>10){
      MIDI.sendNoteOn(notas[i], valorLeido, 10);
    }
    else {
      MIDI.sendNoteOff(notas[i], 0, 10);
    }
  }
}


