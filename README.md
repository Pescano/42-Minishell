# 42-Minishell

## desarrollo del proyecto

#### Funciones permitidas

| Function | Parameter | Return     | Description                |
|:---------| :-------- | :------- | :------------------------- |
| `Readline` | `char *str` | `string` | pasamos como parametro el prompt que mostrara el terminal y nos devolverá el input que insertemos por cli !importante usar el flag al compilar -lreadline ¡ |
| `rl_clear_history`| `void` | `void`| elimina todas las entradas del historial que hemos añadido con add_history además de liberar la memoria utilizada para almacenar el historial |
| `rl_on_new_line`| `void`| `int` | indica al sistema que el cursor se encuentra en la siguiente línea despues de imprimir un texto, el valor de retorno es un int pero no tiene uso, supuestamente es util para la interacción con el sistema |
| `rl_replace_line` | `const char *text` `int clear_undo`| `void` | reemplaza el prompt actual por otro texto que pasemos como parametro, en caso que el segundo parametro sea distinto de 0 las ediciones de prompt anteriores seran eliminadas sin porder deshacer los cambios |
| `add_history`| `char *str` |  | añade al readline por orden de ejecución de esta función todos los string que se pasan como parámetro |
| `opendir` | `char *str` | `DIR *` | Recibe la ruta al directorio y devuelve un puntero a una estructura tipo DIR |
| `readdir` | `DIR *` | `struct dirent` | Cada llamada devuelve el siguiente elemento dentro del directorio como un nodo de la estructura dirent |
| `closedir` | `DIR *` | `int` | Cierra el directorio abierto con opendir. Devielve 0 en éxito y -1 en error |
| `getenv` | `char *str` | `char *` | Busca la variable de entorno str y devuelve su contenido o NULL si no existe | 
