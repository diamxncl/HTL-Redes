/*
    - Incluir una utilidad donde hayan punteros y funciones.
    - Cualquier utilidad relacionada con el ciclo. 
    - Importante comentar el código.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

using namespace std;

//! FUNCIÓN QUE EN BASE AL TEMA QUE LE DES, HARÁ UNAS PREGUNTAS U OTRAS.

void preguntas (int preguntas, int orden[], string tema[][2], string resp[12]) {

    //! DECLARACIÓN DE VARIABLES PARA LLEVAR A CABO EL USO DE LA FUNCIÓN
    char res; // Variable donde guardaremos la respuesta del usuario.
    int nota; // Variable donde guardaremos la nota que de el usuario para cada pregunta resuelta.

    for (int i = 0; i < preguntas; i++) { // Bucle general que realizará las preguntas.
        system("clear"); // Limpiamos la consola
        system("cat banner.txt"); // Sacamos por pantalla el banner

        cout << "\n\nPregunta " << i + 1 << endl << endl;
        cout << tema[orden[i]][0] << endl << endl; // Sacamos por pantalla la pregunta que toque, su orden será definido por el orden que hayamos definido dentro de la variable algoritmo.
        cout << "¿Desea conocer la respuesta? (s/n)\n> "; // Preguntamos al usuario si desea conocer la respuesta de la pregunta.
        cin >> res; // Recogemos su respuesta.
        
        system("clear"); // Limpiamos la consola
        system("cat banner.txt"); // Sacamos por pantalla el banner
        if (res == 'S' or res == 's') // Si la respuesta es S o s, entendemos que quiere ver la respuesta.
            cout << "\n\nRespuesta: " << endl << endl << tema[orden[i]][1]; // Mostramos la respuesta que se encuentra en la misma matriz pero en la segunda columna.
        
        cout << "\n\nCalifícate del 0 al 10\n> "; // El usuario se da una nota, si esta es superior a 7, se dará como sabida la pregunta, si por el contrario es menor que 7, la respuesta será guardada dentro de otra matriz para luego mostrar por pantalla estas preguntas que aún no están claras.
        cin >> nota;
        if (nota < 7)
            resp[i] = tema[orden[i]][0];

    }
}

//! Función que sacará preguntas aleatorias por pantalla y devolverá la nota de la misma.

int modo_examen (string tema[][2], int prob) { 

    int nal, nota; // Declaración de variables

    sleep(0.5); // Dejamos un poco de tiempo para que el número que vaya a generar varíe
    nal = rand() % prob; // Generamos un número aleatorio según la cantidad de preguntas que tenga cada tema.
    cout << endl << tema[nal][0] << endl; // Sacamos por pantalla la pregunta.
    cout << "\nCalifícate del 0 al 10\n> ";
    cin >> nota;

    return nota; // Devolvemos la nota para despues poder sacar la media.
}

int main () {
    system("clear"); // Limpiamos la consola
    srand(time(NULL)); // Configuramos la semilla de rand (esto nos ayuda a generar números aleatorios) en base al tiempo de nuestro sistema, para ello hemos incluido la libreria <time.h>

    //! Declaración de variables del programa general

    // Declaramos los array para cada tema junto con su contenido ej: Tema1[PREGUNTA][RESPUESTA].
    string 
    T1[12][2] =
    {
        {"1.- Diferencia en los roles del host entre cliente/servidor y entre pares.", "La diferencia principal es que en una red entre pares todos reciben los recursos por igual y en una cliente/servidor los recursos son distribuidos según la necesidad del dispositivo o según como lo hayamos configurado."},
        {"2.- Funciones de dispositivos intermedios.", "Regenerar y retransmitir señales de comunicación \nConservar información acerca de las rutas existentes en la red \nSe encarga de redirigir el tráfico cuando existe una falla en algún dispositivo en la red \nClasifica los mensajes de acuerdo a las prioridades de los mismos \nPermitir o denegar el flujo de datos de acuerdo a los parámetros de seguridad previamente indicados."},
        {"3.- Criterios a considerar a la hora de elegir un medio.", "1. ¿Cuánta es la distancia que el medio ha de recorrer?\n2. ¿En qué entorno serán instalados los medios?\n3. ¿Cuál es la cantidad de datos y a qué velocidad necesitamos transmitirla?\n4. ¿Cuál es el costo del medio y su instalación?"},
        {"4.- Diferencia entre topología física y lógica, poniendo algún ejemplo real.", "La diferencia entre una topología física y una lógica, es que, en la física conocemos donde están los dispositivos situados geográficamente, en cambio, en la lógica solamente conocemos las direcciones lógicas (IP).  Por ejemplo: Topología física de un colegio. Podemos ubicar geográficamente la ubicación de un aula en concreto por lo que identificaríamos que la serie de dispositivos que nos indican están dentro de ese aula. \nSi no supiéramos donde están situados geográficamente los dispositivos la topología sería lógica y quedaría algo así (Conocemos las IPs y los dispositivos pero no donde están situados físicamente.):"},
        {"5.- ¿Por qué puede ser diferente una red Home y una SOHO?", "Básicamente la diferencia es que no se comparten los mismos Recursos en la red. En una red doméstica podemos compartir, internet, una impresora…, en cambio, en una red SOHO podemos compartir también recursos compartidos centralizados, conexión al servidor de la empresa…."},
        {"6.- Intranet y extranet; explicación y ejemplos de cada una.", "Intranet: Es un término utilizado para referirse a una red que utiliza una infraestructura privada de LAN que pertenecen a una organización.\nExtranet: Hace referencia a la conexión entre dos o más redes por medio de la infraestructura pública. En la imagen está marcado como el camino que sigue para llegar de una infraestructura a otra. Esta es de color azul oscuro."},
        {"7.- Dentro de las conexiones a internet, explica la diferencia entre Cable modem y DSL. Líneas arrendadas y metro ethernet.", "·Cable modem y DSL:\nLa diferencia principal es el medio de transmisión, en cable modem la señal de datos se transmite por el mismo cable que ofrece la televisión por cable, en cambio, DSL se transporta por la línea telefónica. Otra diferencia es que DSL es una suscripción y en cable modem pagas cuando uses internet.\n Líneas arrendadas y Metro Ethernet.\nLa diferencia principalmente es la velocidad y prioridad que ofrece cada uno, metro ethernet, digamos que es parecido a como nos llega la fibra a casa, pero esta va por un camino menos transitado por lo que es algo más rápida, en cambio, una línea arrendada dedicada es una línea que se contrata a una empresa de telefonía, esta es enviada directa y exclusivamente para nuestra red, por lo que esta es mucho más rápida." },
        {"8.- Características para redes confiables, explicando brevemente cada una de ellas.", "Tolerancia a fallas:\n Una red redundante, esto indica que si la información tiene que pasar por una ruta, pero esta da problemas, la red deberá tener más de un camino por donde llevar la información. Escalabilidad:\n Tiene que ofrecer la posibilidad de que la red crezca, para ello hay que seguir los estándares y protocolos aceptados. Calidad de servicio (QoS):\n Esta indica la cantidad de ancho de banda que será asignado a cada dispositivo, de esto se encarga el rúter, aunque nosotros también podemos gestionarlo. Seguridad de la red:\n Se necesitan 3 requisitos.  Confidencialidad: Acceso restringido a usuarios no deseados. Integridad: Tener la seguridad de que los datos no se alterarán en su transmisión. Disponibilidad: Este hace referencia a poder acceder a los datos siempre que sea necesario de la manera más confiable y segura posible."},
        {"9.- Tipos de nubes con algún ejemplo de cada una.", "Nubes públicas: Amazon Web Services\nNubes privadas: Un CPD privado que utilizo para mi empresa.\nNubes híbridas: Azure, y un CPD empresarial.\nNubes comunitarias: HIPAA."},
        {"10.- Define los siguientes conceptos; PLC y WISP.", "PLC:\n Este es un dispositivo que a través de tu red eléctrica lleva tu conexión de internet, son necesarios 2, uno que introduzca la red y otro que la reciba. Estos cuentan con un puerto RJ45 que son conectados desde el rúter hasta el PLC y otro desde el PLC hasta el dispositivo que queramos conectar, otros también reparten red WI-FI.\nWISP:\n Es una antena que se suele colocar en una estructura alta previamente construida que ofrece una conexión a internet en zonas donde no llegan los cables de conexión. Para que un cliente pueda conectarse necesita colocar una antena en la parte superior de su casa, esta se conecta con el WISP y es como si la conectáramos por cable. La configuración no es muy diferente a la habitual DSL. La diferencia principal es que en lugar de conectarse por cable lo hace inalámbricamente."},
        {"11.- Explicar, al menos 4 amenazas de seguridad para las redes.", "Spyware y adware: Estos recompilan información sobre el usuario tras ser instalados. \nRobo de identidad: Roba las credenciales de inicio de sesión de un usuario para acceder a sus datos privados \nVirus, gusanos y caballos de troya: Contienen software malicioso que se ejecuta en dispositivo de usuario. \nZero Day: Se producen el primer día que se conoce la vulnerabilidad"},
        {"12.- Tipo de soluciones para mitigar amenazas en redes grandes.", "Sistemas de firewall dedicados - Estos pueden filtrar grandes cantidades de tráfico con más granularidad.\nListas de control de acceso (ACL) - Estos filtran aún más el acceso y el reenvío de tráfico en función de las direcciones IP y las aplicaciones.\nSistemas de prevención de intrusiones (IPS) - Estos identifican amenazas de rápida propagación, como ataques de día cero o de hora cero.\nRedes Privadas Virtuales (VPN) - Estos proporcionan acceso seguro a una organización para trabajadores remotos."}
    },
    T3[8][2] = 
    {
        {"1.- ¿Por qué es importante la Gateway en un envío dentro de la trama?","Es importante para poder llegar el dispositivo de destino, nuestro paquete necesita saber la dirección MAC del router (gateway) para que él se encargue de enviar el paquete al dispositivo que se encuentra en otra red."},
        {"2.- Protocolos DNS y DHCP . Significado de siglas, explicación breve y capa de nivel TCP/IP.","DNS: Domain name system, Sistema de nombres de dominio. \nEste es utilizado para realizar una traducción de nombre a dirección IP. Capa Aplicación\nDHCP: Dynamic host configuration protocol, Protocolo de configuración dinámica de hosts.\nEste se encarga de asignar direcciones IP a los dispositivos dinámicamente, permitiendonos ademas configurarlo dependiendo de la necesidad de la red. Capa Aplicación"},
        {"3.- IANNA e ICANN.","ICANN. Esta coordina la asignación de direcciones IP que es realizada por la IANNA, además de la administración de nombres de dominio y otro tipo de información utilizada por los protocolos TCP/IP\n IANNA. Esta es encargada de supervisar y administrar la asignación de direcciones IP global, la administración de nombres de dominio y los identificadores de protocolo para ICANN."},
        {"4.- Segmentación del mensaje en el encapsulado.","La segmentación del mensaje es un proceso que divide el paquete que queramos enviar/recibir en trocitos para transmisiones a través de la red. Esta es necesaria para que podamos usar varios recursos en red a la vez. Digamos que sería como enviar las partes de un coche en diferentes camiones pero todos llegarán al mismo destino, aun así no importa el camino que cojan para llegar pero deberán llegar. \nEste tiene dos beneficios principales.\n- Aumenta la velocidad. Gracias a que los datos se segmentan en paquetes, podemos enviar grandes cantidades de datos por la red sin hacer que colapse. Esto es la llamada multiplexación.\n	- Aumenta la eficiencia. Imagina que un solo trocito no consigue llegar a su destino, sería tan fácil como volver a pedir ese trocito de paquete de nuevo."},
        {"5.- Protocolos SSH y SSL; Significado de siglas, explicación breve y capa de nivel TCP/IP.","SSH: Secure shell. Intérprete de ordenes seguro.\nSu principal función es el acceso remoto a un servidor por medio de un canal seguro en el que toda la información está cifrada. Capa de Aplicación.\n\nSSL: Secure sockets layer. Capa de sockets seguros.\nEs un protocolo para navegadores y servidores web que permite autenticar, cifrar y descifrar la información enviada a través de Internet. Capa de Transporte. "},
        {"6.- Direccionamiento físico y lógico en el encapsulado.","Direccionamiento Físico:\nEsta se suele dar cuando los dispositivos que se comunican estan en la misma red, la trama de enlace de datos se envía directamente al dispositivo receptor. Estas direcciones de enlace de datos son conocidas como MAC. Estas son inamovibles. (Ej: 01-a2-12-42-2d-21)\nMAC Origen\nMAC Destino\n\nDireccionamiento Lógico:\nUna dirección lógica de capa 3, es utilizada para enviar el paquete IP desde el origen hasta el destino. Estos contienen 2 direcciones, IP origen y la IP destino y 2 partes, parte de host y la parte de red."},
        {"7.- Sincronización del mensaje.","El tiempo entre mensajes es muy importante en las comunicaciones de red. Por eso para identificar que el tiempo de respuesta es lento, el tiempo de los mensajes incluye esto:\n- Control de flujo. Este es el proceso encargado de gestionar la velocidad de transmisión de datos. Ej: si una persona habla demasiado rápido, la otra persona tendrá dificultades para escuchar y comprender el mensaje.\n- Tiempo de espera de respuesta. Este es el proceso encargado de determinar cuánto tiempo debe haber entre el mensaje y su respuesta. Los hosts de las redes tienen reglas que especifican cuánto tiempo deben esperar una respuesta y qué deben hacer si se agota el tiempo de espera para la respuesta.\n- Método de acceso. Este determina en qué momento alguien puede enviar un mensaje. Ej. Cuando dos personas hablan a la vez tienen que parar y volver a enviar el mensaje para no colapsarse."},
        {"8.- Protocolos NAT y BGP; Significado de siglas, explicación breve y capa de nivel TCP/IP.","Protocolo NAT (Network address translation. Traducción de direcciones en red): Es el encargado de realizar la traducción de IPs privadas a IPs públicas. Capa de Internet.\nProtocolo BGP (Border Gateway Protocol. Protocolo de puertas de enlace de frontera): Es un protocolo que define políticas de enrutamiento, para estabilizar las conexiones entre dispositivos frontera. Capa de Internet."}
    },

    T4[12][2] =
{
        {"1.- Limitaciones de la tecnología inalámbrica.","\nÁrea de cobertura. Dependiendo de los materiales del alrededor la zona en la que se reparte la red inalámbrica puede verse limitada.\n\nInterferencias. Esta puede verse afectada por dispositivos que solemos utilizar a diario como puede ser, teléfonos inalámbricos de casa, algunas luces fluorescentes, microondas...\n\nSeguridad. Al no ser una red que se transmite por un medio físico, esta puede ser capturada por dispositivos no autorizados y poder acceder a ella sin autorización.\n\nMedio compartido. Como la red inalámbrica opera en medio duplex, lo que significa que solo un dispositivo puede enviar y recibir a la vez, el ancho de banda de los dispositivos conectados se ve ciertamente reducido."},
        {"2.- Señalización y codificación.","\nSeñalización. La señalización es un proceso que se encarga de definir qué tipo de señal puede representar un 1 o un 0. Ya puede ser un cambio de nivel en la señal o un pulso óptico.\n\nCodificación. Es el proceso que se encarga de convertir los datos en un código predefinido, nosotros lo solemos ver como el proceso que se encarga de convertir la trama en bits."},
        {"3.- Estándares T568A y T568B.","\nDependiendo del cable que queramos hacer necesitaremos crimpar el cable utilizando un estándar u otro.\nCable recto. Ambos extremos deben ser iguales.\nCable cruzado. Ambos extremos han de ser diferentes."},
        {"4.- Interferencias en un cable de cobre.","\nInterferencia electromagnética (EMI) o interferencia de radiofrecuencia (RFI). Estas pueden distorsionar y dañar las señales de datos que transportan los medios de cobre.\nCrosstalk. Se trata de una perturbación causada por los campos eléctricos o magnéticos de una señal de un hilo a la señal de un hilo adyacente."},
        {"5.- Diferencias entre monomodo y multimodo.","\nLa diferencia más destacable es la cantidad de dispersión. Esta se refiere a la pérdida de intensidad de los pulsos de luz con el tiempo. El aumento de la dispersión es igual a una mayor pérdida de la intensidad de la señal. La fibra multimodo tiene una mayor dispersión que la monomodo.\nDiferencias físicas. El núcleo de la monomodo es muy pequeño y utiliza tecnología láser.\nEl núcleo de la multimodo es más grande y utiliza luces LED para enviar los pulsos."},
        {"6.- ¿Qué son los números de vueltas en cada par de hilos en los cables UTP?","\nSon vueltas que se le dan al par de hilos para evitar o reducir el efecto crosstalk, para mejorar este los diseñadores cambian el número de vueltas en cada par de hilos."},
        {"7.- ¿Cómo influye la latencia en el rendimiento y cómo influye los acuses de recibo en la capacidad de transferencia útil?","\nEl rendimiento no puede ser más rápido que el enlace que sea más lento en la red, esto quiere decir que el dispositivo cuyo enlace sea más lento influirá completamente en el rendimiento.\n\nLos acuses de recibo añaden más paquetes en el tráfico de red al principio y al fin de un envío de mensaje, por culpa de esto la capacidad de transferencia útil puede verse reducida, ya que al fin y al cabo son más tramas en la red."},
        {"8.- ¿Qué hace la capa física?","\nEs la encargada de codificar en señales los dígitos binarios que representan las tramas de la capa de enlace de datos."},
        {"9.- STP y RJ45.","\nSTP. El cable STP combina las técnicas de blindaje para contrarrestar la EMI y la RFI, y el trenzado de hilos para contrarrestar el crosstalk. Para obtener los máximos beneficios del blindaje, los cables STP se terminan con conectores de datos STP blindados especiales. Si el cable no se conecta a tierra correctamente, el blindaje puede actuar como antena y captar señales no deseadas.\nRJ45. Es el conector que se utiliza para terminar los cables UTP y STP, a él se le 'crimpan' los 8 pines que están dentro de los cables."},
        {"10.- Zigbee y 802.15.","\nZigbee. Medio inalámbrico utilizado para comunicaciones de baja velocidad y baja potencia. Diseñado para aplicaciones que requieren de un corto alcance, baja velocidad de datos y larga duración de la batería. Utilizado normalmente en entornos industriales.\n\n802.15. Medio inalámbrico conocido como 'Bluetooth', es un estándar de red de área personal inalámbrica (WPAN). Utiliza un proceso de emparejamiento entre dispositivos para distancias entre 1 y 100 metros."},
        {"11.- ¿Para qué se utiliza el cable coaxial?","\nSe utiliza para instalaciones inalámbricas en las que estos conectan antenas a los dispositivos inalámbricos y transportan energía de radiofrecuencia entre ellas.\nTambién son usadas en instalaciones de internet por cable en las que se proporciona conectividad a internet a sus clientes mediante el reemplazo de porciones del cable coaxial y la admisión de elementos de amplificación con cables de fibra óptica. Sin embargo, el cableado en las instalaciones del cliente sigue siendo cable coaxial."},
        {"12.- Categorías en el cable UTP.","\nLos cables de categorías superiores se diseñan y fabrican para admitir velocidades superiores de transmisión de datos.\nCat 3. Se utilizó para la comunicación de voz, más tarde también a la transmisión de datos.\nCat 5 y 5e. Son utilizadas para la transmisión de datos, esta soporta 100Mbps y la categoría 5e 1000Mbps.\nCat 6. Esta cuenta con un separador añadido entre cada par de cables para soportar velocidades más altas, soporta hasta 10 Gbps.\nCat 7. También soporta 10 Gbps.\nCat 8. Soporta hasta 40 Gbps."}
    },
    T6[7][2] = 
    {
        {"1.- ¿Qué topología WAN brinda la más alta disponibilidad y por qué? ¿Qué topología WAN tiene una topología lógica y otra física? Razona tu respuesta.","\n\nDesde mi punto de vista la topología con más alta disponibilidad es la topología de malla, ya que esta permite seguir teniendo una conexión con cualquier dispositivo conectado a pesar de que alguna de las conexiones sea interrumpida.\n\n\nTopología Punto a Punto, esta tiene una topología física y una lógica realmente, aunque en la imagen solo podemos apreciar la topología lógica en la que vemos como están conectados, también podríamos ver la topología física de esta siempre que sepamos donde están conectados los dispositivos geográficamente además de poder conocer cómo ese dispositivo se identifica en la red. A todo esto también podemos añadir en una representación gráfica de la red, todos los dispositivos que hay entre las topologías WAN punto a punto que pueden haber en la topología que estamos representando, lo que se conoce como nube o Internet.\n\n(Ejemplo: Topología lógica de punto a punto)",},
        {"2.- Topologías de contención y deterministas. Cita ejemplos.","\n\nTopología de detección de portadora:\n\nEn este tipo de topologías los dispositivos operan en semidúplex, es decir, en una red con 3 dispositivos, si 2 de ellos quieren enviar un mensaje a la vez al 3º, los paquetes deben ser enviados uno tras otro, ya que solo un dispositivo puede enviar a la vez. Si dos dispositivos emiten un mensaje a la vez se produce una colisión. Para que los dispositivos empiecen a enviar paquetes necesitan detectar corriente.\n\nEjemplos:\nTopología de bus heredada.\n\n\nTopología de pase de testigo:\n\nEn este tipo de topología cada dispositivo (nodo) tiene su propio tiempo para usar el medio, este tipo de topologías no son eficientes, ya que cuando un dispositivo tiene el testigo el resto tiene que esperar. Este testigo es completamente aleatorio y tiene un tiempo determinado.\n\nEjemplos:\nAnillo de TokenLegacy",},
        {"3.- Subcapas de 'Enlace de Datos'.","\n\nSubcapa LLC (Control de enlace lógico):\nEsta subcapa se encarga de comunicarse con la capa de red, para agregar información de control de capa 2 para ayudar a que su entrega sea más eficaz.\nEn esta se usa el estándar LLC-IEEE 802.2.\n\nSubcapa MAC (Control de acceso al medio):\nEs responsable de la encapsulación de datos y el control de acceso a los medios. Proporciona direccionamiento de capa de enlace de datos y está integrado con varias tecnologías de capa física:\n\n\t- Delimitación de tramas: Proceso de entramado encargado de indicar cuántos grupos de bits componen la trama, para ayudar a la sincronización entre el dispositivo emisor y el receptor.\n\t- Direccionamiento: Este proporciona direcciones de origen y destino físico entre dispositivos del mismo medio compartido.\n\t- Detección de errores: Cada trama tiene un tráiler utilizada para detectar errores de transmisión.\n\nEsta incluye estándares para varias tecnologías.\nEthernet (IEEE 802.3)\n\t- Varios estándares para Fast Ethernet, Gigabit Ethernet...\nWLAN (IEEE 802.11)\n\t- Varios estándares WLAN para comunicaciones inalámbricas.\nWPAN (IEEE 802.15)\n\t- Varios estándares para Bluetooth, RFID...\nExisten más de estos...",},
        {"4.- Influencia del direccionamiento de capa 2 y capa 3 en el encapsulamiento de una trama a través de cambios de redes.","\n\nSabiendo que el direccionamiento de capa 2 guarda NIC de destino y NIC de origen y el direccionamiento de capa 3 guarda IP de origen e IP de destino,\n\nLa influencia de estas en el encapsulamiento es que, cuando un dispositivo de capa 3 (ISR) lee la trama, es capaz de detectar que esta es para un dispositivo que se encuentra en otra red gracias a el direccionamiento lógico de capa 3. Él es el encargado de crear una nueva trama y en esa nueva trama el direccionamiento de capa 3 no es modificado mientras que el de capa 2 si, ya que la trama ahora es para un dispositivo que no se encuentra en la misma red que la que fue enviada, y el direccionamiento de capa 2 funciona solo en dispositivos que estén dentro de la misma red.",},
        {"5.- ¿Cómo usa un router la capa de enlace de datos.","\n\nConsta de 4 pasos.\n\n1 - El ISR acepta la trama enviada por un dispositivo de su misma red.\n2 - Este desencapsula la trama y lee el paquete, en este puede observar el direccionamiento de capa 3, que es donde tiene que enviar la siguiente trama.\n3 - Este vuelve a encapsular el paquete con una trama diferente pero que ahora a cambiado su direccionamiento físico capa 2.\n4 - Este se encarga de cambiar de 'boquete' o interfaz la trama y la reenvía al dispositivo correspondiente.",},
        {"6.- Ethernet liderando los protocolos de capa 2 entre los antiguos protocolos LAN y WAN.","\n\nLos protocolos Ethernet son utilizados en LAN cableadas.\n\nLas comunicaciones inalámbricas usan protocolos WLAN mencionados anteriormente IEEE 802.11.\n\nTradicionalmente, las topologías WAN utilizaban los protocolos para tipos de topologías Punto a punto, hub & spoke y de malla completa.\nAlgunos de los más comunes son:\n\t- Protocolo punto a punto (PPP).\n\t- Control de enlace de datos de alto nivel (HDLC, High-Level Data Link Control).\n\t- Frame Relay.\n\t- Modo de transferencia asíncrona (ATM).\n\t- X.25.\n\nEstos están siendo reemplazados en la WAN por Ethernet.\n\nEn una red TCP/IP el protocolo de capa 2 puede variar dependiendo de la topología lógica y los medios físicos.\n\nEl protocolo de capa 2 que se utiliza para una topología en particular está determinado por la tecnología a usar, y esta tecnología es determinada por el tamaño de la red.\n\nEl protocolo Ethernet que se usa en redes LAN generalmente usa tecnologías de alto ancho de banda capaz de soportar grandes cantidades de hosts. Sin embargo, utilizar una tecnología de ancho de banda alto no es rentable, en la mayoría de los casos, en redes de área extensa que cubren grandes áreas geográficas. El costo de los enlaces físicos de larga distancia y su tecnología a través de largas distancias ocasiona una menor capacidad de ancho de banda.",},
        {"7.- CSMA/CD y CSMA/C.","\n\nCSMA (Acceso múltiple por detección de portadora): Varios dispositivos conectados entre sí por un medio físico (Cable o Inalámbrico), que quieren compartir datos. Se pueden encontrar con que existan colisiones en estos medios físicos, cada uno tiene su método para detectarlas (CSMA/CD) o evitarlas (CSMA/CA).\n\nCSMA/CD - Redes alámbricas\n\t- Si un envío colisiona en estas, los dispositivos lo detectarán, y deberán 'tirar un dado aleatorio' que les dirá el tiempo y quién tiene que enviar de nuevo los datos.\n\n¿Cómo funciona?\nPC1 necesita enviar una trama a PC3, este necesita saber si hay otro dispositivo usando la red, si no detecta un proveedor de señal, este enviará la trama.\n\nEl HUB recibe y envía la trama a todos los dispositivos de la red, ya que al ser un dispositivo de capa 1 su funcionamiento es reenviar los bits recibidos a todos los dispositivos conectados.\n\nTodos los dispositivos reciben la trama, pero como está tiene un direccionamiento físico que le indica qué dispositivo tiene que recibirla, PC2 la ignora ya que detecta que la trama no es para él, y PC3 la abre.\n\nCSMA/CA - Redes inalámbricas\n\nCSMA/CA utiliza un método similar a CSMA/CD para detectar si el medio está libre. En entornos inalámbricos, es posible que un dispositivo no detecte una colisión, pero sí intenta evitarlas, esto lo hacen ya que cada dispositivo que transmite incluye una duración que necesita para su transmisión. Todos los dispositivos inalámbricos conectados reciben esta información y saben cuándo estará o no disponible de nuevo.\n\nCuando un dispositivo envía una trama 802.11, el receptor devuelve un acuse de recibo, que es un mensaje que indica si la trama ha sido recibida correctamente.",}
    },
    T7[7][2] = 
    {
        {"1.- Si conectamos dos switch nuevos entre si con un cable. ¿Qué podría pasar en cuanto a la velocidad (ancho de banda) y la capacidad de trasmitir y recibir?.","\n\nDando a entender que son 2 switchs que cuentan con la misma tecnología en todas sus interfaces \"boquetes\", pues en principio la velocidad de ancho de banda sería la que definiera el switch 100 Mbps o 1000 Mbps, en cambio, si uno de ellos es 100 Mbps y el otro es 1000 Mbps toda la red se vería utilizando la velocidad más baja, es decir, 100 Mbps (Medio compartido). A parte de esto, las primeras peticiones tardarían en llegar a sus respectivos lugares ya que la tabla CAM aún no estaría diseñada.\n\nEn cuanto al tipo de cable, ¿debería de ser cruzado o recto?. Razona todas tus respuestas.\n\nEl cable debería de ser cruzado ya que, si por algún casual alguien quiere entrar en la red, haciendo lo que se conoce como un \"man in the middle\", es decir, hacerse pasar por un switch, siendo un ordenador y así robando todos los datos que viajan en la red. Si su conexión es por cable cruzado, sería imposible que un ordenador pudiese conectarse con ese switch. Es por ello también importante que si la conexión es realizada con un cable cruzado, y siempre será así, que esto sea configurado en el switch en el apartado (MDIX) si es que este cuenta con él.",},
        {"2.- Fragmentos de colisión y \"jumbos\".","\n\nFragmentos de colisión:\nUn fragmento de colisión es cualquier trama de menos de 64 bytes de longitud, esta es descartada automáticamente por el switch o el dispositivo que las recibe. Para resolver estos existen switches que tienen una tecnología conocida como \"Switching libre de fragmentos\", en esta, el switch almacena solamente los primeros 64 bytes de la trama antes de reenviarla, intentando realizar una pequeña comprobación de errores, ya que la mayoría de los errores en las tramas se concentran en estos primeros bytes.\n\nJumbos:\nUn jumbo es una trama cuyo paquete supera los 1500 Bytes. Esto ocurre cuando un ordenador está generando \"basura\" en la red, por ejemplo, si hay un pelo en el cable o algo que haga que vibre, puede enviar datos sin quererlo y esto genera una trama Jumbo o bebé gigante.",},
        {"3.- Ventaja de utilizar el método de corte para el reenvío de tramas. ¿Qué importancia tiene en este método el número 64 en los bytes de retransmisión?.","\n\nEl funcionamiento de este método consiste en almacenar los primeros 14 bytes de la trama que contiene el preámbulo y SFD, y la MAC de destino, y reenviarlo.\n\nConociendo esto, podemos deducir que su mayor ventaja es la velocidad con la que puede reenviar la trama y así acelerar la velocidad de transmisión. Pero esto también puede ser una desventaja, ya que si la trama es un \"Jumbo\" o un \"Fragmento de colisión\", esta trama será descartada, lo que provoca tráfico innecesario en la red.\n\nDe este método existen dos variantes:\n- Switching de reenvío rápido: Este reenvía la trama inmediatamente tras leer la dirección de destino.\n- Switching libre de fragmentos: En este, el switch almacena los primeros 64 bytes de la trama antes de reenviarla, intentando realizar una pequeña comprobación de errores, ya que la mayoría de los errores en las tramas se concentran en estos primeros bytes.",},
        {"4.- Campo Tipo y FCS de una trama.","\n\nCampo Tipo:\nEl campo Tipo, también conocido como Ethertype, Type o Length, es un campo de 2 bytes que identifica el protocolo de capa superior encapsulado en la trama Ethernet. Representa sus valores en hexadecimal. Algunos de ellos son:\n0x800: IPv4\n0x86DD: IPv6\n0x806: ARP\n\nCampo FCS:\nFCS, o Secuencia de verificación de trama, es un campo de 4 bytes que se utiliza para detectar errores que pueda contener una trama. Esta comprobación se conoce como CRC. Se realizan cálculos matemáticos para comprobar que la trama se encuentra igual que como fue enviada, por lo que si existe alguna modificación, esta será descartada.",},
        {"5.- Búfer de memoria en el almacenamiento de tramas en un switch. Tipos de memoria.","\n\nUn switch Ethernet puede almacenar tramas antes de enviarlas. Por ejemplo, en el caso de que haya congestión en la red, este almacenaría la trama hasta que la interfaz esté libre para reenviarla.\n\nExisten dos métodos:\n- Memoria basada en interfaz:\n  - Las tramas se almacenan en colas que se enlazan a interfaces específicas de entrada/salida.\n  - La trama solo se transmite cuando el resto de las tramas en la cola hayan sido transmitidas.\n  - Es posible que una sola trama retrase toda la cola si la interfaz está ocupada, y esto es inevitable.\n- Memoria compartida:\n  - La cantidad de memoria por cada interfaz se comparte dinámicamente, lo que significa que si un dispositivo requiere más recursos en la red, por ejemplo, un servidor, se le asignará más memoria a su interfaz que a un dispositivo que no requiera tanto.\n  - Las tramas que están en el búfer se enlazan dinámicamente al puerto de destino, lo que permite recibir un paquete en un puerto y luego transmitirlo en otro puerto sin moverlo a una cola diferente.",},
        {"6.- ¿Cómo funciona un switch?.","\n\nUn switch es un dispositivo de capa 2 que es capaz de leer la trama y reenviarla en la red. A este proceso se le llama conmutar, por lo que el switch también es conocido como \"conmutador\". Este switch tiene una tabla CAM que va generando conforme los dispositivos conectados a él envían tramas. Al principio, está vacía, pero a medida que entran tramas, se va llenando con las direcciones MAC y las interfaces correspondientes.\n\nCuando el switch no conoce la dirección MAC de destino, envía la trama a todas las interfaces conectadas. Si el paquete llega a su destino, el switch aprenderá la ubicación de ese dispositivo en la tabla CAM.\n\nEl switch puede descartar tramas dependiendo del tipo de switch y su método para reenviar tramas.",},
        {"7.- Direcciones MAC: unicast, broadcast y multicast. Identificador Único de Organización (OUI).","\n\nUnicast: Es una conexión de un dispositivo a otro dispositivo, y esta no puede ser vista por otros dispositivos que no sean el de destino.\nEjemplo:\nMAC de destino: 3F:2D:21\nMAC de origen: 04:2D:1C\n\nBroadcast: Es una dirección a la que el dispositivo se refiere para realizar una comunicación a todos los dispositivos en la misma red. Se identifica fácilmente porque todos los caracteres son F.\nEjemplo:\nMAC: FF:FF:FF\n\nMulticast: Esta dirección se utiliza cuando se desea que los datos lleguen a un grupo específico de usuarios. Las direcciones multicast se definen porque los primeros 3 bytes de la dirección MAC son idénticos.\nEjemplo:\nMAC de destino: 01:00:5E:12:01:A1\nMAC de origen: 01:AB:2E\n\nEl OUI (Identificador Único de Organización) es un identificador presente en todas las direcciones MAC. Se encuentra en los primeros 3 bytes de la dirección MAC y se utiliza para identificar al fabricante de la tarjeta de red o dispositivo.",}
    };

    string res_pregunta[12]; // Matriz donde almacenaremos las preguntas que hayan sido respondidas con menos de un 7.

    int opt[5], nal, nota, suma = 0;

    // A continuación declaramos los ordenes que serán matrices dinámicas que llevaremos a cabo con nuestro programa para que las respuestas no sean siempre las mismas, aunque solo hay 2 "algoritmos" es suficiente para repasar.
    int* orden_1 = new int[12]{4, 6, 2, 1, 9, 0, 7, 8, 11, 3, 5, 10};
    int* orden_2 = new int[12]{10, 5, 2, 0, 1, 3, 11, 9, 4, 6, 8, 7};
    int* orden_3 = new int[8]{1, 7, 2, 4, 3, 6, 5, 0};
    int* orden_4 = new int[8]{4, 7, 1, 2, 6, 0, 5, 3};
    int* orden_5 = new int[7]{6, 3, 0, 1, 2, 4, 5};
    int* orden_6 = new int[7]{7, 5, 2, 0, 1, 3, 4};

    system("cat banner.txt"); // Sacamos por pantalla el banner de bienvenida y damos las opciones posibles en el menú.
    cout << "\n\nBienvenido a How To Learn de la asingatura de Planificación y administración de redes.\n\n";
    cout << "How to learn es un programa creado para reforzar el aprendizaje de los conocimientos que querramos tener, lo hace en base a preguntas y respuestas, y gracias al modo examen podemos también hacer un simulacro de lo que podría ser una prueba de conocimientos real." << endl << endl;
    cout << "¿Qué desea hacer?\n";
    cout << "\n1. Estudiar\n2. Examen\n\n3. Salir\n\n> ";

    cin >> opt[0]; // Recogemos la opción del usuario, es un array para que podamos recoger más de una respuesta en el transcurso del programa.

    switch (opt[0]) { // Abrimos un switch para poder controlar mejor el flujo del programa separando por la opción dada por el usuario
        case 1: //! Modo Estudio
            system("clear");
            system("cat banner.txt");
            cout << "\n\nElija un tema \n"; // Damos la opción al usuario de poder elegir el tema que desea estudiar.
            cout << "\n1. Tema 1: Las redes en la actualidad.\n2. Tema 3: Protocolos y modelos\n3. Tema 4: Capa física\n4. Tema 6: Capa de enlace de datos\n5. Tema 7: Switching\n\n> ";
            
            cin >> opt[1]; // Recogemos su respuesta.
            switch (opt[1]) { // Abrimos otro switch para comenzar a hacer preguntas dependiendo del tema elegido.
                case 1: // Tema 1

                    system("clear");
                    cout << "Tema 1\n";
                    nal = rand() % 2; // Generamos un número aleatorio para definir que "algoritmo" usaremos para ordenar la pregunta.

                    if (nal == 0) 
                        preguntas (12, orden_1, T1, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    else 
                        preguntas (12, orden_2, T1, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    break;

                case 2: // Tema 3
                    system("clear");
                    cout << "Tema 3\n";
                    nal = rand() % 2; // Generamos un número aleatorio para definir que "algoritmo" usaremos para ordenar la pregunta.

                    if (nal == 0) 
                        preguntas (8, orden_3, T3, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    else 
                        preguntas (8, orden_4, T3, res_pregunta); // Argumentos: nº Preguntas, orden a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    break;

                case 3: // Tema 4
                    system("clear");
                    cout << "Tema 4\n";
                    nal = rand() % 2; // Generamos un número aleatorio para definir que "algoritmo" usaremos para ordenar la pregunta.
                    
                    if (nal == 0) 
                        preguntas (12, orden_1, T4, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    else 
                        preguntas (12, orden_2, T4, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    break;

                case 4: // Tema 6
                    system("clear");
                    cout << "Tema 6\n";
                    nal = rand() % 2; // Generamos un número aleatorio para definir que "algoritmo" usaremos para ordenar la pregunta.

                    if (nal == 0) 
                        preguntas (7, orden_5, T6, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    else 
                        preguntas (7, orden_6, T6, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    break;

                case 5: // Tema 7
                    system("clear");
                    cout << "Tema 7\n";
                    nal = rand() % 2; // Generamos un número aleatorio para definir que "algoritmo" usaremos para ordenar la pregunta.

                    if (nal == 0)
                        preguntas (7, orden_5, T7, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    else
                        preguntas (7, orden_6, T7, res_pregunta); // Argumentos: nº Preguntas, algoritmo a usar, tema, variable donde almacenarmos las preguntas respondidas con menos de un 7
                    break;

                default: // Si el usuario no ha elegido correctamente el tema, volvemos a abrir el programa.
                    main();
                    break;
            }

            // Sacamos por pantalla las preguntas que el usuario respondió con menos de un 7.
            system("clear"); // Limpiamos la consola
            system("cat banner.txt"); // Sacamos por pantalla el banner
            cout << "\n\nRespuestas incorrectas: \n\n";
            for (int i = 0; i < 12; i++) { // Hacemos un bucle con una pequeña comprobación de que exista una pregunta en x posición del array, y si la hay mostrar por pantalla la pregunta.
                if (strlen(res_pregunta[i].c_str()) > 3)
                    cout << res_pregunta[i] << endl;
            }

        break;

        case 2: // Modo Examen
            system("clear"); // Limpiamos la consola
            system("cat banner.txt"); // Sacamos por pantalla el banner
            cout << endl << endl << "A poder ser, espere como mínimo 5 segundos antes de avanzar de pregunta, ya que así la semilla de generación de números aleatorios tendrá tiempo de generar una pregunta diferente en cada ocasión. Aún así, es posible que el algoritmo vuelva a generar una pregunta previamente generada." << endl << endl;
            for (int i = 0; i < 10; i++) { // Este bucle repetirá este proceso 10 veces, para generar 10 posibles preguntas entre todos los temas.
                sleep(0.5); // Detenemos el programa medio segundo para que el número generado sea más eficaz.
                nal = rand() % 5; // Generamos una probabilidad de 5 casos, para elegir uno de los 5 temas posibles. Ya que el examen será global.
                switch (nal) {
                    case 0:
                        nota = modo_examen (T1, 12); // Argumentos: Tema, nª Preguntas.
                        break;

                    case 1: 
                        nota = modo_examen (T3, 8); // Argumentos: Tema, nª Preguntas.
                        break;

                    case 2: 
                        nota = modo_examen (T4, 12); // Argumentos: Tema, nª Preguntas.
                        break;

                    case 3: 
                        nota = modo_examen (T6, 7); // Argumentos: Tema, nª Preguntas.
                        break;

                    case 4: 
                        nota = modo_examen (T7, 7); // Argumentos: Tema, nª Preguntas.
                        break;

                }
                suma += nota;
            }
            cout << "Nota media: " << suma / 10 << endl; // Sacamos la nota media del examen para hacer un aproximado de lo que pasaría en la realidad.
            break;

        case 3: 
            // Liberar la memoria asignada
            delete[] orden_1;
            delete[] orden_2;
            delete[] orden_3;
            delete[] orden_4;
            delete[] orden_5;
            delete[] orden_6;
            return 0;

        default: // Si el usuario se equivoca eligiendo opción por defecto, volveremos a cargar el programa.
            main();
    }

    // Liberar la memoria asignada
    delete[] orden_1;
    delete[] orden_2;
    delete[] orden_3;
    delete[] orden_4;
    delete[] orden_5;
    delete[] orden_6;

    return 0;
}