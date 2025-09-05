/*
  AyresShell_QuickStart.ino
  -------------------------
  Minimal example to use AyresShell on ESP32 with Arduino IDE.

  Requirements:
  - Board: ESP32
  - FS: LittleFS
  - Dependency: ArduinoJson (>= 6.21.0)
  - Serial Monitor: 115200 baud, "Newline" or "Both NL & CR"

  Note: On first run, LittleFS may be auto-formatted (LittleFS.begin(true)).
*/

#if !defined(ARDUINO_ARCH_ESP32)
  #error "This example targets ESP32 (architectures=esp32)."
#endif

#include <Arduino.h>
#include <LittleFS.h>
#include "AyresShell.h"

AyresShell shell;

// Create some sample files so you can play with the shell right away
static void seedSampleFiles() {
  if (!LittleFS.exists("/config")) {
    LittleFS.mkdir("/config");
  }

  // Sample JSON for JSONSET tests
  if (!LittleFS.exists("/config/wifi.json")) {
    File f = LittleFS.open("/config/wifi.json", "w");
    if (f) {
      f.print("{\"ssid\":\"AyresNet\",\"password\":\"changeme\"}");
      f.close();
    }
  }

  // A simple text file to read and move around
  if (!LittleFS.exists("/readme.txt")) {
    File f = LittleFS.open("/readme.txt", "w");
    if (f) {
      f.println("AyresShell demo file");
      f.println("- Commands: DIR, TYPE, DEL, REN, MV, MKDIR, RMDIR, CD, FORMAT, CLS, HELP");
      f.println("- JSONSET <path> <key> \"<value>\"");
      f.close();
    }
  }
}

void setup() {
  Serial.begin(115200);
  // Short wait so the Serial Monitor can attach on native-USB boards
  unsigned long startWait = millis();
  while (!Serial && (millis() - startWait < 1500)) {}

  Serial.println();
  Serial.println("===== AyresShell Quick Start =====");

  // Mount LittleFS (true = format if mount fails on first boot)
  if (!LittleFS.begin(true)) {
    Serial.println("❌ LittleFS mount failed");
  } else {
    seedSampleFiles();
  }

  // Start the shell (prints its own welcome line)
  shell.begin();

  // Quick on-screen guide
  Serial.println();
  Serial.println("Recommended Serial Monitor settings:");
  Serial.println("  - Baud rate: 115200");
  Serial.println("  - Line ending: Newline (or Both NL & CR)");
  Serial.println();
  Serial.println("Try commands like:");
  Serial.println("  DIR");
  Serial.println("  TYPE /readme.txt");
  Serial.println("  TYPE /config/wifi.json");
  Serial.println("  JSONSET /config/wifi.json password \"my-new-pass\"");
  Serial.println("  CD /config");
  Serial.println("  DIR");
  Serial.println("  REN /readme.txt /README.txt");
  Serial.println("  MKDIR /backup");
  Serial.println("  MV /README.txt /backup/");
  Serial.println("  FORMAT   (⚠️ destructive; asks for confirmation: S/N)");
  Serial.println();
  Serial.println("Type HELP to see the full command list.");
  Serial.println("===================================");
}

void loop() {
  // Feed Serial input to AyresShell
  shell.handleInput();
}
