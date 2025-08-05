<p align="center">
  <img src="https://res.cloudinary.com/dxunooptp/image/upload/v1754359437/banner_github_20250804_225256_0000_i9yrwv.jpg" alt="AyresShell Banner" width="100%" />
</p>

# AyresShell

**AyresShell** es una consola serial interactiva para ESP32 que permite ejecutar comandos de administración, depuración, manejo de archivos y edición de JSON directamente desde el monitor serial.  
Creado por [Daniel Cristian Salgado](https://github.com/ayresnet), es compatible con Arduino IDE y PlatformIO.

---

## 🚀 Características

- Comandos tipo shell para interactuar con el sistema de archivos (LittleFS)
- Edición de campos JSON desde la terminal
- Ampliable con comandos personalizados (`addCommand`)
- Compatible con:
  - ✅ Arduino IDE
  - ✅ PlatformIO

---

## 📦 Instalación

### 🔧 PlatformIO

```ini
lib_deps = https://github.com/ayresnet/AyresShell
```

### 🔧 Arduino IDE

1. Descargar el repositorio como ZIP
2. Extraer en `Documentos/Arduino/libraries/AyresShell`
3. Reiniciar el IDE

---

## 🧪 Ejemplo básico

```cpp
#include <AyresShell.h>
#include <FS.h>
#include <LittleFS.h>

AyresShell shell;

void setup() {
  Serial.begin(115200);
  LittleFS.begin();

  shell.begin();

}

void loop() {
  shell.handleInput();
}
```

---

## 🧭 Comandos incluidos

| Comando                  | Descripción                                                  |
|--------------------------|--------------------------------------------------------------|
| `DIR`                   | Lista archivos en el sistema de archivos                     |
| `TYPE <archivo>`        | Muestra el contenido de un archivo                           |
| `DEL <archivo>`         | Elimina un archivo                                           |
| `REN <a> <b>`           | Renombra un archivo                                          |
| `MV <a> <b>`            | Mueve un archivo a otra carpeta                              |
| `MKDIR <carpeta>`       | Crea un directorio                                           |
| `RMDIR <carpeta>`       | Elimina un directorio vacío                                  |
| `CD <carpeta>`          | Cambia de directorio (incluye `..` y `/`)                    |
| `CLS`                   | Limpia la pantalla                                           |
| `HELP`                  | Muestra la lista de comandos                                 |
| `FORMAT`                | Formatea el sistema de archivos (confirma con `S`)           |
| `JSONSET <ruta> <clave> "<valor>"` | Edita un campo JSON directamente en archivo        |

---

## 📂 Estructura del proyecto

```
AyresShell/
├── src/
│   ├── AyresShell.cpp
│   └── AyresShell.h
├── examples/
│   └── BasicShellDemo/
├── library.json
├── library.properties
├── keywords.txt
├── LICENSE
└── README.md
```

---

## 🪪 Licencia

Distribuido bajo la licencia MIT.  
Libre para usar, modificar y compartir.

---
