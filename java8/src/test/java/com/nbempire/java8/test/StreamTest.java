package com.nbempire.java8.test;

import com.nbempire.java8.test.domain.Person;
import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created on 04/04/14, at 17:38.
 *
 * @author Nahuel Barrios <barrios.nahuel@gmail.com>.
 */
public class StreamTest {

    @Test
    public void testStream() {
        List<Person> persons = new ArrayList<>();
        persons.add(new Person("nahuel", 'h'));
        persons.add(new Person("roman", 'H'));
        persons.add(new Person("anahi", 'm'));
        persons.add(new Person("patricia", 'M'));
        persons.add(new Person("samanta", 'M'));

        System.out.println("Filtrado antes de Java 8: ");
        List<Person> filtered = new ArrayList<>();
        for (Person eachPerson : persons) {
            if (eachPerson.getSexo() == 'M') {
                filtered.add(eachPerson);
            }
        }
        validateQuantity(filtered);
        filtered.stream().forEach(cadaPersona -> System.out.println(cadaPersona.getNombre()));


        System.out.println("Filtrado con Stream de Java 8:");
        filtered = persons.stream().filter(cadaPersona -> cadaPersona.getSexo() == 'M').collect(Collectors.toList());
        validateQuantity(filtered);
        filtered.stream().forEach(cadaPersona -> System.out.println(cadaPersona.getNombre()));
    }

    private void validateQuantity(List<Person> persons) {
        Assert.assertEquals(3, persons.size());
    }
}
