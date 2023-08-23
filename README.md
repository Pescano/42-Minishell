# 42-Minishell

## desarrollo del proyecto

#### Funciones permitidas

| Function | Parameter | Return     | Description                |
|:---------| :-------- | :------- | :------------------------- |
| `Readline` | `char *str` | `string` | pasamos como parametro el prompt que mostrara el terminal y nos devolverá el input que insertemos por cli !importante usar el flag al compilar -lreadline ¡ |
| `add_history`| `char *str` |  | añade al readline por orden de ejecución de esta función todos los string que se pasan como parámetro |
| `opendir` | `char *str` | `DIR *` | Recibe la ruta al directorio y devuelve un puntero a una estructura tipo DIR |
| `readdir` | `DIR *` | `struct dirent` | Cada llamada devuelve el siguiente elemento dentro del directorio como un nodo de la estructura dirent |
| `closedir` | `DIR *` | `int` | Cierra el directorio abierto con opendir. Devielve 0 en éxito y -1 en error |
| `getenv` | `char *str` | `char *` | Busca la variable de entorno str y devuelve su contenido o NULL si no existe |
