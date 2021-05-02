#define BUZZER_PIN 13

// notes frequencies
#define A1 440
#define G1 392
#define F1 349
#define E1 330
#define D1 294

// rate 120 4/4
#define FULL 2000
#define HALF 1000
#define QUARTER 500
#define EIGHTH 250
#define SIXTEENTH 125

#define NOTES_COUNT 31

class Note {

  public:
    Note(unsigned int frequency, unsigned int duration, unsigned int silentDuration) {
      _frequency = frequency;
      _duration = duration;
      _silentDuration = silentDuration;
    }

    unsigned int getFrequency()
    {
      return _frequency;
    }
    unsigned int getDuration()
    {
      return _duration;
    }
    unsigned int getSilentDuration()
    {
      return _silentDuration;
    }

  private:
    unsigned int _frequency;
    unsigned int _duration;
    unsigned int _silentDuration;
};

Note melody[NOTES_COUNT] = {
  Note(0, 0, HALF),
  Note(A1, QUARTER + EIGHTH, EIGHTH),
  Note(A1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(F1, EIGHTH, SIXTEENTH),
  Note(G1, QUARTER, QUARTER),

  Note(D1, EIGHTH, 0),
  Note(G1, QUARTER, EIGHTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(F1, EIGHTH, SIXTEENTH),
  Note(E1, EIGHTH, SIXTEENTH),
  Note(F1, QUARTER, QUARTER),
  
  Note(A1, QUARTER + EIGHTH, EIGHTH),
  Note(A1, EIGHTH, SIXTEENTH),
  Note(A1, EIGHTH, SIXTEENTH),
  Note(A1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(F1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, 0),
  Note(F1, EIGHTH, 0),
  Note(E1, EIGHTH, QUARTER),
  
  Note(D1, EIGHTH, 0),
  Note(G1, QUARTER, EIGHTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(G1, EIGHTH, SIXTEENTH),
  Note(F1, EIGHTH, SIXTEENTH),
  Note(E1, EIGHTH, SIXTEENTH),
  Note(F1, QUARTER, HALF),
};

unsigned long startTime = 0;
unsigned int currentNoteIndex = 0;
bool started = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!started) {
    startTime = millis();
    started = true;
  }
  unsigned long currentTime = millis() - startTime;

  if (currentTime < melody[currentNoteIndex].getDuration()) {
    tone(BUZZER_PIN, melody[currentNoteIndex].getFrequency(), 20);
  } else if (currentTime > melody[currentNoteIndex].getDuration() + melody[currentNoteIndex].getSilentDuration()) {
    currentNoteIndex++;
    if (currentNoteIndex == NOTES_COUNT) {
      currentNoteIndex = 0;
    }
    started = false;
  }
}
