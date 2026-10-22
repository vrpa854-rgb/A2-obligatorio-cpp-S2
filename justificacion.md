# Justificación de órdenes — Obligatorio 1

## Ejercicio 1
- ALTA y BUSCAR en orden temporal O(logK) en el peor caso, siendo K la cantidad de piezas registradas en esa colección al momento de ejecutar la operación. / Justificación: La acción ALTA y BUSCAR se realizan con los método Insertar y Existe del AVL, respectivamente. Estas dos operaciones son O(logK) PC porque es el orden de insertar y buscar un elemento en un AVL.

- RANGO en orden temporal O(logK+R) en el peor caso, siendo R la cantidad de piezas que esa consulta reporta. / Justificación: Se utilizó como referencia la operación InOrden que es O(logK) en caso promedio. Como sigue la misma lógica, es del mismo orden. Recortamos el árbol según el rango buscado para que la función solo recorra R 


## Ejercicio 2
- Utilizar una tabla de hash abierta, con resolución de colisiones por encadenamiento. / Se utilizó Hash.cpp basado tanto en hash cerrado que fue hecho en clase y lo trabajado de hash abierto: un vector de punteros a listas enlazadas, donde cada colisión se resuelve insertando un nodo al principio de la lista de su posición.

- Registrar una palabra y responder una consulta, las dos en orden temporal O(L) promedio, siendo L el largo de la palabra involucrada. / La clave de cada palabra es el conteo de sus letras (los anagramas comparten cajón). Armarla cuesta O(L) para contar más O(26) para escribir el resultado, que es O(L) por ser el alfabeto constante. La clave siempre mide 26 caracteres, por lo que la función de hash (que la recorre completa) y cada comparación dentro del bucket cuestan O(1), sin depender de L. La tabla guarda un único nodo por clave, con la cantidad de palabras del cajón como valor, así que las palabras repetidas no alargan las listas y ningún término depende de cuántas palabras comparten cajón. Con un factor de carga acotado, el largo esperado de cada lista es constante, lo que da O(1) promedio por búsqueda. Registrar hace Existe, Recuperar y Actualizar (o solo Existe e Insertar si la clave es nueva) y consultar hace Existe y Recuperar, un número constante de accesos a la tabla. Cada operación completa es entonces O(L) promedio.

- Decisión sobre el factor de carga: que se mantenga sano durante todo el ejercicio, sin rehash y sin ocupar memoria de más. / La tabla se crea con capacidad 2N, siendo N la cantidad de palabras a registrar. Como hay a lo sumo N claves distintas, el factor de carga nunca supera 0.5, así que este nunca se ejecuta el rehash. El vector tiene un largo primo cercano a 2N, es decir O(N), por lo que tampoco se reserva memoria de más.

- Obtener la última línea de la salida en O(1) en el peor caso. / Se mantienen dos contadores durante el registro. cajonesDistintos se incrementa solo cuando la clave no existía en la tabla, y maxCajon se actualiza al incrementar el contador de un cajón, comparando el nuevo valor contra el máximo actual (y fijándolo en 1 al crear el primer cajón). Ambas actualizaciones son O(1) por palabra. Como los contadores solo crecen, el máximo se mantiene correcto sin recalcularlo. Al final solo se imprimen esos dos enteros, sin recorrer la tabla, las N palabras ni ordenar cajones.

- Resolver el problema completo en orden temporal lineal, en promedio, respecto del tamaño total de la entrada. / Crear la tabla es O(N) (reservar el vector y buscar el primo siguiente a 2N). Registrar las N palabras cuesta O(L) promedio cada una, y responder las Q consultas también, de modo que el total es O(suma de los largos de las N palabras + suma de los largos de las Q consultas), que es lineal en el tamaño de la entrada. La última línea agrega O(1).

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

