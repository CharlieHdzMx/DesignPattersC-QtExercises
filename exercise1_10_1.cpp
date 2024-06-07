#include <string>
#include <QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QFile>
#include <iostream>

using namespace Qt;

void WriteFileOnce(QFile& data, QString str)
{
    QTextStream out(&data);
    // Pasar datos el string del text stream para el stream de salida del archivo. Linkeo de string del codigo al archivo.
    out << str;
    // Cerramos la sesion del archivo de escritura.
    data.close();
}

void WriteToFile(void)
{
    QString str;
    QTextStream strbuf(&str);
    /* Accessory text streams para simular cin.*/
    QTextStream qcin(stdin);

    int lucky = 7;
    float pi = 3.14;
    double e = 2.71;

    std::cout << "An in-memory stream" << std::endl;
    strbuf << "luckynumber: " << lucky << endl
           << "pi: " << pi << endl
           << "e: " << e << endl;
    std::cout.flush();

    /* Pedir el nombre del archivo al usuario.*/
    QString fileName;
    fileName = qcin.readLine();
    /* Use case de crear un nuevo archivo y llenarlo con datos*/
    QFile data(fileName);
    /* Checamos si el archivo ya existe antes de tratar de escribirlo, si existe entonces podemos escribir*/
    if(data.exists() == true)
    {
        if(false != data.open(QIODeviceBase::NewOnly))
        {
            WriteFileOnce(data, str);
        }
    }
    /* Si el archivo no existe, podemos crear uno. */
    else
    {
        if(false != data.open(QIODevice::WriteOnly))
        {
            WriteFileOnce(data, str);
        }
    }
}

/* Modifica el ajecrcici 1.11 para tomar el fileName del usuario antes de escribir o leer.
   Necesitas usar la funcion de .c_str() para convertir el string de una manera aceptable para la operacion open()*/
/* Modificalo para que se asegure que el archivo especificado por el usuario no exista, o si esta bien reemplazarlos,
antes de abrirlo.*/
int main()
{
    WriteToFile();

    // QFile data("fileName.txt");

    // /* Use case de lectura con TextStreams de entrada.*/
    // /* Revisamos si se puede abrir el archivo como read only */
    // if(data.open(QIODevice::ReadOnly) != false)
    // {
    //     /* Definir un QTextStream de entrada (para poder tomar valores de file -> a string*/
    //     QTextStream in(&data);
    //     int lucky2;
    //     QString newstr;
    //     /* leer los valores del file a los string.*/
    //     in >> newstr >> lucky2;
    //     /* Cerramos el archivo si es que se abrio y no hay manera que no caiga aqui.*/
    //     data.close();
    // }
}


