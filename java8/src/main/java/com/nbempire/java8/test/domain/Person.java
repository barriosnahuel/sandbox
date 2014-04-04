package com.nbempire.java8.test.domain;


/**
 * Created on 04/04/14, at 17:41.
 *
 * @author Nahuel Barrios <barrios.nahuel@gmail.com>.
 */
public class Person {

    private String nombre;
    private char sexo;

    public Person(String nombre, char sexo) {
        this.nombre = nombre;
        this.sexo = Character.toUpperCase(sexo);
    }

    public char getSexo() {
        return sexo;
    }

    public String getNombre() {
        return nombre;
    }
}
