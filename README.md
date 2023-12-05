# Examen-tema-3
https://github.com/Armenteros05/Examen-tema-3.git
Realizado por Sergio Armenteros Rodríguez

PARTE 1: PREGUNTAS DE SELECCIÓN MÚLTIPLE

- Pregunta 1: ¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?
- Respuesta 1:b) representar cualquier tipo de dato lisp
- Pregunta 2: ¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?
- Respuesta 2:

- Pregunta 3: ¿Qué función cumple el método to_json_string() en la clase Variant?
- Respuesta 3:

- Pregunta 4: ¿Qué función cumple el método from_json_string() en la clase Variant?
- Respuesta 4:



PARTE 2:  Pregunta de desarrollo de código (80%):Sistema de Scripting para Motor de Videojuegos Indie.
Explicación del código:

ESTRUCTURA BÁSICA: He creado una  clase environment, y dentro he creado una tabla de valores usando std::map, donde se introducen parametros x, y, z, que mas adelante nos devuelve esos valores recogidos en la tabla.

INSERTAR SIMBOLOS: He creado una función que permite al usuario indicar cuantos simbolos quiere crear, que permite deicr el nombre del simbolo que quiere crear y el valor del mismo. Todos los simbolos creados se almacenan dentro de una tabla de simbolos.

BUSCAR SIMBOLOS: He creado una tabla de simbolos donde se incluyen solamente los simbolos x o y, y que permite al usuario decidir que valor de esos dos desea buscar, cuando inserta el simbolo deseado, le devuelve el valor del mismo, incluyendo las excepciones donde no pueda ejecutarse bien el código.

GESTIÓN DE ERRORES: En este apartado no he incluido nada, ya que como se puede comprobar, en cada uno de los apartados el código está diseñado para abarcar todas los posibles casos para adaptar los errores y enviar la bandera de error necesaria

INTEGRACIÓN CON VARIANT: He creado una tabla de simbolos donde se recogen 3 parámetros, "x, y, name," incluidos con una clase variant, que a su vez esta recogida e integrada dentro de una tabla de simbolos

EXPANDIENDO FUNCIONALIDADES: En este apartado, he creado una tabla de simbolos donde se crean los parametros "x, y, name", y donde a demás nos indica que la variable x existe, elimina la variable y y verifica que no existe, todo incluido dentro de un entorno. Más adelante imprime el entorno  donde se recogen solo los valores de X y name ya que "y" ha sido eliminado

CASOS DE USO: En este apartado he creado una clase variant donde se incluyen los parametros "salud", "fuerza" y "nombre", lo que refleja como un desarrollador de videojuegos podría usar variant para crear un personaje por ejemplo.

REFLEXIÓN Y MEJORAS: Aquí simplemente he dado mi opinión acerca de como en el futuro el desarrollo de maquinas mas potentes podrían ayudar a la mejora y analisis de datos haciendo mención a las tablas de simbolos y a la implementación de funciones avanzadas. 

