# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- ALTA y BUSCAR en orden temporal O(logK) en el peor caso, siendo K la cantidad de piezas
registradas en esa colección al momento de ejecutar la operación. / Justificación: La acción ALTA y BUSCAR se realizan con los método Insertar y Existe del AVL, respectivamente. Estas dos operaciones son O(logK) PC porque es el orden de insertar y buscar un elemento en un AVL.

-RANGO en orden temporal O(logK+R) en el peor caso, siendo R la cantidad de piezas que esa consulta reporta. / Justificación: Se utilizó como referencia la operación InOrden que es O(logK) en caso promedio. Como sigue la misma lógica, es del mismo orden. Recortamos el árbol según el rango buscado para que la función solo recorra R 


## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
- Utilizar un heap binario / Se utilizó Heap.cpp hecho en clase que contiene una cola de prioridad extendida. Lo modificamos para que se comporte únicamente como un heap binario.
- Resolver en orden temporal O(NlogN) en el peor caso, siendo N la cantidad de archivos. / La inserción al heap es O(log N) en peor caso, luego iterar sobre los archivos para insertarlos es de O(N) lo que nos da O(NlogN). Luego, para la segunda iteración, el heap es de tamaño N y esta saca 2 elementos en O(logN) e inserta 1 en el mismo orden. Esto equivale a recorrer uno a uno lo que termina siendo O(NlogN) también. Como las dos iteraciones están al mismo nivel, es O(NlogN)+O(NlogN)=O(NlogN).
- Orden espacial O(N) / La única memoria que se utiliza es el heap que se llena con los N elementos, por lo que el orden espacial es O(N).
- El costo total puede superar el rango de un entero de 32 bits. / Se utilizó long long para prevenir desborde de int en la suma.

## Ejercicio 4
- Sin restricciones de órdenes. / Justificación: utilicé orden topológico que es de O(V+A) cuando se le agrega el heap, cada inserción dentro es log(V) por lo que el orden es O((V+A)* log(V)) como se pide. 
- Utilizar un heap binario / Se utilizó Heap.cpp hecho en clase que contiene una cola de prioridad extendida. Lo modificamos para que se comporte únicamente como un heap binario.
- Resolver en orden temporal O((V+A)logV) en el peor caso, siendo V la cantidad de módulos y A la cantidad de dependencias. / 

## Ejercicio 5
- Utilizar el algoritmo de Kruskal con una estructura de conjuntos disjuntos. / Se utilizó el algoritmo de Kruskal -con la estructura implementada en MFSet.cpp- visto en el curso.
- La estructura de conjuntos disjuntos debe implementar las dos optimizaciones vistas en el curso:
    - Compresión de caminos al buscar el representante de un refugio. / Implementada, como se vio en el curso, actualizando el representante en la función Find del MFSet. 
    - Unión por altura, colgando siempre el árbol más bajo del más alto. / Implementada, como se sugirió en el curso, utilizando un vector de alturas y sumandole altura cuando dos representantes son iguales en la función Merge. Cuando la altura es distinta, se asigna el representante de mayor altura al del menor.
- Resolver en orden temporal O(ElogE) en el peor caso, siendo E la cantidad de senderos.
- Orden espacial O(V+E). / El Heap es de tamaño V + E y el MFSet es de tamaño V + 1, por lo tanto el orden espacial es O(V+E)
- El costo total puede superar el rango de un entero de 32 bits. / Utilizamos long long para devolver el costo.

