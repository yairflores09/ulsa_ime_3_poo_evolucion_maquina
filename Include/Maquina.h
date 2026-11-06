#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

class Maquina {
private:
    std::string nombre;
    int piezasProcesadas;
    int tiempoTrabajadoSeg;

    void registrarPieza();
    void agregarTiempo(int segundos);
    int tiempoCicloValidado() const;

    virtual void ejecutarCiclo() = 0;

public:
    explicit Maquina(const std::string& nombre);
    virtual ~Maquina() = default;

    // La base valida y registra exactamente una pieza por ciclo.
    void procesar();

    // Cada derivada debe devolver un tiempo mayor que cero.
    virtual int tiempoCicloSeg() const = 0;

    double capacidadPorHora() const;
    const std::string& getNombre() const;
    int getPiezasProcesadas() const;
    int getTiempoTrabajadoSeg() const;
    void mostrarEstado() const;
};

#endif