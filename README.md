# 42-Minishell

## Desarrollo del proyecto

#### Funciones permitidas

| Function | Parameter | Return | Description |
|:---------| :-------- | :------- | :------------------------- |
| `Readline` | `char *str` | `string` | Pasamos como parametro el prompt que mostrara el terminal y nos devolverá el input que insertemos por cli ! importante usar el flag al compilar -lreadline ¡ |
| `rl_clear_history`| `void` | `void`| Elimina todas las entradas del historial que hemos añadido con add_history además de liberar la memoria utilizada para almacenar el historial |
| `rl_on_new_line`| `void`| `int` | Indica al sistema que el cursor se encuentra en la siguiente línea despues de imprimir un texto, el valor de retorno es un int pero no tiene uso, supuestamente es util para la interacción con el sistema |
| `rl_replace_line` | `const char *text, int clear_undo`| `void` | Reemplaza el prompt actual por otro texto que pasemos como parametro, en caso que el segundo parametro sea distinto de 0 las ediciones de prompt anteriores seran eliminadas sin porder deshacer los cambios |
| `rl_redisplay`| `void` | `void` | Cambia lo que se muestra en la pantalla para reflejar el contenido actual del buffer de la línea, se suele utilizar déspues de `rl_replace_line` |
| `add_history`| `char *str` | `void` | Añade al readline por orden de ejecución de esta función todos los string que se pasan como parámetro |
| `printf` | `const char *format, ...` | `int` | Imprime por pantalla en el formato que le expecifiquemos en el primer parametro el resto de parámetros que deseemos. Devuelve la longitud que imprimimos|
| `malloc` | `size_t size` | `void *` | Reserva memoria del sistema devolviendo un puntero a esa memoria para ser utilizada comunmente en estructuras |
| `free` | `void *ptr` | `void` | Libera la memoria que se haya reservado del sistema para el puntero que se le pase como parametro |
| `write`| `int fd, const void buf[.count], size_t count` | `ssize_t`| Escribe en el fd que especifiquemos el segundo parametro hasta la longitud que se configure en el tercer parametro. devuelve el tamaño que se ha impreso|
| `access` | `const char *pathname, int mode`| `int`| Comprueba que el pathname se accesible por el modo que introducimos como segundo parametro. Devuelve 0 si es accesible el pathname con el modo |
| `open` | `const char *pathname, mode_t mode` | `int`| Hace una llamada al sistema para abrir el fichero cuya ruta es el primer parámetro con el modo en el que queremos abrirlo. Devuelve un file descriptor hacia el fichero |
| `read` | `int fd, void buf[.count], size_t count` | `ssize_t` | Intenta leer del fd que le pasamos la cantidad de bytes que le pasamos con tercer parametro y guarda lo que lea en el buffer que le pasamos como segundo parametro. Devuelve la cantidad de bytes que ha leido y -1 en caso de error |
| `close`| `int fd` | `int` | Cierra un fichero director que se haya abierto con open. Devuelve 0  si se cerro con exito sino devuelve -1 |
| `fork`| `void`| `pid_t` | Divide el proceso actual siendo el proceso hijo el que tiene pid 0 y el padre el resultado de llamar a la función. |
| `wait`| `int *_Nullable wstatus` | `pid_t`| Detiene la ejecución actual hasta que un hijo termine de ejecutarse mediante el estado que se le pase como parametro |
| `waitpid`| `pid_t pid, int *_Nullable wstatus, int options` | `pid_t`| Detiene el proceso que le pasemos su pid hasta que su hijo termine mediante las opciones que se le pasan como parametro |
| `wait3`| `int *_Nullable wstatus, int options, struct rusage *_Nullable rusage`| `pid_t`| Hace lo mismo que wait pero en el puntero rusage guarda información del hilo hijo |
| `wait4`| `pid_t pid, int *_Nullable wstatus, int options, struct rusage *_Nullable rusage` | `pid_t` | Hace lo mismo que waitpid pero en el puntero rusage guarda información del hilo hijo |
| `signal`| `int signum, sighandler_t handler` | sighandler_t | Esta función asigna al manejador una señal, el manejador es una función que ante una señal que coincida realiza una acción |
| `sigaction`| `int signum, const struct sigaction *_Nullable restrict act, struct sigaction *_Nullable restrict oldact` | `int`| Ante la señal que se pasa como primer parametro cambia la acción del tercer parametro por la acción del segundo para esa señal. |
| `kill`| `pid_t pid, int sig`| `int` | Envia mediante el pid proporcionado a el proceso una señal personalizada, si se utiliza el 0 en el pid envía a todos los procesos la señal personalizada |
| `exit`| `int status`| `void` | Finaliza el proceso devolviendo el código de status al finalizarlo |
| `getcwd` | `char buf[.size], size_t size`| `char *` | Devuelve un string con el path actual donde se esta ejecutando el proceso |
| `chdir` | `const char *path` | `int` | Cambia al directorio donde nos encontramos por el nuevo que le pasemos por el path |
| `stat`| `const char *restrict pathname, struct stat *restrict statbuf` | `int` | Devuelve información sobre el fichero que le pasemos como pathname en el parametro statbuf |
| `lstat`| `const char *restrict pathname, struct stat *restrict statbuf` | `int` | Igual que stat pero para el path acepta un enlace simbolico |
| `fstat`| `int fd, struct stat *restrict statbuf` | `int` | Igual que stat pero admite |
| `unlink` | `const char *pathname`| `int` | Elimina un fichero del sistema que se especifica con el pathname, si se ha podido eliminar devuelve 0 en caso contrario -1 y actualiza la variable global errno diciendo el porque |
| `execve` | `const char *pathname, char *const _Nullable argv[], char *const _Nullable envp[]` | `int` | Ejecuta el programa que se pasa como primer parametro su path con la posibilidad de añadirle argumentos adicionales y variables de entorno. No devuelve nada si se ejecuta correctamente, en caso contrario -1 |
| `dup` | `int oldfd` | `int` | Crea una nueva copia del file descriptor que se le pasa como parámetro. Esto significa que obtienes un nuevo file descriptor que apunta al mismo archivo abierto, lo que puede ser útil en varias situaciones, como redirigir la entrada y salida estándar de un programa. devuelve 0 si se hizo bien y -1 sino|
| `dup2` | `int olffd, int newfd` | `int` | Crea una copia del file descriptor oldfd y lo asocia al file descriptor de newfd, se utiliza sobre todo para redirigir la entrada o salida estandar a ficheros. Devuelve 0 si fue correcto y -1 sino |
| `opendir` | `char *str` | `DIR *` | Recibe la ruta al directorio y devuelve un puntero a una estructura tipo DIR |
| `readdir` | `DIR *` | `struct dirent` | Cada llamada devuelve el siguiente elemento dentro del directorio como un nodo de la estructura dirent |
| `closedir` | `DIR *` | `int` | Cierra el directorio abierto con opendir. Devielve 0 en éxito y -1 en error |
| `getenv` | `char *str` | `char *` | Busca la variable de entorno str y devuelve su contenido o NULL si no existe | 

## Authors

- Pablo Escaño Martín [@paescano](https://github.com/Pescano)
- Luis Romero Muñoz [@lromero-](https://github.com/lromero-m)
