# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
Primera idea:
- ALTA y BUSCAR en orden temporal O(logK) en el peor caso, siendo K la cantidad de piezas
registradas en esa colección al momento de ejecutar la operación. / Justificación: La acción ALTA y BUSCAR se realizan con los método Insertar y Existe del AVL, respectivamente. Estas dos operaciones son O(logK) PC porque es el orden de insertar y buscar un elemento en un AVL.

-RANGO en orden temporal O(logK+R) en el peor caso, siendo R la cantidad de piezas que esa consulta reporta. / Justificación: Se utilizó como referencia la operación InOrden que es O(logK) en caso promedio. Como sigue la misma lógica, es del mismo orden. No pudimos lograr ese orden en el peor caso. 


## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5
- Sin restricciones de órdenes. / Justificación: ...

