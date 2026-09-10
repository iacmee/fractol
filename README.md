# fractol

Visualizzatore interattivo di frattali scritto in C con MiniLibX per Linux.
Supporta Mandelbrot, Julia e Burning Ship, con zoom e spostamento della vista.

## Requisiti

GCC, Make, Git e un ambiente grafico X11. Su Debian/Ubuntu:

```sh
sudo apt install build-essential git libx11-dev libxext-dev libbsd-dev
```

## Compilazione

```sh
git clone --recurse-submodules https://github.com/iacmee/fractol.git
cd fractol
make
```

[MiniLibX](https://github.com/42Paris/minilibx-linux) è gestita come submodule,
fissato a una revisione precisa. Se il clone non include i submodule, `make`
scarica automaticamente la dipendenza; per scaricarla separatamente:

```sh
make minilibx
```

Il primo download richiede una connessione a Internet.

## Utilizzo

```sh
./fractol M             # Mandelbrot
./fractol J -0.123 0.745 # Julia con parametro complesso cx + cy*i
./fractol B             # Burning Ship
```

Per Julia, omettendo i parametri vengono usati `-0.123` e `0.745`.

| Comando | Azione |
| --- | --- |
| Rotella del mouse oppure `+` / `-` | Zoom centrato sul puntatore |
| Trascinamento con il tasto sinistro | Sposta la vista |
| Frecce direzionali | Sposta la vista |
| `Esc` o chiusura della finestra | Esce dal programma |

## Altri target

- `make opt`: ricompila con ottimizzazioni.
- `make run`: compila e avvia Mandelbrot.
- `make clean`: rimuove i file oggetto del programma.
- `make fclean`: rimuove anche eseguibile e librerie compilate.
- `make re`: esegue una ricompilazione completa.
