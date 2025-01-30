#!/bin/bash

# Colores
WHITE='\033[1;37m'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Tester para muchos casos y generar el promedio
if [ "$#" -lt 2 ] || [ "$#" -gt 3 ]; then
    echo "Uso: sh $0 <rango> <movimientos>"
    exit 1
fi

RANGO=$1
UMBRAL=$2
SUMA=0
INTENTOS=0
PUNTOS=0
MIN=2147483647
MAX=0

for ((i = 1; i <= 501; i++)); do
    rm -f test.txt checker.txt

    # Generar números aleatorios con una semilla única en cada iteración
    ARG=$(awk -v n="$i" -v seed="$i" 'BEGIN { srand(seed); for (i = 0; i < n; i++) printf("%d ", int(-2147483648 + rand() * (2147483647 - -2147483648 + 1))) }')

    ./push_swap $ARG > test.txt
    ./push_swap $ARG | ./checker $ARG > checker.txt

    VAR=$(wc -l < test.txt)
    ULTIMA_LINEA=$(tail -n 1 checker.txt)
    
    if [ "$VAR" -le "$UMBRAL" ] && [ "$ULTIMA_LINEA" = "OK" ]; then
        echo -e "${GREEN}$i.[OK] - Movimientos: $VAR${NC}"
        PUNTOS=$((PUNTOS + 1))
    else
        echo -e "${RED}[KO]${NC} $ARG"
    fi
done