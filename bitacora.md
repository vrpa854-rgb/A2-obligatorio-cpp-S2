# Bitácora — Obligatorio 1

**Integrantes:** Venancio Portillo (276560), Lucía Mottillo (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-09-06 - Venancio Portillo
- Comencé a crear el TAD Hash Table basado en lo dado en clase.

## 2026-09-14 - Venancio Portillo
- Comencé a crear el TAD AVL basado en lo dado en clase.

## 2026-09-16 - Lucía Mottillo
- Leí la letra del ejercicio 1, empecé a hacer bocetos de como debería de ser. 
  Empecé a programar y dejé planteada una idea que sirve (da el resultado esperado).
  Falta chequear que cumpla con la complejidad.

## 2026-09-23 - Lucía Mottillo
- Agregué el tad del grafo, basado en lo que trabajamos en clase.

## 2026-09-27 - Venancio Portillo
- Agregué el rehash a la tabla de hash. Primero dividí el problema en 4 partes: Creación del nuevo vector, rehashing, limpieza y actualización.
 La creación del nuevo vector empieza por duplicar su capacidad, obtener un nuevo primo superior y generar el nuevo vector con esa base.
 El rehash recorre todo el vector viejo con dos condiciones base: Si no hay nodo, sigo; si está borrado no lo paso y limpio la memoria.
 Luego avanzo en el vector nuevo hasta encontrar un lugar disponible y guardo el nodo. Como utilizo punteros, puedo pasarlos de forma sencilla y clara. Esto lo puedo hacer porque las condiciones anteriores me aseguran que no existirán nodos borrados. A diferencia de el método Insertar que debo verificarlo.
 Al final, elimino el vector viejo para liberar la memoria y actualizo el hash a los valores del nuevo vector.

## 2026-09-27 - Venancio Portillo
- Agregué las rotaciones al TAD AVL.

## 2026-10-02 - Venancio Portillo
- Validé y ajusté las restricciones del ejercicio 1. Creé los métodos Existe y InOrderRango para el AVL.
 La única forma que encontré de cumplir la restricción temporal O(logK + R) PC era crear el método InOrderRango dentro del AVL.
 Faltó correr las pruebas. Estoy armando los scritps para automatizarlas.

## 2026-10-07 - Venancio Portillo
-Ajusté detalles y probé el ejercicio 1. Pasó todas las pruebas. Detecté por hacer que RANGO aún no valída O(logK + R),  falta cambiarlo.
Agregué una primera idea de la justificación de ordenes

## 2026-10-12 - Lucía Mottillo
- Agregué el TAD de heap como lo vimos en clase.
- Hice el ejercicio 3. Utilicé Heap (hice un minHeap) ya que la letra misma lo pide. Para resolver el ejercicio primero intenté haciendo una lista, a la cual le cargué todos los datos y de ahí cargarlo al minHeap pero no cumplía con las resticciones, por ende, primero se carga todo al heap y luego se va agarrando de a dos (agarro el tope, lo elimino, agarro el nuevo tope) e insertando y eliminando hsta que quede solamente la suma resultante.

## 2026-10-14 - Lucía Mottillo
- Empecé el ejercicio 2, estuve pensando cómo armar la función hash para que sea la más óptima posible y haya la menor canttidad de coalisiones. Mi idea inicial era sumar el valor de las letras (A - 1, B - 2, ..., Z - 26) pero hay varios valores que pueden tener el mismo resultado, luego se me ocurrió armar un array de bool de largo 26 y poner true cuando está la letra, pero no permite letras repetidas, por lo que concluí en un array de largo 26 de int, que pone la cantidad de veces que aparece una letra. A base de eso se arma la clave que se utiliza en la función hash junto con la regla de Horner.

## 2026-10-15- Lucía Mottillo
- Modifiqué el TAD de Hash, porque el que teníamos era para Hash cerrado y el ejercicio pide que sea abierto.
- Hice el ejercicio 3.

## 2026-10-20 - Venancio Portillo
- Probé el ejercicio 2. Pasa las pruebas y cumple los requerimientos.
- Hice el ejercicio 4 con Orden topológico y heap. Pasó las pruebas.
- Hice ajustes al ejercicio 3. Pasó las pruebas.

## 2026-10-21 - Venancio Portillo
- Hice el ejercicio 5 con Kruskal, pasó las pruebas. Para este ejercicio agregué el MFSet trabajado en clase.
- Eliminé las funciones de Hash y Eq que estaban en el heap pensadas para la cola de prioridad extendida. Actualizé los ejercicios, volví a correr las pruebas y pasaron.

## 2026-10-22 - Lucía Mottillo
- Finalicé la justificación y autoría.
