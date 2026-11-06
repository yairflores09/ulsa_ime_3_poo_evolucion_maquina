#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

class Maquina {
private:
    std::string nombre;
    int piezasProcesadas;
    int tiempoTrabajadoSeg;

protected:
    void registrarPieza();
    void agregarTiempo(int segundos);

public:
    explicit Maquina(const std::string& nombre);
    virtual ~Maquina() = default;

    // Cada llamada procesa exactamente una pieza.
    // La derivada debe registrar la pieza y sumar su tiempo de ciclo.
    virtual void procesar() = 0;

    // Devuelve el tiempo de un ciclo, siempre mayor que cero.
    virtual int tiempoCicloSeg() const = 0;

    double capacidadPorHora() const;

    const std::string& getNombre() const;
    int getPiezasProcesadas() const;
    int getTiempoTrabajadoSeg() const;
    void mostrarEstado() const;
};

#endif