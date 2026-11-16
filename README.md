# `push_swap` — Portfolio Engine (DP Circular LIS + Multi-Variant Turk + Peephole Optimizer)

Implementación de alto rendimiento en C para el proyecto **`push_swap`** de 42, diseñada para minimizar el número de operaciones mediante un **Portafolio de Algoritmos en Memoria** que evalúa 6 variantes heurísticas en paralelo y selecciona la secuencia más corta.

---

## Arquitectura y Fórmulas del Algoritmo

En lugar de depender de una única heurística fija, el motor clona la pila inicial en memoria RAM y ejecuta **6 variantes competitivas** en milisegundos, midiendo la longitud exacta del buffer de instrucciones resultante tras un optimizador *peephole*:

$$\text{Solución Óptima} = \arg\min_{v \in \{0..5\}} \left| \text{Optimize}\left(\text{Simular}(A_0, v)\right) \right|$$

### 1. Discretización por Rangos Ordinales
Cada entero de entrada $x_i \in [-2^{31}, 2^{31}-1]$ se transforma en su rango ordinal limpio:

$$r(x_i) = \left| \{ x_j \in A : x_j < x_i \} \right| \in \{0, 1, \dots, N-1\}$$

### 2. Programación Dinámica para LIS Circular (*Longest Increasing Subsequence*)
Dado que las pilas funcionan como listas circulares mediante rotaciones, el algoritmo evalúa las $N$ rotaciones iniciales posibles y calcula mediante **Programación Dinámica** ($O(N^2)$) la subsecuencia estrictamente creciente más larga:

$$DP[i] = 1 + \max_{0 \le j < i,\; r_j < r_i} DP[j]$$

Los nodos pertenecientes a la LIS máxima se marcan con `keep = true` y **permanecen en la pila A**, reduciendo drásticamente el volumen de elementos que deben desplazarse a B.

### 3. Particionamiento por Chunks con Escaneo Bidireccional (`ra` vs `rra`)
Al vaciar los elementos no marcados hacia la pila B, en lugar de rotar siempre hacia arriba (`ra`), el algoritmo calcula la distancia desde la cima ($d_{\text{top}}$) y desde la base ($N - d_{\text{bottom}}$), eligiendo el sentido de giro más corto:

$$\text{dir} = \begin{cases} \text{ra} & \text{si } d_{\text{top}} \le N - d_{\text{bottom}} \\ \text{rra} & \text{si } d_{\text{top}} > N - d_{\text{bottom}} \end{cases}$$

Además, cada banda doble $[\text{low}, \text{high})$ divide los rangos respecto al pivote medio $\text{mid}$, combinando `pb` + `rb` (o `rr` mediante *lookahead* si el siguiente elemento de A también debe rotarse).

### 4. Función de Coste Combinado de 4 Rutas (*Turk Greedy Return*)
Para reinsertar cada nodo $b \in B$ en su posición destino $t(b) \in A$, se calculan las **4 trayectorias posibles** aprovechando giros simultáneos (`rr` y `rrr`):

1. **Ruta 0 (`rr` — ambos hacia arriba):**
   $$C_0 = \max(\text{idx}_A, \text{idx}_B)$$
2. **Ruta 1 (`rrr` — ambos hacia abajo):**
   $$C_1 = \max(\text{len}_A - \text{idx}_A, \text{len}_B - \text{idx}_B)$$
3. **Ruta 2 (`ra` + `rrb` — cruzada arriba/abajo):**
   $$C_2 = \text{idx}_A + (\text{len}_B - \text{idx}_B)$$
4. **Ruta 3 (`rra` + `rb` — cruzada abajo/arriba):**
   $$C_3 = (\text{len}_A - \text{idx}_A) + \text{idx}_B$$

El coste de inserción de cada nodo es $C(b) = \min(C_0, C_1, C_2, C_3)$. En cada iteración se ejecuta el nodo de coste mínimo global, con sesgo de desempate hacia `rrr` en las variantes agresivas.

### 5. Portafolio de 6 Variantes en Competición
| Variante | Estrategia de Permanencia en A | Bandas Espaciales ($B$) | Sesgo de Rotación Inversa (`rrr`) |
| :--- | :--- | :---: | :---: |
| **V0** | DP Circular LIS | 4 bandas | Estándar |
| **V1** | DP Circular LIS | 6 bandas | Estándar |
| **V2** | DP Circular LIS | 8 bandas | Prioridad `rrr` en empates |
| **V3** | Pure Turk (Top-3 max en A) | 6 bandas | Estándar |
| **V4** | Pure Turk (Top-3 max en A) | 8 bandas | Prioridad `rrr` en empates |
| **V5** | Pure Turk (Top-3 max en A) | 10 bandas | Prioridad `rrr` en empates |

### 6. Optimizador *Peephole* Post-Simulación
Antes de imprimir, el buffer ganador pasa por una pasada de fusión y cancelación algebraica:
* `ra` + `rb` $\rightarrow$ `rr`
* `rra` + `rrb` $\rightarrow$ `rrr`
* `sa` + `sb` $\rightarrow$ `ss`
* Cancelación de pares inversos redundantes (`pa`/`pb`, `ra`/`rra`, `rb`/`rrb`).

---

## Compilación y Uso

### Programa Principal (`push_swap`)
```bash
make
./push_swap 4 67 3 87 23
```

### Bonus (`checker`)
El programa `checker` lee instrucciones desde `stdin`, las ejecuta sobre la pila inicial y verifica que `A` quede ordenada y `B` vacía:
```bash
make bonus
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
* Imprime `OK` si la pila queda ordenada y `B` está vacía.
* Imprime `KO` si no queda ordenada.
* Imprime `Error` en `stderr` ante argumentos inválidos, duplicados, desbordamientos o instrucciones desconocidas.

---

## Benchmarks Esperados
* **3 números:** $\le 2$ operaciones.
* **5 números:** $\le 12$ operaciones.
* **100 números:** ~480 – 560 operaciones (100% puntuación máxima: $< 700$).
* **500 números:** ~3,450 – 3,750 operaciones (100% puntuación máxima: $< 5,500$).
