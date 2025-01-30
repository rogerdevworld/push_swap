# push_swap

## test.sh
### **Documentación**

#### **Uso**
```bash
sh script.sh <rango> <umbral>
```

#### **Argumentos**
- `<rango>`: Un número entero que define el rango de valores que se generarán aleatoriamente como entrada para el programa `push_swap`.
- `<umbral>`: Un número entero que define el límite máximo aceptable para la cantidad de movimientos generados. Si la cantidad de movimientos es menor que este umbral, se mostrará un mensaje con fondo verde; de lo contrario, se mostrará con fondo rojo.

### **Requisitos**
1. El programa `push_swap` debe estar compilado y en el mismo directorio que este script.
2. Se debe contar con el comando `shuf`, utilizado para generar números aleatorios.
3. Permisos para ejecutar scripts (`chmod +x script.sh`).

---

## **Funcionamiento**

1. **Validación de parámetros**:  
   El script verifica que se hayan pasado exactamente dos argumentos al ejecutarlo:
   - Si no se pasan, muestra un mensaje de uso correcto y finaliza.

2. **Inicialización de variables**:  
   - `RANGO` almacena el rango de números aleatorios especificado por el usuario.
   - `UMBRAL` almacena el número máximo de movimientos aceptables.
   - `SUMA` y `INTENTOS` se inicializan en 0 para calcular el promedio.

3. **Bucle infinito**:  
   En cada iteración del bucle:
   - Se genera un archivo temporal llamado `test.txt` para almacenar la salida de `push_swap`.
   - Se genera una lista de números aleatorios de tamaño `RANGO` con el comando `shuf`.
   - Se ejecuta `push_swap` con la lista generada, redirigiendo la salida a `test.txt`.
   - Se cuenta la cantidad de líneas generadas por `push_swap` usando `wc -l`.
   - Se actualiza la suma total de movimientos (`SUMA`) y el número de intentos (`INTENTOS`).
   - Se calcula el promedio de movimientos hasta ese momento (`PROMEDIO`).
   - Se evalúa si la cantidad de movimientos (`VAR`) es menor que el umbral (`UMBRAL`):
     - Si es menor, se muestra un mensaje con fondo verde.
     - Si es mayor o igual, se muestra un mensaje con fondo rojo.

4. **Salida colorida**:  
   - El uso de códigos ANSI (`\033[42m` y `\033[41m`) permite mostrar los mensajes en colores:
     - Verde para resultados aceptables.
     - Rojo para resultados no aceptables.

5. **El bucle no termina automáticamente**:  
   El script seguirá ejecutándose indefinidamente hasta que se detenga manualmente (Ctrl+C).

---

### **Ejemplo de uso**
```bash
sh script.sh 100 700
```
- Generará listas aleatorias de tamaño 100.
- Ejecutará `push_swap` y verificará si los movimientos generados son menores a 700.
- Mostrará los resultados en la terminal con colores.


### Explicación paso a paso:

1. **Validación inicial**:
   ```c
   if (!stack || num_chunks <= 0)
       return;
   ```
   - Si la pila no es válida (`NULL`) o el número de chunks es menor o igual a cero, la función termina inmediatamente, ya que no es posible realizar ninguna operación.

2. **Encontrar el índice máximo**:
   ```c
   size_t max_index = 0;
   t_stack *current = stack;
   t_stack *start = stack;

   while (current->next != start)
   {
       if (current->index > max_index)
           max_index = current->index;
       current = current->next;
   }
   if (current->index > max_index)
       max_index = current->index;
   ```
   - Recorre toda la pila circular para encontrar el índice más alto (`max_index`). Esto asegura que se conocen los límites de los índices en la pila.
   - Se utiliza un bucle `while` para iterar sobre los nodos, comprobando cada índice y actualizando `max_index` si se encuentra un valor mayor.

3. **Calcular el rango para cada chunk**:
   ```c
   size_t range = (max_index + 1) / num_chunks;
   if ((max_index + 1) % num_chunks != 0)
       range++;
   ```
   - Divide el rango total de índices (`max_index + 1`, porque los índices empiezan en 0) por el número de chunks.
   - Si la división no es exacta, incrementa el tamaño del rango (`range`) para asegurarse de que todos los índices se distribuyan adecuadamente entre los chunks.

4. **Asignar cada elemento a un chunk**:
   ```c
   current = stack;
   while (current->next != start)
   {
       current->group = (max_index - current->index) / range;
       current = current->next;
   }
   current->group = (max_index - current->index) / range;
   ```
   - Recorre de nuevo la pila circular para asignar un grupo (`group`) a cada elemento.
   - La fórmula `(max_index - current->index) / range` determina a qué chunk pertenece cada índice. 
     - **`max_index - current->index`**: Se invierte el orden para asignar índices más altos a chunks más bajos. Esto puede ser útil dependiendo de cómo se manipulen los datos en otros lugares del programa.
     - **División por `range`**: Normaliza el valor dentro del rango de chunks.

5. **Asignar al último nodo**:
   - En pilas circulares, el bucle `while` anterior no procesa el último nodo de forma directa, así que se asegura de asignarle su grupo fuera del bucle:
     ```c
     current->group = (max_index - current->index) / range;
     ```

### Objetivo de la función:
El propósito es clasificar los elementos de la pila en `num_chunks` grupos según su índice, distribuyendo los índices proporcionalmente entre los chunks. Esto se usa típicamente para reducir la complejidad en algoritmos, dividiendo el trabajo en pasos más manejables.

### Consideraciones:
1. **Pila circular**: Dado que se trabaja con una pila circular, se debe verificar si el nodo actual es el nodo inicial (`start`) para evitar un bucle infinito.
2. **Rango ajustado**: El ajuste del rango asegura que todos los índices se distribuyan correctamente incluso cuando `max_index + 1` no es divisible por `num_chunks`.
