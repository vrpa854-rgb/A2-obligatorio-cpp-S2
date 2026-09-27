# Bitácora — Obligatorio 1

**Integrantes:** Venancio Portillo (276560), Lucía Mottillo (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## AAAA-MM-DD — Nombre
- Ejemplo: Leí la letra del ejercicio 1. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.

## 2026-09-06 - Venancio Portillo
-Comencé a crear el TAD Hash Table basado en lo dado en clase.

## 2026-09-14 - Venancio Portillo
-Comencé a crear el TAD AVL basado en lo dado en clase.

## 2026-09-16 - Lucía Mottillo
- Leí la letra del ejercicio 1, empecé a hacer bocetos de como debería de ser. 
  Empecé a programar y dejé planteada una idea que sirve (da el resultado esperado).
  Falta chequear que cumpla con la complejidad.

## 2026-09-23 - Lucía Mottillo
- Agregué el tad del grafo, basado en lo que trabajamos en clase.

## 2026-09-27 - Venancio Portillo
-Agregué el rehash a la tabla de hash. Primero dividí el problema en 4 partes: Creación del nuevo vector, rehashing, limpieza y actualización.
 La creación del nuevo vector empieza por duplicar su capacidad, obtener un nuevo primo superior y generar el nuevo vector con esa base.
 El rehash recorre todo el vector viejo con dos condiciones base: Si no hay nodo, sigo; si está borrado no lo paso y limpio la memoria.
 Luego avanzo en el vector nuevo hasta encontrar un lugar disponible y guardo el nodo. Como utilizo punteros, puedo pasarlos de forma sencilla y clara. Esto lo puedo hacer porque las condiciones anteriores me aseguran que no existirán nodos borrados. A diferencia de el método Insertar que debo verificarlo.
 Al final, elimino el vector viejo para liberar la memoria y actualizo el hash a los valores del nuevo vector.

## 2026-09-27 - Venancio Portillo
-Agregué las rotaciones al TAD AVL.
