# Interpolation
Interpolación mínimos cuadrados

Dividiremos el proceso en varias etapas. La primera es solicitar al usuario que indica qué fichero quiere usar, luego se la lectura del archivo de texto donde se almacenan los datos numéricos y se guardan los datos en dos vectores. El segundo paso es resolver el sistema de ecuaciones, mediante la inversa. Por último, se presenta el polinomio con los coeficientes $b_{i}$.\\

El primer paso es el más sencillo, pues tan solo requiere pedir el nombre del fichero. Mediante una sentencia \textit{if} se impone que si el archivo no existe o se introduce mal el nombre, se ejecute un error y cierre el programa.\\

A continuación se definen los vectores $v_{X}$ y $v_{Y}$ donde se almacenarán los valores de las columnas del fichero. Se definen un par de vectores tipo \textit{double} y con un bucle \textit{while} leerá los datos por filas, de manera que el primer dato de la primera columna se almacenará en el vector $v_{X}$ y el segundo dato de la primera columna en el vector $v_{Y}$, hasta llegar a la última fila. Para añadir cada dato al vector correspondiente se usa el método \textit{.push back}.\\

El siguiente paso es definir los elementos de la matriz. Son operaciones sencillas, se ejecutan bucles for que recorren los vectores definidos antes. Una vez definida la matriz, que se mostrará en pantalla, se procede al cálculo de la matriz inversa. \\

Esta parte es la más larga, se divide en varios pasos. Primero calcular el determinante, luego la matriz adjunta, se transpone dicha matriz y por última se calcula la inversa. Mediante una sentencia \textit{if} se impone que la matriz sea regular, en caso contrario, mediante \textit{else} se lanza un error en el que se expone que la matriz es singular, y el programa termina.\\

Se definen varias variables de tipo \textit{double}. En primer lugar se calcula el determinante de la matriz de coeficientes. Mediante bucles \textit{for} que recorran las filas y columnas, basta con aplicar operaciones elementales de álgebra lineal y se consigue la matriz inversa.\\

Por último, se resuelve el sistema y se obtienen los coeficientes buscados. Se presenta el resultado en forma de polinomio, tal como pide el enunciado
